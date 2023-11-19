#ifndef YOUWIN_H_INCLUDED
#define YOUWIN_H_INCLUDED

#include <iostream>

#include "Background.h"

class YouWin
{
public:
    YouWin();
    ~YouWin();
    bool loadMedia(SDL_Renderer *gRenderer);
    void renderImage(SDL_Renderer *gRenderer);
    int GAME;
    bool WIN;
protected:
    Background sky, cloud, effect, snow, again, yes, no, result;
};

#endif // YOUWIN_H_INCLUDED

