#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //--- Synchronizes the Redraw to the Vertical Refresh of Screen ---//
    
    ofSetVerticalSync(true);
    
    
    //----- Audio Setup -----//
    
    audioInput.setup();
    audioInput.soundStream.start();
    
    
    //----- Setup Particle Numbers -----//
    
    int num = 100;
    p.assign(num, Particles());
    
    isGrabbed = false;
    
    resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){
    
    //----- Initial CenterPoints -----//
    
    ctrPoint.x = ofGetWidth()/2;
    ctrPoint.y = ofGetHeight()/2;
    
    
    //----- Random Color -----//
    
    colorR = ofRandom(100, 255);
    colorG = ofRandom(100, 255);
    colorB = ofRandom(100, 255);
    addColorR = addColorG = addColorB = 2;
    
    
    //----- !!SETUP each Particle!! -----//
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setup();
    }	
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //----- Audio Update -----//
    audioInput.update();
    float vol = audioInput.scaledVol;
    
    //----- Grab the Whole Sets -----//
    if (isGrabbed == true) {
        ctrPoint.x = mouseX;
        ctrPoint.y = mouseY;
    }
    else {
        ctrPoint.x = ofGetWidth()/2;
        ctrPoint.y = ofGetHeight()/2;
    }
    
    //----- Change Color per Frame -----//
    colorR += addColorR;
    colorG += addColorG;
    colorB += addColorB;
    
    if (colorR > 255 || colorR < 100) {
        addColorR *= -1;
    }
    if (colorG > 255 || colorG < 100) {
        addColorG *= -1;
    }
    if (colorB > 255 || colorB < 100) {
        addColorB *= -1;
    }
    
    //----- !!UPDATE each Particle!! -----//
    for(int i = 0; i < p.size(); i++){
        p[i].update(vol, ctrPoint);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //----- Draw Gradient Background -----//
    ofBackgroundGradient(ofColor(0), ofColor(80));
    
    //----- Draw Particles and Draw Lines -----//
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
    
        if(i+1 < p.size()){
            ofSetLineWidth(1);
            ofLine(p[i].pos.x, p[i].pos.y, p[i+1].pos.x, p[i+1].pos.y);
        }
    }
    ofSetColor(colorR, colorG, colorB);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

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
    
    if (!isGrabbed) {
        isGrabbed = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    isGrabbed = false;
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

