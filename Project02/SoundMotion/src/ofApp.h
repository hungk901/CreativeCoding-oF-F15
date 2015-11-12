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
    
    AudioIn audioInput; // Audio Input
    
    vector <Particles> p;           // Particles Array
    vector <ofPoint> attractPoints; // Attract Point: Center / Mouse
    ofPoint ctrPoint;               // Center Point
    bool isGrabbed;                 // Check if particle is Grabbed
    
    int colorR, colorG,colorB;              // R, G, B Color
    int addColorR, addColorG, addColorB;    // R, G, B add Value
    
    modeSelection setMode;  // Mode Set
    string modeString;      // Mode String
    

};
