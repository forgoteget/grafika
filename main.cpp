#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

void Simulation(int value){
	glutPostRedisplay();
	glutTimerFunc(20, Simulation, 0);
}

void Reshape(int w, int h){
	glViewport(0,0,w,h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w/h, 0.2, 70.0);
}

void Display(void){
	glClearColor(0.22, 0.88, 0.11, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5,5,7.5,0,0,0,0,1,0);
	
	glColor3f(1.0, 0.0, 0.0);
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
	glutCreateWindow("laba1");
	
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
