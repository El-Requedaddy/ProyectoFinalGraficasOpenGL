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

	//std::vector<GLfloat> color_base_cabeza;
	//std::vector<GLfloat> color_brazo_sup;
	//std::vector<GLfloat> color_brazo_inf;
	//std::vector<GLfloat> color_mano;
	//std::vector<GLfloat> color_dedo1;
	//std::vector<GLfloat> color_dedo2;
	//std::vector<GLfloat> color_dedo3;
	//std::vector<GLfloat> color_pierna;
	//std::vector<GLfloat> color_piernaInf;
	//std::vector<GLfloat> color_pie;
	////Colores lado izq
	//std::vector<GLfloat> color_brazo_supIzq;
	//std::vector<GLfloat> color_brazo_infIzq;
	//std::vector<GLfloat> color_manoIzq;
	//std::vector<GLfloat> color_dedo4;
	//std::vector<GLfloat> color_dedo5;
	//std::vector<GLfloat> color_dedo6;
	//std::vector<GLfloat> color_piernaIzq;
	//std::vector<GLfloat> color_piernaInfIzq;
	//std::vector<GLfloat> color_pieIzq;

	Cylinder* cil;
	Sphere* sph;
	Cylinder* cono;
	Colores* colores_robot;

public:
	Modelos();

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

	//Primitivas básicas
	void cilindro(GLfloat color_cilindro[]);
	void esfera(GLfloat color_esfera[]);
	void cubo(GLfloat color_cubo[]);
	void cono3D(GLfloat color_cono[]);

	//MÉTODOS PARA GESTIONAR LOS COLORES DE LAS PARTES DEL ROBOT
	//
	//void set_colorBaseCabeza(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_base_cabeza.size(); i++) {
	//		color_base_cabeza[i] = a[i];
	//	}
	//}
	//void set_colorBrazoSup(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_brazo_sup.size(); i++) {
	//		color_brazo_sup[i] = a[i];
	//	}
	//}
	//void set_colorBrazoInf(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_brazo_inf.size(); i++) {
	//		color_brazo_inf[i] = a[i];
	//	}
	//}
	//void set_colorMano(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_mano.size(); i++) {
	//		color_mano[i] = a[i];
	//	}
	//}
	//void set_colorDedo1(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_dedo1.size(); i++) {
	//		color_dedo1[i] = a[i];
	//	}
	//}
	//void set_colorDedo2(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_dedo2.size(); i++) {
	//		color_dedo2[i] = a[i];
	//	}
	//}
	//void set_colorDedo3(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_dedo3.size(); i++) {
	//		color_dedo3[i] = a[i];
	//	}
	//}
	//void set_colorPierna(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_pierna.size(); i++) {
	//		color_pierna[i] = a[i];
	//	}
	//}
	//void set_colorPiernaInf(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_piernaInf.size(); i++) {
	//		color_piernaInf[i] = a[i];
	//	}
	//}
	//void set_colorPie(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_pie.size(); i++) {
	//		color_pie[i] = a[i];
	//	}
	//}

	//
	////LADO IZQUIERDO
	//void set_colorBrazoSupIzq(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_brazo_supIzq.size(); i++) {
	//		color_brazo_supIzq[i] = a[i];
	//	}
	//}
	//void set_colorBrazoInfIzq(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_brazo_infIzq.size(); i++) {
	//		color_brazo_infIzq[i] = a[i];
	//	}
	//}
	//void set_colorManoIzq(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_manoIzq.size(); i++) {
	//		color_manoIzq[i] = a[i];
	//	}
	//}
	//void set_colorDedo4(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_dedo4.size(); i++) {
	//		color_dedo4[i] = a[i];
	//	}
	//}
	//void set_colorDedo5(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_dedo5.size(); i++) {
	//		color_dedo5[i] = a[i];
	//	}
	//}
	//void set_colorDedo6(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_dedo6.size(); i++) {
	//		color_dedo6[i] = a[i];
	//	}
	//}
	//void set_colorPiernaIzq(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_piernaIzq.size(); i++) {
	//		color_piernaIzq[i] = a[i];
	//	}
	//}
	//void set_colorPiernaInfIzq(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_piernaInfIzq.size(); i++) {
	//		color_piernaInfIzq[i] = a[i];
	//	}
	//}
	//void set_colorPieIzq(std::vector<GLfloat> a) {
	//	for (int i = 0; i < color_pieIzq.size(); i++) {
	//		color_pieIzq[i] = a[i];
	//	}
	//}


};

