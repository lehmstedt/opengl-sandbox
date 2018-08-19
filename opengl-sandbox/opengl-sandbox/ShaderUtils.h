#pragma once
class ShaderUtils
{
public:
	ShaderUtils();
	~ShaderUtils();
	static void CreateVertexShader(const char * filename);
	static void CreateFragmentShader(const char * filename);
	static void InitShaderProgram();
	static void UseShaderProgram();

private:
	static void CreateShader(GLint shaderType, const char * filename);
	static const GLchar * GetShaderSource(const char * filename);
	static GLuint m_shaderProgram;
};

