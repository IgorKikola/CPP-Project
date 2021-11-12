#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.
template <typename T>
class Node
{
public:
    T data;
    Node<T>* previous;
    Node<T>* next;
    Node(T dataIn, Node *previous = nullptr, Node *next = nullptr)
        : data{std::move(dataIn)}, previous{previous}, next{next}
    {}
};

// TODO your code for the Node class goes here:
// (Note the 'NodeIterator' class will report lots of errors until Node exists





template<typename T>
class NodeIterator {

private:

    Node<T>* current;

public:


    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here

    NodeIterator<T>* operator++() {
    current = current->next;
    return this;
  }

    bool operator==(NodeIterator b) const { return current == b.current; }
    bool operator!=(NodeIterator b) const { return current != b.current; }


    Node<T>* getNodePtr() {
      return current;
    }
  };

// do not edit below this line

#endif
