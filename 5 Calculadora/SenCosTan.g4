grammar SenCosTan;

//grammar
prog: stat+;

stat: expr NEWLINE                #print
    | ID '=' expr NEWLINE         #assign
    | NEWLINE                     #blank
    ;

expr: expr op=('*'|'/') expr      #MulDiv
    | expr op=('+'|'-') expr      #AddSub
    | SIN '(' expr ')'            #Sin
    | COS '(' expr ')'            #Cos
    | TAN '(' expr ')'            #Tan
    | INT                         #int
    | 'pi'                          #pi
    | FLOAT                       #float
    | ID                          #id
    | '(' expr ')'                #parens
    ;
  
  
//lex
MUL    :  '*';
ADD    :  '+';
DIV    :  '/';
SUB    :  '-';
SIN: 'Sin';
COS: 'Cos';
TAN: 'Tan';
ID     :  [a-zA-Z]+;
INT    :  [0-9]+;
FLOAT  :  [0-9]+ '.'[0-9]+;
NEWLINE:  '\r'?'\n';
WS     :  [\t]+ -> skip;
