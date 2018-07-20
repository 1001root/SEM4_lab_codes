#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float arr[3][3];
	float ans=0;
	cout<<"Enter the elements of the matrix"<<endl;
	for(int i=0; i< 3; i++){
		for(int j=0; j<3; j++){
			cin>>arr[i][j];
		}
	}
	float sarr[3];
	float tarr[3];
	cout<<"Enter the checking matrix"<<endl;
	for(int i=0; i<3; i++){
		cin>>sarr[i];
	}
	bool con=true;
	while(con){
		float a=0;
	for(int i=0; i<3; i++){
		float sum=0;
		for(int j=0; j<3; j++){
			sum += (arr[i][j]*sarr[j]);
		}
		tarr[i]=sum;
	}
	int pos;
	for(int i=0; i<3; i++){
		if(tarr[i] >a){
			pos=i;
			a= tarr[i];
		}
	}
	ans=a;
	cout<<"DEc"<<a<<endl;
	for(int i=0; i< 3; i++){
		tarr[i] /= a;
	}
	float chk=0;
	for(int i=0; i<3; i++){
		if(fabs(tarr[i]-sarr[i]) < 0.01){
			con=false;
		}
		else{
			con=true;
			break;
		}
	}
	for(int i=0; i<3; i++){
		sarr[i]=tarr[i];
	}
	}
	cout<<"The required value is : "<<ans<<endl;
	cout<<"The eigen values are: "<<endl;
	for(int i=0; i< 3; i++){
		cout<<tarr[i]<<"\t";
	}
	return 0;
}

