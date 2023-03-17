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
          while (isspace(line[end])) {
          end++;
          start++;
        }
          int matchLength = 0;
          matchLength = findLongestCommonSubstring(line, start);
          strncpy(word, &line[start], matchLength);
          if(strcmp(word, "")==0){
            end++;
            start++;
            continue;
          }
          printf("match length is %d\n", matchLength);
		  (*numLex)++;
		  end = matchLength + end;
          start = end;
		  printf("end is %d", end);
		  printf("word is %s\n", word);


            struct lexics lexeme = lexemmeGenerator(word, numLex);
            aLex[*numLex - 1] = lexeme;
          if(strcmp(word, "")==0){
            end++;
            start++;
          }
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
        lexemme.token = BINOP;
    }
    else if (strcmp(str, "%") == 0) {
        lexemme.token = BINOP;
    }
    else if (strcmp(str, "while") == 0) {
        lexemme.token = 4;
    }
    else if (strcmp(str, "return") == 0) {
        lexemme.token = 5;
    }
    else if (strcmp(str, "int") == 0 || strcmp(str, "void")==0) {
        lexemme.token = 9;
    }
    else if (validIdentifier(str)){
        lexemme.token = 10;
    }
    else if (validNumber(str)){
        lexemme.token = 12;
    }
   return lexemme;
}


int findLongestCommonSubstring(char *str, int start){
    int size = strlen(str);
    int i = start;
    int length = 1;
    char prev = '\0';
    char* lastMatch = NULL;

    for(i = start+1; i < strlen(str); i++){
        char curr = str[i];
        char subStr[i-start+2];
        strncpy(subStr, &str[start], i-start+1);
        subStr[i-start+1] = '\0';
        _Bool isWord = validIdentifier(subStr);
        _Bool isNum = validNumber(subStr);

        if(lastMatch != NULL && strlen(lastMatch) == 1){
            char test[3] = {lastMatch[0], curr, '\0'};
            if(strcmp(test, "==") == 0 || strcmp(test, "!=") == 0 ) {
                length++;
                lastMatch = test;
                continue;
            }
        }
       if(isWord || isNum){
            length++;
            lastMatch = subStr;
        }
        else{
            return length;
        }
    }

    return length;
}





