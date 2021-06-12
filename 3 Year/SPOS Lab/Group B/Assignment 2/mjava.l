
%{
int key=0,id=0,pun=0,fun=0,dir=0,s=0,opt=0,var=0,digit=0;
%}

%%
"import java.io.*;" {printf("\n\t %s is a preprocessor directives",yytext);}

System.out.println|main {printf("\n\t system function:=%s",yytext);}

\"([%]*[A-Z a-z 0-9]+)*\" {printf("\n\t word is a:= %s",yytext);}

[;|,] {printf("\n\t punctuation is a:=%s",yytext);}

(([A-Z]+)*([a-z])+)*[(][)] {printf("\n\t function is a:=%s",yytext);}

if|else|while|do|for|until|elseif|char|void|int|float|string|boolean|long {printf("\n\t keyword is a:=%s",yytext);}

[a-z|A-Z]+ {printf("\n\t variable is a:=%s",yytext);}

[{|}|(|)] {printf("\n\t symbol or bracket is a:=%s",yytext);}

[0-9] {printf("\n\tDigit is a:=%s",yytext);}

[+|-|*|=|<|>|&|%] {printf("\n\t operator is a:=%s",yytext);}
%%

int main(int argc,char* argv[50])
{
FILE *fp;
fp=fopen(argv[1],"r");
yyin=fp;
yylex();
}
int yywrap()
{
return 1;
}


