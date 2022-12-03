#include "Modelos.h"
#include <iostream>


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

	color_marron.push_back(0.1f);
	color_marron.push_back(0.0f);
	color_marron.push_back(0.0f);

	color_base_cabeza.push_back(0.0f);
	color_base_cabeza.push_back(0.0f);
	color_base_cabeza.push_back(1.0f);

	color_brazo_sup.push_back(0.1f);
	color_brazo_sup.push_back(0.1f);
	color_brazo_sup.push_back(0.1f);

	color_brazo_inf.push_back(0.1f);
	color_brazo_inf.push_back(0.1f);
	color_brazo_inf.push_back(0.1f);

	color_mano.push_back(0.1f);
	color_mano.push_back(0.1f);
	color_mano.push_back(0.1f);

	color_brazo_supIzq.push_back(0.1f);
	color_brazo_supIzq.push_back(0.1f);
	color_brazo_supIzq.push_back(0.1f);

	color_brazo_infIzq.push_back(0.1f);
	color_brazo_infIzq.push_back(0.1f);
	color_brazo_infIzq.push_back(0.1f);

	color_manoIzq.push_back(0.1f);
	color_manoIzq.push_back(0.1f);
	color_manoIzq.push_back(0.1f);

	color_dedo1.push_back(0.1f);
	color_dedo1.push_back(0.1f);
	color_dedo1.push_back(0.1f);

	color_dedo2.push_back(0.1f);
	color_dedo2.push_back(0.1f);
	color_dedo2.push_back(0.1f);

	color_dedo3.push_back(0.1f);
	color_dedo3.push_back(0.1f);
	color_dedo3.push_back(0.1f);

	color_dedo4.push_back(0.1f);
	color_dedo4.push_back(0.1f);
	color_dedo4.push_back(0.1f);

	color_dedo5.push_back(0.1f);
	color_dedo5.push_back(0.1f);
	color_dedo5.push_back(0.1f);

	color_dedo6.push_back(0.1f);
	color_dedo6.push_back(0.1f);
	color_dedo6.push_back(0.1f);


	color_pierna.push_back(0.1f);
	color_pierna.push_back(0.1f);
	color_pierna.push_back(0.1f);

	color_piernaInf.push_back(0.1f);
	color_piernaInf.push_back(0.1f);
	color_piernaInf.push_back(0.1f);

	color_pie.push_back(0.1f);
	color_pie.push_back(0.1f);
	color_pie.push_back(0.1f);

	color_piernaIzq.push_back(0.1f);
	color_piernaIzq.push_back(0.1f);
	color_piernaIzq.push_back(0.1f);

	color_piernaInfIzq.push_back(0.1f);
	color_piernaInfIzq.push_back(0.1f);
	color_piernaInfIzq.push_back(0.1f);

	color_pieIzq.push_back(0.1f);
	color_pieIzq.push_back(0.1f);
	color_pieIzq.push_back(0.1f);

	cil = new Cylinder(0.3, 0.3, 1, 40, 20, true);
	sph = new Sphere(1, 40, 40, true);
	cono = new Cylinder(1.5, 0, 2.3459236, 40, 40, true);
}


void Modelos::cilindro(GLfloat color_cilindro[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_cilindro);
	glColor3fv(color_cilindro);
	glPushMatrix();
	glScaled(1, 1, 2);
	cil->draw();
	glPopMatrix();
}

void Modelos::esfera(GLfloat color_esfera[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_esfera);
	//std::cout << color_esfera[0] << "-" << color_esfera[1] << "-" << color_esfera[2] << "-" << std::endl;
	glColor3fv(color_esfera);
	glPushMatrix();

	sph->draw();
	glPopMatrix();
}

void Modelos::cubo(GLfloat color_cubo[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_cubo);
	glColor3fv(color_cubo);
	glPushMatrix();

	glutSolidCube(2);

	glPopMatrix();
}

void Modelos::cono3D(GLfloat color_cono[]) {
	glMaterialfv(GL_FRONT, GL_EMISSION, color_cono);
	glColor3fv(color_cono);
	glPushMatrix();
	glTranslated(0, 0, 1.2);
	cono->draw();
	glPopMatrix();
}

void Modelos::cabeza(std::vector<GLfloat> color_azul, std::vector<GLfloat> color_rojo2, std::vector<GLfloat> color_Verde_Azul, std::vector<GLfloat> color_gris) {

	glPushMatrix();

		glPushMatrix();

			glPushMatrix();   //Transformaciones de la base de la cabeza
			glScaled(1.3, 1, 1);
			//cubo(color_azul.data());//azul
			cubo(color_base_cabeza.data());
			glPopMatrix();

			glPushMatrix();    //Transformaciones del ojo izquierda
			glTranslated(-1, 0.2, 1);
			glScaled(0.35, 0.35, 0.1);
			esfera(color_rojo2.data());//rojo
			glPopMatrix();

			glPushMatrix();  //Transformaciones del ojo derecho
			glTranslated(1, 0.2, 1);
			glScaled(0.35, 0.35, 0.1);
			esfera(color_rojo2.data());//rojo
			glPopMatrix();


			glPushMatrix();  //Transformaciones de la boca

			glTranslated(0, -0.3, 0);

				glPushMatrix(); //Transformaciones de la boca en sí(cubo)
				glTranslated(0, -0.3, 1);
				glScaled(1.4, 0.4, 0.5);
				glScaled(0.5, 0.5, 0.5);
				cubo(color_rojo2.data());//rojo
				glPopMatrix();

				glPushMatrix(); //Transformaciones del piercing(cilindro)
				glTranslated(0, -0.3, 1);
				glScaled(1.4, 0.4, 0.5);
				glRotated(90, 0, 1, 0);
				cilindro(color_Verde_Azul.data());//verde_Azul
				glPopMatrix();

			glPopMatrix();


			glPushMatrix();

				glPushMatrix(); //Transformaciones de la antenita
				glTranslated(0, 1.289, 0);
				glScaled(0.8, 0.6, 0.8);
				glRotated(90, 1, 0, 0);
				cilindro(color_gris.data());
				glPopMatrix();

				glPushMatrix();

			//	glRotated(rotacion_brazo_inf, 0, 1, 0);

					glPushMatrix(); //Transformaciones de la bolita de la antenita
					glTranslated(0, 2.1, 0);
					glScaled(0.35, 0.35, 1);
					esfera(color_rojo2.data());//rojo
					glPopMatrix();

					glPushMatrix(); //Transformaciones de la bolita de la antenita
					glTranslated(0, 2.1, 0);
					glRotated(90, 0, 1, 0);
					glScaled(0.35, 0.35, 1);
					esfera(color_rojo2.data());//rojo
					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();   //Fin cabeza


	glPopMatrix();
}

void Modelos::cuello(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_cuello) {

	glPushMatrix();
		glPushMatrix(); //Transformaciones de la bola de cuello
		glScaled(0.4, 0.4, 0.4);
		esfera(color_bola.data());
		glPopMatrix();

		glPushMatrix(); //Transformaciones del cuello
		glTranslated(0, -0.5, 0);   //(0, -1.7, 0)
		glRotated(90, 1, 0, 0);
		glScaled(1, 1, 0.65);
		cilindro(color_cuello.data());
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

void Modelos::brazo_superior(std::vector<GLfloat> color_brazo_sup_, int lado) {
	std::vector<GLfloat> color_br_sup;
	if (lado == 0) {
		color_br_sup = color_brazo_sup;
	}
	else {
		color_br_sup = color_brazo_supIzq;
	}
	glPushMatrix();

			glPushMatrix(); //Transformaciones del brazo superior
			glTranslated(1.61, 0, 0);
			glRotated(-90, 0, 1, 0);
			glScaled(1.1, 1.1, 1.1);
			cilindro(color_br_sup.data());//gris
			glPopMatrix();


	glPopMatrix();   //Fin brazo(sin hombro)
}

void Modelos::brazo_inferior(std::vector<GLfloat> color_brazo_inf_, std::vector<GLfloat> color_codo, int lado) {
	std::vector<GLfloat> color_br_inf;
	if (lado == 0) {
		color_br_inf = color_brazo_inf;
	}
	else {
		color_br_inf = color_brazo_infIzq;
	}

			glPushMatrix();    //Transformaciones de brazo inferior

				glPushMatrix(); //Transformaciones de la bola del CoDo
				glScaled(0.4, 0.4, 0.4);
				esfera(color_codo.data());//rojo
				glPopMatrix();

				glPushMatrix(); //Transformaciones del brazo inferior
				glTranslated(1.3, 0, 0);
				glRotated(-90, 0, 1, 0);
				glScaled(1.1, 1.1, 1.1);
				if(lado == 0) // si lado == 0 -> se pinta el color del brazo derecho
					cilindro(color_brazo_inf.data());
				else // se pinta color brazo izquierdo
					cilindro(color_br_inf.data());
				glPopMatrix();

			glPopMatrix();
}

void Modelos::mano(std::vector<GLfloat> color_muneca, std::vector<GLfloat> color_palma, int lado) {
	std::vector<GLfloat> color_mano_;
	if (lado == 0) {
		color_mano_ = color_mano;
	}
	else {
		color_mano_ = color_manoIzq;
	}

	glPushMatrix();  //Transformaciones de la mano 

					glPushMatrix(); //Transformaciones de la bola de la muñeca
					glScaled(0.4, 0.4, 0.4);
					esfera(color_muneca.data());//rojo
					glPopMatrix();

					glPushMatrix(); //Transformaciones de la palma de la mano
					glTranslated(0.8, 0, 0);
					glRotated(-90, 0, 1, 0);
					glScaled(0.4, 0.4, 0.4);
					cono3D(color_mano_.data());//gris
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

void Modelos::dedo(std::vector<GLfloat> color_dedo_, int num_dedo) {
	std::vector<GLfloat> color_dedo;
	switch (num_dedo)
	{
	case 1:
		color_dedo = color_dedo1;
		break;
	case 2:
		color_dedo = color_dedo2;
		break;
	case 3:
		color_dedo = color_dedo3;
		break;
	case 4:
		color_dedo = color_dedo4;
		break;
	case 5:
		color_dedo = color_dedo5;
		break;
	case 6:
		color_dedo = color_dedo6;
		break;
	default:
		break;
	}

	glPushMatrix();

	glPushMatrix();
	glScaled(0.3, 0.1, 0.1);
	cubo(color_dedo.data());//gris
	glPopMatrix();

	glPopMatrix();

}

void Modelos::articulacionDedo() {

	glPushMatrix(); //Transformaciones de la bola de dedo
	glScaled(0.2, 0.2, 0.2);
	esfera(color_rojo.data());
	glPopMatrix();

}

void Modelos::piernas(int lado) {
	std::vector<GLfloat> color_piernas_;
	if (lado == 0) {
		color_piernas_ = color_pierna;
	}
	else {
		color_piernas_ = color_piernaIzq;
	}

	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de principio de pierna
		glScaled(0.5, 0.5, 0.5);
		esfera(color_rojo.data());
		glPopMatrix();


		glPushMatrix(); //Transformaciones de pierna sup
		glTranslated(0, -1.2, 0);  
		glRotated(90, 1, 0, 0);
		glScaled(1.2, 1.2, 1.4);
		cilindro(color_piernas_.data());
		glPopMatrix();


	glPopMatrix();

}

void Modelos::piernas_inf(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_pierna_inf, int lado) {
	std::vector<GLfloat> color_pierna_inferior;
	if (lado == 0) {
		color_pierna_inferior = color_piernaInf;
	}
	else {
		color_pierna_inferior = color_piernaInfIzq;
	}
	
	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de principio de pierna
		glScaled(0.4, 0.4, 0.4);
		esfera(color_bola.data());//rojo
		glPopMatrix();


		glPushMatrix(); //pierna inf
		glTranslated(0, -1.2, 0);   //(0, -1.7, 0)
		glRotated(90, 1, 0, 0);
		cilindro(color_pierna_inferior.data());//gris
		glPopMatrix();


	glPopMatrix();
}

void Modelos::pies(std::vector<GLfloat> color_bola, std::vector<GLfloat> color_pie_, int lado) {
	std::vector<GLfloat> color_pie_def;
	if (lado == 0) {
		color_pie_def = color_pie;
	}
	else {
		color_pie_def = color_pieIzq;
	}

	glPushMatrix();

	glPushMatrix(); //Transformaciones de la bola de principio de pierna
	glScaled(0.3, 0.3, 0.3);
	esfera(color_bola.data());//rojo
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, -0.3, 0);
	glScaled(1, 0.15, 0.5);
	cubo(color_pie_def.data());//gris
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

void Modelos::Mostrador() {
	glPushMatrix();
	glScaled(4, 1.3, 0.9);
	cubo(color_marron.data());
	glPopMatrix();

	glPushMatrix();
	glTranslated(-4.7,0,-3.1);
	glRotated(90, 0, 1, 0);
	glScaled(4, 1.3, 1.1);
	cubo(color_marron.data());
	glPopMatrix();

	glPushMatrix();
	glTranslated(5.1, 0, -3.1);
	glRotated(-90, 0, 1, 0);
	glScaled(4, 1.3, 1.1);
	cubo(color_marron.data());
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 2, -7);
	glScaled(3.8, 4, 0.1);
	cubo(color_marron.data());
	glPopMatrix();
}
void Modelos::visualizar() {

	Mostrador();

	
	

}