#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//MUHAMMAD DHITAN IMAM SAKTI
//2702367183
//KELAS LG01
//SPECIAL THANKS TO MY BIG BROTHER, PORTFOLIO COURSES ON YOUTUBE, AND CHATGPT
//THANKS FOR HELPING ME OUT ON THIS ASSIGNMENT :D
//||||||||||||||||||||||||||||||||||||||||||||||||||||
//Comparation used in this program follows the examples inside the word file(in BinusMaya), therefore the csv file have been modified
//Location 1 -> Location
//Location 2 -> City
//The rest remains the same
//Ini dilakukan karena di word nya Column yang di input adalah Location bukan Location 1 ataupun Location 2
//agar comparation dapat dilakukan, saya mengubah nama Header di csv file nya menjad Location dan City 
//supaya sesuai dengan input yang dicontohkan di file Word

//struct for the datas
struct Data {
	char location[255];
	char city[255];
	int price;
	int rooms;
	int bathroom;
	int carpark;
	char type[255];
	char furnish[255];
};
//global variable
Data infos[3940];
int numInf = 0;

//menu
void menu(){
	printf("WELCOME!!!\n");
	printf("What do you want to do?\n");
	printf("1. Display data\n");
	printf("2. Search data\n");
	printf("3. Sort data\n");
	printf("4. Export data\n");
	printf("5. Exit\n");
}

//read data from the file
void read(Data infos[], int *num){
	FILE *fp = fopen("fileAOL.csv", "r");
	fscanf(fp, "%*[^\n]\n");
	while (*num < 3940 && fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%[^\n]\n",
                  infos[*num].location,
                  infos[*num].city,
                  &infos[*num].price,
                  &infos[*num].rooms,
                  &infos[*num].bathroom,
                  &infos[*num].carpark,
                  infos[*num].type,
                  infos[*num].furnish) == 8) {
        (*num)++;
    }
    fclose(fp);
}
//display data from the file
void display(Data infos[], int numIn){
	int row;
	printf("Number of rows: ");
	scanf("%d", &row);
	getchar();
	printf("\n");
		printf("%-30s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
           "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
        printf("\n");
    for (int i = 0; i < row && i < numIn; i++) {
        printf("%-30s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
               infos[i].location, infos[i].city, infos[i].price,
               infos[i].rooms, infos[i].bathroom, infos[i].carpark,
               infos[i].type, infos[i].furnish);
        printf("\n");
    }
    char yes;
    printf("\nKetik y untuk melanjutkan: ");
    scanf(" %c", &yes);
    if(yes == 'y'){
    	system("cls");
	}
}
//to trim leading and trailling spaces
void trim(char query[]){
	int count = 0;
	while (query[count] == ' ' || query[count] == '\n' || query[count] == '\t'){
		count++;
	}
	if(count != 0){
		int i = 0;
		while(query[i + count] != '\0'){
			query[i] = query[i + count];
			i++;
		}
		query[i] = '\0';
	}
	int j = strlen(query) - 1;
	while (j > 0){
		if(query[j] == ' ' || query[j] == '\n' || query[j] == '\t'){
			j--;
		}
		else {
			break;
		}
	}
	query[j + 1] = '\0';
}
//selectRow for char inputs
void selectRow(Data infos[], int numIn, char *col, char *query) {
    trim(query); //trim the query
    int yea = 0; //flag integer
    printf("\n");
    for (int i = 0; i < numIn; i++) {
    	trim(infos[i].location); //trim the location (kalau gaada, it wont work, idk why
        if ((strcmp(col, "Location") == 0 && strcmp(infos[i].location, query) == 0) || 
		   (strcmp(col, "City") == 0 && strcmp(infos[i].city, query) == 0) || (strcmp(col, "Type") == 0 
		   && strcmp(infos[i].type, query) == 0) || (strcmp(col, "Furnish") == 0 && strcmp(infos[i].furnish, query)
		   == 0)){
			if (yea == 0) {
                printf("%-26s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
                       "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                printf("\n");
                yea = 1;
            }
            	printf("%-26s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
                   infos[i].location, infos[i].city, infos[i].price,
                   infos[i].rooms, infos[i].bathroom, infos[i].carpark,
                   infos[i].type, infos[i].furnish);
            	printf("\n");
            	yea = 1;
		} 
	}
    	if (yea == 0) {
        	printf("Data not found TT (emoji nangis)\n");
    	}
    	char yes;
    	printf("Ketik y untuk melanjutkan: ");
    	scanf(" %c", &yes);
    	if (yes == 'y') {
    		system("cls");
    	}
}
//selectRow for integer
void selectRowInteger(Data infos[], int numIn, char *col, long long int query){
	int yea = 0;
	printf("\n");
	for(int i = 0; i < numIn; i++){
		trim(col);
		if((strcmp(col, "Price") == 0 && infos[i].price == query) ||
		   (strcmp(col, "Rooms") == 0 && infos[i].rooms == query) ||
		   (strcmp(col, "Bathrooms") == 0 && infos[i].bathroom == query) ||
		   (strcmp(col, "CarParks") == 0 && infos[i].carpark == query)){
			if(yea == 0){
				printf("%-26s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
                       "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                yea = 1;
			}
				printf("%-26s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
                   infos[i].location, infos[i].city, infos[i].price,
                   infos[i].rooms, infos[i].bathroom, infos[i].carpark,
                   infos[i].type, infos[i].furnish);
            	yea = 1;
		}
	}
	if(yea == 0){
		printf("Data not found TT(emoji nangis)\n");
	}
	char yes;
	printf("Ketik y untuk melanjutkan: ");
	scanf(" %c", &yes);
	if(yes == 'y'){
		system("cls");
	}
}	
//swap function
void swap (struct Data infos[], int a, int b){
	struct Data temp = infos[a];
	infos[a] = infos[b];
	infos[b] = temp;
}
//quickSort for the sorting
void quickSortCharASC(struct Data infos[], int low, int high, char* col);
int partitionCharASC(struct Data infos[], int low, int high, char* col);
void quickSortCharDSC(struct Data infos[], int low, int high, char* col);
int partitionCharDSC(struct Data infos[], int low, int high, char* col);
void quickSortIntASC(struct Data infos[], int low, int high, char* col);
int partitionIntASC(struct Data infos[], int low, int high, char* col);
void quickSortIntDSC(struct Data infos[], int low, int high, char* col);
int partitionIntDSC(struct Data infos[], int low, int high, char* col);

void quickSortCharASC(struct Data infos[], int low, int high, char* col){
	if(low < high){
		int pivot = partitionCharASC(infos, low, high, col);
		quickSortCharASC(infos, low, pivot - 1, col);
        quickSortCharASC(infos, pivot + 1, high, col);
	}
}

int partitionCharASC(struct Data infos[], int low, int high, char* col){
	char* pivot;
    if (strcmp(col, "Location") == 0) {
        pivot = infos[high].location;
    }
    else if (strcmp(col, "City") == 0) {
        pivot = infos[high].city;
    }
    else if (strcmp(col, "Type") == 0) {
        pivot = infos[high].type;
    }
    else if (strcmp(col, "Furnish") == 0) {
        pivot = infos[high].furnish;
    }

    int i = (low);

    for (int j = low; j <= high - 1; j++) {
        char* current;
        if (strcmp(col, "Location") == 0) {
            current = infos[j].location;
        }
        else if (strcmp(col, "City") == 0) {
            current = infos[j].city;
        }
        else if (strcmp(col, "Type") == 0) {
            current = infos[j].type;
        }
        else if (strcmp(col, "Furnish") == 0) {
            current = infos[j].furnish;
        }
        if(strcmp(current, pivot) <= 0){
			swap(infos, i, j);
			i++;
		}
	}	
	swap(infos, i, high);
	
	return i;
}

void quickSortCharDSC(struct Data infos[], int low, int high, char* col){
	if(low < high){
		int pivot = partitionCharDSC(infos, low, high, col);
		quickSortCharDSC(infos, low, pivot - 1, col);
        quickSortCharDSC(infos, pivot + 1, high, col);
	}
}

int partitionCharDSC(struct Data infos[], int low, int high, char* col){
	char* pivot;
    if (strcmp(col, "Location") == 0) {
        pivot = infos[high].location;
    }
    else if (strcmp(col, "City") == 0) {
        pivot = infos[high].city;
    }
    else if (strcmp(col, "Type") == 0) {
        pivot = infos[high].type;
    }
    else if (strcmp(col, "Furnish") == 0) {
        pivot = infos[high].furnish;
    }

    int i = (low);

    for (int j = low; j <= high - 1; j++) {
        char* current;
        if (strcmp(col, "Location") == 0) {
            current = infos[j].location;
        }
        else if (strcmp(col, "City") == 0) {
            current = infos[j].city;
        }
        else if (strcmp(col, "Type") == 0) {
            current = infos[j].type;
        }
        else if (strcmp(col, "Furnish") == 0) {
            current = infos[j].furnish;
        }
        if(strcmp(current, pivot) >= 0){
			swap(infos, i, j);
			i++;
		}
	}	
	swap(infos, i, high);
	
	return i;
}

void quickSortIntASC(struct Data infos[], int low, int high, char* col){
	if(low < high){
		int pivot = partitionIntASC(infos, low, high, col);
		quickSortIntASC(infos, low, pivot - 1, col);
        quickSortIntASC(infos, pivot + 1, high, col);
	}
}

int partitionIntASC(struct Data infos[], int low, int high, char* col){
	int pivot;
    if (strcmp(col, "Price") == 0) {
        pivot = infos[high].price;
    }
    else if (strcmp(col, "Rooms") == 0) {
        pivot = infos[high].rooms;
    }
    else if (strcmp(col, "Bathrooms") == 0) {
        pivot = infos[high].bathroom;
    }
    else if (strcmp(col, "CarParks") == 0) {
        pivot = infos[high].carpark;
    }

    int i = (low);

    for (int j = low; j <= high - 1; j++) {
        int current;
        if (strcmp(col, "Price") == 0) {
            current = infos[j].price;
        }
        else if (strcmp(col, "Rooms") == 0) {
            current = infos[j].rooms;
        }
        else if (strcmp(col, "Bathrooms") == 0) {
            current = infos[j].bathroom;
        }
        else if (strcmp(col, "CarParks") == 0) {
            current = infos[j].carpark;
        }
        if(current <= pivot){
			swap(infos, i, j);
			i++;
		}
	}	
	swap(infos, i, high);
	
	return i;
}

void quickSortIntDSC(struct Data infos[], int low, int high, char* col){
	if(low < high){
		int pivot = partitionIntDSC(infos, low, high, col);
		quickSortIntDSC(infos, low, pivot - 1, col);
        quickSortIntDSC(infos, pivot + 1, high, col);
	}
}

int partitionIntDSC(struct Data infos[], int low, int high, char* col){
	int pivot;
    if (strcmp(col, "Price") == 0) {
        pivot = infos[high].price;
    }
    else if (strcmp(col, "Rooms") == 0) {
        pivot = infos[high].rooms;
    }
    else if (strcmp(col, "Bathrooms") == 0) {
        pivot = infos[high].bathroom;
    }
    else if (strcmp(col, "CarParks") == 0) {
        pivot = infos[high].carpark;
    }

    int i = (low);

    for (int j = low; j <= high - 1; j++) {
        int current;
        if (strcmp(col, "Price") == 0) {
            current = infos[j].price;
        }
        else if (strcmp(col, "Rooms") == 0) {
            current = infos[j].rooms;
        }
        else if (strcmp(col, "Bathrooms") == 0) {
            current = infos[j].bathroom;
        }
        else if (strcmp(col, "CarParks") == 0) {
            current = infos[j].carpark;
        }
        if(current >= pivot){
			swap(infos, i, j);
			i++;
		}
	}	
	swap(infos, i, high);
	
	return i;
}
//to identify if the column input is an integer or a string
int yeaInteger(char* col){
	return strcmp(col, "Price") == 0 || strcmp(col, "Rooms") == 0 || strcmp(col, "Bathrooms") == 0 
		   || strcmp(col, "CarParks") == 0;
}
//to replace space with underscore for the CSV file name after exporting
void replaceUndrScr(char *string){
	while(*string){
		if(*string == ' '){
			*string = '_';
		}
		string++;
	}
}
//export data function
void exportData(char *filename, struct Data infos[],int numIn){
	replaceUndrScr(filename);
	FILE *fp = fopen(filename, "w");
	
	fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", "Location", "City", "Price", "Rooms", "Bathrooms",
			"CarParks", "Type", "Furnish");
	for(int i = 0; i < numIn; i++){
		fprintf(fp, "%s,%s,%d,%d,%d,%d,%s,%s\n", infos[i].location, infos[i].city, infos[i].price,
				infos[i].rooms, infos[i].bathroom, infos[i].carpark, infos[i].type, infos[i].furnish);
	}
	fclose(fp);
	printf("Data has been successfully written to %s.csv!\n", filename);
	char yes;
	printf("Ketik y untuk melanjutkan: ");
	scanf(" %c", &yes);
	if(yes == 'y'){
	system("cls");
	}
}
//main
int main (){
	read(infos, &numInf);
	int input;
	do{
		menu();
		printf("Your choice: ");
		scanf("%d", &input);
		getchar(); 
		switch(input){
			case 1: 
				display(infos, numInf); 
				break;
			case 2: 
				char col[9];
				char query[255];
				long long int query2;
				printf("Choose a column: ");
                scanf(" %[^\n]", col);
                getchar();
                printf("Type in the data that you want to find: ");
                scanf("%s", query);
                getchar();
				if(sscanf(query, "%lld", &query2) == 1){
					selectRowInteger(infos, numInf, col, query2); 
				} else {
					selectRow(infos, numInf, col, query);	
				} 
				break;
			case 3: 
				char order[5];
				printf("Choose a column: ");
				scanf("%s", col);
				getchar();
				printf("Sorted in Ascending or Descending order? ");
				scanf("%s", order);
				getchar();
				if(yeaInteger(col)){
					if(strcmp(order, "asc") == 0){
						quickSortIntASC(infos, 0, numInf - 1, col);
						printf("%-26s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
                       	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                		printf("\n");
            			for(int i = 0; i < 10; i++){
            				printf("%-26s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
                   			infos[i].location, infos[i].city, infos[i].price,
                   			infos[i].rooms, infos[i].bathroom, infos[i].carpark,
                   			infos[i].type, infos[i].furnish);
                			printf("\n");
						}
					} else if (strcmp(order, "dsc") == 0){
						quickSortIntDSC(infos, 0, numInf - 1, col);
						printf("%-26s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
                        "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                		printf("\n");
            			for(int i = 0; i < 10; i++){
            			printf("%-26s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
                   		infos[i].location, infos[i].city, infos[i].price,
                   		infos[i].rooms, infos[i].bathroom, infos[i].carpark,
                   		infos[i].type, infos[i].furnish);
                		printf("\n");
						}
					}
				} else {
					if(strcmp(order, "asc") == 0){
						quickSortCharASC(infos, 0, numInf - 1, col);
						printf("%-26s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
                       	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                		printf("\n");
            			for(int i = 0; i < 10; i++){
            				printf("%-26s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
                   			infos[i].location, infos[i].city, infos[i].price,
                   			infos[i].rooms, infos[i].bathroom, infos[i].carpark,
                   			infos[i].type, infos[i].furnish);
                			printf("\n");
						}
				} else if (strcmp(order, "dsc") == 0){
						quickSortCharDSC(infos, 0, numInf - 1, col);
						printf("%-26s%-20s%-20s%-15s%-15s%-15s%-15s%-15s\n",
                       	"Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                		printf("\n");
            			for(int i = 0; i < 10; i++){
            				printf("%-26s%-20s%-20d%-15d%-15d%-15d%-15s%-15s\n",
                   			infos[i].location, infos[i].city, infos[i].price,
                   			infos[i].rooms, infos[i].bathroom, infos[i].carpark,
                   			infos[i].type, infos[i].furnish);
                			printf("\n");
						}
					}
				}
				char yes;
				printf("Ketik y untuk melanjutkan: ");
				scanf(" %c", &yes);
				if(yes == 'y'){
				system("cls");
				}
				break;	
			case 4: 
				char fileName[255];
				printf("File Name: ");
				scanf("%[^\n]", fileName);
				replaceUndrScr(fileName);
				exportData(fileName, infos, numInf); 
				break;
			case 5: 
				printf("Sayonaraaa\n");
				break;
		}
	} while (input != 5);
	return 0;
}
