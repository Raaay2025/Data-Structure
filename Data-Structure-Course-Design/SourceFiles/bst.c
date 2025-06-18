#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "../HeaderFiles/bst.h"

#define MOD 99

// 创建一个新节点
BSTNode *createNode(int key) {
    BSTNode *newNode = (BSTNode *) malloc(sizeof(BSTNode));
    if (!newNode) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 插入新节点到二叉排序树
BSTree insertBST(BSTree tree, int key) {
    if (tree == NULL) {
        return createNode(key);
    }
    if (key < tree->key) {
        tree->left = insertBST(tree->left, key);
    } else if (key > tree->key) {
        tree->right = insertBST(tree->right, key);
    }
    return tree;
}

// 中序遍历
void inorderTraversal(BSTree root, char *result) {
    if (root != NULL) {
        inorderTraversal(root->left, result);
        char buffer[12];
        sprintf(buffer, "%d ", root->key);
        strcat(result, buffer);
        inorderTraversal(root->right, result);
    }
}

// 逆序遍历（右->根->左）
void reverseInorderTraversal(BSTree root, char *result) {
    if (root != NULL) {
        reverseInorderTraversal(root->right, result);
        char buffer[12];
        sprintf(buffer, "%d ", root->key);
        strcat(result, buffer);
        reverseInorderTraversal(root->left, result);
    }
}

// 查找最小节点
BSTNode *findMin(BSTree tree) {
    while (tree && tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

// 删除节点
BSTree deleteBSTNode(BSTree tree, int key) {
    if (tree == NULL) {
        return NULL;
    }
    if (key < tree->key) {
        tree->left = deleteBSTNode(tree->left, key);
    } else if (key > tree->key) {
        tree->right = deleteBSTNode(tree->right, key);
    } else {
        if (tree->left == NULL) {
            BSTree temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            BSTree temp = tree->left;
            free(tree);
            return temp;
        }
        BSTNode *temp = findMin(tree->right);
        tree->key = temp->key;
        tree->right = deleteBSTNode(tree->right, temp->key);
    }
    return tree;
}

// 查找节点
BSTNode *searchBST(BSTree tree, int key) {
    if (tree == NULL || tree->key == key) {
        return tree;
    }
    if (key < tree->key) {
        return searchBST(tree->left, key);
    } else {
        return searchBST(tree->right, key);
    }
}

// 查找前驱节点
BSTNode *findPredecessor(BSTree tree, int key) {
    BSTNode *node = searchBST(tree, key);
    if (node == NULL) return NULL;

    // 如果左子树不为空，前驱在左子树中
    if (node->left != NULL) {
        node = node->left;
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }

    // 如果左子树为空，前驱在祖先节点中
    BSTNode *predecessor = NULL;
    BSTNode *ancestor = tree;
    while (ancestor != node) {
        if (node->key > ancestor->key) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

// 查找后继节点
BSTNode *findSuccessor(BSTree tree, int key) {
    BSTNode *node = searchBST(tree, key);
    if (node == NULL) return NULL;

    // 如果右子树不为空，后继在右子树中
    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // 如果右子树为空，后继在祖先节点中
    BSTNode *successor = NULL;
    BSTNode *ancestor = tree;
    while (ancestor != node) {
        if (node->key < ancestor->key) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// 随机产生一个N个互不相同的整数，建立二叉树
BSTree createBST_random(BSTree tree, int n) {
    srand(time(NULL));
    while (n--) {
        int key = rand() % MOD;
        if (!searchBST(tree, key)) {
            tree = insertBST(tree, key);
            printf("%d ", key);
        } else n++;
    }
    return tree;
}

// 修改节点
BSTree modifyBST(BSTree tree, int key, int newKey) {
    BSTNode *node = searchBST(tree, key);
    if (node) {
        tree = deleteBSTNode(tree, key);
        tree = insertBST(tree, newKey);
        return tree;
    } else {
        printf("未找到节点\n");
        return NULL;
    }
}

// 获得节点深度
int getDepth(BSTree tree, int key) {
    BSTNode *node = searchBST(tree, key);
    if (node == NULL) return -1;

    int depth = 0;
    while (tree != NULL) {
        if (key < tree->key) {
            tree = tree->left;
        } else if (key > tree->key) {
            tree = tree->right;
        } else {
            return depth;
        }
        depth++;
    }
    return -1;
}

// 获得节点的父节点，在确保key存在的情况下
BSTNode *getParent(BSTree tree, int key) {
    BSTNode *parent = NULL;
    while (tree != NULL) {
        if (key < tree->key) {
            parent = tree;
            tree = tree->left;
        } else if (key > tree->key) {
            parent = tree;
            tree = tree->right;
        } else {
            return parent;
        }
    }
}

// 获得节点的兄弟节点
BSTNode *getSibling(BSTree tree, int key) {
    BSTNode *node = searchBST(tree, key);
    if (node == NULL) return NULL;

    BSTNode *parent = getParent(tree, key);
    if (parent == NULL) return NULL;

    if (parent->left == node) {
        return parent->right;
    } else {
        return parent->left;
    }
}

// 查询节点信息：节点在二叉树中的位置情况（深度、父节点、兄弟、左右孩子）、前驱、后继
void getNodeInfo(BSTree tree, int key, char *result) {
    char buffer[256];
    sprintf(buffer, "节点值：%d\n", key);
    strcat(result, buffer);

    // 节点深度
    sprintf(buffer, "节点深度：%d\n", getDepth(tree, key));
    strcat(result, buffer);

    // 父节点
    BSTNode *resNode = getParent(tree, key);
    if (resNode) {
        sprintf(buffer, "父节点：%d\n", resNode->key);
    } else {
        sprintf(buffer, "该节点是根节点，不存在父节点\n");
    }
    strcat(result, buffer);

    // 兄弟节点
    resNode = getSibling(tree, key);
    if (resNode == NULL) {
        sprintf(buffer, "该节点没有兄弟节点\n");
    } else {
        sprintf(buffer, "兄弟节点：%d\n", resNode->key);
    }
    strcat(result, buffer);

    // 左孩子
    BSTNode *node = searchBST(tree, key);
    if (node == NULL) {
        strcat(result, "节点不存在\n");
        return;
    }
    if (node->left == NULL) {
        sprintf(buffer, "该节点没有左孩子\n");
    } else {
        sprintf(buffer, "左孩子：%d\n", node->left->key);
    }
    strcat(result, buffer);

    // 右孩子
    if (node->right == NULL) {
        sprintf(buffer, "该节点没有右孩子\n");
    } else {
        sprintf(buffer, "右孩子：%d\n", node->right->key);
    }
    strcat(result, buffer);

    // 前驱节点
    resNode = findPredecessor(tree, key);
    if (resNode == NULL) {
        sprintf(buffer, "该节点没有前驱节点\n");
    } else {
        sprintf(buffer, "前驱节点：%d\n", resNode->key);
    }
    strcat(result, buffer);

    // 后继节点
    resNode = findSuccessor(tree, key);
    if (resNode == NULL) {
        sprintf(buffer, "该节点没有后继节点\n");
    } else {
        sprintf(buffer, "后继节点：%d\n", resNode->key);
    }
    strcat(result, buffer);
}

#define MAX_DIGITS 4
#define MAX_NODE 100
#define MAX_TMP 10000  //MAX_NODE^2
int var = 0;

int deepth(BSTree root) {
    if (!root) {
        return 0;
    }
    int left = deepth(root->left);
    int right = deepth(root->right);
    return left >= right ? left + 1 : right + 1;
}

void saveInTraversal(BSTree root, int *term) {
    if (!root) return;
    saveInTraversal(root->left, term);
    term[var++] = root->key;
    saveInTraversal(root->right, term);
}

int findNum(int *term, int x, int n) {
    for (int i = 0; i < n; i++)
        if (term[i] == x)
            return i + 1;
    return -1;
}

int digits(int x) {
    int num = 0;
    while (x != 0) {
        x /= 10;
        num++;
    }
    return num;
}

int count(BSTree T, int num) {
    if (!T) return num;
    num = count(T->left, num);
    num = count(T->right, num);
    num++;
    return num;
}

void printTree(BSTree root, char *result) {
    var = 0;
    int absoluteDistance[2]; // 绝对距离，[1]表示上一个兄弟节点，[0]-[1]用于计算节点的相对距离
    int array[MAX_NODE] = {0}; // 用于储存二叉树的中序遍历序列
    int relativeDistance = 0; // 相对距离
    int leftLineNum = 0; // 节点左边需打印的下划线符号个数
    int rightLineNum = 0; // 节点右边需打印的下划线符号个数
    int rightLineNum_temp = 0; // 临时变量，用于储存需打印节点的上一个兄弟节点右边打印了的下划线符号个数，便于计算需移动位数。（relativeDistance-rightLineNum_temp）
    int verticalLineArray[MAX_NODE] = {0}; // 竖线位置存储
    int verticalLineNum = 0; // 用于记录下一行需打印的竖线个数

    char buffer[256];

    // 定义标志节点N，节点的子孩子为空时用于占位识别
    BSTree N;
    N = (BSTree) malloc(sizeof(BSTNode));
    N->key = -1;
    N->left = NULL;
    N->right = NULL;
    N->height = 0;

    int deep = deepth(root);
    saveInTraversal(root, array);

    // 临时变量，用于层次遍历
    int k = 0;
    int j = 1;
    int n = 1;

    BSTree term[MAX_TMP] = {NULL}; // 指针数组，储存树节点，用于层次遍历
    term[0] = root;
    while (n != deep + 1) {
        absoluteDistance[0] = 0;
        absoluteDistance[1] = 0;
        if (term[k]->left != NULL && term[k]->left != N)
            term[j++] = term[k]->left;
        else
            term[j++] = N;
        if (term[k]->right != NULL && term[k]->right != N)
            term[j++] = term[k]->right;
        else
            term[j++] = N;
        k++;
        if (k == pow(2, n) - 1) {
            rightLineNum_temp = 0;
            verticalLineNum = 0;
            for (int i = pow(2, n - 1) - 1; i < k; i++) {
                leftLineNum = 0;
                rightLineNum = 0;
                absoluteDistance[0] = findNum(array, term[i]->key, count(root, 0)) * MAX_DIGITS;
                if (absoluteDistance[0] == -MAX_DIGITS)
                    continue;
                relativeDistance = absoluteDistance[0] - absoluteDistance[1];

                absoluteDistance[0] += digits(term[i]->key) + 2;

                absoluteDistance[1] = absoluteDistance[0];
                if (term[i]->left != N && term[i]->left != NULL) {
                    leftLineNum =
                            (absoluteDistance[0] - findNum(array, term[i]->left->key, count(root, 0)) * MAX_DIGITS) -
                            digits(term[i]->key) - 4;
                    verticalLineArray[verticalLineNum++] =
                            findNum(array, term[i]->left->key, count(root, 0)) * MAX_DIGITS + 2;
                }
                if (term[i]->right != N && term[i]->right != NULL) {
                    rightLineNum =
                            (findNum(array, term[i]->right->key, count(root, 0)) * MAX_DIGITS - absoluteDistance[0]) +
                            2;
                    verticalLineArray[verticalLineNum++] =
                            findNum(array, term[i]->right->key, count(root, 0)) * MAX_DIGITS + 1;
                }
                for (int m = 0; m < (rightLineNum_temp == 0
                                         ? (relativeDistance - leftLineNum)
                                         : (relativeDistance -
                                            leftLineNum -
                                            rightLineNum_temp)); m++) {
                    sprintf(buffer, " ");
                    strcat(result, buffer);
                }

                for (int m = 0; m < leftLineNum; m++) {
                    sprintf(buffer, "_");
                    strcat(result, buffer);
                }

                if (term[i] != N) {
                    sprintf(buffer, "(%d)", term[i]->key);
                    strcat(result, buffer);
                }

                for (int m = 0; m < rightLineNum; m++) {
                    sprintf(buffer, "_");
                    strcat(result, buffer);
                }

                rightLineNum_temp = rightLineNum;
            }
            sprintf(buffer, "\n");
            strcat(result, buffer);
            if (verticalLineNum) {
                for (int m = 0; m < verticalLineNum; m++) {
                    for (int p = 0;
                         p < (m == 0 ? verticalLineArray[m] : verticalLineArray[m] - verticalLineArray[m - 1]); p++) {
                        sprintf(buffer, " ");
                        strcat(result, buffer);
                    }
                    sprintf(buffer, "|");
                    strcat(result, buffer);
                    verticalLineArray[m]++;
                }
            }
            sprintf(buffer, "\n");
            strcat(result, buffer);
            n++;
        }
    }
}
