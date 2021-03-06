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
 * main.cpp - the main function for the 'Example-026 (Old Mode)' Test.
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

/// The center coordinates <i>'(xc,yc)'</i> to be used for defining and drawing the polyline, approximating the <i>'Ellipse-like'</i> curve of interest.
/**
 * Clearly, the center for the 'Ellipse-like' curve of interest is formed by 2 floating-point values, provided interactively by the user.
 */
float xc,yc;

/// The number <i>'n'</i> of the vertices and the edges in the polyline, used for approximating the <i>'Ellipse-like'</i> curve of interest.
/**
 * It is initially set to 'n=3', which is the minimum number 'n' of the vertices and the edges. It is interactively modified by pressing the '+' and the '-' keys.
 */
unsigned int num_samples=3;

/// The semi-axis <i>'Rx'</i> along the x-axis to be used for defining and drawing the polyline, approximating the <i>'Ellipse-like'</i> curve of interest.
/**
 * Clearly, it must be a positive and not null floating-point value, provided interactively by the user.
 */
float Rx;

/// The semi-axis <i>'Ry'</i> along the y-axis to be used for defining and drawing the polyline, approximating the <i>'Ellipse-like'</i> curve of interest.
/**
 * Clearly, it must be a positive and not null floating-point value, provided interactively by the user.
 */
float Ry;

/// The custom exponent <i>'k'</i> to be used for defining and drawing the polyline, approximating the <i>'Ellipse-like'</i> curve of interest.
/**
 * In particular, any 'Ellipse-like' curve is defined in the same spirit of the 'Ellipse' curve, but it requires an exponent 'k' for computing the cosine and the sine
 * functions to the 'k'-th. Clearly, it must be a positive and not null 'integer value', provided interactively by the user.
 */
int k;

/* Prototypes for all functions of interest! */
void draw();
void initialize();
void resize(int w,int h);
void manageKeys(unsigned char key, int x, int y);
void pause();

/// The main function for the <i>'Example-026 (Old Mode)'</i> Test.
int main(int argc,char **argv)
{
	/* We initialize everything, and create a very basic window! */
	cout<<endl<<"\tThis is the 'Example-026' Test, based on the (Old Mode) OpenGL."<<endl;
	cout<<"\tIt draws a polyline (in 'red'), formed by an arbitrary number 'n' of the vertices and the edges, in an OpenGL window. The polyline of interest ";
	cout<<"approximates the 'Ellipse-like' curve with semi-axis 'Rx' and 'Ry' (respectively along"<<endl; 
	cout<<"\tthe x- and the y-axis), as well as center '(xc,yc)'. In particular, any 'Ellipse-like' curve is defined in the same spirit of the 'Ellipse' curve, but it";
	cout<<" requires an exponent 'k' for computing the cosine and the sine functions to"<<endl;
	cout<<"\tthe 'k'-th. The 'Ellipse-like' curve is defined as follows:"<<endl<<endl;
	cout<<"\tx(t) = xc + Rx * cos ^ k (t), y(t) = yc + Ry * sin ^ k (t)"<<endl<<endl<<"\tfor any 'Rx>0', 'Ry>0', 'k>0', and for every 't' in '[-pi,pi]'."<<endl<<endl;
	cout<<"\tThis test also provides a very basic interaction mechanism with the user, which must provide the semi-axis 'Rx' and 'Ry', as well as the center ";
	cout<<"coordinates '(xc,yc)' and the exponent 'k'. The user can also:"<<endl<<endl;
	cout<<"\t\t-) increase the number 'n' of the vertices and the edges in the polyline of interest by pressing the '+' key;"<<endl;
	cout<<"\t\t-) decrease the number 'n' of the vertices and the edges in the polyline of interest by pressing the '-' key."<<endl<<endl;
	cout<<"\tLikewise, the window of interest can be closed by pressing any among the 'Q', the 'q', and the 'Esc' keys."<<endl<<endl;
	cout.flush();
	cout<<"\tPlease, insert the semi-axis 'Rx' (thus, a positive and not null floating-point value) for the 'Ellipse-like' curve of interest: ";
	cin>>Rx;
	if( (!cin) || (Rx<=0) )
	{
		cin.clear();
		cout<<endl<<"\tPLEASE, INSERT A VALID VALUE (THUS, A POSITIVE AND NOT NULL FLOATING-POINT VALUE) FOR THE SEMI-AXIS 'Rx' OF INTEREST."<<endl<<endl;
		cout<<"\tTHIS PROGRAM IS CLOSING ..."<<endl<<endl;
		pause();
		return EXIT_FAILURE;
	}
	
	/* Now, we read the length of the second semi-axis 'Ry' (along the y-axis) for the 'Ellipse-like' curve of interest. */
	cout<<"\tPlease, insert the semi-axis 'Ry' (thus, a positive and not null floating-point value) for the 'Ellipse-like' curve of interest: ";
	cin>>Ry;
	if( (!cin) || (Ry<=0) )
	{
		cin.clear();
		cout<<endl<<"\tPLEASE, INSERT A VALID VALUE (THUS, A POSITIVE AND NOT NULL FLOATING-POINT VALUE) FOR THE SEMI-AXIS 'Ry' OF INTEREST."<<endl<<endl;
		cout<<"\tTHIS PROGRAM IS CLOSING ..."<<endl<<endl;
		pause();
		return EXIT_FAILURE;
	}
	
	/* Now, we read the center coordinates '(xc,yc)' for the 'Ellipse-like' curve of interest. */
	cout<<"\tPlease, insert the center coordinates '(xc,yc)' for the 'Ellipse-like' curve of interest (thus, 2 floating-point values, separated by a space): ";
	cout.flush();
	cin>>xc>>yc;
	if(!cin)
	{
		cin.clear();
		cout<<endl<<"\tPLEASE, INSERT THE CENTER COORDINATES '(xc,yc)' FOR THE 'ELLIPSE-LIKE' CURVE OF INTEREST (THUS, 2 FLOATING-POINT VALUES, SEPARATED BY A SPACE).";
		cout<<endl<<endl<<"\tTHIS PROGRAM IS CLOSING ..."<<endl<<endl;
		pause();
		return EXIT_FAILURE;
	}
	
	/* Now, we read the exponent 'k' for the 'Ellipse-like' curve of interest. */
	cout<<"\tPlease, insert the exponent 'k' (thus, a positive and not null 'integer' value) for the 'Ellipse-like' curve of interest: ";
	cin>>k;
	if( (!cin) || (k<=0) )
	{
		cin.clear();
		cout<<endl<<"\tPLEASE, INSERT A VALID VALUE (THUS, A POSITIVE AND NOT NULL 'INTEGER' VALUE) FOR THE EXPONENT 'k' OF INTEREST."<<endl<<endl;
		cout<<"\tTHIS PROGRAM IS CLOSING ..."<<endl<<endl;
		pause();
		return EXIT_FAILURE;
	}
	
	/* If we arrive here, then we can draw the polyline, approximating the 'Ellipse-like' curve! */
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowPosition(0,0);
	if(Rx==Ry) glutInitWindowSize(500,500);
	else if(Rx>Ry) { glutInitWindowSize(1000,1000*Ry/Rx); }
	else { glutInitWindowSize(1000*Rx/Ry,1000); }
	glutCreateWindow("The 'Example-026' Test, based on the (Old Mode) OpenGL");
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
   	glOrtho(xc-1.1*Rx,xc+1.1*Rx,yc-1.1*Ry,yc+1.1*Ry,-1,1);
   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();
}

/// This function initializes the OpenGL window of interest.
void initialize() 
{
	/* We initialize the OpenGL window of interest! */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	num_samples=3;
	cout<<endl<<"\tAt the beginning, the polyline, approximating the 'Ellipse-like' curve of center '("<<xc<<","<<yc<<")', exponent 'k="<<k<<"', semi-axis 'Rx="<<Rx;
	cout<<"', and semi-axis 'Ry="<<Ry<<"', is formed by 'n="<<num_samples<<"' vertices and 'n="<<num_samples<<"' edges (thus by";
	cout<<" the minimum number 'n'"<<endl<<"\tas possible)."<<endl<<endl;
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
		if(num_samples>3) num_samples=num_samples-1;
		else 
		{
			cout<<"\tThe minimum number 'n=3' of the vertices and the edges in the polyline of interest is reached, and it is not possible to decrease again this ";
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

/// This function draws the polyline (in <i>'red'</i>), approximating the <i>'Ellipse-like'</i> curve of interest, in the main OpenGL window.
void draw()
{
	float t;

	/* We draw the polyline (in 'red'), approximating the 'Ellipse-like' curve of interest, in the main OpenGL window. */
	t=-PI;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(unsigned int i=0;i<=num_samples;i++)
	{
		glVertex3f(xc+Rx*pow(cos(t),k),yc+Ry*pow(sin(t),k),0);
		t=t+(2*PI/num_samples);
	}
	
	/* If we arrive here, then all is ok */
	glEnd();
	glFlush();
	cout<<"\tThe 'Ellipse-like' curve of interest is currently approximated by a polyline with 'n="<<num_samples<<"' vertices and 'n="<<num_samples<<"' edges."<<endl;
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

