#ifndef CAMERA_H
#define CAMERA_H
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

/*
class Camera{
	public:
		Camera();
		void apply();
};*/

class Camera
{
public:
	Camera();
	Camera(vec3 position);
	Camera(float x, float y, float z);
	void setPosition(vec3 position);
	vec3 getPosition();
	void rotateLeftRight(float degree);
	void rotateUpDown(float degree);
	void zoomInOut(float distance);
private:
	void recalculatePosition();
private:
	float r;
	float angleX;
	float angleY;
	vec3 position;
};
#endif
