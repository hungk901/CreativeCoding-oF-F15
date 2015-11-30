#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Number of Birds
    numBirds = 100;
    
    // Create all Birds.
    for (int i = 0; i < numBirds; i++) {
        Bird tempBird;                  // Create a Bird,
        tempBird.setup();               // Give this Bird all initial content,
        myBirds.push_back(tempBird);    // Put this Bird into myBirds Array.
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    updateBirdsPosition();
    
    // Loop through every Bird.
    for (int i = 0; i < myBirds.size(); i++) {
        
        ofPoint tempAcc;    // Create temp Acc, the 3 sub Acc will be calculated to a Master Acc.
        ofPoint acc1 = accTowardsCenterOfMass(i);    // = Moving towards the middle of the Mass.
        ofPoint acc2 = accAwayFromNearbys(i);        // = Moving away from others that are too close.
        ofPoint acc3 = accSameWithNearbyMovement(i); // = Moving the same speed as nearbys.
        
        tempAcc = acc1 + acc2 +acc3;    // Acc = Acc1 + Acc2 + Acc3...
        myBirds[i].acc = tempAcc;
    }
    
    
    
    
    // Apply Acc to the current Bird: myBirds[i].vel += Acc;
    
    
    for (int i = 0; i < myBirds.size(); i++) {
        myBirds[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < myBirds.size(); i++) {
        myBirds[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::updateBirdsPosition(){
    
//    accTowardsCenterOfMass();
//    accAwayFromNearbys();
//    accSameWithNearbyMovement();
}

//--------------------------------------------------------------
ofPoint ofApp::accTowardsCenterOfMass(int birdIndex){
    
    ofPoint myBirdAcc1;
    ofPoint megaPos = ofPoint(0,0,0);
    // Find Center Point of the Mass without Current Bird.
    
    // Create a Normalize Vector
    for (int i = 0; i < myBirds.size() - 1; i++) {
        
        if (i != birdIndex) {
            megaPos += myBirds[i].pos;  // Add all pos of other Birds to megaPos
        }
    }
    myBirdAcc1 = megaPos / (myBirds.size()-1);  // Devide megaPos by numBird except Current Bird
    myBirdAcc1 = myBirdAcc1.normalize();
    
    return myBirdAcc1;
}

//--------------------------------------------------------------
ofPoint ofApp::accAwayFromNearbys(int birdIndex){
    
    ofPoint myValue;
    return myValue;
}

//--------------------------------------------------------------
ofPoint ofApp::accSameWithNearbyMovement(int birdIndex){
    
    ofPoint myValue;
    return myValue;
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
