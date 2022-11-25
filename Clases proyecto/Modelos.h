#pragma once

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <vector>
#endif
#include "Sphere.h"
#include "Cylinder.h"
class Modelos
{
private:
	float  h;
	float b;

	std::vector<GLfloat> color_rojo;
	std::vector<GLfloat> color_grisOscuro;
	std::vector<GLfloat> color_verdeAzul;
	std::vector<GLfloat> color_azul;
	Cylinder* cil;
	Sphere* sph;
	Cylinder* cono;

public:
	Modelos();

	void visualizar();
	//Primitivas de Robot
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
	
	//Primitivas Puesto
	void Estanteria();

	//Primitivas básicas
	void cilindro(GLfloat color_cilindro[]);
	void esfera(GLfloat color_esfera[]);
	void cubo(GLfloat color_cubo[]);
	void cono3D(GLfloat color_cono[]);
	



};

