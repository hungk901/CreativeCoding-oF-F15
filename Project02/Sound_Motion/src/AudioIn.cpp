//
//  AudioIn.cpp
//  ProjectII
//
//  Created by Ray_Hung on 10/28/15.
//
//

#include "AudioIn.h"

//--------------------------------------------------------------
void AudioIn::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    ofBackground(54, 54, 54);
    
    // 0 output channels,
    // 2 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    
    soundStream.listDevices();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    soundStream.setup(0, 0, 2, 44100, bufferSize, 4);
    soundStream.setInput(this);
    
    soundStream.stop();
}

//--------------------------------------------------------------
void AudioIn::update(){
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 2.30, 0.0, 1.0, true);
    return scaledVol;
}

//--------------------------------------------------------------
void AudioIn::draw(){

}

//--------------------------------------------------------------
void AudioIn::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    for (int i = 0; i < bufferSize; i++){
        left[i]	= input[i*2]*0.5;
        right[i] = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted += 2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
}