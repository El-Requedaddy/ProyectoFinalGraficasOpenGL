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

private:
	/*std::vector<GLfloat> vertexCubo;
	std::vector<GLfloat> textCoordCubo;*/

public:
	Cubo();
	~Cubo();
	static void visualizar(); //cubo
	static void visualizarLata();
	static void cara_abajo(); //solo quad de abajo
	static void cara_derecha(); //solo quad de abajo


};