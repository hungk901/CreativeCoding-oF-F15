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
        void setup();
        void update(float _scaledVolume);
        void draw();
    
        ofPoint pos;
        ofPoint vel;
        ofPoint frc;
        float particleScale;
        float drag;
    
        ofPoint centerPoint;
        ofPoint distance;
        float boundaryRadius;

        float scaledVolume;    
    
        vector <ofPoint> * attractPoints;
    
};

#endif /* defined(__ProjectII__Particles__) */
