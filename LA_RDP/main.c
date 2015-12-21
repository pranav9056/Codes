#include <stdio.h>
#include <stdlib.h>
#include "la.h"
int count=0,a;
int main()
{
    mainly();
    tokenlist();
    /*for(a=0;a<inp;a++)            //to print the list of tokens
        puts(token[a]);*/
    int k=0;
    program();
    if(strcmp(token[count],"$")==0)
        puts("parsing successful");
    else
        puts("parsing unsuccessful");
    return 0;
}
void program()
{
    if(strcmp(token[count],"main")==0)
    {
        count++;
        if(strcmp(token[count],"(")==0)
            count++;
        else
        {
            puts("( expected");
            exit(0);
        }
        if(strcmp(token[count],")")==0)
               count++;
        else
        {
            puts(") expected");
            exit(0);
        }
        if(strcmp(token[count],"{")==0)
               count++;
        else
        {
            puts("{ expected");
            exit(0);
        }
        declration();
        statement_list();
        //insert statement-list here
        if(strcmp(token[count],"}")==0)
               count++;
        else
        {
            puts("} expected");
            exit(0);
        }
    }
    else
    {
        puts("'main' expected");
        exit(0);
    }
}
void declration()
{
    if(data_type())
    {
    	identifier_list();
    	if(strcmp(token[count],";")==0)
         count++;
    	else
		{
      		puts("; expected");
      	    exit(0);
   		}
   		declration();
   	}
   	else
   	{
   		return;
   	}

}
int data_type()
{
    if(strcmp(token[count],"int")==0||strcmp(token[count],"char")==0)
    {
        count++;
        return 1;
    }
    else
    {

        return 0;
    }
}
void identifier_list()
{
	if(isalpha(token[count][0]))
	{
		count++;
		identifier_list1();
	}
	else
	{
		puts("identifier missing");
		exit(0);
	}

}
void identifier_list1()
{
	if(strcmp(token[count],",")==0)
	{
		count++;
		identifier_list();
	}
	else if(strcmp(token[count],"[")==0)
	{
		count++;
		if(isdigit(token[count][0]))
		{
			count++;
		}
		else
		{
			puts("number expected");
			exit(0);
		}
		if(strcmp(token[count],"]")==0)
		{
			count++;

		}
		else
		{
			puts("] expected");
			exit(0);
		}
	}
	else
	{
		return;
	}
}
void statement_list()
{
	if(statement())
	{
		statement_list();
	}
	else
	{

		return;
	}
}
int statement()
{
    if(decision_stat())
    {

    }
    else if(looping_stat())
    {

    }
	else if(assignment_stat())
	{
		if(strcmp(token[count],";")==0)
		{
			count++;
			return 1;
		}
		else
		{
			puts("; expected");
			exit(0);
		}
	}

	else
    {
        return 0;
    }
	//insert looping and decision here	 and add an else to return 0
}
int assignment_stat()
{
	if(isalpha(token[count][0]))
	{
			//	puts(token[count]);

		count++;
		//puts(token[count]);
		if(strcmp(token[count],"=")==0)
		{
			count++;
			expn();
			return 1;
		}
		else
		{
			puts("= missing");
			exit(0);
		}
	}
	else
	{
		return 0;
	}
}
void expn()
{
   // puts(token[count]);
	simple_expn();
	eprime();
}
void simple_expn()
{

	term();
	seprime();
}
void term()
{
	factor();
	tprime();

}
void factor()
{

	if(isalnum(token[count][0]))
	{
		count++;
	}
	else
	{
		puts("identifier/number missing");
		exit(0);
	}
}
void seprime()
{
	if(addop())
	{
		term();
		seprime();
	}
	else
	{
		return;
	}
}
int addop()
{
	if(strcmp(token[count],"+")==0||strcmp(token[count],"-")==0)
	{
		count++;
		return 1;
	}
	else
	return 0;
}
void tprime()
{
	if(mulop())
	{
		factor();
		tprime();
	}
	else
	{
		return;
	}
}
int mulop()
{
	if(strcmp(token[count],"*")==0||strcmp(token[count],"/")==0||strcmp(token[count],"%")==0)
	{
		count++;
		return 1;
	}
	else
	return 0;
}
void eprime()
{
	if(relop())
	{
		simple_expn();
	}
	else
	{
		return;
	}
}
int relop()
{
	if(strcmp(token[count],"==")==0||strcmp(token[count],"!=")==0||strcmp(token[count],"<=")==0||strcmp(token[count],">=")==0||strcmp(token[count],"<")==0||strcmp(token[count],">")==0)
	{
		count++;
		return 1;
	}
	else
	return 0;
}
int decision_stat()
{
    if(strcmp(token[count],"if")==0)
    {
        count++;
        if(strcmp(token[count],"(")==0)
        {
             count++;
             expn();
               //               puts(token[count]);

             if(strcmp(token[count],")")==0)
             {
                 //puts(token[count]);
                 count++;
                 if(strcmp(token[count],"{")==0)
                 {
                        count++;
                        statement_list();
                        if(strcmp(token[count],"}")==0)
                        {
                            count++;
                            dprime();
                            return 1;
                        }
                        else
                        {
                            puts("} expected");
                            exit(0);
                        }
                 }
                else
                {
                    puts("{ expected");
                    exit(0);
                }
            }
            else
             {

                    puts(token[count]);
                 puts(") expected");
                 exit(0);
             }
        }
        else
        {
            puts("( expected");
            exit(0);
        }


    }
    else
    {
        return 0;
    }
}
void dprime()
{
     if(strcmp(token[count],"else")==0)
     {
        count++;
        if(strcmp(token[count],"{")==0)
        {
            count++;
            statement_list();
            if(strcmp(token[count],"}")==0)
            {
                count++;
            }
            else
            {
                puts("} expected");
                exit(0);
            }
        }
        else
        {
            puts("{ expected");
            exit(0);
        }

     }
     else
     {
         return;
     }
}
int looping_stat()
{
    if(strcmp(token[count],"while")==0)
    {
        count++;
        if(strcmp(token[count],"(")==0)
        {
            count++;
            expn();
            if(strcmp(token[count],")")==0)
            {
                count++;
                if(strcmp(token[count],"{")==0)
                {
                    count++;
                    statement_list();
                     if(strcmp(token[count],"}")==0)
                     {
                        count++;
                        return 1;
                     }
                      else
                     {
                        puts("} expected");
                        exit(0);
                     }
                }
                else
                {
                    puts("{ expected");
                    exit(0);
                }
            }
            else
            {
                puts(") expected");
                exit(0);
            }
        }
        else
        {
            puts("( expected");
            exit(0);
        }
    }
    else if(strcmp(token[count],"for")==0)
    {
        count++;
        if(strcmp(token[count],"(")==0)
        {
            count++;
            assignment_stat();
            if(strcmp(token[count],";")==0)
            {
                count++;
                expn();
                if(strcmp(token[count],";")==0)
                {
                    count++;
                    assignment_stat();
                    if(strcmp(token[count],")")==0)
                    {
                        count++;
                        if(strcmp(token[count],"{")==0)
                        {
                            count++;
                            statement_list();
                            if(strcmp(token[count],"}")==0)
                            {
                                count++;
                                return 1;
                            }
                            else
                            {
                                puts("} expected");
                                exit(0);
                            }

                         }
                        else
                        {
                            puts("{ expected");
                            exit(0);
                        }
                    }
                    else
                    {
                        puts(") expected");
                        exit(0);
                    }
                }
                else
                {
                    puts("; expected");
                    exit(0);
                }
            }
            else
            {
                puts("; expected");
                exit(0);
            }
        }
        else
        {
            puts("( expected");
            exit(0);
        }
    }

    else
    {
        return 0;
    }

}
















