//
//  ShapeStroke.h
//  Crystalfilm
//
//  Created by Gal Sasson on 3/30/14.
//
//

#ifndef __Crystalfilm__ShapeStroke__
#define __Crystalfilm__ShapeStroke__

#include <iostream>
#include "Stroke.h"
#include "ofxControlease.h"

class ShapeStroke : public Stroke
{
public:
    
    ShapeStroke(ofColor c);
    void endStroke();
    virtual void draw();
    
    bool bSolid;
};
#endif /* defined(__Crystalfilm__ShapeStroke__) */
