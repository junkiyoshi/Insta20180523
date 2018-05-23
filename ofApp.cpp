#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	this->draw_line_circle(ofPoint(-230, -230));
	this->draw_line_circle(ofPoint(0, -230));
	this->draw_line_circle(ofPoint(230, -230));

	this->draw_line_circle(ofPoint(-230, 0));
	this->draw_line_circle(ofPoint(0, 0));
	this->draw_line_circle(ofPoint(230, 0));

	this->draw_line_circle(ofPoint(-230, 230));
	this->draw_line_circle(ofPoint(0, 230));
	this->draw_line_circle(ofPoint(230, 230));
}

//--------------------------------------------------------------
void ofApp::draw_line_circle(ofPoint point) {

	ofPushMatrix();
	ofTranslate(point);

	int radius = 100;
	for (int line = 0; line < 18; line++) {

		ofColor color;
		color.setHsb(ofRandom(255), 200, 200);
		ofSetColor(color);

		ofRotate(ofRandom(360));

		int start_deg = ofRandom(180) + ofGetFrameNum();
		int end_deg = start_deg + 8;

		vector<ofPoint> vertices;
		for (int deg = start_deg; deg <= end_deg; deg += 1) {

			vertices.push_back(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		}

		for (int deg = 360 - end_deg; deg <= 360 - start_deg; deg += 1) {

			vertices.push_back(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
		}

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}