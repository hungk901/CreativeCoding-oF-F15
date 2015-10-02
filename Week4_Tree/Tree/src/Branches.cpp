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
                  float _maxSplitAngle,
                  float _maxSubdivisions,
                  float _maxSegments,
                  float _segmentsSinceStart,
                  float _angle,
                  float _curvature,
                  ofColor _color,
                  int _season)
{
    
    ofPushMatrix();
    
    
    //-----------------------------------------------//
    //-------1-1. Set Up Variables of Branches-------//
    //-----------------------------------------------//
    
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    length = _length;
    splitPercentage = _splitPercentage;
    maxSplitAngle = _maxSplitAngle;
    maxSubdivisions = _maxSubdivisions;
    maxSegments = _maxSegments;
    segmentsSinceStart = _segmentsSinceStart;
    angle = _angle;
    curvature = _curvature;
    color = _color;
    season = _season;
    
    
    //---------------------------------------------//
    //-------1-2. Set Up Variables of Leaves-------//
    //---------------------------------------------//
    
    //  Different Season, Different number of leaves.
    if (season == 1) {
        numLeaves = (int)ofRandom(1, 2);
    }
    else {
        numLeaves = (int)ofRandom(2, 4);
    }
    
    //  No Leaves for first Branch; Last Branch has more Leaves.
    if (segmentsSinceStart == maxSegments) {
        numLeaves = (int)ofRandom(5, 8);
    }
    if (segmentsSinceStart == 0) {
        numLeaves = 0;
    }
    
    for (int i = 0; i < numLeaves; i++) {
        Leaf tempLeaf;
        tempLeaf.setup();
        myLeaves.push_back(tempLeaf);
    }
    
    
    //-----------------------------//
    //-------2-1. Draw Lines-------//
    //-----------------------------//
    
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(xPos, yPos, xPos+length*cos(angle), yPos+length*sin(angle));
    
    /*
    cout << "width=" << width << ", length=" << length<< endl;
    cout <<  "xPos=" << xPos << ",yPos=" << yPos << endl;
    cout <<  "xPos2=" << xPos+length*cos(angle) <<  ",yPos2=" << yPos+length*sin(angle) << endl<<endl;
    */
    
    //------------------------------//
    //-------2-2. Draw Leaves-------//
    //-----------------------------//
    
    for (int i = 0; i < numLeaves; i++) {
        myLeaves[i].draw(xPos+length*cos(angle), yPos+length*sin(angle), season, segmentsSinceStart);
    }
    
    
    //-------3. Update Variables before Pass them to Sub-Branches-------//
    xPos += length*cos(angle);
    yPos += length*sin(angle);
    width = width*ofRandom(0.7, 0.9);
    length = length*ofRandom(0.7, 0.9);
    segmentsSinceStart += 1;
    angle += curvature;
    curvature += ofRandom(0, (float)(2*PI)/360.0);
    
    
    //-------4. Recursion of Building Branches-------//
    
    // If Segments don't exceed the Maximum,
    if (segmentsSinceStart <= maxSegments){
        
        Branches subBranch;
        subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color, season);
        
        // Roll the Dice to determind if Branch Splits into 2 Branches.
        
        // Don't Split and Create 1 Branch.
        if (ofRandom(0, 1) > splitPercentage){
            
            subBranch.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle, curvature, color, season);
        }
        
        // Do Split and Create 2 Branches.
        else{
            // Left subBranch
            Branches subBranch_1;
            float angle_1 = angle-ofRandom(0, maxSplitAngle);
            
            // Right subBranch
            Branches subBranch_2;
            float angle_2 = angle+ofRandom(0, maxSplitAngle);
            
            subBranch_1.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle_1, curvature, color, season);
            subBranch_2.setup(xPos, yPos, width, length, splitPercentage, maxSplitAngle, maxSubdivisions, maxSegments, segmentsSinceStart, angle_2, curvature, color, season);
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