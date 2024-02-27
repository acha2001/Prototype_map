#include "Hero.h"

Hero::Hero()
{

}

Hero::~Hero()
{

}

void Hero::initHero()
{
    heroTexture->loadTexture("images/purple.jpg");
}

void Hero::drawHero()
{
    glColor3f(1.0,1.0,1.0); // colored rectangle
    heroTexture->bindTexture(); // binding background texture

    glPushMatrix();
    glScalef(0.2,0.2,1);

    glBegin(GL_POLYGON); // drawing quad with polygons

        glTexCoord2f(0,0);
        glVertex3f(-0.5,-0.5,-7.0);

        glTexCoord2f(1,0);
        glVertex3f(0.5,-0.5,-7.0);

        glTexCoord2f(1,1);
        glVertex3f(0.5,0.5,-7.0);

        glTexCoord2f(0,1);
        glVertex3f(-0.5,0.5,-7.0);

    glEnd();
    glPopMatrix();
}

