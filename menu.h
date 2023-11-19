#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>

#include "Background.h"
#include "Key.h"
#include "Title.h"

class Menu
{
public:
    Menu();
    ~Menu();
    bool loadMedia(SDL_Renderer *gRenderer);
    void renderImage(SDL_Renderer *gRenderer);
    void handleAction(SDL_Renderer *gRenderer, SDL_Event e);
protected:
    Background snow, sky1, sky2, sky3, cloud1, cloud2, cloud3, effect1, effect2, effect3;
    Title nameOfGame;
    Key G1, G2, G3;
};

#endif // MENU_H_INCLUDED

