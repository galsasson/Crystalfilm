#include "testApp.h"

ofxControlease *control;

//--------------------------------------------------------------
void testApp::setup(){
    control = new ofxControlease();
    control->setup("Crystalfilm", 6002);
    fabricAlpha = 1;
    control->addInput("Fabric Alpha", &fabricAlpha);
    brush.red = 120;
    control->addInput("stroke RED", &brush.red);
    brush.green = 0;
    control->addInput("stroke GREEN", &brush.green);
    brush.blue = 0;
    control->addInput("stroke BLUE", &brush.blue);
    brush.alpha = 160;
    control->addInput("stroke ALPHA", &brush.alpha);
    scale.set(1, 1);
    control->addInput("scale X", &scale.x);
    control->addInput("scale Y", &scale.y);
    canvas.blurResolution = 14;
    control->addInput("Blur Resolution", &canvas.blurResolution);
    canvas.blurRadius = 10;
    control->addInput("Blur Radius", &canvas.blurRadius);
    
//    fabricImg.loadImage("art/texture-woven-fabric.jpg");
    fabricImg.loadImage("art/Yellow_Velvet_Fabric_Texture_by_Enchantedgal_Stock.jpg");
    cout<<"image size = "<<fabricImg.width<<"x"<<fabricImg.height<<endl;
    burnShader.load("shaders/PhotoshopMathFP");
    
    brush.type = 1;
    canvas.setup(fabricImg.width, fabricImg.height, &brush);
}

//--------------------------------------------------------------
void testApp::update(){
    canvas.update();
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofClear(255, 0, 255);
//    canvas.draw();
//    return;
    
    // draw on screen
    ofClear(0);
    ofPushMatrix();
    fabricImg.draw(0, 0);
    canvas.draw();
    ofPopMatrix();
}

void testApp::exit()
{
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
    canvas.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    canvas.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    canvas.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    canvas.windowResized(w, h);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
