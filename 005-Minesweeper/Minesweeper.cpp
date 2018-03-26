#include <map>
#include <cstdio>

int main(){

	int filas, columnas;
	int field = 0;

	while(scanf("%i ",&filas) & scanf("%i\n",&columnas)){
		if(filas == 0 && columnas == 0) break;
		if(field > 0) printf("\n");
		field++;
		char text;
		int mapa[filas][columnas];
		
		//Rellenar 
		for(int i=0; i<filas; i++){
			for(int j=0; j<columnas; j++){
				mapa[i][j] = 0;
			}
		}
		
		for(int i=0; i<filas; i++){
			//Leo una más por el salto de linea
			for(int j=0; j<=columnas; j++){
				scanf("%c",&text);
				if(text == '*'){
					if(j - 1 >= 0 && i - 1 >= 0){
						if(mapa[i-1][j-1]!=-1) mapa[i-1][j-1]++;
					}
					if(i - 1 >= 0){
						if(mapa[i-1][j]!=-1) mapa[i-1][j]++;
					}
					if(j - 1 >= 0){
						if(mapa[i][j-1]!=-1) mapa[i][j-1]++;
					}
					if(j + 1 < columnas && i + 1 < filas){
						if(mapa[i+1][j+1]!=-1) mapa[i+1][j+1]++;
					}
					if(i + 1 < filas){
						if(mapa[i+1][j]!=-1) mapa[i+1][j]++;
					}
					if(j + 1 < columnas){
						if(mapa[i][j+1]!=-1) mapa[i][j+1]++;
					}
					
					if(j + 1 < columnas && i - 1 >= 0){
						if(mapa[i-1][j+1]!=-1) mapa[i-1][j+1]++;
					}
					if(j - 1 >= 0 && i + 1 < filas){
						if(mapa[i+1][j-1]!=-1) mapa[i+1][j-1]++;
					}										
					//Marca para el *
					mapa[i][j]= -1 ;

				}
			}
		}
		printf("%s%i:\n","Field #",field);
		for(int i=0; i<filas; i++){
			for(int j=0; j<columnas; j++){
				if(mapa[i][j]!=-1){
					printf("%i", mapa[i][j]);
				}
				else{
					printf("%c", '*');
				}
			}
			printf("\n");
		}
		
	}

}
