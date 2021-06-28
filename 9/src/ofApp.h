#pragma once

#include "ofMain.h"

class Ball {
 public:
  ofVec2f pos;  // center position of circle
  ofVec2f vel;  // velocity of circle animation
  float rad;    // radius
  ofColor color;

  Ball();
  void update();
  void draw();
};

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  std::vector<Ball> balls;
};
