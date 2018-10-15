#include "pch.h"
#include "Renderer.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

float Renderer::m_scale = 0.0f;

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

	//param�tres de la fen�tre
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sandbox");

	glutDisplayFunc(Render);
	glutIdleFunc(Render);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

void Renderer::Render()
{
	m_scale += 0.001;

	GLuint gWorldLocation = ShaderUtils::GetUniformLocation("gWorld");

	Pipeline p;
	p.Scale(1.0f, 1.0f, 1.0f);
	p.WorldPos(136.0f, 1.0f, 300.0f);
	p.Rotate(sinf(m_scale) * 90.0f, sinf(m_scale) * 90.0f, sinf(m_scale) * 90.0f);
	Vector3f CameraPos(1.0f, 1.0f, -3.0f);
	Vector3f CameraTarget(0.45f, 0.0f, 1.0f);
	Vector3f CameraUp(0.0f, 1.0f, 0.0f);
	p.SetCamera(CameraPos, CameraTarget, CameraUp);
	p.SetPerspectiveProj(30.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 1.0f, 1000.0f);
	glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, (const GLfloat*)p.GetTrans());

	glClear(GL_COLOR_BUFFER_BIT);


	//activation de l'attribut 0 des sommets (c'est � dire leur position)
	glEnableVertexAttribArray(0);

	//interpr�tation des donn�es dans le tampon par le pipeline
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

