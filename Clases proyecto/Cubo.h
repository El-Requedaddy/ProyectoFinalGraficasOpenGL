#pragma once

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <vector>
#endif

class Cubo {

public:
	Cubo();
	~Cubo();
	void visualizar();


};