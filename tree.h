#pragma once

//Defining a Tree Node
struct tnode{
	int data;
	struct tnode* left;
	struct tnode* right;
};
typedef struct tnode TreeNode;

//Get a new TreeNode with given data value
TreeNode* newTreeNode(int data);

//Insert data into a BST
TreeNode* insertBST(TreeNode *root, int data);

//Inorder traversal of tree
void traverseInorder(TreeNode* root);