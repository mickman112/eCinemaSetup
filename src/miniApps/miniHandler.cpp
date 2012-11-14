//
//  miniHandler.cpp
//  eCinemaSetup
//
//  Created by Mick van Olst on 13-11-12.
//
//

#include "miniHandler.h"

//--------------------------------------------------------------
miniHandler::miniHandler(mpeClientTCP * _cli){
    client = _cli;
    main = new mainMini(client);
    curMiniApp = "";
    
    myTestMini = NULL; // otherwise it will trigger anyways..
}

//--------------------------------------------------------------
void miniHandler::setup(string id){
    appName = id;
    main->setup(appName);
    
    //startMini("01_TestMini"); // for some reason this only works when triggered at start, not through broadcast..
    
    // Listeners
    ofAddListener(main->doneEvent, this, &miniHandler::stopMini);
}

//--------------------------------------------------------------
void miniHandler::update(){
    // not yet finished here, need to figure out how to do this with several mini apps etc
    if (myTestMini != NULL && curMiniApp == "01_TestMini") {
        myTestMini->update();
    }
}

//--------------------------------------------------------------
void miniHandler::draw(){
    // not yet finished here, need to figure out how to do this with several mini apps etc
    if (myTestMini != NULL && curMiniApp == "01_TestMini") {
        myTestMini->draw();
    }
}

//--------------------------------------------------------------
void miniHandler::checkNextApp(string prevChapter){
    if (prevChapter == "02_Rise of the Guardians") {
        //startMini("01_TestMini");
        client->broadcast("playMiniApp,01_TestMini");
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------------------
bool miniHandler::appComesAfter(string prevChapter){
    if (prevChapter == "02_Rise of the Guardians") {
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------------------
void miniHandler::startMini(string wichApp){
    // not yet finished here, need to figure out how to do this with several mini apps etc
//    int myInt;
//    stopMini(myInt);
    if (wichApp == "01_TestMini") {
        myTestMini = new testMini(main);
        myTestMini->setup();
        curMiniApp = "01_TestMini";
    }
    printf("curMiniApp: %s\n",curMiniApp.c_str());
}

//--------------------------------------------------------------
void miniHandler::stopMini(int & i){
    // not yet finished here, need to figure out how to do this with several mini apps etc
    printf("mini app said it's time for bed\n");
    
    if (curMiniApp == "01_TestMini" && myTestMini != NULL) {
        delete myTestMini;
        myTestMini = NULL;
    }
}

//--------------------------------------------------------------
void miniHandler::killMini(){
    
}