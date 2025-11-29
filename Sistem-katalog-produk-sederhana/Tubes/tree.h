#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct Node *adrNode;

struct Node {
    int id;
    string name;
    float price;
    int stock;
    adrNode left;
    adrNode right;
};

void createTree_103012400173(adrNode &root);
adrNode createNode_103012400173(int id, string name, float price, int stock);
void insertNode_103012400173(adrNode &root, adrNode p);

void displayInorder_103012400173(adrNode root);

adrNode searchByID_103012400173(adrNode root, int id);
adrNode searchByName_103012400173(adrNode root, string name);

bool updateProduct_103012400173(adrNode root, int id, string newName, float newPrice, int newStock);
adrNode deleteNode_103012400173(adrNode root, int id);

int totalStock_103012400173(adrNode root);
adrNode minStock_103012400173(adrNode root);

void printByHarga_103012400173(adrNode root, float lastPrinted);
void printByNama_103012400173(adrNode root, string lastPrinted);

void saveToFile_103012400173(adrNode root, const char* filename);

#endif
