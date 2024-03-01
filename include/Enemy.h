#ifndef ENEMY_H
#define ENEMY_H

#include <Common.h>

#include <GLBasics/GLTexture.h>
#include <map/MapMoveHandler.h>
#include <map/MapData.h>

class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();

        GLTexture *enemyTexture = new GLTexture();

        void initEnemy(MapMoveHandler *mmh_, MapData *mapData_);
        void drawEnemy();

        void setPosition(float x, float y);

    protected:

    private:

        void moveEnemy();
        bool sleeping = false;

        float x_pos=0;
        float y_pos=0;

        float speed=0.01;

        time_t st_time=clock();
        MapMoveHandler *mmh;
        MapData *mapData;
};

#endif // ENEMY_H
