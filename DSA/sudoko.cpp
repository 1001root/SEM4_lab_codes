#include<iostream>
#include<cmath>
using namespace std;
void init(int * arr){
	for(int i=0; i<9; i++){
		*(arr+i)=-1;
	}
}
bool putval(int arr[9][9], int ar2[9], int a, int ans[9]){
	int count=0;
	bool con=false;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(arr[i][j]==a){
				ar2[j]=33;
				count++;
				break;
			}
		}
	}
	if(count == 9) {
		con=true;
		ans[a-1]=1;
	}

	return(con==true);
}



int main(){
	int mat[9][9];
	cout<<"Enter the problem rows downwords, for empty insert 0 :\n";
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>mat[i][j];
		}
	}
	int chk=1;
	int k=0;
	int ans[9];
	mat sol[9][2];
	int dchk[9];
	int 1mat[9];
	int 2mat[9];
	int 3mat[9];
	int 4mat[9];
	int 5mat[9];
	int 6mat[9];
	int 7mat[9];
	int 8mat[9];
	int 9mat[9];
	init(1mat);
	init(2mat);
	init(3mat);
	init(4mat);
	init(5mat);
	init(6mat);
	init(7mat);
	init(8mat);
	init(9mat);
	init(ans);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(mat[i][j]==chk){
				sol[k][0]=i;
				sol[k++][1]=j;



