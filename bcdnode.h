/*

  Part of Lab Assignment 6 for CMPT276, winter 2022 by Ben Cameron

 Provides the bcdnode class, (b)en (c)ameron's (d)oubly linked list node (OR (b)oston (c)cream (d)donut node)
 bcdnode is designed to be used with the our_deque class implemented with a doubly linked list to
  

*/

#ifndef __BCDNODE_H__
#define __BCDNODE_H__

#include <string>


using namespace std;

struct bcdnode 
{
	string data;
	bcdnode *link_ahead;
	bcdnode *link_back;
  
};



#endif  // defined __BCDNODE_H__
