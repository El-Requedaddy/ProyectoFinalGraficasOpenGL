#pragma once

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <vector>
#endif

static class Cubo {

public:
	Cubo();
	~Cubo();
	static void visualizar(); //cubo
	static void cara_abajo(); //solo quad de abajo
	static void cara_derecha(); //solo quad de abajo


};