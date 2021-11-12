#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode {

public:
        T data;
        unique_ptr<TreeNode<T>> leftChild, rightChild;
        TreeNode<T> *parent;
        TreeNode(const T & dataIn)
            : data(dataIn), parent(nullptr) {

        }

          void setLeftChild(TreeNode<T>* child) {
            child->parent = this;
            leftChild.reset(child);
            }


          void setRightChild(TreeNode<T>* child) {
            child->parent = this;
            rightChild.reset(child);
          }

          void write(ostream &out) const{
              if (leftChild) {
                  leftChild->write(out);
              }
              out << " " << data << " ";
              if (rightChild) {
                  rightChild->write(out);
              }
          }

          int maxDepth() {

            int left = -1;
            int right = -1;
            if (leftChild == nullptr && rightChild == nullptr) {
              return 1;
            } else {
            	if(leftChild){
            		left = leftChild->maxDepth();
            	}
            	if(rightChild){
            		right = rightChild->maxDepth();
            	}
            	if(left>right){
            		return left+1;
            	}
            	else{
            		return right+1;
            	}
            }
          }
    };

template<typename T>
class TreeNodeIterator {

TreeNode<T>* nodePoint;

public:
    TreeNodeIterator(TreeNode<T>* nodePointIn)
        : nodePoint(nodePointIn) {
    }
    T & operator*() {
        return nodePoint->data;
    }
    TreeNodeIterator<T> operator++() {
      if(nodePoint->rightChild) {
        nodePoint = nodePoint->rightChild.get();
        while (nodePoint->leftChild) {
          nodePoint = nodePoint->leftChild.get();
          }
        return TreeNodeIterator<T>(nodePoint);
      } else {
        T nodePointData = nodePoint->data;
        while (nodePoint->parent && (nodePointData >= nodePoint->data)) {
          nodePoint = nodePoint->parent;
        }
        if (nodePoint->data > nodePointData) {
          return TreeNodeIterator<T>(nodePoint);
        } else {
          nodePoint = nullptr;
          return nodePoint;
        }
      }
    }

    bool operator==(const TreeNodeIterator<T>& dat) {
      return nodePoint==dat.nodePoint;
    }

    bool operator!=(const TreeNodeIterator<T>& dat) {
      return nodePoint!=dat.nodePoint;
    }

};
// do not edit below this line

#endif
