#include "app/app.hpp"

#include "utils/logger.hpp"
#include "utils/utils.hpp"

#include <spdlog/spdlog.h>

struct Test
{
    Logger<Test> logger;

    Test()
    {
        logger.CRITICAL("your momma");
    }
};


struct Testing : private TrackingLogger<Testing>
{};

int main()
{
    spdlog::set_level(spdlog::level::trace);

    App app {"Template Project"};
    app.run();
}
