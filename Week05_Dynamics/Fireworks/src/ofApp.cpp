#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);            // Background color.
    ofSetFrameRate(60);         // Frame rate 60/sec.
    ofEnableAlphaBlending();    // Allow transparency.
    ofSetBackgroundAuto(false);  // True = Auto draw.

}

//--------------------------------------------------------------
void ofApp::fireworkTrigger(){
    
    manyBalls.clear();
    ballsBox.clear();
    
    // Setup many balls
    numBoxs = ofRandom(10, 15);
    numBalls = ofRandom(10, 15);
    
    for (int n = 0; n < numBoxs; n++) {
    
        for(int i = 0; i < numBalls; i++) {
        Ball temp;
        temp.setup(// xPos
                   ofGetWidth()/2,
                   
                   // yPox
                   ofGetHeight(),
                   
                   // xVel
                   0,
                   
                   // yVel
                   -25,
                   
                   // xAcc
                   0,
         
                   // yAcc
                   .5,
                   
                   // Diameter
                   15,
                   
                   // Ball Color
                   ofColor(ofRandom(200, 250), ofRandom(200, 250), ofRandom(200, 250)),
                   
                   //
                   0
                   );
            manyBalls.push_back(temp);
        }
        ballsBox.push_back(manyBalls);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // Update many balls
    for (int n = 0; n < numBoxs; n++) {
        for(int i = 0; i < numBalls; i++) {
            ballsBox[n][i].update();
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushStyle();
        ofSetColor(0, 0, 0, 25);
        ofRect(0,0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    
    for (int n = 0; n < numBoxs; n++) {
        for(int i = 0; i < numBalls; i++) {
            
            ballsBox[n][0].draw();
            
            if (ofGetElapsedTimef() > 2.1) {
                ballsBox[n][i].draw();
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    ofResetElapsedTimeCounter();
    fireworkTrigger();

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
