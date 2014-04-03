#pragma once

#include <vector.h>

#include "ofMain.h"
#include "ofxControlease.h"
#include "Canvas.h"
#include "Brush.h"

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
    ofxControlease control;
    
    Brush brush;
    Canvas canvas[4];

    ofVec2f scale;
    
    ofShader burnShader;
    ofImage fabricImg;
    float fabricAlpha;
    
};
