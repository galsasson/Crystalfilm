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

    ofBeginShape();
    
    for (int i=0; i<vertices.size(); i++)
    {
        ofVertex(vertices[i].x, vertices[i].y, vertices[i].z);
    }
    ofEndShape();
    
    ofPopStyle();
}