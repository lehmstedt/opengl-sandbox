#include "pch.h"


int main(int argc, char ** argv)
{

	Renderer::Init(argc, argv);

	GLenum res = glewInit();

	if (res != GLEW_OK) {
		fprintf(stderr, "Erreur : '%s'\n", glewGetErrorString(res));
		return 1;
	}

	//structure de donnees pour creer un point au milieu de l'ecran
	Vector3f vertices[3];
	vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	GeometryUtils::CreatePoints(vertices, 3);

	
	glutMainLoop();

	return 0;
	

}