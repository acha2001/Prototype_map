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

void Hero::attack()
{
    if (attacking) {
        return;
    }
    attack_timer = clock();
    attacking=true;
    hero_size+=ATTACK_R;
}

void Hero::drawHero()
{
    if(attacking && clock()-attack_timer > 250) {
        attacking = false;
        hero_size = 0.2;
    }

    glColor3f(1.0,1.0,1.0); // colored rectangle
    heroTexture->bindTexture(); // binding background texture

    glPushMatrix();
    glScalef(hero_size,hero_size,1);

    glBegin(GL_POLYGON); // drawing quad with polygons

        glTexCoord2f(0,0);
        glVertex3f(-0.5,-0.5,-8.0);

        glTexCoord2f(1,0);
        glVertex3f(0.5,-0.5,-8.0);

        glTexCoord2f(1,1);
        glVertex3f(0.5,0.5,-8.0);

        glTexCoord2f(0,1);
        glVertex3f(-0.5,0.5,-8.0);

    glEnd();
    glPopMatrix();
}

