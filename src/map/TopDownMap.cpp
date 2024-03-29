#include "map/TopDownMap.h"

TopDownMap::TopDownMap() {}

TopDownMap::~TopDownMap() {

}

void TopDownMap::initMap(MapMoveHandler *mmh_, MapData *mpd_)
{
    mmh=mmh_;
    mapData=mpd_;

    freeTexture->loadTexture("images/green.jpg");
    closedTexture->loadTexture("images/red.jpg");

    obstical_positions.push_back(std::make_tuple(1.0,-2.0));
    obstical_positions.push_back(std::make_tuple(-0.5,3.0));
}

void TopDownMap::drawMap()
{
    // This is the main function and should only be called by main

    glColor3f(1.0,1.0,1.0); // colored rectangle
    freeTexture->bindTexture(); // binding background texture

    glPushMatrix(); // main block


    moveMap(); // get x and y positions
    glTranslatef(mmh->x_pos, mmh->y_pos, 0.0);// setting position of map;

    glPushMatrix();

        glScalef(std::get<0>(mapData->mapDimensions), // width
                 std::get<1>(mapData->mapDimensions), // height
                 1.0); // dont scale y

        drawTile();

    glPopMatrix();

    closedTexture->bindTexture();


    for(auto&& tuple: mapData->obstacle_data) {

        float x,y,sizef;
        std::tie(x, y, sizef) = tuple;

        glPushMatrix();

            glTranslatef(x,y,0);
            glScalef(sizef,sizef, 1);
            drawTile();

        glPopMatrix();
    }


    glPopMatrix(); // end drawing of env


}
void TopDownMap::moveMap()
{
    if(difftime(clock(), st_time) > 30) {
        float delta_t = 0.03;
        x_pos = mmh->get_x_pos(delta_t);
        y_pos = mmh->get_y_pos(delta_t);

        st_time=clock();
    }
}

void TopDownMap::drawTile() {

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
