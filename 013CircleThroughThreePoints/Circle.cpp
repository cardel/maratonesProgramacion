/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=126
 * Solución http://www.qc.edu.hk/math/Advanced%20Level/circle%20given%203%20points.htm
 * https://math.stackexchange.com/questions/827072/finding-an-equation-of-circle-which-passes-through-three-points?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
 */

#include <map>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

#define pi 2*acos(0.0)

int main(){
	double Ax,Ay,Bx,By,Cx,Cy;
	while(cin >> Ax){
		cin >> Ay;
		cin >> Bx;
		cin >> By;
		cin >> Cx;
		cin >> Cy;
		
		
		//double r = sqrt(pow(Ax-Bx,2)+pow(Ay-By,2))/2;
		
		double puntoMedioAx, puntoMedioAy, puntoMedioBx, puntoMedioBy, gradienteA, gradienteB, gradienteL1, gradienteL2;
		
		//Intercepción entre dos puntos
		puntoMedioAx = (Ax+Bx)/2;
		puntoMedioAy = (Ay+By)/2;
		
		puntoMedioBx = (Bx+Cx)/2;
		puntoMedioBy = (By+Cy)/2;
		
		
		gradienteA = (By-Ay)/(Bx-Ax);
		gradienteB = (Cy-By)/(Cx-Bx);
		
		//Calculamos las rectas perpendiculares a los puntos medios de dos segmentos dados
		
		//Como son perpendiculares, las pendientes son - 1 / m
		gradienteL1 = -1/gradienteA;
		// y - puntoMedioAy = gradienteL1 * (x + puntoMedioAx)
		
		gradienteL2 = -1/gradienteB;
		// y - puntoMedioBy = gradienteL2 * (x + puntoMedioBx)
		
			
		//Calculo el centro
		
		// y = gradienteL1 * (x - puntoMedioAx) + puntoMedioAy 
		// y = gradienteL2 * (x - puntoMedioBx) + puntoMedioBy
		
		
		//y = gradienteL1 * x - gradienteL1 * puntoMedioAx + puntoMedioAy 
		//y = gradienteL2 *x - gradienteL2* puntoMedioBx + puntoMedioBy
		
		//gradienteL1 * x - gradienteL1 * puntoMedioAx + puntoMedioAy  = gradienteL2 *x - gradienteL2* puntoMedioBx + puntoMedioBy
		
		// (gradienteL1 - gradienteL2)x = -gradienteL2* puntoMedioBx + puntoMedioBy + gradienteL1 * puntoMedioAx - puntoMedioAy 
		// x = (-gradienteL2* puntoMedioBx + puntoMedioBy + gradienteL1 * puntoMedioAx - puntoMedioAy)/(gradienteL1 - gradienteL2);
		double h = (-gradienteL2* puntoMedioBx + puntoMedioBy + gradienteL1 * puntoMedioAx - puntoMedioAy)/(gradienteL1 - gradienteL2);
		
		double k = gradienteL1 * h - gradienteL1 * puntoMedioAx + puntoMedioAy;
		
		//r es la diatancia a cualquier punto		
		double r = sqrt(pow(Ax-h,2)+pow(Ay-k,2));
		
		double value = h*h+k*k-r*r;
		char opx,opy,opr;
		
		if(h>=0) opx='-'; else{ opx='+'; h*=-1; }
		if(k>=0) opy='-'; else{ opy='+'; k*=-1; }
		
		if(value>=0) opr='+'; else{ opr='-'; value*=-1; }
		

		printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",opx,h,opy,k,r);
		printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n",opx,2*h,opy,2*k,opr,value);
	}
}
