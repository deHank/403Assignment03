#include "Tokenizer.h"
#include "Givens.h"
#include <string.h>
#include <stdio.h>

//*inf is already open
//*I need to modify int numLex
//*And add the lexs to struct lexics
_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf){
    if (inf == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    numLex = 0;
    char *lexic;
    char line[256];
    char *word;
    while (fgets(line, 256, inf) != NULL) {
        int size = strlen(line);
        int end = 0;
        int longestMatch = 0;
        while (end < size){
            int matchLength = 0;
                matchLength = findLongestCommonSubstring(line);
		numLex++;
		end += matchLength;
		printf("end is %d", end);
		printf("\n",word);
        }
        }

    //fclose(inf);
    return 0;
}

int findLongestCommonSubstring(char *str){
  printf("length of string is %d", strlen(str));
  int size = strlen(str);
  int i = 0;
  

  for(i = 0; i < strlen(str); i++){
    char* test = str[i];
    _Bool isWord = validIdentifier(&test);
    _Bool isNum = validNumber(&str[i]);
    if(isWord){
      printf("yes!");
    }
    else{
      return i+1;
    }
    printf("test is %s", &test);
  }
  
  return i+1;
}




