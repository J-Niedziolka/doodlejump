#pragma once

#include "Framework.h"
#include <string>

class Environment : public Framework {
public:
    // Constructor and destructor
    Environment(int width, int height, const std::string& backgroundPath);
    virtual ~Environment();

    // Framework methods
    virtual void PreInit(int& width, int& height, bool& fullscreen);
    virtual bool Init();
    virtual void Close();
    virtual bool Tick();
    virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
    virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
    virtual void onKeyPressed(FRKey k);
    virtual void onKeyReleased(FRKey k);
    virtual const char* GetTitle();

    // Additional methods for the environment
    void drawBackground();

private:
    int windowWidth;
    int windowHeight;
    std::string backgroundPath;
    Sprite* backgroundSprite;
};
