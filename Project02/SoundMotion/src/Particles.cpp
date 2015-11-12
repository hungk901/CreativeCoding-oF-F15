//
//  Particles.cpp
//  ProjectII
//
//  Created by Ray_Hung on 10/29/15.
//
//

#include "Particles.h"

//------------------------------------------------------------------
void Particles::modeSetting(modeSelection newMode){
    mode = newMode;
}

//------------------------------------------------------------------
void Particles::setAttractPoints( vector <ofPoint> * attract ){
    attractPoints = attract;
}

//------------------------------------------------------------------
void Particles::setup(){
    
    randomValue = ofRandom(-10000, 10000);
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    vel.x = (10 * cos(ofRandom(0, 2*PI)));
    vel.y = (10 * sin(ofRandom(0, 2*PI)));
    
    frc   = ofPoint(0,0,0);
    drag  = ofRandom(0.95, 0.998);
    particleScale = ofRandom(0.5, 1.0);
    
    boundaryRadius = 375.0;
}

//------------------------------------------------------------------
void Particles::update(float _scaledVolume, ofPoint _centerPoint){
    
    //---------- 00. Pass Parameters --------------------//
    
    scaledVolume  = _scaledVolume;
    centerPoint.x = _centerPoint.x;
    centerPoint.y = _centerPoint.y;
    
    
    //---------- 01. FREE FLOW MODE --------------------//
    
    if (mode == MODE_FREE_FLOW) {
        
        ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
        frc = attractPt-pos;
        
        // Particles close to the mouse
        float dist = frc.length();
        frc.normalize();
        
        vel *= drag;
        if (dist < 150) {
            vel += -frc;
        }
        else {
            frc.x = ofSignedNoise(randomValue, pos.y * 0.01, ofGetElapsedTimef()*0.2);
            frc.y = ofSignedNoise(randomValue, pos.x * 0.01, ofGetElapsedTimef()*0.2);
            vel += frc * 0.04;
        }
    }
    
    //---------- 02. DRAG AROUND --------------------//
    
    else if (mode == MODE_DRAG_AROUND) {
        
        ofPoint attractPt(centerPoint.x, centerPoint.y);
        
        frc = attractPt-pos;
        frc.normalize();
        
        vel *= drag;
        vel += frc*0.5;
    }
    
    
    //---------- 03. SOUND MOTION --------------------//
    
    else if (mode == MODE_SOUND_MOTION) {
    
        ofPoint attractPt(centerPoint.x, centerPoint.y);
    
        scaledVolume *= 1000;
    
        pos.x += scaledVolume * cos(ofRandom(0, 2*PI));
        pos.y += scaledVolume * sin(ofRandom(0, 2*PI));
    
        frc = attractPt-pos;
        frc.normalize();
    
        float n = ofMap(scaledVolume, 0, 60, 1, 0.91);

        vel *= drag * n;
        vel += frc;
    }
    
    
    //---------- 03. UPDATE POSITION ----------//
    
    pos += vel;
    
    
    //---------- 04. BOUNDARY ----------//
    
    if (mode == MODE_FREE_FLOW) {
        if (pos.x > ofGetWidth()) {
            pos.x = ofGetWidth();
            vel.x *= -1.0;
        }
        if (pos.x < 0) {
            pos.x = 0;
            vel.x *= -1.0;
        }
        
        if (pos.y > ofGetHeight()) {
            pos.y = ofGetHeight();
            vel.y *= -1.0;
        }
        if (pos.y < 0) {
            pos.y = 0;
            vel.y *= -1.0;
        }
    }
    
    else if (mode == MODE_DRAG_AROUND || mode == MODE_SOUND_MOTION) {
        distance = pos - centerPoint;
        if ( sqrtf( powf(fabs(distance.x), 2.0) + powf(fabs(distance.y), 2.0) ) > boundaryRadius){
            distance.normalize();
            pos.x = centerPoint.x + (boundaryRadius * distance.x);
            pos.y = centerPoint.y + (boundaryRadius * distance.y);
            vel *= -1.0;
        }
    }
}

//------------------------------------------------------------------
void Particles::draw(){
    ofCircle(pos.x, pos.y, particleScale * 2.0);
}

