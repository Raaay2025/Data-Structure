#ifndef DATASTRUCTUREASSIGNMENT_BST_H
#define DATASTRUCTUREASSIGNMENT_BST_H

typedef struct BSTNode {  // 二叉排序树节点
    int key;
    struct BSTNode *left, *right;
    int height;
} BSTNode, *BSTree;

BSTNode *createNode(int key);

BSTree insertBST(BSTree tree, int key);

void inorderTraversal(BSTree root, char *result);

void reverseInorderTraversal(BSTree root, char *result);

BSTree deleteBSTNode(BSTree tree, int key);

BSTNode *searchBST(BSTree tree, int key);

BSTNode *findPredecessor(BSTree tree, int key);

BSTNode *findSuccessor(BSTree tree, int key);

BSTree createBST_random(BSTree tree, int n);

BSTree modifyBST(BSTree tree, int key, int newKey);

void getNodeInfo(BSTree tree, int key, char *result);

int getDepth(BSTree tree, int key);

BSTNode *getParent(BSTree tree, int key);

BSTNode *getSibling(BSTree tree, int key);

void printTree(BSTree root, char *result);


#endif //DATASTRUCTUREASSIGNMENT_BST_H
