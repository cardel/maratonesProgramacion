/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=379
 * Solución: https://es.wikipedia.org/wiki/Fórmula_de_Herón
 * Area de circulo dentro de un trigulo https://es.wikipedia.org/wiki/Circunferencia_inscrita_y_exinscrita_en_un_triángulo
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
		
		
		//El triangulo lo creamos tomando la distancia entre los 3 puntos 
        double distanciaAB = sqrt( pow(Ax - Bx, 2) + pow(Ay - By, 2) );
        double distanciaAC = sqrt( pow(Ax - Cx, 2) + pow(Ay - Cy, 2) );
        double distanciaBC = sqrt( pow(Bx - Cx, 2) + pow(By - Cy, 2) );
        
        //Calculamos el semiperimetro
        
        double semiPerimetro = (distanciaAB + distanciaAC + distanciaBC) / 2;
        
        //Calculamos el area del triagunlo
        
        double areaTriangulo = sqrt(semiPerimetro*(semiPerimetro - distanciaAB)*(semiPerimetro - distanciaAC)*(semiPerimetro - distanciaBC));        
        
        //calculamos el radio del circulo inscrito
        double radio = (distanciaAB * distanciaAC * distanciaBC) / (4*areaTriangulo);
        
        
        //Circunferencia pi *2 *r
		double circuferencia = pi*radio*2;

		printf("%.2f\n",circuferencia);
	}
}
