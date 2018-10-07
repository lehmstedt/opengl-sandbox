#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();
	static void Init(int argc, char **argv);

private:
	static void Render();
	static float m_scale;
	static Matrix4f m_world;
	static void SetWorldMatrix();
};

