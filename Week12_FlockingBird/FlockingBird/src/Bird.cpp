//
//  Bird.cpp
//  FlockingBird
//
//  Created by Ray_Hung on 11/19/15.
//
//

#include "Bird.h"

//--------------------------------------------------------------
void Bird::setup(){
    
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-2,2);
    acc.x = 0;
    acc.y = 0;
}

//--------------------------------------------------------------
void Bird::update(){
    
    vel += acc;
    pos += vel;
}

//--------------------------------------------------------------
void Bird::draw(){
    
    ofPushStyle();
        ofSetColor(0, 0, 0);
        ofEllipse(pos.x, pos.y, 5, 5);
    ofPopStyle();
}