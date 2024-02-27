#include "MapData.h"

MapData::MapData()
{
    //ctor
}

MapData::~MapData()
{
    //dtor
}


void MapData::readFileData(char* fileName)
{
    std::ifstream inFile;
    inFile.open("C:\\Users\\15597\\Documents\\csci173 and Game Dev\\myGame\\Prototype_map\\mapData\\map1.txt");

    if(inFile.fail()){
        std::cout<<"ERROR::Failed to open map data file"<<std::endl;

    }

    std::vector<float> lineData;
    int lineNumber=0;
    std::string line;

    std::string tmp = "3.14 2.718 1.01";

    float x,y,sizef;
    while(std::getline(inFile, line)){

        std::istringstream iss(line);

        if(iss >> x >> y >> sizef) {
            //std::cout<<"Success"<<std::endl;
            if(lineNumber == 0){
                mapDimensions = std::make_tuple(x,y);
            } else {
            // make tuple for obsticals and push
                obstacle_data.push_back(std::make_tuple(x,y,sizef));
            }


        } else {

            std::cout<<"Error::Map Data Format"<<std::endl;
        }
        lineNumber+=1;
    }
}
