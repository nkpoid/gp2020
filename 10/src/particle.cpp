#include "particle.h"

Particle::Particle() {
  pos.set(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
  vel.set(ofRandom(-5, 5), ofRandom(-5, 5));
  radius = ofRandom(5, 30);
  color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 50);
}

void Particle::update() {
  pos += vel;

  // boundary cond
  if (pos.x > ofGetWindowWidth() - radius || pos.x < radius) {
    vel.x *= -1;
  }
  if (pos.y > ofGetHeight() - radius || pos.y < radius) {
    vel.y *= -1;
  }
}

void Particle::draw() {
  ofSetColor(color);
  ofDrawCircle(pos.x, pos.y, radius);
}