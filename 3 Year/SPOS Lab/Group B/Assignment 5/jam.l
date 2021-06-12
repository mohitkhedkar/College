%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"

void yyerror(char *);

%}
%%
[\t ]+                    /* ignore whitespace */ ;
is |
am |
are |
were |
was |
be |
being |
been |
do |
does |
did |
will |
would |
should |
can |
could |
has |
have |
had |
go       {  return VERB; }

very |
simply |
gently |
quietly |
calmly |
angrily   {  return ADVERB;}

to |
from |
behind |
above |
between |
below     { return PREPOSITION;}

if |
then |
and |
but |
or       { return CONJUNCTION;}

their |
my |
your |
his |
her |
its      {  return ADJECTIVE;}

I |
you |
he |
she  |
we  |
they       {  return PRONOUN;}


[a-zA-Z]+ { 
             return NOUN;
      }
.|\n        { ECHO;}

%%

int yywrap()
{
	return 1;
}
