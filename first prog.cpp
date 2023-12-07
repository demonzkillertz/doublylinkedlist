#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<strings.h>
#include"gmodule.h"

using namespace std;

void insertion();
void deletion();
void searching();
void sorting();
void displaymodule();
int count = 0, loc, display_position;

struct node
{
    int data;
    struct node *pnext;
    struct node *pprev;
} *pfirst = NULL, *pnew, *pthis, *ptemp, *ptemp1, *plast;

// function to create new node
void create(int da)
{
    pnew = ((struct node *)malloc(sizeof(struct node)));
    pnew->data=da;
    pnew->pnext = NULL;
    pnew->pprev = NULL;
    count++;
}

// function to check the node is empty or not
int empty()
{
    string dat;
    if (pfirst == NULL)
    {
        setfillstyle(1,0);
        clearfooter();
        outtextxy(0,getmaxy()-50,"The node is empty, Press any key to continue...");
        getch();
        return (0);
    }
    else if (pfirst->pnext == NULL)
    {
        dat=to_string(pfirst->data);
        setfillstyle(1,0);
        clearfooter();
        outtextxy(0,getmaxy()-50,"Press Enter to Delete: ");
        outtextxy(300,getmaxy()-50, const_cast<char*>(dat.c_str()));
        free(pfirst);
        pfirst = NULL;
        plast = NULL;
        count = 0;
        getch();
        return (0);
    }
    return (1);
}

// main menu display
void mmenu()
{
    cleardevice();
    displaymodule();
    char mainmenu;
    //main menu graphics
    //.............................................................
    setfillstyle(1,14);
    bar(0,70,getmaxx(),80);
    bar(0,getmaxy()-80,getmaxx(),getmaxy()-70);
    settextstyle(4,0,5);
    outtextxy(getmaxx()/2-420,20,"Doubly Linked List");
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"1. Insertion");
    outtextxy(430,getmaxy()-50,"2. Deletion");
    outtextxy(830,getmaxy()-50,"3. Sorting");
    outtextxy(1230,getmaxy()-50,"4. Searching");
    outtextxy(getmaxx()-150,30,"0. Exit");
    //.................................................................
    mainmenu=getch();
    switch(mainmenu)
    {
    case '1':
        insertion();
        break;

    case '2':
        deletion();
        break;

    case '3':
        sorting();
        break;

    case '4':
        searching();
        break;

    case '0':
        exit(0);
        break;
    }
    mmenu();
}

/* --------------------------------------- START FUNCTIONS FOR INSERTION--------------------------------------------------*/
// 1. function to insert node from beginning
void isbg(int datastore)
{
    create(datastore);
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        pfirst->pnext = NULL;
        pfirst->pprev = NULL;
    }
    else
    {
        pnew->pprev = NULL;
        pnew->pnext = pfirst;
        pfirst->pprev = pnew;
        pfirst = pnew;
    }
}

// 2. function to insert from the end
void isend(int datastore)
{
    create(datastore);
    if (pfirst == NULL)
    {
        pfirst = pnew;
        plast = pnew;
        pfirst->pnext = NULL;
        pfirst->pprev = NULL;
    }
    else
    {
        plast->pnext = pnew;
        pnew->pprev = plast;
        pnew->pnext = NULL;
        plast = pnew;
    }
}

// 3. function to add data in specified location
void issp()
{
    clearfooter();
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"Enter the location to insert data: ");
    loc=input();
    if (loc > count)
    {
        clearfooter();
        outtextxy(30,getmaxy()-50,"The location doesn't exist");
        getch();
    }
    else
    {
        clearfooter();
        outtextxy(30,getmaxy()-50,"Enter data to insert at the location: ");
        if (loc == 1)
        {
            isbg(input());
        }
        else
        {
            create(input());
            pthis = pfirst;
            for (int i = 1; i < loc; i++)
            {
                pthis = pthis->pnext;
            }
            ptemp = pthis->pprev;
            ptemp->pnext = pnew;
            pnew->pprev = ptemp;
            pnew->pnext = pthis;
            pthis->pprev = pnew;
        }
        clearfooter();
        displaymodule();
        setcolor(RGB(179, 254, 254));
        outtextxy(0,getmaxy()-50,"Data successfully added, Press Enter to continue...");
        setcolor(WHITE);
        getch();
    }
}


// 4. function to insert node from specified location end
void isspe()
{
    clearfooter();
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"Enter the location to insert data: ");
    loc=input();
    if (loc > count)
    {
        clearfooter();
        outtextxy(30,getmaxy()-50,"The location doesn't exist");
        getch();
    }
    else
    {
        clearfooter();
        outtextxy(30,getmaxy()-50,"Enter data to insert at the location: ");
        if (loc == 1)
        {
            isbg(input());
        }
        else if(loc==count)
        {
            isend(input());
        }
        else
        {
            create(input());
            pthis = pfirst;
            for (int i = 1; i < loc; i++)
            {
                pthis = pthis->pnext;
            }
            ptemp = pthis->pnext;
            ptemp->pprev = pnew;
            pnew->pnext = ptemp;
            pnew->pprev = pthis;
            pthis->pnext = pnew;
        }
        clearfooter();
        displaymodule();
        outtextxy(0,getmaxy()-50,"Data successfully added, Press Enter to continue...");
        getch();
    }
}

/* -------------------------------------------END FUNCTIONS FOR INSERTION--------------------------------------------------*/


/* -------------------------------------------START FUNCTIONS FOR DELETION--------------------------------------------------*/

// 1. delete node form beginning
void delbeg()
{
    string dat;
    if (empty() == 1)
    {
        ptemp = pfirst->pnext;
        dat=to_string(pfirst->data);
        clearfooter();
        outtextxy(0,getmaxy()-50,"The deleted data is: ");
        outtextxy(530,getmaxy()-50, const_cast<char*>(dat.c_str()));
        free(pfirst);
        pfirst = ptemp;
        pfirst->pprev = NULL;
        count--;
        getch();
    }
}

// 2. delete node from the end
void delend()
{
    string dat;
    if (empty() == 1)
    {
        ptemp = plast->pprev;
        dat=to_string(plast->data);
        clearfooter();
        outtextxy(0,getmaxy()-50,"The deleted data is: ");
        outtextxy(530,getmaxy()-50, const_cast<char*>(dat.c_str()));
        free(plast);
        ptemp->pnext = NULL;
        plast = ptemp;
        count--;
        getch();
    }
}

// 3. function to delete specified node
void delsp()
{
    clearfooter();
    string dat;
    outtextxy(0,getmaxy()-50, "Enter the loc to delete: ");
    loc=input();
    if (loc > count)
    {
        clearfooter();
        outtextxy(30,getmaxy()-50,"The location doesn't exist, Press any key to continue...");
        getch();
    }
    else
    {
        if (loc == 1)
        {
            delbeg();
        }
        else if (loc == count)
        {
            delend();
        }
        else
        {
            pthis = pfirst;
            for (int i = 1; i < loc; i++)
            {
                pthis = pthis->pnext;
            }
            ptemp1 = pthis->pnext;
            ptemp = pthis->pprev;
            ptemp->pnext = ptemp1;
            ptemp1->pprev = ptemp;
            dat=to_string(pthis->data);
            clearfooter();
            outtextxy(0,getmaxy()-50,"The deleted data is: ");
            outtextxy(530,getmaxy()-50, const_cast<char*>(dat.c_str()));
            free(pthis);
            count--;
            getch();
        }
    }

}

/* ----------------------------------------------END FUNCTIONS FOR DELETION--------------------------------------------------*/


/* ----------------------------------------------START FOOTER SECTION--------------------------------------------------*/

void insertion()
{
    char getins;
    cleardevice();
    displaymodule();
    // insertion page graphics
    //.............................................................
    setfillstyle(1,14);
    bar(0,70,getmaxx(),80);
    bar(0,getmaxy()-80,getmaxx(),getmaxy()-70);
    settextstyle(4,0,5);
    outtextxy(getmaxx()/2-420,20,"Doubly Linked List Insertion");
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"1. At The Beginning");
    outtextxy(430,getmaxy()-50,"2. At The End");
    outtextxy(830,getmaxy()-50,"3. Before Node");
    outtextxy(1230,getmaxy()-50,"4. After Node");
    outtextxy(getmaxx()-150,30,"0. Exit");
    //.................................................................
    getins=getch();
    switch(getins)
    {
    case '1': // insertion from beginning
            {
                clearfooter();
                settextstyle(4,0,2);
                outtextxy(30,getmaxy()-50,"Enter data to insert at the beginning: ");
                isbg(input());
                clearfooter();
                displaymodule();
                setcolor(RGB(179, 254, 254));
                outtextxy(0,getmaxy()-50,"Data successfully added, Press any key to continue...");
                setcolor(WHITE);
                getch();
            }
        break;
    case '2': // insertion from end
            {
                clearfooter();
                settextstyle(4,0,2);
                outtextxy(30,getmaxy()-50,"Enter data to insert at the end: ");
                isend(input());
                clearfooter();
                displaymodule();
                setcolor(RGB(179, 254, 254));
                outtextxy(0,getmaxy()-50,"Data successfully added, Press any key to continue...");
                setcolor(WHITE);
                getch();
            }
        break;

    case '3': // insertion in specified position
        issp();
        break;

    case '4': // insertion beginning of node
        isspe();
        break;

    case '0': // go back to main menu
        break;
    }
    mmenu();
}

void deletion()
{
    char getins;
    cleardevice();
    displaymodule();
    // Deletion page graphics
    //.............................................................
    setfillstyle(1,14);
    bar(0,70,getmaxx(),80);
    bar(0,getmaxy()-80,getmaxx(),getmaxy()-70);
    settextstyle(4,0,5);
    outtextxy(getmaxx()/2-420,20,"Doubly Linked List Deletion");
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"1. From The Beginning");
    outtextxy(430,getmaxy()-50,"2. From The End");
    outtextxy(830,getmaxy()-50,"3. At Specified Location");
    outtextxy(getmaxx()-150,30,"0. Exit");
    //.................................................................
    getins=getch();
    switch(getins)
    {
    case '1': // deletion from beginning
        delbeg();
        break;

    case '2': // deletion from end
        delend();
        break;

    case '3': // Deletion in specified position
        delsp();
        break;

    case '0': // go back to main menu
        break;
    }
    mmenu();
}


void searching()
{
    string cnum;
    int inp, num=0;
    display_position=1;
    clearheader();
    clearfooter();
    settextstyle(4,0,5);
    outtextxy(getmaxx()/2-420,20,"Doubly Linked List Searching");
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"Enter data to search");
    inp=input();
    pthis=pfirst;
    setfillstyle(1,14);
    for (int i = 0; i < count; i++)
    {
        if(pthis->data==inp)
        {
            highlight(display_position);
            num++;
            cnum=to_string(num);
        }
        pthis=pthis->pnext;
        display_position++;
    }
    clearfooter();
    if(num==0)
    {
        outtextxy(30,getmaxy()-50,"No node found with given data");
    }
    else
    {
        outtextxy(30,getmaxy()-50,"No of node found is :: ");
        outtextxy(350,getmaxy()-50,const_cast<char*>(cnum.c_str()));
    }
    getch();
}

void sorting()
{
    cout<<"inside sorting"<<endl;
    int arrdata[20],temp,numb=0;
    clearheader();
    clearfooter();
    settextstyle(4,0,5);
    outtextxy(getmaxx()/2-420,20,"Doubly Linked List Sorting");
    settextstyle(4,0,2);
    outtextxy(30,getmaxy()-50,"Press any key to sort data...");
    getch();
    // fetching data of the node into array

     pthis = pfirst;
    for (int i = 0; i < count; i++)
    {
        arrdata[i]=pthis->data;
        pthis = pthis->pnext;
        numb++;
    }

    for(int i=0;i<count;i++)
    {
        //cout<<"inside loop of i"<<endl;
       for(int j=0; j<count-i-1;j++)
       {
           //cout<<"inside loop of j"<<endl;
           if(arrdata[j]>arrdata[j+1])
           {
            // cout<<"true condition"<<endl;
               temp=arrdata[j];
               arrdata[j]=arrdata[j+1];
               arrdata[j+1]=temp;
               // delete all the previous node
               {
                   pthis=pfirst;
                   for(int d=0;d<numb;d++)
                   {
                       ptemp=pthis->pnext;
                       free(pthis);
                       delay(10);
                       pthis=ptemp;
                       count--;
                   }
                   pfirst=NULL;
               }
               {
                   for (int c=0;c<numb;c++)
                   {
                       isend(arrdata[c]);
                       delay(10);
                   }
               }
               delay(5000);
               displaymodule();
           }
       }
    }
}

void displaymodule()
{
    int sd;
    display_position=1;
    string ppp,ddd,nnn,ttt;
    pthis = pfirst;
    clearbody();
    settextstyle(4,0,2);
    if(pfirst==NULL)
    {
        outtextxy(100,300,"CREATE YOUR FIRST NODE");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            stringstream sp,sn,st;// make the function which directly converts pointer to string in simple function
            sp << hex << reinterpret_cast<std::uintptr_t>(pthis->pprev);
            ppp=sp.str();
            sd=pthis->data;
            ddd=to_string(sd);
            sn << hex << reinterpret_cast<std::uintptr_t>(pthis->pnext);
            nnn=sn.str();
            st << hex << reinterpret_cast<std::uintptr_t>(pthis);
            ttt=st.str();
            if(ppp=="0")
            {
                ppp="NULL";
            }
            if(nnn=="0")
            {
                nnn="NULL";
            }
            nodbox(display_position,ppp,ddd,nnn,ttt);
            pthis = pthis->pnext;
            display_position++;
        }
    }
}

int main()
{
    initwindow(getmaxwidth(),getmaxheight(),"Linked List");
    mmenu();
    return 0;
}

