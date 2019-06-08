#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

template<class itemType>
struct nodeType
{
    itemType info;
    nodeType* next;
};

class fullStack {};

class emptyStack {};

template<class itemType>
class stackType
{
    public:
        stackType();
        ~stackType();
        void push(itemType);
        void pop();
        itemType topItem();
        bool isEmpty();
        bool isFull();
        void printStack();
        void replaceItem(int, int);
    private:
        nodeType<itemType>* topPtr;
};

#endif // STACKTYPE_H_INCLUDED
