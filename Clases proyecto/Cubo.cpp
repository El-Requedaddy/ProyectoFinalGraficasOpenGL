#include "Cubo.h"

Cubo::Cubo() {


}

Cubo::~Cubo() {

}

void Cubo::visualizar() {
	float ini_x = 0, ini_y = 0, ini_z = 0, tam_x = 2, tam_y = 2, tam_z = 2, div_x = 50, div_y = 50, div_z = 50;
	//------------------------------------------------------------------------------------------------

	//EN ALGUNOS TEXCOORD SE PONE 1 - POSICIÓN PARA EVITAR QUE LAS IMÁGENES SE VEAN EN MODO ESPEJO

		//CARA ABAJO
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	for (int x = 0; x < div_x; x++) {
		for (int z = 0; z < div_z; z++) {

			glTexCoord2d(ini_x / tam_x, 1 - ini_z / tam_z);
			glVertex3f(ini_x, ini_y, ini_z);

			glTexCoord2f(ini_x / tam_x, 1 -  (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(ini_x, ini_y, ini_z + tam_z / div_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, 1 - (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(ini_x + tam_x / div_x, ini_y, ini_z + tam_z / div_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, 1 - ini_z / tam_z);
			glVertex3f(ini_x + tam_x / div_x, ini_y, ini_z);

			ini_z += tam_z / div_z;
		}
		ini_z = 0;
		ini_x += tam_x / div_x;
	}
	glEnd();
	ini_x = 0;
	ini_z = 0;
	//CARA FRONTAL

	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	for (int x = 0; x < div_x; x++) {
		for (int z = 0; z < div_y; z++) {

			glTexCoord2f(ini_x / tam_x, 1 - ini_y / tam_y);
			glVertex3f(ini_x, ini_y, tam_z);

			glTexCoord2f(ini_x / tam_x, 1 - (ini_y + tam_y / div_y) / tam_y);
			glVertex3f(ini_x, ini_y + tam_y / div_y, tam_z);

			glTexCoord2f( (ini_x + tam_x / div_x) / tam_x, 1 - (ini_y + tam_y / div_y) / tam_y);
			glVertex3f(ini_x + tam_x / div_x, ini_y + tam_y / div_y, tam_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, 1 - ini_y / tam_y);
			glVertex3f(ini_x + tam_x / div_x, ini_y, tam_z);

			ini_y += tam_y / div_y;
		}
		ini_y = 0;
		ini_x += tam_x / div_x;
	}
	glEnd();

	ini_x = 0;
	ini_y = 0;

	//CARA DERECHA

	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);

	for (int x = 0; x < div_z; x++) {
		for (int z = 0; z < div_y; z++) {

			glTexCoord2f(ini_y / tam_y, 1 - ini_z / tam_z);
			glVertex3f(tam_x, ini_y, ini_z);

			glTexCoord2f( (ini_y + tam_y / div_y) / tam_y, 1 - ini_z / tam_z);
			glVertex3f(tam_x, ini_y + tam_y / div_y, ini_z);

			glTexCoord2f((ini_y + tam_y / div_y) / tam_y, 1 - (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(tam_x, ini_y + tam_y / div_y, ini_z + tam_z / div_z);

			glTexCoord2f(ini_y / tam_y, 1 - (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(tam_x, ini_y, ini_z + tam_z / div_z);

			ini_y += tam_y / div_y;
		}
		ini_y = 0;
		ini_z += tam_z / div_z;
	}
	glEnd();
	ini_z = 0;
	ini_y = 0;

	//CARA IZQ

	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	for (int x = 0; x < div_z; x++) {
		for (int z = 0; z < div_y; z++) {

			glTexCoord2f(ini_y / tam_y, ini_z / tam_z);
			glVertex3f(ini_x, ini_y, ini_z);

			glTexCoord2f((ini_y + tam_y / div_y) / tam_y, ini_z / tam_z);
			glVertex3f(ini_x, ini_y + tam_y / div_y, ini_z);

			glTexCoord2f((ini_y + tam_y / div_y) / tam_y, (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(ini_x, ini_y + tam_y / div_y, ini_z + tam_z / div_z);

			glTexCoord2f(ini_y / tam_y, (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(ini_x, ini_y, ini_z + tam_z / div_z);

			ini_y += tam_y / div_y;
		}
		ini_y = 0;
		ini_z += tam_z / div_z;
	}
	glEnd();
	ini_z = 0;
	ini_y = 0;

	//CARA TRASERA	

	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	for (int x = 0; x < div_x; x++) {
		for (int z = 0; z < div_y; z++) {

			glTexCoord2f(ini_x / tam_x, ini_y / tam_y);
			glVertex3f(ini_x, ini_y, ini_z);

			glTexCoord2f(ini_x / tam_x, (ini_y + tam_y / div_y) / tam_y);
			glVertex3f(ini_x, ini_y + tam_y / div_y, ini_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, (ini_y + tam_y / div_y) / tam_y);
			glVertex3f(ini_x + tam_x / div_x, ini_y + tam_y / div_y, ini_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, ini_y / tam_y);
			glVertex3f(ini_x + tam_x / div_x, ini_y, ini_z);

			ini_y += tam_y / div_y;
		}
		ini_y = 0;
		ini_x += tam_x / div_x;
	}
	glEnd();
	ini_x = 0;
	ini_y = 0;

	glBegin(GL_QUADS);//cara arriba
	glNormal3f(0, 1, 0);
	for (int x = 0; x < div_x; x++) {
		for (int z = 0; z < div_z; z++) {

			glTexCoord2d(ini_x / tam_x, ini_z / tam_z);
			glVertex3f(ini_x, tam_y, ini_z);

			glTexCoord2f(ini_x / tam_x, (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(ini_x, tam_y, ini_z + tam_z / div_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, (ini_z + tam_z / div_z) / tam_z);
			glVertex3f(ini_x + tam_x / div_x, tam_y, ini_z + tam_z / div_z);

			glTexCoord2f((ini_x + tam_x / div_x) / tam_x, ini_z / tam_z);
			glVertex3f(ini_x + tam_x / div_x, tam_y, ini_z);

			ini_z += tam_z / div_z;
		}
		ini_z = 0;
		ini_x += tam_x / div_x;
	}
	glEnd();
	ini_x = 0;
	ini_z = 0;

}
