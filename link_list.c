#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *pNext;
}*link_list=NULL,*double_link_list=NULL;

int get_length(){
	int counter=0;
	struct Node* temp=link_list;
	while(temp!=NULL){
		counter++;
		temp=temp->pNext;
	}
	return counter;
}

void display(){
	struct Node * current = link_list;
	while(current!=NULL){
		printf("->%d",current->data);
		current = current->pNext;
		}
	printf("\n");
	return;
}

void insert(int index,int value){
	struct Node*ptr=link_list;
	if(index<0 || index> get_length()){
		printf("invald index\n");
		return;
	}
	struct Node* temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data =value;
	temp->pNext=NULL;
	if(index==0){
		temp->pNext=link_list;
		link_list=temp;
	}
	else{
		for(int i=0;i<index-1;i++){
			ptr=ptr->pNext;
		}
		temp->pNext=ptr->pNext;
		ptr->pNext=temp;
	}
}

void delete(int index){
	struct Node*head,*tail;
	head=link_list;
	if(index<0||index>get_length()){
		printf("invalid index\n");
	}
	else if(index==0){
		link_list= head->pNext;
		free(head);
		}
	else{
		for(int i=0;i<index;i++){
			tail=head;
			head=head->pNext;
			}
		tail->pNext=head->pNext;
		free(head);
	}
}

void reverse(){
	struct Node*first=NULL,*second=NULL,*third=NULL;
	if(get_length()<2){
		return;
	}
	else if(get_length()==2){
		second=link_list;
		first=second->pNext;
		first->pNext=second;
		link_list=first;
		second->pNext=NULL;
	}
	else{
		third=link_list;
		second=third->pNext;
		first=second->pNext;
		third->pNext=NULL;
		while(first!=NULL){
			second->pNext=third;
			third=second;
			second=first;
			first=first->pNext;
			}
		second->pNext=third;
		link_list=second;
	}
	display();
}	

int main(){
	insert(0,2);
	insert(1,5);
	insert(2,10);
	insert(3,6);
	insert(4,77);
	insert(5,54);
	insert(0,7);
	insert(3,17);
	display();
	delete(5);
	display();
	delete(3);
	display();
	reverse();
	return 0;
}
