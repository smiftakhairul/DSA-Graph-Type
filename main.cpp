#include "graphType.h"
#include "heapType.cpp"
#include <iostream>

using namespace std;

int main()
{
    graphType<char> a;
    char arr[8]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char c, u, v;
    bool found=false;
    bool foundU=false, foundV=false;

    for(int i=0; i<8; i++)
        a.addVertex(arr[i]);

    cout << ".....Task 1.....\n" << endl;

    a.addEdge('A', 'B', 1);
    a.addEdge('A', 'C', 1);
    a.addEdge('A', 'D', 1);
    a.addEdge('B', 'A', 1);
    a.addEdge('D', 'A', 1);
    a.addEdge('D', 'E', 1);
    a.addEdge('D', 'G', 1);
    a.addEdge('F', 'H', 1);
    a.addEdge('G', 'F', 1);
    a.addEdge('H', 'E', 1);

    cout << "Enter vertex to find the out degree: ";
    cin >> c;

    for(int i=0; i<8; i++)
    {
        if(c==arr[i])
            found=true;
    }

    if(found)
        cout << "Out Degree of " << c << ": " << a.outDegree(c) << endl;
    else
        cout << "Vertex not found...!" << endl;

    cout << "\n.....Task 2.....\n" << endl;

    cout << "Enter vertex: " << endl;
    cin >> u;
    cin >> v;

    for(int i=0; i<8; i++)
    {
        if(u==arr[i])
            foundU=true;
    }

    for(int i=0; i<8; i++)
    {
        if(v==arr[i])
            foundV=true;
    }

    if(foundU && foundV)
    {
        if(a.foundEdge(u, v))
            cout << "There is an edge...!" << endl;
        else
            cout << "There is no edge...!" << endl;
    }
    else
        cout << "Invalid vertex...!" << endl;

    cout << "\n.....Task 3.....\n" << endl;

    a.depthFirstSearch('B', 'E');
    a.depthFirstSearch('E', 'B');

    return 0;

    if(a.isConnected()==true)
        cout << "Connected..!" << endl;
    else
        cout << "Not connected..!" << endl;
}
