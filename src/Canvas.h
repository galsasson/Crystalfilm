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
#include "LineStroke.h"
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

    ofVec3f pos;
    ofVec3f vel;
    ofVec3f acc;
    float distortion;
    float temporalDistortion;
    
private:
    void applyBlur(ofFbo &fbo);
    void clearCanvas();
    ofVec2f toCanvas(ofVec2f p);

    Brush* brush;
    vector<Stroke*> strokes;
    Stroke *currentStroke;
    
    ofImage fabricImg;
    ofFbo canvasFbo;
    ofFbo blurFbo;
    ofShader blurShader;
    ofShader burnShader;
    
    ofShader testShader;
    

    
    ofVec2f screenToCanvasScale;
    
    
};
#endif /* defined(__Crystalfilm__Canvas__) */
