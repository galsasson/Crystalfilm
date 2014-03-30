#pragma once

#include <vector.h>

#include "ofMain.h"
#include "ofxControlease.h"
#include "Stroke.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
private:
    void applyBlur(ofFbo &fbo);
    void clearCanvas();

    ofxControlease control;
    float red, green, blue, alpha;
    ofVec2f translate;
    ofVec2f scale;
    
    ofShader burnShader;
    ofImage fabricImg;
    ofFbo canvasFbo;

    ofFbo blurFbo;
    ofShader horBlurShader;
    float blurResolution;
    float blurRadius;
    ofVec2f blurDirection;

    
    ofVec2f screenToCanvasScale;
    
    
    vector<Stroke*> strokes;
    Stroke *currentStroke;
};
