%{
#include <stdio.h>
#include<stdlib.h>
%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%
sentence:simple_sentence  {printf("simple sentence.\n"); }
      |compound_sentence { printf("compound sentence.\n"); }
      ;
simple_sentence:subject verb object
      |subject verb object prep_phrase
      ;

compound_sentence:simple_sentence CONJUNCTION simple_sentence
      |compound_sentence CONJUNCTION simple_sentence
      ;
subject:NOUN
      |PRONOUN
      |ADJECTIVE subject
      ;

verb:VERB
      |ADVERB VERB
      |verb VERB
      ;

object:NOUN
      |ADJECTIVE object
      ;

prep_phrase:PREPOSITION NOUN
      ;
%%

extern FILE *yyin;

int main()
{
  yyparse();
             
return 0;
}

void yyerror(s)
char *s;
{

}
