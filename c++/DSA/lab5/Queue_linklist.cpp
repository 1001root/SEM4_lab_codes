#include<iostream>
using namespace std;
class list{
	public:
	int data;
	list * next;
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
		return(head == NULL);
	}

	void enque(int a){
		list * temp;
		temp = new list;
		if(is_empty()){
			head=temp;
			tail= temp;
		}
		else{
			tail->next=temp;
			tail=temp;

		}
		temp->data=a;
	}
	int deque(){
		if(! is_empty()){
			list * tmp;
			tmp = head;
			cout<<head->data<<endl;
			head = head->next;
//			delete tmp;
			return 1;
		}
		else
			cout<<"empty";
		return 2;
	}
	int display(){
		list * tem;
		tem = head;
		while(tem != NULL){
			cout<<tem->data<<"     ";
			tem = tem->next;
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
		one.enque(b);
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


		
