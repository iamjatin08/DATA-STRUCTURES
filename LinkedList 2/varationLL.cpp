#include <iostream>
using namespace std;
#include"node.cpp"
// doublly linked list
class Double{
	int data;
	Double * next;
	Double * prev;
	Double(int data){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};





										



class Pair{
public:
	node * head;
	node * tail;
};

Pair reverseLL2(node * head){
	Pair ans;
	if(head == NULL or head->next == NULL){
		ans.head = head;
		ans.tail = head;
		return ans;
	}
	Pair smallAns = reverseLL2(head->next);
	smallAns.tail->next = head;
	head->next = NULL;

	ans.head = smallAns.head;
	ans.tail = head;
	return ans;

}



node* reverseLLbetter(node * head){
	return reverseLL2(head).head;
}

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

node* reverseLL(node * head){
	if(head==NULL or head->next==NULL) return head;

	node * temp = head->next;
	node * reversed = reverseLL(temp);
	temp->next = head;
	head->next = NULL;
	return reversed;


}
node* reverseLL3(node* head){
	if(head==NULL or head->next==NULL) return head;
	node *smallAns = reverseLL3(head->next);
	node * temp = smallAns;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallAns;
}
//my code
node* reverseIT(node* head){
	if(head == NULL or head->next==NULL) return head;
	node * slow = NULL;
	node * fast = head->next;
	while(fast!=NULL){
		head->next = slow;
		slow = head;
		head = fast;
		fast = fast->next;

	}
	head->next = slow;
	return head;
}
// coding ninja code
node* reverseIterative(node * head){
	
	if(head==NULL or head->next == NULL) return head;
	node* curr = head;
	node* prev = NULL;
	node* nt = head->next;
	while(curr->next!=NULL){
		curr->next = prev;
		prev = curr;
		curr  = nt;
		nt = nt->next;

	}
	curr->next = prev;
	return curr;

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
}



node * circular(node* head){
	head = takeinput();
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = head;
	return head;

}



int main(int argc, char const *argv[])
{
	node * head  = NULL;
	head = takeinput();
	head = reverseIterative(head);
	print(head);
	
	return 0;
}