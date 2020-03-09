/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Struct st_node for the linked list of BTS nodes
typedef struct st_node 
{
	st st;
	struct st_node * next;
} st_node;

// Struct node for the BTS
typedef struct node_B 
{
	struct node_B *left, *right;
	st_node * head;
	int counter;
} node_B;

// Create a new Node
node_B *newNode_B(st st1)
{
	node_B *temp = (node_B *)malloc(sizeof(node_B));

	temp->counter = 0;
	temp->head = (st_node*)malloc(sizeof(st_node));

	temp->head->st = st1;
	temp->head->next = NULL;
	temp->left = temp->right = NULL;

	return temp;
}

// Create a new st_node (if a student with the same grade already exists)
st_node * new_st_node(st st)
{
	st_node* temp = (st_node*)malloc(sizeof(st_node));
	temp->st = st;
	temp->next = NULL;
}

// Create a new st_node in an existing Node
node_B *existingNode(node_B *node_B, st st1)
{
	node_B->counter++;
	st_node * current = node_B->head;

	// Find the last student in the linked list
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_st_node(st1);
	
	return node_B;
}

void print_list(node_B * root) {

	st_node * current = root->head;

	while (current != NULL) {
		print_st(current->st);
		current = current->next;
	}
}

int double_to_int(double a)
{
	return (int)a * 100;
}

// Insert a new student to the Binary Search Tree
node_B* insert_B(node_B* node_B, st st2)
{
	// If the tree is empty, create a new node 
	if (node_B == NULL) return newNode_B(st2);

	int node_grade = double_to_int(node_B->head->st.Grade);
	int st_grade = double_to_int(st2.Grade);
	int res = node_grade - st_grade;

	// If the grade already exists, create a new st_node 
	if (res == 0)	return existingNode(node_B, st2);

	// Otherwise, recur down the tree 
	if (res > 0)
		node_B->left = insert_B(node_B->left, st2);
	else if (res < 0)
		node_B->right = insert_B(node_B->right, st2);

	return node_B;
}

// A utility function to do inorder traversal of BST 
void inorder_B(node_B *root)
{
	if (root != NULL)
	{
		inorder_B(root->left);
		print_list(root);
		inorder_B(root->right);
	}
}

// Find the minimum value of the BTS
node_B * minValueNode_B(node_B* node_B)
{
	while(node_B->left != NULL)
	{
		node_B = node_B->left;
	}
	return node_B;
}

// Find the maximum value of the BTS
node_B * maxValueNode_B(node_B* node_B)
{
	while(node_B->right != NULL)
	{
		node_B = node_B->right;
	}
	return node_B;
}
