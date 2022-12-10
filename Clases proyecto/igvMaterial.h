#ifndef __IGVMATERIAL
#define __IGVMATERIAL

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvColor.h"

class igvMaterial {

	protected:
		// atributos
		igvColor Ka; // coeficiente reflexión luz ambiental
		igvColor Kd; // coeficiente reflexión difuso
		igvColor Ks; // coeficiente reflexión especular
		double   Ns; // exponente de Phong

		// Metodos

	public:
		// Constructores por defecto y destructor
		igvMaterial();
		~igvMaterial();

		// Otros constructores
		igvMaterial(const igvMaterial& p);	//de copia
		igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns);

		// Metodos
		void aplicar(void);

		void set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns);
};

#endif

