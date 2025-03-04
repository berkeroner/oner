
			/* BERKER ÖNER - 150122018 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000


typedef struct DigitNode{
	
	int digit;
	struct DigitNode* next;
	
}DigitNode;


DigitNode* createTheDigit(int digit) {
	
	DigitNode* newDigit = (DigitNode*)malloc(sizeof(DigitNode));
	
	newDigit-> digit = digit;
	newDigit -> next = NULL;
	
	return newDigit;
	
}


void addToTheEnd(DigitNode** head, int digit) {
	
	DigitNode* newDigit = createTheDigit(digit);
	
	if(*head == NULL){
		*head = newDigit;
	}
	
	else{
		DigitNode* temp = *head;
		
		while(temp-> next != NULL){
			temp = temp -> next;
		}
		
		temp -> next = newDigit;
	}
	
}


int removeDecimalPoint(char* numberString, DigitNode** numberHead){
	int decimalCount = 0;
	int fractCount = 0;
	int i = 0;
	
	while(numberString[i] != '\0'){
		if(numberString[i] == '.'){
			decimalCount = 1;		
			}
		else{
			addToTheEnd(numberHead, numberString[i] - '0');
			if(decimalCount){
				fractCount++;
			}
		}
		i++;
	}
	return fractCount;
	
}

DigitNode* reverseList(DigitNode* head){
	DigitNode* prev = NULL;
	DigitNode* current = head;
	DigitNode* next = NULL;
	
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	return prev;
}

void multiplyTheLists(DigitNode* multiplicand, DigitNode* multiplier, int totalFractCount, FILE* outputFile){
	
	DigitNode* temp = multiplicand;
	
	int numLength1 = 0;
	int numLength2 = 0;
	
	while(temp){

		numLength1++;
		temp = temp->next;
	}
	
	temp = multiplier;
	
	while(temp){

		numLength2++;
		temp = temp->next;
	}
	
	int resultSize = numLength1 + numLength2;
	int* result = (int*)calloc(resultSize, sizeof(int));
	
	multiplicand = reverseList(multiplicand);
	multiplier = reverseList(multiplier);
	
	DigitNode* now1 = multiplicand;
	
	int i = 0;
	
	for(i = 0; now1 != NULL; i++){
		DigitNode* now2 = multiplier;
		int carry = 0;
		int j = 0;
		for(j = 0; now2 != NULL; j++){
			int multiply = ((now1->digit * now2->digit) + result[i+j] + carry);
			carry = multiply / 10;
			result[i+j] = multiply % 10;
			now2 = now2->next;
		}
		if(carry > 0){
			result[i + numLength2] += carry;
		}
		now1 = now1->next;
	}
		fprintf(outputFile, "\nResult : ");
		printf("\nResult : ");
		
		int decimalPosition = totalFractCount;
		int leadingZero = 1;
		
		for(i = resultSize - 1; i>= 0; i--){
			if(i == decimalPosition - 1 && totalFractCount > 0){
				fprintf(outputFile, ".");
				printf(".");
			}
			if(result[i] != 0){
				leadingZero = 0;
			}
			if(!leadingZero || i == decimalPosition -1){
				fprintf(outputFile, "%d", result[i]);
				printf("%d", result[i]);
			}
		}
		
		free(result);
}

int main() {
	
	int start, finish;
		
	start = clock();
	
	FILE* inputFile = fopen("150122018_prj1_input.txt", "r");
	FILE* outputFile = fopen("150122018_prj1_output.txt", "w");
	
	if(inputFile == NULL){
		fprintf(outputFile, "Error : Your input file is not opened !");
		printf("Error : Your input file is not opened !");
	}
	
	char multiplicand[MAX_SIZE];
	char multiplier[MAX_SIZE];
	char buffer[MAX_SIZE];
	
	if(fgets(buffer, sizeof(buffer), inputFile) != NULL){
		sscanf(buffer, "%s %s", multiplicand, multiplier);
	}
	
	printf("Multiplicand : %s", multiplicand);
	printf("\nMultiplier : %s", multiplier);
	
	fclose(inputFile);

	
	DigitNode* multiplicandList = NULL;
	DigitNode* multiplierList = NULL;

	
	int fractCount1 = removeDecimalPoint(multiplicand, &multiplicandList);
	int fractCount2= removeDecimalPoint(multiplier, &multiplierList);
	
	int totalFractCount = fractCount1 + fractCount2;

	fprintf(outputFile, "Multiplicand : %s\nMultiplier : %s", multiplicand, multiplier);

	multiplyTheLists(multiplicandList, multiplierList, totalFractCount, outputFile);

	finish = clock();
	double executionTime = ((double) (finish - start)) / CLOCKS_PER_SEC;
	fprintf(outputFile, "\nExecution Time : %f", executionTime);
	printf("\nExecution Time : %f", executionTime);

	fclose(outputFile);
	
	return 0;
	
}



