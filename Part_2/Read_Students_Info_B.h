/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Read students' info from a file and make a BTS by the Grade
node_B * read_file_B(node_B * root, char students_data[])
{
	st student;

	// open the given file
	FILE *file;
	file = fopen(students_data, "r");

	if (file == NULL)
	{
		printf("Error in reading Student Data...");
	}

	int i = 0;
	while (!feof(file))
	{
		// Scan for student's info
		fscanf(file, "%s %s %s %lf\n", student.AM, student.Name, student.Surname, &student.Grade);
		
		// Insert the new student to the BTS
		if (i == 0)
		{	root = insert_B(root, student);	}
		else
		{	insert_B(root, student);	}
		i++;
	}

	fclose(file);
	return root;
}
