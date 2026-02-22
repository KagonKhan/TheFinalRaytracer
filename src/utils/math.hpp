#ifndef TFR_UTILS_MATH_HPP
#define TFR_UTILS_MATH_HPP


#include <glm/glm.hpp>

namespace math
{

struct Ray
{
    glm::vec3 origin;
    glm::vec3 direction;

    glm::vec3 at(float t) const { return origin + t * direction; }
};


class PinholeCamera
{
public:
    bool onUpdate(float dt);
    void onResize(glm::vec2 new_size);

    glm::vec3 getPosition() const noexcept { return position_; }
    glm::vec3 getRayDirection(int x, int y);


private:
    glm::mat4 view_              = {1.f};
    glm::mat4 inverseView_       = {1.f};
    glm::mat4 projection_        = {1.f};
    glm::mat4 inverseProjection_ = {1.f};

    float verticalFOV_   = 90.0f;
    float nearClip_      = 0.1f;
    float farClip_       = 1000.0f;
    float rotationSpeed_ = 7.3f;
    float focusDistance_ = 10.f;
    float aperture_      = 5.f;

    glm::vec3 position_         = {0.0f, 1.0f, 9.0f};
    glm::vec3 forwardDirection_ = {0.0f, 0.0f, -1.f};

    glm::vec2 lastMousePosition_ = {0.0f, 0.0f};
    glm::vec2 viewportSize_      = {1920.0f, 1080.0f};

    void calculateProjection();
};

}     // namespace math


#endif // TFR_UTILS_MATH_HPP
