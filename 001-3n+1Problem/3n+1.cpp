#include <iostream>
#include <vector>



using namespace std;
int acum=0;

int numeros(int n){
	if(n==1||n==0){
		return 1;
	}
	else if((n%2)==0){
		return n/2;
	}
	else{
		return (3*n)+1;
	}
}

int listNum(int n){
	acum++;
	if(n==1){
		return 1;
		
	}
	else{
		int h = numeros(n);
		listNum(h);
		return 0;
	}
}

int main(){
	
	//acum =1;
	int a;
	int b;
	int res=0;
	
	while(cin>>a){
		acum=0;

		cin>>b;
		
		int max =0;
		int min =0;
		
		if(b<a){
			max = a;
			min = b;
		}else{
			max = b;
			min = a;
		}
		
		int datos[max];
		
		while(min<=max){
			listNum(min);
			//cout<<acum<<endl;
			datos[min] = acum;
			acum=0;
			min++;
		}
		
		if(b<a){
			max = a;
			min = b;
		}else{
			max = b;
			min = a;
		}
		
		
		
		
		for(int i=min;i<=max;i++){
			if(res<datos[i]){
				res=datos[i];
			}else{
				
			}
		
		}
		
		cout<<min<<" "<<max<<" "<<res<<endl;
		
	}
}
