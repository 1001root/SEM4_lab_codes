#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main(){
	const int siz=10000;
//	int** mat = new int*[siz];
	int mat[siz][2];
/*	for(int i=0; i<siz; i++){
	       mat[i]=new int[2];
	}	
*/	mat[0][0]=2;
	mat[1][0]=3;
	mat[2][0]=5;
	mat[3][0]=7;
	mat[4][0]=11;
	mat[5][0]=13;
	mat[6][0]=17;
	mat[7][0]=19;
	mat[8][0]=23;
	mat[9][0]=29;
	mat[10][0]=31;
       long long int las=3;	
	for(int i=11; i<siz; i++){
		bool cond=true;
		while(las % 2 ==0 ||las % 3 ==0 ||las % 5 ==0 ||las % 7 ==0 ||las % 11 ==0 ||las % 13 ==0 ||las % 17 ==0 ||las % 19 ==0 ||las % 23 ==0 ||las % 29 ==0 || las %31 ==0){
			++las;
		}
		//	cout<<las<<endl;
	       	     mat[i][0]=las;
		     mat[i][1]=0;
		     ++las;
	}
	mat[0][1]=-1;
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
/*	for(int i=0; i<siz; i++){
		for(int j=0; j<2; j++){
			cout<<mat[i][j]<<"    ";
		}
		cout<<endl;
	}
		int count=0;
*/	ofstream myfile ("tval.txt");
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


	
