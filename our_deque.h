/*

    Part of Lab Assignment 6 for CMPT276, winter 2022 by Ben Cameron

	Provides the bcdnode class, (b)en (c)ameron's (d)oubly linked list node (OR (b)oston (c)cream (d)donut node)
	bcdnode is designed to be used with the our_deque class implemented with a doubly linked list to
  

*/
// CONSTRUCTOR for the our_deque class:
//   our_deque( )
//     Precondition:  None.
//     Postcondition: The deque is empy (i.e. head and tail are both NULL)
//
//GETTERS
//  string front() const
//		Precondition: our_deque is not empty
//		Postcondition: the string in the node at the front of our_deque is returned.
//
//  string back() const
//		Precondition: our_deque is not empty
//		Postcondition: the string in the node at the rear of our_deque is returned.
//
//  bool empty() const 
//    Precondition:  None.
//		Postcondition: returns true if our_deque is empty and false otherwise
//
//  bool single() const
//    Precondition:  None.
//		Postcondition: returns true if our deque only has one element
//
// MODIFIERS
//  void pop_front()
//    Precondition:  None.
//		Postcondition: if our_deque is empty, nothing happens, else element at the front of our deque is removed.
//  
//  void pop_back()
//    Precondition:  None.
//		Postcondition: if our_deque is empty, nothing happens, else element at the rear of our deque is removed.
//
//  void push(string &newstring)
//    Precondition:  None.
//		Postcondition: A new element is added to the rear of our_deque that contains the string newstring
//
// VALUE SEMANTICS for the our_deque class:
//    Assignments and the copy constructor CANNOT be used with our_deque objects.
//
// DYNAMIC MEMORY USAGE by our_deque: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: push

#ifndef __OUR_DEQUE_H__
#define __OUR_DEQUE_H__

#include <string>
#include "bcdnode.h" //provides bcdnode. can implement with struct definition right in the class def below (as in the hand class from Lab 4 to avoid this, but I think this is better)

using namespace std;

class our_deque 
{
public:
  
  //////////////////////////////////////////////////
  // Constructor & destructor
  our_deque();
  ~our_deque();
  
  //////////////////////////////////////////////////
  // Getters
  string front() const { return head->data; }
  string back() const { return tail->data; }
  bool empty() const { return (head == NULL); }  
  bool single() const { return (head == tail && head != NULL); }

  
  
  //////////////////////////////////////////////////
  // Modifiers
  void pop_front();
  void pop_back();
  void push(string &newstring);

  
private:
  
  bcdnode *head;
  bcdnode *tail;
  //size_t numItems; // First card in the hand.
  
};



#endif  // defined __OUR_DEQUE_H__