#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

using namespace std;

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
							 // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz() {

}

igvInterfaz::~igvInterfaz() {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	//p0 = igvPunto3D(3.0, 2.0, 4);
	//r = igvPunto3D(0, 0, 0);
	//V = igvPunto3D(0, 1.0, 0);

	//p0 = igvPunto3D(6.0, 4.0, 8);

	p0 = igvPunto3D(6.0, 4.0, 8);
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
	animar = false;
	aux = 0;
	a = 1;
	fin_primera_fase = 0;
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

	modo = IGV_VISUALIZAR;
	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
		////// Apartado C: incluir aquí el cambio de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva 
		////// Apartado C: incluir aquí la modificación de los grados de libertad del modelo pulsando las teclas correspondientes

	case 'x': // activa/desactiva la visualizacion de los ejes
		interfaz.escena.set_ejes(interfaz.escena.get_ejes() ? false : true);
		break;
	case 'Q':
		interfaz.escena.setRotacion(-10);//todo el modelo
		break;
	case 'q':
		interfaz.escena.setRotacion(10);//todo el modelo
		break;
	case 'w':
		interfaz.escena.setRotacion_cabeza(10);//cabeza
		break;
	case 'W':
		interfaz.escena.setRotacion_cabeza(-10);//cabeza
		break;
	case 'e':
		interfaz.escena.setRotacion3_brazo_sup(10);//brazo supp
		break;
	case 'E':
		interfaz.escena.setRotacion3_brazo_sup(-10);
		break;
	case 'r':
		interfaz.escena.setRotacion_brazo_inf(10);//brazo inf
		break;
	case 'R':
		interfaz.escena.setRotacion_brazo_inf(-10);
		break;
	case 't':
		interfaz.escena.setRotacionMuneca(10);//muñeca
		break;
	case 'T':
		interfaz.escena.setRotacionMuneca(-10);
		break;
	case 'y':
		interfaz.escena.setRotaciondedo1(10);//dedo1
		break;
	case 'Y':
		interfaz.escena.setRotaciondedo1(-10);
		break;
	case 'u':
		interfaz.escena.setRotaciondedo2(10);//dedo2
		break;
	case 'U':
		interfaz.escena.setRotaciondedo2(-10);
		break; 
	case 'i':
		interfaz.escena.setRotaciondedo3(10);//dedo3
		break;
	case 'I':
		interfaz.escena.setRotaciondedo3(-10);
		break;
	case 'o':
		interfaz.escena.setRotacionpierna_sup(10);//pierna_sup
		break;
	case 'O':
		interfaz.escena.setRotacionpierna_sup(-10);
		break;
	case 'p':
		interfaz.escena.setRotacionpierna_inf(10);//pierna_inf
		break;
	case 'P':
		interfaz.escena.setRotacionpierna_inf(-10);
		break;
	case 'm':
		interfaz.escena.setRotacionpie(10);//pie
		break;
	case 'M':
		interfaz.escena.setRotacionpie(-10);
		break;
	case 's':
		interfaz.escena.setRotacion_brazo_sup_izq(10);//brazo supp
		break;
	case 'S':
		interfaz.escena.setRotacion_brazo_sup_izq(-10);
		break;
	case 'd':
		interfaz.escena.setRotacion_brazo_inf_izq(10);//brazo inf
		break;
	case 'D':
		interfaz.escena.setRotacion_brazo_inf_izq(-10);
		break;
	case 'f':
		interfaz.escena.setRotacionMunecaIzq(10);//muñeca
		break;
	case 'F':
		interfaz.escena.setRotacionMunecaIzq(-10);
		break;
	case 'g':
		interfaz.escena.setRotaciondedo1_izq(10);//dedo1
		break;
	case 'G':
		interfaz.escena.setRotaciondedo1_izq(-10);
		break;
	case 'h':
		interfaz.escena.setRotaciondedo2_izq(10);//dedo2
		break;
	case 'H':
		interfaz.escena.setRotaciondedo2_izq(-10);
		break;
	case 'j':
		interfaz.escena.setRotaciondedo3_izq(10);//dedo3
		break;
	case 'J':
		interfaz.escena.setRotaciondedo3_izq(-10);
		break;
	case 'k':
		interfaz.escena.setRotacion2_brazo_sup(10);//rotacion2_brazo_sup
		break;
	case 'K':
		interfaz.escena.setRotacion2_brazo_sup(-10);
		break;
	case 'l':
		interfaz.escena.setRotacionpierna_sup_izq(10);
		break;
	case 'L':
		interfaz.escena.setRotacionpierna_sup_izq(-10);
		break;
	case '<':
		interfaz.escena.setRotacionpierna_inf_izq(10);
		break;
	case '>':
		interfaz.escena.setRotacionpierna_inf_izq(-10);
		break;
	case 'z':
		interfaz.escena.setRotacionpie_izq(10);
		break;
	case 'Z':
		interfaz.escena.setRotacionpie_izq(-10);
		break;
	case 'a':
		if (interfaz.animar) interfaz.animar = false;
		else
			interfaz.animar = true;
		break;
	case 'n':
		interfaz.resetear();
		break;
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

			interfaz.camara.aplicar();
			// visualiza la escena
			interfaz.escena.visualizarVB();

			GLubyte aux[3];
			glReadPixels(interfaz.cursorX, interfaz.alto_ventana - interfaz.cursorY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &aux);

			
			for (int i = 0; i < 33; i+=3) { //colores rojos
				GLfloat ss = (GLfloat)aux[0];
				GLfloat s2 = (GLfloat)aux[1];
				GLfloat s3 = (GLfloat)aux[2];
				GLfloat l = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i] * 255.0);
				GLfloat l2 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 1] * 255.0);
				GLfloat l3 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 2] * 255.0);
				//std::cout << l << "-" << l2 << "-" << l3 << std::endl;
				if (ss == l && s2 == l2 && s3 == l3) {
					std::cout << "rojo";
					std::cout << (float)aux[0] << "-" << (float)aux[1] << "-" << (float)aux[2] << std::endl;
				}
			}



			//for (int i = 11; i < 12; i+=3) {//colores azul
			//	GLfloat ss = (GLfloat)aux[0];
			//	GLfloat s2 = (GLfloat)aux[1];
			//	GLfloat s3 = (GLfloat)aux[2];
			//	GLfloat l = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i] * 255.0);
			//	GLfloat l2 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 1] * 255.0);
			//	GLfloat l3 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 2] * 255.0);
			//	if (ss == l && s2 == l2 && s3 == l3){
			//		std::cout << "azul";
			//		std::cout << (float)aux[0] << "-" << (float)aux[1] << "-" << (float)aux[2]  << std::endl;

			//	}
			//}

			//for (int i = 12; i < 31; i += 3) {//colores gris
			//	GLfloat ss = (GLfloat)aux[0];
			//	GLfloat s2 = (GLfloat)aux[1];
			//	GLfloat s3 = (GLfloat)aux[2];
			//	GLfloat l = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i] * 255.0);
			//	GLfloat l2 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 1] * 255.0);
			//	GLfloat l3 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 2] * 255.0);
			//	if (ss == l && s2 == l2 && s3 == l3) {
			//		std::cout << "gris";
			//		std::cout << (float)aux[0] << "-" << (float)aux[1] << "-" << (float)aux[2] << std::endl;

			//	}
			//}
			//for (int i = 31; i < 32; i += 3) {//colores verdes
			//	GLfloat ss = (GLfloat)aux[0];
			//	GLfloat s2 = (GLfloat)aux[1];
			//	GLfloat s3 = (GLfloat)aux[2];
			//	GLfloat l = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i] * 255.0);
			//	GLfloat l2 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 1] * 255.0);
			//	GLfloat l3 = (GLfloat)(GLubyte)(interfaz.escena.get_colores()[i + 2] * 255.0);
			//	if (ss == l && s2 == l2 && s3 == l3) {
			//		std::cout << "verde";
			//		std::cout << (float)aux[0] << "-" << (float)aux[1] << "-" << (float)aux[2] << std::endl;

			//	}
			//}

			 //refresca la ventana
			glutSwapBuffers();
		
		}
		else {
			interfaz.camara.aplicar();
			// visualiza la escena
			//interfaz.escena.visualizar();
			interfaz.escena.visualizar();
			//interfaz.escena.pintar_robot();
			// refresca la ventana
			glutSwapBuffers();
		}
}

void igvInterfaz::set_glutIdleFunc() {
	///// Apartado D: incluir el código para animar el modelo de la manera más realista posible
	if (interfaz.animar) {
		if (interfaz.fin_primera_fase == 0) { //fase 0 = subir brazo
			if (interfaz.escena.getRotacion2_brazo_sup() > -220) {
				interfaz.escena.setRotacion2_brazo_sup(-1);
			}
			else {
				if (interfaz.escena.getRotacion_brazo_inf() != -90) {
					interfaz.escena.setRotacion_brazo_inf(-1);
				}
				else {
					interfaz.fin_primera_fase = 1;
				}
				
			}
			
		}
		if(interfaz.fin_primera_fase == 1){ //fase 1 = bajar brazo

			if (interfaz.escena.getRotacion2_brazo_sup() < -205) {
				interfaz.escena.setRotacion2_brazo_sup(1);
			}
			else {
				if (interfaz.escena.getRotacion2_brazo_sup() < -110) {
					interfaz.escena.setRotacion2_brazo_sup(1);
				}
				if (interfaz.escena.getRotacion_brazo_inf() < 0) {
					interfaz.escena.setRotacion_brazo_inf(0.8);
					interfaz.escena.setRotaciondedo1(1);
					interfaz.escena.setRotaciondedo2(-1);
					interfaz.escena.setRotaciondedo3(1);
				}
				else {
					interfaz.fin_primera_fase = 2;
				}
				
				
			}

		}

		if (interfaz.fin_primera_fase == 2) {
			if (interfaz.escena.getRotacion_cabeza() < 30) {//bajo cabeza
				interfaz.escena.setRotacion_cabeza(1);
			}
			if (interfaz.escena.getRotacionpierna_sup() < 70 ) { //subo pierna hasta limite
				interfaz.escena.setRotacionpierna_sup(1);
			}
			else {
				//cuando ya este arriba la pierna_sup empiezo a subir la pierna inf y pie
				if (interfaz.escena.getRotacionpierna_inf() < 40) {
					interfaz.escena.setRotacionpierna_inf(1);
					interfaz.escena.setRotacionpie(1);
				}
				else {
					interfaz.fin_primera_fase = 3; //indico que la fase de subida de la pierna ha finalizado
				}
			}
		}
		//bajo la pierna
		if(interfaz.fin_primera_fase == 3 ) {
			interfaz.escena.setRotacionpierna_sup(-1);
			interfaz.escena.setRotacionpierna_inf(-1);
			if (interfaz.escena.getRotacionpie() < 0) {
				interfaz.escena.setRotacionpie(-1);
			}
			
			interfaz.escena.setRotacion_cabeza(-0.7);
		}
		glutPostRedisplay();
	}
	
	
}
//Método que reinicializa a las posiciones originales aquellas que son modificadas por la animación
void igvInterfaz::resetear() {
	interfaz.escena.setRotacion2_brazo_sup(-interfaz.escena.getRotacion2_brazo_sup());
	interfaz.escena.setRotacion_brazo_inf(-interfaz.escena.getRotacion_brazo_inf());
	interfaz.escena.setRotaciondedo1(-interfaz.escena.getRotaciondedo1());
	interfaz.escena.setRotaciondedo2(-interfaz.escena.getRotaciondedo2());
	interfaz.escena.setRotaciondedo3(-interfaz.escena.getRotaciondedo3());
	interfaz.escena.setRotacionpierna_sup(-interfaz.escena.getRotacionpierna_sup());
	interfaz.escena.setRotacionpierna_inf(-interfaz.escena.getRotacionpierna_inf());
	interfaz.escena.setRotacionpie(-interfaz.escena.getRotacionpie());
	interfaz.escena.setRotacion_cabeza(-interfaz.escena.getRotacion_cabeza());
	interfaz.fin_primera_fase = 0;
	glutPostRedisplay();
	

}

void igvInterfaz::set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y) {

	// Apartado A: comprobar que se ha pulsado el botón izquierdo 

		// Apartado A: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
		// pasar a modo IGV_SELECCIONAR
	if (boton == 0 && estado == 1) {
		interfaz.boton_retenido = true;
		interfaz.modo = IGV_SELECCIONAR;
		interfaz.escena.set_modo(true);
		// Apartado A: guardar el pixel pulsado
		interfaz.cursorX = x;
		interfaz.cursorY = y;

	}
	// Apartado A: renovar el contenido de la ventana de vision 

}

void igvInterfaz::set_glutMotionFunc(GLint x, GLint y) {

	/*if (interfaz.boton_retenido && interfaz.objeto_seleccionado != -1) {
		interfaz.escena.getCajas()[interfaz.objeto_seleccionado]->setGrado(x);
	}
	glutPostRedisplay();*/
	
}



void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutIdleFunc(set_glutIdleFunc);

	glutMouseFunc(set_glutMouseFunc);
	glutMotionFunc(set_glutMotionFunc);
}

