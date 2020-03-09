/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

char * AM_read_C()
{
	char am[100];
	printf("Give the student's AM: ");
	gets(am);
	return am;
}

int answer_C()
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
node_C * search_AM_C(hash* hash_list)
{
	char am[100];
	node_C *node_C;
	do
	{
		strcpy(am, AM_read_C());
		node_C = search_st(hash_list, am);
		if (node_C == -1)
			printf("\nThis AM does not exist! Try again!\n");
	} while (node_C == -1);

	return node_C;
}

hash * menu_C(hash * hash_list)
{
	int n;
	char AM[9];
	node_C* node_C;
	int wrong_selection = 0;
	int ans = -1;

	do
	{
		wrong_selection = 0;
		printf("1. Search\n");
		printf("2. Make a Change\n");
		printf("3. Delete\n");
		printf("4. Exit\n");
		printf("\nChoose a function: ");

		scanf("%d", &n);
		while ((getchar()) != '\n'); //clear the input buffer

		switch (n)
		{
		// Search for a student by the AM
		case 1:
			node_C = search_AM_C(hash_list);
			print_st(node_C->student);
			break;

		// Make a change to a student's info
		case 2:
			do
			{
				node_C = search_AM_C(hash_list);
				node_C->student = choose_change(node_C->student);
				print_st(node_C->student);
				printf("Would you like to change something else?(Y/N) ");
				while ((getchar()) != '\n'); //clear the input buffer
			} while (answer_C());
			break;

		// Delete a student from the Hash Table
		case 3:
			node_C = search_AM_C(hash_list);
			hash_list = delete_node(hash_list, node_C);
			printf("\nThe deletion was successful!\n");
			break;

		// Exit the program
		case 4:
			break;	

		default:
			wrong_selection = 1;			
		}

		if (n == 4)
			break;
		else if (wrong_selection == 1)
		{
			printf("\nPlease choose one of the Menu Numbers!\n");
			ans = 1;
		}
		else
		{
			printf("\nWould you like to call an other function?(Y/N): ");
			ans = answer_C();
		}
	} while (ans);

	File_Close_C(hash_list, "New_Foithtes_C.txt");
	
	return hash_list;
}