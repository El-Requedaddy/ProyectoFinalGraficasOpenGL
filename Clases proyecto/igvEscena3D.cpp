#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"


// Metodos constructores 

igvEscena3D::igvEscena3D() {
	ejes = true;
	modelos = new Modelos();
	// Apartado C: inicializar los atributos para el control de los grados de libertad del modelo 
	rotacion_brazo_sup = 0;
	rotacion_brazo_inf = 0;
	rotacion_muneca = 0;
	rotacion_dedo1 = 0;
	rotacion_dedo2 = 0;
	rotacion_dedo3 = 0;
	rotacion_brazo_sup_izq = 0;
	rotacion_brazo_inf_izq = 0;
	rotacion_muneca_izq = 0;
	rotacion_dedo1_izq = 0;
	rotacion_dedo2_izq = 0;
	rotacion_dedo3_izq = 0;
	rotacion_pierna_sup = 0;
	rotacion_pierna_inf = 0;
	rotacion_pie = 0;
}

igvEscena3D::~igvEscena3D() {

}


// Metodos publicos 

void pintar_ejes(void) {
	GLfloat rojo[] = { 1,0,0,1.0 };
	GLfloat verde[] = { 0,1,0,1.0 };
	GLfloat azul[] = { 0,0,1,1.0 };

	glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
	glBegin(GL_LINES);
	glVertex3f(1000, 0, 0);
	glVertex3f(-1000, 0, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, verde);
	glBegin(GL_LINES);
	glVertex3f(0, 1000, 0);
	glVertex3f(0, -1000, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, azul);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 1000);
	glVertex3f(0, 0, -1000);
	glEnd();
}

///// Apartado B: Métodos para visualizar cada parte del modelo
/// ESTO SE ENCUENTRA EN LA CLASE MODELOS

////// Apartado C: añadir aquí los métodos para modificar los grados de libertad del modelo
void igvEscena3D::pintar_robot() {
	glTranslated(0, 0.8, 0);
	glRotated(getRotacion(), 0, 1, 0);
	glScaled(0.7, 0.7, 0.7);
	modelos->torso();

	glPushMatrix();

		glPushMatrix(); //cuello con cabeza
			glTranslated(0, 3, 0);
			modelos->cuello();
			glPushMatrix();
				glTranslated(0, 1, 0);
				glRotated(getRotacion_cabeza(), 1, 0, 0); 
				modelos->cabeza(); //se instancia la cabeza
			glPopMatrix();
			
		glPopMatrix();
		
		glPushMatrix();//brazo derecho completo
		
			glTranslated(1.75, 1.3, 0); 
			glScaled(0.7, 1, 1);
			modelos->brazo();
			
			glPushMatrix();    //brazo superior completo
				
				glRotated(getRotacion_brazo_sup(), 0, 0, 1);//rotacion brazo completo
				glRotated(getRotacion2_brazo_sup(), 1, 0, 0);
				glRotated(-85, 0, 0, 1);
				modelos->brazo_superior();
				
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(getRotacion_brazo_inf(), 0, 1, 0);   //rotación parte inferior brazo
					modelos->brazo_inferior();
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0); 
						glRotated(getRotacionMuneca(), 0, 0, 1);   //Rotación para mover la muñeca Xd
						modelos->mano();
						
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(getRotaciondedo1(), 0, 0, 1); //mover dedo1
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo();
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(getRotaciondedo2(), 0, 1, 0); //mover dedo2
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo();
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(getRotaciondedo3(), 0, 1, 0); //mover dedo3
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo();
							glPopMatrix();

						glPopMatrix();
						
					glPopMatrix(); //mano
					 
				glPopMatrix();  //brazo inferior

			glPopMatrix();  //brazo suPerioR

		glPopMatrix();  //brazo completo xD

		//------------------------BRAZO 2----------------------------------

		glPushMatrix();
		//brazo 2 completo
			glTranslated(-1.75, 1.3, 0); 
			
			glRotated(180, 1, 0, 0);
			glRotated(180, 0, 0, 1);
			glScaled(0.7, 1, 1);
			modelos->brazo();
			
			glPushMatrix();    //brazo superior completo
				
				glRotated(getRotacion_brazo_sup_izq(), 0, 0, 1);//rotacion brazo completo
				glRotated(-85, 0, 0, 1);
				modelos->brazo_superior();
				
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(-getRotacion_brazo_inf_izq(), 0, 1, 0);   //rotación parte inferior brazo
					modelos->brazo_inferior();
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0);   //Mover la mano para pegarlo al brazo xD
						glRotated(-getRotacionMunecaIzq(), 0, 0, 1);   //Rotación para mover la muñeca
						modelos->mano();
						
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(-getRotaciondedo1_izq(), 0, 0, 1); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo();
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(-getRotaciondedo2_izq(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo();
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(-getRotaciondedo3_izq(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo();
							glPopMatrix();

						glPopMatrix();
						
					glPopMatrix(); //mano
					 
				glPopMatrix();  //brazo inferior

			glPopMatrix();  //brazo suPerioR

		glPopMatrix();  //brazo completo xD

		glPushMatrix(); // pierna derecha

			glTranslated(-0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup(), 1, 0, 0); // rotacion pierna
			modelos->piernas();

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf(), 1, 0, 0);// rotacion pierna inf
				modelos->piernas_inf();
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie(), 1, 0, 0); //rotacion pie
					glRotated(-90, 0, 1, 0);
					modelos->pies();
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna 1

		glPushMatrix(); // pierna izq

			glTranslated(0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup_izq(), 1, 0, 0);
			modelos->piernas();

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf_izq(), 1, 0, 0);
				modelos->piernas_inf();
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie_izq(), 1, 0, 0);
					glRotated(-90, 0, 1, 0);
					modelos->pies();
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna

	glPopMatrix();

}


void igvEscena3D::visualizar() {
	// crear luces
	GLfloat luz0[4] = { 5.0,5.0,5.0,1 }; // luz puntual  
	glLightfv(GL_LIGHT0, GL_POSITION, luz0); // la luz se coloca aquí si permanece fija y no se mueve con la escena
	glEnable(GL_LIGHT0);

	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// se pintan los ejes
	if (ejes) pintar_ejes();

	//glLightfv(GL_LIGHT0,GL_POSITION,luz0); // la luz se coloca aquí si se mueve junto con la escena (también habría que desactivar la de arriba).



	

	///// Apartado B: aquí hay que añadir la visualización del árbol del modelo utilizando la pila de matrices de OpenGL
	/////             se recomienda crear una método auxiliar que encapsule todo el código para la visualización
	/////             del modelo, dejando aquí sólo la llamada a ese método, así como distintas funciones una para cada
	/////			  parte del modelo. 
	//pintar_robot();


	glRotated(getRotacion(), 1, 0, 0);
	modelos->visualizar();
	//glPopMatrix();
	glPopMatrix(); // restaura la matriz de modelado
}




