#pragma once
#include "igvPunto3d.h"

class hitbox {

public:
	igvPunto3D posicion, tamano, velocidad;

	hitbox();
	hitbox(igvPunto3D _posicion, igvPunto3D _tamano);

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
};

