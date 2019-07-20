#ifndef ENTRY_
#define ENTRY_

template <class KeyType, class ItemType>
class Entry
{
private:
   KeyType searchKey;
   ItemType item;
   
protected:
   void setKey(const KeyType& searchKey);
   
public:
   Entry();
   Entry(const KeyType& searchKey, const ItemType& newItem);
   ItemType getItem() const;
   KeyType getKey() const;
   void setItem(const ItemType& newItem);
   bool operator==(const Entry<KeyType, ItemType>& rightHandItem) const;
   bool operator>(const Entry<KeyType, ItemType>& rightHandItem) const;
}; // end Entry

#include "Entry.cpp"
#endif
