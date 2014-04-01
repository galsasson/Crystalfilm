//
//  Canvas.h
//  Crystalfilm
//
//  Created by Gal Sasson on 3/29/14.
//
//

#ifndef __Crystalfilm__Canvas__
#define __Crystalfilm__Canvas__

#include <iostream>
#include "Stroke.h"
#include "ShapeStroke.h"
#include "FlyingStroke.h"
#include "ofMain.h"
#include "Brush.h"

class Canvas
{
public:
    Canvas();
    ~Canvas();
    void setup(int w, int h, Brush* brush);
    void update();
    void draw();
    ofTexture& getTextureRef();
    
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);

    float blurResolution;
    float blurRadius;

private:
    void applyBlur(ofFbo &fbo);
    void clearCanvas();
    
    Brush* brush;
    
    ofVec2f toCanvas(ofVec2f p);
    
    ofVec2f size;
    
    ofFbo canvasFbo;
    
    ofFbo blurFbo;
    ofShader blurShader;
    ofVec2f blurDirection;
    
    ofShader burnShader;
    
    
    ofVec2f screenToCanvasScale;
    
    vector<Stroke*> strokes;
    Stroke *currentStroke;
    
    ofImage fabricImg;
};
#endif /* defined(__Crystalfilm__Canvas__) */
