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
    virtual void update();
    virtual void draw();
    
    virtual void translate(ofVec3f amount);
    virtual void scale(ofVec3f amount);
    virtual void applyDistorion(float max);
    
    ofFloatColor color;
    vector<ofPoint> vertices;
    ofVbo vbo;
    ofPath path;
    ofVec3f center;
    
private:
    void rebuildVbo();
    ofVec3f toLocal(ofVec3f p);
    ofVec3f toGlobal(ofVec3f p);
};

#endif /* defined(__Crystalfilm__Stroke__) */
