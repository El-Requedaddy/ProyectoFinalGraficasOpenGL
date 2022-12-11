#pragma once

class juego {

private:
	int puntuacion;
	int punt_maxima;


public:
	juego();
	void sumarPuntuacion(int a) {
		puntuacion += a;
	}
};
