#include "main_header.h"
#include "user_class.h"

extern void disp_time();
extern void loading_main(int i);
int main()
{
	disp_time();
	user u1;
	initwindow(1000,600,"",40,0,false,false);//WindowPositioning
    setbkcolor(WHITE);//Setting Background White
    settextstyle(COMPLEX_FONT,HORIZ_DIR,2);//Text style
    setusercharsize(1,1,1,1);//MagnificationText
    readimagefile("BG//login.jpg",0,0,1000,600);
    u1.selection_login();
    
    getch();
	
	return 0;

}
