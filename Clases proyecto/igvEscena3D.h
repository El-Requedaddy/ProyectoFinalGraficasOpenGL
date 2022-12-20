#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif
#include "Modelos.h"
#include "hitbox.h"
#include "igvPunto3D.h"
#include <vector>
#include <algorithm>
//#include <iostream>
#include "igvFuenteLuz.h"
#include "igvColor.h"
#include "Cubo.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include<stdlib.h>
#include<time.h>
#include "Juego.h"
#include <ctime>
#include <string> 
#include <cstring>
#include <iostream>

class igvEscena3D {
protected:
	//Atributos de luces
	float ang_foco, exp_foco, GB_dif, GB_esp; 
	float X, Y;
	bool foco_activo;

	//atributos que controlan la escena
	bool menu = true;
	bool juegoL = false; //el juego está en modo juego de disparar latas
	bool robot = false; //el juego está en modo jugar con el robot
	int estadoMenu;  //opcion seleccionada del menú, 0 es primera opcion, 1 es segunda opcion y 2 es tercera opcion

	////// Apartado C: añadir quí los atributos para el control de los grados de libertad del modelo
	float rotacionModeloCompleto;
	float rotacion_cabezaY;
	float rotacion_cabezaX;
	float rotacion_brazo_sup;
	float rotacion2_brazo_sup;
	float rotacion_brazo_inf;
	float rotacion_muneca;
	float rotacion_dedo1;
	float rotacion_dedo2;
	float rotacion_dedo3;
	float rotacion_brazo_sup_izq;
	float rotacion_brazo_inf_izq;
	float rotacion_muneca_izq;
	float rotacion_dedo4;
	float rotacion_dedo5;
	float rotacion_dedo6;
	float rotacion_pierna_sup;
	float rotacion_pierna_inf;
	float rotacion_pie;
	float rotacion_pierna_sup_izq;
	float rotacion_pierna_inf_izq;
	float rotacion_pie_izq;

	float escalado_lata;
	float traslación_lata;

	std::vector<GLfloat> color_grisOscuro;
	std::vector<GLfloat> color_rojo;
	std::vector<GLfloat> color_verdeAzul;
	std::vector<GLfloat> color_azul;
	std::vector<GLfloat> color_marron;
	std::vector<GLfloat> color_naranja;
	std::vector<GLfloat> color_negro;

	int pos_r, pos_a, pos_v, pos_g, pos_juego;
	// Otros atributos		
	bool ejes;
	Modelos* modelos;

	bool modo_act;//indicador de si estamos en modo selección
	std::vector<GLfloat> colores; //Array de los diferentes colores

	bool animacionPelota = true;
	bool lanzarPelota = false;

	//vector de hitboxes
	std::vector<hitbox*> hitboxes;
	hitbox hitboxDestino;

	//atributos de la trayectoria de la pelota
	float a;
	float movementSpeed = 0.2;
	float deltaTime = 0.1;
	igvPunto3D posicionPelota;
	igvPunto3D coordenadaFinalLanzamiento; //final 
	igvPunto3D coordenadaInicialLanzamiento;  //inicial

	//aparicion pelota especial
	int numLatasTiradas;
	int numeroGolpes;
	igvPunto3D coordenadasPelotaEspecial;
	hitbox pelotaEspecial;
	bool pelotaEspecialActivada;
	
	//control de aparición y desaparición de latas determinado por tiempo
	 //posiciones ocupadas, a partir del indice 30 las posiciones son de las latas || Tamaño real es 48
	std::vector<hitbox*> hitboxesPendientes; //hitboxes pendientes de dibujar tras renovar latas
	std::vector<int> hitboxes_a_borrar; //hitboxes pendientes de eliminar

	bool finPartida = true;
	bool iniciarPartida = false;

	bool Es_smooth = true;

	

public:

	juego juego;

	// Constructores por defecto y destructor
	igvEscena3D();
	~igvEscena3D();

	// método con las llamadas OpenGL para visualizar la escena
	void visualizar(void);
	void visualizarVB(void);//Método para la visualización en modo selección
	void visualizarMenu(void);


	//----------------------------------Métodos para la visualización de las diferentes partes de la escena-----------------------------
	void pintar_robot();
	void pintar_robotVB();
	void pintar_todo();
	
	//-------------------------------------MÉTODOS PARA INTERACTUAR CON LOS COLORES-------------------------

	//inserta en el vector de destino valores del vector color(inserta 'tam' valores a partir de la posición 'pos')
	void cambia_color(const std::vector<GLfloat>& color, std::vector<GLfloat>& destino, int& pos, int tam) {
			for (int i = 0; i < tam; i++) {
				destino[i] = color[pos];
				pos += 1;
			}
		}
	//Método que reinicia los vectores de colores a su color original
	void reinicio_colores() {
		color_verdeAzul[0] = 0.0;
		color_verdeAzul[1] = 0.5;
		color_verdeAzul[2] = 0.5;

		color_grisOscuro[0] = 0.1;
		color_grisOscuro[1] = 0.1;
		color_grisOscuro[2] = 0.1;

		color_azul[0] = 0.0;
		color_azul[1] = 0.0;
		color_azul[2] = 1.0;

		color_rojo[0] = 1.0;
		color_rojo[1] = 0.0;
		color_rojo[2] = 0.0;
	}


	void set_modo(bool a) {
		modo_act = a;
	}
	bool get_modo() {
		return modo_act;
	}

	std::vector<GLfloat> get_colores() {
		return colores;
	}

	std::vector<GLfloat> get_color_naranja() {
		return color_naranja;
	}

	std::vector<GLfloat> get_color_gris() {
		return color_grisOscuro;
	}

	std::vector<GLfloat> get_color_azul() {
		return color_azul;
	}

	Modelos* getModelos() {
		return modelos;
	}


	//------------------------MÉTODOS PARA GESTIONAR LOS GRADOS DE LIBERTAD DEL GRAFO DE ESCENA-----------------------------
	
	void setRotacion(float a) {
		rotacionModeloCompleto += a;
	}

	float getRotacion() {
		return rotacionModeloCompleto;
	}

	void setRotacion_cabezaY(float a,bool sum) {
		if (sum && (rotacion_cabezaY + a <= 30 && rotacion_cabezaY + a >= -30)) {
			rotacion_cabezaY += a;
		}
		if(!sum) {
			rotacion_cabezaY = a;
		}	
	}

	float getRotacion_cabezaY() {
		return rotacion_cabezaY;
	}

	float getRotacion_cabezaX() {
		return rotacion_cabezaX;
	}

	void setRotacion_cabezaX(float a) {
			rotacion_cabezaX = a;
	}

	//----Rotaciones de Brazo derecho-----

	void setRotacion_brazo_sup(float a, bool sum) {
		if (sum && (rotacion_brazo_sup + a <= 180 && rotacion_brazo_sup + a >= 0)) {
				rotacion_brazo_sup += a;
		}
		if (!sum) {
			rotacion_brazo_sup = a ;
		}
		
	}

	float getRotacion_brazo_sup() {
		return rotacion_brazo_sup;
	}

	void setRotacion2_brazo_sup(float a, bool sum) {
		if (sum) {
			rotacion2_brazo_sup += a;
		}
		if (!sum) {
			rotacion2_brazo_sup = a;
		}
	}

	float getRotacion2_brazo_sup() {
		return rotacion2_brazo_sup;
	}

	void setRotacion_brazo_inf(float a, bool sum) {
		if (sum && (rotacion_brazo_inf + a <= 90 && rotacion_brazo_inf + a >= -90)) {
			rotacion_brazo_inf += a;
		}
		if (!sum) {
			rotacion_brazo_inf = a;
		}
	}

	float getRotacion_brazo_inf() {
		return rotacion_brazo_inf;
	}

	float getRotacionMuneca() {
		return rotacion_muneca;
	}

	void setRotacionMuneca(float a, bool sum) {
		if (sum && (rotacion_muneca + a <= 90 && rotacion_muneca + a >= -90)) {
			rotacion_muneca += a;
		}
		if (!sum) {
			rotacion_muneca = a;
		}
	}

	float getRotaciondedo1() {
		return rotacion_dedo1;
	}

	void setRotaciondedo1(float a, bool sum) {
		if (sum && (rotacion_dedo1 + a <= 50 && rotacion_dedo1 + a >= -30)) {
			rotacion_dedo1 += a;
		}
		if (!sum) {
			rotacion_dedo1 = a;
		}
	}

	float getRotaciondedo2() {
		return rotacion_dedo2;
	}

	void setRotaciondedo2(float a, bool sum) {
		if (sum && (rotacion_dedo2 + a <= 30 && rotacion_dedo2 + a >= -50)) {
			rotacion_dedo2 += a;
		}
		if (!sum) {
			rotacion_dedo2 = a;
		}
	}

	float getRotaciondedo3() {
		return rotacion_dedo3;
	}

	void setRotaciondedo3(float a, bool sum) {
		if (sum && (rotacion_dedo3 + a <= 50 && rotacion_dedo3 + a >= -20)) {
			rotacion_dedo3 += a;
		}
		if (!sum) {
			rotacion_dedo3 = a;
		}
	}

	//-----------------------------------Rotaciones del brazo derecho

	void setRotacion_brazo_sup_izq(float a, bool sum) {
		if (sum && (rotacion_brazo_sup_izq + a <= 180 && rotacion_brazo_sup_izq + a >= 0)) {
			rotacion_brazo_sup_izq += a;
		}
		if (!sum) {
			rotacion_brazo_sup_izq = a;
		}
	}

	float getRotacion_brazo_sup_izq() {
		return rotacion_brazo_sup_izq;
	}

	void setRotacion_brazo_inf_izq(float a, bool sum) {
		if (sum && (rotacion_brazo_inf_izq + a <= 90 && rotacion_brazo_inf_izq + a >= -90)) {
			rotacion_brazo_inf_izq += a;
		}
		if (!sum) {
			rotacion_brazo_inf_izq = a;
		}
	}

	float getRotacion_brazo_inf_izq() {
		return rotacion_brazo_inf_izq;
	}

	float getRotacionMunecaIzq() {
		return rotacion_muneca_izq;
	}

	void setRotacionMunecaIzq(float a, bool sum) {
		if (sum && (rotacion_muneca_izq + a <= 90 && rotacion_muneca_izq + a >= -90)) {
			rotacion_muneca_izq += a;
		}
		if (!sum) {
			rotacion_muneca_izq = a;
		}
	}

	float getRotaciondedo4() {
		return rotacion_dedo4;
	}

	void setRotaciondedo4(float a, bool sum) {
		if (sum && (rotacion_dedo4 + a <= 30 && rotacion_dedo4 + a >= -70)) {
			rotacion_dedo4 += a;
		}
		if (!sum) {
			rotacion_dedo4 = a;
		}
	}

	float getRotaciondedo5() {
		return rotacion_dedo5;
	}

	void setRotaciondedo5(float a, bool sum) {
		if (sum && (rotacion_dedo5 + a <= 70 && rotacion_dedo5 + a >= -30)) {
			rotacion_dedo5 += a;
		}
		if (!sum) {
			rotacion_dedo5 = a;
		}
	}

	float getRotaciondedo6() {
		return rotacion_dedo6;
	}

	void setRotaciondedo6(float a, bool sum) {
		if (sum && (rotacion_dedo6 + a <= 20 && rotacion_dedo6 + a >= -70)) {
			rotacion_dedo6 += a;
		}
		if (!sum) {
			rotacion_dedo6 = a;
		}
	}

	//----------------------Rotaciones pierna derecha

	float getRotacionpierna_sup() {
		return rotacion_pierna_sup;
	}

	void setRotacionpierna_sup(float a, bool sum) {
		if (sum && (rotacion_pierna_sup + a <= 70 && rotacion_pierna_sup + a >= -70)) {
			rotacion_pierna_sup += a;
		}
		if (!sum) {
			rotacion_pierna_sup = a;
		}
	}

	float getRotacionpierna_inf() {
		return rotacion_pierna_inf;
	}

	void setRotacionpierna_inf(float a, bool sum) {
		if (sum && (rotacion_pierna_inf + a <= 80 && rotacion_pierna_inf + a >= 0)) {
			rotacion_pierna_inf += a;
		}
		if (!sum) {
			rotacion_pierna_inf = a;
		}
	}

	float getRotacionpie() {
		return rotacion_pie;
	}

	void setRotacionpie(float a, bool sum) {
		if (sum && (rotacion_pie + a <= 40 && rotacion_pie + a >= -40)) {
			rotacion_pie += a;
		}
		if (!sum) {
			rotacion_pie = a;
		}
	}

	//------PIERNA IZQ

	float getRotacionpierna_sup_izq() {
		return rotacion_pierna_sup_izq;
	}

	void setRotacionpierna_sup_izq(float a, bool sum) {
		if (sum && (rotacion_pierna_sup_izq + a <= 70 && rotacion_pierna_sup_izq + a >= -70)) {
			rotacion_pierna_sup_izq += a;
		}
		if (!sum) {
			rotacion_pierna_sup_izq = a;
		}
	}

	float getRotacionpierna_inf_izq() {
		return rotacion_pierna_inf_izq;
	}

	void setRotacionpierna_inf_izq(float a, bool sum) {
		if (sum && (rotacion_pierna_inf_izq + a <= 80 && rotacion_pierna_inf_izq + a >= 0)) {
			rotacion_pierna_inf_izq += a;
		}
		if (!sum) {
			rotacion_pierna_inf_izq = a;
		}
	}

	float getRotacionpie_izq() {
		return rotacion_pie_izq;
	}

	void setRotacionpie_izq(float a, bool sum) {
		if (sum && (rotacion_pie_izq + a <= 40 && rotacion_pie_izq + a >= -40)) {
			rotacion_pie_izq += a;
		}
		if (!sum) {
			rotacion_pie_izq = a;
		}
	}

	//------------------------------MODIFICADORES DE ASPECTOS DE LAS LUCES------------------------------------

	//Gestión posición de foco
	float GetX() const { return X; }
	void SetX(float val) { X += val; }
	float GetY() const { return Y; }
	void SetY(float val) { Y += val; }

	float GetAng_foco() const { return ang_foco; }
	void SetAng_foco(float val) { ang_foco += val; }
	float GetExp_foco() const { return exp_foco; }
	void SetExp_foco(float val) { exp_foco += val; }
	float GetGB_dif() const { return GB_dif; }
	void SetGB_dif(float val) { GB_dif += val; }
	float GetGB_esp() const { return GB_esp; }
	void SetGB_esp(float val) { GB_esp += val; }


	bool GetFoco_activo() const { return foco_activo; }
	void SetFoco_activo(bool val) { foco_activo = val; }


	bool get_ejes() { return ejes; };
	void set_ejes(bool _ejes) { ejes = _ejes; };
	//-----------------------------------------------------------------------------------------------------------------

	void setPelota(bool animado) {
		animacionPelota = animado;
	}

	bool getPelota() {
		return animacionPelota;
	}

	igvPunto3D getPosicionPelota() {
		return posicionPelota;
	}

	//Se cambia la hitbox destino utilizada al comparar hitboxes
	void setHitboxDestino(hitbox h) {
		hitboxDestino = h;
	}

	hitbox getPelotaEspecial() {
		return pelotaEspecial;
	}

	bool estaPelotaEspecial() {
		return pelotaEspecialActivada;
	}


	//------------------------------MÉTODOS RELATIVOS A LA LÓGICA DEL JUEGO------------------------------------

	//Devuelve el vector de hitboxes
	std::vector<hitbox*>& getHitboxes() { return hitboxes; }
	//Se busca la posición en el vector de una hitbox
	int buscarHitbox(hitbox &h);
	//Cálculo de la trayectoria de la pelota, se requieren como dos argumentos la hitbox de la pelota en primer lugar y la hitbox del objeto destino en segundo lugar
	void calculoTrayectoriaPelota(hitbox h1, hitbox h2);
	//Se activa el lanzamiento de la pelota, desencadenando el lanzamiento
	void activarLanzamientoPelota() { lanzarPelota = true; }
	//Se desactiva el lanzamiento de la pelota
	void desactivarLanzamientoPelota() { lanzarPelota = false; }
	//Comprobar si la pelota esta en modo lanzamiento o no, se devuelve su estado booleano
	bool getLanzandoPelota() { return lanzarPelota; }

	//Comprobamos colision entre dos objetos, esto se hace llevandolo a un supuesto plano 2d
	bool detectarColisiones(const hitbox &h1, hitbox &h2);
	//Actualiza la coordenada final destino a la que se lanza la pelota
	void actualizarCoordenadaFinal(const igvPunto3D &inicial);

	//Sustituimos lata eliminando la pasada de tiempo y encargándonos de guardar la nueva hitbox sustituta en el vector de pendientes para pintar a posterior sin alterar el pintado de objetos
	void sustituirLata(const int &i);
	//Se determina el color de la lata en funcion de su puntuacion. Se almacena el color por referencia
	void determinarColorLata(const int &i, std::vector<float> &colorin);
	//Crea una lata de modo que se añade al vector de hitboxes
	void crearLata();
	//Inicializa las latas y les asigna sus atributos requeridos
	void asignarLatasIniciales();
	//Se procesan las colisiones cuando se impacta con una lata u objeto y se procede con su desenlace
	void procesarColisiones(const hitbox &h1, hitbox h2);
	//Se interpola la trayectoria que va siguiendo la pelota de modo que se pueda alcanzar el objeto seleccionado
	void interpolacionTrayectoria(hitbox &h1, hitbox &h2);

	//Toda la creación de latas, sustitución y demás es llevado a cabo en este método
	void gestionarLatasEventos();
	//Toda la creación y asignación de pelota especial se lleva en este método
	void gestionarPelotaEspecialEventos();
	//Controla la aparición periódica de pelotas dentro de la escena
	void spawnPelotas();

	//Toda la creación de latas, sustitución y demás en la selección es llevado a cabo en este método 
	void gestionarLatasEventosVB();
	//Toda la creación y asignación en la selección de pelota especial se lleva en este método
	void gestionarPelotaEspecialEventosVB();
	//Limpia toda la memoria y variables del juego para empezar de nuevo
	void limpiarMemoriaYReinicio();

	//generación de textos que muestran puntuación y tiempo transcurrido
	void gestionarTextos();

	void IniciarPartida() {
		iniciarPartida = true;
		finPartida = false;
	}

	void acabarPartida() {
		finPartida = true;
	}

	//Método que dibuja texto de puntuación en pantalla
	void drawText(float x, float y, float z, const char* text);
	//-----------------------------------------------------------------------------------------------------------------
	//métodos que indican en que escena nos encontramos para limitar acciones entre diferentes escenas

	bool estaEnMenu() {
		return menu;
	}

	bool estaEnJuego() {
		return juegoL;
	}

	bool estaEnRobot() {
		return robot;
	}

	void setEnMenu(bool e) {
		menu = e;
	}

	void setEnJuego(bool e) {
		juegoL = e;
	}

	void setEnRobot(bool e) {
		robot = e;
	}

	int getEstadoMenu() {
		return estadoMenu;
	}

	void modificarEstadoMenu(int a) {
		if (estadoMenu == 2 && a == 1) {
			estadoMenu = 0;
		}
		else if (estadoMenu == 0 && a == -1) {
			estadoMenu = 2;
		} else if (a == 1 || a == -1){
			estadoMenu += a;
		}
		else {
			estadoMenu = 0;
		}
		std::cout << "El estado del menu es: " << estadoMenu << std::endl;
	}
	bool GetEs_smooth() const { return Es_smooth; }
	void SetEs_smooth(bool val) { Es_smooth = val; }
	float GetEscalado_lata() const { return escalado_lata; }
	void SetEscalado_lata(float val) { escalado_lata = val; }
	float GetTraslación_lata() const { return traslación_lata; }
	void SetTraslación_lata(float val) { traslación_lata = val; }
};

#endif
