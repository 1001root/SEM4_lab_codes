#include<iostream>
using namespace std;
struct node{
	int data;
	int bf;
	node* parent;
	node* lchild;
	node* rchild;
};
class avl{
	public:
		node* root;
		avl(){
			root = NULL;
		}
		int insert(int a){
			if(root == NULL){
				root= new node;
				root->data=a;
				root->parent=NULL;
				root->lchild=NULL;
				root->rchild=NULL;
				return 0;
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
						tmp->parent=itr;
						con=false;
					}
				}
				else if(a< itr->data){
				       if(itr->lchild !=NULL) itr=itr->lchild;
				       else{
					       itr->lchild=tmp;
					       tmp->parent=itr;
					       con=false;
				       }
				}
			}
			tmp->data=a;
			
			node * witr=tmp;
			while(witr != NULL){
				int lheight,rheight;
				if(witr->lchild != NULL) lheight= cmp(witr->lchild,1);
			       	else lheight=0;
				if(witr->rchild != NULL) rheight= cmp(witr->rchild,1); 
				else rheight=0;
				witr->bf=lheight - rheight;
				if(abs(witr->bf)<2){
					witr=witr->parent;
					continue;
				}
				else{
					if(witr->bf == -2 && ((witr->lchild == NULL) || (witr->lchild !=NULL && (witr->lchild)->bf <=0))) left_rotate(witr);
					else if(witr->bf ==-2 && (witr->lchild)->bf >0) right_left_rotate(witr);
					else if(witr->bf == 2 && ((witr->rchild ==NULL) || (witr->rchild != NULL && (witr->rchild)->bf >=0))) right_rotate(witr);
					else if(witr->bf ==2 && (witr->rchild)->bf<0) left_right_rotate(witr);
				/*	if(witr->lchild != NULL) lheight= cmp(witr->lchild,1);
					else lheight=0;
					if(witr->rchild != NULL) rheight= cmp(witr->rchild,1);
					else rheight=0;
					witr->bf=lheight - rheight;*/
					witr=witr->parent;

				}
			}
		}
		}
		void left_rotate(node * ptr){
			node * tmp=ptr;
			node * rtemp=tmp->rchild;
			if(tmp != root){
				if((tmp->parent)->lchild ==tmp) (tmp->parent)->lchild =rtemp;
				else (tmp->parent)->rchild = rtemp;
			}
			else  root=rtemp;
			rtemp->parent=tmp->parent;
			tmp->rchild=rtemp->lchild;
			if(rtemp->lchild != NULL) (rtemp->lchild)->parent=tmp;
			rtemp->lchild=tmp;
			tmp->parent=rtemp;
		}
		void right_rotate(node * ptr){
			node * tmp=ptr;
			node * ltemp=tmp->lchild;
			if(tmp != root){
				if((tmp->parent)->lchild == tmp) (tmp->parent)->lchild=ltemp;
				else (tmp->parent)->rchild=ltemp;
			}
			else root=ltemp;
			ltemp->parent=tmp->parent;
			tmp->lchild=ltemp->rchild;
			if(ltemp->rchild !=NULL) (ltemp->rchild)->parent=tmp;
			ltemp->rchild=tmp;
			tmp->parent = ltemp;
		}
	
		void left_right_rotate(node * ptr){
			//node * tmp= ptr;
			//node* rtemp= tmp->rchild;
			//node * ltemp = tmp->lchild;
			left_rotate(ptr->lchild);
			right_rotate(ptr);
		}
		void right_left_rotate(node * ptr){
			right_rotate(ptr->rchild);
			left_rotate(ptr);

		}
		int cmp(node * ptr, int h){
			if(ptr->lchild ==NULL && ptr->rchild ==NULL) return h;
			else {
				++h;
				if(ptr->lchild==NULL) return cmp(ptr->rchild,h);
				else if(ptr->rchild==NULL) return cmp(ptr->lchild, h);
				else return max(cmp(ptr->lchild,h),cmp(ptr->rchild,h));
			}
		}
		node * search(int a, node * ptr){
			node * itr =ptr;
			bool con= true;
			while(con){
				if(itr == NULL){
					cout<<"NO Such NODE FOUND !!!"<<endl;
					return NULL;
				}
				if(a>itr->data) itr= itr->rchild;
			        else if(a< itr->data) itr=itr->lchild;
				else if(a == itr->data) return itr;
			}
		}
		int getVal(node * tmp){
			return tmp->data;
		}
		int getParent(node * tmp){
			if(tmp->parent != NULL) return (tmp->parent)->data;
		//	else cout<<"Root";
			return 0;
		}
		int getLchild(node * tmp){
			if(tmp->lchild != NULL)	return (tmp->lchild)->data;
		//	else cout<<"NULL lChild";
			return 0;
		}
		int getRchild(node * tmp){
			if(tmp->rchild != NULL)	return (tmp->rchild)->data;
		//	else cout<<"NULL rChild";
			return 0;
		}
		int getBF(node * tmp){
			return tmp->bf;
		}
};
int main(){
	avl t1;
	int a;
	cout<<"1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT\t5.Height\t6.SEARCH\t7.Root\t8.TreeHeight\n";
	cin>>a;
	while(a!=4){
		if(a==1){
			cout<<"Enter the node value : ";
			int b;
			cin>>b;
			t1.insert(b);
		}
		if(a==2){
			cout<<"Enter the node value : ";
			int b;
			cin>>b;
		//	t1.delNode(b);
		}
		if(a==3) {
		//	t1.post_order_display(t1.root);
			cout<<endl;
		}
		if(a==6){
			cout<<"Enter the value : ";
			int tmp;
			cin>>tmp;
			node * val;
			if(t1.root == NULL) cout<<"Empty Tree"<<endl;
			else{
				val = t1.search(tmp, t1.root);
				if(val != NULL) cout<<"Found the node -- Parent : "<<t1.getParent(val)<<"  lchild : "<<t1.getLchild(val)<<"  rchild : "<<t1.getRchild(val)<<"BF : "<<t1.getBF(val)<<endl;
			}
		}
		if(a==5){
			cout<<"Enter the root node : ";
			int tmp;
			cin>>tmp;
			node * itr= t1.search(tmp, t1.root);
			if( itr != NULL) cout<<"Height of the node is : "<<t1.cmp(itr,0)<<endl;
		}
		if(a==7){
			if(t1.root != NULL) cout<<"The Root is : "<<t1.getVal(t1.root)<<endl;
			else cout<<"Empty Tree"<<endl;
		}		
		if(a==8){
			if(t1.root != NULL) cout<<"The Tree Height is : "<<t1.cmp(t1.root,0)<<endl;
			else cout<<"Empty tree"<<endl;
		}
		cout<<"1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT\t5.Height\t6.SEARCH\t7.Root\t8.TreeHeight\n";
		cin>>a;
		}
	return 0;
}


