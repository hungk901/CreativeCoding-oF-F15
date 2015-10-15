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
    numBoxs = ofRandom(5, 10);
    numBalls = ofRandom(5, 10);
    
    for (int j = 0; j < numBoxs; j++) {
    
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
                   25,
                   
                   // Ball Color
                   // ofColor(ofRandom(255), ofRandom(255), ofRandom(255))
                   ofColor(255),
                   
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
    for (int j = 0; j < numBoxs; j++) {
        for(int i = 0; i < numBalls; i++) {
            ballsBox[j][i].update();
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushStyle();
        ofSetColor(0, 0, 0, 25);
        ofRect(0,0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    
    for (int j = 0; j < numBoxs; j++) {
        
        for(int i = 0; i < numBalls; i++) {
            
            if(ballsBox[j][i].state == 0 || ballsBox[j][i].state == 1) {

                ballsBox[j][0].draw();
                
            }
            
            if (ballsBox[j][i].state == 2) {
                
                ballsBox[j][0].draw();
            
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
