/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Print the sudents sorted by grade in the file
void write_inorder_B(FILE *file, node_B *root)
{
	if (root != NULL)
	{
		st_node * current = root->head;
		write_inorder_B(file, root->left);
		while (current != NULL) {
			fprintf(file, "%s %s %s %.2lf\n", current->st.AM, current->st.Name, current->st.Surname, current->st.Grade);
			current = current->next;
		}
		write_inorder_B(file, root->right);
	}
}

// Create a new file to save the BTS
void File_Close_B(node_B *root, char *dir)
{
	FILE *file;
	file = fopen(dir, "w+");
	write_inorder_B(file, root);

	fclose(file);
}