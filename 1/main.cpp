#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
using namespace glm;

int i=1, timeCount=0;
std::vector<ivec3> teapotColor {{255,255,255},{0,0,255},{255,0,0},{255,255,0},{90,0,90}};
std::vector<ivec3> color;
//white blue red yellow purple

void Simulation(int value){
	timeCount+=20;
	if(timeCount == 1000){
		timeCount = 0;
		color.clear();
		color.push_back(teapotColor[i]);
		i++;
		if(i==5){
			i = 0;
		}
	}
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
	glClearColor(0.22, 0.88, 0.11, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5,5,7.5,0,0,0,0,1,0);
	
	if(color.empty())
		color.push_back(teapotColor[0]);
	glColor3ub((int)color[0][0], (int)color[0][1], (int)color[0][2]);
	glutWireTeapot(1.0);
	
	glutSwapBuffers();
}

void KeyboardFunc(unsigned char key, int x, int y){
	printf("Key code is %i\n", (unsigned int) key);
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
	glutCreateWindow("laba2");
	
	///////////callback functions///////////////
	//vizov pri pererisovke
	glutDisplayFunc(Display);
	//vizov pri izmenenii razmera
	glutReshapeFunc(Reshape);
	// funkciya kotoraya vizovetsya cherez 20 ms
	glutTimerFunc(20, Simulation, 0);
	// vizov pri nazhatii na klavishu
	glutKeyboardFunc(KeyboardFunc);
	
	glutMainLoop();
	
	return 0;
}
