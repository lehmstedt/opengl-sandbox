#include "pch.h"
#include "GeometryUtils.h"


GeometryUtils::GeometryUtils()
{
}


GeometryUtils::~GeometryUtils()
{
}

void GeometryUtils::CreatePoints(Vector3f * vertices, int number)
{
	

	//generation du buffer pour le VBO
	GLuint VBO;
	glGenBuffers(1, &VBO);

	//definit le VBO comme un tableau de sommets
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//remplit le buffer avec les données de structure Vector3f
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(vertices), vertices, GL_STATIC_DRAW);
}
