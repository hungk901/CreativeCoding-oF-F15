#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
    
    ofBackground(250, 250, 250);
    myBranches.setup(ofGetWidth()/2,
                     ofGetHeight()/2,
                     40, 40,
                     0.3,
                     2, 8, 0,
                     PI/2, 0,
                     ofColor(150, 50, 20));
    
    /*branches.setup(float _xPos,
                    float _yPos,
                    float _width, 
                    float _length,
                    float _splitPercentage,
                    float _maxSubdivisions,
                    float _maxSegments,
                    float _segmentsSinceStart,
                    float _angle,
                    float _curvature,
                    ofColor _color);*/

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
