/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=483
 * Utilizo una pila para invertir la salida
 */

#include <map>
#include <string>
#include <iostream>
#include <stack>

using std::map;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::stack;

int main(){
	string linea;
	
	while(getline(cin, linea)){
		stack<char> palabraInversa;
		for(int i=0; i<linea.size(); i++){
			//Vaciar la pila cuando llega un espacio
			if(linea[i] == ' '){
				while(!palabraInversa.empty()){
					cout << palabraInversa.top();
					//Elimino elemento
					palabraInversa.pop();
				}
				cout <<' ';					
			}else{				
				palabraInversa.push(linea[i]);
			}
		}
		
		//Imprimir ultima palabra
		while(!palabraInversa.empty()){
			cout << palabraInversa.top();
			//Elimino elemento
			palabraInversa.pop();
		}		
		printf("\n");
		
	}
	
}
