#ifndef _matrix_
#define _matrix_
#include <vector>
#include "square.h"
#include <random>
#include "point.h"
using namespace std;
const int PIXELS=10;
class Matrix{
    private:
        void createSquare(int pSize, double pPercentageNoise, Point* pOriginPoint){ //10 + n ( 6 + 8 + 2 + 6 + *map* )
            Square* square=new Square(pSize, pPercentageNoise, pOriginPoint->clonePoint()); //
            squares->push_back(square);     //2
        }
    public:
        int amountSquares, width, height;
        std::vector<Square*>* squares;

        Matrix(int pHeight, int pWidth){
            this->squares=new std::vector<Square*>();   //2
            this->width=pWidth;                         //1
            this->height=pHeight;                         //1
            this->amountSquares=(pHeight <= pWidth ? pHeight : pWidth)/(PIXELS*2);  //4
            double percentageNoise=0;                   //1
            Point* initialPoint=new Point(0,0);         //4
            for(int index=amountSquares; index>=1; index--){    //10 + n ( 6 + 8 ( *mapping...* ))
                createSquare(index*PIXELS*2, percentageNoise, initialPoint);
                initialPoint->addDistance(PIXELS);      
                percentageNoise+=(100/amountSquares);
            }
        }
        //10 + 14n
};

#endif