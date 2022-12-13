#pragma once
#include "igvPunto3d.h"
#include <vector>
#include <ctime>

class hitbox {

private:
	int valorObjeto;
	std::vector<GLfloat> colorObjeto;
	int tiempoRefresco;

	//temporizador de reciclado de latas
	clock_t t;
	clock_t aux;

public:
	igvPunto3D posicion, tamano, velocidad;

	hitbox();
	hitbox(igvPunto3D _posicion, igvPunto3D _tamano, int valor, int tiempoRefresco);

	float escalarX, escalarY, escalarZ = 0;

	void dibujar();

	void actualizarCoordenadas(float x, float y, float z);

	//modificación atributos y escalado
	void setEscalarX(float scale) {
		this->escalarX = scale;
	}

	void setEscalarY(float scale) {
		this->escalarY = scale;
	}

	void setEscalarZ(float scale) {
		this->escalarZ = scale;
	}

	int getValor() {
		return valorObjeto;
	}

	void setColor(std::vector<GLfloat> color) {
		colorObjeto = color;
	}

	std::vector<GLfloat> getColor() {
		return colorObjeto;
	}

	std::vector<float> getPosicionFloat() {
		std::vector<float> v;
		v.push_back(posicion.c[0]);
		v.push_back(posicion.c[1]);
		v.push_back(posicion.c[2]);
		return v;
	}

	void setPosicion(const std::vector<float> &v) {
		posicion.c[0] = v[0];
		posicion.c[1] = v[1];
		posicion.c[2] = v[2];
	}

	void setPosicion(igvPunto3D p) {
		posicion.c[0] = p.c[0];
		posicion.c[1] = p.c[1];
		posicion.c[2] = p.c[2];
	}

	bool pasadoDeTiempo() {
		aux = clock() - t;
		if ( float(aux) / CLOCKS_PER_SEC > tiempoRefresco) {
			return true;
		}
		else {
			return false;
		}
	}
};

