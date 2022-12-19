#pragma once
#include "Juego.h"

juego::juego() {
	puntuacion = 0;

	posicionesObjetos(vectoresPos);
	posicionPelotaEspecial();
	numMaxLatas = 21;

	segundos1 = 5;
	segundos2 = 7;
	segundos3 = 9;

	hombroDerecho = true;
}

bool juego::getHombroDerecho() {
	return hombroDerecho;
}

void juego::setHombroDerecho(bool e) {
	hombroDerecho = e;
}

void juego::setSegundos1(int a) {
	segundos1 = a;
}

void juego::setSegundos2(int a) {
	segundos2 = a;
}

void juego::setSegundos3(int a) {
	segundos3 = a;
}

void juego::sumadoSeg1() {
	segundos1 += 1;
}

void juego::sumadoSeg2() {
	segundos2 += 1;
}

void juego::sumadoSeg3() {
	segundos3 += 1;
}

int juego::getSeg1() {
	return segundos1;
}

int juego::getSeg2() {
	return segundos2;
}

int juego::getSeg3() {
	return segundos3;
}

void juego::setPosicionesOcupadas(int i, bool ocupada) {
	posicionesVectorOcupadas[i] = ocupada;
}

bool juego::estaLaPosicionOcupada(int i) {
	return posicionesVectorOcupadas[i];
}

void juego::liberarPosicion(std::vector<hitbox*> &hitboxes, const int &i) {
	std::cout << "El valor de i: " << i << "  El tamaño: " << hitboxes.size() << std::endl;  //se busca la posición de la hitbox del indice en el vector de posiciones ocupadas para marcarlo como false
	for (int x = 0; x < vectoresPos.size(); x++) {
		if (hitboxes[i]->posicion == vectoresPos[x]) {
			posicionesVectorOcupadas[x] = false;
		}
	}
}

void juego::inicializarLata(std::vector<hitbox*>& hitboxes, const int& i) {
	srand(time(NULL));
	int tiempoRef;
	int aux = i;
	for (int i = 0; i < aux; i++) {
		int numero = rand() % vectoresPos.size();
		int valor = rand() % 11;
		if (posicionesVectorOcupadas[numero]) {
			aux++;
		}
		else {
			if (valor == 6 || valor == 2) {
				valor = 150;
				tiempoRef = 7 + rand() % (15 - 7);
			}
			else if (valor == 3 || valor == 1 || valor == 7) {
				valor = 100;
				tiempoRef = 20 + rand() % (35 - 20);
			}
			else { 
				valor = 50;
				tiempoRef = 25 + rand() % (45 - 25);
			}
			posicionesVectorOcupadas[numero] = true;
			numLatas++;
			hitboxes.push_back(new hitbox(vectoresPos[numero], igvPunto3D(0.2, 0.2, 0.2), valor, tiempoRef));
		}
	}
}

void juego::reiniciarPosicionesOcupadas() {
	for (int i = 0; i < 49; i++) {
		posicionesVectorOcupadas[i] = false;
	}
}

void juego::actualizarRecord() { 
	if (punt_maxima < puntuacion) {
		punt_maxima = puntuacion;
	}
	puntuacion = 0;
}

void juego::posicionesObjetos(std::vector<igvPunto3D>& vector) {
	/*igvPunto3D aux1(-2.1, 0.9, -6.3);
	igvPunto3D aux2(-1.6, 0.9, -6.3);
	igvPunto3D aux3(-1, 0.9, -6.3);
	igvPunto3D aux4(-0.5, 0.9, -6.3);
	igvPunto3D aux5(0, 0.9, -6.3);
	igvPunto3D aux16(0.5, 0.9, -6.3);
	igvPunto3D aux17(1, 0.9, -6.3);
	igvPunto3D aux18(1.5, 0.9, -6.3);
	igvPunto3D aux19(2, 0.9, -6.3);
	igvPunto3D aux20(2.5, 0.9, -6.3);
	igvPunto3D aux6(-2.1, -0.6, -6.3);
	igvPunto3D aux7(-1.6, -0.6, -6.3);
	igvPunto3D aux8(-1, -0.6, -6.3);
	igvPunto3D aux9(-0.5, -0.6, -6.3);
	igvPunto3D aux10(0, -0.6, -6.3);
	igvPunto3D aux11(0.5, -0.6, -6.3);
	igvPunto3D aux12(1, -0.6, -6.3);
	igvPunto3D aux13(1.5, -0.6, -6.3);
	igvPunto3D aux14(2, -0.6, -6.3);
	igvPunto3D aux15(2.5, -0.6, -6.3);
	igvPunto3D aux21(-2.1, 2.3, -6.3);
	igvPunto3D aux22(-1.6, 2.3, -6.3);
	igvPunto3D aux23(-1, 2.3, -6.3);
	igvPunto3D aux24(-0.5, 2.3, -6.3);
	igvPunto3D aux25(0, 2.3, -6.3);
	igvPunto3D aux26(0.5, 2.3, -6.3);
	igvPunto3D aux27(1, 2.3, -6.3);
	igvPunto3D aux28(1.5, 2.3, -6.3);
	igvPunto3D aux29(2, 2.3, -6.3);
	igvPunto3D aux30(2.5, 2.3, -6.3);
	igvPunto3D aux31(5, 1.11, -4);
	igvPunto3D aux32(5, 1.11, -5);
	igvPunto3D aux33(5, 1.11, -2);
	igvPunto3D aux34(5, 1.11, -1);
	igvPunto3D aux35(6.5, 1.11, -2.5);
	igvPunto3D aux36(6.5, 1.11, -3.7);
	igvPunto3D aux37(6.5, 1.11, -4.8);
	igvPunto3D aux38(6.5, 1.11, -5.5);
	igvPunto3D aux39(6.5, 1.11, -6.5);
	igvPunto3D aux40(-5, 1.11, -6.5);
	igvPunto3D aux41(-5, 1.11, -5.5);
	igvPunto3D aux42(-5, 1.11, -4.8);
	igvPunto3D aux43(-5, 1.11, -3.7);
	igvPunto3D aux44(-5, 1.11, -2.5);
	igvPunto3D aux45(-6, 1.11, -3.5);
	igvPunto3D aux46(-6, 1.11, -4.8);
	igvPunto3D aux47(-6, 1.11, -5.5);
	igvPunto3D aux48(-6, 1.11, -6.5);*/

	//igvPunto3D aux1(-3.8, -0.85, -9); //-2.1, 0.9, -6.3
	igvPunto3D aux2(-3, -0.85, -9);
	igvPunto3D aux3(-2.2, -0.85, -9);
	igvPunto3D aux4(-1.4, -0.85, -9);
	igvPunto3D aux5(-0.6, -0.85, -9);
	igvPunto3D aux16(0.2, -0.85, -9);
	igvPunto3D aux17(1, -0.85, -9);
	igvPunto3D aux18(1.8, -0.85, -9);
	igvPunto3D aux19(2.6, -0.85, -9);
	igvPunto3D aux20(3.4, -0.85, -9);
	igvPunto3D aux6(-3, 1.3, -9);
	igvPunto3D aux7(-2.2, 1.3, -9);
	igvPunto3D aux8(-1.4, 1.3, -9);
	igvPunto3D aux9(-0.6, 1.3, -9);
	igvPunto3D aux10(0.2, 1.3, -9);
	igvPunto3D aux11(1, 1.3, -9);
	igvPunto3D aux12(1.8, 1.3, -9);
	igvPunto3D aux13(2.6, 1.3, -9);
	igvPunto3D aux14(3.4, 1.3, -9);
	/*igvPunto3D aux15(-3, 1.8, -9);*/

	/*igvPunto3D aux21(-2.1, 3.45, -9); */
	igvPunto3D aux22(-3, 3.45, -9);
	igvPunto3D aux23(-2.2, 3.45, -9);
	igvPunto3D aux24(-1.4, 3.45, -9);
	igvPunto3D aux25(-0.6, 3.45, -9);
	igvPunto3D aux26(0.2, 3.45, -9);
	igvPunto3D aux27(1, 3.45, -9);
	igvPunto3D aux28(1.8, 3.45, -9);
	igvPunto3D aux29(2.6, 3.45, -9);
	igvPunto3D aux30(3.4, 3.45, -9);

	igvPunto3D aux31(7.3, 0.6, -7);
	igvPunto3D aux32(7.3, 0.6, -5);
	igvPunto3D aux33(7.3, 0.6, -2);
	igvPunto3D aux34(7.3, 0.6, -1);
	igvPunto3D aux35(6, 0.6, -2.5);
	igvPunto3D aux36(6, 0.6, -3.7);
	igvPunto3D aux37(6, 0.6, -4.8);
	igvPunto3D aux38(6, 0.6, -5.5);
	igvPunto3D aux39(6, 0.6, -6.5);
	igvPunto3D aux40(-7.3, 0.6, -4);
	igvPunto3D aux41(-7.3, 0.6, -5);
	igvPunto3D aux42(-7.3, 0.6, -2);
	igvPunto3D aux43(-7.3, 0.6, -1);
	igvPunto3D aux44(-6, 0.6, -2.5);
	igvPunto3D aux45(-6, 0.6, -3.7);
	igvPunto3D aux46(-6, 0.6, -4.8);
	igvPunto3D aux47(-6, 0.6, -5.5);
	igvPunto3D aux48(-6, 0.6, -6.5);

	vector.push_back(aux2);
	vector.push_back(aux3);
	vector.push_back(aux4);
	vector.push_back(aux5);
	vector.push_back(aux6);
	vector.push_back(aux7);
	vector.push_back(aux8);
	vector.push_back(aux9);
	vector.push_back(aux10);
	vector.push_back(aux11);
	vector.push_back(aux12);
	vector.push_back(aux13);
	vector.push_back(aux14);
	/*vector.push_back(aux15);*/
	vector.push_back(aux16);
	vector.push_back(aux17);
	vector.push_back(aux18);
	vector.push_back(aux19);
	vector.push_back(aux20);
	/*vector.push_back(aux21);*/
	vector.push_back(aux22);
	vector.push_back(aux23);
	vector.push_back(aux24);
	vector.push_back(aux25);
	vector.push_back(aux26);
	vector.push_back(aux27);
	vector.push_back(aux28);
	vector.push_back(aux29);
	vector.push_back(aux30);
	vector.push_back(aux31);
	vector.push_back(aux32);
	vector.push_back(aux33);
	vector.push_back(aux34);
	vector.push_back(aux35);
	vector.push_back(aux36);
	vector.push_back(aux37);
	vector.push_back(aux38);
	vector.push_back(aux39);
	vector.push_back(aux40);
	vector.push_back(aux41);
	vector.push_back(aux42);
	vector.push_back(aux43);
	vector.push_back(aux44);
	vector.push_back(aux45);
	vector.push_back(aux46);
	vector.push_back(aux47);
	vector.push_back(aux48);
}

void juego::posicionPelotaEspecial() {
	igvPunto3D aux1(-0.5, 5, -4);
	igvPunto3D aux2(-3.5, 5, -4);
	igvPunto3D aux3(-1, 0.9, -6.3);
	igvPunto3D aux4(3.5, 4, -1);
	igvPunto3D aux5(3.5, 3, -5);
	igvPunto3D aux6(-3.5, 3, -0.5);
	igvPunto3D aux7(-5, 3, -6);
	igvPunto3D aux8(-2, 6, -6);
	igvPunto3D aux9(-5, 5, -6);
	igvPunto3D aux10(-3.5, 3, -4);

	vectoresPosPelotaEspecial.push_back(aux1);
	vectoresPosPelotaEspecial.push_back(aux2);
	vectoresPosPelotaEspecial.push_back(aux3);
	vectoresPosPelotaEspecial.push_back(aux4);
	vectoresPosPelotaEspecial.push_back(aux5);
	vectoresPosPelotaEspecial.push_back(aux6);
	vectoresPosPelotaEspecial.push_back(aux7);
	vectoresPosPelotaEspecial.push_back(aux8);
	vectoresPosPelotaEspecial.push_back(aux9);
	vectoresPosPelotaEspecial.push_back(aux10);
}

igvPunto3D juego::nuevaPosicionPelotaEspecial() {
	int num = rand() % vectoresPosPelotaEspecial.size();
	return vectoresPosPelotaEspecial[num];
}

