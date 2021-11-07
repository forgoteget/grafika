#include <iostream>
#include "Camera.h"

/*
Camera::Camera(){
}

void Camera::apply(){
	gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);
}*/

Camera::Camera(){
}

Camera::Camera(vec3 position1){
	position = position1;
}

Camera::Camera(float x, float y, float z){
}

void Camera::setPosition(vec3 position)
{
	r = length(position);
	vec3 v1 = position;
	vec3 v2 = vec3(v1.x, 0, v1.z);
	float cos_y = dot(normalize(v1), normalize(v2));
	angleY = degrees(acos(cos_y));
	float cos_x = dot(normalize(v2), vec3(1, 0, 0));
	angleX = degrees(acos(cos_x));
	recalculatePosition();
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
	
}
