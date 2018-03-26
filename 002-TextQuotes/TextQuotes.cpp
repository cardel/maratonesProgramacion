#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> linea;
	string aux = "";
	while(getline(cin,aux)){
		linea.push_back(aux);
	}
	bool conteo = false;
	for(int i=0; i<linea.size(); i++){
		
		for(int j=0; j<linea[i].size(); j++){
			if(linea[i][j]=='"'){
				linea[i].erase(j,1);
				if(!conteo){					
					linea[i].insert(j,"``");
					
				}
				else{
					linea[i].insert(j,"''");					
				}
				conteo = !conteo;
			}
		}
	}
	
	for(int i=0; i<linea.size(); i++){
		cout << linea[i] << endl;
	}
}
