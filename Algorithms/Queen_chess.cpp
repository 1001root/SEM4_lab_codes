#include<iostream>
using namespace std;
void display(int (&arr)[8][8]);
int add(int (&arr)[8][8], int col1, int pos){
	bool con=true;
	int i=pos;
	for(int a=0; a<8; a++) arr[pos][a] +=1;
	for (int a=0; a<8; a++) arr[a][col1] +=1;
	--arr[pos][col1];
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
		return 0;
}

void display(int (&arr)[8][8]){
	for(int i=0; i<8; i++){
		for(int j=0;j<8; j++){
			cout<< arr[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<"\n -------------------------------------------------------\n";
}
bool chk(int (&arr)[8][8]){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(arr[i][j] > 1)return false;
			}
		}
		return true;
}


	int ans[8];
int main(){
	int arr[8][8];
	bool con=true;
	bool yay=true;
	for(int i=1; i<7; i++){
		con=true;
		int col1=0;
                for(int a=0; a<8; a++){        	 
	        	for(int b=0; b<8; b++){
	        		arr[a][b]=0;
	        	}
	        }
	    	add(arr,col1,i);
		for(int j=0; j<8; j++) if(j !=i){
			int mat1[8][8];
			for(int a=0; a<8; ++a){
				for(int b=0; b<8; ++b){
					mat1[a][b]=arr[a][b];
				}
			}
			int col2=1;
			con=true;
			if(mat1[j][col2] >= 1)continue;
			else if(mat1[j][col2] == 0) add(mat1, col2,j);
			for(int k=0; k<8; k++) if(k != j && k !=i){
				int mat2[8][8];
			       	for(int a=0; a<8; ++a){
					for(int b=0; b<8; ++b){              	
                                		mat2[a][b]=mat1[a][b];       	
                                	}                                    	
                                }                                            	
		                int col3=2;                                  	
                                con=true;                                    	
                                if(mat2[k][col3] >= 1)continue;               	
                                else if(mat2[k][col3] == 0) add(mat2, col3,k); 	
                                for(int l=0; l<8; l++) if(l!=i && l !=j && l!=k){                                     	
				        int mat3[8][8];                           	  	
                                        for(int a=0; a<8; ++a){                             	
                                        	for(int b=0; b<8; ++b){                     	
                                        		mat3[a][b]=mat2[a][b];              	
                                        	}                                           	
                                        }                                                   	
                                        int col4=3;                                         	
                                        con=true;                                           	
                                        if(mat3[l][col4] >= 1)continue;                      	
                                        else if(mat3[l][col4] == 0){
					       	add(mat3,col4,l);         	
					}
                                        for(int m=0; m<8; ++m) if(m!=i && m!=j && m!=k && m!=l){
					        int mat4[8][8];                           		  	
                                                for(int a=0; a<8; ++a){                                     	
                                                	for(int b=0; b<8; ++b){                             	
                                                		mat4[a][b]=mat3[a][b];                      	
                                                	}                                                   	
                                                }                                                           	
                                                int col5=4;                                                 	
                                                con=true;                                                   	
                                                if(mat4[m][col5] >= 1)continue;                              	
                                                else if(mat4[m][col5] == 0) add(mat4,col5,m);                 	
                                                for(int n=0; n<8; ++n) if(n!=i && n!=j && n!=k && n!=l && n!=m ){                                     
						        int mat5[8][8];                           			  	
                                                        for(int a=0; a<8; ++a){                                             	
                                                        	for(int b=0; b<8; ++b){                                     	
                                                        		mat5[a][b]=mat4[a][b];                              	
                                                        	}                                                           	
                                                        }                                                                   	
                                                        int col6=5;                                                         	
                                                        con=true;                                                           	
                                                        if(mat5[n][col6] >= 1)continue;                                      	
                                                        else if(mat5[n][col6] == 0) add(mat5,col6,n);  
							display(mat5);			
                                                        for(int o=0; o<8; ++o) if(o!=i && o!=j && o!=k && o!=l && o!=m && o!= n){
								int mat6[8][8];                            					
                                                        	for(int a=0; a<8; ++a){                                                            
                                                        		for(int b=0; b<8; ++b){                                                    
                                                        			mat6[a][b]=mat5[a][b];                                             
                                                        		}                                                                          
                                                        	}                                                                                  
                                                        	int col7=6;                                                                        
                                                        	con=true;                                                                          
                                                        	if(mat6[o][col7] >= 1)continue;                                                     
                                                        	else if(mat6[o][col7] == 0) add(mat6,col7,o);                                        
                                                                for(int p=1; p<7; ++p) if(p!=i && p!=j && p!=k && p!=l && p!=m && p!=n && p!=o){
                                                                        int mat7[8][8];
								        for(int a=0; a<8; ++a){
                                                                        	for(int b=0; b<8; ++b){
                                                                        		mat7[a][b]=mat6[a][b];
                                                                        	}
                                                                        }
                                                                        int col8=7;
                                                                        con=true;
                                                                        if(mat7[p][col8] >= 1)continue;
                                                                        else if(mat7[p][col8] == 0) {
										ans[0]=i;
										ans[1]=j;
										ans[2]=k;
										ans[3]=l;
										ans[4]=m;
										ans[5]=n;
										ans[6]=o;
										ans[7]=p;
										yay=false;
									}
										break;
								}
							if(yay==false) break;
							}
						if(yay==false) break;
						}
					if(yay==false) break;
					}
				if(yay==false) break;
				}
			if(yay==false) break;
			}
		if(yay==false) break;
		}
	if(yay==false) break;
	}
	for(int a=0; a<8; a++){             	
			cout<<ans[a]<<"   ";	
		}                           	
		cout<<endl;                 	
		return 0;                   	
}
