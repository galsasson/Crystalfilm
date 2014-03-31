//
//  Stroke.h
//  Crystalfilm
//
//  Created by Gal Sasson on 3/29/14.
//
//

#ifndef __Crystalfilm__Stroke__
#define __Crystalfilm__Stroke__

#include <iostream>
#include "ofMain.h"

class Stroke
{
public:
    Stroke(ofColor c);
    void addPoint(ofVec3f p);
    virtual void update() {}
    virtual void draw();
    
    ofColor color;
    vector<ofPoint> vertices;
    ofPath path;
};

#endif /* defined(__Crystalfilm__Stroke__) */
