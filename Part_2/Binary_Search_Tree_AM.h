/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Struct node for the BTS
typedef struct node_A
{
	st st0;
	struct node_A *left, *right;
} node_A;

// Create a new Node
node_A * newNode_A(st st1)
{
	node_A *temp = (node_A *)malloc(sizeof(node_A));
	temp->st0 = st1;
	
	temp->left = temp->right = NULL;
	return temp;
}

// Insert a new student to the Binary Search Tree
node_A* insert_A(node_A* node_A, st st2)
{
	// If the tree is empty, return a new node 
	if (node_A == NULL) return newNode_A(st2);

	int res = strcmp(st2.AM, node_A->st0.AM);

	// Otherwise, recur down the tree 
	if (res < 0)
		node_A->left = insert_A(node_A->left, st2);
	else if (res > 0)
		node_A->right = insert_A(node_A->right, st2);

	return node_A;
}

// Print the BST sorted
void inorder_A(node_A *root)
{
	if (root != NULL)
	{
		inorder_A(root->left);
		print_st(root->st0);
		inorder_A(root->right);
	}
}

node_A* search_A(node_A* root, char am[9])
{
	int res = strcmp(am, root->st0.AM);

	// Base Cases: root is null or key is present at root 
	if (res == 0)
	{	return root;	}

	// Key is greater than root's key 
	if (res > 0)
	{	
		if (root->right == NULL)
		{
			return -1;
		}
		return search_A(root->right, am);
	}

	// Key is smaller than root's key 
	else
	{
		if (root->left == NULL)
		{
			return -1;
		}
		return search_A(root->left, am);
	}
}

// Find the minimum value of the BTS
node_A * minValueNode_A(node_A* node_A)
{
	while (node_A->left != NULL)
	{
		node_A = node_A->left;
	}
	return node_A;
}

// Delete a node from the BTS
node_A* deleteNode_A(node_A* root, st st)
{
	if (root == NULL) return root;

	int res = strcmp(st.AM, root->st0.AM);

	// If the key to be deleted is smaller than the root's key, 
	// then it lies in left subtree 
	if (res < 0)
		root->left = deleteNode_A(root->left, st);

	// If the key to be deleted is greater than the root's key, 
	// then it lies in right subtree 
	else if (res > 0)
		root->right = deleteNode_A(root->right, st);

	// if key is same as root's key, then this is the node 
	// to be deleted 
	else
	{
		// node with only one child or no child 
		if (root->left == NULL)
		{
			node_A *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			node_A *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		node_A* temp = minValueNode_A(root->right);

		// Copy the inorder successor's content to this node 
		root->st0 = temp->st0;

		// Delete the inorder successor 
		root->right = deleteNode_A(root->right, temp->st0);
	}
	return root;
}
