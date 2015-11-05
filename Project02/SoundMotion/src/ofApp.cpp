#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    audioInput.setup();
    audioInput.soundStream.start();
    
    int num = 100;
    p.assign(num, Particles());
    
    colorR = ofRandom(100, 255);
    colorG = ofRandom(100, 255);
    colorB = ofRandom(100, 255);
    addColorR = addColorG = addColorB = 2;
    
    setParticles();
}

//--------------------------------------------------------------
void ofApp::setParticles(){
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setup();
    }	
}

//--------------------------------------------------------------
void ofApp::update(){
    
    audioInput.update();
    float vol = audioInput.scaledVol;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].update(vol);
    }
    
    // Update Color.
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
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor(0), ofColor(80));
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
    
        if(i+1 < p.size()){
            ofSetLineWidth(1);
            ofLine(p[i].pos.x, p[i].pos.y, p[i+1].pos.x, p[i+1].pos.y);
        }
    }
    ofSetColor(colorR, colorG, colorB);
    // cout << colorR << " / " << colorG << " / " << colorB << endl;
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

