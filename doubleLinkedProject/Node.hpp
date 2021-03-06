#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   Node<ItemType>* prev; // Pointer to prev node

public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   void setPrev(Node<ItemType>* prevNodePtr);
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
   Node<ItemType>* getPrev() const ;
}; // end Node


template<class ItemType>
Node<ItemType>::Node() : next(nullptr), prev(nullptr)
{
} // end default constructor


template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr), prev(nullptr)
{
} // end constructor


template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr) :
                item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext


template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
    prev = prevNodePtr;
    //end setPrev
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} // end getNext

template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const
{
    return prev;
}

#endif
