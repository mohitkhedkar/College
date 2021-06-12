%{
#include<stdio.h>
#include "y.tab.h" 
%}
%%
int|float|char|boolean {return BUILTIN;}
public|private|protected {return PRIM;} 

"," return COMMA;
";" return SC;
[a-zA-Z]+[a-zA-Z0-9]* {return ID;}
%%
