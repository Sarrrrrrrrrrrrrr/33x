#include "graph.h"
#include <queue>
#include <stack>

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode startNode) {
    if (startNode == NULL) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }
    
    queue<adrNode> Q;
    Q.push(startNode);
    startNode->visited = 1;
    
    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();
        
        cout << current->info << " ";
        
        adrEdge edge = current->firstEdge;
        while (edge != NULL) {
            adrNode neighbor = edge->Node;
            
            if (neighbor->visited == 0) {
                neighbor->visited = 1;
                Q.push(neighbor);
            }
            
            edge = edge->Next;
        }
    }
    
    cout << endl;
}

void PrintDFS(Graph G, adrNode startNode) {
    if (startNode == NULL) {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }
    
    stack<adrNode> S;
    S.push(startNode);
    
    while (!S.empty()) {
        adrNode current = S.top();
        S.pop();
        
        if (current->visited == 0) {
            current->visited = 1;
            cout << current->info << " ";
            
            stack<adrNode> tempStack;
            adrEdge edge = current->firstEdge;
            
            while (edge != NULL) {
                if (edge->Node->visited == 0) {
                    tempStack.push(edge->Node);
                }
                edge = edge->Next;
            }
            
            while (!tempStack.empty()) {
                S.push(tempStack.top());
                tempStack.pop();
            }
        }
    }
    
    cout << endl;
}