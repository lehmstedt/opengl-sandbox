#pragma once
class Renderer
{
public:
	Renderer();
	~Renderer();
	static void Init(int argc, char **argv);

private:
	static void Render();
};

