//linkedlist.cpp


#include <iostream>
#include <cassert>
#include "linkedlist.h"
using namespace std;

LinkedList* createList(){
	LinkedList* newlist = new LinkedList;
	newlist->head =0;
	newlist->tail =0;

	return newlist;

}
//Precondition: list is pointing to a valif linked list


void insert(LinkedList* list, int value){
  //inserts in the front of the list
	assert(list);
	Node* p = new Node;
	p->data = value;
	p->next = list->head; // 0->head -> segfault
	if(list->head == 0 ){	
		list->tail = p;
    }
    list->head = p;



}
int count(LinkedList* list){
  //
	int c = 0;
	Node* p = list->head;
	while(p){ //Iterating through the list
		c++;
		p = p->next;
	}
	return c;


}

void printList(LinkedList* list){
  //

	Node* p = list->head;
	while(p){ //Iterating through the list
		cout<<p->data<<" "<<endl;
		p = p->next;
	}

}

int minList(Node* head);

int minL(LinkedList* list){
	return minList(list->head);

}

int minList(Node* head){
	assert(head);
	if(head->next == 0){ //base case - the list has only one node
		return head->data;
	}
	int currValue = head->data ; //current nodes value
	int minOfRestOfList = minList(head->next);
	if (currValue < minOfRestOfList) return currValue;
	else
		return minOfRestOfList;
	
}





int main(){
	LinkedList* mylist;
	mylist=createList();
	//insert(0, 5);
	assert(mylist);
	assert(mylist->head == 0);
	assert(mylist->tail == 0);
	cout<<"PASSED creating an empty list"<<endl;
	insert(mylist, 100);
	insert(mylist, 20);
	insert(mylist, 30);
	insert(mylist, 50);
	insert(mylist, 70);
	printList(mylist);
	int min = minL(mylist);

	cout<<"Min element is "<<min<<endl;
}