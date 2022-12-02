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
	std::vector<GLfloat> color_marron;

	std::vector<GLfloat> color_base_cabeza;
	std::vector<GLfloat> color_brazo_sup;
	std::vector<GLfloat> color_brazo_inf;
	std::vector<GLfloat> color_mano;
	//Colores lado izq
	std::vector<GLfloat> color_brazo_supIzq;
	std::vector<GLfloat> color_brazo_infIzq;
	std::vector<GLfloat> color_manoIzq;
	Cylinder* cil;
	Sphere* sph;
	Cylinder* cono;

public:
	Modelos();

	void visualizar();
	//Primitivas de Robot
	void cabeza(std::vector<GLfloat> color_azul, std::vector<GLfloat> color_rojo2, std::vector<GLfloat> color_Verde_Azul, std::vector<GLfloat> color_gris);
	void torso();
	void piernas(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_pierna_sup, int lado);
	void piernas_inf(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_pierna_inf, int lado);
	void pies(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_pie, int lado);
	void brazo();  
	void brazo_superior(std::vector<GLfloat> color_brazo_sup_, int lado);
	void brazo_inferior(std::vector<GLfloat> color_brazo_inf_, std::vector<GLfloat> color_codo, int lado);
	void mano(std::vector<GLfloat> color_muneca, std::vector<GLfloat> color_palma, int lado);
	void dedo(std::vector<GLfloat> color_dedo, int num_dedo);
	void articulacionDedo();
	void cuello(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_cuello);
	
	//Primitivas Puesto
	void Estanteria();
	void Mostrador();

	//Primitivas básicas
	void cilindro(GLfloat color_cilindro[]);
	void esfera(GLfloat color_esfera[]);
	void cubo(GLfloat color_cubo[]);
	void cono3D(GLfloat color_cono[]);

	//MÉTODOS PARA GESTIONAR LOS COLORES DE LAS PARTES DEL ROBOT
	
	void set_colorBaseCabeza(std::vector<GLfloat> a) {
		for (int i = 0; i < color_base_cabeza.size(); i++) {
			color_base_cabeza[i] = a[i];
		}
	}
	void set_colorBrazoSup(std::vector<GLfloat> a) {
		for (int i = 0; i < color_brazo_sup.size(); i++) {
			color_brazo_sup[i] = a[i];
		}
	}
	void set_colorBrazoInf(std::vector<GLfloat> a) {
		for (int i = 0; i < color_brazo_inf.size(); i++) {
			color_brazo_inf[i] = a[i];
		}
	}
	void set_colorMano(std::vector<GLfloat> a) {
		for (int i = 0; i < color_mano.size(); i++) {
			color_mano[i] = a[i];
		}
	}
	//LADO IZQUIERDO
	void set_colorBrazoSupIzq(std::vector<GLfloat> a) {
		for (int i = 0; i < color_brazo_supIzq.size(); i++) {
			color_brazo_supIzq[i] = a[i];
		}
	}
	void set_colorBrazoInfIzq(std::vector<GLfloat> a) {
		for (int i = 0; i < color_brazo_infIzq.size(); i++) {
			color_brazo_infIzq[i] = a[i];
		}
	}
	void set_colorManoIzq(std::vector<GLfloat> a) {
		for (int i = 0; i < color_manoIzq.size(); i++) {
			color_manoIzq[i] = a[i];
		}
	}


};

