//
//  Bird.h
//  FlockingBird
//
//  Created by Ray_Hung on 11/19/15.
//
//
#pragma once

#include "ofMain.h"

class Bird : public ofBaseApp{
    
    public:
        void setup();
        void update();
        void draw();
    
        ofPoint pos, vel, acc;  // Variables: Position, Velocity, Accelaration
};


