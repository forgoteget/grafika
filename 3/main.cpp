#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include "GraphicObject.h"
#include "Camera.h"
#include <iostream>
using namespace glm;
std::vector<GraphicObject> graphicObjects;
Camera camera;

void Simulation(int value){
	glutPostRedisplay();
	glutTimerFunc(20, Simulation, 0);
}

void Reshape(int w, int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w/h, 0.2, 70.0);
}

void Display(void){
	glClearColor(0.00, 0.00, 0.00, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.apply();
//	gluLookAt(10, 15, 17.5, 0, 0, 0, 0, 1, 0);
//	Camera camera;
	for (auto& go : graphicObjects) {
		go.draw();
	}
	glutSwapBuffers(); 
}

void KeyboardFunc(unsigned char key, int x, int y){
	printf("Key code is %i\n", (unsigned int) key);
	switch (static_cast<char>(key)) {
	case 'w':
//		camera.rotateUpDown(5.0);
		break;
	case 's':
//		camera.rotateUpDown(-5.0);
		break;
	case 'a':
//		camera.rotateLeftRight(5.0);
		break;
	case 'd':
//		camera.rotateLeftRight(-5.0);
		break;
	case '+':
//		camera.zoomInOut(0.2);
		break;
	case '-':
//		camera.zoomInOut(-0.2);
		break;
	} 
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	////////////sozdanie okna///////////////////
	//verxniy leviy ugol
	glutInitWindowPosition(200, 200);
	//razmer okna
	glutInitWindowSize(600, 600);
	//sozdanie okna
	glutCreateWindow("laba3");
	
	///////////callback functions///////////////
	//vizov pri pererisovke
	glutDisplayFunc(Display);
	//vizov pri izmenenii razmera
	glutReshapeFunc(Reshape);
	// funkciya kotoraya vizovetsya cherez 20 ms
	glutTimerFunc(20, Simulation, 0);
	// vizov pri nazhatii na klavishu
	glutKeyboardFunc(KeyboardFunc);
	
	GraphicObject tempGraphicObject;
	//1
	tempGraphicObject.setPosition(vec3(4,0,0));
	tempGraphicObject.setAngle(180);
	tempGraphicObject.setColor(vec3(255,255,255));
	graphicObjects.push_back(tempGraphicObject);
	//2
	tempGraphicObject.setPosition(vec3(-4,0,0));
	tempGraphicObject.setAngle(0);
	tempGraphicObject.setColor(vec3(255,0,0));
	graphicObjects.push_back(tempGraphicObject);
	//3
	tempGraphicObject.setPosition(vec3(0,0,-4));
	tempGraphicObject.setAngle(270);
	tempGraphicObject.setColor(vec3(0,255,0));
	graphicObjects.push_back(tempGraphicObject);
	//4
	tempGraphicObject.setPosition(vec3(0,0,4));
	tempGraphicObject.setAngle(90);
	tempGraphicObject.setColor(vec3(0,0,255));
	graphicObjects.push_back(tempGraphicObject);
	
	glutMainLoop();
	
	return 0;
}
