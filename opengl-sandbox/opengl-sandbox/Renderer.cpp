#include "pch.h"
#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Init(int argc, char ** argv)
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

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	

}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);


	//activation de l'attribut 0 des sommets (c'est à dire leur position)
	glEnableVertexAttribArray(0);

	//interprétation des données dans le tampon par le pipeline
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}
