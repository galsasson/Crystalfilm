//
//  ShapeStroke.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/30/14.
//
//

#include "ShapeStroke.h"

ShapeStroke::ShapeStroke(ofColor c) : Stroke(c)
{
}

void ShapeStroke::draw()
{
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    
    vbo.drawElements(GL_TRIANGLE_FAN, vertices.size());
    
    ofPopStyle();
}