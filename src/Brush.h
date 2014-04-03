//
//  Brush.h
//  Crystalfilm
//
//  Created by Gal Sasson on 3/30/14.
//
//

#ifndef __Crystalfilm__Brush__
#define __Crystalfilm__Brush__

#include <iostream>
#include "ofMain.h"

enum class BrushType
{
    Points,
    Shape
};

class Brush
{
public:
    int type;
    float red, green, blue, alpha;
    
    ofFloatColor getFloatColor();
    void setColor(int index);
    
};

#endif /* defined(__Crystalfilm__Brush__) */
