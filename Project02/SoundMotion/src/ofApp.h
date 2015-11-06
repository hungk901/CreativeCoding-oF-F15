#pragma once

#include "ofMain.h"
#include "AudioIn.h"
#include "Particles.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void resetParticles();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    AudioIn audioInput;
    
    vector <Particles> p;
    vector <ofPoint> attractPoints;
    vector <ofPoint> attractPointsWithMovement;
    ofPoint ctrPoint;
    
    int colorR, colorG,colorB;
    int addColorR, addColorG, addColorB;
    
    bool isGrabbed;

};
