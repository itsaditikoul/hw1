/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>


/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // base case - when theres nothing left to process
  if (in==NULL) {
    return;
  }

  // take curr node
  Node* current = in;
  in = in->next; // moves it forward here
  current -> next = NULL; // detaches the curr node

  // recursive xase
  split(in, odds, evens);

  // put curr into odds or evens
  if (current->value % 2 ==0) { // if its even then put in front of evens
    current->next = evens;
    evens = current;
  }
  else { // if its odd then put in front of odds
    current->next = odds;
    odds = current;
  }


}

/* If you needed a helper function, write it here */
