#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct description {
	char genre[10];
	int year;
};

struct film {
	int length;
	char* name;
	struct description info ;
};

int SetSize();
struct film * CreateStructArray(int);
void FillStructArray(struct film*, int);

int ShowOptions();
void OperationsWithArray(struct film*, int, int);


int main()
{
	int size = SetSize();
	struct film * library = CreateStructArray(size);
	FillStructArray(library, size);
	ShowStructArray(library, size);
}

int SetSize() {
	int size;
	printf("Enter size of film's library: ");
	scanf("%d", &size);

	return size;
}

struct film* CreateStructArray(int size) {
	struct film* arr = (struct film*)calloc(size, sizeof(struct film));
	return arr;
}

void FillStructArray(struct film* arr, int size) {
	int i;

	
	for (i = 0; i < size; i++) {
		getchar();
		arr[i].name = (char*)calloc(20, sizeof(char));
		printf("\nEnter name of film %d: ", i+1);
		fgets(arr[i].name, 20, stdin);
		printf("Enter length of film %d: ", i+1);
		scanf("%d", &arr[i].length);
		printf("Enter genre of film %d: ", i + 1);
		scanf("%s", &arr[i].info.genre);
		printf("Enter year of film %d: ", i + 1);
		scanf("%d", &arr[i].info.year);
	}
}

void ShowStructArray(struct film* arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Film %d\n", i + 1);
		printf("\nName: %s", arr[i].name);
		printf("Length: %d\n", arr[i].length);
		printf("Genre: %s\n", arr[i].info.genre);
		printf("Year: %d", arr[i].info.year);
		printf("\n");
	}
}

int ShowOptions() {
	int option;
	printf("What would you like to do with the library?\n");
	printf("1. Find film with the same name\n");
	printf("2. Delete film with length longer than entered\n");
	printf("3. Show library\n\n");
	printf("0. Exit.");

	scanf("%d", &option);
	
	return option;
}

void OperationsWithArray(struct film * arr, int size, int opt) {
	switch (opt) {
	case 1: 
		break;
	case 2:
		break;
	case 3:
		//ShowStructArray();
		break;
	case 0:
		break;
	default:
			printf("Error! You have chosen wrong option! Try again");
		ShowOptions();
		break;
	}
}

