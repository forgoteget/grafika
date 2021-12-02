#include <iostream>
#include "Camera.h"

Camera::Camera(){
}

void Camera::apply(){
	gluLookAt(30, 15, 17.5,
		0, 0, 0,
		0, 1, 0);
}

/*
Camera::Camera(){
	gluLookAt(position[0], position[1], position[2], 0, 0, 0, 0, 1, 0);
}

Camera::Camera(vec3 position1){
	position = position1;
	setPosition(position);
}

Camera::Camera(float x, float y, float z){
	position = vec3(x,y,z);
	setPosition(position);
}

void Camera::setPosition(vec3 position1)
{
	r = length(position1);
	vec3 v1 = position1;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	gluLookAt(angleX, angleY, r, 0, 0, 0, 0, 1, 0);
//	recalculatePosition();
} 

vec3 Camera::getPosition(){
	return position;
}

void Camera::rotateLeftRight(float degree){
}

void Camera::rotateUpDown(float degree){
}

void Camera::zoomInOut(float distance){
}

void Camera::recalculatePosition(){
	
}*/
