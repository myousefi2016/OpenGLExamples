/*******************************************************************************************************************************************************
 * David Canino (canino.david@gmail.com)
 *
 * Main website (GitHub): http://github.com/davidcanino/OpenGLExamples
 * 
 * Last update: August 2017
 *
 * This program is Free Software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.                                       
 *                                                                         
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License (http://www.gnu.org/licenses/gpl.txt) for more details.
 * 
 * main.cpp - the main function for the 'Example-027 (Old Mode)' Test.
 *******************************************************************************************************************************************************/

/* First, we must understand which platform we are using. */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <limits>
#define PI 3.14159265358979324
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

/// The number <i>'n'</i> of the vertices and the edges in the polyline, used for approximating the <i>'Sine-like'</i> curve of interest.
/**
 * It is initially set to 'n=5', which is the minimum number 'n' of the vertices and the edges. It is interactively modified by pressing the '+' and the '-' keys.
 */
unsigned int num_samples=5;

/// The custom exponent <i>'k'</i> to be used for defining and drawing the polyline, approximating the <i>'Sine-like'</i> curve of interest.
/**
 * In particular, any 'Sine-like' curve is defined in the same spirit of the 'Sine' curve, but it requires an exponent 'k' for computing sine function to the 'k'-th.
 * Clearly, it must be a positive and not null 'integer' value, provided interactively by the user.
 */
int k;

/* Prototypes for all functions of interest! */
void draw();
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);
void pause();

/// The main function for the <i>'Example-027 (Old Mode)'</i> Test.
int main(int argc,char **argv)
{
	/* We initialize everything, and create a very basic window! */
	cout<<endl<<"\tThis is the 'Example-027' Test, based on the (Old Mode) OpenGL."<<endl;
	cout<<"\tIt draws a polyline (in 'red'), formed by an arbitrary number 'n' of the vertices and the edges, in an OpenGL window. The polyline of interest ";
	cout<<"approximates the 'Sine-like' curve in '[-pi,+pi]'."<<endl;
	cout<<"\tIn particular, any 'Sine-like' curve is defined in the same spirit of the 'Sine' curve, but it requires an exponent 'k' for computing the sine function ";
	cout<<"to the 'k'-th. The 'Sine-like' curve is defined as follows:"<<endl<<endl;
	cout<<"\tx(t) = t, y(t) = sin ^ k (t)"<<endl<<endl<<"\tfor any 'k>0', and for every 't' in '[-pi,pi]'."<<endl<<endl;
	cout<<"\tThis test also provides a very basic interaction mechanism with the user. In fact, this latter must provide the exponent 'k', and can also:"<<endl<<endl;
	cout<<"\t\t-) increase the number 'n' of the vertices and the edges in the polyline of interest by pressing the '+' key;"<<endl;
	cout<<"\t\t-) decrease the number 'n' of the vertices and the edges in the polyline of interest by pressing the '-' key."<<endl<<endl;
	cout<<"\tLikewise, the window of interest can be closed by pressing any among the 'Q', the 'q', and the 'Esc' keys."<<endl<<endl;
	cout.flush();
	cout<<"\tPlease, insert the exponent 'k' (thus, a positive and not null 'integer' value) for the 'Sine-like' curve of interest: ";
	cin>>k;
	if( (!cin) || (k<=0) )
	{
		cin.clear();
		cout<<endl<<"\tPLEASE, INSERT A VALID VALUE (THUS, A POSITIVE AND NOT NULL 'INTEGER' VALUE) FOR THE EXPONENT 'k' OF INTEREST."<<endl<<endl;
		cout<<"\tTHIS PROGRAM IS CLOSING ..."<<endl<<endl;
		pause();
		return EXIT_FAILURE;
	}
	
	/* If we arrive here, then we can draw the polyline, approximating the 'Sine-like' curve! */
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	if(k%2==0) glutInitWindowSize(600,600/(2*PI));
	else glutInitWindowSize(600,2*600/(2*PI));
	glutCreateWindow("The 'Example-027' Test, based on the (Old Mode) OpenGL");
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
   	if(k%2==0) glOrtho(-PI-0.1,+PI+0.1,-0.1,1.1,-1,1);
   	else glOrtho(-PI-0.1,+PI+0.1,-1.1,1.1,-1,1);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	num_samples=5;
	cout<<endl<<"\tAt the beginning, the polyline, approximating the 'Sine-like' curve with exponent 'k="<<k<<"', is formed by 'n="<<num_samples<<"' vertices and ";
	cout<<"'n="<<num_samples<<"' edges (thus by the minimum number 'n' as possible)."<<endl<<endl;
	cout.flush();
}

/// This function is the keyboard input processing routine for the OpenGL window of interest.
void manageKeys(unsigned char key, int x, int y)
{
	/* We are interested only in the 'q' - 'Q' - 'Esc' - '+' - '-' keys. */
	switch (key)
	{
		case 'q':
	
		/* The key is 'q', thus we can exit from this program. */
		cout<<endl<<"\tThis program is closing correctly ... "<<endl<<endl;
		pause();
		exit(EXIT_SUCCESS);
		break;
		
		case 'Q':
	
		/* The key is 'Q', thus we can exit from this program. */
		cout<<endl<<"\tThis program is closing correctly ... "<<endl<<endl;
		pause();
		exit(EXIT_SUCCESS);
		break;
		
		case 27:
	
		/* The key is 'Esc', thus we can exit from this program. */
		cout<<endl<<"\tThis program is closing correctly ... "<<endl<<endl;
		pause();
		exit(EXIT_SUCCESS);
		break;
		
		case '+':
		
		/* The key is '+', thus we increase the number 'n' of the vertices and the edges in the polyline of interest! */
		num_samples=num_samples+1;
		glutPostRedisplay();
		break;
		
		case '-':
		
		/* The key is '-', thus we decrease the number 'n' of the vertices and the edges (if possible) in the polyline of interest. */
		if(num_samples>5) num_samples=num_samples-1;
		else
		{
			cout<<"\tThe minimum number 'n=5' of the vertices and the edges in the polyline of interest is reached, and it is not possible to decrease again this ";
			cout<<"number."<<endl;
			cout.flush();
		}

		/* If we arrive here, then this case is finished! */
		glutPostRedisplay();
		break;

		default:

    	/* Other keys are not important for us! */
    	break;
	}
}

/// This function draws the polyline (in <i>'red'</i>), approximating the <i>'Sine-like'</i> curve of interest, in the main OpenGL window.
void draw()
{
	float d,t;

	/* We draw the polyline (in 'red'), approximating the 'Sine-like' curve of interest, in the main OpenGL window. */
	d=(2*PI/(num_samples-1));
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
	for(unsigned int i=0;i<=num_samples;i++)
	{
		t=-PI+i*d;
		glVertex3f(t,pow(sin(t),k),0);
	}
	
	/* If we arrive here, all is ok */
	glEnd();
	glFlush();
	cout<<"\tThe 'Sine-like' curve of interest is currently approximated by a polyline with 'n="<<num_samples<<"' vertices and 'n="<<num_samples<<"' edges."<<endl;
	cout.flush();
}

/// This function simulates a pause while this test runs.
void pause()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.clear();
	cout << "\tPress the RETURN key to finish ... ";
	cout.flush();
	cin.get();
	#ifndef _MSC_VER
		cout << endl;
		cout.flush();
	#endif
}

