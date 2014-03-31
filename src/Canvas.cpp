//
//  Canvas.cpp
//  Crystalfilm
//
//  Created by Gal Sasson on 3/29/14.
//
//

#include "Canvas.h"

Canvas::Canvas()
{
    
}

Canvas::~Canvas()
{
    for (int i=0; i<strokes.size(); i++)
    {
        delete strokes[i];
        strokes[i] = NULL;
    }
    
    strokes.clear();
    
    if (currentStroke) {
        delete currentStroke;
    }
}

void Canvas::setup(int w, int h, Brush* b)
{
    size = ofVec2f(w, h);
    brush = b;

    blurShader.load("shaders/blur");
    canvasFbo.allocate(w, h, GL_RGBA);
    blurFbo.allocate(w, h, GL_RGBA);
    
    currentStroke = NULL;
    
    // call this to set up screenToCanvasScale
    windowResized(w, h);
}

void Canvas::update()
{
    // draw on canvas
    canvasFbo.begin();
    ofClear(255, 255, 255, 255);
    for (int i=0; i<strokes.size(); i++)
    {
        strokes[i]->update();
        strokes[i]->draw();
    }
    if (currentStroke) {
//        currentStroke->update();
        currentStroke->draw();
    }
    canvasFbo.end();
    
    applyBlur(canvasFbo);
}

void Canvas::draw()
{
    ofSetColor(255);
    canvasFbo.draw(0, 0);
}

ofTexture& Canvas::getTextureRef()
{
    return canvasFbo.getTextureReference();
}

//--------------------------------------------------------------
void Canvas::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Canvas::mouseDragged(int x, int y, int button){
    if (!currentStroke) {
        return;
    }
    
    currentStroke->addPoint(toCanvas(ofVec2f(x, y)));
}

//--------------------------------------------------------------
void Canvas::mousePressed(int x, int y, int button)
{
    if (brush->type == 0)
    {
        currentStroke = new ShapeStroke(ofColor(brush->red, brush->green, brush->blue, brush->alpha));
    }
    else
    {
        currentStroke = new FlyingStroke(ofColor(brush->red, brush->green, brush->blue, brush->alpha));
    }
    currentStroke->addPoint(toCanvas(ofVec2f(x, y)));
}

//--------------------------------------------------------------
void Canvas::mouseReleased(int x, int y, int button){
    if (!currentStroke) {
        return;
    }
    
    strokes.push_back(currentStroke);
    currentStroke = NULL;
}

//--------------------------------------------------------------
void Canvas::windowResized(int w, int h){
    size.set(w, h);
    screenToCanvasScale = ofVec2f(size.x / ofGetWidth(), size.y / ofGetHeight());
}

void Canvas::applyBlur(ofFbo &fbo)
{
    blurShader.begin();
    blurShader.setUniform1f("resolution", blurResolution);
    blurShader.setUniform1f("radius", blurRadius);
    
    blurFbo.begin();
    blurShader.setUniform2f("dir", 1, 0);
    ofSetColor(255, 255, 255, 255);
    fbo.draw(0, 0);
    blurFbo.end();
    
    fbo.begin();
    ofClear(0);
    blurShader.setUniform2f("dir", 0, 1);
    ofSetColor(255, 255, 255, 255);
    blurFbo.draw(0, 0);
    fbo.end();
    
    blurShader.end();
}

void Canvas::clearCanvas()
{
    canvasFbo.begin();
    ofClear(255, 255, 255, 255);
    canvasFbo.end();
}

ofVec2f Canvas::toCanvas(ofVec2f p)
{
    return ofVec2f(p.x, ofGetHeight()-p.y-1) * screenToCanvasScale;
}

