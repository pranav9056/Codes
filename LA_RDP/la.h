#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
int inp=0;
char token[80][100];
void clearbuff(char s[])
{
    int i=0;
    for (i=0;i<80;i++)
    {
        s[i]='\0';
    }
}
int mainly()
{
        FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7;
        char s[80];
        char id[100][30];
        int cnt=0;
        do
        {
            puts("enter name of file\n");
            gets(s);
            f1=fopen(s,"r");
        }while(f1==NULL);
        f2=fopen("keywords","w");
        f3=fopen("identifiers","w");
        f4=fopen("specialsymbols","w");
        f5=fopen("reloperators","w");
        f6=fopen("operators","w");
        f7=fopen("tokens","w");
        char key[16][20]={"int","char","float","double","void","do","while","for","if","else","switch","FILE","EOF","return","include","NULL"};
        char op[5]={'+','-','*','/','%'};
        char relop[4]={'=','>','<','!'};
        char sym[14]={'(',')','{','}','#',';',':',',','[',']','.','"','\'','$'};
        char c;
        c=getc(f1);
        char buf[80];
        clearbuff(buf);
        int i=0,j,k=0,flag=0;
        while(c!=EOF)
        {
            i=0;
            while(isalnum(c))
            {
                buf[i++]=c;
                c=getc(f1);
            }
            for(j=0;j<16;j++)
            {
                if(strcmp(buf,key[j])==0)
                {
                    flag=1;
                }
            }
            if(flag==1 && c!='"')
            {
                    k=0;
                    putc('<',f7);
                    while(buf[k]!='\0')
                    {
                        putc(buf[k],f7);
                        putc(buf[k],f2);
                        k++;
                    }
                    putc('>',f7);
                    putc('\n',f2);
            }
            else if(c!='.' && c!='(' && c!='>' && c!='"' && c!='\\' && isalpha(buf[0]) && c!=' ' && c!='\'')
            {
                    k=0;
                    for(j=0;j<cnt;j++)
                    {
                        if(strcmp(id[j],buf)==0)
                        flag=1;
                    }
                    if(flag==0)
                    {
                        strcpy(id[cnt++],buf);
                        while(buf[k]!='\0')
                        {
                            putc(buf[k],f3);
                            k++;
                        }
                        putc('\n',f3);
                    }
                    k=0;
                    putc('<',f7);
                   // putc('i',f7);
                   // putc('d',f7);
                    while(buf[k]!='\0')
                    {
                        putc(buf[k],f7);
                        k++;
                    }
                    putc('>',f7);
            }
            else if(isalnum(buf[0]))
            {
                k=0;
                putc('<',f7);
                while(buf[k]!='\0')
                {
                    putc(buf[k],f7);
                    k++;
                }
                putc('>',f7);
            }

            clearbuff(buf);
            flag=0;
            for(j=0;j<14;j++)
            {
                if(c==sym[j])
                {
                    putc('<',f7);
                    putc(c,f4);
                    putc(c,f7);
                    putc('>',f7);
                    putc('\n',f4);
                }
            }
            for(j=0;j<4;j++)
            {
                if(c==relop[j])
                {
                    putc('<',f7);
                    putc(c,f5);
                    putc(c,f7);
                    c=getc(f1);
                    if(c=='=')
                    {
                        putc(c,f5);
                        putc(c,f7);
                    }
                    putc('\n',f5);
                    putc('>',f7);

                }
            }
            for(j=0;j<5;j++)
            {
                if(c==op[j])
                {
                    putc('<',f7);
                    putc(c,f6);
                    putc(c,f7);
                    c=getc(f1);
                    if(c=='+'||c=='-')
                    {
                        putc(c,f6);
                        putc(c,f7);
                    }
                    putc('>',f7);
                    putc('\n',f6);

                }
            }
            if(c=='\n')
            putc('\n',f7);
            c=getc(f1);


        }
        fclose(f1);
        fclose(f2);
        fclose(f3);
        fclose(f4);
        fclose(f5);
        fclose(f6);
        fclose(f7);
        return 0;
}
void tokenlist()
{
    FILE * f1;
    f1=fopen("tokens","r");
    char c;
    char buf[80];
    int k;
    clearbuff(buf);
    do
    {
        c=getc(f1);
        if(c=='<')
        {
            c=getc(f1);
            k=0;
            while(c!='>' || k==0)
            {
                buf[k++]=c;
                c=getc(f1);
            }
            strcpy(token[inp++],buf);
            clearbuff(buf);
        }
    }while(c!=EOF);

}
