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


          struct lexics lexeme = lexemmeGenerator(word, numLex);
          aLex[*numLex - 1] = lexeme;
          memset(word, 0, sizeof(word));
        }
        }

    //fclose(inf);
    return 0;
}

struct lexics lexemmeGenerator(char *str, int *numLex) {
    struct lexics lexemme;
    strcpy(lexemme.lexeme, str);
    enum token;
    if (strcmp(str, "(") == 0) {
        lexemme.token = 0;
    }
    else if (strcmp(str, ")") == 0) {
        lexemme.token = 1;
    }
    else if (strcmp(str, "{") == 0) {
        lexemme.token = 2;
    }
    else if (strcmp(str, "}") == 0) {
        lexemme.token = 3;
    }
    else if (strcmp(str, "=") == 0) {
        lexemme.token = 6;
    }
    else if (strcmp(str, ",") == 0) {
        lexemme.token = 7;
    }
    else if (strcmp(str, ";") == 0) {
        lexemme.token = 8;
    }
    else if (strcmp(str, "+") == 0 || strcmp(str, "*") == 0 || strcmp(str, "!") == 0) {
        lexemme.token = 9;
    }
    else if (strcmp(str, "%") == 0) {
        lexemme.token = BINOP;
    }
    else {
        printf("%s : Did not match any case.\n", str);
    }
   return lexemme;
}


int findLongestCommonSubstring(char *str, int start){
  //printf("length of string is %d \n", strlen(str));
  int size = strlen(str);
  int i = start;
  int length = 1;
  char prev = '\0';

  for(i = start+1; i < strlen(str); i++){
    char* test = str[i];
    char curr = str[i];
    char test1[3] = {prev, curr, '\0'};
    _Bool isWord = validIdentifier(&test);
    _Bool isNum = validNumber(&str[i]);
    if(strcmp(test1, "==") == 0) {  // check for '=='
      length++;
      i++;  // skip the second '=' character
    }
    else if(isWord){
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




