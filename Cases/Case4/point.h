#ifndef _point_
#define _point_
#include <string>

class Point{
public:
    Point(){
        this->x = 0;
        this->y = 0;
    }

    Point(int pX, int pY){
        this->x = pX;
        this->y = pY;
    }

    void addDistance(int pDistance){
        this->x+=pDistance;
        this->y+=pDistance;
    }

    Point* clonePoint(){
        return new Point(this->x, this->y);
    }

    std::string toString(){
        return std::to_string(this->x)+";"+std::to_string(this->y)+";";
    }

    int x;
    int y;
};

#endif
