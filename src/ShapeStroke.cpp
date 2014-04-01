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
    bSolid = false;
}

void ShapeStroke::endStroke()
{
    // here we need to set the vbo
    vector<ofVec2f> uvs;
    vector<ofFloatColor> colors;
    vector<ofIndexType> indices;
    for (int i=0; i<vertices.size(); i++)
    {
        uvs.push_back(ofVec2f(vertices[i].x, vertices[i].y));
        colors.push_back(color);
        indices.push_back(i);
    }
    
    vbo.setVertexData(&vertices[0], vertices.size(), GL_DYNAMIC_DRAW);
    vbo.setIndexData(&indices[0], indices.size(), GL_STATIC_DRAW);
    vbo.setTexCoordData(&uvs[0], uvs.size(), GL_STATIC_DRAW);
    vbo.setColorData(&colors[0], colors.size(), GL_STATIC_DRAW);
    bSolid = true;
}

void ShapeStroke::draw()
{
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    
    if (bSolid) {
        vbo.drawElements(GL_TRIANGLE_FAN, vertices.size());
    }
    else {
        ofBeginShape();
        ofVertices(vertices);
        ofEndShape();
    }
    
    ofPopStyle();
}