//
//  myGUI.h
//  eCinemaSetup
//
//  Created by Mick van Olst on 08-11-12.
//
//

#ifndef eCinemaSetup_myGUI_h
#define eCinemaSetup_myGUI_h

#include "ofxUI.h"
#include "mpeClientTCP.h"
#include "chapterHandler.h"

class myGUI {

public:
    myGUI(mpeClientTCP *_cli, handleChapters *_rea);

    void setup(string appID);
    void keyPressed(int key);
    
    void buildGUI(int & i);
    void guiEvent(ofxUIEventArgs &e);

    void setGUI1();
	void setGUI2();
	void setGUI3();
    void exit();
    
    ofxUICanvas *gui1;
	ofxUICanvas *gui2;
	ofxUICanvas *gui3;
    
    bool hideGUI;
    float red, green, blue;
    
    mpeClientTCP *client;
    handleChapters *reader;
    
    string appName;
    
    // All needed values
    float           totalProgress;
    bool            appLaCon;
    bool            appMaCon;
    bool            appRaCon;
    bool            appObj1Con;
    bool            appObj2Con;
    bool            syphonLaOn;
    bool            syphonRaOn;
    
    
    int             activeChap;
    float           chapProgress;
    float           chapCurTime;
    float           chapTotalTime;
    
    // play pause etc btns still to be made
    
    // obj simulator still to be made
    
    // interview syncer still to be made
    
    // msg output still to be made
    
    
    
private:
    
};

#endif