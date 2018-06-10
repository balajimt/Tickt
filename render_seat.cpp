#include "main_header.h"


using namespace std;

int i_r,j_r;
extern int x;
extern int y;
//Array for the seats allocation
//Temporary will be converted to files
int a_m=250,a_n=200;
int b_m=250,b_n=325;
int c_m= 100,c_n = 200;
int d_m= 800,d_n = 200;

char file_name[100];
int no_of_tickets=0;
char temp[10];

//Adds ticket to currently active booking files
void add_ticket(char *str)
{
	ofstream f;
	f.open("booking.txt",ios::app);
	cout<<str;
	f<<str<<endl;
	no_of_tickets++;
	f.close();
}

//Removes ticket from currently active booking files
void remove_ticket(char *str)
{    ofstream fout;
     ifstream fin;
     char ch1[10];
     fin.open("booking.txt",ios::in);
     fout.open("Untitled.txt",ios::app);
     while(fin.getline(ch1,10,'\n'))
     {
                                     if(strcmp(ch1,str))
                                     {fout<<ch1<<endl;}
     }
     fout.close();
     fin.close();
     remove("booking.txt");
     rename("Untitled.txt","booking.txt");
     no_of_tickets--;
}

char* ticket_no(int x,int y,int flag)
{
	char s[10];
	strcpy(s,"");
	if(flag ==1)
	{
		int g = (x+1)*1;
		for(int i=0;i<y;i++)
		{g = g+20;}

		itoa(g,s,10);
		strcat(s,"A");
		return s;
	}

	else if(flag ==2)
	{
		int g = (x+1)*1;
		for(int i=0;i<y;i++)
		{g = g+20;}

		itoa(g,s,10);
		strcat(s,"B");
		return s;

	}

	else if(flag ==3)
	{
		int g = (x+1)*1;
		for(int i=0;i<y;i++)
		{g = g+4;}

		itoa(g,s,10);
		strcat(s,"C");
		return s;

	}

	else if(flag ==4)
	{
		int g = (x+1)*1;
		for(int i=0;i<y;i++)
		{g = g+4;}

		itoa(g,s,10);
		strcat(s,"D");
		return s;
	}

}

//Moves from 'booking' to 'booked' file
void final_ticket()
{    ofstream fout;
     ifstream fin;
     char ch1[10];
     fin.open("booking.txt",ios::in);
     fout.open(file_name,ios::app);
     cout<<file_name<<"Final_comes_Here"<<endl;
     while(fin.getline(ch1,10,'\n'))
     {
            fout<<ch1<<endl;
     }
     fout.close();
     fin.close();
     remove("booking.txt");
     fout.open("Untitled.txt",ios::out);
     fout.close();
     rename("Untitled.txt","booking.txt");
}

//Check ticket in booked
int check_booked(char *s)
{
	ifstream fin;
	fin.open(file_name,ios::in);
	char ch1[10];
	while(fin.getline(ch1,10,'\n'))
     {
            if(strcmp(s,ch1)==0)
            {
				return 1;
			}
     }

     return 0;
}


int check_booking(char *s)
{
	ifstream fin;
	fin.open("booking.txt",ios::in);
	char ch1[10];
	while(fin.getline(ch1,10,'\n'))
     {
            if(strcmp(s,ch1)==0)
            {
				return 1;
			}
     }

     return 0;


}

void check(int x,int y,int m,int n,int flag)
{
	if(flag ==1)
	{

	char temp[10];
	strcpy(temp,"");
	strcpy(temp,ticket_no(x,y,1));
	if(check_booked(temp)==0)
	{

	int g = (x+1)*1;
	for(int i=0;i<y;i++)
	{g = g+20;}

	char s[10];
	itoa(g,s,10);
	outtextxy(800,489,"    ");
	strcat(s,"A");


		if(check_booking(s)==0)
		{
			readimagefile("Tiles//20.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			outtextxy(800,489,s);
			add_ticket(s);
		}
		else if(check_booking(s)==1)
		{
			readimagefile("Tiles//11.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));

			remove_ticket(s);
			outtextxy(800,489,s);
		}
	}
	}

	if(flag ==2)
	{


	char temp[10];
	strcpy(temp,"");
	strcpy(temp,ticket_no(x,y,2));
	if(check_booked(temp)==0)
	{

	int g = (x+1)*1;
	for(int i=0;i<y;i++)
	{g = g+20;}

	char s[10];
	itoa(g,s,10);
	outtextxy(800,489,"    ");
	strcat(s,"B");

		if(check_booking(s)==0)
		{
			readimagefile("Tiles//20.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			add_ticket(s);
			outtextxy(800,489,s);

		}

		else if(check_booking(s)==1)
		{
			readimagefile("Tiles//11.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			remove_ticket(s);
			outtextxy(800,489,s);
		}
	}}

	if(flag ==3)
	{
	char temp[10];
	strcpy(temp,"");
	strcpy(temp,ticket_no(x,y,3));
	if(check_booked(temp)==0)
	{

		int g = (x+1)*1;
		for(int i=0;i<y;i++)
		{g = g+4;}

		char s[10];
		itoa(g,s,10);
		outtextxy(800,489,"    ");
		strcat(s,"C");

		if(check_booking(s)==0)
		{
			readimagefile("Tiles//20.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			add_ticket(s);
			outtextxy(800,489,s);
		}
		else if(check_booking(s)==1)
		{
			readimagefile("Tiles//11.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			remove_ticket(s);
			outtextxy(800,489,s);
		}
	}}

	if(flag ==4)
	{
	char temp[10];
	strcpy(temp,"");
	strcpy(temp,ticket_no(x,y,4));
	if(check_booked(temp)==0)
	{
		int g = (x+1)*1;
		for(int i=0;i<y;i++)
		{g = g+4;}

		char s[10];
		itoa(g,s,10);
		outtextxy(800,489,"    ");
		strcat(s,"D");

		if(check_booking(s)==0)
		{
			readimagefile("Tiles//20.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			add_ticket(s);
			outtextxy(800,489,s);
		}
		else if(check_booking(s)==1)
		{
			readimagefile("Tiles//11.jpg",m+0+25*(i_r),n+0+25*(j_r),m+25+25*(i_r),n+25+25*(j_r));
			remove_ticket(s);
			outtextxy(800,489,s);
		}
	}}
}


void render_seat(char image[100],char date[],char time[])
{
	strcpy(file_name,"Bookings//");
	strcat(file_name,image);
	strcat(file_name,date);
	strcat(file_name,time);
	strcat(file_name,".txt");
	
	//initwindow(1000,600,"",40,0,false,false);//WindowPositioning
    setbkcolor(WHITE);//Setting Background White
    setcolor(BLACK);//Current font color
    settextstyle(COMPLEX_FONT,HORIZ_DIR,2);//Text style
    setusercharsize(1,1,1,1);//MagnificationText
    readimagefile("tickt1.jpg",0,0,1000,600);
	//Drawing of the initial theatre screen
	
	outtextxy(0,20,image);
	outtextxy(0,40,date);
	outtextxy(0,60,time);
	//A
    for(int y=0;y<3;y++)
     {

     for(int x=0;x<20;x++)
	 {

			char temp[10];
			strcpy(temp,"");
			strcpy(temp,ticket_no(x,y,1));
			if(check_booked(temp)==0)
			{readimagefile("Tiles//11.jpg",a_m+0+25*x,a_n+0+25*y,a_m+25+25*(x),a_n+25+25*y);}
			else if(check_booked(temp)==1)
			{readimagefile("Tiles//13.jpg",a_m+0+25*x,a_n+0+25*y,a_m+25+25*(x),a_n+25+25*y);}

	}}

	//B
	for(int y=0;y<4;y++)
     {
     for(int x=0;x<20;x++)
	 {
			char temp[10];
			strcpy(temp,"");
			strcpy(temp,ticket_no(x,y,2));
			if(check_booked(temp)==0)
			{readimagefile("Tiles//11.jpg",b_m+0+25*x,b_n+0+25*y,b_m+25+25*(x),b_n+25+25*y);}
			else if(check_booked(temp)==1)
			{readimagefile("Tiles//13.jpg",b_m+0+25*x,b_n+0+25*y,b_m+25+25*(x),b_n+25+25*y);}

	}}

	//C
	for(int y=0;y<9;y++)
     {
     for(int x=0;x<4;x++)
	 {
			char temp[10];
			strcpy(temp,"");
			strcpy(temp,ticket_no(x,y,3));
			if(check_booked(temp)==0)
			{readimagefile("Tiles//11.jpg",c_m+0+25*x,c_n+0+25*y,c_m+25+25*(x),c_n+25+25*y);}
			else if(check_booked(temp)==1)
			{readimagefile("Tiles//13.jpg",c_m+0+25*x,c_n+0+25*y,c_m+25+25*(x),c_n+25+25*y);}}
	 }

	//D
	for(int y=0;y<9;y++)
     {
     for(int x=0;x<4;x++)
	 {		char temp[10];
			strcpy(temp,"");
			strcpy(temp,ticket_no(x,y,4));
			if(check_booked(temp)==0)
			{readimagefile("Tiles//11.jpg",d_m+0+25*x,d_n+0+25*y,d_m+25+25*(x),d_n+25+25*y);}
			else if(check_booked(temp)==1)
			{readimagefile("Tiles//13.jpg",d_m+0+25*x,d_n+0+25*y,d_m+25+25*(x),d_n+25+25*y);}}
	}
}

