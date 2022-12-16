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

	int numMaxLatas; //máximo número de latas en escena
	int numLatas; //número de latas en escena

	int segundos1; //Variable para controlar los segundos que pasan para pintar latas periodicamente en la estanteria
	int segundos2; //Variable para controlar los segundos que pasan para pintar latas periodicamente
	int segundos3;
public:
	juego();

	//aumenta en una unidad el número de latas(variable)
	void añadirLata() {
		numLatas++;
	}

	void reiniciarNumLatas() {
		numLatas = 0;
	}

	//decrementa en unad unidad el número de latas(variable)
	void eliminarLata() {
		numLatas--;
	}

	int getMaxLatas() {
		return numMaxLatas;
	}

	int getNumLatas() {
		return numLatas;
	}

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

	void setSegundos1(int a);
	void setSegundos2(int a);
	void setSegundos3(int a);
	void sumadoSeg1();
	void sumadoSeg2();
	void sumadoSeg3();
	int getSeg1();
	int getSeg2();
	int getSeg3();

	void actualizarRecord();
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
	//Elimina el contenido del vector que almacena todas las posiciones ocupadas en el juego
	void reiniciarPosicionesOcupadas();
};
