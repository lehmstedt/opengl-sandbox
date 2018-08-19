#include "pch.h"
#include "ShaderUtils.h"

GLuint ShaderUtils::m_shaderProgram;

ShaderUtils::ShaderUtils()
{
}


ShaderUtils::~ShaderUtils()
{
}

void ShaderUtils::CreateVertexShader(const char * filename)
{
	CreateShader(GL_VERTEX_SHADER, filename);
}

void ShaderUtils::CreateFragmentShader(const char * filename)
{
	CreateShader(GL_FRAGMENT_SHADER, filename);
}

void ShaderUtils::InitShaderProgram()
{
	m_shaderProgram = glCreateProgram();
}

void ShaderUtils::UseShaderProgram()
{
	GLint success;

	//on lie le programme de shader au projet
	glLinkProgram(m_shaderProgram);

	//on vérifie que le programme est bien lié
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);

	if (success == 0) {
		GLchar errorLog[1024];
		glGetProgramInfoLog(m_shaderProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Erreur lors du lien du programme de shader : %s", errorLog);
	}

	//vérifie que le programme de shader peut s'executer dans le pipeline actuel
	glValidateProgram(m_shaderProgram);

	//on fait utiliser le programme de shader par le pipeline
	glUseProgram(m_shaderProgram);
}

void ShaderUtils::CreateShader(GLint shaderType, const char * filename)
{
	GLuint vertexShader = glCreateShader(shaderType);

	//spécification du code source du shader
	const GLchar * vertexShaderSources[1];
	vertexShaderSources[0] = GetShaderSource(filename);
	GLint vertexShaderlengths[1];
	vertexShaderlengths[0] = strlen(vertexShaderSources[0]);
	glShaderSource(vertexShader, 1, vertexShaderSources, vertexShaderlengths);

	//compilation du shader
	glCompileShader(vertexShader);

	//vérification de la compilation
	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	//log en cas d'erreur de compilation
	if (!success) {
		GLchar infoLog[1024];
		glGetShaderInfoLog(vertexShader, sizeof(infoLog), NULL, infoLog);
		fprintf(stderr, "Erreur lors de la compilation du shader : %s", infoLog);
		return;
	}

	//on attache le vertex shader au programme de shader
	glAttachShader(m_shaderProgram, vertexShader);
}

const GLchar * ShaderUtils::GetShaderSource(const char * filename)
{
	std::ifstream in(filename);
	std::string source((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

	//il faut ajouter un '\0' a la fin de la chaine de characteres pour bien la terminer
	int length = strlen(source.c_str()) + 1;
	char * cleanSource = new char[length];

	strncpy_s(cleanSource, length, source.c_str(), length - 1);
	cleanSource[length - 1] = '\0';
	return cleanSource;
}
