#include "pch.h"
#include "GeometryUtils.h"


GeometryUtils::GeometryUtils()
{
}


GeometryUtils::~GeometryUtils()
{
}


void GeometryUtils::CreatePyramid()
{

	//generation du buffer pour le VBO
	GLuint VBO;
	GLuint IBO;
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);

	Vector3f Vertices[4];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(0.0f, -1.0f, 1.0f);
	Vertices[2] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[3] = Vector3f(0.0f, 1.0f, 0.0f);

	unsigned int Indices[] = { 0, 3, 1,
						   1, 3, 2,
						   2, 3, 0,
						   0, 1, 2 };

	//definit le VBO comme un tableau de sommets
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	//remplit le buffer avec les données de structure Vector3f
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vector3f), Vertices, GL_STATIC_DRAW);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

}
