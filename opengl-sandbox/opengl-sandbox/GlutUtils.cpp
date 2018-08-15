#include "pch.h"
#include "GlutUtils.h"


GlutUtils::GlutUtils()
{
}

void GlutUtils::Init(int argc, char **argv)
{
	//initialisation de glut
	glutInit(&argc, argv);

	//configuration en double buffering et mode de couleur rgba
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//paramètres de la fenêtre
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Sandbox");

	glutDisplayFunc(Render);
}


GlutUtils::~GlutUtils()
{
}

void GlutUtils::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
