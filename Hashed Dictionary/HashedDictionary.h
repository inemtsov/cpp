#pragma once

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include <exception>
#include <unordered_map>
#include <vector>
#include<iostream>

using namespace std;
#define DEFAULT_SIZE 101

/**
 *
 * This Hash table is of fixed max size 101 - which is a prime number (why?)
 */
template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType> {
private:
    HashedEntry<KeyType, ItemType> **hashTable;  // Array of pointers to entries
    int itemCount;
    int hashTableSize; //Default value should be assigned to 101

    int getHashIndex(const KeyType &itemKey) const;

    void destroyDictionary();

public:


    virtual ~HashedDictionary();

    HashedDictionary();

    bool isEmpty() const override;

    int getNumberOfItems() const override;

    bool add(const KeyType &searchKey, const ItemType &newItem) override;

    bool remove(const KeyType &searchKey) override;

    void clear() override;

    ItemType getItem(const KeyType &searchKey) const override;

    bool contains(const KeyType &searchKey) const override;

    void traverse(void (*visit)(ItemType &)) const override;

    std::vector<ItemType> toVector() const override;

    HashedEntry<KeyType, ItemType>& operator[](KeyType key);


};

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType &key) const {
    //DO NOT MODIFY
    return static_cast<int>(key % hashTableSize);
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
        : itemCount(0), hashTableSize(DEFAULT_SIZE) {
    //DO NOT MODIFY
    hashTable = new HashedEntry<KeyType, ItemType> *[DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++)
        hashTable[i] = nullptr;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary() {
    //TODO


    for(int i=0; i < hashTableSize; i++){
        HashedEntry<KeyType, ItemType> *chainPtr=hashTable[i];
        while(chainPtr!= nullptr)
        {
            remove(chainPtr->getKey());
            chainPtr=chainPtr->getNext();
        }
    }
    delete [] hashTable;
    itemCount=0;
}

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    //DO NOT MODIFY
    destroyDictionary();
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
    //TODO
    bool CountCheck = false;
    if( itemCount==0){
        CountCheck=true;
    }
    return CountCheck;
}

template<class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    //TODO
    return itemCount;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType &searchKey, const ItemType &newItem) {
    //TODO
    HashedEntry<KeyType, ItemType>* entryToAddPtr= new HashedEntry<KeyType, ItemType>(searchKey, newItem);
    int hashIndex=getHashIndex(searchKey);
    if (hashTable[hashIndex]== nullptr)
    {
        hashTable[hashIndex]=entryToAddPtr;
    }
    else {
        entryToAddPtr->setNext(hashTable[hashIndex]);
        hashTable[hashIndex]=entryToAddPtr;
    }
    ++itemCount;
return true;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType &searchKey) {
    //TODO
    bool isSuccessful=false;
    int hashIndex= getHashIndex(searchKey);
    if(hashTable[hashIndex]!= nullptr)
    {
        if( searchKey==hashTable[hashIndex]->getKey()) {
            hashTable[hashIndex] = hashTable[hashIndex]->getNext();
            isSuccessful = true;
        }
        else{
            auto prevPtr=hashTable[hashIndex];
            auto curPtr=prevPtr->getNext();
            while((curPtr!= nullptr)&& !isSuccessful){
                if(searchKey==curPtr->getKey()){
                    prevPtr->setNext(curPtr->getNext());
                    isSuccessful=true;
                }
                else{
                    prevPtr=curPtr;
                    curPtr=curPtr->getNext();
                }
            }
        }
    }
    if (isSuccessful){
        --itemCount;
    }
    return isSuccessful;
}

template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType &searchKey) const {
    //TODO
    int hashIndex=getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType>* curPtr=hashTable[hashIndex];
    if (hashTable[hashIndex]==nullptr){
        throw std::exception();
    }else{
        while(curPtr!= nullptr && curPtr->getKey()!=searchKey){
            curPtr=curPtr->getNext();
        }
        if(curPtr== nullptr){
            throw std::exception();
        }
    }
    return curPtr->getItem();
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType &searchKey) const {
    //TODO
    bool found=false;
    int hashIndex= getHashIndex(searchKey);
    if(hashTable[hashIndex]!= nullptr)
    {
        if( searchKey==hashTable[hashIndex]->getKey())
            found=true;
        else{
            auto prevPtr=hashTable[hashIndex];
            auto curPtr=prevPtr->getNext();
            while((curPtr!= nullptr)&& !found){
                if(searchKey==curPtr->getKey()){
                    found=true;
                }
                else{
                    prevPtr=curPtr;
                    curPtr=curPtr->getNext();
                }
            }
        }
    }
    return found;
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void (*visit)(ItemType &)) const {
    //DO NOT MODIFY
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            visit(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
}

template<class KeyType, class ItemType>
std::vector<ItemType> HashedDictionary<KeyType, ItemType>::toVector() const {
    //DO NOT MODIFY
    std::vector<ItemType> returnVector;
    for (int index = 0; index < hashTableSize; index++) {
        HashedEntry<KeyType, ItemType> *chainPtr = hashTable[index];
        while (chainPtr != nullptr) {
            ItemType currentItem = chainPtr->getItem();
            returnVector.push_back(currentItem);
            chainPtr = chainPtr->getNext();
        }
    }
    return returnVector;
};

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>& HashedDictionary<KeyType, ItemType>::operator[](KeyType searchKey){
    //DO NOT MODIFY
    int itemHashIndex = getHashIndex(searchKey);
    HashedEntry<KeyType, ItemType> *chainPtr = hashTable[itemHashIndex];

    // Short circuit evaluation is important here
    while ((chainPtr != nullptr) && (searchKey != chainPtr->getKey())) {
        chainPtr = chainPtr->getNext();
    } // end while

    if (chainPtr == nullptr)
        throw std::exception();

    return *chainPtr;
}
