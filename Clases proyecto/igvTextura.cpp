#include "igvTextura.h"
#include <iostream>

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
	if (imagen) {
		//glGenTextures(1, &idTextura);
		glBindTexture(GL_TEXTURE_2D, idTextura);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imagen->w, imagen->h, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->pixels);

		glBindTexture(GL_TEXTURE_2D, idTextura);
		
	}
	
}
//
//void igvTextura::cambiar_id() {
//	glBindTexture(GL_TEXTURE_2D, 0);
//}

void igvTextura::vaciar_imagen() {
	SDL_FreeSurface(imagen);
}
void igvTextura::aplicar(void) {
	std::cout << idTextura << std::endl;
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
