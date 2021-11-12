#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {

public:

    const Key k;
    Value v;

    // TODO your code for KeyValuePair goes here
    KeyValuePair(Key kIn, Value vIn)
      : k(kIn), v(vIn) {
    }

    KeyValuePair(Key kIn)
      : k(kIn) {
    }

    bool operator<(const KeyValuePair<Key, Value> & pairs) const{
      if (this->k < pairs.k) {
        return true;
      } else {
        return false;
      }
    }

};

template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {

private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;

public:

    KeyValuePair<Key,Value> *insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }

    void write(ostream & o) const {
        tree.write(o);
    }

    // TODO your code for TreeMap goes here:
    KeyValuePair<Key,Value> *find(const Key & k) {

      if (tree.find(KeyValuePair<Key, Value>(k)) != nullptr) {
        return &(tree.find(KeyValuePair<Key, Value>(k))->data);
      }
      return nullptr;
    }

};

// do not edit below this line

#endif
