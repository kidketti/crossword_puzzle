#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define x 11	//define dimensions for puzzle

char puzzle[x][x] = {
	{'P', 'H', 'K', 'A', 'S', 'C', 'H', 'A', 'O', 'R', 'Y'},
	{'R', 'K', 'E', 'B', 'I', 'H', 'W', 'Y', 'Q', 'A', 'N'},
	{'L', 'O', 'T', 'B', 'G', 'R', 'A', 'N', 'T', 'C', 'I'},
	{'E', 'R', 'T', 'A', 'M', 'I', 'A', 'N', 'E', 'H', 'T'},
	{'I', 'R', 'I', 'S', 'A', 'S', 'N', 'O', 'X', 'E', 'S'},
	{'R', 'A', 'S', 'I', 'V', 'T', 'D', 'S', 'T', 'L', 'E'},
	{'B', 'F', 'A', 'X', 'N', 'O', 'R', 'A', 'A', 'O', 'D'},
	{'A', 'U', 'R', 'E', 'I', 'P', 'O', 'J', 'V', 'G', 'O'},
	{'G', 'X', 'K', 'L', 'C', 'H', 'I', 'Z', 'T', 'L', 'O'},
	{'S', 'A', 'R', 'A', 'K', 'E', 'D', 'Y', 'L', 'A', 'N'},
	{'T', 'R', 'E', 'B', 'O', 'R', 'D', 'A', 'W', 'A', 'J'} 
	};

int found = 0;

void printPuzzle(){
	int i, j;

	printf("\n");

	for(i = 0; i < 11; i++) {

		for (j = 0; j < 11; j++) {
			printf("%c", puzzle[i][j]);	//loops and prints rows and col
			printf("  ");
		}
		printf("\n");
	}
}


void wordInput(char word[]){
	printf("\nEnter a word: ");
	scanf("%s", word);
	printf("\n");
}

int stringMatching(char text[], char pattern[]){
	int i, j, k;
	int m = strlen(text);
	int n = 11;	

	for(i = 0; i <= (n - m); i++){
		j = 0;
		k = i;

		while(text[j] == pattern[k] && j < m){
			k++;
			j++;
		}
		
		if(j == m){
			return i;	//found it
		}
	}
	
	return -1;	//not found
}

void left_right(char word[]){
	int i, j;
	char temp[11];
	int temp1;

	for(i = 0; i < 11; i++){	//loops through row
		for(j = 0; j < 11; j++){	//loops through col
			temp[j] = puzzle[i][j];
		}
		
		temp1 = stringMatching(word, temp);

		if(temp1 < 0){
			;	//do nothing
		}
		else{
			printf("%s is at (%d, %d) from L-R\n", word, i, temp1);   //prints input word, row, and col found at
			
			found = 1;
		}

	}
}

void right_left(char word[]){
	int i, j;
	char temp[11];
	int temp1;
	
	for(i = 0; i < 11; i++){	//loops through row
		for(j = 11; j > 0; j--){	//Start loop at rightmost col
			temp[10 - j] = puzzle[i][j];
		}
		
		temp1 = stringMatching(word, temp);
		
		if(temp1 < 0){
			;	//do nothing
		}
		else{
			printf("%s is at (%d, %d) from R-L\n", word, i, 10 - temp1);   //prints input word, row, and col found at
			
			found = 1;
		}

	}
}

void top_bottom(char word[]){
    int i, j;
	char temp[11];
	int temp1;

	for(j = 0; j < 11; j++){	//loops through col
		for(i = 0; i < 11; i++){	//loops through row
			temp[i] = puzzle[i][j];
		}
		
		temp1 = stringMatching(word, temp);

		if(temp1 < 0){
			;	//do nothing
		}
		else{
			printf("%s is at (%d, %d) from T-B\n", word, temp1, j);   //prints input word, row, and col found at
			
			found = 1;
		}
	}
}

void bottom_top(char word[]){
    int i, j;
	char temp[11];
	int temp1;

	for(j = 0; j < 11; j++){	//loops through row
		for(i = 11; i > 0; i--){	//loops through col
			temp[10 - i] = puzzle[i][j];
		}
		
		temp1 = stringMatching(word, temp);

		if(temp1 < 0){
			;	//do nothing
		}
		else{
			printf("%s is at (%d, %d) from B-T\n", word, 10 - temp1, j);   //prints input word, row, and col found at
			
			found = 1;
		}
	}
}

int main(){
	char word[11];	

	printPuzzle();
	wordInput(word);
	left_right(word);
	right_left(word);
	top_bottom(word);
	bottom_top(word);

	if(found == 0){	//if string returned not found
		printf("NOT FOUND\n");
	}

	return 0;
}