/*
  YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.
  
  
  CLASS INVARIANTS:
  - Strings are stored in bcdnode objects in a doubly linked list.
  - head points to the first node in the list, or NULL if the list is empty.
  - head points to the "front" of the deque and tail points to the "rear" of the deque.
  - Each bcdnode in the list contains two pointers: 
													1) link_ahead which points to the next bcdnode, or NULL if it's the last node in the list. 
													2) link_back which points to the previous bcdnode, or NULL if it's the first node in the list.
  - To be clear, since this can be counter-intuitive, the list can be traversed from head to tail by following link_ahead and from tail to head by following link_back.
  - New strings can only be added to the rear of the deque (i.e., at the tail of the list) but can be popped from the front and rear.
*/

#include <iostream> // for debugging
#include <string>

#include "our_deque.h"


using namespace std;

//////////////////////////////////////////////////
// Constructor 
our_deque::our_deque()
{
	head = NULL;
	tail = NULL;
}


//////////////////////////////////////////////////
// Destructor
our_deque::~our_deque()
{
	bcdnode *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->link_ahead;
		delete temp;
	}
	tail = NULL;
}





//////////////////////////////////////////////////
// Getters all implemented in header


  
  
//////////////////////////////////////////////////
// Modifiers
void our_deque::pop_front()
{
	bcdnode *temp = head;
	
	//cout << "Entered pop_front!" <<endl;
	if(empty())
		return;
	if(head == tail)
	{
		//cout << "in head == tail case" << endl;
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	
	//cout << "In regular case" << endl;
	head = head->link_ahead;
	head->link_back = NULL;
	
	delete temp;
	
	
}

void our_deque::pop_back()
{
	// create a temp pointer to the tail
	bcdnode *temp = tail;
	
	// if the list is empty, return
	if(empty())
		return;

	// if the list has one element, delete the head and set head and tail to NULL
	if(head == tail)
	{
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	
	// if the list has more than one element, set the tail to the previous node
	tail = tail->link_back;
	tail->link_ahead = NULL;
	
	// delete the temp pointer
	delete temp;
	
}

void our_deque::push(string &newstring)
{
	// cout << "Entered push!" <<endl;
	// cout << "newstring is: " << newstring << endl;
	// create a new temp node
	bcdnode *temp = new bcdnode;
	temp->data = newstring;
	temp->link_ahead = NULL;
	temp->link_back = NULL;
	
	// if the list is empty, set head and tail to the new node
	if(empty()){
		head = temp;
		tail = temp;
		return;
	}

	// if the list is not empty, set the new node's link_back to the tail and set the tail's link_ahead to the new node	
	else{
	tail->link_ahead = temp;
	temp->link_back = tail;
	tail = temp;
	}

	
}

