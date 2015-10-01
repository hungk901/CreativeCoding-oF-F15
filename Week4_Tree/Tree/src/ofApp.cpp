#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    season = 1;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    ofBackground(250, 250, 250);
    
    //  Spring
    if (key == 'z' || key == 'Z') {
        season = 1;
        myBranches.setup(ofGetWidth()/2,
                         9*ofGetHeight()/10,
                         40,
                         80,
                         0.3,
                         PI/3,
                         2,
                         4,
                         0,
                         -PI/2,
                         0,
                         ofColor(130, 50, 20),
                         season);
    }
    
    //  Summer
    if (key == 'x' || key == 'X') {
        season = 2;
        myBranches.setup(ofGetWidth()/2,
                         9*ofGetHeight()/10,
                         40,
                         80,
                         0.3,
                         PI/3,
                         3,
                         6,
                         0,
                         -PI/2,
                         0,
                         ofColor(130, 50, 20),
                         season);
    }
    
    //  Fall
    if (key == 'c' || key == 'C') {
        season = 3;
        myBranches.setup(ofGetWidth()/2,
                         9*ofGetHeight()/10,
                         40,
                         80,
                         0.3,
                         PI/3,
                         2,
                         4,
                         0,
                         -PI/2,
                         0,
                         ofColor(130, 50, 20),
                         season);
    }
    
    //  Winter
    if (key == 'v' || key == 'V') {
        season = 4;
        myBranches.setup(ofGetWidth()/2,
                         9*ofGetHeight()/10,
                         30,
                         80,
                         0.3,
                         PI/3,
                         2,
                         4,
                         0,
                         -PI/2,
                         0,
                         ofColor(130, 50, 20),
                         season);
    }
    /*branches.setup(float _xPos,
     float _yPos,
     float _width,
     float _length,
     float _splitPercentage,
     float _maxSplitAngle,
     float _maxSubdivisions,
     float _maxSegments,
     float _segmentsSinceStart,
     float _angle,
     float _curvature,
     ofColor _color
     int _season);*/

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
    
    /*
    ofBackground(250, 250, 250);
    myBranches.setup(ofGetWidth()/2,
                     9*ofGetHeight()/10,
                     40,
                     80,
                     0.3,
                     PI/3,
                     2,
                     5,
                     0,
                     -PI/2,
                     0,
                     ofColor(130, 50, 20),
                     season);
    
    /*branches.setup(float _xPos,
                    float _yPos,
                    float _width, 
                    float _length,
                    float _splitPercentage,
                    float _maxSplitAngle,
                    float _maxSubdivisions,
                    float _maxSegments,
                    float _segmentsSinceStart,
                    float _angle,
                    float _curvature,
                    ofColor _color
                    int _season);*/
    /*
    season += 1;
    if (season > 4) {
        season = 1;
    }
    */

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
