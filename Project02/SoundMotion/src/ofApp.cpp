#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //--- Synchronizes the Redraw to the Vertical Refresh of Screen ---//
    
    ofSetVerticalSync(true);
    
    
    //----- Audio Setup -----//
    
    audioInput.setup();
    
    
    //----- Setup Particle Numbers -----//
    
    int num = 100;
    p.assign(num, Particles());
    
    //----- Set Mode -----//
    setMode = MODE_FREE_FLOW;
    modeString = "[   Free Flow Mode  ]";
    
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
        p[i].modeSetting(setMode);
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
        p[i].modeSetting(setMode);
        p[i].update(vol, ctrPoint);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //----- Draw Gradient Background -----//
    ofBackgroundGradient(ofColor(0), ofColor(80));
    
    //----- Draw Particles and Draw Lines -----//
    ofSetColor(colorR, colorG, colorB);
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
            
        if (i+1 < p.size()) {
            ofLine(p[i].pos.x, p[i].pos.y, p[i+1].pos.x, p[i+1].pos.y);
        }
        
        // Last Point connects to the First Point
        if (i-1 == p.size()) {
            ofLine(p[i-1].pos.x, p[i-1].pos.y, p[0].pos.x, p[0].pos.y);
        }
    }
    
    //----- Display String -----//
    ofSetColor(250);
//    ofDrawBitmapString(modeString + "\n\nz | Free Flow - Move your Mouse. \nx | Drag Around - Drag Particles. \nc | Sound Motion - Particles reponse with Sound. \nr | Reset - Reset Current Mode.", 10, 20);
    
    ofDrawBitmapString(modeString + "\n\nz | Free Flow - Move your Mouse. \nx | Sound Motion - Particles reponse with Sound. \nr | Reset - Reset Current Mode.", 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    if( key == 'z' || key == 'Z'){
        setMode = MODE_FREE_FLOW;
        modeString = "[   Free Flow Mode  ]";
    }
    if( key == 'x' || key == 'X'){
        setMode = MODE_SOUND_MOTION;
        modeString = "[ Sound Motion Mode ]";
        audioInput.soundStream.start();
    }
    if( key == 'r' || key == 'R' ){
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
    
    if (setMode == MODE_SOUND_MOTION) {
        if (!isGrabbed) {
            isGrabbed = true;
        }
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

