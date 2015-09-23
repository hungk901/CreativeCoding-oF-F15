//
//  Branches.cpp
//  Branches
//
//  Created by Ray_Hung on 9/22/15.
//
//


#include "Branches.h"

//--------------------------------------------------------------
void Branches::setup(
                  float _xPos,
                  float _yPos,
                  float _width,
                  float _length,
                  float _splitPercentage,
                  float _maxSubdivisions,
                  float _maxSegments,
                  float _segmentsSinceStart,
                  float _angle,
                  float _curvature,
                  ofColor _color)
{
    
    ofPushMatrix();
    
    
    //-------1. Set Up Variables-------//
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSubdivisions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    
    myLeaf.setup();
    

    //-------2. Draw Lines-------//
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(xPos, yPos, xPos+length*cos(angle), yPos+length*sin(angle));
    
    /*
    cout << "width=" << width << ", length=" << length<< endl;
    cout <<  "xPos=" << xPos << ",yPos=" << yPos << endl;
    cout <<  "xPos2=" << xPos+length*cos(angle) <<  ",yPos2=" << yPos+length*sin(angle) << endl<<endl;
    */
    
 
    //-------3. Update Variables before Pass them to Sub-Branches-------//
    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*ofRandom(0.7, 0.9);
    length = length*ofRandom(1.1, 1.3);
    segmentsSinceStart += 1;
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    myLeaf.draw(xPos, yPos);
    
    
    //-------4. Recursion of Building Branches-------//
    
    // If Segments don't exceed the Maximum,
    if (segmentsSinceStart <= maxSegments){
        
        // Roll the Dice to determind if Branch Splits into 2 Branches.
        
        // Don't Split and Create 1 Branch.
        if (ofRandom(0, 1) > splitPercentage){
            
            Branches subBranch;
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color);
        }
        
        // Do Split and Create 2 Branches.
        else{
            // Left subBranch
            Branches subBranch_1;
            float angle_1 = angle-ofRandom(0, PI/3);
            
            // Right subBranch
            Branches subBranch_2;
            float angle_2 = angle+ofRandom(0, PI/3);
            
            subBranch_1.setup(xPos, yPos, width, length, splitPercentage, maxSubdivisions, maxSegments, segmentsSinceStart, angle_1, curvature, color);
            subBranch_2.setup(xPos, yPos, width, length, splitPercentage, maxSubdivisions, maxSegments, segmentsSinceStart, angle_2, curvature, color);
        }
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void Branches::update(){

}

//--------------------------------------------------------------
void Branches::draw(){
    
}