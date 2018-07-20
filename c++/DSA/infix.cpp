//INFIX TO POSTFIX
//2 simple rules
//two operators of same priority can not stay together in stack
//lower priority operator cannot stay on top of higher priority operator in stack
//voila you got yourslf the algorithm
//now for postfix to infix:
//go ahead until you encounter an operator , do the calculation with the preceeding two operands and keep value as X as move ahead untill you find another operator and loop continues...


#include<iostream>
using namespace std;
class stack{
	private:
		char arr[50];
		int top;
	public:
		stack(){
			top=-1;
		}
		bool is_empty(){
			return (top==-1);
		}
		bool is_full(){
			return (top==49);
		}
		void push(char a){
			if(! is_full())	arr[++top]=a;
			else  cout<<"Stack overflowed"<<endl;
		}
		char pop(){
			if(! is_empty()) return arr[top--];
			else return '!';
		}
		char peek(){
			if(! is_empty()) return arr[top];
			else	return '!';
		}
};

int priority(char a){
	if(a == '^') return 3;
	else if(a == '/' || a== '*') return 2;
	else if(a == '+' || a== '-') return 1;
	else if(a == '(') return -2;
	else if(a== ')') return -3;
	else
		return -5;
}

int main(){
	stack s;
	char operand[50];
	char expression[100];
	cout<<"Enter the Expression : "<<endl;
	cin>>expression;
	char * pt;
	pt = expression;
	int i=0;
	while(* pt != '\0' ){
		if((*pt >=65 && *pt <=90) || (*pt >=97 && *pt <=122) || (*pt >=48 && * pt <=57)){
			operand[i]=*pt;
			i++;
		}
		else{
			if(! s.is_empty()){
				if(priority(*pt) == -3){
						while(s.peek() !='('){
							operand[i]=s.pop();
							//cout<<operand[i]<<"hello"<<endl;
							i++;
						}
						s.pop();
				}
				else if(priority(*pt)== -2 || priority(*pt)== 3) s.push(*pt);
				else if(priority(s.peek()) >= priority(*pt)){
					while(priority(s.peek()) >= priority(*pt)){
						operand[i]=s.pop();
						i++;
					}
					s.push(*pt);
				}
				else s.push(*pt);
			}
			else s.push(*pt);
		}
		pt++;
	}
	if(! s.is_empty()){
		while( ! s.is_empty()){
			if(s.peek() != '('){
			operand[i]=s.pop();
			i++;
			}
			else s.pop();
			}
	}
	cout<<"Results"<<endl;
	for(int j=0; j<i; j++) cout<<operand[j];
	cout<<endl;
	return 0;
}


			

