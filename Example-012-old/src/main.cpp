/*******************************************************************************************************************************************************
 * David Canino (canino.david@gmail.com)
 *
 * Main website (GitHub): http://github.com/davidcanino/OpenGLExamples
 * 
 * Last update: July 2017
 *
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                         
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for more details.
 * 
 * main.cpp - the main function for the 'Example-012 (Old Mode)' Test.
 *******************************************************************************************************************************************************/

/* First, we must understand which platform we are using. */
#include <cstdlib>
#include <iostream>
using namespace std;
#ifdef __APPLE__

	/* We are using a MacOSX platform (Macintosh). */
	#include "GL/glew.h"
	#include "GLUT/glut.h"
	#include "OpenGL/gl.h"

#else

	/* We are not using a MacOSX platform. Thus, we have a generic Unix-like platform, like the GNU/Linux, or a Microsoft Windows platform. */
	#include "GL/glew.h"
	#include "GL/glut.h"
	#include "GL/gl.h"

#endif

/// The custom settings for choosing what triangles sides in the custom triangle strip must be rendered.
/**
 * The value of this flag may be one of the following values:
 * 
 * -) the 'GL_FRONT' value, used for rendering only the 'front' triangles sides in the custom triangle strip (press the 'f' or the 'F' key);
 * -) the 'GL_BACK' value, used for rendering only the 'back' triangles sides in the custom triangle strip (press the 'b' or the 'B' key);
 * -) the 'GL_FRONT_AND_BACK' value, used for rendering both the 'front' and the 'back' triangles sides in the custom triangle strip (press the 't' or the 'T' key).
 *
 * The rendering type to be exploited is chosen separately by the user.
 */
GLenum face;

/// The custom settings for rendering the triangles sides of interest in the custom triangle strip.
/**
 * The value of this flag may be one of the following values:
 *
 * -) the 'GL_POINT' value, used for rendering only the vertices for the triangles sides in the custom triangle strip to be drawn (press the 'p' or the 'P' key);
 * -) the 'GL_LINE' value, used for rendering the 'wireframe versions' for the triangles sides in the custom triangle strip to be drawn (press the 'l' or the 'L' key);
 * -) the 'GL_FILL' value, used for rendering the 'filled versions' for the triangles sides in the custom triangle strip to be drawn (press the 'i' or the 'I' key).
 *
 * The choice for what triangles sides in the custom triangle strip must be drawn is performed separately by the user.
 */
GLenum mode;

/* Prototypes for all functions of interest! */
void draw();
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);

/// The main function for the <i>'Example-012 (Old Mode)'</i> Test.
int main(int argc,char **argv)
{
	/* We initialize everything, and create a very basic window! */
	cout<<endl<<"\tThis is the 'Example-012' Test, based on the (Old Mode) OpenGL."<<endl;
	cout<<"\tIt draws all triangles in a triangle strip (in 'turquoise gray'), approximating a custom shape, in an OpenGL window. It is not possible to modify the ";
	cout<<"size and the position for the vertices of the custom shape. Instead,"<<endl;
	cout<<"\tthe settings for rendering all triangles in the triangle strip of interest can be modified interactively by the user as follows:"<<endl<<endl;
	cout<<"\t\t-) only the 'front' triangles sides in the custom triangle strip are rendered by pressing the 'f' or the 'F' key. The corresponding rendering type is ";
	cout<<"chosen by the user separately."<<endl;
	cout<<"\t\t-) Only the 'back' triangles sides in the custom triangle strip are rendered by pressing the 'b' or the 'B' key. The corresponding rendering type is ";
	cout<<"chosen by the user separately."<<endl;
	cout<<"\t\t-) Both the 'front' and the 'back' triangles sides in the custom triangle strip are rendered by pressing the 't' or the 'T' key. The corresponding ";
	cout<<"rendering type is chosen by the user separately."<<endl;
	cout<<"\t\t-) Only the vertices of the triangles sides in the custom triangle strip to be drawn are rendered by pressing the 'p' or the 'P' key. The user can ";
	cout<<"choose separately what triangles sides must be drawn."<<endl;
	cout<<"\t\t-) The 'wireframe versions' of the triangles sides in the custom triangle strip to be drawn are rendered by pressing the 'l' or the 'L' key. The user ";
	cout<<"can choose separately what triangles sides must be drawn."<<endl;
	cout<<"\t\t-) The 'filled versions' of the triangles sides in the custom triangle strip to be drawn are rendered by pressing the 'i' or the 'I' key. The user can";
	cout<<" choose separately what triangles sides must be drawn."<<endl<<endl;
	cout<<"\tLikewise, the window of interest can be closed by pressing any among the 'Q', the 'q', and the 'Esc' keys."<<endl<<endl;
	cout.flush();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(480,480);
	glutCreateWindow("The 'Example-012' Test, based on the (Old Mode) OpenGL");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutKeyboardFunc(manageKeys);
	glewExperimental = GL_TRUE;
   	glewInit();
   	initialize(); 
	glutMainLoop();
	return EXIT_SUCCESS;
}

/// This function updates the viewport for the scene when it is resized. */
void resize(int w, int h)
{
	/* We update the projection and the modeling matrices! */
	glViewport(0, 0, w, h);
   	glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	glOrtho(0,100,0,100,-1,1);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	face=GL_FRONT;
	mode=GL_FILL;
	cout<<"\tAt the beginning, the 'filled versions' for the 'front' triangles sides in the triangle strip of interest are rendered in the scene."<<endl<<endl;
	cout.flush();
}

/// This function is the keyboard input processing routine for the OpenGL window of interest.
void manageKeys(unsigned char key, int x, int y)
{
	/* We are interested only in the 'q' - 'Q' - 'Esc' - 'f' - 'F' - 'b' - 'F' - 't' - 'T' - 'i' - 'I' - 'l' - 'L' - 'P' - 'p' keys. */
	switch (key)
	{
		case 'q':
	
		/* The key is 'q', thus we can exit from this program. */
		cout<<endl<<"\tThis program is closing correctly ... "<<endl<<endl;
		cout << "\tPress the RETURN key to finish ... ";
		cin.get();
		#ifndef _MSC_VER
			cout << endl;
			cout.flush();
		#endif
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 'Q':
	
		/* The key is 'Q', thus we can exit from this program. */
		cout<<endl<<"\tThis program is closing correctly ... "<<endl<<endl;
		cout << "\tPress the RETURN key to finish ... ";
		cin.get();
		#ifndef _MSC_VER
			cout << endl;
			cout.flush();
		#endif
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 27:
	
		/* The key is 'Esc', thus we can exit from this program. */
		cout<<endl<<"\tThis program is closing correctly ... "<<endl<<endl;
		cout << "\tPress the RETURN key to finish ... ";
		cin.get();
		#ifndef _MSC_VER
			cout << endl;
			cout.flush();
		#endif
		cout.flush();
		exit(EXIT_SUCCESS);
		break;
		
		case 'F':

		/* The key is 'F', thus we draw only the 'front' triangles sides in the triangle strip, approximating the custom shape of interest, by using the rendering type,
		 * chosen by the user. */
		face=GL_FRONT;
		glutPostRedisplay();
		break;
		
		case 'f':

		/* The key is 'f', thus we draw only the 'front' triangles sides in the triangle strip, approximating the custom shape of interest, by using the rendering type,
	 	 * chosen by the user. */
		face=GL_FRONT;
		glutPostRedisplay();
		break;
		
		case 'B':

		/* The key is 'B', thus we draw only the 'back' triangles sides in the triangle strip, approximating the custom shape of interest, by using the rendering type,
		 * chosen by the user. */
		face=GL_BACK;
		glutPostRedisplay();
		break;
		
		case 'b':

		/* The key is 'b', thus we draw only the 'back' triangles sides in the triangle strip, approximating the custom shape of interest, by using the rendering type,
		 * chosen by the user. */
		face=GL_BACK;
		glutPostRedisplay();
		break;
		
		case 'T':

		/* The key is 'T', thus we draw both the 'front' and the 'back' triangles sides in the triangle strip, approximating the custom shape of interest, by using the
		 * rendering type, chosen by the user. */
		face=GL_FRONT_AND_BACK;
		glutPostRedisplay();
		break;
		
		case 't':

		/* The key is 't', thus we draw both the 'front' and the 'back' triangles sides in the triangle strip, approximating the custom shape of interest, by using the
		 * rendering type, chosen by the user. */
		face=GL_FRONT_AND_BACK;
		glutPostRedisplay();
		break;
		
		case 'I':

		/* The key is 'I', thus we render the 'filled versions' for the sides to be drawn of all triangles in the triangle strip, approximating the custom shape of
	 	 * interest. The user can choose separately what triangles sides must be drawn. */
		mode=GL_FILL;
		glutPostRedisplay();
		break;
		
		case 'i':

		/* The key is 'i', thus we render the 'filled versions' for the sides to be drawn of all triangles in the triangle strip, approximating the custom shape of
		 * interest. The user can choose separately what triangles sides must be drawn. */
		mode=GL_FILL;
		glutPostRedisplay();
		break;
		
		case 'L':

		/* The key is 'L', thus we render the 'wireframe versions' for the sides to be drawn of all triangles in the triangle strip, approximating the custom shape of
		 * interest. The user can choose separately what triangles sides must be drawn. */
		mode=GL_LINE;
		glutPostRedisplay();
		break;
		
		case 'l':

		/* The key is 'l', thus we render the 'wireframe versions' for the sides to be drawn of all triangles in the triangle strip, approximating the custom shape of
		 * interest. The user can choose separately what triangles sides must be drawn. */
		mode=GL_LINE;
		glutPostRedisplay();
		break;
		
		case 'P':
		
		/* The key is 'P', thus we render only the vertices for the sides to be drawn of all triangles in the triangle strip, approximating the custom shape of
		 * interest. The user can choose separately what triangles sides must be drawn. */
		mode=GL_POINT;
		glutPostRedisplay();
		break;
		
		case 'p':
		
		/* The key is 'p', thus we render only the vertices for the sides to be drawn of all triangles in the triangle strip, approximating the custom shape of
		 * interest. The user can choose separately what triangles sides must be drawn. */
		mode=GL_POINT;
		glutPostRedisplay();
		break;
		
		default:

    	/* Other keys are not important for us! */
    	break;
	}
}

/// This function draws all triangles in the triangle strip (in <i>'turquoise gray'</i>), approximating a custom shape, in the OpenGL window of interest by using the rendering preferences, chosen by the user.
void draw()
{
	/* We draw a triangle strip (in 'turquoise gray'), approximating a custom shape, in the OpenGL window of interest by using the rendering preferences, chosen by 
	 * the user. */
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glLineWidth(2.0);
	glColor3f(0.6,0.7,0.7);
	glPolygonMode(face,mode);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(10.0, 90.0, 0.0);
   	glVertex3f(10.0, 10.0, 0.0);
   	glVertex3f(35.0, 75.0, 0.0);
    glVertex3f(30.0, 20.0, 0.0);
    glVertex3f(90.0, 90.0, 0.0);
   	glVertex3f(80.0, 40.0, 0.0);
	glEnd();
	glFlush();
	if(face==GL_FRONT)
	{
		/* We must draw only the 'front' triangles sides in the custom triangle strip by using the rendering type, chosen by the user. */
		if(mode==GL_POINT) cout<<"\tOnly the vertices of the 'front' triangles sides in the custom triangle strip are currently rendered in the scene."<<endl;
		if(mode==GL_LINE) cout<<"\tThe 'wireframe versions' of the 'front' triangles sides in the custom triangle strip are currently rendered in the scene."<<endl;
		if(mode==GL_FILL) cout<<"\tThe 'filled versions' of the 'front' triangles sides in the custom triangle strip are currently rendered in the scene."<<endl;
	}
	else if(face==GL_BACK)
	{
		/* We must draw only the 'back' triangles sides in the custom triangle strip by using the rendering type, chosen by the user. */
		if(mode==GL_POINT) cout<<"\tOnly the vertices of the 'back' triangles sides in the custom triangle strip are currently rendered in the scene."<<endl;
		if(mode==GL_LINE) cout<<"\tThe 'wireframe versions' of the 'back' triangles sides in the custom triangle strip are currently rendered in the scene."<<endl;
		if(mode==GL_FILL) cout<<"\tThe 'filled versions' of the 'back' triangles sides in the custom triangle strip are currently rendered in the scene."<<endl;
	}
	else
	{
		/* We must draw both the 'front' and the 'back' triangles sides in the custom triangle strip by using the rendering type, chosen by the user. */
		if(mode==GL_POINT) 
		cout<<"\tOnly the vertices of both the 'front' and the 'back' triangles sides in the custom triangle strip are currently rendered in the scene.";
		if(mode==GL_LINE) 
		cout<<"\tThe 'wireframe versions' of both the 'front' and the 'back' triangles sides in the custom triangle strip are currently rendered in the scene.";
		if(mode==GL_FILL)
		cout<<"\tThe 'filled versions' of both the 'front' and the 'back' sides for triangles sides in the custom triangle strip are currently rendered in the scene.";
		cout<<endl;
	}
}

