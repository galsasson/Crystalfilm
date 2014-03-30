#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    control.setup("Crystalfilm", 6002);
    red = 0;
    control.addInput("stroke RED", &red);
    green = 0;
    control.addInput("stroke GREEN", &green);
    blue = 0;
    control.addInput("stroke BLUE", &blue);
    alpha = 100;
    control.addInput("stroke ALPHA", &alpha);
    translate.set(0, 0);
    control.addInput("translate X", &translate.x);
    control.addInput("translate Y", &translate.y);
    scale.set(1, 1);
    control.addInput("scale X", &scale.x);
    control.addInput("scale Y", &scale.y);
    blurResolution = 14;
    control.addInput("Blur Resolution", &blurResolution);
    blurRadius = 20;
    control.addInput("Blur Radius", &blurRadius);
    
    
    
    
//    fabricImg.loadImage("art/texture-woven-fabric.jpg");
    fabricImg.loadImage("art/Yellow_Velvet_Fabric_Texture_by_Enchantedgal_Stock.jpg");
    cout<<"image size = "<<fabricImg.width<<"x"<<fabricImg.height<<endl;
    burnShader.load("shaders/PhotoshopMathFP");
    horBlurShader.load("shaders/simpleBlurHorizontal");
    canvasFbo.allocate(fabricImg.width, fabricImg.height, GL_RGBA);
    blurFbo.allocate(fabricImg.width, fabricImg.height, GL_RGBA);
    
    currentStroke = NULL;
    screenToCanvasScale = ofVec2f((float)fabricImg.width / ofGetWidth(), (float)fabricImg.height / ofGetHeight());
}

//--------------------------------------------------------------
void testApp::update(){
    // draw on canvas canvas
    canvasFbo.begin();
    ofClear(255, 255, 255, 255);
    ofSetColor(red, green, blue, alpha);
    for (int i=0; i<strokes.size(); i++)
    {
        strokes[i]->draw();
    }
    if (currentStroke) {
        currentStroke->draw();
    }
    canvasFbo.end();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    applyBlur(canvasFbo);
    
    // draw on screen
    ofClear(0);
    ofPushMatrix();
    ofTranslate(translate);
    
    ofSetColor(255, 255, 255, 255);
    burnShader.begin();
    burnShader.setUniform2f("screenSize", ofGetWidth()*scale.x, ofGetHeight()*scale.y);
    // can get the following two from the GPU pipeline itself?
    burnShader.setUniform2f("canvasSize", fabricImg.width, fabricImg.height);
    burnShader.setUniformTexture("fabricTex", fabricImg.getTextureReference(), 0);
    burnShader.setUniformTexture("canvasTex", canvasFbo.getTextureReference(), 1);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    burnShader.end();
    
    ofPopMatrix();
}

void testApp::exit()
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

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    if (!currentStroke) {
        return;
    }
    
    currentStroke->addPoint(ofVec2f(x, ofGetHeight()-y) * screenToCanvasScale);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    currentStroke = new Stroke(ofVec2f(x, ofGetHeight()-y) * screenToCanvasScale);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (!currentStroke) {
        return;
    }
    
    strokes.push_back(currentStroke);
    currentStroke = NULL;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    screenToCanvasScale = ofVec2f((float)fabricImg.width / ofGetWidth(), (float)fabricImg.height / ofGetHeight());
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::applyBlur(ofFbo &fbo)
{
    horBlurShader.begin();
    horBlurShader.setUniform1f("resolution", blurResolution);
    horBlurShader.setUniform1f("radius", blurRadius);
    
    blurFbo.begin();
    horBlurShader.setUniform2f("dir", 1, 0);
    ofSetColor(255, 255, 255, 255);
    fbo.draw(0, 0);
    blurFbo.end();
    
    fbo.begin();
    ofClear(0);
    horBlurShader.setUniform2f("dir", 0, 1);
    ofSetColor(255, 255, 255, 255);
    blurFbo.draw(0, 0);
    fbo.end();
    
    horBlurShader.end();
}

void testApp::clearCanvas()
{
    canvasFbo.begin();
    ofClear(255, 255, 255, 255);
    canvasFbo.end();
}
