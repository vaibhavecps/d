#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<time.h>
char ch;
int score;
clock_t start,end;
struct hgscore
{ int scr;
  char name[50];
}hg[6];
struct Circle
{ int rad,g,f;
} C[8];
void Game();
void Lose();
void Exit();
void Help();
void menu();
void timeout();
void move();
void Leaderboard();
void keyhit()
{ int x=getmaxx(),y=getmaxy();
  setcolor(GREEN);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy(x/2-200,y-40,"Press any key...");
}
void main()
{int gd=DETECT,gm,i;
 initgraph(&gd,&gm,"C:\\Turboc3\\bgi");
 int x=getmaxx(),y=getmaxy(),X,Y;
 cleardevice();
	X=getmaxx()/2;
	Y=getmaxy()/2;
       for(i=30;i<100;i++)
      { delay(100);
	setcolor(i/10);
	line(X,Y,2,i)   ;
	line(X,Y,i,2);
	line(i,Y,Y,3); }
    setcolor(YELLOW);
    settextstyle(10,0,0);
    outtextxy(80,250,"AKV PRESENTS");
    delay(2000);
    cleardevice();
 setbkcolor(YELLOW);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 setcolor(WHITE);
     for(i=0;i<1000;i++)
    line(0,y,x-i,i);
 setcolor(BLUE);
 outtextxy(x/2-200,y/3,"GOLDEN");
 outtextxy(x/2,y/2,"RUSH");
 delay(1000);
 setcolor(GREEN);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 outtextxy(x/2+100,y-40,"loading...");
 setfillstyle(SOLID_FILL,GREEN);
 for(i=1;i<=150;i++)
 { bar(x/2+100,y-60,x/2+100+i,y-40);
   delay(50);
 }
 setcolor(YELLOW);
 outtextxy(x/2+100,y-40,"loading...");
 setfillstyle(SOLID_FILL,YELLOW);
 bar(x/2+100,y-60,x/2+250,y-40);
 keyhit();
 getch();
 menu();
}
//********************************* Menu ************************************
void menu()
{ char ch='1' ;
  cleardevice();
  setlinestyle(DOTTED_LINE,0,3);
  setcolor(WHITE);
  rectangle(5,5,635,470);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
  setcolor(MAGENTA);
  setbkcolor(BLACK);
  setfillstyle(SOLID_FILL,GREEN);
  bar(40,45,520,125);
  outtextxy(50,50,"(1) START GAME");
  outtextxy(50,150,"(2) LEADERBOARD");
  outtextxy(50,250,"(3) HELP");
  outtextxy(50,350,"(4) EXIT");
  keyhit();
  label:
    setcolor(MAGENTA);
    if(ch=='1')
     { setfillstyle(SOLID_FILL,GREEN);
       bar(40,45,520,125);
       setfillstyle(SOLID_FILL,BLACK);
       bar(40,145,520,225);
       bar(40,245,520,325);
       bar(40,345,520,425);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
       outtextxy(50,50,"(1) START GAME");
       outtextxy(50,150,"(2) LEADERBOARD");
       outtextxy(50,250,"(3) HELP");
       outtextxy(50,350,"(4) EXIT");
       ch=getch();
       if(ch=='\r')    Game();
       else  goto label;       }
    else if(ch=='2')
     { setfillstyle(SOLID_FILL,GREEN);
       bar(40,145,520,225);
       setfillstyle(SOLID_FILL,BLACK);
       bar(40,45,520,125);
       bar(40,245,520,325);
       bar(40,345,520,425);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
       outtextxy(50,50,"(1) START GAME");
       outtextxy(50,150,"(2) LEADERBOARD");
       outtextxy(50,250,"(3) HELP");
       outtextxy(50,350,"(4) EXIT");
       ch=getch();
       if(ch=='\r')    Leaderboard();
       else  goto label;     }
    else if(ch=='3')
     { setfillstyle(SOLID_FILL,GREEN);
       bar(40,245,520,325);
       setfillstyle(SOLID_FILL,BLACK);
       bar(40,45,520,125);
       bar(40,145,520,225);
       bar(40,345,520,425);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
       outtextxy(50,50,"(1) START GAME");
       outtextxy(50,150,"(2) LEADERBOARD");
       outtextxy(50,250,"(3) HELP");
       outtextxy(50,350,"(4) EXIT");
       ch=getch();
       if(ch=='\r')    Help();
       else  goto label;         }
    else if(ch=='4')
     { setfillstyle(SOLID_FILL,GREEN);
       bar(40,345,520,425);
       setfillstyle(SOLID_FILL,BLACK);
       bar(40,45,520,125);
       bar(40,145,520,225);
       bar(40,245,520,325);
       settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
       outtextxy(50,50,"(1) START GAME");
       outtextxy(50,150,"(2) LEADERBOARD");
       outtextxy(50,250,"(3) HELP");
       outtextxy(50,350,"(4) EXIT");
       ch=getch();
       if(ch=='\r')    Exit();
       else  goto label;         }
    else menu();
}
//***************************** Leaderboard *********************************
void Leaderboard()
{  cleardevice();
   setbkcolor(BLACK);
   setlinestyle(DOTTED_LINE,0,3);
   setcolor(WHITE);
   rectangle(5,5,635,470);
   setcolor(GREEN);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
   outtextxy(140,20,"SCOREBOARD");
   setcolor(RED);
   line(140,90,515,90);
   setcolor(MAGENTA);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   outtextxy(60,150,"Rank");
   outtextxy(250,150,"Name");
   outtextxy(480,150,"Score");
   keyhit();
   fstream f;
   f.open("Hgscore.dat",ios::in|ios::ate|ios::binary);
   int i=0,j,tmp,a[2][6];
   f.seekg(0);
   while(i<5)
   { f.read((char*)&hg[i],sizeof(hg[i]));
     i++;
   }
   for(i=0;i<6;i++)
   {
     a[0][i]=hg[i].scr;
     a[1][i]=i;
   }
   for(i=0;i<6;i++)
    for(j=0;j<6-i;j++)
    { if(a[0][j]<a[0][j+1])
      { tmp=a[0][j];
	a[0][j]=a[0][j+1];
	a[0][j+1]=tmp;
	tmp=a[1][j];
	a[1][j]=a[1][j+1];
	a[1][j+1]=tmp;
      }
    }
   f.seekg(0);
   f.seekp(0);
   outtextxy(90,210,"1.");
   outtextxy(90,230,"2.");
   outtextxy(90,250,"3.");
   outtextxy(90,270,"4.");
   outtextxy(90,290,"5.");
   char mess[90];
   i=0;
   while(i<5)
   {  f.write((char*)&hg[a[1][i]],sizeof(hg[a[1][i]]));
      sprintf(mess,"%s",hg[a[1][i]].name);
      outtextxy(225,210+i*20,mess);
      sprintf(mess,"%d",hg[a[1][i]].scr);
      outtextxy(500,210+i*20,mess);
      i++;
   }
   f.close();
   getch();
   menu();
}
//******************************* Time Out **********************************
void timeout()
{ setfillstyle(SOLID_FILL,GREEN);
  setcolor(WHITE);
  rectangle(100,100,520,400);
  bar(103,103,517,397);
  setcolor(RED);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
  outtextxy(150,125,"TIME'S UP !");
  setcolor(YELLOW);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(125,230,"Your golden time is ");
  outtextxy(125,280,"finished .");
  char mess[30];
  sprintf(mess,"Your Score = %d",score);
  outtextxy(125,330,mess);
  keyhit();
  hg[5].scr=score;
  getch();
  cleardevice();
  setbkcolor(GREEN);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  setcolor(MAGENTA);
  outtextxy(100,100,"Enter your name :");
  cout<<"\n\n\n\n\n\n\n\n\n\n\t";
  gets(hg[5].name);
  Leaderboard();
}
//********************************* Exit ************************************
void Exit()
  { float x=getmaxx(),y=getmaxy();
    int i;
    cleardevice();
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
    outtextxy(x/2-200,y/4,"THANKS FOR");
    outtextxy(x/2-150,y/2,"PLAYING");
    for(i=1;i<=10;++i)
    { setbkcolor(i);
      delay(300);
    }
    exit(0);
  }
//*********************************** Lose **********************************
void Lose()
{ setfillstyle(SOLID_FILL,GREEN);
  setcolor(WHITE);
  rectangle(100,100,520,400);
  bar(103,103,517,397);
  setcolor(RED);
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
  outtextxy(150,125,"YOU LOSE !");
  setcolor(YELLOW);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(125,230,"You ought to take gold");
  outtextxy(125,280,"in ascending order.");
  char mess[30];
  sprintf(mess,"Your Score = %d",score);
  outtextxy(125,330,mess);
  keyhit();
  hg[5].scr=score;
  getch();
  getch();
  cleardevice();
  setbkcolor(GREEN);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  setcolor(MAGENTA);
  outtextxy(100,100,"Enter your name :");
  cout<<"\n\n\n\n\n\n\n\n\n\n\t";
  gets(hg[5].name);
  Leaderboard();
 }
//********************************* Help ************************************
void Help()
  { cleardevice();
    setbkcolor(LIGHTBLUE);
    setcolor(BROWN);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
    outtextxy(180,10,"HELP");
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    outtextxy(1,90," This game is basically for greedy people.It is a very simple");
    outtextxy(1,120," game and we just have to catch more and more gold");
    outtextxy(1,150," in ascending order in a limited time.") ;
    outtextxy(1,180," During the game there will be a rotating hook,by pressing");
    outtextxy(1,210," any key (except ESC key) you can extend the chain . If it");
    outtextxy(1,240," catches the gold you will earn MONEY !!!") ;
    outtextxy(1,270," To exit the game,press ECS key.");
    outtextxy(1,300," I HOPE YOU WILL ENJOY THE GAME.");
    outtextxy(350,400,"Made by--ARCHIT GUPTA");
    keyhit();
    getch();
    menu();
  }
//***************************** Game Page **********************************
void Game()
{   cleardevice();
    float x=getmaxx(),y=getmaxy();
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
    outtextxy(x/2-150,y/4,"LEVEL  1");
    outtextxy(x/2-150,y/2,"CATCH IT");
    for(int i=1;i<=10;++i)
    { setbkcolor(i);
      delay(300); }
    setcolor(BROWN);
    setbkcolor(BROWN);
    setlinestyle(SOLID_LINE,0,3);
    rectangle(6,99,634,469);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(100,250,BROWN);
    setcolor(LIGHTBLUE);
    rectangle(6,6,634,99);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(100,90,LIGHTBLUE);
    setcolor(WHITE);
    setlinestyle(DOTTED_LINE,0,3);
    rectangle(5,5,635,477);
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    outtextxy(20,10,"Time = 2 min");
    setfillstyle(SOLID_FILL,YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
    outtextxy(200,30,"Score = ");
    outtextxy(450,30,"0");
    circle(100,220,10);
    floodfill(100,220,YELLOW);

    circle(475,400,50);
    floodfill(475,400,YELLOW);

    circle(300,300,30);
    floodfill(300,300,YELLOW);

    circle(175,250,20);
    floodfill(175,250,YELLOW);

    circle(100,400,15);
    floodfill(100,400,YELLOW);

    circle(540,200,20);
    floodfill(540,200,YELLOW);

    circle(520,270,10);
    floodfill(520,270,YELLOW);

    circle(300,400,10);
    floodfill(300,400,YELLOW);
    setcolor(BLUE);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    outtextxy(95,212,"2");
    outtextxy(470,395,"1");
    outtextxy(300,300,"3");
    outtextxy(170,245,"4");
    outtextxy(95,395,"5");
    outtextxy(535,195,"6");
    outtextxy(515,262,"7");
    outtextxy(295,390,"8");
 score=0;
 C[0].rad=50 , C[0].g=475 , C[0].f=400;
 C[1].rad=10 , C[1].g=100 , C[1].f=220;
 C[2].rad=30 , C[2].g=300 , C[2].f=300;
 C[3].rad=20 , C[3].g=175 , C[3].f=250;
 C[4].rad=15 , C[4].g=100 , C[4].f=400;
 C[5].rad=20 , C[5].g=540 , C[5].f=200;
 C[6].rad=10 , C[6].g=520 , C[6].f=270;
 C[7].rad=10 , C[7].g=300 , C[7].f=400;
 start=clock();
 move();
 }
//*************************** Moving Chain **********************************
void move()
{ double q,j,t,cosine;
  float h,k;
  int ptr,i,x=getmaxx();
  end=clock();
  if(((float)(end-start)/CLK_TCK)>=120)
  timeout();
  while(!kbhit())
  {
   for(q=(x/2)-65;q<=(x/2)+65;q+=0.1)
  { if(!kbhit())
    {cosine=(q-x/2)/65 ,t=acos(cosine),j=65*sin(t)+100;
     setlinestyle(SOLID_LINE,1,3);
     setcolor(WHITE);
     line(x/2,101,q,j);
     delay(1);
     setcolor(BROWN);
     line(x/2,101,q,j);
    }
  }
  for(q=(x/2)+65;q>=(x/2)-65;q-=0.1)
  {if(!kbhit())
   {cosine=(q-x/2)/65 ,t=acos(cosine),j=65*sin(t)+100;
    setlinestyle(SOLID_LINE,1,3);
    setcolor(WHITE);
    line(x/2,100,q,j);
    delay(1);
    setcolor(BROWN);
    line(x/2,100,q,j);
    }
  }
}
  ptr=-1;
 setcolor(WHITE);
 h=(x/2)+(65*cosine),k=100+65*sin(t);
 line(x/2,101,h,k);
 setcolor(YELLOW);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 setcolor(WHITE);
 for(i=65;i<500;i++)
  { h=(x/2)+(i*cosine),k=100+i*sin(t);
    circle(h,k,1);
    if(h>425&&h<525 && k>350&&k<450)
     { if(C[0].g!=0)
       { if(score!=0)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"0");
	 setcolor(YELLOW);
	 outtextxy(450,30,"1");
	 ptr=0;  break; }
       else continue; }
    else if(h>90&&h<110 && k>210&&k<230)
     { if(C[1].g!=0)
       { if(score!=1)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"1");
	 setcolor(YELLOW);
	 outtextxy(450,30,"2");
	 ptr=1;  break; }
       else continue; }
    else if(h>270&&h<330 && k>270&&k<330)
     { if(C[2].g!=0)
       { if(score!=2)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"2");
	 setcolor(YELLOW);
	 outtextxy(450,30,"3");
	 ptr=2;  break; }
       else continue; }
    else if(h>155&&h<195 && k>230&&k<270)
     { if(C[3].g!=0)
       { if(score!=3)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"3");
	 setcolor(YELLOW);
	 outtextxy(450,30,"4");
	 ptr=3;  break; }
       else continue; }
    else if(h>85&&h<115 && k>385&&k<415)
     { if(C[4].g!=0)
       { if(score!=4)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"4");
	 setcolor(YELLOW);
	 outtextxy(450,30,"5");
	 ptr=4;  break; }
       else continue; }
    else if(h>520&&h<560 && k>180&&k<220)
     { if(C[5].g!=0)
       { if(score!=5)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"5");
	 setcolor(YELLOW);
	 outtextxy(450,30,"6");
	 ptr=5;  break; }
       else continue; }
    else if(h>510&&h<530 && k>260&&k<280)
     { if(C[6].g!=0)
       { if(score!=6)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"6");
	 setcolor(YELLOW);
	 outtextxy(450,30,"7");
	 ptr=6;  break; }
       else continue; }
    else if(h>290&&h<310 && k>390&&k<410)
     { if(C[7].g!=0)
       { if(score!=7)    Lose();
	 setcolor(LIGHTBLUE);
	 outtextxy(450,30,"7");
	 setcolor(YELLOW);
	 outtextxy(450,30,"8");
	 ptr=7;  break; }
       else continue; }
  }
 setcolor(WHITE);
 if(ptr==-1)
 { setlinestyle(DOTTED_LINE,0,3);
   for(i;i>65;i--)
    { setcolor(BROWN);
      h=(x/2)+(i*cosine),k=100+i*sin(t);
      circle(h,k,1);
      setcolor(WHITE);
      rectangle(5,5,635,477); }
   setlinestyle(SOLID_LINE,0,3);
   setcolor(BROWN);
   line(x/2,101,h,k);  }
 else { setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	circle(C[ptr].g , C[ptr].f , C[ptr].rad);
	floodfill(C[ptr].g , C[ptr].f ,BROWN);
	for(i;i>65;i-=10)
	{ h=(x/2)+(i*cosine) , k=100+i*sin(t);
	  setcolor(YELLOW);
	  setfillstyle(SOLID_FILL,YELLOW);
	  circle(h,k,C[ptr].rad);
	  floodfill(h,k,YELLOW);
	  delay(600);
	  setcolor(BROWN);
	  setfillstyle(SOLID_FILL,BROWN);
	  circle(h,k,C[ptr].rad);
	  floodfill(h,k,BROWN);     }
	setcolor(BROWN);
	line(x/2,101,h,k);
	C[ptr].g=0 ;
	score=ptr+1;
      }
 if(score==8)
 { setfillstyle(SOLID_FILL,GREEN);
   setcolor(WHITE);
   rectangle(100,100,520,400);
   bar(103,103,517,397);
   setcolor(MAGENTA);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   char mess[30];
   sprintf(mess,"Your Score = %d",score);
   outtextxy(150,250,mess);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
   for(i=0;i<=16;i++)
    { setcolor(i);
      outtextxy(170,120,"YOU WIN!!");
      delay(300);  }
   hg[5].scr=score;
   cleardevice();
   setbkcolor(GREEN);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
   setcolor(MAGENTA);
   outtextxy(100,100,"Enter your name :");
   cout<<"\n\n\n\n\n\n\n\n\n\n\t";
   gets(hg[5].name);
   Leaderboard(); }
 getch();
 ch=getch();
 if((int)ch!=27)
 move();
 else menu(); }
