#include <map>
#include <cstdio>
using std::map;

int main(){

	char text;
	map<char, char> mapa;

	mapa['\n']='\n';
	mapa[' ']=' ';
	mapa['=']='-';
	mapa['-']='0';
	mapa['0']='9';
	mapa['9']='8';
	mapa['8']='7';
	mapa['7']='6';
	mapa['6']='5';
	mapa['5']='4';
	mapa['4']='3';
	mapa['3']='2';
	mapa['2']='1';
	mapa['1']='`';
	mapa['\\']=']';
	mapa[']']='[';
	mapa['[']='P';
	mapa['P']='O';
	mapa['O']='I';
	mapa['I']='U';
	mapa['U']='Y';
	mapa['Y']='T';
	mapa['T']='R';
	mapa['R']='E';
	mapa['E']='W';
	mapa['W']='Q';
	mapa['\'']=';';
	mapa[';']='L';
	mapa['L']='K';
	mapa['K']='J';
	mapa['J']='H';
	mapa['H']='G';
	mapa['G']='F';
	mapa['F']='D';
	mapa['D']='S';
	mapa['S']='A';
	mapa['/']='.';
	mapa['.']=',';
	mapa[',']='M';
	mapa['M']='N';
	mapa['N']='B';
	mapa['B']='V';
	mapa['V']='C';
	mapa['C']='X';
	mapa['X']='Z';


	while(scanf("%c",&text) != EOF){
		printf("%c", mapa[text]);

	}



}
