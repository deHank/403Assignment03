#include "Tokenizer.h"
#include <string.h>

//*inf is already open
//*I need to modify int numLex
//*And add the lexs to struct lexics
_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf){
    if (inf == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    char *lexic;
    char line[256];
    while (fgets(line, 256, inf) != NULL) {
        int size = strlen(line);
        int start = 0;
        int end = 0;
        int longestMatch = 0;
        while (end < size){
            int matchLength = 0;
            for(int i = 0; i < 13; i++){
                matchLength = findLongestCommonSubstring(line);
            }
        }
        }

    //fclose(inf);
    return 0;
}

int findLongestCommonSubstring(const char *str){
    return 1;
}




