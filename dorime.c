#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]){
	
	int input;
	int a,b;
	int flagger =0; 
	int tyu = 0;
	int parsetreenodes[1] = {0};
    int astnodes[1] = {0};

	if(argc != 3){
		printf("Please enter according to the correct format\n");
		return 0;
	}
	printf("\nLevel 4: All Modules \n\tAbstract Syntax Tree\n\tsymboltable\n\tsemantic checking\n\ttypechecking\n\tcode generation\n\tSUCCESSFULLY IMPLEMENTED\n\n");
	printf("\n1 : for printing the token list \n2 : for parsing to verify the syntactic correctness of the input source code and produce parse tree on console\n3 : for creating the abstract syntax tree and printing it on console\n4 : for displaying the amount of allocated memory and number of nodes to each of parse tree and abstract syntax tree\n5 : for printing the Symbol Table\n6 : Type Checking and Semantic Verification\n7 : Code Generation\n0 : Exit\n\n");
	
	FILE* fp1 = fopen(argv[1],"a");
	FILE* fp2 = fopen(argv[2],"w");

    //  ./compiler testcase1.txt code.asm

	FILE *semantic = fopen("Type&SemanticErrors.txt", "w+");

	if(fp1==NULL)
    {
        printf("File not found\n");
        return 0;
    }
    if(fp2==NULL)
    {
        printf("File not found\n");
        return 0;
    }

	fprintf(fp1,"%s","\r\n$");
	fclose(fp1);
	createsymboltable();
	FILE* fp = fopen(argv[1], "r");
	int symcount = 0;
	parsetree head = NULL;

		scanf("%d", &input);

	do{

			if(input==1){
					rewind(fp);
					fseek( fp, 0, SEEK_SET);
					fp = getstream(fp);
				    
					node* Lex = getNextToken();					//Call method in lexer
				    int i = 1;
				    int j = 0;
					while(strcmp(Lex->tk->value,"$")!=0){
						if(strcmp(Lex->tk->token,"ERROR") == 0){
							j++;
						}else{
				        	printf("%d. token = %s, value = %s, line = %d\n", i++,Lex->tk->token, Lex->tk->value, Lex->tk->line);	//print tokens to console
				   		}
				        free(Lex);
				        node* Lex = getNextToken();
				    }
				    printf("\nTotal Tokens :- %d\n",i+j);
				    printf("Valid Tokens Found:- %d\n",i);
				    printf("Error Found:- %d\n",j);
			}