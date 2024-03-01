#ifndef TOPDOWNMAP_H
#define TOPDOWNMAP_H

#include <Common.h>
#include <GLBasics/GLTexture.h>
#include <map/MapMoveHandler.h>
#include <time.h>
#include <map/MapData.h>
#include <Enemy.h>


/*

    THIS CLASS RENDERS MAP AND FEATURES AS WELL AS HANDLES MAP CHANGES

*/


class TopDownMap
{
    public:

        TopDownMap();
        virtual ~TopDownMap();

        // create some obsticles
        MapData *mapData;

        double map_size_x = 5;
        double map_size_y = 10;

        double obstical_size = 1;

        std::vector<std::tuple<float, float>>  obstical_positions;



        GLTexture *freeTexture = new GLTexture(); //places that can be walked on
        GLTexture *closedTexture = new GLTexture(); // places that cant be walked on

        MapMoveHandler *mmh;

        void initMap(MapMoveHandler *mmh, MapData *mpd);
        void drawMap();

        void setAcceleration(std::string dir);
        void setDeceleration(std::string dir);

    protected:

    private:
        clock_t st_time = clock();
        void drawTile();
        void moveMap();

        float x_pos=0;
        float y_pos=0;
};

#endif // TOPDOWNMAP_H
