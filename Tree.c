#include <stdio.h>
#include "tree.h"
#include <malloc.h>

//TreeNode factory method
TreeNode* newTreeNode(int data) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL) {
		printf("\nERROR. No more memory available.\n");
		return node;
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//insert into BST
TreeNode* insertBST(TreeNode* root, int data) {
	//first element in this subtree
	if (root == NULL) {
		root = newTreeNode(data);
		return root;
	}
	//new elemet is less than the root
	if (data < root->data) {
		//If left subtree is empty
		if (root->left == NULL) {
			root->left = newTreeNode(data);
			return root->left;
		}
		return insertBST(root->left, data);
	}
	//new element is greater than or equal to the root
	//If right subtree is empty
	if (root->right == NULL) {
		root->right = newTreeNode(data);
		return root->right;
	}
	return insertBST(root->right, data);

}

//Inorder Traversal of the tree
void traverseInorder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	traverseInorder(root->left);
	printf("%d ", root->data);
	traverseInorder(root->right);
}
