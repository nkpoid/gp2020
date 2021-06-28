#include <stdio.h>

#include "ofMain.h"

class Particle {
 public:
  Particle();

  ofVec2f pos;   // center position of circle
  ofVec2f vel;   // velocity of circle animation
  float radius;  // radius
  ofColor color;

  void update();
  void draw();
};