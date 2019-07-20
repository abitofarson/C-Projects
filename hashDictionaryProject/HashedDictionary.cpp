// Separate chaining resolves collisions

#include "HashedDictionary.h"
#include <cmath>    // For sqrt
#include <iostream> // For testing
#include <unordered_map>
#include <stdexcept>

//////////////////////////////////////////////////////////////////////
// Private helper methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary()
{
   for (int i = 0; i < hashTableSize; i++)
   {
      // If there are hashed entries at this location,
      // we need to delete them
      while (hashTable[i] != nullptr)
      {
         hashTable[i] = hashTable[i]->getNext();
      }  // end while
   }  // end for

   itemCount = 0;
}  // end destroyDictionary

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{
	// STEP 2

    return key % hashTableSize;
} // end getHashIndex

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNextPrime(int number) const
{
   bool foundPrime = false;
   if ((number % 2) == 0)
      number++;

   while (!foundPrime)
   {
      if ((number % 5 == 0) || !isPrime(number))
      {
         number = number + 2;
      }
      else
         foundPrime = true;
   }  // end

   return number;
}  // end getNextPrime

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isPrime(int number) const
{
   bool isPrimeNumber = true;                 // Assume prime, prove otherwise

   if ((number == 2) || (number == 3))        // Smallest primes
      isPrimeNumber = true;
   else
   {
      if ((number % 2 == 0) || (number < 2))  // Even number or ineligible
         isPrimeNumber = false;
      else
      {
         int root = sqrt(number);             // Limit of search
         int i = 3;
         do
         {
           if (number % i == 0)               // Not prime
              isPrimeNumber = false;
            else
               i = i + 2;

         } while ((isPrimeNumber == true) && (i <= root));
      }  // end if
   }  // endif

   return isPrimeNumber;
}  // end isPrime


// Constructors & Destructor


template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
:itemCount(0), hashTableSize(DEFAULT_CAPACITY)
{
   // All shared pointers in array initialized to nullptr & reference count zero
   hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(DEFAULT_CAPACITY);
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(int maxNumberOfEntries)
:itemCount(0)
{
   hashTableSize = getNextPrime(maxNumberOfEntries);

   // All shared pointers in array initialized to nullptr & reference count zero
   hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(hashTableSize);
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(const
                                                    HashedDictionary<KeyType, ItemType>& dict)
                  :itemCount(dict.itemCount),  hashTableSize(dict.hashTableSize)
{
   hashTable = std::make_unique<hashTableType<KeyType, ItemType>>(dict.maxItems);
   for (auto index : indices(dict.itemCount))
   {
      hashTable[index] = dict.hashTable[index];
   }  // end for
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
   destroyDictionary();
} // end destructor


// Status and public maintenance (clear) methods

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
   return (itemCount == 0);
} // end isEmpty

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const
{
   return itemCount;
} // end getNumberOfItems

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
   destroyDictionary();
} // end clear

// Container methods (add, remove, getItem, contains, traverse)

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
    auto newNode = HashedEntry(searchKey, newItem);

    int itemHashIndex = getHashIndex(searchKey);
    if(hashTable[itemHashIndex] == nullptr){
        hashTable[itemHashIndex] = newNode;
        itemCount++;
        }
    else{
        // Add new entry to beginning of chain
        newNode->setNext(hashTable[itemTable[itemHashIndex]]);
        hashTable[indexHashIndex] = newNode;
        itemCount++;
    }
    return true;
} // end add

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
    int hashTableIndex = getHashIndex(searchKey);
    if(hashTable[hashTableIndex]){
        //Search the chain pointed to by HashTable[]
    }

} // end remove

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{

} // end getItem

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{


} // end contains

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{


}  //end traverse
