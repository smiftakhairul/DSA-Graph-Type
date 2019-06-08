#ifndef GRAPHTYPE_H_INCLUDED
#define GRAPHTYPE_H_INCLUDED
#include "stackType.h"
#include "queType.h"

template <class vertexType>
class graphType
{
    public:
        graphType();
        graphType(int maxV);
        ~graphType();
        void makeEmpty();
        bool isEmpty();
        bool isFull();
        void addVertex(vertexType);
        void addEdge(vertexType, vertexType, int);
        int weightIs(vertexType, vertexType);
        void getToVertices(vertexType, queType<vertexType>&);
        void clearMarks();
        void markVertex(vertexType);
        bool isMarked(vertexType);
        void depthFirstSearch(vertexType, vertexType);
        void breadthFirstSearch(vertexType, vertexType);
        int outDegree(vertexType);
        bool foundEdge(vertexType, vertexType);
        bool isConnected();
    private:
        int numVertices;
        int maxVertices;
        vertexType* vertices;
        int **edges;
        bool* marks;
};

#endif // GRAPHTYPE_H_INCLUDED
