#include "renderer.hpp"

#include "utils/logger.hpp"

#include <glm/glm.hpp>
#include <imgui.h>

#include <execution>
#include <numeric>
#include <random>
#include <vector>
#include <vector>


namespace
{

struct Ray
{
    glm::vec3 orig, dir;
};

bool solveQuadratic(const float& a, const float& b, const float& c,
    float& x0, float& x1)
{
    float discr = b * b - 4 * a * c;
    if (discr < 0) {
        return false;
    }
    else if (discr == 0) {
        x0 = x1 = -0.5 * b / a;
    }
    else {
        float q = (b > 0)?
                -0.5 * (b + sqrt(discr)) :
                -0.5 * (b - sqrt(discr));
        x0 = q / a;
        x1 = c / q;
    }

    if (x0 > x1) {
        std::swap(x0, x1);
    }

    return true;
}

bool intersect(const Ray& ray)
{
    float t0, t1;     // Solutions for t if the ray intersects the sphere
#if 0
    // Geometric solution
    Vec3f L   = center - ray.orig;
    float tca = L.dotProduct(ray.dir);
    // if (tca < 0) return false;
    float d2 = L.dotProduct(L) - tca * tca;
    if (d2 > radius * radius) {
        return false;
    }

    float thc = sqrt(radius * radius - d2);
    t0 = tca - thc;
    t1 = tca + thc;
#else
    // Analytic solution
    glm::vec3 L = ray.orig - glm::vec3 {0, 0, 0};
    float     a = glm::dot(ray.dir, ray.dir);
    float     b = 2 *glm::dot(ray.dir, L);
    float     c = glm::dot(L, L) - 1.0;
    if (!solveQuadratic(a, b, c, t0, t1)) {
        return false;
    }

#endif
    if (t0 > t1) {
        std::swap(t0, t1);
    }

    if (t0 < 0) {
        t0 = t1;     // If t0 is negative, let's use t1 instead.
        if (t0 < 0) {
            return false;             // Both t0 and t1 are negative.
        }
    }

    //t = t0;

    return true;
}

} // namespace

Renderer::Renderer()
{
    listener.listen(
        [this] (event::SettingsChanged const& event) {
            this->settings = event.newSettings;
        });

    data = static_cast<unsigned char*>(malloc(image.size().x * image.size().y * 4));

    renderThread = std::jthread(
        [this] {
            int width = image.size().x, height = image.size().y;
            std::vector<int> indices(width * height);
            std::iota(indices.begin(), indices.end(), 0);

            std::for_each(
                std::execution::par_unseq,
                indices.begin(),
                indices.end(),
                [&] (int i) {
                    int x = i % width;
                    int y = i / width;

                    float fov    = 90.0f;
                    float scale  = tan(glm::radians(fov / 2.0f));
                    float aspect = (float)width / height;

                    float px = (2.0f * (x + 0.5f) / width - 1.0f) * scale * aspect;
                    float py = (1.0f - 2.0f * (y + 0.5f) / height) * scale;

                    Ray ray {glm::vec3(0, 0, -3), glm::normalize(glm::vec3(px, py, 1.0f))};

                    if (!intersect(ray)) {
                        return;
                    }

                    int idx       = i * 4;
                    data[idx + 0] = 255;
                    data[idx + 1] = 0;
                    data[idx + 2] = 255;
                    data[idx + 3] = 255;
                });
        });
}

void Renderer::tick()
{
    if (settings.generateNoise) {
        // updateWithNoise(image);
    }

    image.update(data);
}
