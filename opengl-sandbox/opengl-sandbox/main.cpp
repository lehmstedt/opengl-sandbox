#include "pch.h"


int main(int argc, char ** argv)
{

	GlutUtils::Init(argc, argv);

	GLenum res = glewInit();

	if (res != GLEW_OK) {
		fprintf(stderr, "Erreur : '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//structure de donnees pour creer un point au milieu de l'ecran
	Vector3f vertices[1];
	vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	//generation du buffer pour le VBO
	GLuint VBO;
	glGenBuffers(1, &VBO);

	//definit le VBO comme un tableau de sommets
	glBindBuffer(GL_ARRAY_BUFFER, VBO);



	while (true) {
		glutMainLoop();
	}

}