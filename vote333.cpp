
#include<iostream>
#include <string>


using namespace std;
static int i=0;
static int n;

class info
{
    protected:
    static string candis[25];
    int voter_id[50];
    string voter_name[50];
    string voter_surname[50];
    string voter_phone[50];
    string voter_password[50];
    int voter_check[50];
    static int votecount[25];
};

string info::candis[25];
int info::votecount[25];

class intface
{
    protected:
    void interface1();
    void interface2();
};

class voter:protected info,virtual public intface
{
    protected:
    void check_required();
    void voter_registration();
};

class vote:protected voter
{
    protected:
    void voter_login();
    void cast_vote(); 
};

class officer:protected info,virtual public intface
{
    private:
    string vigilance_password="#Good@Officer";
    string entered_password="";
    protected:
    void vote_count();
    void vigilance_officer();
    void candi_entry();
};

class menu:protected vote,protected officer
{
    public:
    void main_menu();
};

void intface::interface1()
{
    cout<<"\n\t\t\t|===============================================|";
    cout<<"\n\t\t\t|=====       ONLINE ELECTION SYSTEM       ======|";
    cout<<"\n\t\t\t|=====            C++ PROJECT             ======|";
    cout<<"\n\t\t\t|===============================================|";
    cout<<"\n";
}

void intface::interface2()
{
    cout<<"\n\t\t\t|===============================================|";
    cout<<"\n\t\t\t|=====    WELCOME TO ELECTIONS - 2022     ======|";
    cout<<"\n\t\t\t|===============================================|";
    cout<<"\n";
}

void voter::check_required()
{
    int noo=0;
    for(noo=0;noo<n;noo++)
    {
        voter_check[noo]=0;
    }
    getc;
}

void voter::voter_registration()
{
    system("cls");
    interface1();
    interface2();
    static int x=0;
    static int id=3458889;

    check_required();
    cout<<"\n\t\t Your voter id is "<<id;
    cout<<"\n\t\t Please enter the voter id alloted to you: ";
    cin>>voter_id[i];
    cout<<"\n\t\t Enter your first name: ";
    cin>>voter_name[i];
    cout<<"\n\t\t Enter your last name: ";
    cin>>voter_surname[i];
    cout<<"\n\t\t Enter your phone number: ";
    cin>>voter_phone[i];
    cout<<"\n\t\t Enter your password: ";
    cin>>voter_password[i];
    cout<<"\n\t\t You have successfully completed the registration!!!";
    voter_check[i] = 1;
    i++;
    id++;

    fflush(stdin);
    getchar();
}

void vote::voter_login()
{
    system("cls");
    int choice_voter;
    do
    {
        system("cls");
        interface1();
        interface2();
        cout<<"\n\t\t\t|===============================================|";
        cout<<"\n\t\t\t|=====            |VOTER MENU|            ======|";
        cout<<"\n\t\t\t|===============================================|";
        cout<<"\n";
        cout<<"\n\t\t If you are a new voter please register yourself first by selecting choice 2";
        cout<<"\n\t\t 1. Cast your vote";
        cout<<"\n\t\t 2. Voter registration";
        cout<<"\n\t\t 3. Back";
        cout<<"\n\t\t Please enter your choice:";
        cin>>choice_voter;

        switch(choice_voter)
        {
            case 1: cast_vote();break;
            case 2: voter_registration();break;
            case 3: cout<<"\n Home page";system("cls");break;
            default: cout<<"\n Kindly give a valid Input!";
        }
    }while(choice_voter!=3);
    fflush(stdin);
}

void vote::cast_vote()
{
    system("cls");
    interface1();
    interface2();
    int choice;
    int var;
    int hi=0,ji=0;
    int hii=0;
    string passwerd;
    cout<<"\n\t\t Enter your voter id : ";
    cin>>var;
    for(hi=0,ji=0;hi<i || ji<=i;hi++,ji++)
    {
        if(var==voter_id[hi])
        {
            do
            {
                cout<<"\n\t\t Enter your password: ";
                cin>>passwerd;
                if(voter_password[hi]==passwerd)
                {
                    if(n!=0)
                    {
                        if(voter_check[hi]==1)
                        {
                            cout<<"\n\t\t Voter first name : "<<voter_name[hi];
                            cout<<"\n\t\t Voter last name : "<<voter_surname[hi];
                            cout<<"\n\t\t Voter phone number : "<<voter_phone[hi];
                            cout<<"\n\n\t\t ### Please choose your Candidate ####";
                            for(int i=0;i<n;i++)
                            {
                                cout<<"\n\t\t"<<i+1<<". "<<candis[i];
                            }
                            cout<<"\n\n\t\t Input your choice (1 - "<<n<<" ) : ";
                            cin>>choice;
                            votecount[choice-1]++;
                            voter_check[hi]++;
                        }
                        else
                        {
                            cout<<"\n\t\t Sorry you have already voted!!!";
                        }
                        hii=0;
                    }
                    else
                    {
                        cout<<"\n\t\tVoting Not Allowed! Contact Vigilante officer!";
                    }
                }
                else
                {
                    cout<<"\n\t\tYou have entered the password incorrectly!!!";
                    cout<<"\n\t\t Please re-enter the password correctly.....";
                    hii++;
                    break;
                }
            }while(hii!=0 && hii<=3);
            break;
        }
        if(ji==i)
        {
            cout<<"\n\t\t Sorry the voter id does not exist!!!";
            break;
        }
    }
    cout<<"\n\t\tThank you for your Participation!";
    fflush(stdin);
    getchar();
}

void officer::vote_count()
{
    system("cls");
    interface1();
    interface2();
    cout<<"\n\t\t ##### Voting Statics ####";
    for(int i=0;i<n;i++)
    {
        cout<<"\n\t\t"<< candis[i]<<  "                "<<votecount[i];   
    }
    fflush(stdin);
    getchar();
}

void officer::vigilance_officer()
{
    system("cls");
    interface1();
    interface2();
    char ch;

    cout<<"\n\t\t MASTER KEY : ";
    cin>>entered_password;

    if(vigilance_password==entered_password)
    {
        int choice_officer=0;
        do
        {
            system("cls");
            interface1();
            interface2();
            cout<<"\n\t\t\t|===============================================|";
            cout<<"\n\t\t\t|======          |OFFICER MENU|           ======|";
            cout<<"\n\t\t\t|===============================================|";
            cout<<"\n";
            cout<<"\n\t\t 1. Find Vote Count";
            cout<<"\n\t\t 2. Enter Candidates";
            cout<<"\n\t\t 3. Back";

            cout<<"\n\t\t Please enter your choice : ";
            cin>>choice_officer;

            switch(choice_officer)
            {
                case 1: vote_count();break;
                case 2: candi_entry();system("cls");break;
                case 3: cout<<"\n Home page";system("cls");break;
                default: cout<<"\n Kindly give a valid Input!";
            }
      }while(choice_officer!=3);
    }
    else
    {   system("cls");
        cout<<"\n\t\t Please renter the password correctly";
    }
    fflush(stdin);
}

void officer::candi_entry()
{  
    system("cls");
    interface1();
    interface2();
    int n1,p;
    cout<<"\n\t\tEnter Number of Parties:" ;
    cin>>n1;
    n=n+n1;
    for(p=i;p<n;p++)
    {
        cout<<"\n\t\tParty "<<p+1<<" name :";
        cin>>candis[p];
    }
    cout<<"\n\t\tParties Updated Successfully!";
    
    i=p;
    fflush(stdin);
    getchar();
}

void menu::main_menu()
{
    system("cls");

    int i;
    int choice;

    while(1)
    {
        interface1();
        interface2();
        cout<<"\n\t\t\t--------------------------------------------------";
        cout<<"\n\t\t\t--------              LOGIN               --------";
        cout<<"\n\t\t\t--------------------------------------------------";
        cout<<"\n\t\t\t-------        1. Vigilance officer        -------";
        cout<<"\n\t\t\t-------             2. Voter               -------";
        cout<<"\n\t\t\t-------             3. Exit                -------";
        cout<<"\n\t\t\t--------------------------------------------------";
        cout<<"\n\t\t\tPlease enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: vigilance_officer();break;
            case 2: voter_login();break;
            case 3: cout<<"\n Session ended";exit(0);break;
            default: system("cls");cout<<" Kindly give a valid Input!\n ";break;
        }
    }
    fflush(stdin);
    getchar();
}

int main()
{
    menu m;
    m.main_menu();
    return 0;
}