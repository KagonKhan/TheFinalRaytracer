#include "math.hpp"

#include <fmt/format.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/mat4x4.hpp>

#include <numbers>

namespace math
{

bool PinholeCamera::onUpdate(float dt)
{
    return false;
}

void PinholeCamera::onResize(glm::vec2 new_size)
{
    if (viewportSize_ == new_size) {
        return;
    }

    viewportSize_ = new_size;
}

void PinholeCamera::calculateProjection()
{
    projection_ = glm::perspectiveFov(
        glm::radians(verticalFOV_),
        viewportSize_.x,
        viewportSize_.y,
        nearClip_,
        farClip_
    );

    inverseProjection_ = glm::inverse(projection_);

    view_        = glm::lookAt(position_, position_ + forwardDirection_, glm::vec3(0, 1, 0));
    inverseView_ = glm::inverse(view_);
}

glm::vec2 randomUnitDisk()
{
    float f_1 = (rand() % 100'000) / 100'000;
    float f_2 = (rand() % 100'000) / 100'000;

    float r     = std::sqrtf(f_1);
    float theta = 2.f * std::numbers::pi_v<float>* f_2;

    return {r* std::cosf(theta), r* sinf(theta)};
}

glm::vec3 PinholeCamera::getRayDirection(int x, int y)
{
    glm::vec2 coords = {
        static_cast<float>(x) / viewportSize_.x,
        static_cast<float>(y) / viewportSize_.y
    };

    coords = coords * 2.0f - 1.0f;

    glm::vec4 target = inverseProjection_ * glm::vec4(coords.x, coords.y, 1, 1);
    target = glm::vec4(glm::normalize(glm::vec3(target) / target.w), 0);
    glm::vec3 rayDirection = glm::vec3(inverseView_ * target);


    return rayDirection;
    {
        glm::vec3 camera_origin = inverseView_[3];
        glm::vec3 focal_point   = camera_origin + rayDirection * focusDistance_;

        glm::vec2 disk_sample = randomUnitDisk() * aperture_;

        glm::vec3 cam_right = glm::vec3(inverseView_[0]);
        glm::vec3 cam_up    = glm::vec3(inverseView_[1]);

        glm::vec3 lens_offset = cam_right * disk_sample.x + cam_up * disk_sample.y;

        glm::vec3 new_origin    = camera_origin + lens_offset;
        glm::vec3 new_direction = glm::normalize(focal_point - new_origin);

        return new_direction;
    }
}

} // namespace math
