//
//  Brush.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/30/14.
//
//

#include "Brush.h"

ofFloatColor Brush::getFloatColor()
{
    return ofFloatColor(red/255, green/255, blue/255, alpha/255);
}

void Brush::setColor(int index)
{
    int low = 50;
    int high = 180;
    if (index == 0) {
        red = low;
        green = low;
        blue = low;
    }
    else if (index == 1) {
        red = high;
        green = low;
        blue = low;
    }
    else if (index == 2) {
        red = high;
        green = high;
        blue = low;
    }
    else if (index == 3) {
        red = low;
        green = high;
        blue = low;
    }
    else if (index == 4) {
        red = low;
        green = high;
        blue = high;
    }
    else if (index == 5) {
        red = 50;
        green = 50;
        blue = 255;
    }
    else if (index == 6) {
        red = high;
        green = low;
        blue = high;
    }
    else {
        red = high;
        green = high;
        blue = high;
    }
    
    alpha = 251;
}