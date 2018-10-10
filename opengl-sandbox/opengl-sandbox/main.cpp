#include "pch.h"


void processShaders() {
	
	ShaderUtils::InitShaderProgram();
	ShaderUtils::CreateVertexShader("exemple.vert");
	ShaderUtils::CreateFragmentShader("exemple.frag");
	ShaderUtils::UseShaderProgram();
	
}

int main(int argc, char ** argv)
{

	Renderer::Init(argc, argv);

	GLenum res = glewInit();

	if (res != GLEW_OK) {
		fprintf(stderr, "Erreur : '%s'\n", glewGetErrorString(res));
		return 1;
	}

	GeometryUtils::CreatePyramid();

	processShaders();
	
	glutMainLoop();

	return 0;
	

}