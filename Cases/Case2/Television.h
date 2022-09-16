#ifndef _television_
#define _television_

#include "Media.h"

class Television : public Media {

    private:
    int Channel = 1;
    
    void SetChannel(int pChannel){
        Channel = pChannel;
    }

    public:
    Television(int pId):Media(pId){}

    int GetChannel(){
        return Channel;
    }

    void ChangeChannel(int pChannel){
        cout << "" << endl;
        cout << "Changed the channel " << Channel << " to channel " << pChannel << endl;
        SetChannel(pChannel);
    }

};

#endif