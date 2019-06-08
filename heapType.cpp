#include "graphType.h"
#include "stackType.cpp"
#include "queType.cpp"
#include <iostream>

using namespace std;
const int NULL_EDGE=0;

template <class vertexType>
graphType<vertexType>::graphType()
{
    numVertices=0;
    maxVertices=50;
    vertices=new vertexType[50];
    edges=new int*[50];

    for(int i=0; i<50; i++)
        edges[i]=new int[50];
    marks=new bool[50];
}

template <class vertexType>
graphType<vertexType>::graphType(int maxV)
{
    numVertices=0;
    maxVertices=maxV;
    vertices=new vertexType[maxV];
    edges=new int*[maxV];

    for(int i=0; i<maxV; i++)
        edges[i]=new int[maxV];
    marks=new bool[maxV];
}

template <class vertexType>
graphType<vertexType>::~graphType()
{
    delete [] vertices;
    delete [] marks;

    for(int i=0; i<maxVertices; i++)
        delete [] edges[i];
    delete edges;
}

template <class vertexType>
void graphType<vertexType>::makeEmpty()
{
    numVertices=0;
}

template <class vertexType>
bool graphType<vertexType>::isEmpty()
{
    return (numVertices==0);
}

template <class vertexType>
bool graphType<vertexType>::isFull()
{
    return (numVertices==maxVertices);
}

template <class vertexType>
void graphType<vertexType>::addVertex(vertexType vertex)
{
    vertices[numVertices]=vertex;

    for(int index=0; index<numVertices; index++)
    {
        edges[numVertices][index]=NULL_EDGE;
        edges[index][numVertices]=NULL_EDGE;
    }
    numVertices++;
}

template <class vertexType>
int indexIs(vertexType* vertices, vertexType vertex)
{
    int index=0;
    while(!(vertex==vertices[index]))
        index++;
    return index;
}

template <class vertexType>
void graphType<vertexType>::clearMarks()
{
    for(int i=0; i<maxVertices; i++)
        marks[i]=false;
}

template <class vertexType>
void graphType<vertexType>::markVertex(vertexType vertex)
{
    int index=indexIs(vertices, vertex);
    marks[index]=true;
}

template <class vertexType>
bool graphType<vertexType>::isMarked(vertexType vertex)
{
    int index=indexIs(vertices, vertex);
    return marks[index];
}

template <class vertexType>
void graphType<vertexType>::addEdge(vertexType fromVertex, vertexType toVertex, int weight)
{
    int row=indexIs(vertices, fromVertex);
    int col=indexIs(vertices, toVertex);
    edges[row][col]=weight;
}

template <class vertexType>
int graphType<vertexType>::weightIs(vertexType fromVertex, vertexType toVertex)
{
    int row=indexIs(vertices, fromVertex);
    int col=indexIs(vertices, toVertex);
    return edges[row][col];
}

template <class vertexType>
void graphType<vertexType>::getToVertices(vertexType vertex, queType<vertexType>& adjVertices)
{
    int fromIndex, toIndex;
    fromIndex=indexIs(vertices, vertex);

    for(toIndex=0; toIndex<numVertices; toIndex++)
        if(edges[fromIndex][toIndex]!=NULL_EDGE)
            adjVertices.enqueue(vertices[toIndex]);
}

template <class vertexType>
void graphType<vertexType>::depthFirstSearch(vertexType startVertex, vertexType endVertex)
{
    stackType<vertexType> stack;
    queType<vertexType> vertexQ;
    bool found=false;
    vertexType vertex, item;

    clearMarks();
    stack.push(startVertex);

    do
    {
        vertex=stack.topItem();
        stack.pop();

        if(vertex==endVertex)
        {
            cout << vertex << " ";
            found=true;
        }
        else
        {
            if(!isMarked(vertex))
            {
                markVertex(vertex);
                cout << vertex << " ";
                getToVertices(vertex, vertexQ);

                while(!vertexQ.isEmpty())
                {
                    vertexQ.dequeue(item);
                    if(!isMarked(item))
                        stack.push(item);
                }
            }
        }
    }
    while(!stack.isEmpty() && !found);
    cout << endl;

    if(!found)
        cout << "Path not found...!" << endl;
}

template <class vertexType>
void graphType<vertexType>::breadthFirstSearch(vertexType startVertex, vertexType endVertex)
{
    queType<vertexType> queue;
    queType<vertexType> vertexQ;
    bool found=false;
    vertexType vertex, item;

    clearMarks();
    queue.enqueue(startVertex);

    do
    {
        queue.dequeue(vertex);
        if(vertex==endVertex)
        {
            cout << vertex << " ";
            found=true;
        }
        else
        {
            if(!isMarked(vertex))
            {
                markVertex(vertex);
                cout << vertex << " ";
                getToVertices(vertex, vertexQ);

                while(!vertexQ.isEmpty())
                {
                    vertexQ.dequeue(item);
                    if(!isMarked(item))
                        queue.enqueue(item);
                }
            }
        }
    }
    while(!queue.isEmpty() && !found);
    cout << endl;

    if(!found)
        cout << "Path not found...!" << endl;
}

template <class vertexType>
int graphType<vertexType>::outDegree(vertexType v)
{
    int count=0;

    for(int i=0; i<maxVertices; i++)
    {
        if(v==vertices[i])
        {
            for(int j=0; j<maxVertices; j++)
                if(edges[i][j]==1)
                    count++;
        }
    }
    return count;
}

template <class vertexType>
bool graphType<vertexType>::foundEdge(vertexType u, vertexType v)
{
    int tempU, tempV;
    for(int i=0; i<maxVertices; i++)
    {
        if(u==vertices[i])
            tempU=i;
    }

    for(int i=0; i<maxVertices; i++)
    {
        if(v==vertices[i])
            tempV=i;
    }

    if(edges[tempU][tempV]==1)
        return true;
    else
        return false;
}

template <class itemType>
bool graphType<itemType>::isConnected()
{
    int row=0, column=1;

    while(row<maxVertices)
    {
        while(column<maxVertices)
        {
            if(edges[row][column]==1)
            {
                column++;
                return true;
            }
            else
                return false;
        }
        row++;
    }
    return false;
}
