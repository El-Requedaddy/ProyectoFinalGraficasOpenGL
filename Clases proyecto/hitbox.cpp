#include "hitbox.h"

hitbox::hitbox(): 
	posicion(0.0f, 0.0f, 0.0f), tamano(1.0f, 1.0f, 1.0f), velocidad(0.0f, 0.0f, 0.0f)
{}

hitbox::hitbox(igvPunto3D _posicion, igvPunto3D _tamano) :
	posicion(_posicion), tamano(_tamano) {}

void hitbox::dibujar() {
	
	//glTranslated(escalarX, escalarY, escalarZ);
	glutSolidCube(1);

}

void hitbox::actualizarCoordenadas(float x, float y, float z) {
	posicion.c[X] = x;
	posicion.c[Y] = y;
	posicion.c[Z] = z;
}
