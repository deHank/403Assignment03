#include "Givens.h"


_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf);

struct lexics lexemmeGenerator(char *str, int *numLex);

int findLongestCommonSubstring(char *str, int start);

_Bool validBinaryOperator(char *str);
