/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

int answer_B()
{
	char ans = NULL;	
	do
	{
		ans = getchar();
		while ((getchar()) != '\n'); //clear the input buffer

		if (ans != 'N' && ans != 'n' && ans != 'Y' && ans != 'y')
		{
			printf("Press (Y/N): ");
		}
		else if (ans == 'N' || ans == 'n')
		{
			return 0;
		}
		else if (ans == 'Y' || ans == 'y')
		{
			return 1;
		}
			
	} while (1);
}

node_B* menu_B(node_B *root)
{
	int n;
	char AM[9];
	node_B *node_B;
	int ans = -1;
	int wrong_selection = 0;

	do
	{
		wrong_selection = 0;
		printf("\n1. Minimun Grade\n");
		printf("2. Maximun Grade\n");
		printf("3. Exit\n");
		printf("\nChoose a function: ");

		scanf("%d", &n);
		while ((getchar()) != '\n'); //clear the input buffer
		switch (n)
		{
		// Print a list of the students with the minimum grade
		case 1:
			print_list(minValueNode_B(root));
			break;
		
		// Print a list of the students with the maximum grade
		case 2:
			print_list(maxValueNode_B(root));
			break;
		
		// Exit the program
		case 3:
			break;			 

		default:
			printf("Please choose one of the Menu Numbers!");
			wrong_selection = 1;
			ans = 1;
		}

		if (n == 3)
			break;
		else if (wrong_selection == 0)
		{
			printf("\nWould you like to call an other function?(Y/N): ");
			ans = answer_B();
		}
	} while (ans);

	// Write in a new file the new changed BTS of students
	File_Close_B(root, "New_Foithtes_B.txt");
	
	return root;
}