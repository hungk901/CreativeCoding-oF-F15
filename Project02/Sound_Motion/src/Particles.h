//
//  Particles.h
//  ProjectII
//
//  Created by Ray_Hung on 10/29/15.
//
//

#ifndef __ProjectII__Particles__
#define __ProjectII__Particles__

#include "ofMain.h"
#include "AudioIn.h"

class Particles{
    
    public:
        Particles();
    
        void setAttractPoints( vector <ofPoint> * attract );
    
        void reset();
        void update(float _scaledVolume);
        void draw();
    
        ofPoint pos;
        ofPoint vel;
        ofPoint frc;
    
        ofPoint centerPoint;
        ofPoint distance;
        float boundaryRadius;
    
        float drag;
        float scale;
    
        float scaledVolume;
    
        vector <ofPoint> * attractPoints;
    
};

#endif /* defined(__ProjectII__Particles__) */
