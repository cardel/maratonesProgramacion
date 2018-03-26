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

#define pi 2*acos(0.0)

int main(){
	int numeroCasos;
	cin >> numeroCasos;
	
	for(int i=0; i<numeroCasos; i++){
		int numeroComandos;
		cin >> numeroComandos;
		
		//La tortuga se mueve en 2 dimensiones
		double posX = 0;
		double posY = 0;
		double angulo = 0;
		
		for(int j=0; j<numeroComandos; j++){
			string comando;
			cin >> comando;
			
			int numeroLineas;
			cin >> numeroLineas;
			
			if(comando.compare("fd")==0){
				posX +=  numeroLineas*cos( angulo * pi / 180.0 );
				posY +=  numeroLineas*sin( angulo * pi / 180.0 );
			}
			
			if(comando.compare("lt")==0){
				angulo-=numeroLineas;
			}
			
			if(comando.compare("rt")==0){
				angulo+=numeroLineas;
			}			
			if(comando.compare("bk")==0){
				posX -=  numeroLineas*cos( angulo * pi / 180.0 );
				posY -=  numeroLineas*sin( angulo * pi / 180.0 );
			}	
			
						
		}
		
		//Calcular distancia
		
		double distancia = round(sqrt(pow(posX,2)+pow(posY,2)));
		cout << (int)distancia << endl;
		
		
	}
}
