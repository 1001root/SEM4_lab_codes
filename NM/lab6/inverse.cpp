#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout<<"Enter the no. of equations"<<endl;
	int row;
	cin>>row;
	int col;
	col=2*row;
	cout<<"Enter the equation"<<endl;
	float arr[row][col];
	for(int i=0; i<row; i++){
		for(int j=0; j<row; j++){
			cin>>arr[i][j];
		}
		for(int k=row; k<col; k++){
			if(k != (i+row)){
				arr[i][k]=0;
			}
			else{
				arr[i][k]=1;
			}
		}

	}

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}

	for(int i=0; i<row; i++){
		float div = arr[i][i];
		for(int j=0; j<row; j++){
			float sam= arr[j][i];
			if(i != j){	
				for(int k=0; k<col; k++){
					arr[j][k]= arr[j][k] - ((sam/div) * arr[i][k]);
//					cout<<arr[j][k]<<endl;	
				}
			}
		}
	}

	for(int i=0; i<row; i++){
		float d= arr[i][i];
		for(int j=0; j<col; j++){
			arr[i][j] /= d;
		}
	}

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}
