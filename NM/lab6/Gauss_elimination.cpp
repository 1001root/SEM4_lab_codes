#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout<<"Enter the no. of equations"<<endl;
	int row;
	cin>>row;
	cout<<"Enter the equation"<<endl;
	float arr[row][row+1];
	for(int i=0; i<row; i++){
		for(int j=0; j<=row; j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0; i<row; i++){
		float div=arr[i][i];
		for(int j=0; j<row; j++){
			float sam =arr[j][i];
			if(j>i){
			 for(int k=0; k<=row; k++){
					arr[j][k]= arr[j][k] - ((sam/div) * arr[i][k]);
					cout<<arr[j][k]<<endl;	
				}
			}
		}
	}
	for(int i=row-1; i>=0; i--){
		float ans =0 ;
		for(int j=row-1; j>i; j--){
			if(i != row-1){
				ans += arr[i][j]*arr[j][row];
			}
			}
		float rans= arr[i][row]-ans;
		rans /=arr[i][i];
		arr[i][row]=rans;

	}


	for(int i=0; i<row; i++){
		for(int j=0; j<=row; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
			

