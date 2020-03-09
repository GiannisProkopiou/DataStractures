/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Create a new file to save the Hash Table
void File_Close_C(hash * hash_list, char *dir)
{
	FILE *file;
	file = fopen(dir, "w+");

	node_C* current = NULL;
	for (int i = 0; i < w; i++)
	{
		current = hash_list[i].node_C;
		while (current != NULL)
		{
			fprintf(file, "%s %s %s %.2lf\n", current->student.AM, current->student.Name, current->student.Surname, current->student.Grade);
			current = current->next_node;
		}
	}
	fclose(file);
}