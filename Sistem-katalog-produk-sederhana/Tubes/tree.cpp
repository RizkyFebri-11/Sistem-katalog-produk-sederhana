#include "tree.h"
#include <cstdio> // untuk FILE*, fprintf

void createTree_103012400173(adrNode &root) {
    root = nullptr;
}

adrNode createNode_103012400173(int id, string name, float price, int stock) {
    adrNode p;

    p = new Node;
    p->id = id;
    p->name = name;
    p->price = price;
    p->stock = stock;
    p->left = p->right = nullptr;

    return p;
}

void insertNode_103012400173(adrNode &root, adrNode p) {
    if (root == nullptr) root = p;
    else if (p->id < root->id) insertNode_103012400173(root->left, p);
    else insertNode_103012400173(root->right, p);
}

void displayInorder_103012400173(adrNode root) {
    if (root) {
        displayInorder_103012400173(root->left);
        int totalHarga = root->price * root->stock;
        cout << root->id << "    |   " << root->name << "   |   " << root->price << "   |   "
                << root->stock << "   |   " << totalHarga << endl;
        displayInorder_103012400173(root->right);
    }
}

adrNode searchByID_103012400173(adrNode root, int id) {
    if (!root) return nullptr;
    if (root->id == id) return root;
    if (id < root->id) return searchByID_103012400173(root->left, id);
    return searchByID_103012400173(root->right, id);
}

adrNode searchByName_103012400173(adrNode root, string name) {
    if (!root) return nullptr;
    if (root->name == name) return root;

    adrNode left = searchByName_103012400173(root->left, name);
    if (left) return left;
    return searchByName_103012400173(root->right, name);
}

bool updateProduct_103012400173(adrNode root, int id, string newName, float newPrice, int newStock) {
    adrNode p = searchByID_103012400173(root, id);
    if (!p) return false;

    p->name = newName;
    p->price = newPrice;
    p->stock = newStock;
    return true;
}

adrNode deleteNode_103012400173(adrNode root, int id) {
    if (!root) return nullptr;

    if (id < root->id) root->left = deleteNode_103012400173(root->left, id);
    else if (id > root->id) root->right = deleteNode_103012400173(root->right, id);
    else {
        if (!root->left) {
            adrNode tmp = root->right;
            delete root;
            return tmp;
        } else if (!root->right) {
            adrNode tmp = root->left;
            delete root;
            return tmp;
        } else {
            adrNode succ = root->right;
            while (succ->left) succ = succ->left;
            root->id = succ->id;
            root->name = succ->name;
            root->price = succ->price;
            root->stock = succ->stock;
            root->right = deleteNode_103012400173(root->right, succ->id);
        }
    }
    return root;
}

int totalStock_103012400173(adrNode root) {
    if (!root) return 0;
    return root->stock
         + totalStock_103012400173(root->left)
         + totalStock_103012400173(root->right);
}

// mencari stok terendah
adrNode minStock_103012400173(adrNode root) {
    if (!root) return nullptr;

    adrNode leftMin = minStock_103012400173(root->left);
    adrNode rightMin = minStock_103012400173(root->right);

    adrNode minNode = root;
    if (leftMin && leftMin->stock < minNode->stock) minNode = leftMin;
    if (rightMin && rightMin->stock < minNode->stock) minNode = rightMin;

    return minNode;
}

// PRINT BERDASARKAN HARGA TANPA ARRAY
void printByHarga_103012400173(adrNode root, float lastPrinted) {
    if (!root) return;

    if (root->price >= lastPrinted) {
        printByHarga_103012400173(root->left, lastPrinted);
        cout << root->id << " | " << root->name
             << " | " << root->price << endl;
    }

    printByHarga_103012400173(root->right, lastPrinted);
}

// PRINT BERDASARKAN NAMA TANPA ARRAY
void printByNama_103012400173(adrNode root, string lastPrinted) {
    if (!root) return;

    if (root->name >= lastPrinted) {
        printByNama_103012400173(root->left, lastPrinted);
        cout << root->name << " | " << root->id << endl;
    }

    printByNama_103012400173(root->right, lastPrinted);
}

// Simpan file tanpa fstream (pakai FILE*)
void saveToFile_103012400173(adrNode root, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) return;

    // inorder ID
    if (root) {
        saveToFile_103012400173(root->left, filename);
        fprintf(fp, "%d %s %.2f %d\n",
                root->id,
                root->name.c_str(),
                root->price,
                root->stock);
        saveToFile_103012400173(root->right, filename);
    }

    fclose(fp);
}
