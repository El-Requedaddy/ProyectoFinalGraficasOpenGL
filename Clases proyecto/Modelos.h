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
#include "Colores.h"
#include "Cubo.h"
#include "igvTextura.h"
class Modelos
{
private:
	float  h;
	float b;

	std::vector<GLfloat> color_rojo;
	std::vector<GLfloat> color_grisOscuro;
	std::vector<GLfloat> color_verdeAzul;
	std::vector<GLfloat> color_azul;
	std::vector<GLfloat> color_marron;



	Cylinder* cil;
	Sphere* sph;
	Cylinder* cono;
	Colores* colores_robot;
	igvTextura* text;	//textura de madera
	igvTextura* text2; //textura de ladrillo
	igvTextura* text3; //textura de suelo
	igvTextura* text4;	//textura de cocacola
	igvTextura* text5; //textura de pepsi
	igvTextura* text6; //textura de fanta

public:
	Modelos();
	~Modelos();

	void visualizar();
	//Primitivas de Robot
	void cabeza(std::vector<GLfloat> color_rojo2, std::vector<GLfloat> color_Verde_Azul, std::vector<GLfloat> color_gris);
	void torso();
	void piernas(int lado);
	void piernas_inf(int lado);
	void pies(int lado);
	void brazo();  
	void brazo_superior(int lado);
	void brazo_inferior(int lado);
	void mano(int lado);
	void dedo(int num_dedo);
	void articulacionDedo();
	void cuello();
	
	//Primitivas Puesto
	void Estanteria();
	void Mostrador();
	void Suelo();
	void Pared();
	void latas(GLfloat color_lata[], int version = 1);

	//Primitivas básicas
	void cilindro(GLfloat color_cilindro[]);
	void esfera(GLfloat color_esfera[]);
	void cubo(GLfloat color_cubo[]);
	void cono3D(GLfloat color_cono[]);

	Colores* Get_coloresRobot() {
		return colores_robot;
	}

	void lata(GLfloat color_cubo[]);

};

