//
//  interview_bezoekers.h
//  eCinemaSetup
//
//  Created by Mick van Olst on 16-12-12.
//
//

#ifndef eCinemaSetup_interview_bezoekers_h
#define eCinemaSetup_interview_bezoekers_h

#include "mainMini.h"
#include "ofxOsc.h"
#include "ofxXmlSettings.h"

class interview_bezoekers {
public:
    interview_bezoekers();
    
    void init(mainMini *_mai, ofxOscSender *_osc);
    void setup();
    void update();
    void draw();
    void endOfMini();
    void loadXML(string file, bool printResult);
    void exit();
    
    string afterChapter;
    
    ofxOscSender *oscOut;
    mainMini *main;
    
private:
    void drawViewPorts(int numPorts);
    
    int initTime;
    int durTime;
    
    int curVid;
    int rotateVideos;
    
    ofDirectory           files;
    ofxXmlSettings        XML;
    
    struct smartClip {
        ofVideoPlayer   vid;
        ofRectangle     viewport;
        ofVec2f         vidpos;
        bool            onScreen;
        int             inFrame;
        int             duration;
        int             outFrame;
        string          filename;
    };
    vector<smartClip> videos;
};


#endif
