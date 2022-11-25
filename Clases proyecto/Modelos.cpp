#include "Modelos.h"


Modelos::Modelos() :h(1), b(3){

	color_rojo.push_back(1.0f);
	color_rojo.push_back(0.0f);
	color_rojo.push_back(0.0f);
	color_rojo.push_back(0.0f);

	color_verdeAzul.push_back(0.0f);
	color_verdeAzul.push_back(0.5f);
	color_verdeAzul.push_back(0.5f);

	color_grisOscuro.push_back(0.1f);
	color_grisOscuro.push_back(0.1f);
	color_grisOscuro.push_back(0.1f);

	color_azul.push_back(0.0f);
	color_azul.push_back(0.0f);
	color_azul.push_back(1.0f);

	cil = new Cylinder(0.3, 0.3, 1, 40, 20, true);
	sph = new Sphere(1, 40, 40, true);
	cono = new Cylinder(1.5, 0, 2.3459236, 40, 40, true);
}


void Modelos::cilindro(GLfloat color_cilindro[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_cilindro);

	glPushMatrix();
	glScaled(1, 1, 2);
	cil->draw();
	glPopMatrix();
}

void Modelos::esfera(GLfloat color_esfera[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_esfera);

	glPushMatrix();

	sph->draw();
	glPopMatrix();
}

void Modelos::cubo(GLfloat color_cubo[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_cubo);

	glPushMatrix();

	glutSolidCube(2);

	glPopMatrix();
}

void Modelos::cono3D(GLfloat color_cono[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_cono);

	glPushMatrix();
	glTranslated(0, 0, 1.2);
	cono->draw();
	glPopMatrix();
}

void Modelos::cabeza() {

	glPushMatrix();

		glPushMatrix();

			glPushMatrix();   //Transformaciones de la base de la cabeza
			glScaled(1.3, 1, 1);
			cubo(color_azul.data());
			glPopMatrix();

			glPushMatrix();    //Transformaciones del ojo izquierda
			glTranslated(-1, 0.2, 1);
			glScaled(0.35, 0.35, 0.1);
			esfera(color_rojo.data());
			glPopMatrix();

			glPushMatrix();  //Transformaciones del ojo derecho
			glTranslated(1, 0.2, 1);
			glScaled(0.35, 0.35, 0.1);
			esfera(color_rojo.data());
			glPopMatrix();


			glPushMatrix();  //Transformaciones de la boca

			glTranslated(0, -0.3, 0);

				glPushMatrix(); //Transformaciones de la boca en sí(cubo)
				glTranslated(0, -0.3, 1);
				glScaled(1.4, 0.4, 0.5);
				glutSolidCube(1);
				glPopMatrix();

				glPushMatrix(); //Transformaciones del piercing(cilindro)
				glTranslated(0, -0.3, 1);
				glScaled(1.4, 0.4, 0.5);
				glRotated(90, 0, 1, 0);
				cilindro(color_verdeAzul.data());
				glPopMatrix();

			glPopMatrix();


			glPushMatrix();

				glPushMatrix(); //Transformaciones de la antenita
				glTranslated(0, 1.289, 0);
				glScaled(0.8, 0.6, 0.8);
				glRotated(90, 1, 0, 0);
				cilindro(color_grisOscuro.data());
				glPopMatrix();

				glPushMatrix();

			//	glRotated(rotacion_brazo_inf, 0, 1, 0);

					glPushMatrix(); //Transformaciones de la bolita de la antenita
					glTranslated(0, 2.1, 0);
					glScaled(0.35, 0.35, 1);
					esfera(color_rojo.data());
					glPopMatrix();

					glPushMatrix(); //Transformaciones de la bolita de la antenita
					glTranslated(0, 2.1, 0);
					glRotated(90, 0, 1, 0);
					glScaled(0.35, 0.35, 1);
					esfera(color_rojo.data());
					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();   //Fin cabeza


	glPopMatrix();
}

void Modelos::cuello() {

	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de cuello
		//glTranslated(0, -1.2, 0);
		glScaled(0.4, 0.4, 0.4);
		esfera(color_rojo.data());
		glPopMatrix();

		glPushMatrix(); //Transformaciones del cuello
		glTranslated(0, -0.5, 0);   //(0, -1.7, 0)
		glRotated(90, 1, 0, 0);
		glScaled(1, 1, 0.65);
		cilindro(color_grisOscuro.data());
		glPopMatrix();

	glPopMatrix();

}

void Modelos::torso() {

	glPushMatrix();

		glPushMatrix(); //Transformaciones del torso
		glScaled(1.5, 1.723, 1);
		cubo(color_azul.data());
		glPopMatrix();

		glPushMatrix(); //Transformaciones de la parte superior de torso que conecta con cuello
		glTranslated(0, 1.8, 0);
		glScaled(0.25, 0.25, 0.75);
		esfera(color_rojo.data());
		glPopMatrix();

		glPushMatrix(); //Transformaciones de la parte superior de torso que conecta con cuello
		glTranslated(0, 1.8, 0);
		glRotated(90, 0, 1, 0);
		glScaled(0.25, 0.25, 0.75);
		esfera(color_rojo.data());
		glPopMatrix();

	glPopMatrix();
}

void Modelos::brazo_superior() {
	glPushMatrix();

			glPushMatrix(); //Transformaciones del brazo superior
			glTranslated(1.61, 0, 0);
			glRotated(-90, 0, 1, 0);
			glScaled(1.1, 1.1, 1.1);
			cilindro(color_grisOscuro.data());
			glPopMatrix();


	glPopMatrix();   //Fin brazo(sin hombro)
}

void Modelos::brazo_inferior() {

	glPushMatrix();    //Transformaciones de brazo inferior

				glPushMatrix(); //Transformaciones de la bola del CoDo
				glScaled(0.4, 0.4, 0.4);
				esfera(color_rojo.data());
				glPopMatrix();

				glPushMatrix(); //Transformaciones del brazo inferior
				glTranslated(1.3, 0, 0);
				glRotated(-90, 0, 1, 0);
				glScaled(1.1, 1.1, 1.1);
				cilindro(color_grisOscuro.data());
				glPopMatrix();

			glPopMatrix();
}

void Modelos::mano() {

	glPushMatrix();  //Transformaciones de la mano 

					glPushMatrix(); //Transformaciones de la bola de la muñeca
					glScaled(0.4, 0.4, 0.4);
					esfera(color_rojo.data());
					glPopMatrix();

					glPushMatrix(); //Transformaciones de la palma de la mano
					glTranslated(0.8, 0, 0);
					glRotated(-90, 0, 1, 0);
					glScaled(0.4, 0.4, 0.4);
					cono3D(color_grisOscuro.data());
					glPopMatrix();

			

				glPopMatrix();
}

void Modelos::brazo() {

	glPushMatrix();

	//glRotated(-45, 0, 0, 1);

		glPushMatrix(); //Transformaciones de la bola de principio Brazo
		glScaled(0.6, 0.6, 0.6);
		esfera(color_rojo.data());
		glPopMatrix();
		
	glPopMatrix();
}

void Modelos::dedo() {

	glPushMatrix();

	glPushMatrix();
	glScaled(0.3, 0.1, 0.1);
	cubo(color_grisOscuro.data());
	glPopMatrix();

	glPopMatrix();

}

void Modelos::articulacionDedo() {

	glPushMatrix(); //Transformaciones de la bola de dedo
	glScaled(0.2, 0.2, 0.2);
	esfera(color_rojo.data());
	glPopMatrix();

}

void Modelos::piernas() {
	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de principio de pierna
		glScaled(0.5, 0.5, 0.5);
		esfera(color_rojo.data());
		glPopMatrix();


		glPushMatrix(); //Transformaciones de pierna sup
		glTranslated(0, -1.2, 0);   //(0, -1.7, 0)
	
		glRotated(90, 1, 0, 0);
		glScaled(1.2, 1.2, 1.4);
		cilindro(color_grisOscuro.data());
		glPopMatrix();


	glPopMatrix();

}

void Modelos::piernas_inf() {
	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de principio de pierna
		glScaled(0.4, 0.4, 0.4);
		esfera(color_rojo.data());
		glPopMatrix();


		glPushMatrix(); 
		glTranslated(0, -1.2, 0);   //(0, -1.7, 0)

		glRotated(90, 1, 0, 0);
		//glScaled(1.3, 1.3, 1.8);
		cilindro(color_grisOscuro.data());
		glPopMatrix();


	glPopMatrix();
}

void Modelos::pies() {
	glPushMatrix();

	glPushMatrix(); //Transformaciones de la bola de principio de pierna
	glScaled(0.3, 0.3, 0.3);
	esfera(color_rojo.data());
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, -0.3, 0);
	//glRotated(90, 0, 0, 1);
	glScaled(1, 0.15, 0.5);
	cubo(color_grisOscuro.data());
	glPopMatrix();




	glPopMatrix();
}

void Modelos::Estanteria() {
	//Lado izq
	glPushMatrix();
	glScaled(0.1, 3, 0.7);
	cubo(color_grisOscuro.data());
	glPopMatrix();

	 //Lado der
	glPushMatrix();
	glTranslated(8, 0, 0);
	glScaled(0.1, 3, 0.7);
	cubo(color_grisOscuro.data());
	glPopMatrix();

	//Lado arriba
	glPushMatrix();
	glTranslated(4, 3.1, 0);
	glScaled(4.1, 0.1, 0.7);
	cubo(color_grisOscuro.data());
	glPopMatrix();

	//lado abajo
	glPushMatrix();
	glTranslated(4, -3.1, 0);
	glScaled(4.1, 0.1, 0.7);
	cubo(color_grisOscuro.data());
	glPopMatrix();

	//Balda 2
	glPushMatrix();
	glTranslated(4, 1, 0);
	glScaled(4, 0.1, 0.7);
	cubo(color_grisOscuro.data());
	glPopMatrix();

	//Balda 3
	glPushMatrix();
	glTranslated(4, -1, 0);
	glScaled(4, 0.1, 0.7);
	cubo(color_grisOscuro.data());
	glPopMatrix();
}

void Modelos::visualizar() {

	//glPushMatrix();
	//glRotated(90, 1, 0, 0);
	//glScaled(0.8, 1, 1);
	//cilindro(color_azul.data());
	//glPopMatrix();

	glPushMatrix();
	glTranslated(-2, 0, 0);
	//glRotated(getRotacion(), 0, 1, 0);
	glScaled(0.87, 1, 1);
	Estanteria();
	glPopMatrix();

	
	

}