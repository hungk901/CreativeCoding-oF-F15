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
        void setup(float _xPos,
                   float _yPos,
                   float _xVel,
                   float _yVel,
                   float _xAcc,
                   float _yAcc,
                   float _diameter,
                   ofColor _ballColor,
                   int _state);
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
    
        int state;
    
    private:
        ofVec2f vel;
        ofVec2f pos;
        ofVec2f acc;
        float diameter;
        ofColor ballColor;
    
};

#endif /* defined(__Fireworks__Ball__) */
