/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 26-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2624U
 * Utilizo códigos ASCII de las minusculas a= 97, z = 122
 */

#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::getline;
using std::cin;

int main(){
	int numberLines;
	scanf("%i\n", &numberLines);
	
	for(int i=0; i<numberLines; i++){
		
		int conteo[26];	
		for(int i=0; i<26; i++){
			conteo[i]=0;
		}
		//Llevamos un conteo del máximo para evitar ordenar
		int maximo = 0;
		string linea;
		//Ignorar salto de linea
		//cin.ignore();
		getline(cin, linea);
		//Recorremos linea por linea y vamos contando
		for(int j=0; j<linea.size(); j++){
			
			char letra = linea[j];
			//Pasar a minusculas
			letra = tolower(letra);
			int diferencia = letra-97;
			
			if(diferencia >=0 && diferencia < 26){
				conteo[diferencia]++;
				
				//Actualizar el maximo
				if(maximo < conteo[diferencia]){
					maximo = conteo[diferencia];
				}
			}
			
			
		}
		
		//Ahora mostramos en orden alfabetico
		
		for(int i=0; i<26; i++){
			if(conteo[i]==maximo){
				printf("%c",(char)(i+97));
			}
		}
		printf("\n");
	}

}
