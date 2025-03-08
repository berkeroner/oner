
	//	Berker ÖNER 150122018


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void addNumber(int* numArray, int* size, int num) {
	
	if(*size < MAX_SIZE) {
		numArray[*size] = num;
		(*size)++;
	}
	
}

void sortArray(int* numArray, int size) {
	
		int i, j, sort; 
	
	for(i = 0; i < size-1; i++) {
		for(j = 0; j < size-1; j++) {
			if(numArray[j] > numArray[j+1]) {
				
				sort = numArray[j];
				numArray[j] = numArray[j+1];
				numArray[j+1] = sort;
			}
		}
	}
	
}

double findMedian(int* numArray, int size) {
	
	sortArray(numArray, size);
	
	if(size % 2 == 0) {
		return ((numArray[(size / 2) - 1] + numArray[size / 2]) / 2.0);
	}
	
	else {
		return numArray[size / 2];
	}
}

void inputFile(const char *filename, int *numArray, int *size) {
   
    char line[MAX_SIZE];
    FILE *file = fopen(filename, "r");
    int printOutput = 1;
	int printExp = 1; 
    
    while (fgets(line, sizeof(line), file)) {

		int number;    	
        char command[100];

        if (sscanf(line, "%s %d", command, &number) == 2) {
            if (strcmp(command, "addNumber") == 0) {
                addNumber(numArray, size, number);
            }
        } 
        
        else if (sscanf(line, "%s", command) == 1) {
            if (strcmp(command, "findMedian") == 0) {
            	
            	int i = 0;
            	
            	if(printOutput == 1) {
            		printf("Output:\n");
            		printOutput = 0;
				}

            	double median = findMedian(numArray, *size);
            	
                if (*size % 2 == 0) {
                    printf("%.1f\n", median);
                }
				
				else {
                    printf("%.0f\n", median);
                }

                if (printExp == 1) {
                    printf("\nExplanation:\n");
                    printExp = 0;
                }

                printf("Median of [");
                for (i = 0; i < *size; i++) {
                    if (i > 0) {
                        printf(", ");
                    }
                    printf("%d", numArray[i]);
                }
                if (*size % 2 == 0) {
                	
                    int firstMiddle = numArray[(*size / 2) - 1];
                    int secondMiddle = numArray[*size / 2];
                    
                    printf("] is (%d+%d)/2 = %.1f.\n", firstMiddle, secondMiddle, median);
                }
				
				else {
                    printf("] is %d.\n", (int)median);
                }
			}
			
        }
    }

    fclose(file);
}

int main() {
	
	int numArray[MAX_SIZE];
	int size = 0;
	
	inputFile("input.txt", numArray, &size);
	
	return 0;
}

