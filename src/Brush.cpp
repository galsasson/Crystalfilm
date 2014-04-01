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