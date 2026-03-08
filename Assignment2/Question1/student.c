/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // TODO: implement
    // Hint: Use the BST property to decide whether to go left or right.
    struct TreeNode* current = root;
    while ((current != NULL)) {
        if (current->val < target) {
            current = current->right;

        }
        else if (current->val > target) {
            current = current->left;
        }
        else {
            return current;
        }
    }
    return NULL;
}
