#include<stdlib.h>
#include<stdio.h>
#include <windows.h>
#include <io.h>
#include <direct.h>
#include<ctype.h>
#include <sys/types.h>
#include <sys/param.h>
#include<unistd.h>
#include<sys/stat.h>
#define INT_BITS 32
void setcolor(int ForgC)
{
WORD wColor;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;//We use csbi for the wAttributes word.
if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {//Mask out all but the background attribute, and add in the forgournd color
wColor = (csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
SetConsoleTextAttribute(hStdOut, wColor);
}
return;
}
//this function reverse the bits and returns the decimal equivalent of that reversed binary number
unsigned int reverseBits(unsigned int num) 
{   unsigned int  NO_OF_BITS = 5; 
    unsigned int reverse_num = 0, i, temp; 
    for (i = 0; i < NO_OF_BITS; i++) 
    { 
    temp=(num&(1<<i)); 
    if(temp) 
    reverse_num|=(1<<((NO_OF_BITS - 1) - i)); 
    } 
   return reverse_num; 
} 
//code for error detection 
int error_detection(FILE *fp1, FILE *fp2) 
{   // fetching character of two file 
    // in two variable ch1 and ch2 
    char ch1 = getc(fp1); 
    char ch2 = getc(fp2); 
     // error keeps track of number of errors 
     // pos keeps track of position of errors 
     // line keeps track of error line 
     int error = 0, pos = 0, line = 1; 
     // iterate loop till end of file 
    while (ch1 != EOF && ch2 != EOF) 
    { 
    pos++; 
    // if both variable encounters new 
    // line then line variable is incremented 
    // and pos variable is set to 0 
    if (ch1 == '\n' && ch2 == '\n') 
    { 
    line++; 
    pos = 0; 
    } 
    // if fetched data is not equal then 
    // error is incremented 
    if (ch1 != ch2) 
    { 
    error++; 
    printf("Line Number : %d \tError"" Position : %d \n", line, pos); 
    } 
    // fetching character until end of file 
    ch1 = getc(fp1); 
    ch2 = getc(fp2); 
    } 
    if(error>0)
    return -1;
    else
	return 1;
} 
void display_file_content(FILE* f)
{   
    rewind(f);
	char c;
	while((c=fgetc(f))!=EOF)
	printf("%c",c);
	printf("\n");
}
FILE* encrypt(FILE* k)
{
	FILE* l=tmpfile();
	char ch;
	while((ch=fgetc(k))!=EOF)
{       char space;
        char chartemp;
        int cptlflag=0;//for capital letters we set flag and don't apply our algorihtm of encyption to it and copy it as it is by making temp and rev aS 0
	    int temp=0,decimal=0;
		if(ch!='.'||ch!='?'||ch!='!'||ch!='@'||ch!='#'||ch!='^'||ch!='%'||ch!='\\'||ch!=':'||ch!=';'||ch!='('||ch!=')')
		{
		if((isdigit(ch))!=1)
		{
	    switch(ch)
        {
		 case ' ':
		 space='*';
		 break;
         case 'a':
         temp=1;
         break;
         case 'A':
		 temp=1;
         cptlflag=1;
         break;
         case 'b':
         temp=2;
         break;
         case 'B':
		 temp=2;
         cptlflag=1;
         break;
         case 'c':
         temp=3;
         break;
         case 'C':
		 temp=3;
         cptlflag=1;
         break;
         case 'd':
         temp=4;
         break;
		 case 'E':
		 temp=5;
		 cptlflag=1;
         case 'e':
         temp=5;
         break;
         case 'D':
		 temp=4;
         cptlflag=1;
         break;
         case 'f':
         temp=6;
         break;
		 case 'F':
		 temp=6;
		 cptlflag=1;
		 break;
         case 'g':
         temp=7;
         break;
		 case 'G':
		 temp=7;
		 cptlflag=1;
		 break;
         case 'h':
         temp=8;
         break;
		 case 'H':
		 temp=8;
		 cptlflag=1;
		 break;
         case 'i':
         temp=9;
         break;
		 case 'I':
		 temp=9;
		 cptlflag=1;
		 break;
         case 'j':
         temp=10;
         break;
		 case 'J':
		 cptlflag=1;
		 temp=10;
		 break;
         case 'k':
         temp=11;
         break;
		 case 'K':
		 cptlflag=1;
		 temp=11;
		 break;
         case 'l':
         temp=12;
         break;
		 case 'L':
		 cptlflag=1;
		 temp=12;
		 break;
         case 'm':
         temp=13;
         break;
		 case 'M':
		 temp=13;
		 cptlflag=1;
		 break;
         case 'n':
         temp=14;
         break;
		 case 'N':
		 temp=14;
		 cptlflag=1;
		 break;
         case 'o':
         temp=15;
         break;
		 case 'O':
		 cptlflag=1;
		 temp=15;
		 break;
         case 'p':
         temp=16;
         break;
		 case 'P':
		 temp=16;
		 cptlflag=1;
		 break;
         case 'q':
         temp=17;
         break;
		 case 'Q':
		 temp=17;
		 cptlflag=1;
		 break;
         case 'r':
         temp=18;
         break;
		 case 'R':
		 temp=18;
		 cptlflag=1;
		 break;
         case 's':
         temp=19;
         break;
		 case 'S':
		 temp=19;
		 cptlflag=1;
		 break;
         case 't':
         temp=20;
         break;
		 case 'T':
		 cptlflag=1;
		 temp=20;
		 break;
         case 'u':
         temp=21;
         break;
		 case 'U':
		 cptlflag=1;
		 temp=21;
		 break;
         case 'v':
         temp=22;
         break;
		 case 'V':
		 cptlflag=1;
		 temp=22;
		 break;
         case 'w':
         temp=23;
         break;
		 case 'W':
		 cptlflag=1;
		 temp=23;
		 break;
         case 'x':
         temp=24;
         break;
		 case 'X':
		 cptlflag=1;
		 temp=24;
		 break;
         case 'y':
         temp=25;
         break;
		 case 'Y':
		 cptlflag=1;
		 temp=25;
		 break;
         case 'z':
         temp=26;
         break;
		 case 'Z':
		 cptlflag=1;
		 temp=26;
		 break;
       }
//encrpting each letter 
if(cptlflag!=1)//capital letters need not to be encrypted
{
decimal=reverseBits(temp);
switch(decimal)
{
case 0:
chartemp='*';
break;
case 1:
chartemp='a';
break;
case 2:
chartemp='b';
break;
case 3:
chartemp='c';
break;
case 4:
chartemp='d';
break;
case 5:
chartemp='e';
break;
case 6:
chartemp='f';
break;
case 7:
chartemp='g';
break;
case 8:
chartemp='h';
break;
case 9:
chartemp='i';
break;
case 10:
chartemp='j';
break;
case 11:
chartemp='k';
break;
case 12:
chartemp='l';
break;
case 13:
chartemp='m';
break;
case 14:
chartemp='n';
break;
case 15:
chartemp='o';
break;
case 16:
chartemp='p';
break;
case 17:
chartemp='q';
break;
case 18:
chartemp='r';
break;
case 19:
chartemp='s';
break;
case 20:
chartemp='t';
break;
case 21:
chartemp='u';
break;
case 22:
chartemp='v';
break;
case 23:
chartemp='w';
break;
case 24:
chartemp='x';
break;
case 25:
chartemp='y';
break;
case 26:
chartemp='z';
break;
default:
goto v;
//if the decimal equivalent of reversed binary exceeds the value between 0 to 26
//srand(time(NULL));
//decimal=rand()%26;
//goto L1;
break;
}
fputc(chartemp,l);
}
else
v:fputc(ch,l);
}
else
fputc(ch,l);
}
else
fputc(ch,l);

//tempfile is written i.e. encrypted file
}
return l;
}
FILE* decrypt(FILE* u)
{
char rp;
int binary1;
int rever1;
//opening receiver file to write encrypted data
FILE* reciver;
char filename2[50];
printf("ENTER RECIEVER FILE NAME :\n");
scanf("%s",&filename2);
reciver=fopen(filename2,"a+");
if(fopen==NULL)
{
printf("file not found");
exit(1);
}
int v=access(filename2,W_OK);
while((rp=fgetc(u))!=EOF)
{
char space,r1;
int temp1=0;
if(rp!='.'||rp!='?'||rp!='!'||rp!='@'||rp!='#'||rp!='^'||rp!='%'||rp!='\\'||rp!=':'||rp!=';'||rp!='('||rp!=')'||isupper(rp)!=1 && isdigit(rp)!=1)
{
switch(rp)
{
case 'a':
temp1=1;
break;
case '*':
temp1=0;
break;
case 'b':
temp1=2;
break;
case 'c':
temp1=3;
break;
case 'd':
temp1=4;
break;
case 'e':
temp1=5;
break;
case 'f':
temp1=6;
break;
case 'g':
temp1=7;
break;
case 'h':
temp1=8;
break;
case 'i':
temp1=9;
break;
case 'j':
temp1=10;
break;
case 'k':
temp1=11;
break;
case 'l':
temp1=12;
break;
case 'm':
temp1=13;
break;
case 'n':
temp1=14;
break;
case 'o':
temp1=15;
break;
case 'p':
temp1=16;
break;
case 'q':
temp1=17;
break;
case 'r':
temp1=18;
break;
case 's':
temp1=19;
break;
case 't':
temp1=20;
break;
case 'u':
temp1=21;
break;
case 'v':
temp1=22;
break;
case 'w':
temp1=23;
break;
case 'x':
temp1=24;
break;
case 'y':
temp1=25;
break;
case 'z':
temp1=26;
break;
}
//decrypting each letter
int decimal1; 
decimal1=reverseBits(temp1);
switch(decimal1)
{
case 0:
r1=' ';
break;
case 1:
r1='a';
break;
case 2:
r1='b';
break;
case 3:
r1='c';
break;
case 4:
r1='d';
break;
case 5:
r1='e';
break;
case 6:
r1='f';
break;
case 7:
r1='g';
break;
case 8:
r1='h';
break;
case 9:
r1='i';
break;
case 10:
r1='j';
break;
case 11:
r1='k';
break;
case 12:
r1='l';
break;
case 13:
r1='m';
break;
case 14:
r1='n';
break;
case 15:
r1='o';
break;
case 16:
r1='p';
break;
case 17:
r1='q';
break;
case 18:
r1='r';
break;
case 19:
r1='s';
break;
case 20:
r1='t';
break;
case 21:
r1='u';
break;
case 22:
r1='v';
break;
case 23:
r1='w';
break;
case 24:
r1='x';
break;
case 25:
r1='y';
break;
case 26:
r1='z';
break;
default:
goto m;
//if the decimal equivalent of reversed binary exceeds the value between 0 to 26
//srand(time(NULL));
//decimal1=rand()%26;
//goto x1;
break;
}
if(v==0)//if receiver file has the access to write into file
fputc(r1,reciver);
}
else
{
m:if(v==0)
fputc(rp,reciver);
}
}
return reciver;
}




FILE* f1;
int main()
{FILE* fptr;//pointer to sender file 
char filename1[50];
FILE* j;//pointer to encrypted file
int out1;//to exit out of program
W1:
printf("ENTER SENDER FILE NAME:\n");
scanf("%s",&filename1);
int a=access("hello.txt",R_OK);
//openning the sender file contaning data to be encrypted  
if((fptr=fopen(filename1,"r"))==NULL)
{
setcolor(4);
printf("Error!openning file\n");
exit(1);
}
//displaying sender file to be encrypted
printf("FILE BEFORE ENCRYPTION\n");
display_file_content(fptr);
//displaying buffer file after file is completely encoded
rewind(fptr);
if(a==0)//if file is readable
j=encrypt(fptr);
printf("FILE AFTER ENCRYPTION\n");
display_file_content(j);
//DECRYPTION AT RECIEVER SIDE(buffer stream to be decrypted and writing  decrypted data to receiver file)
rewind(j);
FILE* v=decrypt(j);
//displaying after file is completely decrypted
display_file_content(v);
int ack=error_detection(fptr,v);//work as an acknowledgement if recieved or not correctly
printf("PRINTING THE ACKNOWLEDGEMENT FROM RECIEVER SIDE\n");
if(ack==-1)
{
printf("FILE NOT RECIEVED SUCCESSFULLY!ENTER 1 to continue and -1 to discontinue\n");
scanf("%d",&out1);
if(out1==-1)
exit(0);
else
goto W1;
}
else{ 
printf("FILE RECIEVED SUCESSFULLY!ENTER 1 to continue and 0 to discontinue\n");
scanf("%d",&out1);
if(out1==0)
exit(0);
else 
goto W1;
}
return 0;
}
