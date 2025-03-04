
// Berker ÖNER 150122018

#include <stdio.h>

#define MAX_SIZE 1000 


int findLastRemaining(int n){
	
	int i, j;
	int array[MAX_SIZE];
	
	for(i = 0; i < n; i++){
		array[i] = i + 1;
	}
	
	int left = 1;
	int remaining = n;
	int k = 2;
	
	while (remaining > 1) {
		
        printf("arr = [");
        
        for (i = 0; i < remaining; i++) {
    		printf("%d", array[i]);
    		
    		if (i < remaining - 1) {
        		printf(",");
   			}
		}

        printf("]\n");
        
	    if (k % 2 == 0) {
	
	        for (i = 1, j = 0; i < remaining; i += 2, j++) {
	            array[j] = array[i];
	        }
	        remaining = j;
	            
	    } 
			
		else {
   			for (i = 0, j = 0; i < remaining; i += 2, j++) {
        		array[j] = array[i];
    	}
    	remaining = j;
	}

		k++;
 	   
    }
	
	return array[0];
	
}

int main() {

	int n;
	
	printf("Input: n = ");
	scanf("%d", &n);
	printf("Output:\n");

	int lastRemaining = findLastRemaining(n);
	printf("arr = [%d]", lastRemaining);
	
	return 0;
	
}

