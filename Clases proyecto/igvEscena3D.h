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
#include "hitbox.h"
#include "igvPunto3D.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "Juego.h"


class igvEscena3D {
protected:
	////// Apartado C: añadir quí los atributos para el control de los grados de libertad del modelo
	float rotacionModeloCompleto;
	float rotacion_cabezaY;
	float rotacion_cabezaX;
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
	float rotacion_dedo4;
	float rotacion_dedo5;
	float rotacion_dedo6;
	float rotacion_pierna_sup;
	float rotacion_pierna_inf;
	float rotacion_pie;
	float rotacion_pierna_sup_izq;
	float rotacion_pierna_inf_izq;
	float rotacion_pie_izq;

	std::vector<GLfloat> color_grisOscuro;
	std::vector<GLfloat> color_rojo;
	std::vector<GLfloat> color_verdeAzul;
	std::vector<GLfloat> color_azul;
	std::vector<GLfloat> color_marron;
	std::vector<GLfloat> color_naranja;

	int pos_r, pos_a, pos_v, pos_g;
	// Otros atributos		
	bool ejes;
	Modelos* modelos;
	bool modo_act;//indicador de si estamos en modo selección
	std::vector<GLfloat> colores; //Array de los diferentes colores

	//Atributos proyecto final!!!
	float trasX = 1.5;
	float trasY = -2.7;
	float trasZ = 0.1;

	float rotX, rotY, rotZ = 0;

	float trasXrobot = 0;
	float trasYrobot = 0;
	float trasZrobot = 2;

	bool animacionPelota = true;
	bool lanzarPelota = false;

	//vector de hitboxes
	std::vector<hitbox*> hitboxes;
	juego juego;

	//atributos de la trayectoria de la pelota
	float a;
	float movementSpeed = 0.01;
	float deltaTime = 0.1;
	igvPunto3D posicionPelota;
	igvPunto3D coordenadaInicial; //final 
	igvPunto3D coordenadaFinal;  //inicial

public:

	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// método con las llamadas OpenGL para visualizar la escena
	void visualizar(void);
	void visualizar2(void);
	void visualizarVB(void);//Método para la visualización en modo selección


	//----------------------------------Métodos para la visualización de las diferentes partes de la escena-----------------------------
	void pintar_robot();
	void pintar_robotVB();
	void pintar_todo();
	
	//-------------------------------------MÉTODOS PARA INTERACTUAR CON LOS COLORES-------------------------

	//inserta en el vector de destino valores del vector color(inserta 'tam' valores a partir de la posición 'pos')
	void cambia_color(std::vector<GLfloat> color, std::vector<GLfloat>& destino, int& pos, int tam) {
			for (int i = 0; i < tam; i++) {
				destino[i] = color[pos];
				pos += 1;
			}
		}
	//Método que reinicia los vectores de colores a su color original
	void reinicio_colores() {
		color_verdeAzul[0] = 0.0;
		color_verdeAzul[1] = 0.5;
		color_verdeAzul[2] = 0.5;

		color_grisOscuro[0] = 0.1;
		color_grisOscuro[1] = 0.1;
		color_grisOscuro[2] = 0.1;

		color_azul[0] = 0.0;
		color_azul[1] = 0.0;
		color_azul[2] = 1.0;

		color_rojo[0] = 1.0;
		color_rojo[1] = 0.0;
		color_rojo[2] = 0.0;
	}


	void set_modo(bool a) {
		modo_act = a;
	}
	bool get_modo() {
		return modo_act;
	}

	std::vector<GLfloat> get_colores() {
		return colores;
	}

	std::vector<GLfloat> get_color_naranja() {
		return color_naranja;
	}

	std::vector<GLfloat> get_color_gris() {
		return color_grisOscuro;
	}

	std::vector<GLfloat> get_color_azul() {
		return color_azul;
	}

	Modelos* getModelos() {
		return modelos;
	}


	//------------------------MÉTODOS PARA GESTIONAR LOS GRADOS DE LIBERTAD DEL GRAFO DE ESCENA-----------------------------
	
	void setRotacion(float a) {
		rotacionModeloCompleto += a;
	}

	float getRotacion() {
		return rotacionModeloCompleto;
	}

	void setRotacion_cabezaY(float a,bool sum) {
		if (sum && (rotacion_cabezaY + a <= 30 && rotacion_cabezaY + a >= -30)) {
			rotacion_cabezaY += a;
		}
		if(!sum) {
			rotacion_cabezaY = a;
		}	
	}

	float getRotacion_cabezaY() {
		return rotacion_cabezaY;
	}

	float getRotacion_cabezaX() {
		return rotacion_cabezaX;
	}

	void setRotacion_cabezaX(float a) {
			rotacion_cabezaX = a;
	}

	//----Rotaciones de Brazo derecho-----

	void setRotacion_brazo_sup(float a, bool sum) {
		if (sum && (rotacion_brazo_sup + a <= 180 && rotacion_brazo_sup + a >= 0)) {
				rotacion_brazo_sup += a;
		}
		if (!sum) {
			rotacion_brazo_sup = a ;
		}
		
	}

	float getRotacion_brazo_sup() {
		return rotacion_brazo_sup;
	}

	void setRotacion2_brazo_sup(float a, bool sum) {
		if (sum) {
			rotacion2_brazo_sup += a;
		}
		if (!sum) {
			rotacion2_brazo_sup = a;
		}
	}

	float getRotacion2_brazo_sup() {
		return rotacion2_brazo_sup;
	}

	void setRotacion_brazo_inf(float a, bool sum) {
		if (sum && (rotacion_brazo_inf + a <= 90 && rotacion_brazo_inf + a >= -90)) {
			rotacion_brazo_inf += a;
		}
		if (!sum) {
			rotacion_brazo_inf = a;
		}
	}

	float getRotacion_brazo_inf() {
		return rotacion_brazo_inf;
	}

	float getRotacionMuneca() {
		return rotacion_muneca;
	}

	void setRotacionMuneca(float a, bool sum) {
		if (sum && (rotacion_muneca + a <= 90 && rotacion_muneca + a >= -90)) {
			rotacion_muneca += a;
		}
		if (!sum) {
			rotacion_muneca = a;
		}
	}

	float getRotaciondedo1() {
		return rotacion_dedo1;
	}

	void setRotaciondedo1(float a, bool sum) {
		if (sum && (rotacion_dedo1 + a <= 50 && rotacion_dedo1 + a >= -30)) {
			rotacion_dedo1 += a;
		}
		if (!sum) {
			rotacion_dedo1 = a;
		}
	}

	float getRotaciondedo2() {
		return rotacion_dedo2;
	}

	void setRotaciondedo2(float a, bool sum) {
		if (sum && (rotacion_dedo2 + a <= 30 && rotacion_dedo2 + a >= -50)) {
			rotacion_dedo2 += a;
		}
		if (!sum) {
			rotacion_dedo2 = a;
		}
	}

	float getRotaciondedo3() {
		return rotacion_dedo3;
	}

	void setRotaciondedo3(float a, bool sum) {
		if (sum && (rotacion_dedo3 + a <= 50 && rotacion_dedo3 + a >= -20)) {
			rotacion_dedo3 += a;
		}
		if (!sum) {
			rotacion_dedo3 = a;
		}
	}

	//-----------------------------------Rotaciones del brazo derecho

	void setRotacion_brazo_sup_izq(float a, bool sum) {
		if (sum && (rotacion_brazo_sup_izq + a <= 180 && rotacion_brazo_sup_izq + a >= 0)) {
			rotacion_brazo_sup_izq += a;
		}
		if (!sum) {
			rotacion_brazo_sup_izq = a;
		}
	}

	float getRotacion_brazo_sup_izq() {
		return rotacion_brazo_sup_izq;
	}

	void setRotacion_brazo_inf_izq(float a, bool sum) {
		if (sum && (rotacion_brazo_inf_izq + a <= 90 && rotacion_brazo_inf_izq + a >= -90)) {
			rotacion_brazo_inf_izq += a;
		}
		if (!sum) {
			rotacion_brazo_inf_izq = a;
		}
	}

	float getRotacion_brazo_inf_izq() {
		return rotacion_brazo_inf_izq;
	}

	float getRotacionMunecaIzq() {
		return rotacion_muneca_izq;
	}

	void setRotacionMunecaIzq(float a, bool sum) {
		if (sum && (rotacion_muneca_izq + a <= 90 && rotacion_muneca_izq + a >= -90)) {
			rotacion_muneca_izq += a;
		}
		if (!sum) {
			rotacion_muneca_izq = a;
		}
	}

	float getRotaciondedo4() {
		return rotacion_dedo4;
	}

	void setRotaciondedo4(float a, bool sum) {
		if (sum && (rotacion_dedo4 + a <= 30 && rotacion_dedo4 + a >= -70)) {
			rotacion_dedo4 += a;
		}
		if (!sum) {
			rotacion_dedo4 = a;
		}
	}

	float getRotaciondedo5() {
		return rotacion_dedo5;
	}

	void setRotaciondedo5(float a, bool sum) {
		if (sum && (rotacion_dedo5 + a <= 70 && rotacion_dedo5 + a >= -30)) {
			rotacion_dedo5 += a;
		}
		if (!sum) {
			rotacion_dedo5 = a;
		}
	}

	float getRotaciondedo6() {
		return rotacion_dedo6;
	}

	void setRotaciondedo6(float a, bool sum) {
		if (sum && (rotacion_dedo6 + a <= 20 && rotacion_dedo6 + a >= -70)) {
			rotacion_dedo6 += a;
		}
		if (!sum) {
			rotacion_dedo6 = a;
		}
	}

	//----------------------Rotaciones pierna derecha

	float getRotacionpierna_sup() {
		return rotacion_pierna_sup;
	}

	void setRotacionpierna_sup(float a, bool sum) {
		if (sum && (rotacion_pierna_sup + a <= 70 && rotacion_pierna_sup + a >= -70)) {
			rotacion_pierna_sup += a;
		}
		if (!sum) {
			rotacion_pierna_sup = a;
		}
	}

	float getRotacionpierna_inf() {
		return rotacion_pierna_inf;
	}

	void setRotacionpierna_inf(float a, bool sum) {
		if (sum && (rotacion_pierna_inf + a <= 80 && rotacion_pierna_inf + a >= 0)) {
			rotacion_pierna_inf += a;
		}
		if (!sum) {
			rotacion_pierna_inf = a;
		}
	}

	float getRotacionpie() {
		return rotacion_pie;
	}

	void setRotacionpie(float a, bool sum) {
		if (sum && (rotacion_pie + a <= 40 && rotacion_pie + a >= -40)) {
			rotacion_pie += a;
		}
		if (!sum) {
			rotacion_pie = a;
		}
	}

	//------PIERNA IZQ

	float getRotacionpierna_sup_izq() {
		return rotacion_pierna_sup_izq;
	}

	void setRotacionpierna_sup_izq(float a, bool sum) {
		if (sum && (rotacion_pierna_sup_izq + a <= 70 && rotacion_pierna_sup_izq + a >= -70)) {
			rotacion_pierna_sup_izq += a;
		}
		if (!sum) {
			rotacion_pierna_sup_izq = a;
		}
	}

	float getRotacionpierna_inf_izq() {
		return rotacion_pierna_inf_izq;
	}

	void setRotacionpierna_inf_izq(float a, bool sum) {
		if (sum && (rotacion_pierna_inf_izq + a <= 80 && rotacion_pierna_inf_izq + a >= 0)) {
			rotacion_pierna_inf_izq += a;
		}
		if (!sum) {
			rotacion_pierna_inf_izq = a;
		}
	}

	float getRotacionpie_izq() {
		return rotacion_pie_izq;
	}

	void setRotacionpie_izq(float a, bool sum) {
		if (sum && (rotacion_pie_izq + a <= 40 && rotacion_pie_izq + a >= -40)) {
			rotacion_pie_izq += a;
		}
		if (!sum) {
			rotacion_pie_izq = a;
		}
	}

	
	bool get_ejes() { return ejes; };
	void set_ejes(bool _ejes) { ejes = _ejes; };


	//métodos movimiento robot
	void setxRobot(float a) {
		trasXrobot += a;
	};

	void setyRobot(float a) {
		trasYrobot += a;
	};

	float getRobotX() {
		return trasXrobot;
	};

	float getRobotY() {
		return trasYrobot;
	};

	float getRobotZ() {
		return trasZrobot;
	};

	void setxTras(float a) {
		trasX += a;
	};

	void setyTras(float a) {
		trasY += a;
	};

	void setzTras(float a) {
		trasZ += a;
	};

	void setxRot(float a) {
		rotX += a;
	};

	void setyRot(float a) {
		rotY += a;
	};

	void setzRot(float a) {
		rotZ += a;
	};

	void setPelota(bool animado) {
		animacionPelota = animado;
	}

	bool getPelota() {
		return animacionPelota;
	}

	igvPunto3D getPosicionPelota() {
		return posicionPelota;
	}

	//métodos relacionados con el lanzamiento de la pelota, están explicados en su inplementación en cpp correspondiente
	std::vector<hitbox*>& getHitboxes() { return hitboxes; }
	int buscarHitbox(float x, float y, float z);
	void calculoTrayectoriaPelota(hitbox h1, hitbox h2);
	void activarLanzamientoPelota() { lanzarPelota = true; }
	void desactivarLanzamientoPelota() { lanzarPelota = false; }
	bool getLanzandoPelota() { return lanzarPelota; }

	//comprobamos colision entre dos objetos, esto se hace llevandolo a un supuesto plano 2d
	bool detectarColisiones(hitbox h1, hitbox h2) {
		bool colisionX = h1.posicion.c[0] + h1.tamano.c[0] >= h2.posicion.c[0] && h2.posicion.c[0] + h2.tamano.c[0] >= h1.posicion.c[0];
		bool colisionY = h1.posicion.c[2] + h1.tamano.c[2] >= h2.posicion.c[2] && h2.posicion.c[2] + h2.tamano.c[2] >= h1.posicion.c[2];

		return colisionX && colisionY;
	}
	void actualizarCoordenadasPelota(igvPunto3D final, igvPunto3D inicial);
	void posicionesObjetos(std::vector<igvPunto3D> &vector);
};

#endif
