#ifndef GRAPHICOBJECT_H
#define GRAPHICOBJECT_H
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

class GraphicObject
{
	public:
		GraphicObject();
		void setPosition(vec3 position);
		vec3 getPosition();
		void setAngle(float grad);
		float getAngle();
		void setColor(vec3 color);
		vec3 getColor();
		void draw();
	private:
		vec3 position;
		float angle;
		vec3 color;
}; 
#endif
