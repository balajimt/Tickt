#include "main_header.h"
using namespace std;

void graphic_gets(char buffer[],int x,int y,int fore=BLACK, int back=WHITE,int limit=80)
{       
        int width=textwidth((char *)"W");
        int height=textheight((char *)"A");
        int cursor=x,i=0;
        char ch;
        buffer[0]='\0';
        setcolor(fore);
        setfillstyle(1,back);
        while(1)
        {
                //If you donot want to diplay a flashing cursor, then remove
                //the kbhit() while loop
                ///*
                while(!kbhit())
                {
                        setcolor(fore);
                        line(cursor,y+height,cursor+width,y+height);
                        delay(10);
                        //clear out a rectangle of widthXheight
                        setcolor(back);
                        setfillstyle(1,back);
                        int a[8];
                        a[0]=cursor;
                        a[1]=y;
                        a[2]=cursor+width;
                        a[3]=y;
                        a[4]=cursor+width;
                        a[5]=y+height+1;
                        a[6]=cursor;
                        a[7]=y+height+1;
                        fillpoly(4,a);
                        delay(10);
                }
                //till here*/

                ch=getch();
                if( isprint(ch) )
                {
                        if(i<limit)
                        {
                        buffer[i++]=ch;
                        buffer[i]='\0';
                        char tempstr[2]={ch,'\0'};
                        //If you want to input a password,
                        //then replace the above line with:
                        //char tempstr[2]={'*','\0'};

                        //clear out a rectangle of widthXheight
                        setcolor(back);
                        setfillstyle(1,back);
                        int a[8];
                        a[0]=cursor;
                        a[1]=y;
                        a[2]=cursor+width;
                        a[3]=y;
                        a[4]=cursor+width;
                        a[5]=y+height+1;
                        a[6]=cursor;
                        a[7]=y+height+1;
                        fillpoly(4,a);

                        setcolor(fore);
                        outtextxy(cursor,y,tempstr);
                        cursor+=width;
                        }
                }
                else if( ch==8 )        //code for Backspace
                {
                        if(i>0)
                        {
                                buffer[--i]='\0';
                                cursor-=width;

                                //clear out a rectangle of widthXheight
                                setcolor(back);
                                setfillstyle(1,back);
                                int a[8];
                                a[0]=cursor;
                                a[1]=y;
                                a[2]=cursor+width;
                                a[3]=y;
                                a[4]=cursor+width;
                                a[5]=y+height+1;
                                a[6]=cursor;
                                a[7]=y+height+1;
                                fillpoly(4,a);

                                setcolor(fore);
                        }
                }
                else    //The Enter key was pressed.
                {                     //You can put a similar exit
                       cout<<ch;
	           break;    //for Esc key (ch==27)
                }
        }
        setcolor(fore);
}
void graphic_gets_p(char buffer[],int x,int y,int fore=BLACK, int back=WHITE,int limit=80)
{
        int width=textwidth((char *)"W");
        int height=textheight((char *)"A");
        int cursor=x,i=0;
        char ch;
        buffer[0]='\0';
        setcolor(fore);
        setfillstyle(1,back);
        while(1)
        {
                //If you donot want to diplay a flashing cursor, then remove
                //the kbhit() while loop
                ///*
                while(!kbhit())
                {
                        setcolor(fore);
                        line(cursor,y+height,cursor+width,y+height);
                        delay(10);
                        //clear out a rectangle of widthXheight
                        setcolor(back);
                        setfillstyle(1,back);
                        int a[8];
                        a[0]=cursor;
                        a[1]=y;
                        a[2]=cursor+width;
                        a[3]=y;
                        a[4]=cursor+width;
                        a[5]=y+height+1;
                        a[6]=cursor;
                        a[7]=y+height+1;
                        fillpoly(4,a);
                        delay(10);
                }
                //till here*/

                ch=getch();
                if( isprint(ch) )
                {
                        if(i<limit)
                        {
                        buffer[i++]=ch;
                        buffer[i]='\0';
                        //char tempstr[2]={ch,'\0'};
                        //If you want to input a password,
                        //then replace the above line with:
                        char tempstr[2]={'*','\0'};

                        //clear out a rectangle of widthXheight
                        setcolor(back);
                        setfillstyle(1,back);
                        int a[8];
                        a[0]=cursor;
                        a[1]=y;
                        a[2]=cursor+width;
                        a[3]=y;
                        a[4]=cursor+width;
                        a[5]=y+height+1;
                        a[6]=cursor;
                        a[7]=y+height+1;
                        fillpoly(4,a);

                        setcolor(fore);
                        outtextxy(cursor,y,tempstr);
                        cursor+=width;
                        }
                }
                else if( ch==8 )        //code for Backspace
                {
                        if(i>0)
                        {
                                buffer[--i]='\0';
                                cursor-=width;

                                //clear out a rectangle of widthXheight
                                setcolor(back);
                                setfillstyle(1,back);
                                int a[8];
                                a[0]=cursor;
                                a[1]=y;
                                a[2]=cursor+width;
                                a[3]=y;
                                a[4]=cursor+width;
                                a[5]=y+height+1;
                                a[6]=cursor;
                                a[7]=y+height+1;
                                fillpoly(4,a);

                                setcolor(fore);
                        }
                }
                else if(ch==13)      //The Enter key was pressed.
                {                     //You can put a similar exit
                        break;    //for Esc key (ch==27)
                }
        }
        setcolor(fore);
}
