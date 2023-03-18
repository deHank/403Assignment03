#include "Givens.h"
#include "Analyzer.h"
#include <stdbool.h>


int index = 0;
int numLex = 0;
struct lexics *tokens;

_Bool parser(struct lexics *someLexics, int numberOfLexics){
     tokens = someLexics;
     numLex = numberOfLexics;
    index = 0;
 if (index != numLex) {
        return 1;
    }
    return 0;
}

_Bool header(){
}

_Bool match(enum token expectedToken){
    if (index < numLex && tokens[index].token == expectedToken){
      index++;
      return true;
    }
    else{
     return false;
    }

}
