%{
extern int yylex();
int yyerror(char *s) {printf("Error: %s\n", s); return(0);}
%}

%token tk_function
%token tk_variable
%token tk_real
%token tk_newConstraint
%left '+' '-' '*' '/' '(' ')' '='

%%
input:   constraints;

problem: tk_model ':' model ';' tk_data ':' list ';'
    {
        Node noeud(QString("prb"),$3.number,$7.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    };

list: data
    {
        Node noeud(QString("list"),$1.number,-1,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       data ',' list
    {
        Node noeud(QString("list"),$1.number,$3.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    };

data: '(' expr_r ',' interval ')'
    {
        Node noeud(QString("data"),$2.number,$4.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    };

interval: '[' expr_r ',' expr_r ']'
    {
        Node noeud(QString("interval"),$2.number,$4.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    };

expr_r : tk_real
    {
        Node noeud($1.name,-1,-1,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    };

model : expr
    {
        Node noeud(QString("model"),$1.number,-1,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud)
    };

expr:    tk_variable
    {
        Node noeud($1.name,-1,-1,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       tk_real
    {
        Node noeud($1.name,-1,-1,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       expr '+' expr
    {
        Node noeud(QString("+"),$1.number,$3.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       expr '-' expr
    {
        Node noeud(QString("-"),$1.number,$3.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       expr '*' expr
    {
        Node noeud(QString("*"),$1.number,$3.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       expr '/' expr
    {
        Node noeud(QString("/"),$1.number,$3.number,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       tk_function '(' expr ')'
    {
        Node noeud($1.name,$3.number,-1,syntax_tree.size());
        $$.number=syntax_tree.size();
        syntax_tree.push_back(noeud);
    }
    |       '(' expr ')'
;

%%
