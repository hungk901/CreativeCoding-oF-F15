//
//  AudioIn.h
//  ProjectII
//
//  Created by Ray_Hung on 10/28/15.
//
//

#ifndef __ProjectII__AudioIn__
#define __ProjectII__AudioIn__

#include "ofMain.h"
#include "Particles.h"

class AudioIn : public ofBaseSoundInput{
    
    public:
        void setup();
        void update();
        void draw();
				
        void audioIn(float * input, int bufferSize, int nChannels);
    
        vector <float> left;
        vector <float> right;
    
        float smoothedVol;
        float scaledVol;
    
        ofSoundStream soundStream;
};

#endif /* defined(__ProjectII__AudioIn__) */
