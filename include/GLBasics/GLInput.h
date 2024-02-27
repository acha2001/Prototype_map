#ifndef GLINPUT_H
#define GLINPUT_H

#include <TopDownMap.h>
#include <MapMoveHandler.h>
#include <Common.h>

class GLInput
{
    public:
        GLInput();
        virtual ~GLInput();

        MapMoveHandler *mmh;

        void initInput(MapMoveHandler *mmh_);

        void keyPress();      // when key pressed
        void keyUP();         // when key released

        void mouseEventDown(double, double); // mouse button pressed
        void mouseEventUP();                                // mouse button released
        void mouseWheel(double);              // mouse wheel rolled
        void mouseMove(double,double);       // mouse moved

        double prev_MouseX;      // current mouse location X before action
        double prev_MouseY;      // current mouse location Y before action

        bool mouse_Translate;    // if mouse moved
        bool mouse_Rotate;       // if mouse moved for rotation

        WPARAM wParam;           // catching input interrupts



    protected:

    private:
};

#endif // GLINPUT_H
