#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:

template<class T>
class BinarySearchTree{
  unique_ptr<TreeNode<T>> root;
public:
  BinarySearchTree(){};

  void  write(ostream & os) const {
     if(root){
       root->write(os);
     }
   }

  TreeNode<T>* insertLoop(TreeNode<T>* current, T data) {
     if(data < current->data && current->leftChild != nullptr) {
         insertLoop(current->leftChild.get(), data);
     } else if (current->data < data && current->rightChild != nullptr) {
         insertLoop(current->rightChild.get(), data);
     } else {
       if (data < current->data){
         current->setLeftChild(new TreeNode<T>(data));
       } else {
         current->setRightChild(new TreeNode<T>(data));
       }
     }
     return current;
 }

  TreeNode<T>* insert(const T & data) {
     if (root == nullptr) {
       TreeNode<T>* node = new TreeNode<T>(data);
       root.reset(node);
       return root.get();
     } else {
       return insertLoop(root.get(),data);
     }
   }

  TreeNode<T>* findLoop(TreeNode<T>* current, T data) {

         if (current != nullptr) {
           if (data < current->data) {
             return findLoop(current->leftChild.get(), data);
           } else if (current->data < data){
             return findLoop(current->rightChild.get(), data);
           } else {
             return current;
           }
         } else {
           return nullptr;
         }
       }

  TreeNode<T>* find(const T & data) {
       return findLoop(root.get(), data);
        }

  TreeNodeIterator<T> begin() {
    TreeNode<T> * nodePoint = root.get();
    if(nodePoint)
      while (nodePoint->leftChild != nullptr) {
          nodePoint = nodePoint->leftChild.get();
          }
          return TreeNodeIterator<T>(nodePoint);
          }


  TreeNodeIterator<T> end() {
  return nullptr;
  }

  int maxDepth() {
    return root->maxDepth();
  }

};
// do not edit below this line

#endif
