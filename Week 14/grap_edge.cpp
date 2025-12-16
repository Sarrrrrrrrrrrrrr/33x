#include "graph.h"

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge e1 = new ElmEdge;
        e1->Node = N2;
        e1->Next = N1->firstEdge;
        N1->firstEdge = e1;

        adrEdge e2 = new ElmEdge;
        e2->Node = N1;
        e2->Next = N2->firstEdge;
        N2->firstEdge = e2;
    }
}