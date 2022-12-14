#include <cstdlib>
#include <stdio.h>
#include "igvEscena3D.h"
#include <algorithm>


// Metodos constructores 
igvEscena3D::igvEscena3D() {
	ejes = true;
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

	//bola especial
	numeroGolpes = 0;
	numLatasTiradas = 0;
	coordenadasPelotaEspecial = juego.nuevaPosicionPelotaEspecial();
	pelotaEspecial.posicion = coordenadasPelotaEspecial;
	pelotaEspecialActivada = false;

	segundos1 = 10;
	segundos2 = 15;
	segundos3 = 5;

	//creamos vector que contiene todas las posiciones posibles de los objetos en la escena
	/*asignarLatasIniciales();*/

	/*coordenadaInicial.set(hitboxes[0]->posicion.c[0], hitboxes[0]->posicion.c[1], hitboxes[0]->posicion.c[2]);*/
	/*coordenadaInicial.set(0, 2, 0);*/
	coordenadaFinal.set(0, 2.5, 2);
	//coordenadaFinal.set(getRobotX() + 1, getRobotY() + 2.9, getRobotZ() + 4);

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
	pos_juego = 66;
	pos_r = 0;
	int veces_rojo = 1, veces_azul = 1, veces_gris = 48, veces_verde = 1;
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

	/*for (int i = 66; i < colores.size(); i+=3) {
			std::cout << colores[i] << "-" << colores[i + 1] << colores[i + 2] << std::endl;
	}*/

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
		glScaled(0.4, 0.4, 0.4);
		glutSolidSphere(1.2, 32, 32);
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

	cambia_color(colores, color_azul, pos_aa, 3);
	cambia_color(colores, color_rojo, pos_rr, 3);
	cambia_color(colores, color_verdeAzul, pos_vv, 3);
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

void igvEscena3D::calculoTrayectoriaPelota(hitbox h1, hitbox h2) {
	if (animacionPelota) {
		actualizarCoordenadaFinal(hitboxDestino.posicion);
	}
	//atributos booleanos para activar el lanzamiento de la pelota y cancelar el animar al robot
	animacionPelota = false;
	lanzarPelota = true;
	
	//Se genera la siguiente posición de la pelota lanzada que se corresponde con un segmento de una trayectoria
	interpolacionTrayectoria(h1, h2);

	//Se procesan las colisiones entre las dos hitboxes
	procesarColisiones(h1, h2);

	glPushMatrix();
	glTranslated(posicionPelota.c[0], posicionPelota.c[1], posicionPelota.c[2]);
	glScaled(0.2, 0.2, 0.2);
	modelos->esfera(color_rojo.data());
	glPopMatrix();

	glutPostRedisplay();
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
	/*if (getLanzandoPelota()) {*/
		/*calculoTrayectoriaPelota();*/
	/*}*/

	glPopMatrix(); // restaura la matriz de modelado
}

void igvEscena3D::visualizarVB() {

	if (!modo_act) {
		//pintar_robot();
		glPushMatrix();
		glRotated(getRotacion(), 0, 1, 0);
		glPushMatrix();
		//glRotated(getRotacion(), 0, 1, 0);
		glTranslated(-2.5, 1, -6.5);
		glScaled(0.7, 0.7, 0.7);
		modelos->Estanteria();
		glPopMatrix();

		glPushMatrix();
		//glRotated(getRotacion(), 0, 1, 0);
		glScaled(1.2, 0.6, 1.2);
		//modelos->visualizar();
		modelos->Mostrador();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 1.5, 2);
		glRotated(180, 0, 1, 0);
		glScaled(0.55, 0.55, 0.55);
		pintar_robot();
		glPopMatrix();

		if (iniciarPartida) {
			asignarLatasIniciales(); 
			iniciarPartida = false;
			juego.iniciarReloj();
			/*numLatas = hitboxes.size();*/
		}

		if (!finPartida) {
			gestionarLatasEventos();
			gestionarPelotaEspecialEventos();
			spawnPelotas();
		}

		/*std::cout << "Segundos: " << juego.getTiempoTranscurrido() << std::endl;*/
		glPopMatrix();
	}
	else {

		/*glPushMatrix();
		pintar_robotVB();
		glPopMatrix();*/

		glPushMatrix();
		glRotated(getRotacion(), 0, 1, 0);
		glPushMatrix();
		//glRotated(getRotacion(), 0, 1, 0);
		glTranslated(-2.5, 1, -6.5);
		glScaled(0.7, 0.7, 0.7);
		modelos->Estanteria();
		glPopMatrix();

		glPushMatrix();
		//glRotated(getRotacion(), 0, 1, 0);
		glScaled(1.2, 0.6, 1.2);
		//modelos->visualizar();
		modelos->Mostrador();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 1.5, 2);
		glRotated(180, 0, 1, 0);
		glScaled(0.55, 0.55, 0.55);
		pintar_robotVB();
		glPopMatrix();

		//dibujado de latas y pelota especial en seleccion
		gestionarLatasEventosVB();
		gestionarPelotaEspecialEventosVB();

		glPopMatrix();
	}

}

void igvEscena3D::pintar_todo() {
	glPushMatrix();
	glRotated(getRotacion(), 0, 1, 0);
	glPushMatrix();
	//glRotated(getRotacion(), 0, 1, 0);
	glTranslated(-2, 1, -6.5);
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

//buscar posicion de una hitbox en el vector de hitboxes mediante vector de posicion
int igvEscena3D::buscarHitbox(hitbox &h) {
	for (int i = 0; i < getHitboxes().size(); i++) {
		if (h.posicion == hitboxes[i]->posicion) {
			return i;
		}
	}

	return -1;

}

void igvEscena3D::actualizarCoordenadaFinal(const igvPunto3D &inicial) {
	coordenadaInicial = inicial;
}

void igvEscena3D::sustituirLata(const int& i) {
	//Elimino del vector donde indico que posiciones han sido tomadas
	hitboxes_a_borrar.push_back(i);
	juego.inicializarLata(hitboxesPendientes, 1);
}

void igvEscena3D::crearLata() {
	juego.inicializarLata(hitboxes, 1);
}

void igvEscena3D::determinarColorLata(const int &i, std::vector<float> &colorin) {
		if (hitboxes[i]->getValor() == 50) {
			GLfloat color[] = { color_azul[0], color_azul[1], color_azul[2] };
			colorin.push_back(color[0]);
			colorin.push_back(color[1]);
			colorin.push_back(color[2]);
		}
		else if (hitboxes[i]->getValor() == 100) {
			GLfloat color[] = { color_naranja[0], color_naranja[1], color_naranja[2] };
			colorin.push_back(color[0]);
			colorin.push_back(color[1]);
			colorin.push_back(color[2]);
		}
		else if (hitboxes[i]->getValor() == 150) {
			GLfloat color[] = { color_rojo[0], color_rojo[1], color_rojo[2] };
			colorin.push_back(color[0]);
			colorin.push_back(color[1]);
			colorin.push_back(color[2]);
		}
	
}

bool igvEscena3D::detectarColisiones(const hitbox& h1, hitbox& h2) {
	bool colisionX = h1.posicion.c[0] + h1.tamano.c[0] >= h2.posicion.c[0] && h2.posicion.c[0] + h2.tamano.c[0] >= h1.posicion.c[0];
	bool colisionY = h1.posicion.c[2] + h1.tamano.c[2] >= h2.posicion.c[2] && h2.posicion.c[2] + h2.tamano.c[2] >= h1.posicion.c[2];

	return colisionX && colisionY;
}

void igvEscena3D::asignarLatasIniciales() {
	juego.inicializarLata(hitboxes, 10);
}

void igvEscena3D::procesarColisiones(const hitbox& h1, hitbox h2) {
	//si la hitbox seleccionada y la hitbox de la pelota entran en contacto, aparece la pelota en la mano del robot y se borra el objeto que es impactado(h2)
	if (detectarColisiones(h1, h2)) {
		if (h2.getPosicionFloat() == pelotaEspecial.getPosicionFloat()) { //si la hitbox es la pelota especial se procede a asignar una nueva posicion aleatoria a esta
			numeroGolpes++;
			if (numeroGolpes == 3) { //si son 5 golpes los que hay significa que la pelota es destruida, procesamos los puntos por lo tanto y aumentamos el numero de tiradas
				numLatasTiradas++;
				juego.sumarPuntuacion(1000);
			}
			else {
				coordenadasPelotaEspecial = juego.nuevaPosicionPelotaEspecial();
				pelotaEspecial.setPosicion(coordenadasPelotaEspecial);
			}
		}
		else { //en caso de no ser la pelota especial el objeto destino, se procede de forma normal, se busca la hitbox en el vector y se elimina su puntero
			int i = buscarHitbox(h2);
			if (i != -1) {
				juego.sumarPuntuacion(hitboxes[i]->getValor());
				juego.liberarPosicion(hitboxes, i);
				hitboxes.erase(hitboxes.begin() + i);
				numLatasTiradas++;
			}
		}
		desactivarLanzamientoPelota();
		animacionPelota = true;
		lanzarPelota = false;
		a = 0;
		/*actualizarCoordenadasPelota(final, );*/
	}
}

void igvEscena3D::interpolacionTrayectoria(hitbox& h1, hitbox& h2) {
	igvPunto3D inic = coordenadaInicial;
	igvPunto3D fin = coordenadaFinal;

	//formula para trazar camino mediante interpolacion
	a += movementSpeed * deltaTime;
	/*a = std::clamp((int)a, 0, 1);*/
	float resta = 1 - a;
	inic.multiplicacionEscalar(a);
	fin.multiplicacionEscalar(resta);
	inic.sumaVectores(fin);
	posicionPelota = inic;
	h1.actualizarCoordenadas(posicionPelota.c[0], posicionPelota.c[1], posicionPelota.c[2]);
}

void igvEscena3D::gestionarLatasEventos() {
	hitbox h1;
	h1.tamano.c[0] = 0.2;
	h1.tamano.c[1] = 0.2;
	h1.tamano.c[2] = 0.2;

	GLfloat colorin[3];
	std::vector<float> colorinAux;
	//dibujamos los objetos del vector de hitboxes sacando su posicion y aplicando esta misma mediante un translated()
	for (int i = 0; i < hitboxes.size(); i++) {
		if (hitboxes[i]->pasadoDeTiempo()) {
			sustituirLata(i); //dado que la lata ha excedido su tiempo deber ser eliminada y traer una nueva en consecuencia
		}
		else {
			glPushMatrix();
			colorinAux.clear();
			determinarColorLata(i, colorinAux);
			colorin[0] = colorinAux[0];
			colorin[1] = colorinAux[1];
			colorin[2] = colorinAux[2];
			glTranslated(hitboxes[i]->posicion.c[0], hitboxes[i]->posicion.c[1], hitboxes[i]->posicion.c[2]);
			glRotated(90, 0, 0, 1);
			glScaled(0.35, 0.2, 0.2);
			modelos->cubo(colorin);
			glPopMatrix();
		}
	}
	glutPostRedisplay();

	if (hitboxes_a_borrar.size() > 0) { //borrar hitboxes cuyo tiempo ha expirado
		for (int i = 0; i < hitboxes_a_borrar.size(); i++) {
			juego.liberarPosicion(hitboxes, hitboxes_a_borrar[i]);
		}
		for (int i = 0; i < hitboxes_a_borrar.size(); i++) {
			hitboxes.erase(hitboxes.begin() + hitboxes_a_borrar[i]);
		}
	}

	hitboxes_a_borrar.clear();

	if (hitboxesPendientes.size() > 0) {
		for (int i = 0; i < hitboxesPendientes.size(); i++) {
			hitboxes.push_back(hitboxesPendientes[i]);
		}
	}

	hitboxesPendientes.clear();

	actualizarCoordenadaFinal(hitboxDestino.posicion);
	//si la pelota se lanza, la trayectoria se va calculando y aplicando en cada frame
	if (getLanzandoPelota()) {
		glPushMatrix();
		calculoTrayectoriaPelota(h1, hitboxDestino);
		glPopMatrix();
	}
}

void igvEscena3D::gestionarPelotaEspecialEventos() {
	if (juego.getTiempoTranscurrido() > 15 && numeroGolpes < 3) { //numLatasTiradas >= 3 && numeroGolpes < 5
		glPushMatrix();
		pelotaEspecialActivada = true;
		/*Sphere esfera;
		esfera.setRadius(0.8);*/
		glMaterialfv(GL_FRONT, GL_EMISSION, color_naranja.data());
		glColor3fv(color_naranja.data());
		glTranslated(coordenadasPelotaEspecial.c[0], coordenadasPelotaEspecial.c[1], coordenadasPelotaEspecial.c[2]);
		/*esfera.setSectorCount(10);
		esfera.draw();*/
		glutSolidSphere(1.2, 12, 12);
		glPopMatrix();
	}
}

void igvEscena3D::spawnPelotas() {
	if (juego.getTiempoTranscurrido() > segundos1) {
		segundos1 += 7;
		crearLata();
	}

	if (juego.getTiempoTranscurrido() > segundos2) {
		segundos2 += 7;
		crearLata();
	}

	/*if (juego.getTiempoTranscurrido() > segundos3) {
		segundos3 += 15;
		crearLata();
	}*/
}

void igvEscena3D::gestionarLatasEventosVB() {
	int contGris = 66;
	for (int i = 0; i < hitboxes.size(); i++) {
		glPushMatrix();
		glTranslated(hitboxes[i]->posicion.c[0], hitboxes[i]->posicion.c[1], hitboxes[i]->posicion.c[2]);
		glRotated(90, 0, 0, 1);
		glScaled(0.35, 0.2, 0.2);
		cambia_color(colores, color_grisOscuro, contGris, 3);
		if (hitboxes[i]->getValor() == 150) {
			std::cout << "El color gris de la roja es: " << color_grisOscuro[0] << ", " << color_grisOscuro[1] << ", " << color_grisOscuro[2] << std::endl;
		}
		hitboxes[i]->setColor(color_grisOscuro);
		modelos->cubo(color_grisOscuro.data());
		reinicio_colores();
		glPopMatrix();
	}

	pos_juego = contGris;
}

void igvEscena3D::gestionarPelotaEspecialEventosVB() {
	int contGris = pos_juego;
	if (juego.getTiempoTranscurrido() > 15 && numeroGolpes < 3) {
		glPushMatrix();
		cambia_color(colores, color_grisOscuro, contGris, 3);
		pelotaEspecial.setColor(color_grisOscuro);
		glMaterialfv(GL_FRONT, GL_EMISSION, color_grisOscuro.data());
		/*std::cout << "El color es: " << color_grisOscuro[0] << ", " << color_grisOscuro[1] << ", " << color_grisOscuro[2] << std::endl;*/
		glColor3fv(color_grisOscuro.data());
		/*Sphere esfera;
		esfera.setRadius(0.8);*/
		glTranslated(coordenadasPelotaEspecial.c[0], coordenadasPelotaEspecial.c[1], coordenadasPelotaEspecial.c[2]);
		/*esfera.setSectorCount(10);
		esfera.draw();*/
		glutSolidSphere(1.2, 12, 12);
		reinicio_colores();
		glPopMatrix();
	}
}
