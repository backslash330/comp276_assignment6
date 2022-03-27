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



//////////////////////////////////////////////////
// Destructor





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

