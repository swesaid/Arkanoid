# Minimum required version of CMake
cmake_minimum_required(VERSION 3.30)

# Project name
project(Arkanoid)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find required libraries
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(GLEW REQUIRED)

# Include directories
include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/Configurations
        ${PROJECT_SOURCE_DIR}/Objects
        ${PROJECT_SOURCE_DIR}/Graphics
        ${PROJECT_SOURCE_DIR}/GameLogic
        ${PROJECT_SOURCE_DIR}/Data
        ${PROJECT_SOURCE_DIR}/Game
        ${PROJECT_SOURCE_DIR}/PlayerInteraction
)

# Link directories
link_directories(
        ${SDL2_LIBRARY_DIRS}
        ${GLEW_LIBRARY_DIRS}
)

# Add source files (update paths based on the provided structure)
set(SOURCE_FILES
        main.cpp
        Game/Game.cpp
        GameLogic/GameLoopManager.cpp
        GameLogic/CollisionHandler.cpp
        Graphics/GraphicsRenderer.cpp
        Graphics/ShapesDrawer.cpp
        Objects/Ball.cpp
        Objects/Brick.cpp
        Objects/Paddle.cpp
        Data/BricksRepository.cpp
        Configurations/GameConfigurationsCleaner.cpp
        Configurations/GameConfigurator.cpp
        Graphics/TextRenderer.cpp
        GameLogic/GameResultManager.cpp
        GameLogic/LevelManager.cpp
        PlayerInteraction/GraphicalPlayerInteraction.cpp
        PlayerInteraction/GameStateManager.cpp
)

# Add the executable
add_executable(Arkanoid ${SOURCE_FILES})

# Link libraries
target_link_libraries(Arkanoid
        ${OPENGL_LIBRARIES}
        SDL2::SDL2
        SDL2_ttf::SDL2_ttf
        GLEW::GLEW
)
