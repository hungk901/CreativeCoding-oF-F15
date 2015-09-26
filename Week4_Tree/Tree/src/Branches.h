//
//  Branches.h
//  Branches
//
//  Created by Ray_Hung on 9/22/15.
//
//

#ifndef __Branches__Branches__
#define __Branches__Branches__

#include "ofMain.h"
#include "Leaf.h"

class Branches : public ofBaseApp{

    public:
        void setup(
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
                   ofColor _color
        );
        void update();
        void draw();
    
    
    private:
        float xPos, yPos;
        float width;    // Line Width.
        float length;   // Line Length.
        float splitPercentage;  // Branch Splits or not.
        float maxSplitAngle;
        float maxSubdivisions;
        float maxSegments;
        float segmentsSinceStart;   // Segments Counter.
        float angle;    // It is Radians(using PI) in Code but not Degrees.
        float curvature;    // To Bend Branches.
        ofColor color;
    
        int numLeaves;
        vector<Leaf> myLeaves;
    
};

#endif /* defined(__Branches__Branches__) */
