#include "Environment.h"
#include <iostream>

Environment::Environment(int width, int height, const std::string& backgroundPath)
    : windowWidth(width), windowHeight(height), backgroundPath(backgroundPath), backgroundSprite(nullptr) {}

Environment::~Environment() {
    if (backgroundSprite) {
        destroySprite(backgroundSprite);
    }
}

void Environment::PreInit(int& width, int& height, bool& fullscreen) {
    width = windowWidth;
    height = windowHeight;
    fullscreen = false;
}

bool Environment::Init() {
    backgroundSprite = createSprite(backgroundPath.c_str());
    if (!backgroundSprite) {
        std::cerr << "Failed to load background sprite" << std::endl;
        return false;
    }
    return true;
}

void Environment::Close() {
    if (backgroundSprite) {
        destroySprite(backgroundSprite);
    }
}

bool Environment::Tick() {
    drawBackground();
    // Add game logic here
    return false;
}

void Environment::onMouseMove(int x, int y, int xrelative, int yrelative) {
    // Handle mouse movement
}

void Environment::onMouseButtonClick(FRMouseButton button, bool isReleased) {
    // Handle mouse button clicks
}

void Environment::onKeyPressed(FRKey k) {
    // Handle key presses
}

void Environment::onKeyReleased(FRKey k) {
    // Handle key releases
}

const char* Environment::GetTitle() {
    return "Doodle Jump Clone";
}

void Environment::drawBackground() {
    int bgWidth, bgHeight;
    getSpriteSize(backgroundSprite, bgWidth, bgHeight);

    // Calculate how many background sprites are needed to fill the screen
    int horizontalCount = (windowWidth + bgWidth - 1) / bgWidth;
    int verticalCount = (windowHeight + bgHeight - 1) / bgHeight;

    // Draw the background sprites
    for (int i = 0; i < horizontalCount; ++i) {
        for (int j = 0; j < verticalCount; ++j) {
            drawSprite(backgroundSprite, i * bgWidth, j * bgHeight);
        }
    }
}
