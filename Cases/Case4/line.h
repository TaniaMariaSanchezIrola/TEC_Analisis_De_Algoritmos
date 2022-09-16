#ifndef _line_
#define _line_

#include "point.h"
#include <vector>
#include <iostream>
#include <string>
#include "auxFunctions.h"

class Line{
    public:
        int large;
        bool orientation; //True to horizontal, false to vertical
        Point *initialPoint, *finalPoint;
        std::vector<Point*>* referenceListPoints;

        Line(int pLarge, bool pOrientantion, int originX, int originY){
            referenceListPoints=new std::vector<Point*>();
            this->large=pLarge;
            this->orientation=pOrientantion;
            this->initialPoint=new Point(originX, originY);
            this->finalPoint=new Point(originX, originY);
            if(orientation)
                this->finalPoint=new Point(originX+this->large, originY);
            else
                this->finalPoint=new Point(originX, originY+this->large);
        }

        void setNoise(double pNoisePercentage){ //96nr + 532n + 10
            int noiseSize=getRandom(1, this->large-(this->large*(pNoisePercentage/100)));
            int referencePointsAmount=getRandom(1, this->large/10);
            int distance=noiseSize/referencePointsAmount;
            if(orientation){
                int noiseOrigin=getRandom(this->initialPoint->x, this->finalPoint->x - noiseSize);
                int noiseFinal=noiseOrigin-noiseSize;
                for(int index=0; index <referencePointsAmount; index++){
                    referenceListPoints->push_back(new Point(noiseOrigin+(distance*index), this->initialPoint->y+getRandom(-9,9)));
                }
            }else{
                int noiseOrigin=getRandom(this->initialPoint->y, this->finalPoint->y - noiseSize);
                int noiseFinal=noiseOrigin-noiseSize;
                for(int index=0; index <referencePointsAmount; index++){
                    
                    referenceListPoints->push_back(new Point(this->initialPoint->x+getRandom(-5,5), noiseOrigin+(distance*index)));
                }
            }
        }


        void toString(){
            std::cout<<"Punto inicial: "<<this->initialPoint->toString()<<" Punto Final: "<<this->finalPoint->toString()<<"\n";
            if(this->referenceListPoints->size()>0){
                std::cout<<"Puntos de referencia: "<<"\n";
                for(int i=0; i<this->referenceListPoints->size(); i++){
                    std::cout<<this->referenceListPoints->at(i)->toString()<<"\n";
                }
            }
        }
};

#endif
