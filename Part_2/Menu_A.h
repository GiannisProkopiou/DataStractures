/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

char * AM_read_A()
{
	char am[100];
	printf("Give the student's AM: ");
	gets(am);	
	return am;
}

int answer_A()
{
	char ans = NULL;
	
	do
	{
		ans = getchar();
		while ((getchar()) != '\n'); //clear the input buffer
		
		if (ans == 'N' || ans == 'n')
		{
			return 0;
		}
		else if (ans == 'Y' || ans == 'y')
		{
			return 1;
		}
		else if (ans != 'N' && ans != 'n' && ans != 'Y' && ans != 'y')
		{
			printf("Press (Y/N): ");
		}
			
	} while (1);
}

// Check if the AM exists
node_A * search_AM_A(node_A * root)
{
	char am[100];
	node_A *node_A;
	do
	{
		strcpy(am, AM_read_A());
		node_A = search_A(root, am);
		if (node_A == -1)
			printf("\nThis AM does not exist! Try again!\n");
	} while (node_A == -1);

	return node_A;
}

node_A* menu_A(node_A *root)
{
	int n;
	node_A *node_A;
	int wrong_selection = 0;
	int ans = -1;

	do
	{
		wrong_selection = 0;
		printf("\n1. Sort List\n");
		printf("2. Search\n");
		printf("3. Make a Change\n");
		printf("4. Delete\n");
		printf("5. Exit\n");
		printf("\nChoose a function: ");

		scanf("%d", &n);
		while ((getchar()) != '\n'); //clear the input buffer
		switch (n)
		{
		// Print the soerted BTS
		case 1:
			printf("AM\t\tFirst Name\tLast Name\tGrade\n\n");
			inorder_A(root);
			break;

		// Search for a student by the AM
		case 2:
			node_A = search_AM_A(root);
			print_st(node_A->st0);
			break;

		// Make a change to a student's info
		case 3:
			do
			{
				node_A = search_AM_A(root);
				node_A->st0 = choose_change(node_A->st0);
				print_st(node_A->st0);
				printf("Would you like to change something else?(Y/N) ");
				while ((getchar()) != '\n'); //clear the input buffer
			} while (answer_A());
			break;

		// Delete a student from the BTS
		case 4:
			node_A = search_AM_A(root);
			root = deleteNode_A(root, node_A->st0);
			printf("\nDeletion was successful!\n");
			break;

		// Exit the program
		case 5:
			break;			 

		default:
			wrong_selection = 1;
		}

		if (n == 5)
			break;
		else if (wrong_selection == 1)
		{
			printf("\nPlease choose one of the Menu Numbers!\n");
			ans = 1;
		}
		else 
		{
			printf("\nWould you like to call an other function?(Y/N): ");
			ans = answer_A();
		}
	} while (ans);

	// Write in a new file the new changed BTS of students
	File_Close_A(root, "New_Foithtes_A.txt");
	
	return root;
}
