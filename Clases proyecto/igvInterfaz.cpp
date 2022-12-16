#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

using namespace std;

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
							 // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz() {
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
	objeto_seleccionado = -1;
	animar = false;
	objeto_seleccionado = -1;
	fin_primera_fase = 0;
	cambio = false;
}

igvInterfaz::~igvInterfaz() {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	//p0 = igvPunto3D(3.0, 2.0, 4);
	//r = igvPunto3D(0, 0, 0);
	//V = igvPunto3D(0, 1.0, 0);

	//p0 = igvPunto3D(6.0, 4.0, 8);
	p0 = igvPunto3D(0, 2, 5);
	//p0 = igvPunto3D(1.5,3,8);
	r = igvPunto3D(0, 0, 0);
	V = igvPunto3D(0, 1.0, 0);

	interfaz.camara.set(IGV_PARALELA, p0, r, V, -1 * 5, 1 * 5, -1 * 5, 1 * 5, -1 * 3, 200);

	//interfaz.camara.set(IGV_PARALELA, p0, r, V, -1 * 3, 1 * 3, -1 * 3, 1 * 3, 1, 200);

	//parámetros de la perspectiva
	interfaz.camara.angulo = 60;
	interfaz.camara.raspecto = 1.0;
}

void igvInterfaz::configura_entorno(int argc, char** argv,
	int _ancho_ventana, int _alto_ventana,
	int _pos_X, int _pos_Y,
	string _titulo) {
	// inicialización de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;
	
	// inicialización de la ventana de visualización
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(_ancho_ventana, _alto_ventana);
	glutInitWindowPosition(_pos_X, _pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
	glClearColor(1.0, 1.0, 1.0, 0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
	glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
		////// Apartado C: incluir aquí el cambio de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva 
		////// Apartado C: incluir aquí la modificación de los grados de libertad del modelo pulsando las teclas correspondientes
	
	case '9':
		interfaz.escena.SetX(0.1);
		break;
	case '8':
		interfaz.escena.SetX(-0.1);
		break;
	case '7':
		interfaz.escena.SetY(0.1);
		break;
	case '*': // Apartado D: disminuir en 10 el exponente de Phong del material
		interfaz.escena.SetY(-0.1);
		break;
	

	case 'x': // activa/desactiva la visualizacion de los ejes
		interfaz.escena.set_ejes(interfaz.escena.get_ejes() ? false : true);
		break;
	case 'Q':
		interfaz.escena.setRotacion(-10);//todo el modelo
		break;
	case 'q':
		interfaz.escena.setRotacion(10);//todo el modelo
		break;

		//---------------------------------GESTIÓN DE LUCES-------------------------------

	case 'w': // Aumentar ángulo de foco
		if(interfaz.escena.GetAng_foco() + 3 <= 90) // límites que tiene el ángulo según la teoría
			interfaz.escena.SetAng_foco(3);
		break;
	case 'W': //Disminuir ángulo de foco
		if (interfaz.escena.GetAng_foco() - 3 >= 0)
			interfaz.escena.SetAng_foco(-3);;
		break;
	case 'e': //aumentar´Exponente
		if (interfaz.escena.GetExp_foco() + 2 <= 179) //  límites que tiene el ángulo según la teoría
			interfaz.escena.SetExp_foco(2);
		break;
	case 'E': //diminuir exponente
		if (interfaz.escena.GetExp_foco() - 2 >= 0)
			interfaz.escena.SetExp_foco(-2);;//cabeza
		break;
	case 'r': //aumentar G y B de refleción difusa
		if (interfaz.escena.GetGB_dif() + 0.1 <= 1.0) 
			interfaz.escena.SetGB_dif(0.1);
		break;
	case 'R': //disminuir G y B de refleción difusa
		if (interfaz.escena.GetGB_dif() - 0.1 >= 0.0)
			interfaz.escena.SetGB_dif(-0.1);
		break;
	case 't': //aumentar G y B de refleción especular
		if (interfaz.escena.GetGB_esp() + 0.1 <= 1.0)
			interfaz.escena.SetGB_esp(0.1);
		break;
	case 'T': //disminuir G y B de refleción especular
		if (interfaz.escena.GetGB_esp() - 0.1 >= 0.0)
			interfaz.escena.SetGB_esp(-0.1);
		break;
	case 'y': //Apagar/Encender foco
		interfaz.escena.SetFoco_activo(interfaz.escena.GetFoco_activo() ? false : true);
		break;
	case 'Y': //Apagar/Encender foco
		interfaz.escena.SetFoco_activo(interfaz.escena.GetFoco_activo() ? false : true);
		break;
	case 'u': { //Apagar/Encender foco
		igvPunto3D p0, r, v;
		p0 = igvPunto3D(2, 4, 4);
		r = igvPunto3D(0.5, 0, -6.3);
		v = igvPunto3D(0, 1.0, 0);
		interfaz.camara.set(IGV_PERSPECTIVA, p0, r, v, -1 * 3, 1 * 3, -1 * 3, 1 * 3, 1, 200);
		interfaz.camara.aplicar();
	}
		break;
	//--------------------------------------GESTIÓN ANIMACIÓN------------------------------------------------------------------------
	
	case 'a':
		if (interfaz.animar) interfaz.animar = false;
		else
			interfaz.animar = true;
		break;
	case 'n':
		interfaz.resetear();
		break;

		//-------------------------------------GESTIÓN CÁMARA---------------------------------------------------------

	case '1': // cambia el tipo de proyección de paralela a perspectiva y viceversa
		interfaz.camara.setTipoCamara(IGV_PERSPECTIVA);
		interfaz.camara.aplicar();
		break;
	case '2': // cambia el tipo de proyección de paralela a perspectiva y viceversa
		interfaz.camara.setTipoCamara(IGV_PARALELA);
		interfaz.camara.aplicar();
		break;
	case '3':
	{
		// cambia la posición de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva
		igvPunto3D posicion = igvPunto3D::igvPunto3D(0.1, 8, 0);
		igvPunto3D referenciaVista = igvPunto3D::igvPunto3D(0, 0, 0);
		igvPunto3D vectorArriba = igvPunto3D::igvPunto3D(0, 1, 0);
		interfaz.camara.set(posicion, referenciaVista, vectorArriba);
		interfaz.camara.aplicar();
	}
	break;
	{
	case '4': // cambia la posición de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva
		igvPunto3D posicion = igvPunto3D::igvPunto3D(5, 0, 0);
		igvPunto3D referenciaVista = igvPunto3D::igvPunto3D(0, 0, 0);
		igvPunto3D vectorArriba = igvPunto3D::igvPunto3D(0, 1, 0);
		interfaz.camara.set(posicion, referenciaVista, vectorArriba);
		interfaz.camara.aplicar();
	}
	break;
	case '5':
	{
		hitbox h1;
		hitbox h2;

		if (interfaz.detectarColisiones(h1, h2)) {
			std::cout << "COLISIONAN " << std::endl;
		}
	}
	case '6':
	{
		interfaz.escena.setPelota(true);
	}
		break;
	case '+': // zoom in
		interfaz.camara.zoom();
		interfaz.camara.aplicar();
		break;
	case '-': // zoom out
		interfaz.camara.zoomOut();
		interfaz.camara.aplicar();
		break;
	case 'b': // incrementar la distancia del plano cercano
		interfaz.camara.sumarZnear();
		interfaz.camara.aplicar();
		break;
	case 'B': // decrementar la distancia del plano cercano
		interfaz.camara.restarZnear();
		interfaz.camara.aplicar();
		break;		
	case 27: // tecla de escape para SALIR
		exit(1);
		break;
	}
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
	// dimensiona el viewport al nuevo ancho y alto de la ventana
	// guardamos valores nuevos de la ventana de visualizacion

	interfaz.set_ancho_ventana(w);
	interfaz.set_alto_ventana(h);

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
		// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

		if(interfaz.modo == IGV_SELECCIONAR){

			glDisable(GL_LIGHTING); // desactiva la iluminacion de la escena
			glDisable(GL_DITHER);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_CULL_FACE);
			

			//Reinicio de colores
			interfaz.resetear_colores();

			//Aplico la cámara
			interfaz.camara.aplicar();

			// visualiza la escena
			interfaz.escena.visualizarVB();
			
			//Leo el pixel seleccionado
			GLubyte aux[3];
			glReadPixels(interfaz.cursorX, interfaz.alto_ventana - interfaz.cursorY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &aux);

			//Comparo los colores del vector  con el color del pixel y me quedo con la posición
			bool fin = false;
			for (int i = 0; (i < interfaz.escena.get_colores().size()) && !fin; i+=3) { 
				GLfloat ss = (GLfloat)aux[0];
				GLfloat s2 = (GLfloat)aux[1];
				GLfloat s3 = (GLfloat)aux[2];
				GLfloat l = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i] * 255.0);
				GLfloat l2 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 1] * 255.0);
				GLfloat l3 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 2] * 255.0);
				if (ss == l && s2 == l2 && s3 == l3) {
					interfaz.objeto_seleccionado = i;
					fin = true;
				}
				else {
					interfaz.objeto_seleccionado = -1; //si los colores no coinciden se marca
					
				}
			}

			
			//glutPostRedisplay();
			
			//pinto de otro color la parte seleccionada
			interfaz.pintar_seleccion();

			//vuelvo a activar la visualización
			interfaz.escena.set_modo(false);
			interfaz.modo = IGV_VISUALIZAR; // tras la selección hay que pulsar click derecho o sino se vuelve al modo selección 
			
			glutPostRedisplay();

			//Habilitar de nuevo la iluminación
			glEnable(GL_LIGHTING);
		
		}
		else {
			// aplica la cámara
			interfaz.camara.aplicar();
			// visualiza la escena
			interfaz.escena.visualizar();
			// refresca la ventana
			glutSwapBuffers();
		}
}

void igvInterfaz::set_glutIdleFunc() {



	///// Apartado D: incluir el código para animar el modelo de la manera más realista posible
	if (interfaz.animar) {

		if (interfaz.fin_primera_fase == 0) { //fase 0 = subir brazo
			if (interfaz.escena.getRotacion2_brazo_sup() > -220) {
				interfaz.escena.setRotacion2_brazo_sup(-1, true);
			}
			else {
				if (interfaz.escena.getRotacion_brazo_inf() != -90) {
					interfaz.escena.setRotacion_brazo_inf(-1, true);
				}
				else {
					interfaz.fin_primera_fase = 1;
				}
				
			}
			
		}
		if(interfaz.fin_primera_fase == 1){ //fase 1 = bajar brazo

			if (interfaz.escena.getRotacion2_brazo_sup() < -205) {
				interfaz.escena.setRotacion2_brazo_sup(1, true);
			}
			else {
				if (interfaz.escena.getRotacion2_brazo_sup() < -110) {
					interfaz.escena.setRotacion2_brazo_sup(1, true);
				}
				if (interfaz.escena.getRotacion_brazo_inf() < 0) {
					interfaz.escena.setRotacion_brazo_inf(0.8, true);
					interfaz.escena.setRotaciondedo1(1, true);
					interfaz.escena.setRotaciondedo2(-1, true);
					interfaz.escena.setRotaciondedo3(1, true);
				}
				else {
					interfaz.fin_primera_fase = 2;
				}
				
				
			}

		}

		if (interfaz.fin_primera_fase == 2) {
			if (interfaz.escena.getRotacion_cabezaY() < 30) {//bajo cabeza
				interfaz.escena.setRotacion_cabezaY(1,true);
			}
			if (interfaz.escena.getRotacionpierna_sup() < 70 ) { //subo pierna hasta limite
				interfaz.escena.setRotacionpierna_sup(1, true);
			}
			else {
				//cuando ya este arriba la pierna_sup empiezo a subir la pierna inf y pie
				if (interfaz.escena.getRotacionpierna_inf() < 40) {
					interfaz.escena.setRotacionpierna_inf(1, true);
					interfaz.escena.setRotacionpie(1, true);
				}
				else {
					interfaz.fin_primera_fase = 3; //indico que la fase de subida de la pierna ha finalizado
				}
			}
		}
		//bajo la pierna
		if(interfaz.fin_primera_fase == 3 ) {
			interfaz.escena.setRotacionpierna_sup(-1, true);
			interfaz.escena.setRotacionpierna_inf(-1, true);
			if (interfaz.escena.getRotacionpie() < 0) {
				interfaz.escena.setRotacionpie(-1, true);
			}
			
			interfaz.escena.setRotacion_cabezaY(-0.7,true);
		}
		glutPostRedisplay();
	}
	
}
//Método que reinicializa a las posiciones originales(solo aquellas que son modificadas por la animación)
void igvInterfaz::resetear() {
	interfaz.escena.setRotacion2_brazo_sup(-interfaz.escena.getRotacion2_brazo_sup(), true);
	interfaz.escena.setRotacion_brazo_inf(-interfaz.escena.getRotacion_brazo_inf(), true);
	interfaz.escena.setRotaciondedo1(-interfaz.escena.getRotaciondedo1(), true);
	interfaz.escena.setRotaciondedo2(-interfaz.escena.getRotaciondedo2(), true);
	interfaz.escena.setRotaciondedo3(-interfaz.escena.getRotaciondedo3(), true);
	interfaz.escena.setRotacionpierna_sup(-interfaz.escena.getRotacionpierna_sup(), true);
	interfaz.escena.setRotacionpierna_inf(-interfaz.escena.getRotacionpierna_inf(), true);
	interfaz.escena.setRotacionpie(-interfaz.escena.getRotacionpie(), true);
	interfaz.escena.setRotacion_cabezaY(-interfaz.escena.getRotacion_cabezaY(),true);
	interfaz.fin_primera_fase = 0;
	glutPostRedisplay();

	//Lanzamiento de pelota (físicas)
	interfaz.escena.setPelota(false);
	interfaz.escena.activarLanzamientoPelota();

}

void igvInterfaz::set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y) {
	if (boton == 0 && estado == GLUT_DOWN && !interfaz.cambio) {
		interfaz.boton_retenido = true;
		interfaz.modo = IGV_SELECCIONAR;
		interfaz.escena.set_modo(true);
		interfaz.cursorX = x;
		interfaz.cursorY = y;
	}

	glutPostRedisplay();
}

void igvInterfaz::set_glutMotionFunc(GLint x, GLint y) {
	int a = (int)(interfaz.objeto_seleccionado / 3);
	int f = -1;
	if (interfaz.objeto_seleccionado != -1 && interfaz.boton_retenido) {

		if (a >= 0 && a <= 3) { //intervalo de colores de cabeza
			a = 0;
		}

		switch (a)//se mira que parte del cuerpo se ha seleccionado y se hace la rotación
		{
		case 0://cabeza
			interfaz.escena.setRotacion_cabezaX(x + 90);//La rotación en x no tiene limitaciones
			if (y - interfaz.cursorY > -40 && y - interfaz.cursorY < 40) {//limitación de movimiento
				interfaz.escena.setRotacion_cabezaY(y - interfaz.cursorY,false);
			}
			break;
		case 4://brazo superior
			if (y - interfaz.cursorY > -180 && y - interfaz.cursorY < 0) {
				interfaz.escena.setRotacion2_brazo_sup(y - interfaz.cursorY, false);
			}
			if (x - interfaz.cursorX > 0 && x - interfaz.cursorX < 180) {
				interfaz.escena.setRotacion_brazo_sup(x - interfaz.cursorX,false);
			}
			break;
		case 5: //brazo inferio
			if (y - interfaz.cursorY > -90 && y - interfaz.cursorY < 90) {
				interfaz.escena.setRotacion_brazo_inf(y - interfaz.cursorY, false);
			}
			break;
		case 6://mano
			if (x - interfaz.cursorX > -90 && x - interfaz.cursorX < 90) {
				interfaz.escena.setRotacionMuneca(x - interfaz.cursorX, false);
			}
			break;
		case 7://dedo1
			if (x - interfaz.cursorX > -30 && x - interfaz.cursorX < 50) {
				interfaz.escena.setRotaciondedo1(x - interfaz.cursorX, false);
			}
			break;
		case 8://dedo2
			if (y - interfaz.cursorY > -50 && y - interfaz.cursorY < 30) {
				interfaz.escena.setRotaciondedo2(y - interfaz.cursorY, false);
			}
			break;
		case 9://dedo3
			if (y - interfaz.cursorY > -20 && y - interfaz.cursorY < 50) {
				interfaz.escena.setRotaciondedo3(y - interfaz.cursorY, false);
			}
			break;
			break;
		case 10://brazo superior izquierdo
			if (x - interfaz.cursorX > 0 && x - interfaz.cursorX < 180) {
				interfaz.escena.setRotacion_brazo_sup_izq(x - interfaz.cursorX, false);
			}
			break;
		case 11: //brazo inferio izquierdo
			if (y - interfaz.cursorY > -90 && y - interfaz.cursorY < 90) {
				interfaz.escena.setRotacion_brazo_inf_izq(y - interfaz.cursorY, false);
			}
			break;
		case 12://mano izquierdo
			if (x - interfaz.cursorX > -90 && x - interfaz.cursorX < 90) {
				interfaz.escena.setRotacionMunecaIzq(x - interfaz.cursorX, false);
			}
			break;
		case 13://dedo4
			if (x - interfaz.cursorX > -70 && x - interfaz.cursorX < 30) {
				interfaz.escena.setRotaciondedo4(x - interfaz.cursorX, false);
			}
			break;
		case 14://dedo5
			if (y - interfaz.cursorY > -30 && y - interfaz.cursorY < 70) {
				interfaz.escena.setRotaciondedo5(y - interfaz.cursorY, false);
			}
			break;
		case 15://dedo6
			if (y - interfaz.cursorY > -70 && y - interfaz.cursorY < 20) {
				interfaz.escena.setRotaciondedo6(y - interfaz.cursorY, false);
			}
			break;
		case 16://pierna sup
			if (y - interfaz.cursorY > -70 && y - interfaz.cursorY < 70) {
				interfaz.escena.setRotacionpierna_sup(y - interfaz.cursorY, false);
			}
			break;
		case 17://pierna inf
			if (y - interfaz.cursorY > 0 && y - interfaz.cursorY < 80) {
				interfaz.escena.setRotacionpierna_inf(y - interfaz.cursorY, false);
			}
			break;
		case 18://pie
			if (y - interfaz.cursorY > -40 && y - interfaz.cursorY < 40) {
				interfaz.escena.setRotacionpie(y - interfaz.cursorY, false);
			}
			break;
		case 19://pierna sup izq
			if (y - interfaz.cursorY > -70 && y - interfaz.cursorY < 70) {
				interfaz.escena.setRotacionpierna_sup_izq(y - interfaz.cursorY, false);
			}
			break;
		case 20://pierna inf izq
			if (y - interfaz.cursorY > 0 && y - interfaz.cursorY < 80) {
				interfaz.escena.setRotacionpierna_inf_izq(y - interfaz.cursorY, false);
			}
			break;
		case 21://pie izq
			if (y - interfaz.cursorY > -40 && y - interfaz.cursorY < 40) {
				interfaz.escena.setRotacionpie_izq(y - interfaz.cursorY, false);
			}
			break;

		default:
			break;
		}

	}
	//interfaz.modo = IGV_VISUALIZAR;
	glutPostRedisplay();
}

void igvInterfaz::resetear_colores() {

	//Reinicio de los colores

	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBaseCabeza(interfaz.escena.get_color_azul());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoSup(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoInf(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorMano(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo1(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo2(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo3(interfaz.escena.get_color_gris());

	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPierna(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPiernaInf(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPie(interfaz.escena.get_color_gris());

	//Lado Izquierdo del cuerpo

	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoSupIzq(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoInfIzq(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorManoIzq(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo4(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo5(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo6(interfaz.escena.get_color_gris());

	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPiernaIzq(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPiernaInfIzq(interfaz.escena.get_color_gris());
	interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPieIzq(interfaz.escena.get_color_gris());
}

void igvInterfaz::pintar_seleccion() {

	if (interfaz.objeto_seleccionado != -1) { // se comprueba que se haya seleccionado alguna caja
		int a = (int)(interfaz.objeto_seleccionado / 3);

		//Se pinta la parte del cuerpo seleccionada
		if (a >= 0 && a <= 3) //cabeza
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBaseCabeza(interfaz.escena.get_color_naranja());
		if (a == 4)//brazo superior
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoSup(interfaz.escena.get_color_naranja());
		if (a == 5)//brazo inferior
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoInf(interfaz.escena.get_color_naranja());
		if (a == 6)//mano
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorMano(interfaz.escena.get_color_naranja());
		if (a == 7)//dedo1
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo1(interfaz.escena.get_color_naranja());
		if (a == 8)//dedo2
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo2(interfaz.escena.get_color_naranja());
		if (a == 9)//dedo3
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo3(interfaz.escena.get_color_naranja());
		if (a == 10)//brazo_sup_izq
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoSupIzq(interfaz.escena.get_color_naranja());
		if (a == 11)//brazo_inf_izq
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorBrazoInfIzq(interfaz.escena.get_color_naranja());
		if (a == 12)//mano_izq
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorManoIzq(interfaz.escena.get_color_naranja());
		if (a == 13)//dedo4
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo4(interfaz.escena.get_color_naranja());
		if (a == 14)//dedo5
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo5(interfaz.escena.get_color_naranja());
		if (a == 15)//dedo6
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorDedo6(interfaz.escena.get_color_naranja());
		if (a == 16)//pierna
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPierna(interfaz.escena.get_color_naranja());
		if (a == 17)//pierna_Inf
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPiernaInf(interfaz.escena.get_color_naranja());
		if (a == 18)//pie
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPie(interfaz.escena.get_color_naranja());
		if (a == 19)//pierna izq
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPiernaIzq(interfaz.escena.get_color_naranja());
		if (a == 20)//pierna_Inf_izq
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPiernaInfIzq(interfaz.escena.get_color_naranja());
		if (a == 21)//pie izq
			interfaz.escena.getModelos()->Get_coloresRobot()->set_colorPieIzq(interfaz.escena.get_color_naranja());

		//interfaz.escena.set_modo(false);
	}

}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutIdleFunc(set_glutIdleFunc);

	glutMouseFunc(set_glutMouseFunc);
	glutMotionFunc(set_glutMotionFunc);
}

void igvInterfaz::Update(float dt) {

}
