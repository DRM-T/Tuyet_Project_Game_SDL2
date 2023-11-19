#include <fstream>

#include "Level2.h"

void Level2::readMatrix()
{
    ifstream fileStone("level2/stone.txt");
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            fileStone>> codeStone[i][j];
    fileStone.close();

    ifstream fileLadder("level2/ladder.txt");
    for (int i=0; i<14; i++)
        for (int j=0; j<20; j++)
            fileLadder>> codeLadder[i][j];
    fileLadder.close();

    ifstream fileKey("level2/key.txt");
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

void Level2::renderImage(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    // background level 2
    sky.render(sky.x, sky.y, gRenderer);
    effect.render(effect.x, effect.y, gRenderer);
    cloud.render(cloud.x, cloud.y, gRenderer);
    fire.render(fire.x, fire.y, gRenderer);

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


    gate1.render(gate1.x, gate1.y, gRenderer);
    gate2.render(gate2.x, gate2.y, gRenderer);

    snake.render(snake.x, snake.y, gRenderer);

    // main character
    soldier.render(soldier.x, soldier.y, gRenderer);

    SDL_RenderPresent( gRenderer );
    return;
}

Level2::~Level2()
{
}

Level2::Level2()
{
}


bool Level2::loadMedia(SDL_Renderer *gRenderer)
{
    bool success=true;

    string fileSky="art/background/Level2/sky.png";
    sky.x=0;
    sky.y=0;
    if (!sky.loadFromFile(fileSky, gRenderer))
        success=false;

    string fileEffect="art/background/Level2/effect.png";
    effect.x=0;
    effect.y=0;
    if (!effect.loadFromFile(fileEffect, gRenderer))
        success=false;

    string fileCloud="art/background/Level2/cloud.png";
    cloud.x=0;
    cloud.y=0;
    if (!cloud.loadFromFile(fileCloud, gRenderer))
        success=false;

    string fileFire="art/background/fire/1.png";
    fire.x=8*48-25;
    fire.y=11*48-30;
    if (!fire.loadFromFile(fileFire, gRenderer))
        success=false;

    string fileGate="art/background/gate/2.png";
    gate1.x=750;
    gate1.y=60;
    if (!gate1.loadFromFile(fileGate, gRenderer))
        success=false;
    gate2.x=120;
    gate2.y=490;
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
                    printf("Not found: %d", i, j, codeStone[i][j]);
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

    string fileSnake="art/snake/left/1.png";
    snake.x=19*48-50;
    snake.y=8*48-12-40;
    if (!snake.loadFromFile(fileSnake, gRenderer))
        success=false;

    return success;
}

void Level2::checkWin(SDL_Renderer *gRenderer)
{
    string gasWin="art/character/gas/0.png";
    if (numOfKey==0)
    {
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

void Level2::checkLose(SDL_Renderer *gRenderer)
{
    checkWin(gRenderer);
    if (WIN)
        return;
    if ((soldier.x+15>fire.x && soldier.x+15<fire.x+70) && (soldier.y+30>fire.y && soldier.y+30<fire.y+70))
    {
        LOSE=true;
        printf("findFire   \n");
        death(gRenderer);
        return;
    }
    if (soldier.y+60>620)
    {
        LOSE=true;
        printf("fall out   \n");
        death(gRenderer);
        return;
    }
    if (soldier.y+60>7*48 && soldier.y+60<8*48)
    {
        if (snakeLeft)
        {
            if (snake.x>= soldier.x && snake.x <= soldier.x+40)
            {
                LOSE=true;
                printf("find snake \n");
                death(gRenderer);
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

void Level2::death(SDL_Renderer *gRenderer)
{
    checkWin(gRenderer);
    if (WIN)
        return;
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
void Level2::checkGate()
{
    //gate1.x=750;
    //gate1.y=60;
    //gate2.x=120;
    //gate2.y=490;
    if (soldier.x<gate1.x+40 && soldier.x>gate1.x+25 && soldier.y<48*3)
    {
        soldier.x=gate2.x+60;
        soldier.y=gate2.y;
        return;
    }
    if (soldier.x<gate2.x+55 && soldier.x>gate2.x+40 && soldier.y>10*48)
    {
        soldier.x=gate1.x+20;
        soldier.y=gate1.y;
        return;
    }
    return;
}

bool Level2::okDown()
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
bool Level2::check()
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

void Level2::findKey(SDL_Renderer *gRenderer)
{
    string fileKeyReplace="art/background/key/key1/0.png";
    if (codeKey[(soldier.y+60)/48][(soldier.x+10)/48]!='-')
    {
        printf("FindKey %d\n", numOfKey);
        numOfKey--;
        codeKey[(soldier.y+60)/48][(soldier.x+10)/48]='-';
        matrixKey[(soldier.y+60)/48][(soldier.x+10)/48].loadFromFile(fileKeyReplace, gRenderer);
        return;
    }
    if (codeKey[(soldier.y+60)/48][(soldier.x+30)/48]!='-')
    {
        printf("FindKey %d\n", numOfKey);
        numOfKey--;
        codeKey[(soldier.y+60)/48][(soldier.x+30)/48]='-';
        matrixKey[(soldier.y+60)/48][(soldier.x+30)/48].loadFromFile(fileKeyReplace, gRenderer);

        return;
    }
    return;
}

void Level2::fall(SDL_Renderer *gRenderer)
{
    while (check())
    {
        findKey(gRenderer);
        if (soldier.y%30==0)
            ok=50000-1;
        continueEffect(gRenderer);
        soldier.y++;
        renderImage(gRenderer);
    }
    return;
}


void Level2::continueEffect(SDL_Renderer *gRenderer)
{
    //return;
    ok++;
    if (ok%50000!=0)
        return;
    ok%=50000;
    FIRE++;
    FIRE%=6;
    string fileFire="art/background/fire/1.png";
    fileFire[20]=char(FIRE+1+'0');
    fire.loadFromFile(fileFire, gRenderer);

    GATE++;
    GATE%=10;
    string fileGate="art/background/gate/2.png";
    fileGate[20]=char(GATE+'0');
    gate1.loadFromFile(fileGate, gRenderer);
    gate2.loadFromFile(fileGate, gRenderer);

    SNAKE++;
    SNAKE%=4;
    string fileSnakeLeft="art/snake/Left/1.png";
    string fileSnakeRight="art/snake/right/1.png";
    if (!snakeLeft)
    {
        if (snake.x+50<=19*48-speedSnake)
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
        if (snake.x+50>=10*48+speedSnake)
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

    checkWin(gRenderer);
    checkLose(gRenderer);

    renderImage(gRenderer);
    return;
}


void Level2::handleAction(SDL_Renderer *gRenderer, SDL_Event e)
{
    fall(gRenderer);
    checkGate();
    findKey(gRenderer);
    std:: string rogueRight="art/character/rogue/walkRight/1.png";
    std:: string rogueLeft="art/character/rogue/walkLeft/1.png";
    std:: string rogueClimb="art/character/rogue/climb/1.png";

    checkWin(gRenderer);
    if (!WIN)
        checkLose(gRenderer);

    if (WIN || LOSE)
        return;
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
    checkWin(gRenderer);
    if (!WIN)
        checkLose(gRenderer);
    return;
}


