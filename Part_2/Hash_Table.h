/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

extern const int w; 

// Struct node for the linked lists
typedef struct node_C {
	st student;
	struct node_C *next_node;
} node_C;

// Struct hash for the Hash Table
typedef struct hash {
	int value;
	node_C *node_C;
} hash;

// Initialize the Hash Table as NULL
hash* hash_setup()
{
	hash* hash_list = (hash*)calloc(w, sizeof(hash));

	for (int i = 0; i < w; i++)
	{
		hash_list[i].value = i;
		hash_list[i].node_C = NULL;
	}

	return hash_list;
}

// Create a new node (head of the linked list)
node_C* newHashNode(st st)
{
	node_C *temp = (node_C *)malloc(sizeof(node_C));
	temp->student = st;
	temp->next_node = NULL;

	return temp;
}

// Find the hash of student
int pos_finder(char *AM)
{
	int counter = 0;
	int sum = 0;
	for (int i = 0; i < strlen(AM); i++)
	{
		counter = AM[i];
		sum += counter;
	}
	sum = sum % w;
	return sum ;
}

// Insert the new student to the linked list
node_C * insertNode(node_C* node_C, st st)
{
	while (node_C != NULL)
	{
		node_C->next_node = insertNode(node_C->next_node, st);
		break;
	}
	if (node_C == NULL)
	{	node_C = newHashNode(st);	}	
	return node_C;
}

// Insert the new student to the Hash Table
hash* insert_Hash(hash* hash_list, st st)
{
	int pos = pos_finder(st.AM, w);
	hash_list[pos].node_C = insertNode(hash_list[pos].node_C, st);

	return hash_list;	
}

// Search a student by AM in tha linked list
node_C * search_next(char AM[9], node_C* node_C)
{
	int res = strcmp(AM, node_C->student.AM);
	if (res == 0)
		return node_C;
	else
		if (node_C->next_node == NULL)
		{	return -1;	}
		search_next(AM, node_C->next_node);
}

// Search a student by AM in tha Hash Table
node_C * search_st(hash* hash_list, char AM[9])
{  
	int i = pos_finder(AM);
	int res = strcmp(AM, hash_list[i].node_C->student.AM);
	if (res == 0)
		return hash_list[i].node_C;
	else
		return search_next(AM, hash_list[i].node_C->next_node);
}

// Delete a student from the middle or the end of the linked list
node_C * del_mid_node(node_C * prev, node_C * current, node_C * del_node)
{
	while (current != del_node)
	{
		current = del_mid_node(current, current->next_node, del_node);
		break;
	}
	if (current == del_node)
	{	prev->next_node = current->next_node;	}

	return prev;
}

// Delete a student from the Hash Table
hash * delete_node(hash * hash_list, node_C * del_node)
{
	int pos = pos_finder(del_node->student.AM);

	// Delete the student if it's the fist in the linked list
	if (del_node == hash_list[pos].node_C)
	{
		hash_list[pos].node_C = del_node->next_node;
		free(del_node);
	}

	// Delete if it's in the middle or at the end
	else
	{
		hash_list[pos].node_C = del_mid_node(hash_list[pos].node_C, hash_list[pos].node_C->next_node, del_node);
		free(del_node);
	}

	return hash_list;
}

void print_table(hash* hash_list)
{
	node_C* current = NULL;
	for (int i = 0; i < w; i++)
	{
		current = hash_list[i].node_C;
		while (current != NULL)
		{
			print_st(current->student);
			current = current->next_node;
		}
	}
}