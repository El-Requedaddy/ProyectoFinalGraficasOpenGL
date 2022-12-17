#include <cstdlib>
#include <stdio.h>
#include "igvEscena3D.h"
#include <algorithm>


// Metodos constructores 

igvEscena3D::igvEscena3D() {
	ejes = false;
	modelos = new Modelos();
	// Apartado C: inicializar los atributos para el control de los grados de libertad del modelo 
	rotacion_cabezaY = 0;
	rotacion_brazo_sup = 0;
	rotacion_brazo_inf = 0;
	rotacion_muneca = 0;
	rotacion_dedo1 = 0;
	rotacion_dedo2 = 0;
	rotacion_dedo3 = 0;
	rotacion_brazo_sup_izq = 0;
	rotacion_brazo_inf_izq = 0;
	rotacion_muneca_izq = 0;
	rotacion_dedo4 = 0;
	rotacion_dedo5 = 0;
	rotacion_dedo6 = 0;
	rotacion_pierna_sup = 0;
	rotacion_pierna_inf = 0;
	rotacion_pie = 0;

	X = 0;
	Y = 0;
	SetAng_foco(6);
	SetExp_foco(40);
	SetGB_dif(0.8);
	GB_esp = 0.8;
	foco_activo = false;

	coordenadaInicial.set(0, -4, 0);
	coordenadaFinal.set(getRobotX() + 1, getRobotY() + 2.9, getRobotZ() + 4);

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

	color_naranja.push_back(0.1f);
	color_naranja.push_back(0.5f);
	color_naranja.push_back(0.0f);

	color_rojo.push_back(1.0f);
	color_rojo.push_back(0.0f);
	color_rojo.push_back(0.0f);
	
	//Se generan los colores para la selección
	pos_r = 0;
	int veces_rojo = 1, veces_azul = 1,veces_gris = 19, veces_verde = 1;
	float ac = 1;
	for (int i = 0; i < veces_rojo; i++) {
		colores.push_back(1.0);
		colores.push_back(((0.0 * 255) + ac) / 255);
		colores.push_back(((0.0 * 255) + ac) / 255);
		ac += 10;
	}
	
	pos_a = colores.size();
	ac = 1;
	for (int i = 0; i < veces_azul; i++) {
		colores.push_back(((0.0 * 255) + ac) / 255);
		colores.push_back(((0.0 * 255) + ac) / 255);
		colores.push_back(1.0);
		ac += 1;
	}

	pos_v = colores.size();
	ac = 1;
	for (int i = 0; i < veces_verde; i++) {
		colores.push_back(((0.0 * 255) + ac) / 255);
		colores.push_back(((0.5 * 255) + ac) / 255);
		colores.push_back(((0.5 * 255) + ac) / 255);
		ac += 1;
	}
	
	pos_g = colores.size();
	ac = 1;
	for (int i = 0; i < veces_gris; i++) {
		colores.push_back(((0.1 * 255) + ac) / 255);
		colores.push_back(((0.1 * 255) + ac) / 255);
		colores.push_back(((0.1 * 255) + ac) / 255);
		ac += 1;
	}

}

igvEscena3D::~igvEscena3D() {
	delete modelos;
	
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

//Grafo de Escena
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
				glRotated(getRotacion_cabezaY(), 1, 0, 0);
				glRotated(getRotacion_cabezaX(), 0, 1, 0);
				modelos->cabeza(color_rojo, color_verdeAzul, color_grisOscuro); //se instancia la cabeza
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
				modelos->brazo_superior(0);
				
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(getRotacion_brazo_inf(), 0, 1, 0);   //rotación parte inferior del  brazo
					modelos->brazo_inferior(0);
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0); 
						glRotated(getRotacionMuneca(), 0, 0, 1);   //Rotación para mover la muñeca Xd
						modelos->mano(0);
						
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(getRotaciondedo1(), 0, 0, 1); //mover dedo1
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(1);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(getRotaciondedo2(), 0, 1, 0); //mover dedo2
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(2);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(getRotaciondedo3(), 0, 1, 0); //mover dedo3
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(3);
							glPopMatrix();

							if (getPelota() == true) {
								glPushMatrix();
								//Sphere esfera;
								//esfera.setRadius(0.9);
								glTranslated(0.8265, -0.1, 0);
								//esfera.draw();
								std::vector<GLfloat> culo; 
								culo.push_back(0.0f);
								culo.push_back(0.5f);
								culo.push_back(0.5f);
								modelos->esfera(culo.data());
								glutSolidSphere(0.9, 32, 32);
								glPopMatrix();		
							}
						
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
				modelos->brazo_superior(1);
				
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(-getRotacion_brazo_inf_izq(), 0, 1, 0);   //rotación parte inferior brazo
					modelos->brazo_inferior(1);
					
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0);   //Mover la mano para pegarlo al brazo xD
						glRotated(-getRotacionMunecaIzq(), 0, 0, 1);   //Rotación para mover la muñeca
						modelos->mano(1);
						
						glPushMatrix();  //dedo 1
							glTranslated(0.8265, 0.3, 0);
							glRotated(-getRotaciondedo4(), 0, 0, 1); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(4);
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 2
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(-getRotaciondedo5(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(5);
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 3
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(-getRotaciondedo6(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								modelos->dedo(6);
							glPopMatrix();

						glPopMatrix();
						
					glPopMatrix(); //mano
					 
				glPopMatrix();  //brazo inferior

			glPopMatrix();  //brazo suPerioR

		glPopMatrix();  //brazo completo xD

		glPushMatrix(); // pierna derecha

			glTranslated(-0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup(), 1, 0, 0); // rotacion pierna
			modelos->piernas(0);

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf(), 1, 0, 0);// rotacion pierna inf
				modelos->piernas_inf(0);
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie(), 1, 0, 0); //rotacion pie
					glRotated(-90, 0, 1, 0);
					modelos->pies(0);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna 1

		glPushMatrix(); // pierna izq

			glTranslated(0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup_izq(), 1, 0, 0);
			modelos->piernas(1);

			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf_izq(), 1, 0, 0);
				modelos->piernas_inf(1);
				glPushMatrix();
					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie_izq(), 1, 0, 0);
					glRotated(-90, 0, 1, 0);
					modelos->pies(1);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna

	glPopMatrix();

}
//--------------------------------------------------
//--------------------------------------------------
//--------------------------------------------------

//Método para la visualización del grafo de escena con colores diferentes para la selección
void igvEscena3D::pintar_robotVB() {
	int pos_rr = pos_r, pos_aa = pos_a, pos_vv = pos_v, pos_gg = pos_g;
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
				glRotated(getRotacion_cabezaY(), 1, 0, 0);
				glRotated(getRotacion_cabezaX(), 0, 1, 0);

				cambia_color(colores, color_azul, pos_aa,3);
				cambia_color(colores, color_rojo, pos_rr,3);
				cambia_color(colores, color_verdeAzul, pos_vv,3);
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->Get_coloresRobot()->set_colorBaseCabeza(color_azul);
				modelos->cabeza(color_rojo, color_verdeAzul, color_grisOscuro);
				
				reinicio_colores();

			glPopMatrix();
			
		glPopMatrix();
		
		glPushMatrix();//brazo derecho completo
		
			glTranslated(1.75, 1.3, 0); 
			glScaled(0.7, 1, 1);
			modelos->brazo();
			glPushMatrix();    //brazo superior completo
				
				glRotated(getRotacion_brazo_sup(), 0, 0, 1);
				glRotated(getRotacion2_brazo_sup(), 1, 0, 0);
				glRotated(-85, 0, 0, 1);

				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->Get_coloresRobot()->set_colorBrazoSup(color_grisOscuro);
				modelos->brazo_superior(0); 

				reinicio_colores();
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);  
					glRotated(getRotacion_brazo_inf(), 0, 1, 0);

					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					modelos->Get_coloresRobot()->set_colorBrazoInf(color_grisOscuro);
					modelos->brazo_inferior(0);

					reinicio_colores();
					glPushMatrix(); //mano
					
						glTranslated(2.42345, 0, 0); 
						glRotated(getRotacionMuneca(), 0, 0, 1);   

						cambia_color(colores, color_grisOscuro, pos_gg, 3);
						modelos->Get_coloresRobot()->set_colorMano(color_grisOscuro);
						modelos->mano(0);

						reinicio_colores();
						glPushMatrix();  //dedo 1

							glTranslated(0.8265, 0.3, 0);
							glRotated(getRotaciondedo1(), 0, 0, 1); 
							modelos->articulacionDedo();
							glPushMatrix();

								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->Get_coloresRobot()->set_colorDedo1(color_grisOscuro);
								modelos->dedo(1);
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
								modelos->Get_coloresRobot()->set_colorDedo2(color_grisOscuro);
								modelos->dedo(2);
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
								modelos->Get_coloresRobot()->set_colorDedo3(color_grisOscuro);
								modelos->dedo(3);
								reinicio_colores();

							glPopMatrix();

						glPopMatrix();//dedo3
						
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
				modelos->Get_coloresRobot()->set_colorBrazoSupIzq(color_grisOscuro);
				modelos->brazo_superior(1);
				reinicio_colores();
				glPushMatrix();   //brazo inferior completo

					glTranslated(2.5, 0, 0);   //Traslación de brazo inferior completa, juntando superior e inferior
					glRotated(-getRotacion_brazo_inf_izq(), 0, 1, 0);   
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					modelos->Get_coloresRobot()->set_colorBrazoInfIzq(color_grisOscuro);
					modelos->brazo_inferior(1);
					reinicio_colores();
					glPushMatrix();
					
						glTranslated(2.42345, 0, 0);   //Mover la mano para pegarlo al brazo xD
						glRotated(-getRotacionMunecaIzq(), 0, 0, 1);
						cambia_color(colores, color_grisOscuro, pos_gg, 3);
						modelos->Get_coloresRobot()->set_colorManoIzq(color_grisOscuro);
						modelos->mano(1);
						reinicio_colores();

						glPushMatrix();  //dedo 4
							glTranslated(0.8265, 0.3, 0);
							glRotated(-getRotaciondedo4(), 0, 0, 1); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->Get_coloresRobot()->set_colorDedo4(color_grisOscuro);
								modelos->dedo(4);
								reinicio_colores();
							glPopMatrix();
						glPopMatrix();

						glPushMatrix();  //dedo 5
							glTranslated(0.8265, -0.2, 0.3);
							glRotated(-getRotaciondedo5(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->Get_coloresRobot()->set_colorDedo5(color_grisOscuro);
								modelos->dedo(5);
								reinicio_colores();
							glPopMatrix();
						glPopMatrix();


						glPushMatrix();  //dedo 6
							glTranslated(0.8265, -0.2, -0.3);
							glRotated(-getRotaciondedo6(), 0, 1, 0); //mover dedo
							modelos->articulacionDedo();
							glPushMatrix();
								glTranslated(0.45, 0, 0);
								cambia_color(colores, color_grisOscuro, pos_gg, 3);
								modelos->Get_coloresRobot()->set_colorDedo6(color_grisOscuro);
								modelos->dedo(6);
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
			modelos->Get_coloresRobot()->set_colorPierna(color_grisOscuro);
			modelos->piernas(0);
			reinicio_colores();
			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf(), 1, 0, 0);// rotacion pierna inf
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->Get_coloresRobot()->set_colorPiernaInf(color_grisOscuro);
				modelos->piernas_inf(0);
				reinicio_colores();
				glPushMatrix();

					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie(), 1, 0, 0); //rotacion pie
					glRotated(-90, 0, 1, 0);
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					modelos->Get_coloresRobot()->set_colorPie(color_grisOscuro);
					modelos->pies(0);
					reinicio_colores();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna 1

		glPushMatrix(); // pierna izq

			glTranslated(0.8, -1.8, 0);
			glRotated(getRotacionpierna_sup_izq(), 1, 0, 0);
			cambia_color(colores, color_grisOscuro, pos_gg, 3);
			modelos->Get_coloresRobot()->set_colorPiernaIzq(color_grisOscuro);
			modelos->piernas(1);
			reinicio_colores();
			glPushMatrix();

				glTranslated(0, -2.45, 0);
				glRotated(getRotacionpierna_inf_izq(), 1, 0, 0);
				cambia_color(colores, color_grisOscuro, pos_gg, 3);
				modelos->Get_coloresRobot()->set_colorPiernaInfIzq(color_grisOscuro);
				modelos->piernas_inf(1);
				reinicio_colores();
				glPushMatrix();

					glTranslated(0, -2.3, 0);
					glRotated(getRotacionpie_izq(), 1, 0, 0);
					glRotated(-90, 0, 1, 0);
					cambia_color(colores, color_grisOscuro, pos_gg, 3);
					modelos->Get_coloresRobot()->set_colorPieIzq(color_grisOscuro);
					modelos->pies(1);
					reinicio_colores();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();//fin pierna

	glPopMatrix();

}

void igvEscena3D::calculoTrayectoriaPelota() {
	//trazar trayectoria de la pelota
	igvPunto3D inic = coordenadaInicial;
	igvPunto3D fin = coordenadaFinal;
	a += movementSpeed * deltaTime;
	//INCLUIR ALGORITMO CLAMP MINIMOS MAXIMOS!!!!!!
	float resta = 1 - a;
	inic.multiplicacionEscalar(a);
	fin.multiplicacionEscalar(resta);
	inic.sumaVectores(fin);
	posicionPelota = inic;

	//if (posicionPelota == coordenadaFinal) {
	//	desactivarLanzamientoPelota();
	//}

	glPushMatrix();
	glTranslated(getPosicionPelota().c[0], getPosicionPelota().c[1], getPosicionPelota().c[2]);
	glutSolidSphere(0.60, 32, 32);
	glPopMatrix();

	glutPostRedisplay();
}

void igvEscena3D::visualizar() {
	
	//ACTIVO LAS TEXTURAS
	glEnable(GL_TEXTURE_2D);

	//LUZ PUNTUAL
	igvPunto3D pos(-2.0, 6.0, 5.0);
	igvColor amb(0.5, 0.5, 0.5, 1.0);
	igvColor dif(0.7, 0.7, 0.7, 1.0);
	igvColor esp(0.8, 0.8, 0.8, 1.0);
	igvFuenteLuz luz(GL_LIGHT0, pos, amb, dif, esp, 1.0, 0.0, 0.0,false);
	luz.aplicar();

	//LUZ FOCO
	igvPunto3D pos_f(X, Y ,5);
	igvColor amb_f(0, 0.0, 0.0, 1.0);
	igvColor dif_f(0, GetGB_dif(), GetGB_dif(), 1.0);
	igvColor esp_f(0, GB_esp, GB_esp, 1.0);
	igvPunto3D dirF_f(0,0,-1);
	igvFuenteLuz foco(GL_LIGHT1, pos_f, amb_f, dif_f, esp_f, 1, 0, 0, dirF_f,GetAng_foco(), GetExp_foco(),false);
	if (!foco_activo) {
		foco.apagar();
		foco.aplicar();
	}
	else {
		foco.encender();
		foco.aplicar();
	}
	  
	//LUZ DIRECCIONAL
	igvPunto3D pos_d(0, 8, -5);
	igvColor amb_d(0.7, 0.7, 0.7, 1.0);
	igvColor dif_d(0.8, 0.8, 0.8, 1.0);
	igvColor esp_d(0.5, 0.5, 0.5, 1.0);
	igvFuenteLuz direccional(GL_LIGHT2, pos_d, amb_d, dif_d, esp_d, 1, 0, 0, true);
	direccional.aplicar();

	glPushMatrix();
	// se pintan los ejes
	if (ejes) pintar_ejes();
	glPopMatrix();

	glPushMatrix();
	visualizarVB();
	glPopMatrix();

}

void igvEscena3D::visualizar2() {
	//glLightfv(GL_LIGHT0,GL_POSITION,luz0); // la luz se coloca aquí si se mueve junto con la escena (también habría que desactivar la de arriba).

	hitbox cubo;
	//glScaled(1, 1, 1);
	//cubo.dibujar(); 
	/*cubo.setEscalarX(1);
	cubo.setEscalarY(1);
	cubo.setEscalarZ(1);*/
	Sphere esfera;

	glPushMatrix();
	glTranslated(getRobotX(), getRobotY(), getRobotZ());
	pintar_robot();
	glPopMatrix();

	//modelos->visualizar();

	glPushMatrix();
	glTranslated(getRobotX() + 1, getRobotY() + 2.9, getRobotZ() + 4);
	glutSolidSphere(0.60, 32, 32);
	glPopMatrix();

	//if (getPelota() == false) {
	//	glPushMatrix();
	//	glTranslated(trasX, trasY, trasZ);
	//	esfera.setRadius(0.45);
	//	//xesfera.printSelf();
	//	esfera.draw();
	//	//glutSolidCube(0.9);
	//	glPopMatrix();
	//}

	//calcular trayectoria de la pelota y moverla

	calculoTrayectoriaPelota();

	if (getLanzandoPelota()) {
		calculoTrayectoriaPelota();
	}

	glPopMatrix(); // restaura la matriz de modelado
}

void igvEscena3D::visualizarVB() {
	if (!modo_act) {
		glRotated(rotacionModeloCompleto, 0, 1, 0);
		glPushMatrix();

			glShadeModel(GL_SMOOTH);
			igvColor ambMo(0.1, 0.1, 0.1);
			igvColor difMo(0.5, 0.5, 0.5);
			igvColor espMo(0.3, 0.3, 0.3);
			igvMaterial material2(ambMo, difMo, espMo, 90);
			material2.aplicar();


			glPushMatrix();
			glTranslated(0, -0.5, 0.35);
			glScaled(1, 0.4, 1);
			modelos->Mostrador();
			glPopMatrix();


			
			//std::string j = "\estea2.jpg";
			//igvTextura text(&j[0]);
			//text.aplicar();
			//glPushMatrix();
			//glRotated(rotacionModeloCompleto, 0, 1, 0);
			//glRotated(90, 0, 0, 1);
			//glScaled(0.35, 0.2, 0.2);
			//modelos->cubo(color_grisOscuro.data());

			//glPopMatrix();

			glShadeModel(GL_SMOOTH);
			igvColor ambM(0.1, 0.1, 0.1);
			igvColor difM(0.7, 0.7, 0.7);
			igvColor espM(0.8, 0.8, 0.8);
			igvMaterial material(ambM, difM, espM, 80);
			material.aplicar();

			glPushMatrix();
			glTranslated(-2,0.65,-6.5);
			glScaled(0.5, 0.5, 0.5);
			modelos->Estanteria();
			glPopMatrix();

			glPushMatrix();
			glTranslated(0, 0, 2);
			glRotated(180, 0, 1, 0);
			glScaled(0.2, 0.2, 0.2);
			pintar_robot();
			glPopMatrix();

			glPushMatrix();
			glTranslated(0, 0, 1);
			glScaled(4, 1, 4);
			modelos->Suelo();
			glPopMatrix();

			glPushMatrix();
			glTranslated(7.7, 0.6, 5);
			modelos->Pared();
			glPopMatrix();

			glPushMatrix();
			//glTranslated(-7.7,3.8,-7);
			glTranslated(-7.7, 0.6, -3);
			glRotated(180, 0, 1, 0);
			modelos->Pared();
			glPopMatrix();

			glPushMatrix();
			glTranslated(4, 0.6, -7);
			glRotated(90, 0, 1, 0);
			modelos->Pared();
			glPopMatrix();

		glPopMatrix();
	}
	else {

		/*glPushMatrix();
		pintar_robotVB();
		glPopMatrix();*/
		
		glPushMatrix();

			glPushMatrix();
			glTranslated(-2, 1, -6.5);
			glScaled(0.5, 0.5, 0.5);
			modelos->Estanteria();
			glPopMatrix();

			glPushMatrix();
			glScaled(1, 0.4, 1);
			modelos->Mostrador();
			glPopMatrix();

			glPushMatrix();
			glTranslated(0, 0, 2);
			glRotated(180, 0, 1, 0);
			glScaled(0.2, 0.2, 0.2);
			pintar_robotVB();
			glPopMatrix();

		glPopMatrix();
	}

}

void igvEscena3D::pintar_todo() {
	glPushMatrix();
	glRotated(getRotacion(), 0, 1, 0);
		glPushMatrix();
		glTranslated(-2,1,-6.5);
		glScaled(0.5, 0.5, 0.5);
		modelos->Estanteria();
		glPopMatrix();

		glPushMatrix();
		glScaled(1, 0.4, 1);
		modelos->Mostrador();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, 2);
		glScaled(0.2, 0.2, 0.2);
		pintar_robot();
		glPopMatrix();

	glPopMatrix();
}

int igvEscena3D::buscarHitbox(float x, float y, float z) {
	for (int i = 0; i < getHitboxes().size(); i++) {
		if (x == getHitboxes()[i]->posicion.c[0] && y == getHitboxes()[i]->posicion.c[1] && z == getHitboxes()[i]->posicion.c[2]) {
			return i;
		}
	}

	return 0;

}

void igvEscena3D::visualizar3() {
	glTranslated(-2, -1, -6.5);
	glRotated(90, 1, 0, 0);
	glScaled(12, 1, 4);
	modelos->cilindro(color_marron.data());
}