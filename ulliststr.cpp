#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if (tail_==NULL){
    // list is empty so allocate a whole new Item
    tail_ = new Item();
    head_ = tail_ ;
    tail_->val[0] =  val;
    tail_->first = 0;
    tail_-> last = 1;
  }

  else if (tail_->last << ARRSIZE) {
    // space avail in current tail 
    tail_ -> val[tail_ -> last] = val;
    tail_->last++;
  }

  else {
    // tail is full so allocate a new node
    Item* newNode = new Item();
    newNode->val[0] = val;
    newNode->first = 0;
    newNode->last = 1;
    newNode->prev = tail_;
    tail_->next = newNode;
    tail_ = newNode;
  }

  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  if (head_==NULL){
    // list empty - allocate new Item
    head_ = new Item();
    tail_ = head_;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
  }

  else if (head_ -> first > 0) {
    // space before first element
    head_->first--;
    head_->val[head_->first] = val;
  }

  else {
    // no front space - allocate new node
    Item* newNode = new Item();
    newNode->val[ARRSIZE-1] = val;
    newNode->first = ARRSIZE-1;
    newNode->last = ARRSIZE;
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
  }
  size_++;
}

void ULListStr::pop_back()
{
  if (tail_==NULL) return; 

  tail_->last--;
  size_--;

  if (tail_->last ==tail_->first) { // the node is empty so remove it
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL) tail_->next = NULL;
    else head_ = NULL; 
    delete temp;
  }
}

void ULListStr::pop_front()
{
  if (head_ == NULL) return; 

  head_->first++;
  size_--;

  if (head_->first == head_->last) 
  { 
    // node is empty so remove it
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL) head_->prev = NULL;
    else tail_ = NULL; // list is now empty
    delete temp;
  }
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_) return NULL;

  Item* curr = head_;
  while (curr != NULL) {
    size_t count = curr->last - curr->first;
    if (loc < count) {
      return &curr->val[curr->first + loc];
    }
    else {
      loc -= count;
      curr = curr->next;
    }
  }
  return NULL;
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
