/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=55
 */

#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;


int main(){
	int number;
	//Para evitar error de presentación
	bool first = true;
	while(cin >> number){
		
		map<string,int> names;
		string salida[number];
		
		//Error de presentación (espacio entre entradas)
		if(!first)	cout << endl;
		if(first)	first=false;
		
		for(int i=0; i<number; i++){
			string person;
			cin >> person;
			
			//Inicialmente no da ni recibe
			names[person] = 0;
			salida[i] = person;			
		}
		
		for(int i =0; i<number; i++){
			string person;
			cin >> person;
			
			int money;
			cin >> money;
			
			int numberOfPeople;
			cin >> numberOfPeople;
			
			//Esto trunca la cifra, porque se da por partes iguales
			int totalForPerson;
			if(numberOfPeople!=0) totalForPerson = money / numberOfPeople;
			else totalForPerson = 0;			
			money = totalForPerson * numberOfPeople;
			
			names[person] -= money;
			
			for(int j=0; j<numberOfPeople; j++){
				cin >> person;
				names[person] += totalForPerson;
			}				
			
		}
		
		//Imprimir salida
		for(int i=0; i<number; i++){
			cout << salida[i]<< " " << names[salida[i]]<< endl;
			
		}
		
		
	}
	

}
