//
//  Ball.cpp
//  Fireworks
//
//  Created by Ray_Hung on 10/8/15.
//
//

#include "Ball.h"

//--------------------------------------------------------------
// Setup many balls.
void Ball::setup(float _xPos,
                 float _yPos,
                 float _xVel,
                 float _yVel,
                 float _xAcc,
                 float _yAcc,
                 float _diameter,
                 ofColor _ballColor,
                 int _state){
    
    pos.x = _xPos;
    pos.y = _yPos;
    vel.x = _xVel;
    vel.y = _yVel;
    acc.x = _xAcc;
    acc.y = _yAcc;
    diameter = _diameter;
    ballColor = _ballColor;
    state = _state;
    
}

//--------------------------------------------------------------
void Ball::update(){
    
    state = 0;
    
    float myTime = ofGetElapsedTimef();
    
    // Update Vel by Acc.
    vel.x += acc.x;
    vel.y += acc.y;
    
    // Update Pos by Vel.
    pos.x += vel.x;
    pos.y += vel.y;
    
    // At the top of first and First Explosion.
    if (pos.x == ofGetWidth()/2 && vel.y == 0) {
        vel.x += ofRandom(-5, 5);
        vel.y += ofRandom(-5, -10);
        acc.y = 0.25;
    }
    
    // Second Explosion.
    if (myTime > 2.1 && myTime < 2.15) {
        state = 1;
    }
    
    if (state == 1) {
        vel.x += ofRandom(-1, 1);
        vel.y += -5;
        acc.y = 0.1;
        diameter = 10;
        ballColor = ofColor(ofRandom(150, 250), ofRandom(150, 250), ofRandom(150, 250));
    }
    
}

//--------------------------------------------------------------
void Ball::draw(){
    
    ofPushStyle();
        ofSetColor(ballColor);
        ofEllipse(pos.x, pos.y, diameter, diameter);
    ofPopStyle();
    
}

//--------------------------------------------------------------
void Ball::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Ball::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Ball::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Ball::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Ball::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Ball::dragEvent(ofDragInfo dragInfo){
    
}
