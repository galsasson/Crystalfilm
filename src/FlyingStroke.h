//
//  FlyingStroke.h
//  Crystalfilm
//
//  Created by Gal Sasson on 3/31/14.
//
//

#ifndef __Crystalfilm__FlyingStroke__
#define __Crystalfilm__FlyingStroke__

#include <iostream>
#include "ShapeStroke.h"

class FlyingStroke : public ShapeStroke
{
public:
    FlyingStroke(ofColor c);
    void update();
    
};
#endif /* defined(__Crystalfilm__FlyingStroke__) */
