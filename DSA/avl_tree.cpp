#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int data;
	node * lchild;
	node * rchild;
};
class tree{
	public:
		node * root= new node;
		//static int height;
		//static int mheight;
		tree(){
			root->data= -5;
			root->lchild=NULL;
			root->rchild=NULL;
		}
		void addNode(int a){
			if(root->data ==-5){
				root->data=a;
			}
			else{
			node * tmp=new node;
			tmp->lchild=NULL;
			tmp->rchild=NULL;
			node * itr=root;
			bool con=true;
			while(con){
				if(a> itr->data){
					if(itr->rchild !=NULL) itr=itr->rchild;
					else{
						itr->rchild=tmp;
						con=false;
					}
				}
				else if(a< itr->data){
				       if(itr->lchild !=NULL) itr=itr->lchild;
				       else{
					       itr->lchild=tmp;
					       con=false;
				       }
				}
			}
			tmp->data=a;
			}
		}
		int delNode(int a){
			node * pitr;
			node * itr=root;
			bool con=true;
			while(con){
			//	pitr=itr;
				if(a==itr->data) con=false;
				else if(a> itr->data){
					pitr=itr;
					if(itr->rchild !=NULL) itr=itr->rchild;
					else {
						cout<<"NO such NODE Found"<<endl;
						return -3;
						//con=false;
					}
				}
				else if(a< itr->data){
					pitr=itr;
				       if(itr->lchild !=NULL) itr=itr->lchild;
				       else{
					       cout<<"NO such NODE Found"<<endl;
					       return -3;
					      // con=false;
				       }
				}
			}
			int child=0;
			if(itr->lchild !=NULL) ++child;
			if(itr->rchild !=NULL) ++child;
			if(child == 0){
				cout<<"Deleted node is : "<<itr->data<<endl;
				if(itr == root) delete itr;
				else{
					if(pitr->lchild ==itr) pitr->lchild=NULL;
					else pitr->rchild=NULL;
					delete itr;
				}
			}
			if(child ==1){
				if(itr == root){
					if(itr->lchild != NULL)root=itr->lchild;
					else root= itr->rchild;
					delete itr;
				}
				else{
					if(pitr->lchild==itr){
						if(itr->lchild !=NULL)	pitr->lchild=itr->lchild;
						else pitr->lchild=itr->rchild;
					}
					else{
						if(itr->lchild !=NULL)	pitr->rchild=itr->lchild;
						else pitr->rchild=itr->rchild;
					}
				}
			}
			if(child ==2){
				node * ptemp=itr->rchild;
				node * tmp= ptemp;
				while(tmp->lchild != NULL){
					ptemp=tmp;
				       	tmp= tmp->lchild;
				}
				if(tmp->rchild !=NULL)	ptemp->lchild =tmp->rchild;
				else ptemp->lchild=NULL;
				//if(tmp !=itr->lchild)
				tmp->lchild=itr->lchild;
				tmp->rchild=itr->rchild;
				if(itr ==root){
					root = tmp;
				}
				else{
					if(pitr->lchild == itr) pitr->lchild=tmp;
					else pitr->rchild=tmp;
				}
				delete itr;
			}
		}
		int post_order_display(node * t){
			if(t==NULL){
				cout<<"NULL TREE"<<endl;
				return 0;
			}
			if(t->lchild == NULL){
				cout<<t->data<<"  ";
				if(t->rchild == NULL) return 0;
				//++height;
				//mheight=max(height,mheight);
				post_order_display(t->rchild);
				//--height;
			}
			else{
			//	++height;
			//	mheight=max(height,mheight);
				post_order_display(t->lchild);
			//	--height;
				cout<<t->data<<"  ";       
				if(t->rchild ==NULL){
					return 0;
				}

				post_order_display(t->rchild);
			}
			if(t==root)
			//cout<<"The height of the tree is : "<<mheight <<endl; 

		}




		
		void display(node * t, node* pt=NULL){
			int spc =72;
			node * tmp =t;
//#while(tmp->rchild !=NULL){
			
			for(int i=0; i<spc; i++) cout<<" ";
			cout<<tmp->data<<endl;
			spc /=2;
			for(int i=0; i<spc; i++) cout<<" ";
			cout<<(tmp->lchild)->data;
			for(int i=0; i<spc; i++) cout<<" ";
			cout<<(tmp->rchild)->data;
				

					display(tmp->lchild);
				display(tmp->rchild);

		}
		int cmp(node * ptr, int h=0){
			if(ptr->lchild ==NULL && ptr->rchild ==NULL) return h;
			else {
				if(ptr->lchild==NULL) return cmp(ptr->rchild,h+1);
				else if(ptr->rchild==NULL) return cmp(ptr->lchild, h+1);
				else return max(cmp(ptr->lchild,h+1),cmp(ptr->rchild,h+1));
			}
		}
		};
		//int tree::height=0;
		//int tree::mheight=0;
		int main(){
			tree t1;
			int a;
			cout<<"1.INSERT \t 2.DELETE \t. 3.DISPLAY\t 4.EXIT\t 5.HEIGHT \n";
			cin>>a;
			while(a!=4){
				if(a==1){
					cout<<"Enter the node value : ";
					int b;
					cin>>b;
					t1.addNode(b);
				}
				if(a==2){
					cout<<"Enter the node value : ";
					int b;
					cin>>b;
					t1.delNode(b);
				}
				if(a==3) {
					t1.post_order_display(t1.root);
					cout<<endl;
				}
				if(a==5) cout<<"The Height of the tree is : "<<t1.cmp(root)<<endl;

			cout<<"1.INSERT \t 2.DELETE \t. 3.DISPLAY \t 4.EXIT\t 5.HEIGHT \n";
			cin>>a;
			}
			return 0;
		}








				



