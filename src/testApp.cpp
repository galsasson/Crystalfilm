#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    control.setup("Crystalfilm", 6002);
    fabricAlpha = 1;
    control.addInput("Fabric Alpha", &fabricAlpha);
    brush.setColor(1);
    control.addInput("stroke RED", &brush.red);
    control.addInput("stroke GREEN", &brush.green);
    control.addInput("stroke BLUE", &brush.blue);
    control.addInput("stroke ALPHA", &brush.alpha);
    scale.set(1, 1);
    control.addInput("scale X", &scale.x);
    control.addInput("scale Y", &scale.y);
    canvas[0].blurResolution = 10;
    canvas[0].blurRadius = 5;
    control.addInput("[A] Blur Radius", &canvas[0].blurRadius);
    canvas[0].vel = ofVec3f();
    control.addInput("[A] Velocity X", &canvas[0].vel.x);
    control.addInput("[A] Velocity Y", &canvas[0].vel.y);
    control.addInput("[A] Velocity Z", &canvas[0].vel.z);
    canvas[0].distortion = 0;
    control.addInput("[A] Distortion", &canvas[0].distortion);

    
//    fabricImg.loadImage("art/texture-woven-fabric.jpg");
    fabricImg.loadImage("art/Yellow_Velvet_Fabric_Texture_by_Enchantedgal_Stock.jpg");
//    fabricImg.loadImage("art/fabric_decorated.jpg");
//    fabricImg.loadImage("art/blue_mohair_fabric_texture.jpg");

    cout<<"image size = "<<fabricImg.width<<"x"<<fabricImg.height<<endl;
    burnShader.load("shaders/PhotoshopMathFP");
    
    brush.type = 0;
    canvas[0].setup(fabricImg.width, fabricImg.height, &brush);
}

//--------------------------------------------------------------
void testApp::update(){
    canvas[0].update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofClear(0);
    canvas[0].draw();
    return;
    
    // draw on screen
    ofClear(0);
    ofPushMatrix();
    fabricImg.draw(0, 0);
    canvas[0].draw();
    ofPopMatrix();
}

void testApp::exit()
{
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    cout << "key: "<<key<<endl;
    if (key >= 48 &&
        key <= 55) {
        brush.setColor(key-48);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    canvas[0].mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
    canvas[0].mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    canvas[0].mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    canvas[0].windowResized(w, h);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
