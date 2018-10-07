#include "pch.h"
#include "Renderer.h"

float Renderer::m_scale = 0.0f;
Matrix4f Renderer::m_world;

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
	glutIdleFunc(Render);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

void Renderer::Render()
{
	m_scale += 0.001;
	SetWorldMatrix();

	GLuint gWorldLocation = ShaderUtils::GetUniformLocation("gWorld");

	glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, &m_world.m[0][0]);

	glClear(GL_COLOR_BUFFER_BIT);


	//activation de l'attribut 0 des sommets (c'est à dire leur position)
	glEnableVertexAttribArray(0);

	//interprétation des données dans le tampon par le pipeline
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void Renderer::SetWorldMatrix()
{
	m_world.m[0][0] = 1.0f; m_world.m[0][1] = 0.0f; m_world.m[0][2] = 0.0f; m_world.m[0][3] = sinf(m_scale);
	m_world.m[1][0] = 0.0f; m_world.m[1][1] = 1.0f; m_world.m[1][2] = 0.0f; m_world.m[1][3] = 0.0f;
	m_world.m[2][0] = 0.0f; m_world.m[2][1] = 0.0f; m_world.m[2][2] = 1.0f; m_world.m[2][3] = 0.0f;
	m_world.m[3][0] = 0.0f; m_world.m[3][1] = 0.0f; m_world.m[3][2] = 0.0f; m_world.m[3][3] = 1.0f;
}
