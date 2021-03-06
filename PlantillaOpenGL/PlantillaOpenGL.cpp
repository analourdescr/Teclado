// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace std;

// Variables de posición X,Y
float posicionXTriangulo = 0.0f;
float posicionYTriangulo = 0.0f;
float angulo1 = 0;
float xTriangulo = 0;
float yTriangulo = 0;

// Enum de la Dirección
enum Direccion {Izquierda, Derecha, Arriba, Abajo};
Direccion direccionHorizontalTriangulo = Izquierda;
Direccion direccionVerticalTriangulo = Arriba;

void dibujar();
void actualizar();
void dibujarTriangulo();
void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	// Creamos una ventana
	GLFWwindow *window;

	// Si no se puede inicializar glfw, finalizamos la ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// Si se pudo iniciar GLFW, entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);
	
	// Si no podemos iniciar la ventana, terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto, activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL << std::endl;

	glfwSetKeyCallback(window, teclado_callback);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(.23, 0.3, 0.3, 1);

		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		actualizar();
		dibujar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

void dibujar()
{
	dibujarTriangulo();
}

void actualizar()
{
	// Rotación
	/*if (angulo1 >= 360*100)
	{
		angulo1 += 0.0f;
	}
	else angulo1 += 0.1f;

	// Dirección Horizontal
	if (direccionHorizontalTriangulo == Direccion::Izquierda)
	{
		if (posicionXTriangulo > -0.79f)
		{
			posicionXTriangulo -= 0.001f;
		}
		else {
			direccionHorizontalTriangulo = Direccion::Derecha;
		}
	}else
	if (direccionHorizontalTriangulo == Direccion::Derecha)
	{
		if (posicionXTriangulo < 0.79f)
		{
			posicionXTriangulo += 0.001f;
		}
		else {
			direccionHorizontalTriangulo = Direccion::Izquierda;
		}
	}

	// Dirección Vertical
	if (direccionVerticalTriangulo == Direccion::Abajo)
	{
		if (posicionYTriangulo > -0.79f)
		{
			posicionYTriangulo -= 0.0005f;
		}
		else {
			direccionVerticalTriangulo = Direccion::Arriba;
		}
	}
	else
		if (direccionVerticalTriangulo == Direccion::Arriba)
		{
			if (posicionYTriangulo < 0.79f)
			{
				posicionYTriangulo += 0.0005f;
			}
			else {
				direccionVerticalTriangulo = Direccion::Abajo;
			}
		}*/
}

void dibujarTriangulo()
{
	/*
	// Utilización de la matriz identidad
	glPushMatrix();

	//Transformaciones
		
		// 1. Traslación
		glTranslatef(-0.25f, 0.0f, 0.0f);
		glTranslatef(0.25, .5f, 0.0f);

		// 2. Escala
		glScalef(0.1f, 0.1f, 0.1f);
		glScalef(10, 10, 10);

		// 3. Rotación
		glRotatef(90, 0.0f, 0, 1.0f);

			// Dibujado de los vértices
			glBegin(GL_TRIANGLES);
				glColor3f(1.0f, 0.8f, 0.0f);
				glVertex3f(-0.4, -0.4f, 0);
				glVertex3f(0.4, -0.4f, 0);
				glVertex3f(0, 0.4f, 0);
			glEnd();
		
	//Soltado de la Matriz
	glPopMatrix();
	*/

	// Utilización de la matriz identidad
	/*glPushMatrix();
	
		glTranslatef(posicionXTriangulo, posicionYTriangulo, 0);
		glRotatef(angulo1, 1.0f, 1.0f, 1.0f);
		
		// Dibujado de los vértices
		glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.8f, 0.0f);
			glVertex3f(-0.2f, -0.2f, 0);
			glVertex3f(0.2f, -0.2f, 0);
			glVertex3f(0, 0.2f, 0);
		glEnd();

	glPopMatrix();*/


	glPushMatrix();
	glTranslatef(xTriangulo, yTriangulo, 0);
		glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.0f, 0.2f, 0.0f);
			glVertex3f(0.2f, -0.2f, 0.0f);
			glVertex3f(-0.2f, -0.2f, 0.0f);
		glEnd();
	glPopMatrix();

}

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if(key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		xTriangulo = .5;
	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		xTriangulo = -.5;
	}

}