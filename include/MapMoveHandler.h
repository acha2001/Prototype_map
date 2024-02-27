#ifndef MAPMOVEHANDLER_H
#define MAPMOVEHANDLER_H

#include <Common.h>
#include <MapData.h>


/*

    THIS CLASS HANDLES MAP MOVEMENTS I.E. PLAYER POSITIONS MAYBE ENEMIES

*/


class MapMoveHandler
{
    public:

        MapMoveHandler();
        virtual ~MapMoveHandler();

        MapData *mapData;
        void setMapData(MapData *mapData_);


        float get_x_pos(float delta_t, float prev_x);
        float get_y_pos(float delta_t, float prev_y);

        void setAcceleration(std::string dir);
        void setDeceleration(std::string dir);

    protected:

    private:

        float x_a=0; // x velocity
        float y_a=0; // y velocity

        float x_v=0;
        float y_v=0;

        float x_pos=0;
        float y_pos=0;

        bool dec_x;
        bool dec_y;
};

#endif // MAPMOVEHANDLER_H
