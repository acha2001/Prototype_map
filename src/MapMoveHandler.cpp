#include "MapMoveHandler.h"

MapMoveHandler::MapMoveHandler() {}

MapMoveHandler::~MapMoveHandler() {}

void MapMoveHandler::setMapData(MapData *mapData_)
{
    mapData = mapData_;

    std::cout <<"SETING MAP DATA"<<std::endl;
    makeBoundingBoxes();
    for(auto&& tuple: mapData->obstacle_data)
    {
        float obs_x,obs_y,obs_sizef;
        std::tie(obs_x, obs_y, obs_sizef) = tuple;


        boundBox temp;
        temp.topLeft.x=obs_x-(obs_sizef/2);
        temp.topLeft.y=obs_y+(obs_sizef/2);

        temp.bottomRight.x=obs_x+(obs_sizef/2);
        temp.bottomRight.y=obs_y-(obs_sizef/2);

        Boxes.push_back(temp);

        std::cout<<"TL_x = "<<temp.topLeft.x<<", TL_y = "<<temp.topLeft.y<<std::endl;
        std::cout<<"BR_x = "<<temp.bottomRight.x<<", BR_y = "<<temp.bottomRight.y<<std::endl;
    }
    std::cout<<Boxes.size()<<std::endl;
    //std::cout<<"TL_x = "<<Boxes[0].topLeft.x<<", TL_y = "<<Boxes[0].topLeft.y<<std::endl;
    //std::cout<<"BR_x = "<<Boxes[0].bottomRight.x<<", BR_y = "<<Boxes[0].bottomRight.y<<std::endl;
}

void MapMoveHandler::makeBoundingBoxes()
{
    std::cout<<mapData->obstacle_data.size()<<std::endl;
}

bool MapMoveHandler::envCollision(int dim)
{

    bool x_positive = x_pos<=((std::get<0>(mapData->mapDimensions))/2)-0.1;
    bool x_negative = x_pos>=((std::get<0>(mapData->mapDimensions))/-2)+0.1;

    bool y_positive = y_pos<=((std::get<1>(mapData->mapDimensions))/2)-0.1;
    bool y_negative = y_pos>=((std::get<1>(mapData->mapDimensions))/-2)+0.1;

    if (dim==1 && x_positive && x_negative) {
        return false;
    }
    if (dim==2 && y_positive && y_negative) {
        return false;
    }

    for(auto&& tuple: mapData->obstacle_data)
    {
        float obs_x,obs_y,obs_sizef;
        std::tie(obs_x, obs_y, obs_sizef) = tuple;

    }

    return true;
}

bool MapMoveHandler::obstacleCollision(int dim) {

    for(int i=0;i<Boxes.size();i++) {
        bool in_x = -x_pos<Boxes[i].bottomRight.x+0.1 && -x_pos>Boxes[i].topLeft.x-0.1;
        bool in_y = -y_pos>Boxes[i].bottomRight.y-0.1 && -y_pos<Boxes[i].topLeft.y+0.1;
        if (in_x && in_y) {
            return true;
        }
    }
    return false;
}

float MapMoveHandler::get_x_pos(float delta_t)
{
    x_pos+=(x_a*delta_t*-1);
    if(envCollision(1) || obstacleCollision(1)) {
        x_pos-=(x_a*delta_t*-1);
        return x_pos;
    }
    return x_pos;
}
float MapMoveHandler::get_y_pos(float delta_t)
{
    y_pos+=(y_a*delta_t*-1);
    if (envCollision(2)||obstacleCollision(2)) {
        y_pos-=(y_a*delta_t*-1);
        return y_pos;
    }

    return y_pos;
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
