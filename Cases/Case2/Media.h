#ifndef _media_
#define _media_

#include <iostream>
#include <map>
#include "IObserver.h"

using namespace std;



//Media is a mother class to Television, Radio, Music 

class Media : public IObserver {

    private:

    int id;
    map<int,string> hashNames;
    bool State;

    // Print a signal of the media was started
    void Play(){
        cout << "" << endl;
        cout << "Is playing the media : " << hashNames[id] << endl << endl;
        State = true;
    }

    // Print a signal of the media was stopped
    void Stop(){
        cout << "The media : " << hashNames[id] << " was stopped" << endl << endl;
        State = false;
    }

    public:

    //The constructor of Media

    Media(int pId){
        id = pId;
        State = false;
        hashNames[1] = "Television";
        hashNames[2] = "Radio";
        hashNames[3] = "Youtube";
        hashNames[4] = "Spotify";
    }


    //This function upgrade the state of the media, if the input id  is equals to media id 

    void Update(int pId) override {
        if(id == pId){
            if(State == false){
                Play();
            }
            else{
                Stop();
            }
        }
        else{
            if(State){
                cout << "Other media has been activated." << endl;
                Stop();
            }
        }
    }

    int getId(){
        return this->id;
    }
};



#endif