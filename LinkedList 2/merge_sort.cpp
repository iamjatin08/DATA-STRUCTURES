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


node* midPoint(node* head){
	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
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


node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	node* c;

	if(a->data <= b->data){
		c = a;
		c->next = merge(a->next,b);
	}else{
		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}



node* mergeSort(node* head){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* a = head;

	node* mid = midPoint(head);

	node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a,b);
	return c;
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
	node* head = NULL;
	head = takeinput();
	head = mergeSort(head);
	print(head);
	return 0;
}

