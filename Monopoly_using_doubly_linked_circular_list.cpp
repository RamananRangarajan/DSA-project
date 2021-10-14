#include <windows.h>
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int mx=0;
int my=0;
int con1=0;
int placecount[3];
using namespace std;
COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class board
{
    public:
        char name[10];
        float cost;
        int plcmark;
        int owner;
        int p[3];
        int spcl;
        board *link;
        board *linkb;
}*start;
class players
{
    public:
        float money;
        float debtamt;
        int debt;
        int turnskip;
        players()
        {
            money=100000;
            debtamt=0;
            debt=0;
            turnskip=0;
        }
}playa[3];
void assign()
{
    srand(time(0));
    char nams[35][10];
    strcpy(nams[1],"Russia");
    strcpy(nams[2],"Canada");
    strcpy(nams[3],"China");
    strcpy(nams[4],"U.S.A");
    strcpy(nams[5],"Brazil");
    strcpy(nams[6],"India");
    strcpy(nams[7],"Algeria");
    strcpy(nams[8],"Congo");
    strcpy(nams[9],"U.K");
    strcpy(nams[10],"Mexico");
    strcpy(nams[11],"Libya");
    strcpy(nams[12],"Iran");
    strcpy(nams[13],"Mongolia");
    strcpy(nams[14],"Peru");
    strcpy(nams[15],"Kenya");
    strcpy(nams[16],"France");
    strcpy(nams[17],"Yemen");
    strcpy(nams[18],"Thailand");
    strcpy(nams[19],"Spain");
    strcpy(nams[20],"Sweden");
    strcpy(nams[21],"Iraq");
    strcpy(nams[22],"Oman");
    int i=1,j=1;
    while(i<31)
    {
        board *ptr=new board;
        ptr->link=NULL;
        ptr->linkb=NULL;
        if(start==NULL)
        {
            start=ptr;
        }
        else
        {
            board *temp=start;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=ptr;
            ptr->linkb=temp;
        }
        if(i==30)
        {
            ptr->link=start;
            start->linkb=ptr;
        }
        ptr->p[1]=0;
        ptr->p[2]=0;
        ptr->spcl=0;
        if(i==1)
        {
            strcpy(ptr->name," START ");
            ptr->spcl=i;
            ptr->p[1]=1;
            ptr->p[2]=2;
        }
        else
        if(i==11)
        {
            strcpy(ptr->name,"  CLUB  ");
            ptr->spcl=i;
        }
        else
        if(i==16)
        {
            strcpy(ptr->name," G.HOUSE");
            ptr->spcl=i;
        }
        else
        if(i==26)
        {
            strcpy(ptr->name,"  JAIL  ");
            ptr->spcl=i;
        }
        else
        if(i==14)
        {
            strcpy(ptr->name," I.TAX ");
            ptr->spcl=i;
        }
        else
        if(i==29)
        {
            strcpy(ptr->name," W.TAX ");
            ptr->spcl=i;
        }
        else
        if(i==3)
        {
            strcpy(ptr->name," CHANCE ");
            ptr->spcl=i;
        }
        else
        if(i==18)
        {
            strcpy(ptr->name," C.CHEST");
            ptr->spcl=i;
        }
        else
        {
            strcpy(ptr->name,nams[j]);
            ptr->cost=((rand()%22)+1)*1000;
            j++;
        }
        ptr->owner=0;
        i++;
    }
}
int paydebt(int con,float &amt,int compul3)
{
    int paydet(int,float &mamt,int,int);
    void disp();
    char cho1='y';
    system("cls");
    disp();
    cout<<"You owe the bank (as shown above)"<<amt;
    if(compul3==0)
    {
        cout<<"\nAre u sure u wanna pay ur debt?(y/n)";
        cin>>cho1;
    }
    else
    {
        cho1='y';
    }
    if(cho1=='y')
    {
        float res1=0;
        if(compul3==0)
        {
            res1=paydet(con,amt,0,1);
        }
        else
        {
            paydet(con,amt,1,1);
        }
        system("cls");
        disp();
        if(res1==1)
        {
            cout<<"Debt repaid.";
            playa[con].debt=0;
            playa[con].debtamt=0;
            system("pause");
            return 1;
        }
        else
        {
            cout<<"Sorry ur debt cant be paid with ur current financial condition.";
            return 0;
        }
    }
    else
    {
        system("cls");
        disp();
        cout<<"As u wish.U can payback later(before the deadline)";
    return 0;
    }
}
int paydet(int con,float &mamt,int compul6,int dop)
{
    int borrowmon(int,float);
    void disp();
    float liquidate(int);
    void defeat(int);
    if(mamt<=playa[con].money)
    {
        system("cls");
        disp();
        playa[con].money-=mamt;
        mamt=0;
        cout<<"Payment successful\n";
        system("pause");
        return 1;
    }
    else
    {
        char cho34='y';
        if(compul6==0)
        {
            cout<<"\nInsufficient funds.Do u wanna go through with the transaction?(y/n)";
            cout<<"\n";
            cin>>cho34;
        }
        if(cho34=='y')
        {
            cout<<"\n$"<<playa[con].money;
            if(dop==1)
            {
                mamt-=playa[con].money;
                playa[con].money=0;
                if(playa[con].money==0)
                {
                    cout<<" is available but u still need \n"<<mamt;
                    system("pause");
                }
                char cho5='y';
                if(compul6==0)
                {
                    cout<<"\nDo u wanna pay it now by selling a property?(y/n)";
                    cin>>cho5;
                }
                if(cho5=='y')
                {
                    float sucl=liquidate(con);
                    if(sucl==-1)
                    {
                        if(compul6==1)
                        {
                            cout<<"\nYou r bankrupt";
                            defeat(con);
                        }
                        else
                        {
                            cout<<"\nPayment unsuccessful";
                        }
                        return -1;
                    }
                    else
                    if(sucl>=mamt)
                    {
                        mamt-=sucl;
                        return 1;
                    }
                    while(sucl<mamt)
                    {
                        system("cls");
                        disp();
                        mamt-=sucl;
                        cout<<"$"<<sucl<<" has been reduced from ur required amount";
                        char cho9='y';
                        if(compul6==0)
                        {
                            cout<<"\nbut one property was not enough.Do u wanna sell another 1?(y/n)";
                            cin>>cho9;
                        }
                        if(cho9=='y')
                        {
                            sucl=liquidate(con);
                        }
                        else
                        {
                            return -1;
                        }
                        if(sucl==-1)
                        {
                            if(compul6==1)
                            {
                                defeat(con);
                            }
                            return -1;
                        }
                    }
                    mamt-=sucl;
                    return 1;
                }
                else
                {
                    cout<<"\nPayment unsuccessful";
                    return -1;
                }
            }
            else
            if(dop==2)
            {
                cout<<" is not enough to pay ur rent.";
                system("pause");
                system("cls");
                disp();
                playa[con1].money+=playa[con].money;
                mamt-=playa[con].money;
                playa[con].money=0;
                cout<<"You have to borrow $"<<mamt;
                int resb=borrowmon(con,mamt);
                if(resb==-1)
                {
                    cout<<"You have to clear ur debt first.";
                    paydebt(con,playa[con].debtamt,1);
                }
                playa[con].money-=mamt;
                playa[con1].money+=mamt;
                cout<<"\nPayment successful\n";
                system("pause");
                return 1;
            }
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
float liquidate(int con)
{
    system("cls");
    int flag=-1;
    cout<<"\nPlayer "<<con<<" is to sell one of their properties.\n";
    system("pause");
    cout<<"\nEach of player "<<con<<"'s properties will be displayed one by one.if u want to sell the currently displayed property, enter 'y' else enter 'n'";
    char lcho='n';
    board *temp=start->link;
    while(lcho=='n')
    {
        if((temp->spcl==1)&&(flag==-1))
        {
            return -1;
        }
        if(temp->owner==con)
        {
            flag=1;
            cout<<"\nDo u wanna sell "<<temp->name<<" ?(y/n)";
            cin>>lcho;
            if(lcho=='y')
            {
                temp->owner=0;
                return temp->cost*(3/4);
            }
        }
        temp=temp->link;
    }
}
void defeat(int con)
{
    system("cls");
    cout<<"Player 1 owns:"<<placecount[1]<<" places";
    cout<<"\nPlayer 2 owns:"<<placecount[2]<<" places";
    cout<<"\nPlayer "<<con<<" loses :(";
    cout<<"\nPlayer "<<con1<<" wins :)\n";
    system("pause");
    exit(1);
}
void plc()
{
    for(int i=1;i<3;i++)
    {
        board *temp=start->link;
        while(temp->spcl!=1)
        {
            if(temp->owner==i)
            {
                placecount[i]++;
            }
            temp=temp->link;
        }
    }

}
void strtpay(int con)
{
    void defeat(int);
    void disp();
    char lose='n';
    system("cls");
    disp();
    cout<<"You have completed a journey round the world!!! $5000 has been added.";
    cout<<"\n Do u wanna forfeit?(y/n)";
    cin>>lose;
    if(lose=='y')
    {
        defeat(con);
    }
    playa[con].money+=5000;
    if(playa[con].debt==1)
    {
        cout<<"\nYou still have 2 more round to play your debt";
        playa[con].debt++;
        char cho10='n';
        cout<<"\nDo u wanna pay ur debt?(y/n)";
        cin>>cho10;
        if(cho10=='y')
        {
            paydebt(con,playa[con].debtamt,0);
        }
    }
    else
    if(playa[con].debt==2)
    {
        cout<<"\nThis is ur last chance to pay ur debt";
        playa[con].debt++;
        char cho10='n';
        cout<<"\nDo u wanna pay ur debt?(y/n)";
        cin>>cho10;
        if(cho10=='y')
        {
            paydebt(con,playa[con].debtamt,0);
        }
     }
        else
        if(playa[con].debt==3)
        {
            paydebt(con,playa[con].debtamt,1);
        }
}
void traverse(int d,int con,int m=0)
{
    void plcopt(int,int);
    int d1=d;
    int s=0;
    void disp();
    board *temp=start;
    while(temp->p[con]!=con)
    {
        temp=temp->link;
    }
    temp->p[con]=0;
    system("cls");
    disp();
    if(m==-1)
    {
        while(d!=0)
        {
            temp=temp->linkb;
            d--;

        }
        temp->p[con]=con;
        system("cls");
        disp();
        cout<<"Player "<<con<<" has moved "<<d1<<" steps";
        cout<<" back\n";
        system("pause");
        system("cls");
    }
    else
    {
        while(d!=0)
        {
            temp=temp->link;
            if(temp->spcl==1)
                s=1;
            d--;
        }
        temp->p[con]=con;
        system("cls");
        disp();
        cout<<"Player "<<con<<" has moved "<<d1<<" steps";
        cout<<" forward\n";
        system("pause");
        system("cls");

    }
    if(s==1)
    {
        strtpay(con);
    }
    plcopt(con,d);




}
void plcopt(int con,int d)
{
    srand(time(0));
    void disp();
    system("cls");
    disp();
    int paydet(int,float &mamt,int,int);
    board *temp=start->link;
    while(temp->spcl!=1)
    {
        if(temp->p[con]==con)
        {
            break;
        }
        temp=temp->link;
    }
    if(temp->spcl==0)
    {
        cout<<"You've come to "<<temp->name;
        if(temp->owner==0)
        {
            float price=temp->cost;
            char ch39='y';
            cout<<"\nDo u wanna buy it?(y/n)";
            cin>>ch39;
            if(ch39=='y')
            {
                if(paydet(con,price,0,1)==1)
                {
                    temp->owner=con;
                    cout<<"\n"<<temp->name<<" now belongs to player "<<con;
                }
                else
                {
                    cout<<"\nSorry u cant buy this place due to lack of funds\n";
                    system("pause");
                }
            }
        }
        else
        if(temp->owner==con)
        {
            cout<<"\nThe place already belongs to u.\n";
            system("pause");
            cout<<"\nNo actions can be done";
        }
        else
        if(temp->owner==con1)
        {
            float rent=temp->cost/10;
            cout<<"\nThe place already belongs to ur opponent.";
            cout<<"\nYou have to pay ur rent of $"<<temp->cost/10<<"\n";
            system("pause");
            paydet(con,rent,1,2);
            playa[con1].money+=temp->cost/10;
            cout<<"$"<<temp->cost/10<<" has been added to ur account player "<<con1<<"\n";
            system("pause");
        }
    }
    else
    if(temp->spcl==11)
    {
        float club=500;
        cout<<"You've arrived at the club.\n";
        system("pause");
        cout<<"\nYou have to pay $500.\n";
        system("pause");
        paydet(con,club,1,1);
    }
    else
    if(temp->spcl==26)
    {
        char jcho='p';
        cout<<"You r in jail.\nYou can either PAY $1000 or STAY in jail for 3 turns.(p/s)\n";
        cin>>jcho;
        float jmon=1000;
        if(jcho=='p')
        {
            if(paydet(con,jmon,0,0)==1)
            {
                cout<<"\nYou r free to go\n";
                system("pause");
            }
            else
            {
                cout<<"\nSorry.Insufficient funds,u have to stay for 3 turns.\n";
                playa[con].turnskip+=3;
                system("pause");
            }
        }
        else
        {
            cout<<"\nAs u wish.U have to stay for 3 turns.\n";
            playa[con].turnskip+=3;
            system("pause");
        }
    }
    else
    if(temp->spcl==16)
    {
        cout<<"You r at the guest house.\nCollect $500 and relax for one turn.\n";
        playa[con].money+=500;
        playa[con].turnskip++;
        system("pause");
    }
    else
    if(temp->spcl==14)
    {
        cout<<"You have to pay ur income taxes.";
        cout<<"\n";
        system("pause");
        float itax=placecount[con]*100;
        paydet(con,itax,1,1);
    }
    else
    if(temp->spcl==29)
    {
        cout<<"You have to pay ur wealth taxes.";
        cout<<"\n";
        system("pause");
        float wtax=playa[con].money*(1/100);
        paydet(con,wtax,1,1);
    }
    else
    if(temp->spcl==1)
    {
    ;
    }
    else
    if(temp->spcl==3)
    {
        if(d%2==0)
        {
            int r=rand()%10+1;
            cout<<"\nYou've come to chance by rolling an even number so move "<<r<<" steps back.\n";
            system("pause");
            traverse(r,con,-1);
        }
        else
        {
            int r=rand()%10+1;
            cout<<"\nYou've come to chance by rolling an odd number so move "<<r<<" steps forward.\n";
            system("pause");
            traverse(r,con);
        }
    }
    else
    if(temp->spcl==18)
    {
        if(d%2==0)
        {
            int r=rand()%10+1;
            float a=1000;
            cout<<"\nYour warehouse burned down.U lost $"<<a<<"\n";
            system("pause");
            paydet(con,a,1,1);
            cout<<"\n";
            system("pause");
        }
        else
        {
            int r=rand()%10+1;
            cout<<"\nYou've won the lottery for $\n"<<1000<<"\n";
            playa[con].money+=1000;
            system("pause");
        }
    }
    cout<<"\n";
    system("pause");
}
void boxp(int x,int y,board *t)
{
    if(t->spcl==0)
    {
        gotoxy(x+1,y+1);
        cout<<t->name;
        gotoxy(x+1,y+2);
        if(t->owner!=0)
            cout<<"Owner:P"<<t->owner;
        else
            cout<<"$"<<t->cost;
        gotoxy(x+1,y+3);
        if(t->p[1]==1)
            cout<<" p"<<t->p[1];
        if(t->p[2]==2)
            cout<<" p"<<t->p[2];
        gotoxy(x+1,y+4);
        if(t->owner!=0)
            cout<<"R:$"<<0.3*t->cost;
    }
    else
    {
        gotoxy(x+1,y+2);
        cout<<t->name;
        gotoxy(x+1,y+3);
        if(t->p[1]!=0)
            cout<<" p"<<t->p[1];
        if(t->p[2]!=0)
            cout<<" p"<<t->p[2];
    }
    gotoxy(x,y);
    for(int i=1;i<=4;i++)
    {
        gotoxy(x,y+i);
        cout<<"|";
    }
    gotoxy(x+1,y);
    for(int i=0;i<8;i++)
        cout<<"_";
    for(int i=1;i<=4;i++)
    {
        gotoxy(x+9,y+i);
        cout<<"|";
    }
    gotoxy(x+1,y+4);
    for(int i=0;i<8;i++)
        cout<<"_";

}
void stats(int x,int y,int con)
{
    if(con==2)
    {
        y=7;
    }
    gotoxy(x+11,y+6);
    cout<<"Player "<<con<<"'s stats:";
    gotoxy(x+32,y+7);
    cout<<"Funds:$"<<playa[con].money;
    gotoxy(x+62,y+7);
    cout<<"Debt amount:$"<<playa[con].debtamt;
    gotoxy(x+20,y+9);
    cout<<"Player "<<con<<"'s properties:";
    gotoxy(x+40,y+10);
    board *temp=start->link;
    int k=0,l=1;
    while(temp->spcl!=1)
    {
        if(temp->owner==con)
        {
            cout<<temp->name<<",";
            k++;
            if(k==8)
                gotoxy(x+20,y+11);
            if(k==20)
                gotoxy(x+20,y+12);
        }
        temp=temp->link;
    }
}
void disp()
{
    int x=0,y=0;
    mx=x,my=y;
    gotoxy(x+50,y+5);
    cout<<"Scoreboard";
    board *temp=start;
    stats(x,y,1);
    stats(x,y,2);
    for(int i=1;i<=30;i++)
    {
        boxp(x,y,temp);
        if(i<11)
        {
            x+=10;
        }
        if(i<16&&i>=11)
        {
            y+=5;
        }
        if(i>=16&&i<26)
        {
            x-=10;
        }
        if(i>=26&&i<31)
        {
            y-=5;
        }
        temp=temp->link;
    }
    plc();
    gotoxy(0,30);
}
void displaydice(int dice,int pos3)
{
    if(pos3==1)
    {
        if (dice == 1)
        {
            gotoxy(mx+45,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+45,my+21);
            cout<<"|       |"<<endl;
            gotoxy(mx+45,my+22);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+45,my+23);
            cout<<"|       |"<<endl;
            gotoxy(mx+45,my+24);
            cout<<"+-------+"<<endl;
        }
        else if(dice == 2)
        {
            gotoxy(mx+45,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+45,my+21);
            cout<<"|       |"<<endl;
            gotoxy(mx+45,my+22);
            cout<<"|  @  @ |"<<endl;
            gotoxy(mx+45,my+23);
            cout<<"|       |"<<endl;
            gotoxy(mx+45,my+24);
            cout<<"+-------+"<<endl;
        }
        else if(dice == 3)
        {
            gotoxy(mx+45,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+45,my+21);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+45,my+22);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+45,my+23);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+45,my+24);
            cout<<"+-------+"<<endl;
        }
        else if (dice == 4)
        {
            gotoxy(mx+45,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+45,my+21);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+22);
            cout<<"|       |"<<endl;
            gotoxy(mx+45,my+23);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+24);
            cout<<"+-------+"<<endl;
        }
        else if (dice == 5)
        {
            gotoxy(mx+45,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+45,my+21);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+22);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+45,my+23);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+24);
            cout<<"+-------+"<<endl;
        }
        else if (dice == 6)
        {
            gotoxy(mx+45,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+45,my+21);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+22);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+23);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+45,my+24);
            cout<<"+-------+"<<endl;
        }
    }
    else
    {
         if (dice == 1)
        {
            gotoxy(mx+64,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+64,my+21);
            cout<<"|       |"<<endl;
            gotoxy(mx+64,my+22);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+64,my+23);
            cout<<"|       |"<<endl;
            gotoxy(mx+64,my+24);
            cout<<"+-------+"<<endl;
        }
        else if(dice == 2)
        {
            gotoxy(mx+64,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+64,my+21);
            cout<<"|       |"<<endl;
            gotoxy(mx+64,my+22);
            cout<<"|  @  @ |"<<endl;
            gotoxy(mx+64,my+23);
            cout<<"|       |"<<endl;
            gotoxy(mx+64,my+24);
            cout<<"+-------+"<<endl;
        }
        else if(dice == 3)
        {
            gotoxy(mx+64,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+64,my+21);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+64,my+22);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+64,my+23);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+64,my+24);
            cout<<"+-------+"<<endl;
        }
        else if (dice == 4)
        {
            gotoxy(mx+64,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+64,my+21);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+22);
            cout<<"|       |"<<endl;
            gotoxy(mx+64,my+23);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+24);
            cout<<"+-------+"<<endl;
        }
        else if (dice == 5)
        {
            gotoxy(mx+64,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+64,my+21);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+22);
            cout<<"|   @   |"<<endl;
            gotoxy(mx+64,my+23);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+24);
            cout<<"+-------+"<<endl;
        }
        else if (dice == 6)
        {
            gotoxy(mx+64,my+20);
            cout<<"+-------+"<<endl;
            gotoxy(mx+64,my+21);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+22);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+23);
            cout<<"| @   @ |"<<endl;
            gotoxy(mx+64,my+24);
            cout<<"+-------+"<<endl;
        }
    }
    gotoxy(0,30);
}
int borrowmon(int con,float bormon)
{
 void disp();
 system("cls");
 disp();
 if(playa[con].debt==0)
 {
  playa[con].money+=bormon;
  playa[con].debtamt=bormon;
  playa[con].debt++;
  cout<<"\nU now owe the bank \n"<<bormon<<'\n';
  system("pause");
  return 1;
 }
 else
 {
  cout<<"\nU already owe the bank.So u cant borrow more\n";
  system("pause");
  return -1;
 }
}
int main()
{
    srand(time(0));
    int d1,d2,d;
    int pos3=0;
    assign();
    int tempcon=0;
    for(int con=1;con<=2;con++)
    {
    if(con==1)
    {
        con1=2;
    }
    else
    if(con==2)
    {
        con1=1;
    }
    if(playa[con].turnskip!=0)
    {
        playa[con].turnskip--;
        tempcon=con;
        con=con1;
        con1=tempcon;
    }
    system("cls");
    disp();
    cout<<"Player"<<con<<"'s turn\n";
    system("pause");
    system("cls");
    disp();
    cout<<"Press any key to roll the die\n";
    system("pause");
    system("cls");
    disp();
    pos3=1;
    pos3=1;
    d1=(rand()%6)+1;
    displaydice(d1,pos3);
    pos3=2;
    d2=(rand()%6)+1;
    displaydice(d2,pos3);
    d=d1+d2;
    system("pause");
    system("cls");
    disp();
    traverse(d,con);
    system("cls");
    disp();
    char cho0='n';
    float boramt=0;
    cout<<"Do u wanna borrow?(y/n)\n";
    cin>>cho0;
    if(cho0=='y')
    {
        cout<<"\nHow much do u wanna borrow?\n";
        cin>>boramt;
        borrowmon(con,boramt);
    }
    system("cls");
    disp();
    if(con==2)
    {
        con=0;
    }
    continue;
 }
    disp();
    return 0;
}
