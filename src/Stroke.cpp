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
    center = ofVec3f(0, 0, 0);
}

void Stroke::addPoint(ofVec3f p)
{
    vertices.push_back(p);
    
    // adjust center of shape
    center += (p-center)/vertices.size();
    
    // build new vbo
    rebuildVbo();
}

void Stroke::update()
{
    // update only vertex positions for now
    vbo.setVertexData(&vertices[0], vertices.size(), GL_DYNAMIC_DRAW);
}


void Stroke::draw()
{
    ofSetColor(color);
    for (int i=0; i<vertices.size(); i++)
    {
        ofEllipse(vertices[i].x, vertices[i].y, 10, 10);
    }
}

void Stroke::translate(ofVec3f amount)
{
    center += amount;
    
    for (int i=0; i<vertices.size(); i++)
    {
        vertices[i] += amount;
    }
}

void Stroke::scale(ofVec3f amount)
{
    for (int i=0; i<vertices.size(); i++)
    {
        ofVec3f local = toLocal(vertices[i]);
        local *= amount;
        vertices[i].set(toGlobal(local));
    }
}

void Stroke::applyDistorion(float max)
{
    for (int i=0; i<vertices.size(); i++)
    {
        vertices[i].x += ofRandom(-max, max);
        vertices[i].y += ofRandom(-max, max);
//        vertices[i].z += ofRandom(-max, max);
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

ofVec3f Stroke::toLocal(ofVec3f p)
{
    return p-center;
}

ofVec3f Stroke::toGlobal(ofVec3f p)
{
    return center+p;
}