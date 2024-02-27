#include "GLBasics/GLInput.h"

GLInput::GLInput()
{
    prev_MouseX =0;
    prev_MouseY =0;

    mouse_Translate =0;
    mouse_Rotate =0;
}

GLInput::~GLInput() {}

void GLInput::initInput(MapMoveHandler *mmh_)
{
    mmh=mmh_;
}

void GLInput::keyPress()
{
    switch(wParam)

    {
    case VK_LEFT:
        mmh->setAcceleration("left");
        break;

    case VK_RIGHT:
        mmh->setAcceleration("right");
        break;

    case VK_DOWN:
        mmh->setAcceleration("down");
        break;

    case VK_UP:
        mmh->setAcceleration("up");
        break;
    case VK_SPACE:
        std::cout<<"Space"<<std::endl;
        break;
    }
}
void GLInput::keyUP()
{
    switch(wParam)

    {
    case VK_LEFT:
        mmh->setDeceleration("left");
        break;

    case VK_RIGHT:
        mmh->setDeceleration("right");
        break;

    case VK_DOWN:
        mmh->setDeceleration("down");
        break;

    case VK_UP:
        mmh->setDeceleration("up");
        break;

    case VK_SPACE:
        std::cout<<"Space up"<<std::endl;
        break;
    }
}
void GLInput::mouseEventDown(double x, double y)
{

    prev_MouseX = x;        // keep previous x value
    prev_MouseY = y;        // keep previous y value

    switch (wParam)
    {
    case MK_LBUTTON:
        mouse_Rotate = true;    // set rotation flag
        break;
    case MK_RBUTTON:
        mouse_Translate = true; // set translation flag
        break;
    case MK_MBUTTON:
        // something you like to add for middle mouse button
        break;


        default:
        break;
    }
}
void GLInput::mouseEventUP()
{
    mouse_Rotate = false;       // reset rotation flag
    mouse_Translate = false;    // reset translation flag

}
void GLInput::mouseWheel(double delta)
{
    //mdl->zPos += delta/100.0;    // mouse wheel movement
}


void GLInput::mouseMove( double x , double y)
{
    if(mouse_Translate)
    {
        //mdl->xPos += (x-prev_MouseX)/100.0;   // move model in x direction
        //mdl->yPos -= (y-prev_MouseY)/100.0;   // move model in y direction | 0,0 is at the top for y coordinate w/mouse

        prev_MouseX = x;                        // update previous mouse x
        prev_MouseY = y;                        // update previous mouse y
    }

    if(mouse_Rotate)
    {
        //mdl->RotateY += (x-prev_MouseX)/3.0;     // model rotation on X direction
        //mdl->RotateX += (y-prev_MouseY)/3.0;     // model rotation on Y direction

        prev_MouseX = x;                        // update previous mouse x
        prev_MouseY = y;                        // update previous mouse y
    }
}


