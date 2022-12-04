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


	cil = new Cylinder(0.3, 0.3, 1, 40, 20, true);
	sph = new Sphere(1, 40, 40, true);
	cono = new Cylinder(1.5, 0, 2.3459236, 40, 40, true);
	colores_robot = new Colores();
}

Modelos::~Modelos() {
	/*delete [] cil;
	delete[] sph;
	delete[] cono;
	delete[] colores_robot;*/
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

void Modelos::cabeza(std::vector<GLfloat> color_rojo2, std::vector<GLfloat> color_Verde_Azul, std::vector<GLfloat> color_gris) {

	glPushMatrix();

		glPushMatrix();

			glPushMatrix();   //Transformaciones de la base de la cabeza
			glScaled(1.3, 1, 1);
			cubo(colores_robot->GetColor_base_cabeza().data());
			glPopMatrix();

			glPushMatrix();    //Transformaciones del ojo izquierda
			glTranslated(-1, 0.2, 1);
			glScaled(0.35, 0.35, 0.1);
			esfera(color_rojo2.data());
			glPopMatrix();

			glPushMatrix();  //Transformaciones del ojo derecho
			glTranslated(1, 0.2, 1);
			glScaled(0.35, 0.35, 0.1);
			esfera(color_rojo2.data());
			glPopMatrix();

			glPushMatrix();  //Transformaciones de la boca
			glTranslated(0, -0.3, 0);

				glPushMatrix(); //Transformaciones de la boca en sí(cubo)
				glTranslated(0, -0.3, 1);
				glScaled(1.4, 0.4, 0.5);
				glScaled(0.5, 0.5, 0.5);
				cubo(color_rojo2.data());
				glPopMatrix();

				glPushMatrix(); //Transformaciones del piercing(cilindro)
				glTranslated(0, -0.3, 1);
				glScaled(1.4, 0.4, 0.5);
				glRotated(90, 0, 1, 0);
				cilindro(color_Verde_Azul.data());
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

					glPushMatrix(); //Transformaciones de la bolita de la antenita
					glTranslated(0, 2.1, 0);
					glScaled(0.35, 0.35, 1);
					esfera(color_rojo2.data());
					glPopMatrix();

					glPushMatrix(); //Transformaciones de la bolita de la antenita
					glTranslated(0, 2.1, 0);
					glRotated(90, 0, 1, 0);
					glScaled(0.35, 0.35, 1);
					esfera(color_rojo2.data());
					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

		glPopMatrix();   //Fin cabeza


	glPopMatrix();
}

void Modelos::cuello() {

	glPushMatrix();
		glPushMatrix(); //Transformaciones de la bola de cuello
		glScaled(0.4, 0.4, 0.4);
		esfera(color_rojo.data());
		glPopMatrix();

		glPushMatrix(); //Transformaciones del cuello
		glTranslated(0, -0.5, 0);
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

void Modelos::brazo_superior(int lado) {
	std::vector<GLfloat> color_br_sup;
	if (lado == 0) {
		color_br_sup = colores_robot->GetColor_brazo_sup();
	}
	else {
		color_br_sup = colores_robot->GetColor_brazo_supIzq();
	}
	glPushMatrix();

			glPushMatrix(); //Transformaciones del brazo superior
			glTranslated(1.61, 0, 0);
			glRotated(-90, 0, 1, 0);
			glScaled(1.1, 1.1, 1.1);
			cilindro(color_br_sup.data());
			glPopMatrix();


	glPopMatrix();   //Fin brazo(sin hombro)
}

void Modelos::brazo_inferior(int lado) {
	std::vector<GLfloat> color_br_inf;
	if (lado == 0) {
		color_br_inf = colores_robot->GetColor_brazo_inf();
	}
	else {
		color_br_inf = colores_robot->GetColor_brazo_infIzq();
	}

			glPushMatrix();    //Transformaciones de brazo inferior

				glPushMatrix(); //Transformaciones de la bola del CoDo
				glScaled(0.4, 0.4, 0.4);
				esfera(color_rojo.data());
				glPopMatrix();

				glPushMatrix(); //Transformaciones del brazo inferior
				glTranslated(1.3, 0, 0);
				glRotated(-90, 0, 1, 0);
				glScaled(1.1, 1.1, 1.1);
				cilindro(color_br_inf.data());
				glPopMatrix();

			glPopMatrix();
}

void Modelos::mano(int lado) {
	std::vector<GLfloat> color_mano_;
	if (lado == 0) {
		color_mano_ = colores_robot->GetColor_mano();
	}
	else {
		color_mano_ = colores_robot->GetColor_manoIzq();
	}

	glPushMatrix();  //Transformaciones de la mano 

		glPushMatrix(); //Transformaciones de la bola de la muñeca
		glScaled(0.4, 0.4, 0.4);
		esfera(color_rojo.data());
		glPopMatrix();

		glPushMatrix(); //Transformaciones de la palma de la mano
		glTranslated(0.8, 0, 0);
		glRotated(-90, 0, 1, 0);
		glScaled(0.4, 0.4, 0.4);
		cono3D(color_mano_.data());
		glPopMatrix();

	glPopMatrix();
}

void Modelos::brazo() {

	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de principio Brazo
		glScaled(0.6, 0.6, 0.6);
		esfera(color_rojo.data());
		glPopMatrix();
		
	glPopMatrix();
}

void Modelos::dedo(int num_dedo) {
	std::vector<GLfloat> color_dedo;
	switch (num_dedo)
	{
	case 1:
		color_dedo = colores_robot->GetColor_dedo1();
		break;
	case 2:
		color_dedo = colores_robot->GetColor_dedo2();
		break;
	case 3:
		color_dedo = colores_robot->GetColor_dedo3();
		break;
	case 4:
		color_dedo = colores_robot->GetColor_dedo4();
		break;
	case 5:
		color_dedo = colores_robot->GetColor_dedo5();
		break;
	case 6:
		color_dedo = colores_robot->GetColor_dedo6();
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
		color_piernas_ = colores_robot->GetColor_pierna();
	}
	else {
		color_piernas_ = colores_robot->GetColor_piernaIzq();
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

void Modelos::piernas_inf(int lado) {
	std::vector<GLfloat> color_pierna_inferior;
	if (lado == 0) {
		color_pierna_inferior = colores_robot->GetColor_piernaInf();
	}
	else {
		color_pierna_inferior = colores_robot->GetColor_piernaInfIzq();
	}
	
	glPushMatrix();

		glPushMatrix(); //Transformaciones de la bola de principio de pierna
		glScaled(0.4, 0.4, 0.4);
		esfera(color_rojo.data());
		glPopMatrix();

		glPushMatrix(); //pierna inf
		glTranslated(0, -1.2, 0);   
		glRotated(90, 1, 0, 0);
		cilindro(color_pierna_inferior.data());
		glPopMatrix();

	glPopMatrix();
}

void Modelos::pies(int lado) {
	std::vector<GLfloat> color_pie_def;
	if (lado == 0) {
		color_pie_def = colores_robot->GetColor_pie();
	}
	else {
		color_pie_def = colores_robot->GetColor_pieIzq();
	}

	glPushMatrix();

	glPushMatrix(); //Transformaciones de la bola de principio de pierna
	glScaled(0.3, 0.3, 0.3);
	esfera(color_rojo.data());
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5, -0.3, 0);
	glScaled(1, 0.15, 0.5);
	cubo(color_pie_def.data());
	glPopMatrix();

	glPopMatrix();
}

void Modelos::Estanteria() {
	glPushMatrix();

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

	glPopMatrix();
}

void Modelos::Mostrador() {
	glPushMatrix();

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

	glPopMatrix();
}
void Modelos::visualizar() {

	Mostrador();

}