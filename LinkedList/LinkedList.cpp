#include<iostream>
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


void insert(node* head , int position , int data){
	node *n = new node(data);
	if(head==NULL){
		head = n;
		return;
	}
	if(position==0){
		n->next = head;
		head = n;
	}
	while(position!=1 ){
		head = head->next;
		position--;
	}
	if(head!=NULL){
	node *temp = head->next;
	head->next = n;
	n->next = temp;
 }

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





// coding ninja code
node* insertNode(node* head , int i , int data){
	node *newNode = new node(data);
	node * temp = head;
	int count = 0;
	if(head==NULL){
		return newNode;
	}
	if(i==0){
		newNode->next = head;
		head = newNode;
		return head;
	}
	while(temp!=NULL and count<i-1){
		temp = temp->next;
		count++;
	}
	if(temp!=NULL){
		node *a  = temp->next;
		temp->next = newNode;
		newNode->next = a;
	}	
	return head;
}



void deleteNode(node* head , int position){
	node * temp = head;
	if(position==0){
		head = head->next;
		delete temp;
	}
	while(position!=1){
		temp = temp->next;
		position--;
	}
	node* a = temp->next;
	temp->next = a->next;
	delete a;
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

void print(node *head){
	if(head==NULL){
		cout<<"NULL"<<endl;
	}
	node * temp = head;
	while(head->next!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<head->data<<" NULL"<<endl;
	
	// head = temp;
	// while(head->next!=NULL){
	// 	cout<<head->next<<" ";
	// 	head = head->next;
	// }
	// cout<<endl;
}

int main(int argc, char const *argv[])
{
	node *head = NULL;
	head = takeinput();
	print(head);
	int data , position ;
	cout<<"enter data :";
	cin>>data;
	cout<<"enter position :";
	cin>>position;
	head = insertNodeRecresively(head,position,data);
	print(head);
	cout<<"enter position :";
	cin>>position;
	head = deleteNodeRecrusively(head,position);
	print(head);














	// // statically
	// node n1(1);
	// node n2(2);
	// node n3(3);
	// node n4(4);
	// node n5(5);
	
	// node *head = &n1;
	// n1.next = &n2;
	// n2.next = &n3;
	// n3.next = &n4;
	// n4.next = &n5;
	// print(head);
	// print(head);

	

	// // dynamically
	// node *n3 = new node(10);
	// node *n4 = new node(20);

	// n2.next = n3;
	// n3->next = n4;

	// while(head!=NULL){
	// 	cout<<head->data<<" ";
	// 	head = head->next;
	// }
	// cout<<endl;
	return 0;
}