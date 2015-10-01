//
//  Leaf.cpp
//  Leaf
//
//  Created by Ray_Hung on 9/10/15.
//
//

#include "Leaf.h"

//--------------------------------------------------------------
void Leaf::setup(){

    xPos = ofGetWidth()/2;
    yPos = 2*ofGetHeight()/3;
    
    leafWidth = ofRandom(40, 80);
    leafHeight = ofRandom(80, 120);
    
    stemWidth = ofRandom(3, 6);
    stemHeight = ofRandom(30, 60);
    
    fruitRadiusOne = ofRandom(10, 15);
    fruitRadiusTwo = ofRandom(10, 15);
    
    fruitXPosOne = ofRandom(0, stemWidth+fruitRadiusOne/2);
    fruitYPosOne = ofRandom((3*stemHeight)/4, stemHeight);
    fruitXPosTwo = ofRandom(0, stemWidth+fruitRadiusTwo/2);
    fruitYPosTwo = ofRandom((3*stemHeight)/4, stemHeight);
    
    rotation = ofRandom(135, 225);
    
    leafColorLeft = ofColor(ofRandom(0, 20), ofRandom(150, 255), ofRandom(0, 20), ofRandom(200, 225));
    leafColorRight = ofColor(ofRandom(0, 20), ofRandom(150, 255), ofRandom(0, 20), ofRandom(200, 225));
    
    stemColor = ofColor(130, 50, 20);
    fruitColorOne = ofColor(ofRandom(225, 250), ofRandom(50, 100), ofRandom(0, 100));
    fruitColorTwo = ofColor(ofRandom(225, 250), ofRandom(50, 100), ofRandom(0, 100));
    
    scaleFactor = ofRandom(0.8, 1.2);
    
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(float _xPos, float _yPos, int _season){
    
    season = _season;
    
    //--------------------------//
    //-DRAW LEAF / STEM / FRUIT-//
    //--------------------------//
    
    ofPushMatrix(); // Keep "Leaf" as a pack and Prevent it from changeing by other factors.
    ofPushStyle();  // Keep "Leaf" style(i.e ofSetLineWidth).
    
    xPos = _xPos;
    yPos = _yPos;
    
    
    // Season Fall, Leaves are Orange and Red.
    if (season == 3) {
        leafColorLeft = ofColor(ofRandom(200, 255), ofRandom(50, 150), ofRandom(0, 20), ofRandom(200, 225));
        leafColorRight = ofColor(ofRandom(200, 255), ofRandom(50, 150), ofRandom(0, 20), ofRandom(200, 225));
    }
    
    if (season == 1) {
        scaleFactor = ofRandom(0.5, 0.7);
    }
    
    ofTranslate(xPos, yPos);    // Set Center Point to xPos and yPos.
    
    
    //----------------------------------------------------//
    //------0. Do Rotation, Scale and Set Line Width------//
    //----------------------------------------------------//
    
    ofRotateZ(rotation);
    ofScale(scaleFactor, scaleFactor);
    ofSetLineWidth(0);  // Line Width could be effected by Branch's Width, set it to 0.
    
    // Season Winter, all Leaves die.
    if (season != 4) {
    
    //-----------------------------//
    //------1. Draw Left Leaf------//
    //-----------------------------//
    
    ofBeginShape();
    ofSetColor(leafColorLeft);  // Set Color Green to Leaf.

    
    // Set x Values of Bezier
    float x0 = 0;
    float x1 = x0-leafWidth/2;
    float x2 = x0-leafWidth/4;
    float x3 = x0;

    // Set y Values of Bezier
    float y0 = (2*stemHeight)/3;
    float y1 = y0+leafHeight/3;
    float y2 = y0+(2*leafHeight)/3;
    float y3 = y0+leafHeight;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //----------------------------//
    //-----2. Draw Right Leaf-----//
    //----------------------------//
    
    ofBeginShape();
    ofSetColor(leafColorRight);
    
    // Set x Values of Bezier
    x0 = 0;
    x1 = x0+leafWidth/2;
    x2 = x0+leafWidth/4;
    x3 = x0;
    
    // Set y Values of Bezier
    y0 = (2*stemHeight)/3;
    y1 = y0+leafHeight/3;
    y2 = y0+(2*leafHeight)/3;
    y3 = y0+leafHeight;
    
    ofVertex(x0, y0);
    ofBezierVertex(x1, y1, x2, y2, x3, y3);
    
    ofEndShape();
    
    
    //---------------------------//
    //-----3. Draw Stem Body-----//
    //---------------------------//
    
    ofSetColor(stemColor);  //Set Color Brown to Stem.
    ofRect(0, 0+stemHeight/2, stemWidth, stemHeight);
    
    
    //---------------------------//
    //-----4. Draw Stem Head-----//
    //---------------------------//
    
    ofTriangle(0-stemWidth/2, 0+stemHeight, 0+stemWidth/2, 0+stemHeight, 0, 0+stemHeight+leafHeight/3);
    
    }


    // Season Summer, Fruits grow up.
    if (season == 2) {
    
    //------------------------------//
    //-----5. Draw Fruits No.01-----//
    //------------------------------//
    
    ofSetColor(fruitColorOne);
    ofCircle(fruitXPosOne, fruitYPosOne, fruitRadiusOne);
    
    
    //------------------------------//
    //-----6. Draw Fruits No.02-----//
    //------------------------------//
    
    ofSetColor(fruitColorTwo);
    ofCircle(fruitXPosTwo, fruitYPosTwo, fruitRadiusTwo);
        
    }
    
    
    // Season Winter, all Leaves die.
    if (season != 4) {
    
    //----------------------//
    //-----7. Draw Root-----//
    //----------------------//
    
    ofSetColor(stemColor);
    ofCircle(0, 0, stemWidth/2);
        
    }
    
    
    ofPopStyle();
    ofPopMatrix();
    
}
