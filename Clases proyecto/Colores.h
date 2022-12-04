#pragma once
#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#include <vector>
#endif
#include <vector>
class Colores
{
private:

	std::vector<GLfloat> color_base_cabeza;
	std::vector<GLfloat> color_brazo_sup;
	std::vector<GLfloat> color_brazo_inf;
	std::vector<GLfloat> color_mano;
	std::vector<GLfloat> color_dedo1;
	std::vector<GLfloat> color_dedo2;
	std::vector<GLfloat> color_dedo3;
	std::vector<GLfloat> color_pierna;
	std::vector<GLfloat> color_piernaInf;
	std::vector<GLfloat> color_pie;
	//Colores lado izq
	std::vector<GLfloat> color_brazo_supIzq;
	std::vector<GLfloat> color_brazo_infIzq;
	std::vector<GLfloat> color_manoIzq;
	std::vector<GLfloat> color_dedo4;
	std::vector<GLfloat> color_dedo5;
	std::vector<GLfloat> color_dedo6;
	std::vector<GLfloat> color_piernaIzq;
	std::vector<GLfloat> color_piernaInfIzq;
	std::vector<GLfloat> color_pieIzq;

public:

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
	void set_colorDedo1(std::vector<GLfloat> a) {
		for (int i = 0; i < color_dedo1.size(); i++) {
			color_dedo1[i] = a[i];
		}
	}
	void set_colorDedo2(std::vector<GLfloat> a) {
		for (int i = 0; i < color_dedo2.size(); i++) {
			color_dedo2[i] = a[i];
		}
	}
	void set_colorDedo3(std::vector<GLfloat> a) {
		for (int i = 0; i < color_dedo3.size(); i++) {
			color_dedo3[i] = a[i];
		}
	}
	void set_colorPierna(std::vector<GLfloat> a) {
		for (int i = 0; i < color_pierna.size(); i++) {
			color_pierna[i] = a[i];
		}
	}
	void set_colorPiernaInf(std::vector<GLfloat> a) {
		for (int i = 0; i < color_piernaInf.size(); i++) {
			color_piernaInf[i] = a[i];
		}
	}
	void set_colorPie(std::vector<GLfloat> a) {
		for (int i = 0; i < color_pie.size(); i++) {
			color_pie[i] = a[i];
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
	void set_colorDedo4(std::vector<GLfloat> a) {
		for (int i = 0; i < color_dedo4.size(); i++) {
			color_dedo4[i] = a[i];
		}
	}
	void set_colorDedo5(std::vector<GLfloat> a) {
		for (int i = 0; i < color_dedo5.size(); i++) {
			color_dedo5[i] = a[i];
		}
	}
	void set_colorDedo6(std::vector<GLfloat> a) {
		for (int i = 0; i < color_dedo6.size(); i++) {
			color_dedo6[i] = a[i];
		}
	}
	void set_colorPiernaIzq(std::vector<GLfloat> a) {
		for (int i = 0; i < color_piernaIzq.size(); i++) {
			color_piernaIzq[i] = a[i];
		}
	}
	void set_colorPiernaInfIzq(std::vector<GLfloat> a) {
		for (int i = 0; i < color_piernaInfIzq.size(); i++) {
			color_piernaInfIzq[i] = a[i];
		}
	}
	void set_colorPieIzq(std::vector<GLfloat> a) {
		for (int i = 0; i < color_pieIzq.size(); i++) {
			color_pieIzq[i] = a[i];
		}
	}


	std::vector<GLfloat> GetColor_pieIzq() const {
		return color_pieIzq;
	}

	std::vector<GLfloat> GetColor_piernaInfIzq() const {
		return color_piernaInfIzq;
	}

	std::vector<GLfloat> GetColor_piernaIzq() const {
		return color_piernaIzq;
	}

	std::vector<GLfloat> GetColor_dedo6() const {
		return color_dedo6;
	}

	std::vector<GLfloat> GetColor_dedo5() const {
		return color_dedo5;
	}

	std::vector<GLfloat> GetColor_dedo4() const {
		return color_dedo4;
	}

	std::vector<GLfloat> GetColor_manoIzq() const {
		return color_manoIzq;
	}

	std::vector<GLfloat> GetColor_brazo_infIzq() const {
		return color_brazo_infIzq;
	}

	std::vector<GLfloat> GetColor_brazo_supIzq() const {
		return color_brazo_supIzq;
	}

	std::vector<GLfloat> GetColor_pie() const {
		return color_pie;
	}

	std::vector<GLfloat> GetColor_piernaInf() const {
		return color_piernaInf;
	}

	std::vector<GLfloat> GetColor_pierna() const {
		return color_pierna;
	}

	std::vector<GLfloat> GetColor_dedo3() const {
		return color_dedo3;
	}

	std::vector<GLfloat> GetColor_dedo2() const {
		return color_dedo2;
	}

	std::vector<GLfloat> GetColor_dedo1() const {
		return color_dedo1;
	}

	std::vector<GLfloat> GetColor_mano() const {
		return color_mano;
	}

	std::vector<GLfloat> GetColor_brazo_inf() const {
		return color_brazo_inf;
	}

	std::vector<GLfloat> GetColor_brazo_sup() const {
		return color_brazo_sup;
	}

	std::vector<GLfloat> GetColor_base_cabeza() const {
		return color_base_cabeza;
	}
};

