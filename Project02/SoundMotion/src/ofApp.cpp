#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    audioInput.setup();
    audioInput.soundStream.start();
    
    ofSetVerticalSync(true);
    
    int num = 100;
    p.assign(num, Particles());
    
    particleColor = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    
    resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){
    
    //these are the attraction points used in the forth demo
    attractPoints.clear();
    attractPointsWithMovement = attractPoints;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setAttractPoints(&attractPointsWithMovement);;
        p[i].reset();
    }	
}

//--------------------------------------------------------------
void ofApp::update(){
    
    audioInput.update();
    float vol = audioInput.scaledVol;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].update(vol);
    }
    
    //lets add a bit of movement to the attract points
    for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
        attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 0.1, ofGetElapsedTimef() * 0.7) * 12.0;
        attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -0.1, ofGetElapsedTimef() * 0.7) * 12.0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    audioInput.draw();
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));
    
    //ofSetColor(particleColor);
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
        
        if(i+1 < p.size()){
            ofSetLineWidth(1);
            ofLine(p[i].pos.x, p[i].pos.y, p[i+1].pos.x, p[i+1].pos.y);
        }
    }

    ofSetColor(230);
    ofDrawBitmapString("\n\nSpacebar to reset. \n", 25, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    if( key == ' ' ){
        resetParticles();
    }
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

