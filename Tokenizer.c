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
    *numLex = 0;
    char *lexic;
    char line[256];
    char word[256];
    while (fgets(line, 256, inf) != NULL) {
        int size = strlen(line);
        int end = 0;
        int start = 0;
        while (end < size){
          int matchLength = 0;
          matchLength = findLongestCommonSubstring(line, start);
          strncpy(word, &line[start], matchLength);
          printf("match length is %d\n", matchLength);
		  (*numLex)++;
		  end = matchLength + end;
          start = end;
		  printf("end is %d", end);
		  printf("word is %s\n", word);
          memset(word, 0, sizeof(word));
        }
        }

    //fclose(inf);
    return 0;
}

int findLongestCommonSubstring(char *str, int start){
  //printf("length of string is %d \n", strlen(str));
  int size = strlen(str);
  int i = start;
  int length = 1;
  

  for(i = start+1; i < strlen(str); i++){
    char* test = str[i];
    _Bool isWord = validIdentifier(&test);
    _Bool isNum = validNumber(&str[i]);
    if(isWord){
      printf("yes! TEST IS%s", &test);
        length++;
      }
    else{
      printf("no! test is %s", &test);
      return length;
    }
    //printf("test is %s", &test);
  }
  
  return length;
}




