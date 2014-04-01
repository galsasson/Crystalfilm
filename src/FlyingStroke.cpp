//
//  FlyingStroke.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/31/14.
//
//

#include "FlyingStroke.h"

FlyingStroke::FlyingStroke(ofColor c) : ShapeStroke(c)
{
    
}

void FlyingStroke::update()
{
    for (int i=0; i<vertices.size(); i++)
    {
        vertices[i].x -= 0.2;
    }
    
    vbo.setVertexData(&vertices[0], vertices.size(), GL_DYNAMIC_DRAW);
}