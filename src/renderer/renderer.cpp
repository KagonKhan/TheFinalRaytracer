#include "renderer.hpp"


#include <imgui.h>

#include <random>
#include <vector>

namespace
{

void updateWithNoise(Image& image)
{
    auto size = image.size();

    std::vector<unsigned char> pixels(size.x * size.y * 4);

    static std::mt19937 gen(std::random_device {}());

    static std::uniform_int_distribution<unsigned int> dist(0, 255);

    for (auto& p : pixels) {
        p = static_cast<unsigned char>(rand() & 0xFF);
    }

    image.update(pixels.data());
}

} // namespace

Renderer::Renderer()
{
    updateWithNoise(image);

    listener.listen(
        [this] (event::SettingsChanged const& event) {
            this->settings = event.newSettings;
        });
}

void Renderer::tick()
{
    if (settings.generateNoise) {
        updateWithNoise(image);
    }
}
