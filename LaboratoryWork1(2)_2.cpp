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

void SetSize(int *);
struct film * CreateStructArray(int);
void FillStructArray(struct film*, int);

void ShowOptions();
void OperationsWithArray(struct film*, int *, int);
void FindFilm (struct film *, int *);
void DeleteFilm(struct film *, int *);
int CountElements(struct film*, int*, int);
void ReallocateArray(struct film*, int*, int);
void WorkWithLibrary(struct film*, int*);
void ReplaceElemByKey(struct film*, int*, int);

int main()
{
	int size;
	SetSize(&size);
	struct film * library = CreateStructArray(size);
	FillStructArray(library, size);
	WorkWithLibrary(library, &size);
	
	return 0;
}

void SetSize(int * size) {
	do {
		printf("Enter size of film's library: ");
		scanf("%d", size);
	} while (*size <= 0);
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
		getchar();
		printf("Enter genre of film %d: ", i + 1);
		fgets(arr[i].info.genre, 9, stdin);
		printf("Enter year of film %d: ", i + 1);
		scanf("%d", &arr[i].info.year);
	}
}

void ShowStructArray(struct film* arr, int * size) {
	int i;
	if (*size == 0) {
		printf("there aren't films left here :(\n");
	}
	else {
		for (i = 0; i < *size; i++) {
			printf("\nFilm %d:\n", i + 1);
			printf("\nName: %s", arr[i].name);
			printf("Length: %d\n", arr[i].length);
			printf("Genre: %s", arr[i].info.genre);
			printf("Year: %d", arr[i].info.year);
			printf("\n");
		}
	}
}

void ShowOptions() {
	printf("\nWhat would you like to do with the library?\n");
	printf("1. Find film with the same name\n");
	printf("2. Delete film with length longer than entered\n");
	printf("3. Show library\n\n");
	printf("0. Exit.");
	printf("\n");
}

void OperationsWithArray(struct film* arr, int * size, int opt) {
    
	switch (opt) {
	case 1: 
		FindFilm(arr, size);
		break;
	case 2:
		DeleteFilm(arr, size);
		break;
	case 3:
		ShowStructArray(arr, size);
		break;
	case 0:
		break;
	default:
			printf("Error! You have chosen wrong option! Try again");
		break;
	}
}

void FindFilm (struct film * arr, int * size){
	if (*size == 0) {
		printf("there aren't films left here :(\n");
	}
	else {
		char key[20];
		int i;
		bool isExist = false;
		printf("Enter film name you want to find: ");
		getchar();
		fgets(key, 20, stdin);
		for (i = 0; i < *size; i++) {
			if (strcmp(arr[i].name, key) == 0) {
				isExist = true;
				printf("\nWe found film with the same name:\n");
				printf("Film %d\n", i + 1);
				printf("\nName: %s", arr[i].name);
				printf("Length: %d\n", arr[i].length);
				printf("Genre: %s\n", arr[i].info.genre);
				printf("Year: %d", arr[i].info.year);
				printf("\n");
			}
		}
		if (!isExist) {
			printf("\nWe found nothing with the same name :(\n");
		}
	}
    
    
}

void DeleteFilm(struct film* arr, int * size) {
	if (*size == 0) {
		printf("there aren't films left here :(\n");
	}
	else {
		int key;
		int amount;

		printf("Enter length film: ");
		scanf("%d", &key);

		amount = CountElements(arr, size, key);
		if (amount != 0) {
			ReplaceElemByKey(arr, size, key);
			ReallocateArray(arr, size, amount);
			printf("deleted!\n");
		}
		else {
			printf("There is nothing to delete\n");
		}
	}
	
}

void ReplaceElemByKey(struct film* arr, int * size, int key) {
	int i, j;
	struct film temp;
	

	for (i = 0; i < *size; i++) {
		for (j = *size - 1; j > i; j--) {
			if ((arr[j - 1].length > key) && (arr[j].length) <= key) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int CountElements(struct film * arr, int * size, int key) {
	int i, counter = 0;
	for (i = 0; i < *size; i++) {
		if (key < arr[i].length) {
			counter++;
		}
	}

	return counter;
}

void ReallocateArray(struct film* arr, int * size, int count) {
	*size = *size - count;
	arr = (struct film*)realloc(arr, (*size) * sizeof(struct film));
}

void WorkWithLibrary(struct film * arr, int * size) {
	int opt;
	do {
		ShowOptions();
		scanf("%d", &opt);
		system("cls");
		OperationsWithArray(arr, size, opt);
	} while (opt != 0);
	
}