//
// Created by Administrator on 2018/12/11.
//

#include "Tree.h"

struct BiNode {
    BiNode *right;
    BiNode *left;
    char value;
};

BiNode *createTreeByPreIn(BiNode *node, char *preOrder, int preIndex,
                          char *inOrder, int inIndex, size_t length);

void getPostOrder(BiNode *node, char result[], int &index);

char *Tree::PostOrder(char *preOrder, char *inOrder, char *result) {
    BiNode *node = new BiNode();
    createTreeByPreIn(node, preOrder, 0, inOrder, 0, strlen(preOrder));
    int index = 0;
    getPostOrder(node, result, index);
    return result;
}

void getPostOrder(BiNode *node, char result[], int &index) {
    if (node->left != NULL) {
        getPostOrder(node->left, result, index);
    }
    if (node->right != NULL) {
        getPostOrder(node->right, result, index);
    }
    result[index++] = node->value;
}

BiNode *createTreeByPreIn(BiNode *node, char *preOrder, int preIndex,
                          char *inOrder, int inIndex, size_t length) {
    if (length <= 0) {
        return node;
    }

    char pre = preOrder[preIndex];
    node->value = pre;
    if (length == 1) {
        return node;
    }
    char in;
    for (size_t i = 0; i < length; i++) {
        in = inOrder[inIndex + i];
        if (in == pre) {
            if (i >= 1) {
                node->left = new BiNode();
                createTreeByPreIn(node->left, preOrder, preIndex + 1, inOrder, inIndex, i);
            }
            if (length - i - 1 >= 1) {
                node->right = new BiNode();
                createTreeByPreIn(node->right, preOrder, preIndex + i + 1, inOrder, inIndex + i + 1, length - i - 1);
            }
            break;
        }
    }
};
