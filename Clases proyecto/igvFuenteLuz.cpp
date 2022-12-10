#include "igvFuenteLuz.h"

// Metodos constructores 

igvFuenteLuz::igvFuenteLuz() {
}

igvFuenteLuz::igvFuenteLuz(const unsigned int _idLuz,
													 const igvPunto3D  & _posicion,
													 const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp,
													 const double a0, const double a1, const double a2) {

  idLuz = _idLuz;
														 
	posicion = _posicion;
														 
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;

	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;

	// valores por defecto cuando la luz no es un foco
	direccion_foco = igvPunto3D(0,0,0);
	angulo_foco = 180; // de esta manera la luz se convierte en puntual	
	exponente_foco = 0;

	encendida = true;
}

igvFuenteLuz::igvFuenteLuz(const unsigned int _idLuz,
			                     const igvPunto3D & _posicion, 
			                     const igvColor& cAmb, const igvColor& cDif, const igvColor& cEsp,
								           const double a0, const double a1, const double a2,
													 const igvPunto3D& dir_foco, const double ang_foco, const double exp_foco) {

  idLuz = _idLuz;
														 
	posicion = _posicion;
														 
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;

	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;

	direccion_foco = dir_foco;
	angulo_foco = ang_foco;
	exponente_foco = exp_foco;

	encendida = true;
}

// Metodos publicos ----------------------------------------

igvPunto3D& igvFuenteLuz::getPosicion(void) {
	return posicion;
}

void igvFuenteLuz::setPosicion(igvPunto3D pos) {
	posicion = pos;
}


void igvFuenteLuz::set(const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp) {
	colorAmbiente = cAmb;
	colorDifuso = cDif;
	colorEspecular = cEsp;
}

void igvFuenteLuz::setAmbiental(const igvColor & cAmb) {
	colorAmbiente = cAmb;
}

void igvFuenteLuz::setDifuso(const igvColor & cDif) {
	colorDifuso = cDif;
}

void igvFuenteLuz::setEspecular(const igvColor & cEsp) {
	colorEspecular = cEsp;
}

igvColor & igvFuenteLuz::getAmbiental(void) {
	return colorAmbiente;
}

igvColor & igvFuenteLuz::getDifuso(void) {
	return colorDifuso;
}

igvColor & igvFuenteLuz::getEspecular(void) {
	return colorEspecular;
}

void igvFuenteLuz::setAtenuacion(double a0, double a1, double a2) {
	aten_a0 = a0;
	aten_a1 = a1;
	aten_a2 = a2;
}

void igvFuenteLuz::getAtenuacion(double & a0, double & a1, double & a2) {
	a0 = aten_a0;
	a1 = aten_a1;
	a2 = aten_a2;
}

void igvFuenteLuz::encender(void) {
  encendida = true;
}

void igvFuenteLuz::apagar(void) {
  encendida = false;
}

unsigned int igvFuenteLuz::esta_encendida(void) {
  return encendida;
}

void igvFuenteLuz::aplicar(void) {

// APARTADO A
// si la luz está encendida
//	activar la luz
//	establecer la posición de la luz
//	establecer los colores ambiental, difuso y especular
//	establecer la atenuación radial
//	establecer la atenuación angular y la dirección del foco

// si la luz está apagada
//	desactivar la luz
	if (esta_encendida()) {
		glEnable(idLuz);
		GLfloat aux[] = { posicion.c[0], posicion.c[1], posicion.c[2], 1 };
		glLightfv(idLuz, GL_POSITION, aux);
		glLightfv(idLuz, GL_AMBIENT, colorAmbiente.cloneToFloatArray());
		glLightfv(idLuz, GL_DIFFUSE, colorDifuso.cloneToFloatArray());
		glLightfv(idLuz, GL_SPECULAR, colorEspecular.cloneToFloatArray());
		glLightf(idLuz, GL_CONSTANT_ATTENUATION, (GLfloat)aten_a0);
		glLightf(idLuz, GL_LINEAR_ATTENUATION, (GLfloat)aten_a1);
		glLightf(idLuz, GL_QUADRATIC_ATTENUATION, (GLfloat)aten_a2);
		glLightfv(idLuz, GL_SPOT_DIRECTION, direccion_foco.cloneToFloatArray());
		//glLightf(idLuz, GL_SPOT_DIRECTION, angulo_foco);
		//glLightf(idLuz, GL_SPOT_DIRECTION,exponente_foco);
		glLightf(idLuz, GL_SPOT_CUTOFF, angulo_foco);
		glLightf(idLuz, GL_SPOT_EXPONENT, exponente_foco);
	}
	else {
		glDisable(idLuz);
	}

	

}

