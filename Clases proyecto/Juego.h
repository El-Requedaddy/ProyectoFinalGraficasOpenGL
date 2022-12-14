#pragma once
#include <ctime>
#include "igvPunto3D.h"
#include "hitbox.h"
#include <iostream>

class juego {

private:
	int puntuacion;
	int punt_maxima;
	clock_t t;
	clock_t aux;

	std::vector<igvPunto3D> vectoresPos;
	std::vector<igvPunto3D> vectoresPosPelotaEspecial;
	bool posicionesVectorOcupadas[49]; //posiciones ocupadas, a partir del indice 30 las posiciones son de las latas || Tamaño real es 48

	int numMaxLatas;
	int numLatas;
public:
	juego();
	void sumarPuntuacion(int a) {
		puntuacion += a;
	}

	float getTiempoTranscurrido() {
		aux = clock() - t;
		return float(aux) / CLOCKS_PER_SEC;
	}

	void iniciarReloj() {
		t = clock();
		aux = clock();
	}

	void setPosicionesOcupadas(int i, bool ocupada);
	bool estaLaPosicionOcupada(int i);
	void liberarPosicion(std::vector<hitbox*>& hitboxes, const int& i);
	//Inicializa la cantidad de latas deseadas insertandolas en el vector de hitboxes
	void inicializarLata(std::vector<hitbox*> &hitboxes, const int &i);
	//Se rellena un vector de PUNTOS 3D con todas las posiciones posibles de las latas
	void posicionesObjetos(std::vector<igvPunto3D>& vector);
	//Se inicializan las posibles posiciones de la pelota especial
	void posicionPelotaEspecial();
	//Genera nueva posición de la pelota especial
	igvPunto3D nuevaPosicionPelotaEspecial();
};
