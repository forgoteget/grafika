#include "GraphicObject.h"
#include <iostream>

GraphicObject::GraphicObject(){
}

void GraphicObject::setPosition(vec3 position){
//	position = position1;
}

vec3 GraphicObject::getPosition(){
	return position;
}

void GraphicObject::setAngle(float grad){
	angle = grad;
}

float GraphicObject::getAngle(){
	return angle;
}

void GraphicObject::setColor(vec3 color1){
	color = color1;
}

vec3 GraphicObject::getColor(){
	return color;
}

void GraphicObject::recalculateModelMatrix(){
}

void GraphicObject::draw(){
	glPushMatrix();
	glTranslatef(position[0], position[1], position[2]);
	glColor3ub(color[0], color[1], color[2]);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glutWireTeapot(1.0);
	glPopMatrix();
}
