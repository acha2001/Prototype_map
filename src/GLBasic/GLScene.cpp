#include "GLBasics/GLScene.h"

TopDownMap *mp = new TopDownMap();
MapData *myMapData = new MapData(); // this will hold map data
MapMoveHandler *mmh = new MapMoveHandler();

Enemy *enemy = new Enemy();
Hero *hero = new Hero();
GLInput *KbMs = new GLInput();



GLScene::GLScene()
{
    screenWidth= GetSystemMetrics(SM_CXSCREEN);
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
}

GLScene::~GLScene() {}

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH); // for smooth render
    glClearColor(0.5f,0.25f,0.33f,0.8f); // clear background to black
    glClearDepth(2.0f);            // depth test for layers
    glEnable(GL_DEPTH_TEST);       // activate depth test
    glDepthFunc(GL_LEQUAL);         // depth function type

    glEnable(GL_TEXTURE_2D);  //enable textures

    myMapData->readFileData("mapData/map1.txt"); // this needs to be done !!BEFORE!! init map or mmh

    mp->initMap(mmh, myMapData);
    mmh->setMapData(myMapData);
    hero->initHero();
    KbMs->initInput(mmh);
    enemy->initEnemy(mmh, myMapData);


    return true;
}

GLint GLScene::drawScene()    // this function runs on a loop
                              // DO NOT ABUSE ME
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);// clear bits in each itterration
    glLoadIdentity();

    gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,100.0);
    glColor3f(1.0,1.0,0.0);     //color the object red


    glPushMatrix();
        mp->drawMap();
    glPopMatrix();
    glPushMatrix();
        hero->drawHero();
    glPopMatrix();
    glPushMatrix();
        enemy->drawEnemy();
    glPopMatrix();


   return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height; //keep track of the ratio
    glViewport(0,0,width,height); //adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,aspectRatio,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)// check for inputs
    {
        case WM_KEYDOWN:
             KbMs->wParam = wParam;
             KbMs->keyPress();// I don't think this is for player
             KbMs->heroKey(hero);
             break;

         case WM_KEYUP:
             KbMs->wParam = wParam;
             KbMs->keyUP();
             break;

         case WM_LBUTTONDOWN:
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_RBUTTONDOWN:
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
            KbMs->mouseEventUP();
            break;

        case WM_MOUSEMOVE:
            KbMs->mouseMove(LOWORD(lParam), HIWORD(lParam));
            break;

        case WM_MOUSEWHEEL:
            KbMs->wParam = wParam;
            KbMs->mouseWheel((double)GET_WHEEL_DELTA_WPARAM(wParam));
            break;
    }
}
