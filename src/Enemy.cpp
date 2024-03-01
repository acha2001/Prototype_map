#include "Enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::initEnemy(MapMoveHandler *mmh_, MapData *mapData_)
{
    enemyTexture->loadTexture("images/pink.jpg");
    mmh = mmh_;
    mapData = mapData;
}

void Enemy::drawEnemy() {

    glColor3f(1.0,1.0,1.0); // colored rectangle

    if(!sleeping)
        moveEnemy(); // -> this makes enemy position change

    enemyTexture->bindTexture(); // binding background texture
    glTranslatef(mmh->x_pos, mmh->y_pos, 0);// move the enemy with the map
    glTranslatef(x_pos,y_pos,0);

    glScalef(0.2,0.2,1);

    glPushMatrix();
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

void Enemy::moveEnemy() {

    if(clock()-st_time>30){

        // player is at 10,10 and enemy is at 1,1
        // player is at 9,9 and enemy is at 0,0
        // Calculate the differences in coordinates
        double delta_x = ((double)mmh->x_pos*-1) - (double)x_pos;
        double delta_y = ((double)mmh->y_pos*-1) - (double)y_pos;

        // Calculate the angle using atan2
        double angle_radians = atan2(delta_y, delta_x);

        // Convert radians to degrees
        double angle_degrees = angle_radians * (180.0 / M_PI);

        // Ensure angle is in [0, 360) degrees
        if (angle_degrees < 0) {
            angle_degrees += 360.0;
        }

        double na_r = angle_degrees*(M_PI/180);

       x_pos+=speed*cos(na_r);
       y_pos+=speed*sin(na_r);

        st_time=clock();

    }
}

void Enemy::setPosition(float x, float y) {

    x_pos=x;
    y_pos=y;

}
