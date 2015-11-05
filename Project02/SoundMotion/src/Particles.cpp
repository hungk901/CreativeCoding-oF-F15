//
//  Particles.cpp
//  ProjectII
//
//  Created by Ray_Hung on 10/29/15.
//
//

#include "Particles.h"

//------------------------------------------------------------------
void Particles::setup(){
    
    centerPoint.x = ofGetWidth()/2;
    centerPoint.y = ofGetHeight()/2;
    
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
void Particles::update(float _scaledVolume){
    
    //----------01. APPLY FORCE----------//
    
    ofPoint attractPt(ofGetWidth()/2, ofGetHeight()/2);
    
    scaledVolume = _scaledVolume;
    
    scaledVolume *= 1000;
    
    pos.x += scaledVolume * cos(ofRandom(0, 2*PI));
    pos.y += scaledVolume * sin(ofRandom(0, 2*PI));
    
    frc = attractPt-pos;    // Get the attraction force/vector by relativily pos
    frc.normalize();        // by normalizing we disregard how close the particle is to the attraction point
    
    float n = ofMap(scaledVolume, 0, 60, 1, 0.91);
    
    // cout << "n: " << n << endl;
    
    vel *= drag * n;    //apply drag
    vel += frc;         //apply force
    
    
    //----------02. UPDATE POSITION----------//
    
    pos += vel;
    
    
    //----------03. LIMIT PARTICLES IN A CIRCLE----------//
    
    distance = pos - centerPoint;
    if ( sqrtf( powf(fabs(distance.x), 2.0) + powf(fabs(distance.y), 2.0) ) > boundaryRadius){
        distance.normalize();
        pos.x = centerPoint.x + boundaryRadius * distance.x;
        pos.y = centerPoint.y + boundaryRadius * distance.y;
        vel *= -1.0;
    }
}

//------------------------------------------------------------------
void Particles::draw(){
    
    ofCircle(pos.x, pos.y, particleScale * 2.0);
}

