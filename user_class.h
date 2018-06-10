#include "main_header.h"

extern void graphic_gets(char buffer[],int x,int y,int fore=BLACK, int back=WHITE,int limit=80);
extern void graphic_gets_p(char buffer[],int x,int y,int fore=BLACK, int back=WHITE,int limit=80);
extern void render_seat(char image[100],char date[],char time[]);
extern void final_ticket();
extern void check(int x,int y,int m,int n,int flag);
extern void setfilename_date();
extern void make_time();
extern tm *ltm2;
extern void disp_time();
extern int i_r;
extern int j_r;
extern void loading_main(int i);
extern void loading_green();

extern int a_m;
extern int a_n;
extern int b_m;
extern int b_n;
extern int c_m;
extern int c_n;
extern int d_m;
extern int d_n;


using namespace std;

int x;
int y;
int disp_x;
int disp_y;
int j=1;
char id[100];
int first_movie = 0;

char date2[20];
char day2[10];
char month2[10];
char year2[10];
extern char filename_date[30];
extern int no_of_tickets;

class admin
{
	protected:
		 int finance;
		
	
	public:
		
		
		void service_tax_add(int i)
		{
			char fin1[10];
			fstream fin;
			fin.open("finance.txt",ios::in);
			fin.getline(fin1,10,'\n');
			fin.close();
			finance = atoi(fin1)+i;
			
			fstream fout;
			fout.open("finance.txt",ios::out);
			fout<<finance<<endl;
			fout.close();
			
		}
		
		
		void movies()
		{
			readimagefile("BG//movies_admin.jpg",0,0,1000,600);
			char fin1[10];
			fstream fin;
			fin.open("finance.txt",ios::in);
			fin.getline(fin1,10,'\n');
			fin.close();
			settextstyle(COMPLEX_FONT,HORIZ_DIR,8);
			outtextxy(550,480,fin1);
			selection();
			
		}
		
		void selection()
		{ 
			while(2)
		     {
			     getmouseclick(WM_LBUTTONDOWN, x, y);
				 if((x>918)&&(y>0)&&(x<1000)&&(y<70))
				 {closegraph();
				 exit(0);
				 break;}
		   }
		}
	
};

class user:public admin
{
	protected :
		
		char username[100];
		char username1[100];
		char password[100];
		char password1[100];
		
		char filename[100];
		char filename_m[100];
		char filename_i[100];
		char filename_d[100];
		char filename_money[100];
		
		char movie[100];
		char image[100];
		char theatre[100];
		char date[20];
		char date2[20];
		char time [10];
	
	public:
		
		void create_account()
		{
		    check_user();
		    if(j==1)
		    {
		            setfilename();
		            app_user();
		            write_account();
		            read_account();
		            readimagefile("BG//success_create.jpg",0,0,1000,600);
		            back_to_main();
		            
		            
		    }
			
		}
		
		void app_user()//To append user to main list
		{
		     ofstream f2;
		     f2.open("Accounts//main.txt",ios::app);
		     f2<<username<<endl;
		     f2.close();
		}
		
		void check_user()//To check if that user exists in the database
		{
		     fstream f;
		     f.open("Accounts//main.txt",ios::in);
		     while(f.getline(id,100,'\n'))
		     {
					if(!strcmp(id,username))
				    {
											
											j=0;
											cout<<"Signup failure"<<endl;
				                            readimagefile("BG//signup_failure.jpg",0,0,1000,600);
				                            back_to_main();
					}
			}
		}
		
		void setfilename()
		{
			//Setting user ID filename
		     strcpy(filename,"Accounts\\");
		     strcat(filename, username);
		     strcat(filename, ".txt");
			
		}
		
		
		
		void write_account()
		{
			 fstream f;
		     f.open(filename,ios::out);
		     f<<username<<endl<<password;
		     f.close();
			
		}
		
		void read_account()
		{
			fstream f1;
		    f1.open(filename,ios::in);
		    f1.getline(username1,100,'\n');
		    f1.getline(password1,100,' ');
		    f1.close();
		}
		
		void get_username()
		{    
		     readimagefile("BG//login.jpg",0,0,1000,600);
		     graphic_gets(username,255,257);
		     get_password();
		}
		
		void get_password()
		{
    
		     readimagefile("BG//login.jpg",0,0,1000,600);
		     outtextxy(255,257,username);
		     graphic_gets_p(password,255,380);
		     selection_login_2();
		}
		
		void log_account()//To log a user 
		{
			if(!strcmp(username,""))
		    {
				readimagefile("BG//failure.jpg",0,0,1000,600);
				back_to_main();
			}
			
		    setfilename();
		    ifstream f3;
		    f3.open(filename,ios::in);
		    if(!f3)
		    {
				readimagefile("BG//failure.jpg",0,0,1000,600);
				back_to_main();
			}
		    
		    else
		    {
				f3.getline(username1,100,'\n');
				f3.getline(password1,100,'\n');
			    if(!strcmp(password,password1))
			     {
						loading_main(2);
			     		if(!strcmp(username,"admin")){admin::movies();} else {movies();}
			     
			     }
			    else
			     {readimagefile("BG//failure.jpg",0,0,1000,600);
				 back_to_main();}
				 
		     }
			
		}
		
		void selection_login()
		{
		     while(2)
		     {            
		             getmouseclick(WM_LBUTTONDOWN, x, y);
		             if((x>930)&&(y>0)&&(x<1000)&&(y<70))
		             {closegraph();
		             exit(0);
		             break;}
		             else if((x>183)&&(y>237)&&(x<796)&&(y<290))
		             {get_username();
		             break;}
		     }
		}
		
		void back_to_main()
		{
		     while(2)
		     {            
		             getmouseclick(WM_LBUTTONDOWN, x, y);
		             if((x>930)&&(y>0)&&(x<1000)&&(y<70))
		             {closegraph();
		             exit(0);
		             break;}
		             else if((x>0)&&(y>495)&&(x<1000)&&(y<600))
		             {
							readimagefile("BG//login.jpg",0,0,1000,600);
							selection_login();
							break;
					}
		     }
		}
		
		void selection_login_2()
		{
		     while(2)
		     {            
		             getmouseclick(WM_LBUTTONDOWN, x, y);
		             if((x>930)&&(y>0)&&(x<1000)&&(y<70))
		             {closegraph();
		             exit(0);
		             break;}
		             else if((x>473)&&(y>495)&&(x<1000)&&(y<600))
		             {cout<<"log account"<<endl;
					 log_account();
		             break;}
		             else if((x>0)&&(y>495)&&(x<473)&&(y<600))
		             {cout<<"create account"<<endl;
		             cout<<username<<endl;
		             cout<<password<<endl;
					 create_account();
		             break;}
		             else if((x>183)&&(y>237)&&(x<796)&&(y<290))
		             {get_username();
		             break;}
		     }
		}
		
		void selection();
		void selection_movies();
		void movies();
		void display_movies();
		void bookings();
		void users();
		void settings();
		void about();
		void scroll_up();
		void scroll_down();
		void book_ticket(int i);
		void get_input();
		void selection_ticket_success();
		void access_date(int i);
		void selection_date();
		void selection_time();
		void book_time(int counter);
		void display_date();
		void money();
		void selection_money();
		void selection_about();
			
};

void user::movies()
{
	readimagefile("BG//movies.jpg",0,0,1000,600);
	display_movies();
	selection_movies();
	
}

void user::display_movies()
{
	 setbkcolor(WHITE);
	 setcolor(BLACK);
	 disp_x =0;disp_y =0;
	 int ctr=0;
	 
     fstream f9;
     strcpy(filename_m,"Data\\Movies\\movies_main.txt");
     f9.open(filename_m,ios::in);
     
     
     while(ctr<first_movie)
     {f9.getline(movie,100,'\n');
	 f9.getline(image,100,'\n');
	 ctr++;}
	 
     while(f9.getline(movie,100,'\n'))
     {
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	 outtextxy(170+disp_x,400+disp_y,movie);
	 f9.getline(image,100,'\n');
	 strcpy(filename_i,"Data\\Movies\\");
	 strcat(filename_i,image);
	 strcat(filename_i,".jpg");
	 
	 readimagefile(filename_i,173+disp_x,115+disp_y,340+disp_x,355+disp_y);
	 readimagefile("Data\\Movies\\book.jpg",173+disp_x,450+disp_y,173+170+disp_x,510+disp_y);
	 if(340+disp_x<=918)
	 {disp_x=disp_x+340-173+90;}   
	 else
	 {break;}
	 delay(10);                   
     }
}

void user::users()
{
	int i=0,j=0;
	readimagefile("BG//users.jpg",0,0,1000,600);
	loading_green();
	 fstream f2;
	 f2.open("Accounts//main.txt",ios::in);
	 while(f2.getline(username1,100,'\n'))
	 {
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	 outtextxy(190+i,154+j,username1);
	 
	 if(j<550)
	 {j=j+30;}
	 else
	 {i=i+320;
	 j=0;}                      
	 }
	selection();
	
}

void user::bookings()
{
	char number[10];
	char bill[10];
	char service_tax[10];
	char total_bill[10];
	ifstream f2;
	int i=0,j=0;
	readimagefile("BG//bookings.jpg",0,0,1000,600);
	loading_green();
	strcpy(filename_money,"Transactions\\");
    strcat(filename_money, username);
    strcat(filename_money, ".txt");
    
	 f2.open(filename_money,ios::in);
	 while(f2.getline(movie,100,'\n'))
	 {
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	 setbkcolor(WHITE);
	 setcolor(BLACK);
	 //f<<movie<<endl<<number<<endl<<total_bill<<endl<<date<<endl<<time<<endl;
	 f2.getline(number,10,'\n');
	 f2.getline(total_bill,10,'\n');
	 f2.getline(date,20,'\n');
	 f2.getline(time,10,'\n');
	 outtextxy(180,250+j,movie);
	 outtextxy(420,250+j,number);
	 outtextxy(620,250+j,total_bill);
	 outtextxy(800,250+j,date);
	 outtextxy(900,250+j,time);
	 
	 if(j<550)
	 {j=j+30;}
	 else
	 {i=i+320;
	 j=0;}                      
	 }
	selection();
	
}

void user::settings()
{
	readimagefile("BG//settings.jpg",0,0,1000,600);
	loading_green();
	selection();
	
}

void user::about()
{
	readimagefile("BG//aboutus.jpg",0,0,1000,600);
	loading_green();
	selection_about();
	
}

void user::selection()
{
	while(2)
     {
	     getmouseclick(WM_LBUTTONDOWN, x, y);
		 if((x>0)&&(y>70)&&(x<133)&&(y<200))
		 {loading_green();
		 if(!strcmp(username,"admin")){admin::movies();} else {movies();}
		 break;}
		 else if((x>0)&&(y>200)&&(x<133)&&(y<316))
		 {bookings();
		 break;}
		 else if((x>0)&&(y>316)&&(x<133)&&(y<430))
		 {users();
		 break;}
		 else if((x>0)&&(y>430)&&(x<133)&&(y<540))
		 {about();
		 break;}
		 else if((x>882)&&(y>0)&&(x<1000)&&(y<70))
		 {closegraph();
		 exit(0);
		 break;}
   }
}

void user::selection_about()
{
	while(2)
     {
	     getmouseclick(WM_LBUTTONDOWN, x, y);
		 if((x>0)&&(y>70)&&(x<133)&&(y<200))
		 {loading_green();if(!strcmp(username,"admin")){admin::movies();} else {movies();}
		 break;}
		 else if((x>0)&&(y>200)&&(x<133)&&(y<316))
		 {bookings();
		 break;}
		 else if((x>0)&&(y>316)&&(x<133)&&(y<430))
		 {users();
		 break;}
		 else if((x>0)&&(y>430)&&(x<133)&&(y<540))
		 {about();
		 break;}
		 else if((x>882)&&(y>0)&&(x<1000)&&(y<70))
		 {closegraph();
		 exit(0);
		 break;}
		 else if((x>344)&&(y>357)&&(x<750)&&(y<447))
		 {
				readimagefile("BG//aboutus_kidding.jpg",0,0,1000,600);
				selection();
		 break;}
   }
}

void user::selection_movies()
{
     while(2)
     {            
             getmouseclick(WM_LBUTTONDOWN, x, y);
             if((x>0)&&(y>70)&&(x<133)&&(y<200))
             {loading_green();if(!strcmp(username,"admin")){admin::movies();} else {movies();}
             break;}
             else if((x>0)&&(y>200)&&(x<133)&&(y<316))
             {bookings();
             break;}
             else if((x>0)&&(y>316)&&(x<133)&&(y<430))
             {users();
             break;}
             else if((x>0)&&(y>430)&&(x<133)&&(y<540))
             {about();
             break;}
             else if((x>882)&&(y>0)&&(x<1000)&&(y<70))
             {closegraph();
			 exit(0);
             break;}
			 else if((x>158)&&(y>536)&&(x<190)&&(y<577))
             {scroll_up();
			 break;}
             
             else if((x>943)&&(y>536)&&(x<1271)&&(y<977))
             {scroll_down();
			 break;}
			 
			 else if((x>173)&&(y>450)&&(x<340)&&(y<510))
             {book_ticket(1);
             display_date();
             selection_date();
			 break;}
			 
			 else if((x>173+340-173+90)&&(y>450)&&(x<340+340-173+90)&&(y<510))
             {book_ticket(2);
             display_date();
             selection_date();
			 break;}
			 
			 else if((x>173+2*(340-173+90))&&(y>450)&&(x<340+2*(340-173+90))&&(y<510))
             {book_ticket(3);
             display_date();
             selection_date();
			 break;}
			 
     }

}

void user::access_date(int i)
{
	int y_d=0;
	fstream f;
	int temp_date;
	char temp_date_c[10];
	itoa(i,temp_date_c,10);
	strcpy(filename_d,"Times\\");
	strcat(filename_d,temp_date_c);
	strcat(filename_d,".txt");
	
	
	 f.open(filename_d,ios::in);
     f.getline(date,20,'\n');
     f.getline(date2,20,'\n');
     cout<<date<<"hello"<<endl;
     while(f.getline(time,10,'\n'))
     {
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	 cout<<time;
	 setbkcolor(WHITE);
	 setcolor(BLACK);
	 outtextxy(263,200+y_d,time);
	 readimagefile("BG//book_time.jpg",704,200+y_d,704+147,200+45+y_d);
	 y_d +=50;}
	 f.close();
	 selection_time();
	
}

void user::display_date()
{
	 disp_time();
	 readimagefile("BG//date.jpg",0,0,1000,600);
	//495,373
	 fstream f1,f2,f3;
	 f1.open("Times//3.txt",ios::in);
     f1.getline(date,20,'\n');
     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	 setbkcolor(COLOR(217,217,217));
	 setcolor(BLACK);
	 outtextxy(493,373-20,date);
	 f1.close();
	 
	 f2.open("Times//4.txt",ios::in);
     f2.getline(date,20,'\n');
	 outtextxy(493,450-20,date);
	 f2.close();
	 
	 f3.open("Times//5.txt",ios::in);
     f3.getline(date,20,'\n');
	 outtextxy(493,530-20,date);
	 f3.close();
	
	
	
}

void user::selection_date()
{  
     while(2)
     {            
             getmouseclick(WM_LBUTTONDOWN, x, y);
             if((x>132)&&(y>172)&&(x<1000)&&(y<243))
             {
					readimagefile("BG//time.jpg",0,0,1000,600);
					access_date(1);
			 		selection_time();
					break;
			 }
			 
             else if((x>132)&&(y>250)&&(x<1000)&&(y<317))
             {		readimagefile("BG//time.jpg",0,0,1000,600);
					access_date(2);
			 		selection_time();
					break;
			 }
             else if((x>132)&&(y>326)&&(x<1000)&&(y<395))
             {
					readimagefile("BG//time.jpg",0,0,1000,600);
					access_date(3);
			 		selection_time();
					break;
			 }
             else if((x>132)&&(y>404)&&(x<1000)&&(y<475))
             {
					readimagefile("BG//time.jpg",0,0,1000,600);
					access_date(4);
			 		selection_time();
					break;
			 }
             else if((x>132)&&(y>480)&&(x<1000)&&(y<550))
             {		
					readimagefile("BG//time.jpg",0,0,1000,600);
					access_date(5);
			 		selection_time();
					break;
			 }
			 
			 else if((x>882)&&(y>0)&&(x<1000)&&(y<70))
			 {closegraph();
			 exit(0);
			 break;}
			 
			 else if((x>16)&&(y>500)&&(x<135)&&(y<600))
			 {loading_green();if(!strcmp(username,"admin")){admin::movies();} else {movies();}
			 break;}	
			 
     }

}

void user::book_time(int counter)
{
	 int k=1;
	 fstream f;
	 f.open(filename_d,ios::in);
	 cout<<filename_d<<endl;
     f.getline(date,20,'\n');
	 f.getline(date2,20,'\n');
	 while(k<counter)
     { k++;
       f.getline(time,10,'\n');
	 }
	 f.getline(time,10,'\n');
	 cout<<"Balaji "<<time;
	 f.close();
	 render_seat(image,date2,time);
	 get_input();
}

void user::selection_time()
{   
	
     while(2)
     {            
             getmouseclick(WM_LBUTTONDOWN, x, y);
             if((x>704)&&(y>200)&&(x<704+147)&&(y<200+45))
             {
					 book_time(1);
			 }
			 
             else if((x>704)&&(y>200+1*(50))&&(x<704+147)&&(y<200+45+1*(50)))
             {		
					book_time(2);
			 }
             else if((x>704)&&(y>200+2*(50))&&(x<704+147)&&(y<200+45+2*(50)))
             {
					book_time(3);
			 }
             else if((x>704)&&(y>200+3*(50))&&(x<704+147)&&(y<200+45+3*(50)))
             {
					book_time(4);
			 }
             else if((x>704)&&(y>200+4*(50))&&(x<704+147)&&(y<200+45+4*(50)))
             {		
					book_time(5);
			 }
			 
			 else if((x>704)&&(y>200+5*(50))&&(x<704+147)&&(y<200+45+5*(50)))
             {		
					book_time(6);
			 }
			 
			 else if((x>882)&&(y>0)&&(x<1000)&&(y<70))
			 {closegraph();
			 exit(0);
			 break;}
			 
			 else if((x>16)&&(y>500)&&(x<135)&&(y<600))
			 {display_date();
			 selection_date();
			 break;}
			 
     }

}

void user::selection_ticket_success()
{
     while(2)
     {            
             getmouseclick(WM_LBUTTONDOWN, x, y);
             if((x>0)&&(y>519)&&(x<1000)&&(y<600))
             {if(!strcmp(username,"admin")){admin::movies();} else {movies();}
             break;}	 
     }

}

void user::scroll_down()
{
	
	first_movie++;
    if(!strcmp(username,"admin")){admin::movies();} else {movies();}
}

void user::scroll_up()
{
	if(first_movie>=1)
	first_movie--;
    if(!strcmp(username,"admin")){admin::movies();} else {movies();}
}

void user::book_ticket(int i)
{
	int k=0;
	int ctr=0;
	fstream j;
	j.open(filename_m);
	while(ctr<first_movie)
    {j.getline(movie,100,'\n');
    j.getline(image,100,'\n');
	 ctr++;}
	while(j.getline(movie,100,'\n'))
	{j.getline(image,100,'\n');
	k++;
	if(k==i)
	{
	break;
	}}
	j.close();
}


void user::get_input()
{
	cout<<"Comes here"<<endl;
	int m,n;
	 while(2)
     {
             getmouseclick(WM_LBUTTONDOWN, x, y);
             if(x>a_m&&y>a_n&&x<a_m+500&&y<a_n+75)
			{
					m= a_m;
					n= a_n;

					x=x-m;
					y=y-n;

					i_r = x/25;
					j_r  = y/25;
					cout<<i_r<<" "<<j_r;
					if((j_r<3)&&(i_r<20))
					check(i_r,j_r,m,n,1);
					get_input();
			}

			else if(x>b_m&&y>b_n&&x<b_m+500&&y<b_n+100)
			{
					m= b_m;
					n= b_n;

					x=x-m;
					y=y-n;

					i_r = x/25;
					j_r  = y/25;

					cout<<i_r<<" "<<j_r;
					if((j_r<4)&&(i_r<20))
					check(i_r,j_r,m,n,2);
					get_input();
			}

			else if(x>c_m&&y>c_n&&x<c_m+100&&y<c_n+225)
			 {
					m= c_m;
					n= c_n;

					x=x-m;
					y=y-n;

					i_r = x/25;
					j_r  = y/25;
					cout<<i_r<<" "<<j_r;

					if((j_r<9)&&(i_r<4))
					check(i_r,j_r,m,n,3);
					get_input();

			}

			else if(x>d_m&&y>d_n&&x<d_m+100&&y<d_n+225)
			{
					m= d_m;
					n= d_n;

					x=x-m;
					y=y-n;

					i_r = x/25;
					j_r  = y/25;

					cout<<i_r<<" "<<j_r;

					if((j_r<9)&&(i_r<4))
					check(i_r,j_r,m,n,4);
					get_input();}



			else if(x>860&&y>519&&x<1000&&y<600)
			{
					final_ticket();
					cout<<no_of_tickets<<endl;
					money();
					
			}
			
			else if(x>0&&y>519&&x<142&&y<600)
			{
					if(!strcmp(username,"admin")){admin::movies();} else {movies();}
			}


     }

}


void user::money()
{
	char number[10];
	char bill[10];
	char service_tax[10];
	char total_bill[10];
	int service_tax_temp;
	if(no_of_tickets!=0)
	{
	itoa(no_of_tickets,number,10);
	itoa(no_of_tickets* 120,bill,10);
	itoa(int(0.1 * no_of_tickets* 120),service_tax,10);
	service_tax_temp = int(0.1 * no_of_tickets* 120);
	itoa(no_of_tickets * 120+int(0.1 * no_of_tickets * 120),total_bill,10);
	no_of_tickets=0;}
	
	else
	{
		strcpy(number,"No seats");
		strcpy(bill,"-");
		strcpy(service_tax,"-");
		strcpy(total_bill,"ZERO :)");
		
		
	}
	
	readimagefile("BG//money.jpg",0,0,1000,600);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(796,194-20,username);
	outtextxy(796,258-20,movie);
	outtextxy(796,264,number);
	outtextxy(796,314-20,bill);
	outtextxy(796,339-20,service_tax);
	admin::service_tax_add(service_tax_temp);
	
	settextstyle(COMPLEX_FONT,HORIZ_DIR,6);
	outtextxy(650,460-44,total_bill);
	
	ofstream f;
	
	strcpy(filename_money,"Transactions\\");
    strcat(filename_money, username);
    strcat(filename_money, ".txt");
	
	f.open(filename_money,ios::app);
	f<<movie<<endl<<number<<endl<<total_bill<<endl<<date<<endl<<time<<endl;
	f.close();
	
	selection_money();
}

void user::selection_money()
{
     while(2)
     {            
             getmouseclick(WM_LBUTTONDOWN, x, y);
             if((x>0)&&(y>519)&&(x<1000)&&(y<600))
             {readimagefile("BG//ticket_success.jpg",0,0,1000,600);
			  selection_ticket_success();
             break;}	 
     }

}
