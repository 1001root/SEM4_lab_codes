#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout<<"Enter the order of square matrix\n";
	int order;
	cin>>order;
	float mat[order][order];
	cout<<"Begin entering the data\n";
	for(int i=0; i<order; i++){
		for(int j=0; j<order; j++){
			cin>>mat[i][j];
		}
	}

	for(int i=0; i<order; i++){
		float div=mat[i][i];
		for(int j=0; j<order; j++){
			float sam =mat[j][i];
			if(j>i){
			 for(int k=0; k<=order; k++){
					mat[j][k]= mat[j][k] - ((sam/div) * mat[i][k]);
				//	cout<<mat[j][k]<<endl;	
				}
			}
		}
		
	}

/*	for(int i=0; i<order; i++){
		for(int j=0; j<order; j++){
			cout<<mat[i][j]<<"    ";
		}
		cout<<endl;
	}*/
	float ans=1;
	for(int i=0; i<order; i++){
		ans *=mat[i][i];
	}
	cout<<"The Determinant is : "<<ans<<endl;
	return 0;
}
