#ifndef MAPDATA_H
#define MAPDATA_H

#include <Common.h>
#include <fstream>
#include <sstream>


class MapData
{
    public:
        MapData();
        virtual ~MapData();

        void readFileData(char *fileName);

        std::tuple <float,float> mapDimensions;
        std::vector <std::tuple <float,float,float>> obstacle_data;






    protected:

    private:
};

#endif // MAPDATA_H
