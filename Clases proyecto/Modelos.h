#pragma once

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <vector>
#endif
class Modelos
{
private:
	float  h;
	float b;

	std::vector<GLfloat> color_rojo;
	std::vector<GLfloat> color_grisOscuro;
	std::vector<GLfloat> color_verdeAzul;
	std::vector<GLfloat> color_azul;

public:
	Modelos();

	void visualizar();
	void base();
	void cabeza();
	void torso();
	void piernas();
	void piernas_inf();
	void pies();
	void brazo();  
	void brazo_superior();
	void brazo_inferior();
	void mano();
	void dedo();
	void articulacionDedo();
	void cuello();

	void cilindro(GLfloat color_cilindro[]);
	void esfera(GLfloat color_esfera[]);
	void cubo(GLfloat color_cubo[]);
	void cono3D(GLfloat color_cono[]);
	



};

