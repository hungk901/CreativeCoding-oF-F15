//
//  Ball.h
//  Fireworks
//
//  Created by Ray_Hung on 10/8/15.
//
//

#ifndef __Fireworks__Ball__
#define __Fireworks__Ball__

#include "ofMain.h"

class Ball : public ofBaseApp{
    
    public:
        void setup();
        void setup(float _xPos,
                   float _yPos,
                   float _xVel,
                   float _yVel,
                   float _xAcc,
                   float _yAcc);
        void update();
        void draw();
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    private:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f acc;
        float diameter;
        float bounciness;
        float ballColor;
    
};

#endif /* defined(__Fireworks__Ball__) */
