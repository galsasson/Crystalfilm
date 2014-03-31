//
//  Stroke.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/29/14.
//
//

#include "Stroke.h"

Stroke::Stroke(ofColor c)
{
    color = c;
}

void Stroke::addPoint(ofVec3f p)
{
    vertices.push_back(p);//ofVec3f(p.x, p.y, 0));
}

void Stroke::draw()
{
    ofSetColor(color);
    for (int i=0; i<vertices.size(); i++)
    {
        ofEllipse(vertices[i].x, vertices[i].y, 10, 10);
    }
}