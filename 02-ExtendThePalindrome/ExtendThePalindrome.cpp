#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


vector <int> getMatch(string word){
	int size = (int)word.size();
	vector <int> match (size,0);
	
	for(int i=0;i<size;i++){
		
		int k = 0;
		int last = size-1;
		int coincidence=0;
				
		while(word[last]==word[i+k]){
			match[i+k] = ++coincidence;
			//cout << word[last] << " " << word[i+k] << endl;
			last--;
			k++;
			
			if(i+k==size){
				return match;
			}
		}


		
	}
	return match;
}


int main(){
	string word;
	
	while(getline(cin,word)){
		
		vector<int> coincidence = getMatch(word);
		
		/*for(int i=0; i<(int)coincidence.size(); i++){
			cout << coincidence[i] << " ";
		}*/
		//cout << endl;
		int sizeMatch = coincidence[coincidence.size()-1];
		int difference = word.size()-sizeMatch-1;
		
		for(int i=difference; i>=0; i--){
			word.push_back(word[i]);			
		}
		
		cout << word << endl;
		
	}

}
