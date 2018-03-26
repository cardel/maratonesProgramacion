/*
 * Autor: Carlos Andres Delgado. 
 * Fecha: 25-Marzo-2018
 * Descripción: Solución del problema https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1137
 */

#include <map>
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;



int main(){
	string game[8];
	int value = 0;
	int filas = 8;
	int columnas = 8;
	//Tenemos que leer 8 lineas por 8 caracteres ya que es un ajedrez
	while(true){
		for(int i=0; i<filas; i++){
			cin >> game[i];
		}
		 //Condición de salida
		bool salida = true;
		for(int i=0; i<8; i++){
			salida &= (game[i].compare("........")==0);
		}
		if(salida) break;

		 value++;
		 bool jaque = false;
		 char objetivo;
		 for(int i=0; i<8; i++){			 
 
			for(int j=0; j<8; j++){
				//Condiciones 
				
				//Vamos a generalizar, si es letra minuscula son las negras y se debe buscar al blanco
				//Si es letra mayuscula, se debe buscar el jaque
				
				char ficha = game[i][j];
				
				
				if(ficha == 'P' || ficha == 'R' || ficha == 'B' || ficha == 'Q' || ficha == 'N') objetivo = 'k';
				else objetivo = 'K';
				//Peon blancas
				if(ficha=='P'){
					//Verifico fila anterior para el caso de blancas
					if(i - 1 >= 0 && j - 1 >= 0){
						if(game[i-1][j-1]==objetivo){
							jaque = true;
						}
					}
					if(i-1 >= 0 && j+1 < filas){
						if(game[i-1][j+1]==objetivo){
							jaque = true;
						}						
					}
				}
				//Peon negras
				if(ficha=='p'){
					//Verifico fila siguiente para el caso de negras
					if(i + 1< filas && j - 1 >= 0){
						if(game[i+1][j-1]==objetivo){
							jaque = true;
						}
					}
					if(i+1 < filas && j+1 < filas){
						if(game[i+1][j+1]==objetivo){
							jaque = true;
						}						
					}
				}
				//Convertimos a mayuscula
				ficha = toupper(ficha);

				//Torre y reina (como torre)
				
				if(ficha=='R' || ficha=='Q'){
					
					//Examinanos hacia arriba			
					for(int k=i-1; k>=0; k--){
						
						if(game[k][j]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[k][j] != '.') k = -1;						
					}

				   //Examinanos hacia abajo
					for(int k=i+1; k<filas; k++){
									
						if(game[k][j]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[k][j] != '.') k = 8;					
					}
					
					//Examinanos a la izquierda			
					for(int k=j-1; k>=0; k--){
						
						if(game[i][k]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[i][k] != '.') k = -1;						
					}
					
				   //Examinanos a la derecha 
					for(int k=j+1; k<columnas; k++){
									
						if(game[i][k]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[i][k] != '.') k = 8;					
					}
					

				}				
							
				//Condiciones alfil y reina (como alfil)
				if(ficha=='B' || ficha=='Q'){
					//Primera diagonal (decremento filas y columnas)
					for(int a = i-1, b = j-1; a>=0 && b >=0 ; a--, b--){
						if(game[a][b]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[a][b] != '.') a = -1;
					}
					
					//Primer diagonal (incremento filas y columnas)
					for(int a = i+1, b = j+1; a<filas && b<columnas ; a++, b++){
						if(game[a][b]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[a][b] != '.') a = 8;
					}	
					
					//Segunda diagonal (incremento filas y decremento columnas)				
					for(int a = i+1, b = j-1; a<filas && b >=0 ; a++, b--){
						if(game[a][b]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[a][b] != '.') a = 8;
					}
					
					//Segunda diagonal (decremento filas e incremento columnas)				
					for(int a = i-1, b = j+1; a>=0 && b<columnas ; a--, b++){
						if(game[a][b]==objetivo){
							jaque = true;
						}
						//En caso de que una ficha esté en el camino examinamos hasta alli (ya que está tapando)
						if(game[a][b] != '.') a = -1;
					}
				}	
				
							
				//Condiciones caballo
				if(ficha=='N'){
					//Primera posición i - 1, j -2 
					if(i - 1>=0 && j - 2 >=0){
						if(game[i-1][j-2]==objetivo){
							jaque = true;
						}						
					}
					
					//Segunda posición i -2 , j -1
					if(i - 2>=0 && j - 1 >=0){
						if(game[i-2][j-1]==objetivo){
							jaque = true;
						}						
					}
					
					//Tercera posición i-2, j+1
					if(i - 2>=0 && j + 1 < columnas){
						if(game[i-2][j+1]==objetivo){
							jaque = true;
						}							
					}
					//Cuarta posición i -1 , j + 2
					if(i - 1>=0 && j + 2 < columnas){
						if(game[i-1][j+2]==objetivo){
							jaque = true;
						}							
					}
					//Quinta posición i + 1 , j + 2
					if(i + 1<filas && j + 2 < columnas){
						if(game[i+1][j+2]==objetivo){
							jaque = true;
						}							
					}
					//Sexta posición i + 2 , j + 1
					if(i + 2<filas && j + 1 < columnas){
						if(game[i+2][j+1]==objetivo){
							jaque = true;
						}							
					}	
					//Séptima posición i + 2 , j - 1
					if(i + 2<filas && j - 1 >=0){
						if(game[i+2][j-1]==objetivo){
							jaque = true;
						}							
					}
					//Octava posición i + 1 , j - 2
					if(i + 1<filas && j - 2 >=0){
						if(game[i+1][j-2]==objetivo){
							jaque = true;
						}							
					}												
				}
				
			
				if(jaque){
					i = 8;
					j = 8;
				}
				
			}
			 
	     }
	     if(objetivo=='k' && jaque) printf("Game #%i: %s\n", value,"black king is in check.");
	     else if(objetivo=='K' && jaque) printf("Game #%i: %s\n", value,"white king is in check.");
				else printf("Game #%i: %s\n", value,"no king is in check.");
	}

}
