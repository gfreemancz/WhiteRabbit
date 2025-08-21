#pragma once

#include <SDL2/SDL.h>
#include "wrTypes.h"
#include <iostream>
#undef main

namespace nsWhiteRabbit
{
  class cWindow_WR
  {
    public:
    SDL_Window * getWinPtr(void){return myWindow;}
    cWindow_WR(void);
    cWindow_WR(std::string arg_title,int arg_px,int arg_py,int arg_width,int arg_height, float arg_Opacity = 1.0f);
    ~cWindow_WR(void);
    void setOpacity(float arg_opacity);
    void SwapOglBuffers(void);
    void GetWindowPosition(si32 * arg_x, si32 * arg_y);
    void UpdateWinTitle(std::string arg_NewTitle);
    ui32 GetWidth(void) { return Width; }
    ui32 GetHeight(void) { return Height; }
    private:
    std::string   windowTitle;
    ui32  Width;
    ui32  Height;
    ui32  PosX;
    ui32  PosY;
    float Opacity;
    SDL_Window* myWindow;
  };
}