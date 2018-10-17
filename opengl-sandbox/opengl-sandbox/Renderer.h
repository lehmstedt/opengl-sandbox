#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();
	static void Init(int argc, char **argv);
	static void Close();

private:
	static void Render();
	static float m_scale;
	static Camera * m_camera;
	static void SpecialKeyboardCB(int Key, int x, int y);
};

