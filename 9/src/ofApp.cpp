#include "ofApp.h"

Ball::Ball() {
  pos.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
  vel.set(ofRandom(-5, 5), ofRandom(-5, 5));
  rad = ofRandom(5, 30);
  color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 50);
}

void Ball::update() {
  pos += vel;

  // boundary cond
  if (pos.x > ofGetWindowWidth() - rad || pos.x < rad) {
    vel.x *= -1;
  }
  if (pos.y > ofGetHeight() - rad || pos.y < rad) {
    vel.y *= -1;
  }
}

void Ball::draw() {
  ofSetColor(color);
  ofDrawCircle(pos.x, pos.y, rad);
}

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
  for (int i = 0; i < 1000; i++) {
    balls.push_back(Ball());
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto& b : balls) {
    b.update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto& b : balls) {
    b.draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}