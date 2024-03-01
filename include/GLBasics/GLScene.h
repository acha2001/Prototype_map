#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include <Common.h>

#include <map/MapMoveHandler.h>
#include <map/TopDownMap.h>
#include <Hero.h>
#include <Enemy.h>
#include <map/MapData.h>

#include <GLBasics/GLTexture.h>
#include <GLBasics/GLInput.h>


using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();

        GLint initGL();
        GLint drawScene();
        GLvoid resizeScene(GLsizei, GLsizei);

        int windMsg(HWND,UINT,WPARAM,LPARAM);  // take windows inputs
        WPARAM wParam; //keyboard mouse msg

        // get values from main
        float screenWidth;
        float screenHeight;

    protected:

    private:
};

#endif // GLSCENE_H
