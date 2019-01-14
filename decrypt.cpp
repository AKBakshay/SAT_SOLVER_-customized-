//Decrypt

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ifstream inFile;
	ofstream outFile;

	inFile.open("minisat_o.txt");
	outFile.open("Decrypted.txt");

	string check;
	int y,a[10][10];
	int i,j,k;
	
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			a[i][j]=0;
		}
	}

	if(inFile.is_open()){
		inFile >> check;
		
		if(check=="SAT"){
			inFile >> y;

			while(y!=0){
				if(y>0)	a[y/100][(y%100)/10] = (y%10);
				inFile >> y;
			}
		}
		else cout <<"Unsatisfiable";}


		for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				if(a[i][j]==0)	cout << '.';
				else			cout << a[i][j] ;
			}
			cout << endl;
		}


	inFile.close();
	outFile.close();

	return 0;
}