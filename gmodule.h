#include<string.h>
using namespace std;

int input()
{
    int datai;
    string data="";
    char tem;
    char datas[20]="";
    int i=0;
    string dat;
     while(tem!='\r')
    {
        tem=getch();
        if(tem=='\r')
        {
            break;
        }
        if(tem=='\b')
        {
            if(i>0)
            {
                i--;
                datas[i]='\0';
                setfillstyle(1,0);
                bar(520,getmaxy()-50,getmaxx(),getmaxy()-30);
                outtextxy(520,getmaxy()-50,datas);
                tem='\0';
            }
        }
        else
        {
            if(i<4)
            {
                datas[i]=tem;
                outtextxy(520,getmaxy()-50,datas);
                i++;
            }
        }
        delay(10);
    }
    i=0;
    while(datas[i]!='\0')
    {
        data=data+datas[i];
        i++;
    }
    if(data=="\0")
    {
        datai=0;
    }
    else
        {
    datai=stoi(data);
        }
    return datai;
}

// function to make node with all the shapes and the the data
void nod(int x, int y, string prev, string data, string next, string add, bool direction)
{
    if(direction)
    {
        rectangle(x,y,x+400,y+50);                                       // outer rectangle
        outtextxy(x+20,y+18,const_cast<char*>(prev.c_str()));
        rectangle(x+10,y+10,x+150,y+40);                                 // inner 1 rectangle ::prev field address
        outtextxy(x+20+150,y+18,const_cast<char*>(data.c_str()));
        rectangle(x+160,y+10,x+250,y+40);                                // inner 2 rectangle ::data field
        outtextxy(x+18+150+100,y+18,const_cast<char*>(next.c_str()));
        rectangle(x+260,y+10,x+390,y+40);                                // inner 3 rectangle ::next field address
        outtextxy(x+143,y+65,const_cast<char*>(add.c_str()));
        rectangle(x+130,y+60,x+270,y+90);                                // inner rectangle for address
        rectangle(x+120,y+50,x+280,y+100);                               // outer rectangle for address
    }
    else
    {
        rectangle(x,y,x+400,y+50);                                       // outer rectangle
        outtextxy(x+20,y+18,const_cast<char*>(next.c_str()));
        rectangle(x+10,y+10,x+150,y+40);                                 // inner 1 rectangle ::prev field address
        outtextxy(x+20+150,y+18,const_cast<char*>(data.c_str()));
        rectangle(x+160,y+10,x+250,y+40);                                // inner 2 rectangle ::data field
        outtextxy(x+18+150+100,y+18,const_cast<char*>(prev.c_str()));
        rectangle(x+260,y+10,x+390,y+40);                                // inner 3 rectangle ::next field address
        outtextxy(x+143,y+65,const_cast<char*>(add.c_str()));
        rectangle(x+130,y+60,x+270,y+90);                                // inner rectangle for address
        rectangle(x+120,y+50,x+280,y+100);                               // outer rectangle for address
    }


}
void narro(int x, int y)
{
    line(x,y,x+100,y);
}

void srarro(int x, int y)
{
    line(x,y,x+40,y);
    line(x+40,y,x+40,y+200);
    line(x,y+200,x+40,y+200);

}
void slarro(int x, int y)
{
    line(x,y,x-40,y);
    line(x-40,y,x-40,y+200);
    line(x,y+200,x-40,y+200);

}
void arrow(int pos)
{
    switch(pos)
    {
    case 1:
            narro(450,225);
            break;
    case 2:
            narro(950,225);
            break;
    case 3:
            srarro(1450,225);
            break;
    case 4:
            narro(950,425);
            break;
    case 5:
            narro(450,425);
            break;
    case 6:
            slarro(50,425);
            break;
    case 7:
            narro(450,625);
            break;
    case 8:
            narro(950,625);
            break;
    default:
        break;

    }
}

void nodbox(int position, string pp, string dd, string nn, string tt)
{
    switch(position)
    {
    case 1:
            nod(50,200,pp,dd,nn,tt,true);
            break;
    case 2:
            nod(550,200,pp,dd,nn,tt,true);
            arrow(1);
            break;
    case 3:
            nod(1050,200,pp,dd,nn,tt,true);
            arrow(2);
            break;
    case 4:
            nod(1050,400,pp,dd,nn,tt,false);
            arrow(3);
            break;
    case 5:
            nod(550,400,pp,dd,nn,tt,false);
            arrow(4);
            break;
    case 6:
            nod(50,400,pp,dd,nn,tt,false);
            arrow(5);
            break;
    case 7:
            nod(50,600,pp,dd,nn,tt,true);
            arrow(6);
            break;
    case 8:
            nod(550,600,pp,dd,nn,tt,true);
            arrow(7);
            break;
    case 9:
            nod(1050,600,pp,dd,nn,tt,true);
            arrow(8);
            break;
    default:
            break;

    }
}

void highlight(int swtch)
{
    switch(swtch)
    {
    case 1:
            bar(50,200,450,210);
            bar(50,240,450,250);
            bar(50,200,60,250);
            bar(440,200,450,250);
            break;
    case 2:
            bar(550,200,950,210);
            bar(550,240,950,250);
            bar(550,200,560,250);
            bar(940,200,950,250);
            break;
    case 3:
            bar(1050,200,1450,210);
            bar(1050,240,1450,250);
            bar(1050,200,1060,250);
            bar(1440,200,1450,250);
            break;
    case 4:
            bar(1050,400,1450,410);
            bar(1050,440,1450,450);
            bar(1050,400,1060,450);
            bar(1440,400,1450,450);
            break;
    case 5:
            bar(550,400,950,410);
            bar(550,440,950,450);
            bar(550,400,560,450);
            bar(940,400,950,450);
            break;
    case 6:
            bar(50,400,450,410);
            bar(50,440,450,450);
            bar(50,400,60,450);
            bar(440,400,450,450);
            break;
    case 7:
            bar(50,600,450,610);
            bar(50,640,450,650);
            bar(50,600,60,650);
            bar(440,600,450,650);
            break;
    case 8:
            bar(550,600,950,610);
            bar(550,640,950,650);
            bar(550,600,560,650);
            bar(940,600,950,650);
            break;
    case 9:
            bar(1050,600,1450,610);
            bar(1050,640,1450,650);
            bar(1050,600,1060,650);
            bar(1440,600,1450,650);
            break;
    default:
            break;
    }

}

void clearbody()
{
    setfillstyle(1,0);
    bar(0,80,getmaxx(),getmaxy()-80);
}

void clearheader()
{
    setfillstyle(1,0);
    bar(0,0,getmaxx(),70);
}

void clearfooter()
{
    setfillstyle(1,0);
    bar(0,getmaxy()-70,getmaxx(),getmaxy());
}
