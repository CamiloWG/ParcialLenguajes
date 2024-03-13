%option noyywrap

%{
#include <stdio.h>

int lambda_def_found = 0;
int lambda_arg = 0;
int lambda_call_found = 0;
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*[ \t]*=[ \t]*lambda           { lambda_def_found = 1; }

:[ \t]*[a-zA-Z_][a-zA-Z0-9_]*\s*                    { if(lambda_def_found) lambda_arg = 1; }

print\(\s*[a-zA-Z_][a-zA-Z0-9_]*\s*\(.+\)\s*\)      { lambda_call_found = 1; }

\n                                                                      {  }
.                                                                       {  }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <archivo de entrada>\n", argv[0]);
        return 1;
    }

    FILE *myfile = fopen(argv[1], "r");
    if (!myfile) {
        perror("Error al abrir el archivo");
        return 1;
    }

    yyin = myfile;

    yylex();

    fclose(myfile);

    if (lambda_def_found && lambda_call_found && lambda_arg) {
        printf("ACEPTA\n");
    } else {
        printf("NO ACEPTA\n");
    }

    return 0;
}
