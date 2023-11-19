#include <fstream>

#include "Level3.h"

void Level3::readMatrix()
{
    ifstream fileStone("Level3/stone.txt");
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            fileStone>> codeStone[i][j];
    fileStone.close();

    ifstream fileLadder("Level3/ladder.txt");
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            fileLadder>> codeLadder[i][j];
    fileLadder.close();

    ifstream fileKey("Level3/key.txt");
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
        {
            fileKey>> codeKey[i][j];
            if (codeKey[i][j]!='-')
                numOfKey++;
        }
    fileKey.close();
    return;
}

void Level3::renderImage(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    // background level 2
    sky.render(sky.x, sky.y, gRenderer);
    effect.render(effect.x, effect.y, gRenderer);
    cloud.render(cloud.x, cloud.y, gRenderer);

    // stone
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            matrixStone[i][j].render(matrixStone[i][j].x, matrixStone[i][j].y, gRenderer);

    // ladder
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            matrixLadder[i][j].render(matrixLadder[i][j].x, matrixLadder[i][j].y, gRenderer);

    // key
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            matrixKey[i][j].render(matrixKey[i][j].x, matrixKey[i][j].y, gRenderer);

    keyYellow.render(keyYellow.x, keyYellow.y, gRenderer);

    gate1.render(gate1.x, gate1.y, gRenderer);
    gate2.render(gate2.x, gate2.y, gRenderer);

    magic1.render(magic1.x, magic1.y, gRenderer);
    magic2.render(magic2.x, magic2.y, gRenderer);

    heart.render(heart.x, heart.y, gRenderer);

    snake1.render(snake1.x, snake1.y, gRenderer);
    snake2.render(snake2.x, snake2.y, gRenderer);
    snake3.render(snake3.x, snake3.y, gRenderer);

    // main character
    soldier.render(soldier.x, soldier.y, gRenderer);

    SDL_RenderPresent( gRenderer );
    return;
}

Level3::~Level3()
{
    return;
}

Level3::Level3()
{
    return;
}


bool Level3::loadMedia(SDL_Renderer *gRenderer)
{
    bool success=true;

    string fileSky="art/background/Level3/sky.png";
    sky.x=0;
    sky.y=0;
    if (!sky.loadFromFile(fileSky, gRenderer))
        success=false;

    string fileEffect="art/background/Level3/effect.png";
    effect.x=0;
    effect.y=0;
    if (!effect.loadFromFile(fileEffect, gRenderer))
        success=false;

    string fileCloud="art/background/Level3/cloud.png";
    cloud.x=0;
    cloud.y=0;
    if (!cloud.loadFromFile(fileCloud, gRenderer))
        success=false;

    string fileGate="art/background/gate/2.png";
    gate1.x=20*48-100;
    gate1.y=5*48-100;
    if (!gate1.loadFromFile(fileGate, gRenderer))
        success=false;
    gate2.x=3*48-100;
    gate2.y=13*48-100;
    if (!gate2.loadFromFile(fileGate, gRenderer))
        success=false;

    string fileCharacter="art/character/rogue/rogue.png";
    soldier.x=650;
    soldier.y=1;
    if (!soldier.loadFromFile(fileCharacter, gRenderer))
        success=false;

    readMatrix();

    string fileStone="art/background/stone/X.png";
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            if (codeStone[i][j]!='-')
            {
                matrixStone[i][j].x=j*48;
                matrixStone[i][j].y=i*48+3;
                fileStone[21]=codeStone[i][j];
                if (!matrixStone[i][j].loadFromFile(fileStone, gRenderer))
                {
                    success=false;
                }

            }

    string fileLadder="art/background/Ladder/X.png";
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            if (codeLadder[i][j]!='-')
            {
                matrixLadder[i][j].x=j*48;
                matrixLadder[i][j].y=i*48-10;
                fileLadder[22]=codeLadder[i][j];
                if (!matrixLadder[i][j].loadFromFile(fileLadder, gRenderer))
                    success=false;
            }

    string fileKey="art/background/key/key1/1.png";
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            if (codeKey[i][j]!='-')
            {
                matrixKey[i][j].x=j*48;
                matrixKey[i][j].y=i*48-10;
                if (!matrixKey[i][j].loadFromFile(fileKey, gRenderer))
                    success=false;
            }

    string fileKeyYellow="art/key.png";
    keyYellow.x=8*48;
    keyYellow.y=2*48-12;
    if (!keyYellow.loadFromFile(fileKeyYellow, gRenderer))
        success=false;

    string fileSnakeRight="art/snake/right/1.png";
    snake1.x=15*48;
    snake1.y=5*48-12-40;
    if (!snake1.loadFromFile(fileSnakeRight, gRenderer))
        success=false;

    snake3.x=16*48;
    snake3.y=13*48-12-40;
    if (!snake3.loadFromFile(fileSnakeRight, gRenderer))
        success=false;

    string fileSnakeLeft="art/snake/left/1.png";
    snake2.x=12*48-50;
    snake2.y=8*48-12-40;
    if (!snake2.loadFromFile(fileSnakeLeft, gRenderer))
        success=false;

    return success;
}

void Level3::checkWin(SDL_Renderer *gRenderer)
{
    string gasWin="art/character/gas/0.png";
    if (numOfKey==0 && soldier.x<heart.x+98 && soldier.y/48==0)
    {
        string fileUnHeart="art/unHeart.png";
        heart.loadFromFile(fileUnHeart, gRenderer);
        soldier.x-=105;
        soldier.y-=100;
        WIN=true;
        for (char x='0'; x<='9'; x++)
        {
            int i=0;
            while (i<30000000)
                i++;
            gasWin[18]=x;
            soldier.loadFromFile(gasWin, gRenderer);
            renderImage(gRenderer);
        }
    }
    return;
}

void Level3::checkLose(SDL_Renderer *gRenderer)
{
    if (soldier.y+60>620)
    {
        LOSE=true;
        printf("fall out   \n");
        death(gRenderer);
        return;
    }
    return;
}

void Level3::death(SDL_Renderer *gRenderer)
{
    string deathLeft="art/character/rogue/deathLeft/0.png";
    string deathRight="art/character/rogue/deathRight/0.png";

    soldier.x-=105;
    soldier.y-=100;

    if (nowLeft)
    {
        for (char x='0'; x<='9'; x++)
        {
            int i=0;
            while (i<30000000)
                i++;
            deathLeft[30]=x;
            soldier.loadFromFile(deathLeft, gRenderer);
            renderImage(gRenderer);
        }
    }
    else
    {
        for (char x='0'; x<='9'; x++)
        {
            int i=0;
            while (i<30000000)
                i++;
            deathRight[31]=x;
            soldier.loadFromFile(deathRight, gRenderer);
            renderImage(gRenderer);
        }
    }
    return;
}

void Level3::checkGateSnake1()
{
    if (snake1.x>gate1.x+20 && snake1.y>gate1.y && snake1.y<gate1.y+80)
    {
        snake1.x=gate2.x+60;
        snake1.y=gate2.y+50;
        snake1_Top=false;
        return;
    }

    if (snake1.x<gate2.x+55 && snake1.y>gate2.y && snake1.y<gate2.y+80)
    {
        snake1.x=gate1.x+10;
        snake1.y=gate1.y+50;
        snake1_Top=true;
        return;
    }
    return;


}

void Level3::checkGateSnake3()
{
    if (snake3.x>magic1.x+20 && snake3.y>magic1.y && snake3.y<magic1.y+80)
    {
        snake3.x=magic2.x+60;
        snake3.y=magic2.y+30;
        snake3_Top=true;
        return;
    }

    if (snake3.x<magic2.x+55 && snake3.y>magic2.y && snake3.y<magic2.y+80)
    {
        snake3.x=magic1.x+10;
        snake3.y=magic1.y+30;
        snake3_Top=false;
        return;
    }
    return;


}


void Level3::checkGate()
{
    if (soldier.x>gate1.x+30 && soldier.x<gate1.x+55 && soldier.y>gate1.y && soldier.y<gate1.y+50)
    {
        soldier.x=gate2.x+60;
        soldier.y=gate2.y+28;
        return;
    }
    if (soldier.x<gate2.x+55 && soldier.x>gate2.x+40 && soldier.y>gate2.y && soldier.y<gate2.y+50)
    {
        soldier.x=gate1.x+20;
        soldier.y=gate1.y+28;
        return;
    }

    if (soldier.x>magic1.x+30 && soldier.x<magic1.x+55 && soldier.y>magic1.y && soldier.y<magic1.y+50)
    {
        soldier.x=magic2.x+60;
        soldier.y=magic2.y+8;
        return;
    }
    if (soldier.x<magic2.x+55 && soldier.x>magic2.x+40 && soldier.y>magic2.y && soldier.y<magic2.y+50)
    {
        soldier.x=magic1.x+20;
        soldier.y=magic1.y+8;
        return;
    }


    return;
}

bool Level3::okDown()
{
    if (codeStone[(soldier.y+60)/48][(soldier.x)/48]!='-')
    {
        if (codeLadder[(soldier.y+60)/48+1][(soldier.x)/48]!='-')
            return true;
        if (codeLadder[(soldier.y+60)/48][(soldier.x)/48]!='-')
            if (soldier.y+60<((soldier.y+60)/48)*48+38)
                return true;
    }
    else if (codeLadder[(soldier.y+60)/48][(soldier.x)/48]!='-')
        return true;
    return false;
}
bool Level3::check()
{
    if (soldier.y+60>638)
        return false;
    if (codeLadder[(soldier.y+60)/48][(soldier.x+40)/48]!='-')
        return false;
    if (soldier.y+60<((soldier.y+60)/48)*48+38)
        return true;
    if (codeStone[(soldier.y+60)/48][(soldier.x+40)/48]=='-' && codeStone[(soldier.y+60)/48][(soldier.x)/48]=='-')
        return true;
    return false;
}

void Level3::findKey(SDL_Renderer *gRenderer)
{
    string fileKeyReplace="art/background/key/key1/0.png";
    if (codeKey[(soldier.y+60)/48][(soldier.x+10)/48]!='-')
    {
        printf("FindKey %d\n", numOfKey);
        numOfKey--;
        codeKey[(soldier.y+60)/48][(soldier.x+10)/48]='-';
        matrixKey[(soldier.y+60)/48][(soldier.x+10)/48].loadFromFile(fileKeyReplace, gRenderer);
        if (numOfKey==0)
            newHeart(gRenderer);
        return;
    }
    if (codeKey[(soldier.y+60)/48][(soldier.x+30)/48]!='-')
    {
        printf("FindKey %d\n", numOfKey);
        numOfKey--;
        codeKey[(soldier.y+60)/48][(soldier.x+30)/48]='-';
        matrixKey[(soldier.y+60)/48][(soldier.x+30)/48].loadFromFile(fileKeyReplace, gRenderer);
        if (numOfKey==0)
            newHeart(gRenderer);
        return;
    }
    return;
}


void Level3::newGATE(SDL_Renderer *gRenderer)
{
    string fileUnKey="art/unKey.png";
    keyYellow.loadFromFile(fileUnKey, gRenderer);


    //gate1.x=20*48-100;
    //gate1.y=5*48-100;
        //gate2.x=3*48-100;
        //gate2.y=13*48-100;
    magic1.x=19*48-100;
    magic1.y=13*48-80;

    magic2.x=3*48-100;
    magic2.y=4*48-80;
}

void Level3::newHeart(SDL_Renderer *gRenderer)
{
    string fileHeart="art/heart.png";
    heart.x=9*48-2;
    heart.y=6;
    heart.loadFromFile(fileHeart, gRenderer);
}
void Level3::fall(SDL_Renderer *gRenderer)
{
    while (check())
    {
        if (!appearGATE)
            if (soldier.x/48==9 && soldier.y/48==1)
            {
                appearGATE=true;
                newGATE(gRenderer);
            }
        findKey(gRenderer);
        if (soldier.y%16==0)
            ok=50000-1;
        continueEffect(gRenderer);
        soldier.y++;
        renderImage(gRenderer);
    }
    return;
}

void Level3::snakeWalk(Snake &snake, int col1, int col2, int &SNAKE, bool &snakeLeft, SDL_Renderer *gRenderer)
{
    // snake
    SNAKE++;
    SNAKE%=4;
    string fileSnakeLeft="art/snake/Left/1.png";
    string fileSnakeRight="art/snake/right/1.png";
    if (!snakeLeft)
    {
        if (snake.x+50<=col2*48-speedSnake)
        {
            snake.x+=speedSnake;
            fileSnakeRight[16]=char(SNAKE+1+'0');
            snake.loadFromFile(fileSnakeRight, gRenderer);
        }
        else
        {
            snakeLeft=true;
            SNAKE=0;
        }
    }
    else
    {
        if (snake.x+50>=col1*48+speedSnake)
        {
            snake.x-=speedSnake;
            fileSnakeLeft[15]=char(SNAKE+1+'0');
            snake.loadFromFile(fileSnakeLeft, gRenderer);

        }
        else
        {
            snakeLeft=false;
            SNAKE=0;
        }
    }
    return;

}

void Level3::checkSnake(Snake &snake, int &SNAKE, bool &snakeLeft, SDL_Renderer *gRenderer)
{
    if (soldier.y<snake.y && soldier.y+40>snake.y)
    {
        if (snakeLeft)
        {
            if (snake.x>= soldier.x && snake.x <= soldier.x+40)
            {
                LOSE=true;
                printf("find snake \n");
                death(gRenderer);
                return;
            }
        }
        else
        {
            if (snake.x+50>=soldier.x && snake.x+50<=soldier.x+40)
            {
                LOSE=true;
                printf("find snake \n");
                death(gRenderer);
            }
        }
    }
    return;
}
void Level3::continueEffect(SDL_Renderer *gRenderer)
{
    //return;
    ok++;
    if (ok%50000!=0)
        return;

    GATE++;
    GATE%=10;
    string fileGate="art/background/gate/0.png";
    fileGate[20]=char(GATE+'0');
    gate1.loadFromFile(fileGate, gRenderer);
    gate2.loadFromFile(fileGate, gRenderer);

    MAGIC=GATE+4;
    MAGIC%=10;
    if (appearGATE)
    {
        string fileMagic="art/background/magic/0.png";
        fileMagic[21]=char(MAGIC+'0');
        magic1.loadFromFile(fileMagic, gRenderer);
        magic2.loadFromFile(fileMagic, gRenderer);
    }

    if (snake1_Top)
        snakeWalk(snake1, 15, 20, SNAKE1, snakeLeft1, gRenderer);
    else
        snakeWalk(snake1, 2, 8, SNAKE1, snakeLeft1, gRenderer);

    snakeWalk(snake2, 6, 12, SNAKE2, snakeLeft2, gRenderer);

    if (snake3_Top)
        snakeWalk(snake3, 2, 8, SNAKE3, snakeLeft3, gRenderer);
    else
        snakeWalk(snake3, 12, 19, SNAKE3, snakeLeft3, gRenderer);

    checkSnake(snake1, SNAKE1, snakeLeft1, gRenderer);
    checkSnake(snake2, SNAKE2, snakeLeft2, gRenderer);
    checkSnake(snake3, SNAKE3, snakeLeft3, gRenderer);

    checkGateSnake1();

    if (appearGATE)
        checkGateSnake3();

    checkWin(gRenderer);
    checkLose(gRenderer);

    renderImage(gRenderer);
    return;
}


void Level3::handleAction(SDL_Renderer *gRenderer, SDL_Event e)
{
    if (WIN || LOSE)
        return;
    fall(gRenderer);
    checkGate();
    if (!numOfKey==0)
        findKey(gRenderer);

    if (!WIN && !LOSE)
        checkWin(gRenderer);
    if (!WIN && !LOSE)
        checkLose(gRenderer);

    std:: string rogueRight="art/character/rogue/walkRight/1.png";
    std:: string rogueLeft="art/character/rogue/walkLeft/1.png";
    std:: string rogueClimb="art/character/rogue/climb/1.png";

    if(e.type == SDL_KEYDOWN)
    {
        if(e.key.keysym.sym == SDLK_RIGHT)
        {
            Left=Up=Down=0;
            nowRight=true;
            nowLeft=false;
            rogueRight[30]=char(Right+1+'0');
            Right++;
            Right%=6;
            soldier.loadFromFile(rogueRight, gRenderer);
            renderImage(gRenderer);
            if (soldier.x+42<960)
                soldier.x+=12;
        }
        else if(e.key.keysym.sym == SDLK_LEFT)
        {
            Right=Up=Down=0;
            nowRight=false;
            nowLeft=true;
            rogueLeft[29]=char(Left+1+'0');
            Left++;
            Left%=6;
            soldier.loadFromFile(rogueLeft, gRenderer);
            renderImage(gRenderer);
            if (soldier.x>0)
                soldier.x-=12;
        }
        else if (e.key.keysym.sym == SDLK_UP)
        {
            if (codeLadder[(soldier.y+60)/48][(soldier.x)/48]!='-')
            {
                Down=Left=Right=0;
                rogueClimb[26]=char(Up+1+'0');
                Up++;
                Up%=3;

                soldier.loadFromFile(rogueClimb, gRenderer);
                renderImage(gRenderer);
                soldier.y-=12;
            }
        }
        else
        {
            if (okDown())
            {
                Up=Left=Right=0;
                rogueClimb[26]=char(Down+1+'0');
                Down++;
                Down%=3;
                soldier.loadFromFile(rogueClimb, gRenderer);
                renderImage(gRenderer);
                soldier.y+=12;
            }
        }
    }
    if (!WIN && !LOSE)
        checkWin(gRenderer);
    if (!WIN && !LOSE)
        checkLose(gRenderer);
    return;
}


