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
    
    fruitRadiusOne = ofRandom(8, 12);
    fruitRadiusTwo = ofRandom(8, 12);
    
    fruitXPosOne = ofRandom(0, stemWidth+fruitRadiusOne/2);
    fruitYPosOne = ofRandom((3*stemHeight)/4, stemHeight);
    fruitXPosTwo = ofRandom(0, stemWidth+fruitRadiusTwo/2);
    fruitYPosTwo = ofRandom((3*stemHeight)/4, stemHeight);
    
    rotation = ofRandom(120, 250);
    
    leafColorLeft = ofColor(ofRandom(0, 20), ofRandom(150, 255), ofRandom(0, 20), ofRandom(225, 255));
    leafColorRight = ofColor(ofRandom(0, 20), ofRandom(150, 255), ofRandom(0, 20), ofRandom(225, 255));
    stemColor = ofColor(130, 50, 20);
    fruitColorOne = ofColor(ofRandom(225, 250), ofRandom(50, 100), ofRandom(0, 100));
    fruitColorTwo = ofColor(ofRandom(225, 250), ofRandom(50, 100), ofRandom(0, 100));
    
    scaleFactor = ofRandom(2, 3);
    
}

//--------------------------------------------------------------
void Leaf::update(){
    
}

//--------------------------------------------------------------
void Leaf::draw(){
    
    // DRAW LEAF / STEM / FRUIT
    
    ofPushMatrix();
    
    ofTranslate(xPos, yPos);    // Set Center Point to xPos and yPos.
    //------0. Do Rotation and Scale------//
    ofRotateZ(rotation);
    ofScale(scaleFactor, scaleFactor);
    
    
    //------1. Draw Left Leaf------//
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
    
    
    //-----2. Draw Right Leaf-----//
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
    
    
    //-----3. Draw Stem Body-----//
    ofSetColor(stemColor);  //Set Color Brown to Stem.
    ofRect(0, 0+stemHeight/2, stemWidth, stemHeight);
    
    
    //-----4. Draw Stem Head-----//
    ofTriangle(0-stemWidth/2, 0+stemHeight, 0+stemWidth/2, 0+stemHeight, 0, 0+stemHeight+leafHeight/3);
    
    
    //-----5. Draw Fruits No.01-----//
    ofSetColor(fruitColorOne);
    ofCircle(fruitXPosOne, fruitYPosOne, fruitRadiusOne);
    
    
    //-----6. Draw Fruits No.02-----//
    ofSetColor(fruitColorTwo);
    ofCircle(fruitXPosTwo, fruitYPosTwo, fruitRadiusTwo);
    
    //-----7. Draw Root
    ofSetColor(stemColor);
    ofCircle(0, 0, stemWidth/2);
    
    ofPopMatrix();
    
}
