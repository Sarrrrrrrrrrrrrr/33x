#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};
//Fungsi Alokasi/Pembuatan Node baru
address newNode(infotype x);
//fungsi insert Node ke BST
address insertNode(address root, infotype x);
//Prosedur Traversal InOrder
void inOrder(address root);
#endif 