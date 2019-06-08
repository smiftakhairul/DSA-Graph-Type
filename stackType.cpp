#include "stackType.h"
#include <iostream>

using namespace std;

template<class itemType>
stackType<itemType>::stackType()
{
    topPtr=NULL;
}

template<class itemType>
stackType<itemType>::~stackType()
{
    nodeType<itemType>* tempPtr;
    while(topPtr!=NULL)
    {
        tempPtr=topPtr;
        topPtr=topPtr->next;
        delete tempPtr;
    }
}

template<class itemType>
void stackType<itemType>::push(itemType newItem)
{
    if(isFull())
        throw fullStack();
    else
    {
        nodeType<itemType>* location;
        location=new nodeType<itemType>;
        location->info=newItem;
        location->next=topPtr;
        topPtr=location;
    }
}

template<class itemType>
void stackType<itemType>::pop()
{
    if(isEmpty())
        throw emptyStack();
    else
    {
        nodeType<itemType>* tempPtr;
        tempPtr=topPtr;
        topPtr=topPtr->next;
        delete tempPtr;
    }
}

template<class itemType>
itemType stackType<itemType>::topItem()
{
    if(isEmpty())
        throw emptyStack();
    else
        return topPtr->info;
}

template<class itemType>
bool stackType<itemType>::isEmpty()
{
    return (topPtr==NULL);
}

template<class itemType>
bool stackType<itemType>::isFull()
{
    nodeType<itemType>* location;

    try
    {
        location=new nodeType<itemType>;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}

template<class itemType>
void stackType<itemType>::printStack()
{
    nodeType<itemType>* tempPtr;
    tempPtr=topPtr;

    while(tempPtr!=NULL)
    {
        cout << tempPtr->info << " ";
        tempPtr=tempPtr->next;
    }
    delete tempPtr;
}

template<class itemType>
void stackType<itemType>::replaceItem(int oldItem, int newItem)
{
    nodeType<itemType>* tempPtr;
    tempPtr=topPtr;

    while(tempPtr!=NULL)
    {
        if(oldItem==tempPtr->info)
            tempPtr->info=newItem;
        tempPtr=tempPtr->next;
    }
    delete tempPtr;
}
