#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void _initialize_(int **a){
	int i,j;
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			a[i][j]=0;
		}
	}
}

// Cover creates logical constraints
void cover_block(){
	int i,j,k,x,y;
	ofstream outFile;
	outFile.open("output1.txt");
	int m,n;
	for(m=0;m<3;m++){
		for(n=0;n<3;n++){

	for(k=1;k<10;k++){
		for(i=1;i<4;i++){
			for(j=1;j<4;j++){
				outFile << (i+3*m) << (j+3*n) << k << " ";
			}
		}
		outFile << "0" << endl;
	}
	
	for(k=1;k<10;k++){
		for(i=1+m*3;i<4+m*3;i++){
			for(j=1+n*3;j<4+n*3;j++){
				for(x=1+m*3;x<4+m*3;x++){
					for(y=1+n*3;y<4+n*3;y++){
						if(3*i+j<3*x+y) outFile << '-' << i << j << k << " " << '-' << x << y << k<< " 0" <<endl;
					} 
				}
			}
		}
	}
		}
	}
	outFile.close();
}

void cover_rows(){
	int i,j,k,x;
	ofstream outFile;
	outFile.open("output2.txt");
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				outFile << i << j << k << ' ';
			}
			outFile << "0" <<endl;
		}
	}
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				for(x=1;x<10;x++){
					if(j<x) {outFile << '-' << i << j << k << " " << '-' << i << x << k;
						outFile << " 0" << endl;}
				}
			}
		}
	}
	outFile.close();
}

void cover_columns(){
	int i,j,k,x;
	ofstream outFile;
	outFile.open("output3.txt");
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				outFile << j << i << k << ' ';
			}
			outFile << "0" << endl;
		}
	}
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				for(x=1;x<10;x++){
					if(j<x) {outFile << '-' << j << i << k << " " << '-' << x << i << k;
						outFile << " 0" << endl;}
				}
			}
		}
	}
	outFile.close();
}

void cover_diagonals(){
	int i,k,x;
	ofstream outFile;
	outFile.open("output4.txt");
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			outFile << i << i << k << ' ';
		}
		outFile << "0" << endl;
	}
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			outFile << i << 10-i << k << ' ';
		}
		outFile << "0" << endl;
	}
	
	for(k=1;k<10;k++){
		for(i=1;i<10;i++){
			for(x=1;x<10;x++){
				if(x>i){
					outFile << '-' << i << i << k << ' ' << '-' << x << x << k << " 0" << endl;
					outFile << '-' << i << 10-i << k << ' ' << '-' << x << 10-x << k << " 0" << endl;
				}
			}
		}
	}
	outFile.close();
}

void cover_data(int **a){
	int i,j;
	ofstream outFile;
	outFile.open("output5.txt");
	
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			if(a[i][j]!=0) {outFile << -1 << " " << i << j << a[i][j] << " 0" << endl;
		outFile << 1 << " " << i << j << a[i][j] << " 0" << endl;	
		outFile << -1 << " -" << i << j << a[i][j] << " 0" << endl;
		}
		}
	}
	outFile.close();
}

// Merges all the constraints into  ssingle file
void Merger(int t_count){
	string x;

	ifstream Data;
	ofstream outFile;
	outFile.open("output.txt");

	Data.open("output1.txt");

	outFile << "p cnf 999 " << t_count <<endl;

	
	while(getline(Data,x)){
		outFile << x << endl;
	}
	Data.close();

	Data.open("output2.txt");
	
	while(getline(Data,x)){
		outFile << x << endl;
	}
	Data.close();

	Data.open("output3.txt");
	
	while(getline(Data,x)){
		outFile << x << endl;
	}
	Data.close();

	Data.open("output4.txt");
	
	while(getline(Data,x)){
		outFile << x << endl;
	}
	Data.close();

	Data.open("output5.txt");
	
	while(getline(Data,x)){
		outFile << x << endl;
	}
	

	Data.close();

	Data.open("output6.txt");
	
	while(getline(Data,x)){
		outFile << x << endl;
	}
	

	Data.close();


/*	for (int i=1;i<1000;i++){
		if (i%10==0 || ((i/10)%10)==0 || i/100 == 0) outFile << "-" << i << " 0" << endl;

	}
	*/outFile.close();
}

void same_number(){
	int i,j,k,l;

	ofstream outFile;
	outFile.open("output6.txt");

	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
			for(k=1;k<10;k++){
				for(l=1;l<10;l++){
					if(k<l) outFile << "-" << i << j << k << " " << "-" << i << j << l << " 0" << endl ;
				}
			}
		}
	}
}

int main(int argc, char **argv)
{
	ifstream inFile;
	inFile.open("Data.txt");
	
	
	int **a;
	a = new int*[10];
	// Suduko
	int i,j;
	
	for(i=0;i<10;i++){
	a[i] = new int[10];	
	}
	
	_initialize_(a);
	
 char x;

int count=0;
	// Input sudoku
	if(inFile.is_open()){
		for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				inFile >> x;
			 	//outFile << x; 

				if(x!='.'){
					a[i][j]=int(x)-int('0');
					count++;}
			 }
		}
	}
	

	else cout << "File is not open";

	int	t_count = 9657+2916+3*count;
	
	
	
	// Condition blocks
	cover_block();
	cover_rows();
	cover_columns();
	cover_diagonals();
	cover_data(a);
	same_number();
	Merger(t_count);
	inFile.close();
	
	system("minisat output.txt minisat_o.txt");
	
	// Reading input from minisat
	ifstream inFile2;
	inFile2.open("minisat_o.txt");
	
	string check;
	int y;
	
	if(inFile2.is_open()){
		inFile2 >> check;
		
		if(check=="SAT"){
			inFile2 >> y;

			while(y!=0){
				if(y>0)	a[y/100][(y%100)/10] = (y%10);
				inFile2 >> y;
			}
		}
		else cout <<"Unsatisfiable";
	}
	for(i=1;i<10;i++){
			for(j=1;j<10;j++){
				//inFile >> x;
			 	//outFile << x; 
				cout << a[i][j] << " ";
			 }
			 cout << endl;
		}

	return 0;
}
