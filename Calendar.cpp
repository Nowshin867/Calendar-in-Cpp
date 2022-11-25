#include<bits/stdc++.h>
using namespace std;
class Calendar_Parent {
public:
    int Year;
};
// Sub class inheriting from Base Class(Parent)
class Calendar_Child : public Calendar_Parent {
public:
   string d;
   string t;
   string Event;
};
int dayNumber(int day, int month, int year)
{

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}
string getMonthName(int monthNumber)
{
    string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      };

    return (months[monthNumber]);
}
int numberOfDays (int monthNumber, int year)
{
    // January
    if (monthNumber == 0)
        return (31);

    // February
    if (monthNumber == 1)
    {

        if (year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    // March
    if (monthNumber == 2)
        return (31);

    // April
    if (monthNumber == 3)
        return (30);

    // May
    if (monthNumber == 4)
        return (31);

    // June
    if (monthNumber == 5)
        return (30);

    // July
    if (monthNumber == 6)
        return (31);

    // August
    if (monthNumber == 7)
        return (31);

    // September
    if (monthNumber == 8)
        return (30);

    // October
    if (monthNumber == 9)
        return (31);

    // November
    if (monthNumber == 10)
        return (30);

    // December
    if (monthNumber == 11)
        return (31);
}

void Calendar(int year)
{
    int days;
    int current = dayNumber (1, 1, year);
    for (int i = 0; i < 12; i++)
    {
        days = numberOfDays (i, year);
        printf("\n\t\t\t\t\t ------------%s-------------\n",
               getMonthName (i).c_str());

        printf("\n\t\t\t\t\t  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int k;
        cout<<"\t\t\t\t\t";
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++k > 6)
            {
                k = 0;
                printf("\n\t\t\t\t\t");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }

    return;
}

void Insert(string d,string t,string Event)
{
    try
    {
        fstream file;
        file.open("D:\\SD2\\Input.txt", ios::app | ios::out);
        if(file)
        {
            file<<d<<' '<<t<<' '<<Event<<endl;
            file.close();
        }
        else
        {
            throw 420;
        }
    }
    catch(...)
    {
        cout<<"\n\t\t\t\t\t  Can't access file."<<endl;
    }

}

void Remind_Me(string d,string t)
{
    int cnt=0,flag=0;
    try
    {
        fstream file;
        string word;
        string filename ="D:\\SD2\\Input.txt";
        file.open(filename.c_str());
        if(file)
        {
            while(file >> word)
            {
                if(word==d)
                    cnt++;
                else if(word==t)
                    cnt++;
                else if(cnt==2)
                {
                    flag=1;
                    cout<<"\n\t\t\t\t\t  ---*REMINDER*---  : "<<word<<endl;
                    break;
                }
                else cnt=0;
            }
            file.close();
            if(flag==0)
            {
                cout<<"\n\t\t\t\t\t  NO REMINDER!!!! \n";
            }
        }
        else
        {
            throw 420;
        }
    }
    catch(...)
    {
        cout<<"\n\t\t\t\t\t  Can't access file."<<endl;
    }

}

void Reminder_list()
{

    try
    {
        ifstream ifs;
        string s;
        int i=1;
        ifs.open("D:\\SD2\\Input.txt");
        if(ifs)
        {
            cout<< "\n\t\t\t\t\t\t   *| REMINDER LIST |*" <<endl;
            while (getline (ifs,s))
            {
                cout<< "\n\t\t\t\t\t  "<<i<<". "<<s <<endl;
                i++;
            }
            ifs.close();
        }
        else
        {
            throw 420;
        }
    }
    catch(...)
    {
        cout<<"\n\t\t\t\t\t  Can't access file."<<endl;
    }
}
int menu(void)
{
    int choice;
    do
    {
        cout<<"\n\n\n";
        cout << "\t\t\t                ............................" << endl;
        cout << "\t\t\t                 Choose Options:[1/2/3/4/5]" << endl;
        cout << "\t\t\t                ............................" << endl;
        printf("\n\t\t\t\t\t  Press 1- to See Calendar\n\t\t\t\t\t  Press 2- to Add Remindar\n\t\t\t\t\t  Press 3- to Remind Me\n\t\t\t\t\t  Press 4- to See Reminder List\n\t\t\t\t\t  Press 5- to Exit\n");
        printf("\n\t\t\t\t\tYour choice please... ");
        scanf("%d",&choice);
        if(choice<1||choice>5)
            printf("\n\t\t\t\t\tWrong...Choice again...\n");
    }
    while(choice<1||choice>5);
    return (choice);
}
int main()
{

    system("color b1");
    int choice;
    Calendar_Child obj;
    cout<<"\n\n\n";
    cout << "\n\t\t\t\t\t*-------------------------------*\n";
    cout << "\t\t\t\t\t* ----------------------------- *" << endl;
    cout << "\t\t\t\t\t* | WELCOME TO THE CALENDAR | *" << endl;
    cout << "\t\t\t\t\t* ----------------------------  *" << endl;
    cout << "\t\t\t\t\t*-------------------------------*" << endl;
    cout << "\t\t\t    *Made By : Mahmuda Begum, Nafija Tabassum, Noushin Tabassum*" << endl;
    //cout<<"\t\t**************************---------------------***************************\n";
    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
             cout<<"\n\t\t\t\t\t  Enter a Year :";
             cin>>obj.Year;
             printf ("\n\t\t\t\t\t THE CALENDAR OF : %d\n\n", obj.Year);
             Calendar(obj.Year);
             break;
        case 2:
            printf("\n\t\t\t\tEnter Date(dd/mm/yyyy) and Time(hh:mm) : "); //format Date(12/12/2007 Time(23:01)
            cin>>obj.d>>obj.t;
            printf("\n\t\t\t\tEnter an Event for Reminder : ");
            cin>>obj.Event;
            Insert(obj.d,obj.t,obj.Event);
            break;
        case 3:
            printf("\n\t\t\t\tEnter Date(dd/mm/yyyy) and Time(hh:mm) : "); //format Date(12/12/2007 Time(23:01)
            cin>>obj.d>>obj.t;
            Remind_Me(obj.d,obj.t);
            break;
        case 4:
            Reminder_list();
            break;
        case 5:
            printf("\n\t\t\t\t\tThank You For Visiting OUR CALENDAR...\n");
            break;
        }
    }
    while(choice!=5);
    return 0;
}


