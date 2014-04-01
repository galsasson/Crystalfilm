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
    Stroke(ofFloatColor c);
    void addPoint(ofVec3f p);
    virtual void endStroke() {}
    virtual void update() {}
    virtual void draw();
    
    ofFloatColor color;
    vector<ofPoint> vertices;
    ofVbo vbo;
    ofPath path;
    
private:
    void rebuildVbo();
};

#endif /* defined(__Crystalfilm__Stroke__) */
