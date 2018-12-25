#include<fstream>
#include<iostream>
#include<bits/stdc++.h>
#include<time.h>

using namespace std;

int N=4,decomposition=0;
unordered_map<int,int> m;
vector<int> result;
bool cmp(int a,int b){
	return m[a]>m[b];
}
bool cmpar(vector<int> &a,vector<int> &b){
	if(a.size()!=b.size())return a.size()<b.size();
	for(int i=0;i<a.size();i++){
		if(m[a[i]]==m[b[i]])continue;
		return m[a[i]]>m[b[i]];
	}
	return 0;
}
bool compare_1(int x,int y){
	return abs(x)<abs(y);
}


bool check_presence(int a,vector<int> v){

	for(int i=0;i<v.size();i++){
		if(v[i]==a) return true;
	}
	return false;
}

vector<vector<int>> func_1(int a, vector<vector<int>> V){
	vector<vector<int>> v;
	v.clear();
	decomposition++;
	
	vector<int> temp;
	temp.clear();
	int flag=0;

	for(int i=0;i<V.size();i++){
		if(check_presence(a,V[i]));
		else if(check_presence(-a,V[i])&&V[i].size()>1){
			for(int j=0;j<V[i].size();j++){
				if(V[i][j]!=-a) temp.push_back(V[i][j]);
			}
			v.push_back(temp);
			temp.clear();
		}
		else if(check_presence(-a,V[i])){
			v.clear();
		temp.push_back(N+1);
			v.push_back(temp);
			temp.clear();
			flag=1;
		}
		else v.push_back(V[i]);

		if(flag==1) break;
	}

	return v;
}

int func_0(vector<vector<int>> V){
	for(int i=0;i<V.size();i++)sort(V[i].begin(),V[i].end(),cmp);
	sort(V.begin(),V.end(),cmpar);
	
	vector<vector<int>> v;
	vector<int> temp;
	v.clear();
	temp.clear();
	v = V;
	
	if(V.empty()) return 1;
	int i=0,j=0;
	while(v[i].size()==1&&i+1<v.size()){
		j=i+1;
		while(v[j].size()==1){
			if(v[i][0]==-v[j][0]) return 0;
			j++;
			if(j==v.size()) break;
		}
		temp.push_back(v[i][0]);
		
		v = func_1(v[i][0],v);
//		cout << "check1" << endl;
		for(int i=0;i<v.size();i++)sort(v[i].begin(),v[i].end(),cmp);
		if(!v.empty())sort(v.begin(),v.end(),cmpar);
		if(v.empty()) break;
}
	for(int i=0;i<temp.size();i++) result.push_back(temp[i]);
	
	if(v.empty()) return 1;
	if(v.size()==1&&v[0].size()==1) return 1;

	for(int i=0;i<v.size();i++)sort(v[i].begin(),v[i].end(),cmp);
	sort(v.begin(),v.end(),cmpar);
	

	for(int i=0;i<v[0].size();i++){
		if(func_0(func_1(v[0][i],v))==1) {
			result.push_back(v[0][i]);
			return 1;}
		else {
		 	result.push_back(-v[0][i]);
			return func_0(func_1(-v[0][i],v));}
	}

}


int main()
{
	
	string input_str; 

	clock_t t1,t2;
	t1=clock();

	cout << "Input File: " ;
	cin >> input_str;
	cout << endl;
	ifstream in;
	in.open(input_str);

	if(!in)
	{
		cout<<"No input file"<<endl;
		system("pause");
		return 1;
	}
	int count=0;
	//getline(in,input);
	string a,b;
	int l,w;
	in>>a>>b>>w>>l;
	N=w;
	vector<int> vec;
	vector<vector<int> > arr;
	while(l--){
		int x=1;
		vec.clear();
		while(x){
			in>>x;
			if(x==0)break;
			vec.push_back(x);
			m[x]++;
		}
		arr.push_back(vec);
	}
	

	result.clear();

	for(int i=0;i<arr.size();i++)sort(arr[i].begin(),arr[i].end(),cmp);
	sort(arr.begin(),arr.end(),cmpar);

	int x = func_0(arr);

	t2=clock();

	vector<int> result1;
	result1.clear();
	int j=0;
	
	if(x==0) cout << "UNSAT" << endl;
	else{
		for(int i=result.size()-1;i>=0;i--){
			if((!check_presence(result[i],result1))&&(!check_presence(-result[i],result1))) result1.push_back(result[i]);
		}
		sort(result1.begin(),result1.end(),compare_1);
/*		for(int i=0;i<result.size();i++){
			if(i==0) {result1.push_back(result[i]);
			j++;	continue;}
			if(result[i]==result1[j-1]);
			else{
				result1.push_back(result[i]);
			j++;
			}

		}
*/
		cout << "SAT" << endl;
		for(int i=0;i<result1.size();i++){
			cout << result1[i] << ' ';
		}
		cout << endl;}

	float diff=((float)t2-(float)t1);

	cout << "Time taken: " << diff/CLOCKS_PER_SEC << " s" << endl;
	cout << "No. of Decompositions: " << decomposition << endl;

	return 0;
}
