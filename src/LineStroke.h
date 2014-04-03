//
//  LineStroke.h
//  Crystalfilm
//
//  Created by Gal Sasson on 4/3/14.
//
//

#ifndef __Crystalfilm__LineStroke__
#define __Crystalfilm__LineStroke__

#include <iostream>
#include "Stroke.h"
#include "ofxControlease.h"

class LineStroke : public Stroke
{
public:
    
    LineStroke(ofColor c);
    virtual void draw();
};

#endif /* defined(__Crystalfilm__LineStroke__) */
