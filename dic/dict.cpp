#include<iostream>
using namespace std;
int main(){
	cout<<"Enter the no. of characters"<<endl;
	int n;
	cin>>n;
	cout<<"Enter the characters involved"<<endl;
	char arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	system("gnome-terminal -x sh -c 'echo arr[0];exec bash'");
	return 0;
}
