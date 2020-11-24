#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h> 
#define SIZE 100

char op_stack[SIZE];
int num_stack[SIZE];
int op_top=-1,num_top=-1;


typedef struct node{
	int flg;
	int num;
	struct node *next;
}node;

node *HEAD=NULL;


int insert(int value, int flag){
	node *p = (node*)malloc(sizeof(node));
	p->next=NULL;
	p->flg = flag;
	p->num = value;

	if (HEAD==NULL){
		HEAD=p;
		p=NULL;
	}else{
		node *temp = HEAD;
		while(temp->next != NULL)
			temp=temp->next;
		
		temp->next=p;
		p=NULL;
		temp=NULL;
	}
	return 1;
}


int display(){
	if(HEAD==NULL){
		printf("\n\tLIST IS EMPTY!!");
		return 0;
	}else{
		node *temp=HEAD;
		printf("\nDisplay: ");
		while(temp!=NULL){
			if (temp->flg)
				printf("%c ",temp->num);
			else
				printf("%d ",temp->num);
			temp=temp->next;
		}
		return 1;
	}
}

int is_numstk_full(){
	if(num_top==SIZE-1)
		return 1;
	else
		return 0;
}

int is_numstk_empty(){
	if(num_top==-1)
		return 1;
	else
		return 0;
}

void push_numstk(int item){
	if(is_numstk_full()){
		printf("\n\tSTACK OVERFLOW!");
		return;
	}
	num_stack[++num_top] = item;
}

int pop_numstk(){
	if(is_numstk_empty()){
		printf("\n\tSTACK UNDERFLOW!");
		return -1;
	}
	return num_stack[num_top--];
}

int is_opstk_empty(){
	if(op_top==-1)
		return 1;
	else
		return 0;
}

int is_opstk_full(){
	if(op_top==SIZE-1)
		return 1;
	else
		return 0;
}

void push_opstk(char item){
	if(is_opstk_full()){
		printf("\n\t OP STACK OVERFLOW!");
		return;
	}
	op_stack[++op_top] = item;
}

char pop_opstk(){
	if(is_opstk_empty()){
		printf("\n\t OP STACK UNDERFLOW!");
		return -1;
	}
	return op_stack[op_top--];
}

int get_precedence(char ch){
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

int is_operator(char ch){
    if(
        ch == '^' ||
        ch == '+' ||
        ch == '-' ||
        ch == '*' ||
        ch == '/'
    ){
        return 1;
    }else{
        return 0;
    }
}

void infix_to_postfix(char* infix){
	char c;
	for (int i=0;i<strlen(infix);i++){
		// c = infix[i];
		if(isdigit(infix[i])){
			int d = infix[i]-'0';
			while (isdigit(infix[i+1])){
				d*=10;
				d+=infix[i+1]-'0';
				i++;
			}
			insert(d,0);
		}else{
			insert(infix[i],1);
		}
			
	}
}

int main(){
    char infix[SIZE] = "10+(3*4-(4/2^2)*5)*3";
	infix_to_postfix(infix);
	display();

    return 0;
}