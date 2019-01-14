#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool check_(int i){
	if(i<0) i=-i;


		if (i%10==0 || ((i/10)%10)==0 || i/100 == 0) return false;

		return true;

}


int main(){

	string str;
	int x;
	ifstream inFile;
	ofstream outFile;

	inFile.open("minisat_o.txt");
	outFile.open("verfication_file.txt",ios::trunc);

	inFile >> str;

	x=10;

	while(x!=0){
		inFile >> x;
		if(check_(x))
		outFile << -x << " ";
	}
	outFile << "0";


	inFile.close();
	outFile.close();
	return 0;
}