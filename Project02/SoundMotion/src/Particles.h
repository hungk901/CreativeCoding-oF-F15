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

enum modeSelection{
    MODE_FREE_FLOW,
    MODE_DRAG_AROUND,
    MODE_SOUND_MOTION
};

class Particles{
    
    public:
        void setup();
        void update(float _scaledVolume, ofPoint _centerPoint, bool _grabbed);
        void draw();
    
        void modeSetting(modeSelection newMode);
        void setAttractPoints( vector <ofPoint> * attract );
    
        ofPoint pos;            // Position X, Y
        ofPoint vel;            // Velocity X, Y
        ofPoint frc;            // Force X, Y
        float particleScale;    // Particle Scale
        float drag;             // Drag
        float randomValue;      // Apply to Noise
    
        vector <ofPoint> * attractPoints;   // Attract Point
        ofPoint centerPoint;                // Center of Window
        ofPoint distance;                   // Distance from Center to Particle
        float boundaryRadius;               // Radius of Boundary

        float scaledVolume;                 // Volume after Scaled
        bool grabbed;
    
        modeSelection mode;                 // Mode Set
};

#endif /* defined(__ProjectII__Particles__) */
