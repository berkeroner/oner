
	//	Berker ÖNER 150122018
	
		/*		Ýç içe parantezli yapmak için yazdýðým kodda doðru sonucu bulamýyorum. 3. inputla yapýlan iþlemde sonuç 23 yerine 6 ya da 12 çýkýyor. 
			Bu yüzden parantezli iþlemlerde iþlem önceliðini yapamadým. 																				*/
		

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
	
    int result = 0;
    int sign = 1;
    int num = 0;

    while (*s) {
    	
        if (isdigit(*s)) {
            num = 0;
            
            while (isdigit(*s)) {
                num = *s - '0';
                s++;
            }
            
            result += sign * num;
        }
        
		else if (*s == '+') {
            sign = 1;
            s++;
        }
        
		else if (*s == '-') {
            sign = -1;
            s++;
        }
        
		else if (*s == '(') {
            s++;
        }
		
		else if (*s == ')') {
            s++;
        }
		
		else if (*s == ' ') {
            s++;
        }
		
		else {
            printf("Invalid input !\n");
            return 0;
        }
        
    }

    return result;
}

int main() {
	
	char input1[] = "1 + 1";
	char input2[] = "2-1 + 2";
	char input3[] = "(1+(4+5+2)-3)+(6+8)";

    int result1 = calculate(input1);
    int result2 = calculate(input2);
    int result3 = calculate(input3);
    
    printf("Example 1:\nInput: \"%s\"\nOutput: %d\n\n", input1, result1);
    printf("Example 2:\nInput: \"%s\"\nOutput: %d\n\n", input2, result2);
    printf("Example 3:\nInput: \"%s\"\nOutput: %d\n\n", input3, result3);
    
    return 0;
}

