/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=579
 * Estrategia: Convertir todo a grados y luego comparar
 */

#include <map>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){
	while(true){
		
		string palabra;
		cin >> palabra;
		
		int valorMinutos =0;
		int valorHoras = 0;
		
		//Separar
		int indice = 0;
		
		//Sacar hora
		if(palabra[1]==':'){
			valorHoras = (int)(palabra[0] - '0');
			indice = 1;
		}
		else{
			valorHoras = 10*(int)(palabra[0] - '0')+(int)(palabra[1] - '0');
			indice = 2;
		}
		//Condicion de salida
		if(valorHoras == 0 && valorMinutos == 0) break;
		
		//La hora 12 es la hora 0
		if(valorHoras==12) valorHoras = 0;
		
		
		//Saco los minutos
		
		valorMinutos += 10*(int)(palabra[indice+1]-'0');
		valorMinutos += (int)(palabra[indice+2]-'0');
		//60 minutos son 360 grados
		double gradosMinutos = valorMinutos * 6;
			
		//Pasamos las horas a minutos, 720 minutos al dia a 360 grados
		double gradoHoras = 30*valorHoras + (double)valorMinutos/2;
		double diferencia = abs(gradoHoras - gradosMinutos);
		
		
		
		if(diferencia > 180) diferencia = 360 - diferencia;
		
		printf("%.3f\n",diferencia);
		
	}

}
