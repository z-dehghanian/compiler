#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;
//function declare
void id_num(void);
void error_attribute(void);
bool searchm( char *a,int l);
void syntax(void);
void keyword(void);
void expression(void);
void variableint(void);
void error_attribute(void);
void variableif(void);
void parantesess_baste(void);
void punc(void);
void  parantesess_baz(void);
int searchtable( char *s);
void tokenize (char token[]);
void idDictation  (char token[]);
void number (char token[]);
void file (void);
int searchm( char *s);
void findsharpe(void);
void warning(void);
void return_int(void);
void changeToIR(void);
int searchNum( char *s);
void number_print(int a);
void l_recognize(void);
void IR(void);
void if_ir(void);
// tables
typedef struct word{
    int line ;
    char attribute[50];
    char token[15];
    char ir[50];

}word;

typedef struct symbol{
    char attribute[50];
    char type[10];
    char value[2];
    int warning;
    int id;
}symbol;

typedef struct numberTable{
    char number[20];
    int index ;
}numberTable;


word wordm[1000];
symbol symbolm[1000];
numberTable numberTablem[1000];
char error[50];
int line = 0;
int i=0,j=0,n=0,idcounter=0,include_counter=0;
int main_flag=0,z,o=0,v=0,flag_int=0,error_counter=0,flag_build=0,w,intmain_flag=0,if_flag=0,lcounter=1,while_flag=0,syntax_flag=0,flag_ir=0;
FILE *fp;
int main()
{
    if(syntax_flag==0){
  findsharpe();
    file();
    z=i-1;
    i=0;
    while(wordm[i].line<=include_counter)
        i++;
    syntax();}//z tedadie ke toosh arraye ye word por shode!!
       // if (error_counter==0){
     else if (error_counter==0){
            fp=fopen("IR.txt","a");
            z=i;
        i=0;
        changeToIR();
        i=0;
        IR();
    error_counter=1; }
    //}
    return 0;
}
///////////////////////////// include

void findsharpe(void){
char c[50],includeword[1000];
FILE *fp,*fp2,*include;
int i,m;
fp=fopen("text.txt","r");
fp2=fopen("textasli.txt","w+");//check!!!!
fscanf(fp,"%s",c);
int neshane=1;
while(!strcmp(c,"#include"))
            {
                fscanf(fp,"%s",c);
                i=1;
                while(c[i]!=NULL){
                    c[i-1]=c[i];
                    i++;
                }

                c[i-2]=c[i];
                include=fopen(c,"r");
                    while(true){
                        char a;
                        fscanf(include,"%c",&a);
                        if(!feof(include))
                            fprintf(fp2,"%c",a);
                        else
                            break;
                    }
                    fscanf(fp,"%s",c);
                    fprintf(fp2,"%c",10);
                }
                if(!feof(fp))
                           fprintf(fp2,c);
                else
                           neshane=0;


                  while(neshane==1){
                        char a;
                        fscanf(fp,"%c",&a);
                        if(!feof(fp))
                            fprintf(fp2,"%c",a);
                        else
                            break;
                  }
        fclose(fp2);
        fclose(fp);

}

//////////////////////////////////////token
void file (void){
    char stringm[201];
    FILE *fp;
    int p,b=0;
    char *pos;
    fp=fopen("textasli.txt","r");
    if (fp == NULL)
		exit;
    else{
    while(!feof(fp)){

        fgets(stringm,200,fp);
        line++;
        // remove /n
        if ((pos=strchr(stringm, '\n')) != NULL)
            *pos = '\0';
        p=0;
        while(stringm[p]!= '\0'){
            char token[20];
            while(stringm[p]==9 || stringm[p]==32)
                p++;
            b=0;
            while(stringm[p]!=32 && stringm[p]!='\0' && stringm[p]!=9 ){
            token[b]=stringm[p];
            p++;
            b++;
            }
            token[b]=NULL;
            tokenize(token);
        }
    }

}
}

void tokenize (char token[]){
    int s,c=0;
    strcpy(wordm[i].attribute,token);
    // keyword
    if(strcmp(wordm[i].attribute,"if")== 0 || strcmp(wordm[i].attribute,"main")==0 || strcmp(wordm[i].attribute,"else")==0 || strcmp(wordm[i].attribute,"int")==0 || strcmp(wordm[i].attribute,"char")==0 || strcmp(wordm[i].attribute,"bool")==0 || strcmp(wordm[i].attribute,"void")==0 || strcmp(wordm[i].attribute,"NULL")==0 || strcmp(wordm[i].attribute,"float")==0 || (strcmp(wordm[i].attribute,"return")==0) || strcmp(wordm[i].attribute,"while")==0 ){
        strcpy(wordm[i].token,"keyword");
        wordm[i].line=line;
    }
    //operator
    else if (strcmp(wordm[i].attribute,"+")==0 || strcmp(wordm[i].attribute,"=")==0 || strcmp(wordm[i].attribute,"-")==0 || strcmp(wordm[i].attribute,"*")==0 || strcmp(wordm[i].attribute,"/")==0 || strcmp(wordm[i].attribute,"==")==0 || strcmp(wordm[i].attribute,">")==0 || strcmp(wordm[i].attribute,"<")==0 || strcmp(wordm[i].attribute,"!=")==0 || strcmp(wordm[i].attribute,"&&")==0 || strcmp(wordm[i].attribute,"||")==0 || strcmp(wordm[i].attribute,">=")==0 || strcmp(wordm[i].attribute,"=<")==0){
        strcpy(wordm[i].token,"operator");
        wordm[i].line=line;
    }
    //punctuation
    else if (strcmp(wordm[i].attribute,"(")==0 || strcmp(wordm[i].attribute,")")==0 || strcmp(wordm[i].attribute,"{")==0 || strcmp(wordm[i].attribute,"}")==0 || strcmp(wordm[i].attribute,";")==0 || strcmp(wordm[i].attribute,",")==0){
        strcpy(wordm[i].token,"punctuation");
        wordm[i].line=line;
    }
    else if (strcmp(wordm[i].attribute,"true")==0 || strcmp(wordm[i].attribute,"false")==0){
        strcpy(wordm[i].token,"bool");
        wordm[i].line=line;
    }
    // charachter
    else if (wordm[i].attribute[0]==39){
            int s ;
        if (wordm[i].attribute[2]==39){
            wordm[i].attribute[0]=wordm[i].attribute[1];
            wordm[i].attribute[1]=NULL;
            strcpy(wordm[i].token,"char");
            wordm[i].line=line;
            s=searchNum(wordm[i].attribute);
            if(s!=1){
            strcpy(numberTablem[n].number,wordm[i].attribute);
            numberTablem[n].index=n;
            n++;
        }
        }

        else{
            strcpy(wordm[i].token,"error");
            wordm[i].line=line;
            }
    }
    // number
    else if (48<=wordm[i].attribute[0] && wordm[i].attribute[0]<=57){
            number(wordm[i].attribute);
    }

    else if (wordm[i].attribute[0]== 45 || wordm[i].attribute[0]==43){
            number(wordm[i].attribute);
    }

    else if (65<=wordm[i].attribute[0] && wordm[i].attribute[0]<=90 || 97<=wordm[i].attribute[0] && wordm[i].attribute[0]<=122) {
        idDictation(wordm[i].attribute);
    }

    i++;
}


void number (char token[]){
    strcpy(wordm[i].attribute,token);
    int counter=1,ashar=0;
    int s ;
    s=searchNum(wordm[i].attribute);
    while(wordm[i].attribute[counter]!=NULL){

        if (wordm[i].attribute[counter]<48  ||  wordm[i].attribute[counter]>57 ){

            if(wordm[i].attribute[counter] == 46 && (48<=wordm[i].attribute[counter+1] && wordm[i].attribute[counter+1] <= 57) )
                ashar++;
            else{
                ashar=2;
            }
        }
        counter++;
    }
        if(ashar==1){
            strcpy(wordm[i].token,"float");
            wordm[i].line=line;
            if(s!=1){
            strcpy(numberTablem[n].number,wordm[i].attribute);
            numberTablem[n].index=n;
            n++;
            }
        }
        else if(ashar==0){
            strcpy(wordm[i].token,"int");
            wordm[i].line=line;
            if(s!=1){
            strcpy(numberTablem[n].number,wordm[i].attribute);
            numberTablem[n].index=n;
            n++;

            }

        }
        else if (ashar==2){
            strcpy(wordm[i].token,"error");
            wordm[i].line=line;
        }
}

void idDictation  (char token[]){
    strcpy(wordm[i].attribute,token);
    int s,temp=0;
    s=searchm(wordm[i].attribute);
    int c=0;
    if(s!=1){
        while(wordm[i].attribute[c]!= NULL){

            if( (wordm[i].attribute[c]<48) || (wordm[i].attribute[c]>57 && wordm[i].attribute[c]<=64) || ((90<wordm[i].attribute[c]) && (wordm[i].attribute[c]<97)) || 122<wordm[i].attribute[c] ){
            temp = 1 ;
            wordm[i].line=line;
            strcpy(wordm[i].token,"error");
            }
            c++;
        }
        if(temp==0){
        if(strcmp(wordm[i-1].attribute,"int")==0 || strcmp(wordm[i-1].attribute,"char")==0 || strcmp(wordm[i-1].attribute,"float")==0 || strcmp(wordm[i-1].attribute,"bool")==0){
            strcpy(wordm[i].token,"identifier");
            wordm[i].line=line;
            strcpy(symbolm[j].attribute,wordm[i].attribute);
            idcounter++;
            symbolm[j].id = idcounter ;symbolm[j].warning =1;
            strcpy(symbolm[j].type,wordm[i-1].attribute);
            j++;
            }
        else{
            if(strcmp(wordm[i-1].attribute,",")==0){
                strcpy(wordm[i].token,"identifier");
                wordm[i].line=line;
                strcpy(symbolm[j].attribute,wordm[i].attribute);
                idcounter++;
                symbolm[j].id = idcounter ;
                strcpy(symbolm[j].type,wordm[i-1].attribute);
                j++;
               }
            else{
                strcpy(wordm[i].token,"error");
                wordm[i].line=line;
            }
        }
    }
    }
        else{
            if(strcmp(wordm[i-1].attribute,"int")==0 || strcmp(wordm[i-1].attribute,"char")==0 || strcmp(wordm[i-1].attribute,"float")==0 || strcmp(wordm[i-1].attribute,"bool")==0){
                strcpy(wordm[i].token,"error2");
                wordm[i].line=line;
            }
            else
            strcpy(wordm[i].token,"identifier");
            wordm[i].line=line;
        }
}






//////////////////////////////////////////////////////////////////////////// syntax

 void  syntax(void){
    while(i<=z)
    {
     if(main_flag==1){
        if(!strcmp(wordm[i].token,"keyword"))
            keyword();
        else if(!strcmp(wordm[i].token,"identifier"))
            expression();
        else if(!strcmp(wordm[i].attribute,"}"))
        {
            v--;
            i++;
            if(if_flag==1 && !strcmp(wordm[i].attribute,"else"))if_flag++;
            syntax();
            }
        else if(!strcmp(wordm[i].token,"error"))
        {
             strcpy(error,"not defined");
             error_attribute();
        }
        else i++;
    }

    else if(!strcmp(wordm[i].token,"keyword")  || ( (!strcmp(wordm[i].attribute,"int")) || (!strcmp(wordm[i].attribute,"char"))  || (!strcmp(wordm[i].attribute,"bool"))  || (!strcmp(wordm[i].attribute,"float"))))
            keyword();
    else if (!strcmp(wordm[i].attribute,"}")){v--;i++;syntax();}
    else if (!strcmp(wordm[i].attribute," ") )i++;
    else
        {
           strcpy(error,"keyword");
            error_attribute();
            i++;
        }
 }
 if(i>z)
 {  if(!strcmp(wordm[i].attribute,"}"))v--;
     if(v<=0)
     { if(flag_build==0) {return_int();warning();
        if(error_counter>0){cout<<"=== BUILD FAILED: "<<error_counter<<" error(s) " ;}
        else {cout<<"=== RUN === : "<<error_counter<<" error " ;}
        flag_build++;}
        syntax_flag=1;
        main();
     }
     else
        {   v--;
            strcpy(error,"braces");
             error_attribute();
        }
 }
 }
void keyword(void){
    if(!strcmp(wordm[i].attribute,"void")){
            i++;
            if(!strcmp(wordm[i].attribute,"main")){
                main_flag=1;
                keyword();}
                else {
                    strcpy(error,"main");
                    error_attribute();
                }}

        if(!strcmp(wordm[i].attribute,"return")){
            i++;intmain_flag=intmain_flag+10;main_flag++;
            if(intmain_flag==11){
            if((!strcmp(wordm[i].token,"float"))||(!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char"))  || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
            {
                i++;
                if(strcmp(wordm[i].attribute,";")==0){
                        i++;
                    if(v==1){
                    if(!strcmp(wordm[i].attribute,"}")){
                        i++;
                        v--;
                        return ;
                    }
                }
                    else
                    {   strcpy(error,"braces");
                        error_attribute();
                    }

        }
        else {
        strcpy(error,";");
        error_attribute();
        }
            }
            else
                {   strcpy(error,"number");
                    error_attribute();
            }}

            else if (main_flag==2 )
                {
                    if(strcmp(wordm[i].attribute,";")==0){
                        i++;
                    if(v==1){
                    if(!strcmp(wordm[i].attribute,"}")){
                        i++;
                        v--;
                        return;
                    }
                }
                    else
                    {   strcpy(error,"braces");
                        error_attribute();
                    }

        }
        else {
        strcpy(error,";");
        error_attribute();
        }
            }
            else
                {   strcpy(error,"number");
                    error_attribute();
            }
        }
        if(!strcmp(wordm[i].attribute,"int")){
            i++;
            if(!strcmp(wordm[i].attribute,"main")){
                main_flag=1;intmain_flag++;
                keyword();}
            else if(!strcmp(wordm[i].token,"identifier"))
                {

                 variableint();
                }
            else
                {
                  strcpy(error,"identifier");
                  error_attribute();
                }
        }
       if( (!strcmp(wordm[i].attribute,"char"))  || (!strcmp(wordm[i].attribute,"bool")) || (!strcmp(wordm[i].attribute,"float"))){
                                                i++;
                                                variableint();

                                                }
       else if(!strcmp(wordm[i].attribute,"if") || (strcmp(wordm[i].attribute,"while")==0))
               {  i++;if_flag=1;
               if(!strcmp(wordm[i].attribute,"("))
                {    i++;
                  variableif();
                }
                else
                {   strcpy(error,"(");
                    error_attribute();
                }
               }
       else if(!strcmp(wordm[i].attribute,"else"))
       {
       if(if_flag%2==0){
           i++;
           if(!strcmp(wordm[i].attribute,"{"))
           {    i++;
                v++;
               syntax();
           }
           else{
            strcpy(error,"{");
            error_attribute();
           }
       }
        else
        {   if_flag--;
            strcpy(error," previous else ");
            error_attribute();
        }}
       else if(!strcmp(wordm[i].attribute,"main")){
              i++;
              if(!strcmp(wordm[i].attribute,"(")){
                 i++;
                 if(!strcmp(wordm[i].attribute,")")){
                    i++;
                    if(!strcmp(wordm[i].attribute,"{")){
                       i++;
                       v++;
                       syntax();
                       }
                       else
                        {   strcpy(error,"{");
                            error_attribute();
                        }
                    }
                     else
                        {   strcpy(error,")");
                            error_attribute();
                        }
               }
                else
                        {   strcpy(error,"(");
                            error_attribute();
                        }
           }
}

void variableint(void){
if(!strcmp(wordm[i].token,"identifier")){
    i++;
    if(!strcmp(wordm[i].attribute,",")){
            i++;
            variableint();
    }
    else if(!strcmp(wordm[i].attribute,"=")){
            i++;
            /// yademoon bashe bayad baraye semantic avazeshoon konim
            if((!strcmp(wordm[i].token,"float")) ||(!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char")) || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
                {   w=searchtable(wordm[i].attribute);
                    symbolm[w].warning=0;
                    i++;
                    if(!strcmp(wordm[i].attribute,";")){
                        w=searchtable(wordm[i-3].attribute);
                    strcpy(symbolm[w].value , wordm[i-1].attribute);

                        i++;
                        syntax();
                    }
                    else if((!strcmp(wordm[i].attribute,"+"))  || (!strcmp(wordm[i].attribute,"-")) ||(!strcmp(wordm[i].attribute,"*"))  || (!strcmp(wordm[i].attribute,"/"))){
                        i=i-3;
                        flag_int=1;
                        expression();
                    }
                    else
                   {
                      strcpy(error,"punctuation");
                      error_attribute();
                   }

            }
            else if(!strcmp(wordm[i].attribute,"("))
                    {
                        if(!strcmp(wordm[i+2].attribute,")"))
                           {
                              w=searchtable(wordm[i-2].attribute);
                              strcpy(symbolm[w].value , wordm[i-2].attribute);
                           }
                           else
                           {   o++;
                               i=i-2;
                               flag_int=1;
                               expression();
                           }
                    }
            else
                {
                    strcpy(error,"value for identifier");
                    error_attribute();
                }
    }
    else if(!strcmp(wordm[i].attribute,";")){
            i++;
            syntax();
    }
    else
        {
            strcpy(error,";");
                    error_attribute();

        }
}
 else{
        strcpy(error,"identifier");
        error_attribute();
          }
}


void variableif(void){
     if((!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char"))  || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
     {
         if(!strcmp(wordm[i].token,"identifier")){
        w=searchtable(wordm[i].attribute);
        symbolm[w].warning=0;}
        i++;
        if((!strcmp(wordm[i].attribute,"&&"))||(!strcmp(wordm[i].attribute,"||"))||(!strcmp(wordm[i].attribute,"=="))  ||  (!strcmp(wordm[i].attribute,">="))  || (!strcmp(wordm[i].attribute,"<=")) ||(!strcmp(wordm[i].attribute,"!="))  ||(!strcmp(wordm[i].attribute,">"))  ||(!strcmp(wordm[i].attribute,"<")))
        {
                i++;
                if((!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char"))  || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
                {
                    if(!strcmp(wordm[i].token,"identifier")){
                    w=searchtable(wordm[i].attribute);
                    symbolm[w].warning=0;}
                    i++;
                     if((!strcmp(wordm[i].attribute,"&&")) || (!strcmp(wordm[i].attribute,"||"))) {
                        i++;
                        variableif();
                     }
                     else if(!strcmp(wordm[i].attribute,")"))
                     {
                         i++;
                         if(!strcmp(wordm[i].attribute,"{"))
                            {
                                i++;
                                v++;
                                syntax();

                            }
                        else
                        {
                            strcpy(error,"{");
                            error_attribute();
                        }
                     }
                    else
                    {
                        strcpy(error,")");
                        error_attribute();
                    }

                }
                else
                {
                    strcpy(error,"value after punctuation");
                    error_attribute();
                }
        }

    else
    {
        strcpy(error,"punctuation");
        error_attribute();
    }

     }
else
{
    strcpy(error,"a value");
    error_attribute();
}
}

void expression(void)
{
 o=0;
    if(!strcmp(wordm[i].token,"identifier"))
    {   if(flag_int==0)
       {
        w=searchtable(wordm[i].attribute);
        symbolm[w].warning=0;}
        i++;
        if(!strcmp(wordm[i].attribute,"="))
        {
            i++;
            if((!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char"))  || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
            {   if(!strcmp(wordm[i].token,"identifier")){
                w=searchtable(wordm[i].attribute);
                symbolm[w].warning=0;}i++;
                id_num();
            }
            else if(!strcmp(wordm[i].attribute,"(") )
                    {
                        i++;
                        o++;
                        parantesess_baz();
                    }
            else
            {
                strcpy(error,"identifier or number");
                error_attribute();
            }
        }
        else
            {
                strcpy(error,"=");
                error_attribute();
            }

    }
    else
    {
        strcpy(error,"identifier");
        error_attribute();
    }
}
void id_num(void){

 if((!strcmp(wordm[i].attribute,"+")) || (!strcmp(wordm[i].attribute,"-")) ||(!strcmp(wordm[i].attribute,"*")) ||(!strcmp(wordm[i].attribute,"/")))
 {   i++;
     punc();
 }

else if(!strcmp(wordm[i].attribute,")") ){
        if (o>0){
            o--;
            i++;
            parantesess_baste();
        }
        else {
             strcpy(error,"( or ;");
             error_attribute();
        }
}
else if(!strcmp(wordm[i].attribute,";"))
        {
            if(o==0)
            {
              i++;
              syntax();
            }
            else
            {

              strcpy(error,"parantesses");
              error_attribute();
            }
        }
        else if(flag_int==1)
        { if (!strcmp(wordm[i].attribute,","));
                {
                    i++;
                    variableint();
                }
        }
        else if(o==0) {
            strcpy(error,";");
             error_attribute();
        }
        else {
            strcpy(error,"parentesses");
             error_attribute();
        }


}

void  parantesess_baz(void)
{
    if( !strcmp(wordm[i].attribute,"("))
        {
            o++;
            i++;
            parantesess_baz();
        }
        else if((!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char"))  || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
        {   if(!strcmp(wordm[i].token,"identifier")){
        w=searchtable(wordm[i].attribute);
        symbolm[w].warning=0;}
            i++;
            id_num();
        }
        else
            {
            strcpy(error,"a value after parantesess");
            error_attribute();
            }
}


void parantesess_baste(void){
    if( !strcmp(wordm[i].attribute,")"))
        {
            i++;
            o--;
             parantesess_baste();

        }

    else if((!strcmp(wordm[i].attribute,"+")) || (!strcmp(wordm[i].attribute,"-")) ||(!strcmp(wordm[i].attribute,"*")) ||(!strcmp(wordm[i].attribute,"/")))
    {
        i++;
        punc();
    }
    else if (flag_int==1)
    {
        if(!strcmp(wordm[i].attribute,",")){
           if(o==0)
            {
              i++;
              variableint();
            }
            else
            {

              strcpy(error,"parantesess");
              error_attribute();
            }
        }

   else if(!strcmp(wordm[i].attribute,";"))
   {
       if(o==0)
            {
              i++;
              syntax();
            }
            else
            {

              strcpy(error,"parantesess");
              error_attribute();
            }
   }}

}

void punc(void){
  if((!strcmp(wordm[i].token,"int")) || (!strcmp(wordm[i].token,"char"))  || (!strcmp(wordm[i].token,"bool")) || (!strcmp(wordm[i].token,"identifier")))
  {   if(!strcmp(wordm[i].token,"identifier")){
        w=searchtable(wordm[i].attribute);
        symbolm[w].warning=0;}
      i++;
      id_num();
  }
  else if( !strcmp(wordm[i].attribute,"("))
        {
            o++;
            i++;
            parantesess_baz();
        }
  else
  {
      strcpy(error,"value after puncctuation");
      error_attribute();
  }

}
int oskol;
void error_attribute(void){
oskol=i;
int p=0;
error_counter++;
if(!strcmp(wordm[i].token,"error")){
    cout<<" in line "<<wordm[i].line<<"  "<<wordm[i].attribute<<" does not name a type "<<endl;
}
else if(!strcmp(wordm[i].token,"error2"))
    cout<<" in line "<<wordm[i].line<<" redifinition of "<<wordm[i].attribute<<endl;
else{
while(wordm[oskol].line==0){wordm[oskol].line=wordm[i].line;oskol--;}
cout<<" in line "<<wordm[oskol].line<<"  expected to see  "<<error<<" after "<<wordm[i-1].attribute<<"  but also see  "<<wordm[i].attribute<<endl;}
if(i>z)return ;

    while(p!=1  && i<z && v!=0 )
    {
        if(!strcmp(wordm[i].attribute,"{"))v++;
        if(!strcmp(wordm[i].attribute,"}"))v--;
        if(!strcmp(wordm[i].attribute,";"))p=1;
        if(!strcmp(wordm[i].attribute,"main"))main_flag=1;
        if(!strcmp(wordm[i].attribute,"return")){if((!strcmp(wordm[i+1].token,"int")) || (!strcmp(wordm[i+1].token,"float")) || (!strcmp(wordm[i+1].token,"bool"))  ||(!strcmp(wordm[i+1].token,"char")) ||(!strcmp(wordm[i+1].token,"identifier")))intmain_flag=intmain_flag+10;
        main_flag++;}
        i++;
    }
    if ( v ==0 && i<z-5)
    {

    while(p!=1  && i<z  )
    {
        if(!strcmp(wordm[i].attribute,"{"))v++;
        if(!strcmp(wordm[i].attribute,"}"))v--;
        if(!strcmp(wordm[i].attribute,";"))p=1;
        if(!strcmp(wordm[i].attribute,"main"))main_flag=1;
        if(!strcmp(wordm[i].attribute,"return")){if((!strcmp(wordm[i+1].token,"int")) || (!strcmp(wordm[i+1].token,"float")) || (!strcmp(wordm[i+1].token,"bool"))  ||(!strcmp(wordm[i+1].token,"char")) ||(!strcmp(wordm[i+1].token,"identifier")))intmain_flag=intmain_flag+10;
        main_flag++;}
        i++;
    }

    }
    else if (v==0 && i<=z){i++;}
syntax();

}


 void warning (void){
 int x=0;
 while(x<idcounter)
 {
     if(symbolm[x].warning==1)cout<<"warning : "<<symbolm[x].attribute<<" was not used "<<endl;x++;
 }

 }

void return_int ( void )
{

    if( intmain_flag==11)return;
    else if(main_flag==2 )return;
    else if(intmain_flag==10 && main_flag==2)cout<<"you can not return a value in void function"<<endl;
    else if(intmain_flag==1 && main_flag==1)cout<<"you just forgot to write return"<<endl;
    else if(intmain_flag==0 && main_flag==1)cout<<"you just forgot to write return"<<endl;
    else if(intmain_flag>11 || main_flag>2)cout<<"you write more than 1 main/return"<<endl;
    error_counter++;
    if(intmain_flag==0 && main_flag==0)error_counter--;



}
//////////////////////////////////// search

 int searchtable( char *s){
    bool qw=1;
    for(int d=0;d<=1000;d++){
        qw=strcmp(symbolm[d].attribute,s);
        if(qw==0)
            return d ;
    }
 }

int searchm( char *s){
    bool qw=1;
    for(int i=0;i<=1000;i++){
        qw=strcmp(symbolm[i].attribute,s);
        if(qw==0)
            return 1;
    }
 }

 int searchNum( char *s){
     bool qw=1;
    for(int i=0;i<=1000;i++){
        qw=strcmp(numberTablem[i].number,s);
        if(qw==0)
            return 1;
    }
 }


int searchnum( char *s){
    bool qw=1;
    for(int k=0;k<=1000;k++){
        qw=strcmp(numberTablem[k].number,s);
        if(qw==0)
            return k;
    }
 }

/////////////////////////////////////////////////////////////////////// IR


void changeToIR(void){
    int index;
    while(i<=z)
    {
        if(strcmp(wordm[i].attribute,"{")==0 || strcmp(wordm[i].attribute,"}")==0 || strcmp(wordm[i].attribute,";")==0 )
            {
                strcpy(wordm[i].ir,"\n");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"main")==0)
                {
                strcpy(wordm[i].ir,"PROCEDURE MAIN \n BEGIN \n");
                i++;

            }
            else if(strcmp(wordm[i].attribute,"true")==0){
                strcpy(wordm[i].ir,"TRUE");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"false")==0){
                strcpy(wordm[i].ir,"FALSE");
                i++;

            }
            else if(strcmp(wordm[i].attribute,"=")==0){
                strcpy(wordm[i].ir,":=");
                i++;

            }
            else if(strcmp(wordm[i].attribute,"+")==0){
                strcpy(wordm[i].ir," + ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"-")==0){
                strcpy(wordm[i].ir," - ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"*")==0){
                strcpy(wordm[i].ir," * ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"/")==0){
                strcpy(wordm[i].ir," / ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,">")==0){
                strcpy(wordm[i].ir," > ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"<=")==0){
                strcpy(wordm[i].ir," <= ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,">=")==0){
                strcpy(wordm[i].ir," >= ");
                i++;
            }

            else if(strcmp(wordm[i].attribute,"==")==0){
                strcpy(wordm[i].ir," == ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"||")==0){
                strcpy(wordm[i].ir," || ");
                i++;
            }
            else if(strcmp(wordm[i].attribute,"&&")==0){
                strcpy(wordm[i].ir," && ");
                i++;
            }
             else if(strcmp(wordm[i].attribute,"return")==0){
                strcpy(wordm[i].ir,"RETURN");
                while(i<z){
                i=i+2;
                strcpy(wordm[i].ir," ");
                strcpy(wordm[i].attribute," ");
                strcpy(wordm[i].token," ");
                }
            }
            else if(strcmp(wordm[i].attribute,"if")==0){
                strcpy(wordm[i].ir,"if");
                i++;

            }
            else if(strcmp(wordm[i].attribute,"while")==0){
                strcpy(wordm[i].ir,"if");
                i++;

            }
            else if(strcmp(wordm[i].attribute,"else")==0){
                strcpy(wordm[i].ir,"else");
                i++;

            }
            else if(strcmp(wordm[i].token,"identifier")==0){
                index=searchtable(wordm[i].attribute);
                wordm[i].ir[0]= 'T';
                wordm[i].ir[1]=symbolm[index].id+48;
                i++;
            }
            else if(strcmp(wordm[i].token,"int")==0 || strcmp(wordm[i].token,"float")==0 || strcmp(wordm[i].token,"char")==0 ){
                index=searchnum(wordm[i].attribute);
                wordm[i].ir[0]= 'T';
                wordm[i].ir[1]= '_';
                wordm[i].ir[2]= numberTablem[index].index+48;
                i++;

            }
            else if ( strcmp(wordm[i].attribute,")")==0 || strcmp(wordm[i].attribute,"(")==0 || strcmp(wordm[i].attribute,"void") || strcmp(wordm[i].attribute,"int")){
                strcpy(wordm[i].ir," ");
                i++;
            }

    }

}

int chap_ta_koja=0,chap_ta_koja_shart=0;
void IR(void)
{   if(!strcmp(wordm[i].attribute,"return"))
{
    i=z;
    chap_ta_koja=i;
    flag_ir=1;
}
    else if(!strcmp(wordm[i].attribute,"if"))
        {   while_flag=0;
            i=i+2;
            number_print(2);
            if_ir();
        } /// while
    else if(!strcmp(wordm[i].attribute,"while"))
        {   while_flag=1;
            i=i+2;
            number_print(2);
            if_ir();
        }
    else if(!strcmp(wordm[i].token,"identifier"))number_print(1);

       while(i<=chap_ta_koja  && i<=z){
            fprintf(fp,"%s",wordm[i].ir);
            i++;
        }
        chap_ta_koja=i;
        if(i<z)
         IR();
         if(i==z)main();
}

void if_ir (void)
{   i=i-2;

        if(while_flag==1){
           fprintf(fp,"%c",'\n');fprintf(fp,"%s","L");fprintf(fp,"%d",lcounter+2);fprintf(fp,"%c",'\n');fprintf(fp,"%c",'\n');
        }

     while(i<=chap_ta_koja_shart){
            fprintf(fp,"%s",wordm[i].ir);
            i++;
        }

        fprintf(fp,"%s","goto L");fprintf(fp,"%d",lcounter);fprintf(fp,"%s"," else L");fprintf(fp,"%d",lcounter + 1);fprintf(fp,"%c",'\n');
        l_recognize();
}
void l_recognize(void)
{   fprintf(fp,"%c",'\n');fprintf(fp,"%s","L");fprintf(fp,"%d",lcounter);fprintf(fp,"%c",'\n');
    while(strcmp(wordm[i].attribute,"}")!=0  && j<z){
       fprintf(fp,"%s",wordm[i].ir);
       i++;
    }

    if(while_flag==1){
        fprintf(fp,"%s"," \n goto L");fprintf(fp,"%d",lcounter+2);fprintf(fp,"%c",'\n');
    }

    lcounter++;
    fprintf(fp,"%c",'\n');fprintf(fp,"%s","L");fprintf(fp,"%d",lcounter);fprintf(fp,"%c",'\n');
    if(!strcmp(wordm[++i].attribute,"else")  && j<z){
       while(strcmp(wordm[i].attribute,"}")!=0){
        i++;
        fprintf(fp,"%s",wordm[i].ir);

    }
    }
    lcounter++;
    fprintf(fp,"%c",'\n');
    fprintf(fp,"%c",'\n');
    if(while_flag==1) lcounter++;
}

void number_print(int a)
{int j=i,e;
    if(a==1)
    {
        while(strcmp(wordm[j].attribute,";")!=0  && j<z)
        {
            if((!strcmp(wordm[j].token,"int")) || (!strcmp(wordm[j].token,"float")) || (!strcmp(wordm[j].token,"char")))
               {   if(!strcmp(wordm[j].token,"char")){
                        wordm[j].attribute[1]=wordm[j].attribute[0];
                        wordm[j].attribute[0]=wordm[j].attribute[2]=39;
               }
                   e=searchnum(wordm[j].attribute);
                   fprintf(fp,"%s",wordm[j].ir); fprintf(fp,"%s"," :="); fprintf(fp,"%s",wordm[j].attribute); fprintf(fp,"%c",'\n');

                   j++;
               }
               else if (strcmp(wordm[j].attribute,",")==0)
               {    j++;

               }
               else j++;

        }
        if(j-i ==1)strcpy(wordm[i].ir," ");
    }

       if(a==2)
       {
           while(strcmp(wordm[j].attribute,"}")!=0 && j<z)
           {
               if(strcmp(wordm[j].token,"int")==0  || strcmp(wordm[j].token,"char")==0  || strcmp(wordm[j].token,"float")==0)
                {
                    e=searchnum(wordm[j].attribute);
                    fprintf(fp,"%s",wordm[j].ir); fprintf(fp,"%s"," :="); fprintf(fp,"%s",wordm[j].attribute); fprintf(fp,"%c",'\n');
                    }

                if(strcmp(wordm[j].attribute,")")==0)
                    chap_ta_koja_shart=j;
                j++;

           }
           if(strcmp(wordm[j+1].attribute,"else")==0 )
           {
               while(strcmp(wordm[j].attribute,"}")!=0 )
                {
                if(strcmp(wordm[j].token,"int")==0  || strcmp(wordm[j].token,"char")==0  || strcmp(wordm[j].token,"float")==0){
                    e=searchnum(wordm[j].attribute);
                    fprintf(fp,"%s",wordm[j].ir); fprintf(fp,"%s"," :="); fprintf(fp,"%s",wordm[j].attribute); fprintf(fp,"%c",'\n');
                    j++;
                }

           }
       }
       }
       chap_ta_koja=j;
       return ;
}
