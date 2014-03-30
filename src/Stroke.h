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
    Stroke(ofVec2f start);
    void addPoint(ofVec2f p);
    virtual void update() {}
    void draw();
    
    ofPath path;
    vector<ofPoint> vertices;
};

#endif /* defined(__Crystalfilm__Stroke__) */
