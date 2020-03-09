/*---------------------------------------------
Computer Engineering and Informatics Department
University of Patras

Data Structures
Project 2019

Glarakis George AM: 1059561
Papadias Epameinondas AM: 1062665
Prokopiou Giannis AM: 1059554
---------------------------------------------*/

// Struct Student 
typedef struct Student {

	char AM[9];
	char Name[100];
	char Surname[100];
	double Grade;
} st;

// Print the student's info
void print_st(st st0)
{
	printf("%s\t%s\t%s\t\t%.2lf\n", st0.AM, st0.Name, st0.Surname, st0.Grade);
}

// Functions to make a change at student's info
st change_am(st st, char *new_am)
{
	strcpy(st.AM, new_am);
	return st;
}

st  change_name(st st, char *new_name)
{
	strcpy(st.Name, new_name);
	return st;
}

st change_surname(st st, char *new_surname)
{
	strcpy(st.Surname, new_surname);
	return st;
}

st change_grade(st st, double new_grade)
{
	st.Grade = new_grade;
	return st;
}

char * read_change()
{
	char ch[100];
	while ((getchar()) != '\n'); // clear the input buffer
	printf("Give the change: ");
	scanf("%s", ch);
	return ch;
}

double read_grade()
{
	double newgrade = -1;
	printf("Give the change: ");
	scanf("%lf", &newgrade);
	return newgrade;
}

st choose_change(st st_change)
{
	int n;
	char ch[100];
	printf("1. Change Name\n");
	printf("2. Change Surame\n");
	printf("3. Change Grade\n");
	printf("\nChoose a change function: ");
	while (1)
	{
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			strcpy(ch, read_change());
			st_change = change_name(st_change, ch);
			break;

		case 2:
			strcpy(ch, read_change());
			st_change = change_surname(st_change, ch);
			break;

		case 3:
			st_change = change_grade(st_change, read_grade());
			break;

		default:
			printf("Please choose one of the above options: ");

		}
		 
		break;
	}
	return st_change;
}