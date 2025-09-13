/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef> // null error
#include <iostream> //std::cout error

void printList(Node* head) {
  while(head!=NULL){
    std::cout << head-> value << " ";
    head = head -> next;
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[])
{
  // building an input list 12345
  Node* in = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, NULL)))));
  Node* odds = NULL; // init odds and evens to null to start
  Node* evens = NULL;

  split(in, odds, evens); // call to function

  // checking:
  std::cout << "in (after split): ";
  printList(in); //ideally empty

  std::cout << "odds: ";
  printList(odds); //135

  std::cout << "evens: ";
  printList(evens); //24





  // correcting the valgrind error
  while (odds != NULL) {
    Node* temp=odds;
    odds = odds-> next;
    delete temp;
  }

  while (evens != NULL) {
    Node* temp = evens;
    evens=evens->next;
    delete temp;
  }


  return 0;
}
