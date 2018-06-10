#include "main_header.h"
using namespace std;

int a[6] = {10,13,16,18,20,22};

char date[20];
char day[10];
char month[10];
char year[10];
char filename_date[30];
tm *ltm2;

int date_c = 1;

void setfilename_date()
{
			//Setting user ID filename
		strcpy(filename_date,"Times\\");
		strcat(filename_date, date);
		strcat(filename_date, ".txt");
			
}

void disp_time()
{
	
	strcpy(date,"");
	fstream t;
	fstream l;
	fflush(stdin);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	for(int i=0;i<5;i++)
	{
		mktime(ltm);
		itoa(date_c,date,20);
		setfilename_date();
		itoa(int(ltm->tm_mday),day,10);
		itoa(int(1+ltm->tm_mon),month,10);
		itoa(int(1900+ltm->tm_year),year,10);
		
		strcpy(date,day);
		strcat(date,"/");
	    strcat(date,month);
	    strcat(date,"/");
	    strcat(date,year);
	    
		l.open(filename_date,ios::out);
		l<<date<<endl;
		
		strcpy(date,day);
		strcat(date,"");
	    strcat(date,month);
	    strcat(date,"");
	    strcat(date,year);
	    
	    l<<date<<endl;
	    
		for(int i=0;i<6;i++)
		{if(date_c==1)
		{if(a[i]>ltm->tm_hour)
		{l<<a[i]<<" 00"<<"\n";}}
		else
		{l<<a[i]<<" 00"<<"\n";}}
		l.close();
		
		ltm->tm_mday ++;
		date_c++;
	}
}


void make_time()
{
	time_t now2 = time(0);
	tm *ltm2 = localtime(&now2);
}
