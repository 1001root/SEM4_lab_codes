#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
	const int siz=10000;
	int** mat = new int*[siz];
//	int mat[siz][2];
	for(int i=0; i<siz; i++){
	       mat[i]=new int[2];
	}	       
	for(int i=0; i<siz; i++){
	       	mat[i][0]=i+1;
		mat[i][1]=0;
	}
	mat[0][1]=0;
	mat[1][1]=-1;
	mat[2][1]=-1;
	bool con=true;
	for(int i=3; i<siz; i++){
		int a= mat[i][0];
		con=true;
		for(int j=2; j<=pow(a,0.5);j++){
			if(a% j ==0){
			       	mat[i][1]=5;
				con=false;
				break;
			}
		}
		if(con ==true) mat[i][1]=-1;
	}
	for(int i=0; i<siz; i++){
	//	for(int j=0; j<2; j++){
		if(mat[i][1]==-1){
			cout<<mat[i][0]<<endl;
		}
	}
		cout<<endl;
		int count=0;
	ofstream myfile ("val.txt");
	for(int i=0; i<siz; i++){
	//	for(int j=0; j<2; j++){
			if(mat[i][1] !=-1) ++count;
			else{
		//		cout<<count<<endl;
				myfile<<count<<endl;
				count=0;
			}
	}
	cout<<mat[siz-1][0]<<endl;
	myfile.close();
			
	return  0;
}


	
