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

	color_verdeAzul.push_back(0.0f);
	color_verdeAzul.push_back(0.5f);
	color_verdeAzul.push_back(0.5f);

	color_grisOscuro.push_back(0.1f);
	color_grisOscuro.push_back(0.1f);
	color_grisOscuro.push_back(0.1f);

	color_azul.push_back(0.0f);
	color_azul.push_back(0.0f);
	color_azul.push_back(1.0f);

	color_marron.push_back(0.1f);
	color_marron.push_back(0.0f);
	color_marron.push_back(0.0f);

	color_rojo.push_back(1.0f);
	color_rojo.push_back(0.0f);
	color_rojo.push_back(0.0f);
	//color_rojo.push_back(0.0f);

	//poner vector< vector<GLfloat> > y separarlo por colores, es decir tener una matriz par< color rojo otra para gris...

	pos_r = 0;
	int veces_rojo = 11, veces_azul = 1,veces_gris = 19, veces_verde = 1;
	float ac = 1;
	for (int i = 0; i < veces_rojo; i++) {
		//colores.push_back(((0.1 * 255) + ac) / 255);//0.1039
		colores.push_back(1.0);
		colores.push_back(((0.0 * 255) + ac) / 255);//0.0039
		colores.push_back(((0.0 * 255) + ac) / 255);
		//colores.push_back(((0.0 * 255) + ac) / 255);
		//std::cout << colores.size() << " -> " << 255 << "-" << ((0.0 * 255) + ac) << "-" << ((0.0 * 255) + ac) << std::endl;

		ac += 10;
	}
	std::cout << "rojo: " << colores.size() << std::endl;
	pos_a = veces_rojo * 3;
	ac = 1;
	for (int i = 0; i < veces_azul; i++) {
		colores.push_back(((0.0 * 255) + ac) / 255);
		colores.push_back(((0.0 * 255) + ac) / 255);
		//colores.push_back(((0.1 * 255) + ac) / 255);
		colores.push_back(1.0);
		ac += 1;
	}
	std::cout << "azul: " << colores.size() << std::endl;
	pos_g = pos_a + (veces_azul * 3);
	ac = 1;
	for (int i = 0; i < veces_gris; i++) {
		colores.push_back(((0.1 * 255) + ac) / 255);
		colores.push_back(((0.1 * 255) + ac) / 255);
		colores.push_back(((0.1 * 255) + ac) / 255);
		ac += 1;
	}
	std::cout << "gris: " << colores.size() << std::endl;
	pos_v = pos_g + (veces_gris * 3);
	ac = 1;
	for (int i = 0; i < veces_verde; i++) {
		colores.push_back(((0.0 * 255) + ac) / 255);
		colores.push_back(((0.5 * 255) + ac) / 255);
		colores.push_back(((0.5 * 255) + ac) / 255);
		//colores.push_back(0.5);
		//colores.push_back(0.5);
		ac += 1;
	}
	std::cout << "verde: " << colores.size() << std::endl;

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


void igvEscena3D::pintar_robot() {
	glTranslated(0, 0.8, 0);
	glRotated(getRotacion(), 1, 0, 0);
	glScaled(0.7, 0.7, 0.7);
	modelos->torso();

	glPushMatrix();

		glPushMatrix(); //cuello con cabeza
			glTranslated(0, 3, 0);
			modelos->cuello(color_rojo, color_grisOscuro);
			glPushMatrix();
				glTranslated(0, 1, 0);
				glRotated(getRotacion_cabeza(), 1, 0, 0); 
				modelos->cabeza(color_azul, color_rojo, color_verdeAzul, color_grisOscuro); //se instancia la cabeza
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
				modelos->brazo_superior(color_grisOscuro);
				
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(getRotacion_brazo_inf(), 0, 1, 0);   //rotación parte inferior brazo
					modelos->brazo_inferior(color_grisOscuro,color_rojo);
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0); 
						glRotated(getRotacionMuneca(), 0, 0, 1);   //Rotación para mover la muñeca Xd
						modelos->mano(color_rojo,color_grisOscuro);
						
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(getRotaciondedo1(), 0, 0, 1); //mover dedo1
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(color_grisOscuro);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(getRotaciondedo2(), 0, 1, 0); //mover dedo2
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(color_grisOscuro);
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(getRotaciondedo3(), 0, 1, 0); //mover dedo3
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(color_grisOscuro);
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
				modelos->brazo_superior(color_grisOscuro);
				
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(-getRotacion_brazo_inf_izq(), 0, 1, 0);   //rotación parte inferior brazo
					modelos->brazo_inferior(color_grisOscuro,color_rojo);
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0);   //Mover la mano para pegarlo al brazo xD
						glRotated(-getRotacionMunecaIzq(), 0, 0, 1);   //Rotación para mover la muñeca
						modelos->mano(color_rojo, color_grisOscuro);
						
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(-getRotaciondedo1_izq(), 0, 0, 1); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(color_grisOscuro);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(-getRotaciondedo2_izq(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(color_grisOscuro);
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(-getRotaciondedo3_izq(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(color_grisOscuro);
							glPopMatrix();

						glPopMatrix();
						
					glPopMatrix(); //mano
					 
				glPopMatrix();  //brazo inferior

			glPopMatrix();  //brazo suPerioR

		glPopMatrix();  //brazo completo xD

		glPushMatrix(); // pierna derecha

			glTranslated(-0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup(), 1, 0, 0); // rotacion pierna
			modelos->piernas(color_rojo, color_grisOscuro);

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf(), 1, 0, 0);// rotacion pierna inf
				modelos->piernas_inf(color_rojo, color_grisOscuro);
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie(), 1, 0, 0); //rotacion pie
					glRotated(-90, 0, 1, 0);
					modelos->pies(color_rojo, color_grisOscuro);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna 1

		glPushMatrix(); // pierna izq

			glTranslated(0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup_izq(), 1, 0, 0);
			modelos->piernas(color_rojo, color_grisOscuro);

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf_izq(), 1, 0, 0);
				modelos->piernas_inf(color_rojo, color_grisOscuro);
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie_izq(), 1, 0, 0);
					glRotated(-90, 0, 1, 0);
					modelos->pies(color_rojo, color_grisOscuro);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna

	glPopMatrix();

}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------


void igvEscena3D::pintar_robotVB() {
	int pos_rr = pos_r, pos_aa = pos_a, pos_vv = pos_v, pos_gg = pos_g;
	//std::cout << "H";
	//std::vector<GLfloat> aux_col;
	glTranslated(0, 0.8, 0);
	glRotated(getRotacion(), 1, 0, 0);
	glScaled(0.7, 0.7, 0.7);
	modelos->torso();

	glPushMatrix();

		glPushMatrix(); //cuello con cabeza
			glTranslated(0, 3, 0);
			modelos->cuello(color_rojo, color_grisOscuro);
			glPushMatrix();
				glTranslated(0, 1, 0);
				glRotated(getRotacion_cabeza(), 1, 0, 0); 
				cambia_color(colores, color_azul, pos_aa,3);
				cambia_color(colores, color_rojo, pos_rr,3);
				cambia_color(colores, color_verdeAzul, pos_vv,3);
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->cabeza(color_azul, color_rojo, color_verdeAzul, color_grisOscuro); //se instancia la cabeza, colores[0-12)
				reinicio_colores();
				//reinicio_colores(color_rojo,color_grisOscuro,color_azul,color_verdeAzul);
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
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->brazo_superior(color_grisOscuro); // rango en colores: [12-15)
				reinicio_colores();
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(getRotacion_brazo_inf(), 0, 1, 0);   //rotación parte inferior brazo
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					cambia_color(colores, color_rojo, pos_rr, 3);
					modelos->brazo_inferior(color_grisOscuro,color_rojo);//rango en colores: [15-21)
					reinicio_colores();
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0); 
						glRotated(getRotacionMuneca(), 0, 0, 1);   //Rotación para mover la muñeca Xd
						cambia_color(colores, color_grisOscuro, pos_gg, 3);
						cambia_color(colores, color_rojo, pos_rr, 3);
						modelos->mano(color_grisOscuro,color_rojo);// rango en colores: [21-27)
						reinicio_colores();
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(getRotaciondedo1(), 0, 0, 1); //mover dedo1 usando rotación de color [27-30)
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->dedo(color_grisOscuro);//rango en colores: [27-30)
								reinicio_colores();
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(getRotaciondedo2(), 0, 1, 0); //mover dedo2
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->dedo(color_grisOscuro);//rango en colores: [30-33)
								reinicio_colores();
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(getRotaciondedo3(), 0, 1, 0); //mover dedo3
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->dedo(color_grisOscuro);//rango en colores: [33-36)
								reinicio_colores();
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
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->brazo_superior(color_grisOscuro); // rango en colores: [36-39)
				reinicio_colores();
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(-getRotacion_brazo_inf_izq(), 0, 1, 0);   //rotación parte inferior brazo
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					cambia_color(colores, color_rojo, pos_rr, 3);
					modelos->brazo_inferior(color_grisOscuro, color_rojo);//rango en colores: [39-45)-4-9
					reinicio_colores();
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0);   //Mover la mano para pegarlo al brazo xD
						glRotated(-getRotacionMunecaIzq(), 0, 0, 1);   //Rotación para mover la muñeca
						cambia_color(colores, color_grisOscuro, pos_gg, 3);
						cambia_color(colores, color_rojo, pos_rr, 3);
						modelos->mano(color_grisOscuro, color_rojo);// rango en colores: [45-51)5-10
						reinicio_colores();

						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(-getRotaciondedo1_izq(), 0, 0, 1); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->dedo(color_grisOscuro);//rango en colores: [51-54)5-11
								reinicio_colores();
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(-getRotaciondedo2_izq(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->dedo(color_grisOscuro);//rango en colores: [54-57)-5-12
								reinicio_colores();
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(-getRotaciondedo3_izq(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->dedo(color_grisOscuro);//rango en colores: [57-60)-5-13
								reinicio_colores();
							glPopMatrix();

						glPopMatrix();
						
					glPopMatrix(); //mano
					 
				glPopMatrix();  //brazo inferior

			glPopMatrix();  //brazo suPerioR

		glPopMatrix();  //brazo completo xD

		glPushMatrix(); // pierna derecha

			glTranslated(-0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup(), 1, 0, 0); // rotacion pierna
			cambia_color(colores, color_grisOscuro, pos_gg, 3);
			cambia_color(colores, color_rojo, pos_rr, 3);
			modelos->piernas(color_rojo,color_grisOscuro);//rango en colores: [60-66)-6-14
			reinicio_colores();
			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf(), 1, 0, 0);// rotacion pierna inf
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				cambia_color(colores, color_rojo, pos_rr, 3);
				modelos->piernas_inf(color_rojo, color_grisOscuro);//rango en colores: [66-72)-7-15
				reinicio_colores();
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie(), 1, 0, 0); //rotacion pie
					glRotated(-90, 0, 1, 0);
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					cambia_color(colores, color_rojo, pos_rr, 3);
					modelos->pies(color_rojo, color_grisOscuro);//rango en colores: [72-78)-8-16
					reinicio_colores();
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna 1

		glPushMatrix(); // pierna izq

			glTranslated(0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup_izq(), 1, 0, 0);
			cambia_color(colores, color_grisOscuro, pos_gg, 3);
			cambia_color(colores, color_rojo, pos_rr, 3);
			modelos->piernas(color_rojo, color_grisOscuro);//rango en colores: [78-84)-9-17
			reinicio_colores();

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf_izq(), 1, 0, 0);
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				cambia_color(colores, color_rojo, pos_rr, 3);
				modelos->piernas_inf(color_rojo, color_grisOscuro);//rango en colores: [84-90)-10-18
				reinicio_colores();
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie_izq(), 1, 0, 0);
					glRotated(-90, 0, 1, 0);
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					cambia_color(colores, color_rojo, pos_rr, 3);
					modelos->pies(color_rojo, color_grisOscuro);//rango en colores: [90-96)-11-19
					reinicio_colores();
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
		glPopMatrix();

		glPushMatrix();
		visualizarVB();
		glPopMatrix();

}
void igvEscena3D::visualizarVB() {
	if (!modo_act) {
		pintar_robot();
	}
	else {

		glPushMatrix();
		pintar_robotVB();
		//glMaterialfv(GL_FRONT, GL_EMISSION, color_rojo.data());
		//glColor3fv(color_rojo.data());//Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		//glPushMatrix();
		//glScalef(1, 1, 2);
		//glutSolidCube(1);
		//glPopMatrix();

		//glPushMatrix();
		//glTranslatef(0, 0.4, 0);
		//glScalef(1.1, 0.2, 2.1);
		//glutSolidCube(1);
		//glPopMatrix();
		glPopMatrix();
	}

}
void igvEscena3D::pintar_todo() {
	glPushMatrix();
	glRotated(getRotacion(), 0, 1, 0);
		glPushMatrix();
		//glRotated(getRotacion(), 0, 1, 0);
		glTranslated(-2,1,-6.5);
		glScaled(0.5, 0.5, 0.5);
		modelos->Estanteria();
		glPopMatrix();

		glPushMatrix();
		//glRotated(getRotacion(), 0, 1, 0);
		glScaled(1, 0.4, 1);
		//modelos->visualizar();
		modelos->Mostrador();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, 2);
		glScaled(0.2, 0.2, 0.2);
		pintar_robot();
		glPopMatrix();

	glPopMatrix();
}




