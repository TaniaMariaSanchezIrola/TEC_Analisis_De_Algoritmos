#ifndef _radio_
#define _radio_

#include "Media.h"


class Radio : public Media{

    private:
    double frequency = 90.0;
    
    void SetFrequency(int pfrequency){
        frequency = pfrequency;
    }

    public:
    Radio(int pId):Media(pId){}

    double GetFrequency(){
        return frequency;
    }


    void ChangeFrequency(int pfrequency){
        cout << "" << endl;
        cout << "Changed the frequency " << frequency << " to frequency " << pfrequency << endl;
        SetFrequency(pfrequency);
    }

};

#endif