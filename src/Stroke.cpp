//
//  Stroke.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/29/14.
//
//

#include "Stroke.h"

Stroke::Stroke(ofFloatColor c)
{
    color = c;
}

void Stroke::addPoint(ofVec3f p)
{
    vertices.push_back(p);
    
    // build new vbo
    rebuildVbo();
}

void Stroke::draw()
{
    ofSetColor(color);
    for (int i=0; i<vertices.size(); i++)
    {
        ofEllipse(vertices[i].x, vertices[i].y, 10, 10);
    }
}

void Stroke::rebuildVbo()
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
}