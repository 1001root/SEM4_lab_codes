#include<iostream>
using namespace std;
int add(int (&arr)[8][8], int col1, int pos){
	bool con=true;
	int i=col1;
	for(int a=0; a<8; ++a) arr[i][a] +=1;
	for (int a=0; a<8; ++a) arr[a][0] +=1;
			int a=pos;
			int b=col1;
		while(con){
			++a;
			++b;
			if(a<8 && b<8){
			       	arr[a][b] +=1;
			}
			else con=false;
		}
			a=pos;
			b=col1;
			con=true;
		while(con){
			--a;
			++b;
			if(a>=0 && b<8){
			       	arr[a][b] +=1;
			}
			else con=false;
		}
		a=pos;   	
		b=col1;  	
		con=true;	
		while(con){
			--a;
			--b;
			if(a>=0 && b>=0){
			       	arr[a][b] +=1;
			}
			else con=false;
		}
		a=pos;   	
		b=col1;  	
		con=true;	
		while(con){
			++a;
			--b;
			if(a<8 && b>=0){
			       	arr[a][b] +=1;
			}
			else con=false;
		}
}
bool chk(int (&arr)[8][8]){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(arr[i][j] > 1)return false;
			}
		}
		return true;
}


int main(){
	int arr[8][8];
	int ans[8];
	bool con=true;
	for(int i=1; i<6; i++){
		con=true;
		int col1=0;
            for(int a=0; a<8; a++){        	
	    	for(int b=0; b<8; b++){
	    		arr[a][b]=0;
	    	}
	    }
		/*for(int a=0; a<8; ++a) arr[i][a]=1;
	        for (int a=0; a<8; ++a) arr[a][0]=1;
			int a=i;
			int b=col1;
		while(con){
			if(a<8 && b<8){
			       	arr[++a][++b] +=1;
			}
			else con=false;
		}
			a=i;
			b=col1;
			con=true;
		while(con){
			if(a>=0 && b<8){
			       	arr[--a][++b] +=1;
			}
			else con=false;
		}*/
	    	add(arr,col1,i);
		if(!chk(arr)) break;
		ans[0]=i;
		for(int j=0; j<8; ++j){
			int mat1[8][8];
			for(int a=0; a<8; ++a){
				for(int b=0; b<8; ++b){
					mat1[a][b]=arr[a][b];
				}
			}
			int col2=1;
			con=true;
			if(arr[j][col2] == 1)continue;
			else if(arr[j][col2] == 0) add(arr, col2,j);
			else break;
			if(!chk (arr)) break;
			ans[1]=j;
			for(int k=0; k<8; ++k){
			         	int mat2[8][8];
				 	for(int a=0; a<8; ++a){
                                 		for(int b=0; b<8; ++b){
                                 			mat2[a][b]=mat1[a][b];
                                 		}
		                 	}
                                 	int col3=2;
                                 	con=true;
                                 	if(arr[k][col3] == 1)continue;
                                 	else if(arr[k][col3] == 0) add(arr, col3,k);
                                 	else break;
                                 	if(!chk (arr)) break;
                                 	ans[2]=k;
					for(int l=0; l<8; ++l){
                                                 	int mat3[8][8];
                                                 	for(int a=0; a<8; ++a){
                                                 		for(int b=0; b<8; ++b){
                                                 			mat3[a][b]=mat2[a][b];
                                                 		}
                                                 	}
                                                 	int col4=3;
                                                 	con=true;
                                                 	if(arr[k][col4] == 1)continue;
                                                 	else if(arr[l][col4] == 0) add(arr,col4,l);
                                                 	else break;
                                                 	if(!chk (arr)) break;
                                                 	ans[3]=l;
							for(int m=0; m<8; ++m){
                                                                 	int mat4[8][8];
                                                                 	for(int a=0; a<8; ++a){
                                                                 		for(int b=0; b<8; ++b){
                                                                 			mat4[a][b]=mat3[a][b];
                                                                 		}
                                                                 	}
                                                                 	int col5=4;
                                                                 	con=true;
                                                                 	if(arr[m][col5] == 1)continue;
                                                                 	else if(arr[m][col5] == 0) add(arr,col5,m);
                                                                 	else break;
                                                                 	if(!chk (arr)) break;
                                                                 	ans[4]=m;
									for(int n=0; n<8; ++n){
                                                                                 	int mat5[8][8];
                                                                                 	for(int a=0; a<8; ++a){
                                                                                 		for(int b=0; b<8; ++b){
                                                                                 			mat5[a][b]=mat4[a][b];
                                                                                 		}
                                                                                 	}
                                                                                 	int col6=5;
                                                                                 	con=true;
                                                                                 	if(arr[m][col6] == 1)continue;
                                                                                 	else if(arr[n][col6] == 0) add(arr,col6,n);
                                                                                 	else break;
                                                                                 	if(!chk (arr)) break;
                                                                                 	ans[5]=n;
												for(int o=0; o<8; ++o){                          ;
                                                                                                	int mat6[8][8];
                                                                                                	for(int a=0; a<8; ++a){
                                                                                                		for(int b=0; b<8; ++b){
                                                                                                			mat6[a][b]=mat5[a][b];
                                                                                                		}
                                                                                                	}
                                                                                                	int col7=6;
                                                                                                	con=true;
                                                                                                	if(arr[o][col7] == 1)continue;
                                                                                                	else if(arr[o][col7] == 0) add(arr,col7,o);
                                                                                                	else break;
                                                                                                	if(!chk (arr)) break;
                                                                                                	ans[6]=o;
													for(int p=0; p<8; ++p){
                                                                                                                 	int mat7[8][8];
                                                                                                                 	for(int a=0; a<8; ++a){
                                                                                                                 		for(int b=0; b<8; ++b){
                                                                                                                 			mat7[a][b]=mat6[a][b];
                                                                                                                 		}
                                                                                                                 	}
                                                                                                                 	int col8=7;
                                                                                                                 	con=true;
                                                                                                                 	if(arr[p][col8] == 1)continue;
                                                                                                                 	else if(arr[p][col8] == 0) add(arr,col8,p);
                                                                                                                 	else break;
                                                                                                                 	if(!chk (arr)) break;
                                                                                                                 	ans[7]=p;
													}
												}
									}
							}
					}
			}
		}
	}



		for(int a=0; a<8; a++){
				cout<<ans[a]<<"   ";
			}
			cout<<endl;
			return 0;
}
