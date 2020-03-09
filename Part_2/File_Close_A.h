/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Print the sudents sorted by AM in the file
void write_inorder_A(FILE *file, node_A *root)
{
	if (root != NULL)
	{
		write_inorder_A(file, root->left);
		fprintf(file, "%s %s %s %.2lf\n", root->st0.AM, root->st0.Name, root->st0.Surname, root->st0.Grade);
		write_inorder_A(file, root->right);
	}
}

// Create a new file to save the BTS
void File_Close_A(node_A *root, char *dir)
{
	FILE *file;
	file = fopen(dir, "w+");
	write_inorder_A(file, root);

	fclose(file);
}