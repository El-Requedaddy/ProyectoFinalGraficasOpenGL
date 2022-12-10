#ifndef __IGVFUENTELUZ
#define __IGVFUENTELUZ

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvPunto3D.h"
#include "igvColor.h"

class igvFuenteLuz {

	protected:
		// Atributos
		unsigned int idLuz; // identificador de la luz (GL_LIGHT0 a GL_LIGHT7)

    igvPunto3D posicion; // posición de la luz

		igvColor colorAmbiente; // color ambiental de la luz
		igvColor colorDifuso; // color difuso de la luz
		igvColor colorEspecular; // color especular de la luz

		double aten_a0; // coeficiente de atenuación a0
		double aten_a1; // coeficiente de atenuación a1
		double aten_a2; // coeficiente de atenuación a2

		// parámetros para definir un foco
		igvPunto3D direccion_foco;
		double angulo_foco;
		double exponente_foco;

		bool encendida; // Indica si la luz está encendida o no

		// Metodos

	public:
		// Constructores por defecto y destructor
		igvFuenteLuz();

		// Otros constructores
		// luz puntual
		igvFuenteLuz(const unsigned int _idLuz,
			           const igvPunto3D & _posicion,
			           const igvColor & cAmb, const igvColor & cDif, const igvColor & cEsp,
								 const double a0, const double a1, const double a2);

		// foco
		igvFuenteLuz(const unsigned int _idLuz,
			           const igvPunto3D & _posicion,
			           const igvColor& cAmb, const igvColor& cDif, const igvColor& cEsp,
								 const double a0, const double a1, const double a2,
								 const igvPunto3D& dir_foco, const double ang_foco, const double exp_foco);

		// Metodos
		igvPunto3D & getPosicion(void); // devuelve la posición de la luz
		void setPosicion(igvPunto3D pos); // establece la posición de la luz

		void set(const igvColor& cAmb, const igvColor& cDif, const igvColor& cEsp);
		void setAmbiental(const igvColor& cAmb);
		void setDifuso(const igvColor& cDif);
		void setEspecular(const igvColor& cEsp);
		igvColor& getAmbiental(void);
		igvColor& getDifuso(void);
		igvColor& getEspecular(void);

		void setAtenuacion(double a0, double a1, double a2);
		void getAtenuacion(double & a0, double & a1, double & a2);

		void encender(void);
		void apagar(void);
		unsigned int esta_encendida(void);

		void aplicar(void);
};

#endif

