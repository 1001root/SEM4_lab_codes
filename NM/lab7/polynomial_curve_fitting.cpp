#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout<<"Enter the order of equation"<<endl;
	int o;
	cin>>o;
	cout<<"Enter the no. of data"<<endl;
	int d;
	cin>>d;
	if(o>d+1){
		cout<<"Inefficient Data"<<endl;
		return 0;
	}
	float x[d], y[d];
	cout<<"Enter the datas as x y :"<<endl;
	
	//Data insertion
	//
	for(int i=0; i<d; i++){
		cin>>x[i]>>y[i];
	}

	//making in the form of 
	float arr[o+1][o+2];
	for(int i=0; i<o+1; i++){
		for(int j=0; j<o+2; j++){
			arr[i][j]=0;
			if(j!= o+1){
				for(int k=0; k<d; k++){
					arr[i][j] += pow(x[k],i+j);
				}
			}
			else{
				for(int k=0; k<d; k++){
					arr[i][j] += (pow(x[k],i)*y[k]);
				}
			}
		}
	}
	cout<<"The matrix is :"<<endl;
	for(int i=0; i< o+1; i++){
		for(int j=0; j<o+2; j++){
			cout<<arr[i][j]<<"      ";
		}
		cout<<endl;
	}
	int row = o+1;
	for(int i=0; i<row; i++){
		float div = arr[i][i];
		for(int j=0; j<row; j++){
			float sam= arr[j][i];
			if(i != j){	
				for(int k=0; k<=row; k++){
					arr[j][k]= arr[j][k] - ((sam/div) * arr[i][k]);
				//	cout<<arr[j][k]<<endl;	
				}
			}
		}
	}
	for(int i=0; i<row; i++){
		float d= arr[i][i];
		for(int j=0; j<= row; j++){
			arr[i][j] /= d;
		}
	}

	cout<<"The result is : "<<endl;
	for(int i=0; i<row; i++){
		for(int j=0; j<=row; j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
	return 0;
}


