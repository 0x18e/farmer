cmake_minimum_required(VERSION 3.20)

project(FarmingGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.h")


add_executable(FarmingGame ${SOURCES})

set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries" FORCE)

# Fetch SDL2
include(FetchContent)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.28.4
)

FetchContent_MakeAvailable(SDL2)

set(SDL2IMAGE_INSTALL OFF CACHE BOOL "" FORCE)  # Keep installation disabled
FetchContent_Declare(
  SDL2_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG release-2.6.3
)

FetchContent_MakeAvailable(SDL2_image)


set(SDL2MIXER_INSTALL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  SDL2_mixer
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
  GIT_TAG release-2.8.0
)
FetchContent_MakeAvailable(SDL2_mixer)


target_link_libraries(FarmingGame PUBLIC SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer)

# Copy resources to the output directory
add_custom_command(TARGET FarmingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/sprites" "$<TARGET_FILE_DIR:FarmingGame>/sprites"
)
add_custom_command(TARGET FarmingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/sound" "$<TARGET_FILE_DIR:FarmingGame>/sound"
)

# Copy SDL2_image DLL to the output directory
add_custom_command(TARGET FarmingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:SDL2_image> $<TARGET_FILE_DIR:FarmingGame>
)

# Copy SDL2_mixer DLL to the output directory
add_custom_command(TARGET FarmingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:SDL2_mixer> $<TARGET_FILE_DIR:FarmingGame>
)
