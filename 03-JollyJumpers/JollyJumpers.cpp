/*
 * Autor: Carlos Andres Delgado
 * Descripción: En este ejercicio uso un arreglo de booleanos entre 0 y n-1 para representar las diferencias entre 1 y n-1
 * Muire como reduzco el n en la linea 20
 */

#include <map>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int main(){

	int n;

	while(cin>>n){
		n = n -1;
		bool estado[n];
		bool salida = true;
		int actual, anterior;
		for(int i=0; i<n; i++){ 
			estado[i] = false;
		}
		cin >> anterior;
		for(int i=1; i<=n; i++){ 
			cin >> actual;
			if(abs(actual-anterior)-1 < n && abs(actual-anterior)-1 >= 0) estado[abs(actual-anterior)-1] = true;
			anterior = actual;
		}
		
		for(int i=0; i<n; i++){
			salida&=estado[i];
		}
		
		if(salida) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;

	}

}
