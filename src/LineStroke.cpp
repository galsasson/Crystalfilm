//
//  LineStroke.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 4/3/14.
//
//

#include "LineStroke.h"

LineStroke::LineStroke(ofColor c) : Stroke(c)
{
}

void LineStroke::draw()
{
    ofPushStyle();
    ofSetColor(color);
    ofSetLineWidth(5);
    ofNoFill();

    ofBeginShape();
    for (int i=0; i<vertices.size(); i++)
    {
        ofVertex(vertices[i]);
    }
    ofEndShape();
    
//    ofSetLineWidth(10);
//    glBegin(GL_LINE_STRIP);
//    for (int i=0; i<vertices.size(); i++)
//    {
//        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//    }
//    glEnd();
    
    ofPopStyle();
}