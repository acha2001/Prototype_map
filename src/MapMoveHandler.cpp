#include "MapMoveHandler.h"

MapMoveHandler::MapMoveHandler() {}

MapMoveHandler::~MapMoveHandler() {}

void MapMoveHandler::setMapData(MapData *mapData_)
{
    mapData = mapData_;
}


float MapMoveHandler::get_x_pos(float delta_t, float prev_x)
{
    return (x_a*delta_t*-1)+prev_x;
}
float MapMoveHandler::get_y_pos(float delta_t, float prev_y)
{
    return (y_a*delta_t*-1)+prev_y;
}

void MapMoveHandler::setAcceleration(std::string dir)
{

    if (dir=="left")
    {
        x_a=-1;
        dec_x=false;
    }
    if (dir=="right")
    {
        dec_x=false;
        x_a=1;
    }
    if (dir=="up")
    {
        dec_y=false;
        y_a=1;
    }
    if (dir=="down")
    {
        dec_y=false;
        y_a=-1;
    }
}

void MapMoveHandler::setDeceleration(std::string dir)
{

    if (dir=="left" || dir=="right")
    {
        x_a=0
        ;
    }
    if (dir=="up" || dir=="down")
    {
        dec_y=true;
        y_a=0;
    }
}
