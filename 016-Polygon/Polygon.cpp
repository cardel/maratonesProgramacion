/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=575
 * Solución https://sakseiw.wordpress.com/2013/10/04/punto-dentro-de-poligono/
 * https://en.wikipedia.org/wiki/Point_in_polygon
 * Idea: Lanzar un rayo desde el punto hacia el infinito, si el número de iteracciones es impar el punto está dentro del poligono, en otro caso no.
 */

#include <map>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){
	
	
	while(true){
		int numeroDePuntos;
		cin >> numeroDePuntos;
		
		if (numeroDePuntos == 0) break;
		//Obtener puntos
		int puntosX[numeroDePuntos+1];
		int puntosY[numeroDePuntos+1];
		
		for(int i = 0; i<numeroDePuntos; i++){
			cin >> puntosX[i];
			cin >> puntosY[i]; 
		}
		//Colocamos el primer punto de ultimo tambien para evitar repetir código
		puntosX[numeroDePuntos]= puntosX[0];
		puntosY[numeroDePuntos] = puntosY[0];
		//Obtener punto a investigar
		
		int puntoXInvestigar;
		int puntoYInvestigar;
		
		cin >> puntoXInvestigar;
		cin >> puntoYInvestigar;
		
		int intersecciones = 0;
		
		//Lanzamos un rayo desde puntoX a investigar miramos las interseccion, entonces y es la variable que nos interesa.
		for(int i = 0; i<numeroDePuntos; i++){
			//Primero ajustamos el minimo y maximo de cada punto
			int minX, maxX, minY, maxY;
			
			//( (condicion) ? proceso si es verdad : proceso si es falso ) operador condicional ternario, para evitar escribir un if largo
			minX = (puntosX[i] <= puntosX[i+1]) ? puntosX[i] : puntosX[i+1];
			maxX = (puntosX[i] <= puntosX[i+1]) ? puntosX[i+1] : puntosX[i];
			minY = (puntosY[i] <= puntosY[i+1]) ? puntosY[i] : puntosY[i+1];
			maxY = (puntosY[i] <= puntosY[i+1]) ? puntosY[i+1] : puntosY[i];	
			
			//Miramos si se interecta en X  (Basicamente es mirar si el maximo de X está despues del punto a investigar).			
			if(	maxX <= puntoXInvestigar){
				//Miramos si se intersecta en Y
				if(	puntoYInvestigar >= minY and 	puntoYInvestigar <= maxY){
					intersecciones++;
				}	
			}

			
		}
		
		(intersecciones % 2 == 0) ? printf("%c\n",'F') : printf("%c\n",'T');
	
	
	}
	
	
	
}
