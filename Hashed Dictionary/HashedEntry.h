#pragma  once

#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> *nextPtr;

public:
    HashedEntry();

    HashedEntry(KeyType searchKey, ItemType newEntry);

    HashedEntry(KeyType searchKey, ItemType newEntry,
                HashedEntry<KeyType, ItemType> *nextEntryPtr);

    void setNext(HashedEntry<KeyType, ItemType> *nextEntryPtr);

    HashedEntry<KeyType, ItemType> *getNext() const;

    void operator=(const ItemType&);
};

//TODO Implement the necessary functions.
template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry() { }
template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType searchKey, ItemType newEntry) {
    this->setItem(newEntry);
    this->setKey(searchKey);
  this->nextPtr= nullptr;
}
template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType searchKey, ItemType newEntry,
                                            HashedEntry<KeyType, ItemType> *nextEntryPtr) {
    this->setItem(newEntry);
    this->setKey(searchKey);
    this->nextPtr=nextEntryPtr;
}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType> *nextEntryPtr){
    this->nextPtr=nextEntryPtr;
}
template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const {
 return nextPtr;
}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::operator=(const ItemType& newItem){
    //DO NOT MODIFY
    this->setItem(newItem);
}
