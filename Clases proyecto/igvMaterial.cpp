#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {


// establecer como color de emisión (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)

	GLfloat amb[] = { Ka.cloneToFloatArray()[0], Ka.cloneToFloatArray()[1], Ka.cloneToFloatArray()[2] };
	GLfloat dif[] = { Kd.cloneToFloatArray()[0], Kd.cloneToFloatArray()[1], Kd.cloneToFloatArray()[2] };
	GLfloat esp[] = { Ks.cloneToFloatArray()[0], Ks.cloneToFloatArray()[1], Ks.cloneToFloatArray()[2] };
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, esp);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, (GLfloat)Ns);
	GLfloat emision[] = {0,0,0};
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,emision);

}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



