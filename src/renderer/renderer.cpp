#include "renderer.hpp"

#include "utils/logger.hpp"

#include <glm/glm.hpp>
#include <imgui.h>

#include "utils/math.hpp"
#include <fmt/format.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/mat4x4.hpp>
#include <execution>
#include <numeric>
#include <random>
#include <vector>
#include <vector>


Renderer::Renderer()
{
    listener.listen(
        [this] (event::SettingsChanged const& event) {
            this->settings = event.newSettings;
        });

    data = static_cast<unsigned char*>(malloc(image.size().x * image.size().y * 4));
}

void Renderer::tick()
{
    if (settings.generateNoise) {
        // updateWithNoise(image);
    }

    for (int x = 0; x < 1920; ++x) {
        for (int y = 0; y < 1080; ++y) {
            glm::vec3 ray_direction = camera.getRayDirection(x, y);
            spdlog::info("{{ {}, {}, {} }}", ray_direction.x, ray_direction.y, ray_direction.z);
        }
    }

    image.update(data);
}
