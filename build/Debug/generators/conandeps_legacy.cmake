message(STATUS "Conan: Using CMakeDeps conandeps_legacy.cmake aggregator via include()")
message(STATUS "Conan: It is recommended to use explicit find_package() per dependency instead")

find_package(imgui)
find_package(glfw3)
find_package(glew)
find_package(stb)
find_package(spdlog)

set(CONANDEPS_LEGACY  imgui::imgui  glfw  GLEW::GLEW  stb::stb  spdlog::spdlog )