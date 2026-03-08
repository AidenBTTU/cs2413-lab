/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int verify(struct TreeNode* root, long long min, long long max) {
    if (root == NULL) {
        return 0; // This isnt a leaf, so it has no height. Still valid
    }
    if ((long long)root->val <= min || (long long)root->val >= max) {
        return -1;
    }
    int leftHeight = verify(root->left, min, root->val);
    if (leftHeight == -1) { //The value in the left has to be less than the value in the bridge above it but no real constriciton for min
        return -1;  //I have to propogate the negative value up
    }
    int rightHeight = verify(root->right, root->val, max);
    if (rightHeight == -1) { //Vice versa
        return -1;
    }
    int diff = leftHeight - rightHeight;  //no include for abs. unsure if im allowed to use it?
    if (diff < -1 || diff > 1) {
        return -1;
    }

    //If we have gotten this far, the leg is valid so we need to know its height
    if (leftHeight >= rightHeight) {
        return leftHeight+1;
    }
    else {
        return rightHeight+1;
    }
}

bool isAVL(struct TreeNode* root) {
    if ((verify(root, -1000000000000000000LL, 1000000000000000000)) != -1) {
        return true;
    }
    return false;
}
