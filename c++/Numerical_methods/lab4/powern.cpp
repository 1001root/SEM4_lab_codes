#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int siz;
	cout<<"Enter the size : ";
	cin>>siz;
	float arr[siz][siz];
	float ans=0;
	cout<<"Enter the elements of the matrix"<<endl;
	for(int i=0; i< siz; i++){
		for(int j=0; j<siz; j++){
			cin>>arr[i][j];
		}
	}
	float sarr[siz];
	float tarr[siz];
	cout<<"Enter the checking matrix"<<endl;
	for(int i=0; i<siz; i++){
		cin>>sarr[siz];
	}
	bool con=true;
	while(con){
		float a=0;
	for(int i=0; i<siz; i++){
		float sum=0;
		for(int j=0; j<siz; j++){
			sum += (arr[i][j]*sarr[j]);
		}
		tarr[i]=sum;
	}
	int pos;
	for(int i=0; i<siz; i++){
		if(tarr[i] >a){
			pos=i;
			a= tarr[i];
		}
	}
	ans=a;
	cout<<"DEc"<<a<<endl;
	for(int i=0; i< siz; i++){
		tarr[i] /= a;
	}
	float chk=0;
	for(int i=0; i<siz; i++){
		if(fabs(tarr[i]-sarr[i]) < 0.01){
			con=false;
		}
		else{
			con=true;
			break;
		}
	}
	for(int i=0; i<siz; i++){
		sarr[i]=tarr[i];
	}
	}
	cout<<"The required value is : "<<ans<<endl;
	cout<<"The eigen values are: "<<endl;
	for(int i=0; i< siz; i++){
		cout<<tarr[i]<<"\t";
	}
	return 0;
}

