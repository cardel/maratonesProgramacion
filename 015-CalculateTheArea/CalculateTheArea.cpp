/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: http://www.spoj.com/problems/CALCAREA/
 * Solución http://www.universoformulas.com/matematicas/geometria/area-poligono-irregular/
 * No nos dicen en el problema que sea regular
 */

#include <map>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){
	int numeroDePuntos;
	
	while(cin >> numeroDePuntos){
		
		//Obtener puntos
		int puntosX[numeroDePuntos];
		int puntosY[numeroDePuntos];
		
		for(int i = 0; i<numeroDePuntos; i++){
			cin >> puntosX[i];
			cin >> puntosY[i]; 
		}
		
		double area = 0;
		
		//Calculamos los determinantes de Gauss
		for(int i = 0; i<numeroDePuntos-1; i++){
			area += (puntosX[i]*puntosY[i+1] - puntosX[i+1]*puntosY[i]);
		}
		//Ultimo punto con el primero
		area += (puntosX[numeroDePuntos-1]*puntosY[0] - puntosX[0]*puntosY[numeroDePuntos-1]);
		area = area/2;
		
		printf("%i\n", (int) round(area));
	}
	
	
	
}
