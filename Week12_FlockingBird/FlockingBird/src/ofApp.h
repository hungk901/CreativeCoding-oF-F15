#pragma once

#include "ofMain.h"
#include "Bird.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void updateBirdsPosition();
        ofPoint accTowardsCenterOfMass(int birdIndex);
        ofPoint accAwayFromNearbys(int birdIndex);
        ofPoint accSameWithNearbyMovement(int birdIndex);
    
        void screenBoundaries();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector <Bird> myBirds;
        int numBirds;
};
