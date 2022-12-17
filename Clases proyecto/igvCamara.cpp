
#include <math.h>
#include <stdio.h>

#include "igvCamara.h"

// Metodos constructores

igvCamara::igvCamara() {}

igvCamara::~igvCamara() {}

void igvCamara::setTipoCamara(tipoCamara camara) {
	tipo = camara;
}

igvCamara::igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;

	tipo = _tipo;
}


// Metodos publicos 
void igvCamara::set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;
}
void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
	double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar) {
	tipo = _tipo;

	P0 = _P0;
	r = _r;
	V = _V;

	xwmin = _xwmin;
	xwmax = _xwmax;
	ywmin = _ywmin;
	ywmax = _ywmax;
	znear = _znear;
	zfar = _zfar;
}

void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
	double _angulo, double _raspecto, double _znear, double _zfar) {
	tipo = _tipo;

	P0 = _P0;
	r = _r;
	V = _V;

	angulo = _angulo;
	raspecto = _raspecto;
	znear = _znear;
	zfar = _zfar;
}

void igvCamara::aplicar(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (tipo == IGV_PARALELA) {
		glOrtho(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (tipo == IGV_FRUSTUM) {
		glFrustum(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (tipo == IGV_PERSPECTIVA) {
		gluPerspective(angulo, raspecto, znear, zfar);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(P0[X], P0[Y], P0[Z], r[X], r[Y], r[Z], V[X], V[Y], V[Z]);
}

void igvCamara::zoom() {
		xwmin = xwmin + 0.05;
		xwmax = xwmax - 0.05;
		ywmin = ywmin + 0.05;
		ywmax = ywmax - 0.05;
		angulo = angulo - 0.5;
}

void igvCamara::zoomOut() {
		xwmin = xwmin - 0.05;
		xwmax = xwmax + 0.05;
		ywmin = ywmin - 0.05;
		ywmax = ywmax + 0.05;
		angulo = angulo + 0.5;
}

void igvCamara::sumarZnear() {
	znear = znear + 0.2;
}

void igvCamara::restarZnear() {
	znear = znear - 0.2;
}

void igvCamara::maszP0(float a) {
	P0.c[2] += a;
}

void igvCamara::menoszP0(float a) {
	P0.c[2] += a;
}

void igvCamara::masyP0(float a) {
	P0.c[1] += a;
}

void igvCamara::menosyP0(float a) {
	P0.c[1] += a;
}

void igvCamara::masxP0(float a) {
	P0.c[0] += a;
}

void igvCamara::menosxP0(float a) {
	P0.c[0] += a;
}

void igvCamara::panoramica(float a) {
	r.c[0] += a;
}

void igvCamara::cabeceo(float a) {
	r.c[1] += a;
}
