//
//  Stroke.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/29/14.
//
//

#include "Stroke.h"

Stroke::Stroke(ofVec2f start)
{
    path.setFilled(false);
    path.moveTo(start);
}

void Stroke::addPoint(ofVec2f p)
{
    
    path.lineTo(p);
    vector<ofPolyline> outline = path.getOutline();
    vertices = outline[0].getVertices();
}

void Stroke::draw()
{
    ofBeginShape();
    ofVertices(vertices);
    ofEndShape();
}