#pragma once
#include <ctime>

class juego {

private:
	int puntuacion;
	int punt_maxima;
	clock_t t;
	clock_t aux;

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
};
