#include <iostream>
using namespace std;
#include"node.cpp"

node *takeinput(){
	int data;
	cin>>data;
	node *head = NULL;
	node *temp = NULL;
	while(data!=-1){
		node *n = new node(data);
		if(head==NULL){
			head = n;
		}
		else{
			temp->next = n;
		}
		temp = n;
		cin>>data;
	}
	return head;
}


int midpoint(node* head){
	node* slow = head;
	node* fast = head;
	while(fast!=NULL and fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;

	}
	
	return slow->data;

}

node* mergeLinkedList(node* head1 , node* head2){
	if(head1==NULL or head2==NULL){
		if(head1==NULL) return head2;
		else return head1;
	}
	node* finalhead = NULL;
	node* finaltail = NULL;
	if(head1->data>head2->data){
		finalhead = head2;
		finaltail = head2;
		head2 = head2->next;
	}
	else{
		finalhead = head1;
		finaltail = head1;
		head1 = head1->next;
	}
	while(head1!=NULL and head2!=NULL){
		if(head1->data>head2->data){
			finaltail->next = head2;
			finaltail = head2;
			head2 = head2->next;
		}
		else{
			finaltail->next = head1;
			finaltail = head1;
			head1 = head1->next;
		}
	}

	if(head1==NULL){
		finaltail->next = head2;
	}
	else {
		finaltail->next = head1;
	}

	return finalhead;


}





node* insertNodeRecresively(node *head , int position , int data)
{
	if(head==NULL){
		node *newNode = new node(data);
		head = newNode;
		return head;
	}
	if(position==0){
		node *newNode = new node(data);
		newNode->next = head;
		head = newNode;
		return head;
	}
	head->next = insertNodeRecresively(head->next,position-1,data);
	return head;
}

node* deleteNodeRecrusively(node* head , int position){
	if(head==NULL) return NULL;
	if(position==0){
		node*temp =head;
		head = head->next;
		delete temp;
		return head;
	}
	head->next = deleteNodeRecrusively(head->next,position-1);
	return head;
}

int main(int argc, char const *argv[])
{
	node* head = NULL;
	node* head1 = NULL;
	node* head2 = NULL;
	head1  =	takeinput();
	head2 = takeinput();
	head = mergeLinkedList(head1 ,head2);
	print(head);
	return 0;
}

