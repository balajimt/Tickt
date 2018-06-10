#include "main_header.h"

int f = 20;

void loading_green()
{   
	char green[100];
	char load[10];
	int f=10;
	for(int i=0;i<38;i++)
  {
		strcpy(green,"Green/");
		itoa(i,load,10);
		strcat(green,load);
  		strcat(green,".jpg");
  		readimagefile(green,133,72,1000,75);delay(f);
  		strcpy(green,"");
  }                           
}


void loading_main(int i)
{
	setbkcolor(WHITE);  
	readimagefile("Loading//back.jpg",0,0,1000,600);
	
	char green[100];
	char load[10];
	int f=0;
	for(int k=0;k<i;k++)
  {     
		
		for(int j=0;j<21;j++)
	  {
			strcpy(green,"Loading//");
			itoa(j,load,10);
			strcat(green,load);
	  		strcat(green,".jpg");
	  		readimagefile(green,128,50,851,534);delay(f);
	  		strcpy(green,"");
	  } 
  }  
	
}
