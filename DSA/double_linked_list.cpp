#include<iostream>
using namespace std;
class node{
	public:
	int  key;
	node * prev;
	node * next;
};

class list{
	node* head;
	node* tail;
	public:
	list(){
		head=NULL;
		tail=NULL;
	}
	bool is_empty(){
		return(head==NULL);
	}
	void pushBack(int a){
		node *tmp = new node;
		if(is_empty()){
			tmp->next=NULL;
			tmp->prev=NULL;
			head=tmp;
			tail=tmp;
		}
		else{
			tail->next=tmp;
			tmp->prev=tail;
			tmp->next=NULL;
			tail=tmp;
		}
		tmp->key=a;
		cout<<"Inserting at Back : "<<a<<endl;
	}
	int popBack(){
		if(is_empty()){
			cout<<"Empty List"<<endl;
			return -1;
		}
		node * tmp=NULL;
		int val= tail->key;
		cout<<"The deleted node is tail : "<<val<<endl;
		if(tail->prev!=NULL){
		tmp=tail->prev;
		tmp->next=NULL;
		delete tail;
		tail = tmp;
		}
		else{
			delete head;
			head = NULL;
			tail=NULL;
		}
		return val;
	}
	void pushFront(int a){
		if(is_empty()) pushBack(a);
		else{
			node * tmp =new node;
			tmp->next=head;
			head->prev=tmp;
			tmp->prev=NULL;
			tmp->key=a;
			head=tmp;
			cout<<"Inserting at Front : "<<a<<endl; 
		}
	}
	int popFront(){
		if(is_empty()){
			cout<<"Empty List"<<endl;
			return -2;
		}
		int val=head->key;
		cout<<"The deleted node is Head : "<<val<<endl;
		if(head->next == NULL){
			delete head;
			head=NULL;
			tail=NULL;
		}
		else{
			node * tmp=head->next;
			delete head;
			head= tmp;
			head->prev=NULL;
		}
		return val;
	}

	void display(){
		node * tmp=head;
		while(tmp != NULL){
			cout<<tmp->key<<"\t";
			tmp=tmp->next;
		}
		cout<<endl;
	}
	int insertBefore(int a, int b){
		node * tmp=head;
		while(tmp->key != a){
			if(tmp==NULL){
				cout<<"No value found"<<endl;
				return -1;
			}
			tmp= tmp->next;
		}
		node *ins=new node;
		if(tmp != head){
		ins->prev=(tmp->prev)->next;
		(tmp->prev)->next=ins;
		}
		else if (tmp ==head){
			ins->prev=NULL;
			head=ins;
		}
		tmp->prev=ins;
		ins->next=tmp;
		ins->key=b;
		cout<<"Inserting : "<<b<<" before Value : "<<a<<endl;
	}
	int insertAfter(int  a, int b){
		if(is_empty()){
			cout<<"Empty list"<<endl;
			return -1;
		}
		node *tmp=head;
		while(tmp->key !=a){
			tmp=tmp->next;
			if(tmp==NULL){
				cout<<"No sought value found"<<endl;
				return -1;
			}
		}
		node *ins = new node;
		ins->prev=tmp;
		if(tmp->next !=NULL){
			ins->next=tmp->next;
			(tmp->next)->prev=ins;
		}
		else{
			ins->next=NULL;
			tail =ins;
		}
		tmp->next=ins;
		ins->key=b;
		cout<<"Inserting : "<<b<<" After value : "<<a<<endl;
	}
	int insertAt(int pos, int b){
		if(is_empty() && pos >0){
			cout<<"Out of Bounds"<<endl;
			return -3;
		}
		if(pos == 0){
		       	pushFront(b);
			return 0;
		}
		else {
			node *tmp = head;
			int tpos=pos;
			while(tpos--){
				if(tmp==NULL){
					cout<<"Out of Bounds"<<endl;
					return -1;
				}
				tmp= tmp->next;
			}
			node * ins= new node;
			if(tmp !=NULL){
				ins->prev=tmp->prev;
				ins->next=tmp;
				(tmp->prev)->next=ins;
				tmp->prev=ins;
				ins->key =b;
			}
			else if(tmp==NULL)  pushBack(b);
			cout<<"Inserting : "<<b<<" At position : "<<pos<<endl; 
		}
	}
	int delBefore(int a){
		if(is_empty()){
			cout<<"Empty list"<<endl;
			return -1;
		}
		else if(head->next ==NULL){
			cout<<"Only one Element"<<endl;
			return -2;
		}
		node * tmp=head;
		while(tmp->key !=a){
		       if(tmp==NULL){
			       cout<<"Out of Bounds"<<endl;
			       return -3;
		       }
			tmp= tmp->next;
		}
		node * del= tmp->prev;
		if(tmp == head){
			cout<<"out of bounds"<<endl;
			return -3;
		}
		if(tmp->prev != head){
			((tmp->prev)->prev)->next = tmp;
			tmp->prev = (tmp->prev)->prev;
		}
		else{
			tmp->prev=NULL;
			head=tmp;
		}
		int val= del->key;
		cout<<"Deleting : "<<val<<endl;
		delete del;
		return val;
	}
	int delAfter(int a){
		if(is_empty()){
			cout<<"Empty list"<<endl;
			return -1;
		}
		else if(head->next ==NULL){
			cout<<"Just one node "<<endl;
			return -2;
		}
		node * tmp=head;
		while(tmp->key !=a){
		 	if(tmp==NULL){
			  cout<<"No value found"<<endl;
			}	  
			tmp= tmp->next;
		}
		node * del=tmp->next;
		if(del == NULL){
			cout<<"Out of Bounds"<<endl;
			return -3;
		}
		if(del->next==NULL) {
			tmp->next=NULL;
			tail=tmp->prev;
		}
		else{
			(del->next)->prev=tmp;
			del= del->next;
		}
		int val=del->key;
		cout<<"Deleting : "<<val<<endl;
		delete del;
		return val;
	}
	int delAt(int pos){
		if(is_empty()){
			cout<<"Empty List"<<endl;
			return -1;
		}
		node * tmp=head;
		if(pos==0) popFront();
		else {
			int tpos=pos;
			while(tpos--){
				if(tmp==NULL){
			 		cout<<"Out of Bounds"<<endl;
					return -2;
				}	
				tmp=tmp->next;
			}
			if(tmp ==NULL){
				cout<<"Out of bounds"<<endl;
				return -2;
			}
			int val=tmp->key;
			cout<<"Deleted value at pos : "<<pos <<" is : "<<val<<endl;
			if(tmp->next == NULL){
				(tmp->prev)->next=NULL;
				tail=tmp->prev;
			}
			else if(tmp->next != NULL){
				(tmp->prev)->next= tmp->next;
				(tmp->next)->prev=tmp->prev;
			}
			delete tmp;
			return val;
		}
		return 0;
	}
	void print_empty(){
		if(is_empty())
			cout<<"Empty List"<<endl;
		else
			cout<<"Crowded List"<<endl;
	}



};
int data(){
	cout<<"Data??";
	int val;
	cin>>val;
	return val;
}

int main(){
	list l1;
	cout<<"Enter the process"<<endl;
	bool con=true;
	while(con){
	cout<<"1.Empty\t 2.pushBack\t 3.Display \t4.Exit\t 5.popBack\t 6.pushFront\t 7.popFront\t8.insertBefore\t9.insertAfter\t10.insertAt\t11.delBefore\t12.delAfter\t13.delAt\n";
	int a;
	cin>>a;
	if(a==1)l1.print_empty();
	else if(a==2)l1.pushBack(data());
	else if(a==3)l1.display();
	else if(a==5)l1.popBack();
	else if(a==6)l1.pushFront(data());
	else if(a==7)l1.popFront();
	else if(a==8){
		if(l1.is_empty())	cout<<"List Empty"<<endl;
		else{
			int x,y;
			cout<<"Enter the value before and data : ";
			cin>>x>>y;
			l1.insertBefore(x,y);
		}
	}
	else if(a==9){
		if(l1.is_empty())	cout<<"List Empty"<<endl;
		else{
			int x,y;
			cout<<"Enter the value after and data : ";
			cin>>x>>y;
			l1.insertAfter(x,y);
		}
	}
	else if(a==10){
		int x,y;
		cout<<"Enter the position and value : ";
		cin>>x>>y;
		l1.insertAt(x,y);
	}
	else if(a==11){
		if(l1.is_empty())	cout<<"List Empty"<<endl;
		else l1.delBefore(data());
	}
	else if(a==12){
		  if(l1.is_empty()) cout<<"List Empty"<<endl;
		  else l1.delAfter(data());
	}
	else if(a==13) l1.delAt(data());
	else con=false;
	}

	return 0;
}
