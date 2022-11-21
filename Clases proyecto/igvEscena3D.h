#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif
#include "Modelos.h"


enum {
	basex,
	cuerpoinferior,
	cuerposuperior,
	brazo
};

class igvEscena3D {
protected:
	////// Apartado C: añadir quí los atributos para el control de los grados de libertad del modelo
	float rotacionModeloCompleto;
	float rotacion_cabeza;
	float rotacion_brazo_sup;
	float rotacion2_brazo_sup;
	float rotacion_brazo_inf;
	float rotacion_muneca;
	float rotacion_dedo1;
	float rotacion_dedo2;
	float rotacion_dedo3;
	float rotacion_brazo_sup_izq;
	float rotacion_brazo_inf_izq;
	float rotacion_muneca_izq;
	float rotacion_dedo1_izq;
	float rotacion_dedo2_izq;
	float rotacion_dedo3_izq;
	float rotacion_pierna_sup;
	float rotacion_pierna_inf;
	float rotacion_pie;
	float rotacion_pierna_sup_izq;
	float rotacion_pierna_inf_izq;
	float rotacion_pie_izq;


	// Otros atributos		
	bool ejes;
	Modelos* modelos;

public:

	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// método con las llamadas OpenGL para visualizar la escena
	void visualizar(void);

	///// Apartado B: Métodos para visualizar cada parte del modelo
	//Se realiza en la clase Modelos

	////// Apartado C: añadir aquí los métodos para modificar los grados de libertad del modelo
	void setRotacion(float a) {
		rotacionModeloCompleto += a;
	}

	float getRotacion() {
		return rotacionModeloCompleto;
	}

	void setRotacion_cabeza(float a) {
		if(rotacion_cabeza + a <= 30 && rotacion_cabeza +a >= -30 ) rotacion_cabeza += a;
	}

	float getRotacion_cabeza() {
		return rotacion_cabeza;
	}

	void setRotacion3_brazo_sup(float a) {
		if(rotacion_brazo_sup + a <= 180 && rotacion_brazo_sup + a >= 0 ) rotacion_brazo_sup += a ;
	}

	float getRotacion_brazo_sup() {
		return rotacion_brazo_sup;
	}

	void setRotacion2_brazo_sup(float a) {
		//if (rotacion2_brazo_sup + a <= 90 && rotacion2_brazo_sup + a >= -90) 
		rotacion2_brazo_sup += a;
	}

	float getRotacion2_brazo_sup() {
		return rotacion2_brazo_sup;
	}

	void setRotacion_brazo_inf(float a) {
		if(rotacion_brazo_inf + a <= 90 && rotacion_brazo_inf + a >= -90)rotacion_brazo_inf += a;
	}

	float getRotacion_brazo_inf() {
		return rotacion_brazo_inf;
	}

	float getRotacionMuneca() {
		return rotacion_muneca;
	}

	void setRotacionMuneca(float a) {
		if (rotacion_muneca + a <= 90 && rotacion_muneca + a >= -90) rotacion_muneca += a;
	}

	float getRotaciondedo1() {
		return rotacion_dedo1;
	}

	void setRotaciondedo1(float a) {
		if (rotacion_dedo1 + a <= 50 && rotacion_dedo1 + a >= -30) rotacion_dedo1 += a;
	}

	float getRotaciondedo2() {
		return rotacion_dedo2;
	}

	void setRotaciondedo2(float a) {
		if (rotacion_dedo2 + a <= 30 && rotacion_dedo2 + a >= -50) rotacion_dedo2 += a;
	}

	float getRotaciondedo3() {
		return rotacion_dedo3;
	}

	void setRotaciondedo3(float a) {
		if (rotacion_dedo3 + a <= 50 && rotacion_dedo3 + a >= -20) rotacion_dedo3 += a;
	}

	//------------------------------------------------LADO IZQUIERDO DE MANO

	void setRotacion_brazo_sup_izq(float a) {
		if (rotacion_brazo_sup_izq + a <= 180 && rotacion_brazo_sup_izq + a >= 0) rotacion_brazo_sup_izq += a;
	}

	float getRotacion_brazo_sup_izq() {
		return rotacion_brazo_sup_izq;
	}

	void setRotacion_brazo_inf_izq(float a) {
		if (rotacion_brazo_inf_izq + a <= 90 && rotacion_brazo_inf_izq + a >= -90)rotacion_brazo_inf_izq += a;
	}

	float getRotacion_brazo_inf_izq() {
		return rotacion_brazo_inf_izq;
	}

	float getRotacionMunecaIzq() {
		return rotacion_muneca_izq;
	}

	void setRotacionMunecaIzq(float a) {
		if (rotacion_muneca_izq + a <= 90 && rotacion_muneca_izq + a >= -90) rotacion_muneca_izq += a;
	}

	float getRotaciondedo1_izq() {
		return rotacion_dedo1_izq;
	}

	void setRotaciondedo1_izq(float a) {
		if (rotacion_dedo1_izq + a <= 30 && rotacion_dedo1_izq + a >= -70) rotacion_dedo1_izq += a;
	}

	float getRotaciondedo2_izq() {
		return rotacion_dedo2_izq;
	}

	void setRotaciondedo2_izq(float a) {
		if (rotacion_dedo2_izq + a <= 70 && rotacion_dedo2_izq + a >= -30) rotacion_dedo2_izq += a;
	}

	float getRotaciondedo3_izq() {
		return rotacion_dedo3_izq;
	}

	void setRotaciondedo3_izq(float a) {
		if (rotacion_dedo3_izq + a <= 20 && rotacion_dedo3_izq + a >= -70) rotacion_dedo3_izq += a;
	}

	//----------------------PIERNAS

	float getRotacionpierna_sup() {
		return rotacion_pierna_sup;
	}

	void setRotacionpierna_sup(float a) {
		if (rotacion_pierna_sup + a <= 70 && rotacion_pierna_sup + a >= -70) rotacion_pierna_sup += a;
	}

	float getRotacionpierna_inf() {
		return rotacion_pierna_inf;
	}

	void setRotacionpierna_inf(float a) {
		if (rotacion_pierna_inf + a <= 80 && rotacion_pierna_inf + a >= 0) rotacion_pierna_inf += a;
	}

	float getRotacionpie() {
		return rotacion_pie;
	}

	void setRotacionpie(float a) {
		if (rotacion_pie + a <= 40 && rotacion_pie + a >= -40) rotacion_pie += a;
	}

	//------PIERNA IZQ

	float getRotacionpierna_sup_izq() {
		return rotacion_pierna_sup_izq;
	}

	void setRotacionpierna_sup_izq(float a) {
		if (rotacion_pierna_sup_izq + a <= 70 && rotacion_pierna_sup_izq + a >= -70) rotacion_pierna_sup_izq += a;
	}

	float getRotacionpierna_inf_izq() {
		return rotacion_pierna_inf_izq;
	}

	void setRotacionpierna_inf_izq(float a) {
		if (rotacion_pierna_inf_izq + a <= 80 && rotacion_pierna_inf_izq + a >= 0) rotacion_pierna_inf_izq += a;
	}

	float getRotacionpie_izq() {
		return rotacion_pie_izq;
	}

	void setRotacionpie_izq(float a) {
		if (rotacion_pie_izq + a <= 40 && rotacion_pie_izq + a >= -40) rotacion_pie_izq += a;
	}

	Modelos* getModelos() {
		return modelos;
	}
	bool get_ejes() { return ejes; };
	void set_ejes(bool _ejes) { ejes = _ejes; };

	void pintar_robot();

	

};

#endif
