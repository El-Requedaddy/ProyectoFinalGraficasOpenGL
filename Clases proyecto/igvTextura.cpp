#include "igvTextura.h"

// Metodos constructores y destructor

igvTextura::igvTextura(char* fichero) {
	ancho = 0;
	alto = 0;

	imagen = NULL;

	glEnable(GL_TEXTURE_2D);
	if (!glIsTexture(idTextura)) {

		imagen = IMG_Load(fichero);
		if (!imagen)
		{
			/* Fallo de carga de la imagen */
			printf("Error al cargar la imagen: %s\n", IMG_GetError());
			return;

		}
		/* Muestra alguna información sobre la imagen */
		printf("Cargando %s: %dx%d %dbpp\n", fichero,
			imagen->w, imagen->h, imagen->format->BitsPerPixel);

	}
}
void igvTextura::pre_aplicar(){
		// Apartado F: Añadir aquí el código para cargar como textura OpenGL la imagen */
	    //	- Generar el identificador de textura y asignarlo al atributo idTextura (glGenTextures)
		//	- Enlazar el identificador creado a GL_TEXTURE_2D (glBindTexture)
		//  - Especificar la textura, asignádole como textura el array imagen (glTexImage2D)
		//  - Modo de aplicación de la textura (glTexEnvf)
		//	- Parámetros de la textura: repetición y filtros (glTexParameteri)
		
	if (imagen) {
		glGenTextures(1, &idTextura);
		glBindTexture(GL_TEXTURE_2D, idTextura);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imagen->w, imagen->h, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->pixels);


		glBindTexture(GL_TEXTURE_2D, idTextura);

		/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glEnable(GL_TEXTURE_2D);*/


		
	}
	
}

void igvTextura::cambiar_id() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void igvTextura::vaciar_imagen() {
	SDL_FreeSurface(imagen);
}
void igvTextura::aplicar(void) {
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
