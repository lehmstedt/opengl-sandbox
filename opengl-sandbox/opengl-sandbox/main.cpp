#include "pch.h"


int main(int argc, char ** argv)
{

	Renderer::Init(argc, argv);

	GLenum res = glewInit();

	if (res != GLEW_OK) {
		fprintf(stderr, "Erreur : '%s'\n", glewGetErrorString(res));
		return 1;
	}

	GeometryUtils::CreatePoint(0.0f, 0.0f, 0.0f);

	
	glutMainLoop();

	return 0;
	

}