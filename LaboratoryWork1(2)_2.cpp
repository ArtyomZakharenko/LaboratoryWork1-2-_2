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

void ShowOptions();
void OperationsWithArray(struct film*, int);
void FindFilm (struct film *, int);
void DeleteFilm(struct film *, int);

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
		scanf("%19s", &arr[i].info.genre);
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

void ShowOptions() {
	printf("What would you like to do with the library?\n");
	printf("1. Find film with the same name\n");
	printf("2. Delete film with length longer than entered\n");
	printf("3. Show library\n\n");
	printf("0. Exit.");
}

void OperationsWithArray(struct film* arr, int size) {
    int opt;
    scanf("%d", opt);
    
	switch (opt) {
	case 1: 
		FindFilm(arr, size);
		break;
	case 2:
		break;
	case 3:
		ShowStructArray(arr, size);
		break;
	case 0:
		break;
	default:
			printf("Error! You have chosen wrong option! Try again");
		ShowOptions();
		break;
	}
}

void FindFilm (struct film * arr, int size){
    char key[20];
    int i;
	bool isExist = false;
    printf ("Enter film name you want to find: ");
    scanf("%19s", &key);
    for (i = 0; i < size; i++){
        if (strcmp(arr[i].name, key) == 0){
			isExist = true;
			printf("We found film with the same name:");
			printf("Film %d\n", i + 1);
			printf("\nName: %s", arr[i].name);
			printf("Length: %d\n", arr[i].length);
			printf("Genre: %s\n", arr[i].info.genre);
			printf("Year: %d", arr[i].info.year);
			printf("\n");
        }
    }
	if (!isExist) {
		printf("We found nothing with the same name :(");
	}
    
}

void DeleteFilm(struct film* arr, int size) {
	int key;
	int amount;

	printf("Enter length film: ");
	scanf("%d", &key);

	amount = CountElements(arr, size, key);
	if (amount != 0) {
		ReplaceElemByKey(arr, size, key);

	}
	
}

void ReplaceElemByKey(struct film* arr, int size, int key) {
	int i, j, temp;
	

	for (i = 0; i < size; i++) {
		for (j = size - 1; j > i; j--) {
			if ((arr[j - 1].length > key) && (arr[j].length) <= key) {
				temp = arr[j - 1].length;
				arr[j - 1].length = arr[j].length;
				arr[j].length = temp;
			}
		}
	}
}

int CountElements(struct film* arr, int size, int key) {
	int i, counter = 0;
	for (i = 0; i < size; i++) {
		if (key < arr[i].length) {
			counter++;
		}
	}

	return counter;
}

void ReallocateArray(struct film* arr, int size, int count) {
	arr = (struct film*)realloc(arr, (size-count)*sizeof(struct film));
}
