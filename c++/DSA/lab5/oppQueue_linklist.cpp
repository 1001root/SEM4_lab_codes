#include<iostream>
using namespace std;
class list{
	public:
	int data;
	list * next;
	list * previous;
};

class queue{
	public:
	list * head;
	list * tail;
	public:
	queue(){
		head = NULL;
		tail = NULL;
	}
	bool is_empty(){
		return(head == NULL || tail == NULL);
	}
	void enqueue(int a){
		list * temp;
		temp = new list;
		if(is_empty()){
			head=temp;
			tail= temp;
			temp->next=NULL;
			temp->previous=NULL;
		}
		
		else{
			head->next=temp;
			temp->previous=head;
		//	temp->previous=head;
			head=temp;
			head->next=NULL;
		}
		temp->data=a;
	}
	int deque(){
		if(! is_empty()){
			list * tmp;
			tmp = tail;
			cout<<tmp->data<<endl;
			tail=tail->next;
			if(tail != NULL)
			tail->previous=NULL;
			else{
				head=NULL;
				delete head;
			}
			delete tmp;
		}
		else {
			cout<<"Empty"<<endl;
		}
	}

	int display(){
		list * tem;
		tem = head;
		while(tem != NULL){
			cout<<tem->data<<"     ";
			tem = tem->previous;
		}
		cout<<endl;
		return 0;
	}


};
int main(){
	queue one;
	bool con= true;
	cout<<"You have a Queue"<<endl;
	cout<<"1.Enque. 2.Deque 3.Display 9.Quit"<<endl;
	while(con){
		cout<<"?? : ";
		int a;
		cin>>a;
		if(a==1){
			int b;
			cout<<"value"<<endl;
			cin>>b;
		one.enqueue(b);
		}
		else if(a==2){
			one.deque();
		}
		else if(a==3){
			one.display();
		}
		else if(a==9){
			con=false;
		}

	}
	return 0;
}


			
