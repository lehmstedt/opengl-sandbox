#pragma once

#include <GL/glut.h>
class GlutUtils
{
public:
	GlutUtils();
	static void Init(int argc, char **argv);
	~GlutUtils();

private:
	static void Render();
	
};

