#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>
#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:
template<typename T>
class LinkedList
{
  int listSize =0;
  Node<T> * head;
  Node<T> * tail;
  Node<T> * current;
public:
  LinkedList(){
    head = nullptr;
    tail = nullptr;
    listSize = 0;
  }
  LinkedList(std::initializer_list<T> list) {

    head = nullptr;
    tail = nullptr;
    listSize = 0;

    for (auto & itemInList: list) {
      push_back(itemInList);
    }

  }
    NodeIterator<T> begin() { return NodeIterator<T>(head); }
    NodeIterator<T> begin() const { return NodeIterator<T>(head); }

    NodeIterator<T> end() { return nullptr; }
    NodeIterator<T> end() const { return nullptr; }

    void push_back(T);
    const T back() const;
    void push_front(T);
    const T front() const;
    int size();
    void reverse();

    NodeIterator<T> insert(NodeIterator<T> itr, const T & data) {
      if (head == nullptr) {
        head = new Node<T>(data);
        head->data = data;
        head->next = nullptr;
      }else{
        Node<T>* tempNode = new Node<T>(data);
        tempNode->next = itr.getNodePtr();
        tempNode->previous = tempNode->next->previous;
        tempNode->next->previous = tempNode;
        tempNode->previous->next = tempNode;
        ++listSize;
        return NodeIterator<T>(tempNode);
      }
      return NodeIterator<T>(head);
    }

    NodeIterator<T> erase(NodeIterator<T> itr) {

      Node<T>* erasedNode = itr.getNodePtr();
      ++itr;
      erasedNode->next->previous = erasedNode->previous;
      erasedNode->previous->next = erasedNode->next;
      --listSize;
      delete erasedNode;
      return itr;
    }
};

template <typename T>
void LinkedList<T>:: push_back(T dat)
{
    current = new Node<T>(dat);
    if (head == nullptr)
    {
        head = current;
    }
    else
    {
        tail -> next = current;
        current -> previous = tail;
    }
    tail = current;
    listSize++;
}

template <typename T>
const T LinkedList<T>:: back() const
{
    return tail->data;
}

template <typename T>
void LinkedList<T>:: push_front(T dat)
{
    current = new Node<T>(dat);
    if (head == nullptr)
    {
        head = current;
        tail = current;
    }
    else
    {
        head -> previous = current;
        current -> next = head;
        head = current;
    }
    listSize++;
}
template <typename T>
const T LinkedList<T>:: front() const
{
    return head->data;
}

template <typename T>
int LinkedList<T>:: size()
{
  return listSize;
}


template <typename T>
void LinkedList<T>:: reverse()
{
    current = tail;
    Node<T>* future_next = nullptr;
    while (current)
    {
        future_next = current -> previous;
        if (current == tail)
        {
            head = tail;
            current -> previous = nullptr;
            current -> next = future_next;
        }
        else
        {
            current -> next = future_next;
            current -> previous = tail;
        }
        tail = current;
        current = future_next;
    }
}

#endif
