#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<TIME.h>
#include<math.h>

using namespace std;

char fileACC[]="ACC.TXT", loginFile[25], call[10];
int Day, Month, Year, Hour, Min, Sec;
long int date, Time, alarm=5000;
char wish[20], alarm_name[20]="NULL";

void time()
{
  time_t currentTime;
  struct tm *localTime;

  time( &currentTime );                   // Get the current time
  localTime = localtime( &currentTime );  // Convert the current time to the local time

   Day    = localTime->tm_mday;
   Month  = localTime->tm_mon + 1;
   Year   = localTime->tm_year + 1900;
   Hour   = localTime->tm_hour;
   Min    = localTime->tm_min;
   Sec    = localTime->tm_sec;

  date= Year*10000 + Month*100 + Day;
  Time= Hour*100 + Min;
}

void start()
{
	system("cls");
	char a;
	cout<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t00000000000000000000          0000000      0000000   000000   00000         000000000000000000000000\n"
		<<"\t00000000000000000000          0000000      0000000   000000   00000         000000000000000000000000\n"
		<<"\t000000000000000000000000  0000000000  0000  000000    0000    000000000  000000000000000000000000000\n"
		<<"\t000000000000000000000000  0000000000  0000  000000    0000    000000000  000000000000000000000000000\n"
		<<"\t000000000000000000000000  0000000000  0000  000000  0  00  0  000000000  000000000000000000000000000\n"
		<<"\t000000000000000000000000  0000000000  0000  000000  0  00  0  000000000  000000000000000000000000000\n"
		<<"\t000000000000000000000000  0000000000  0000  000000  00    00  000000000  000000000000000000000000000\n"
		<<"\t000000000000000000000000  0000000000  0000  000000  00    00  000000000  000000000000000000000000000\n"
		<<"\t000000000000000000000000  000000  000      000  00  000  000  00  00        00  00000000000000000000\n"
		<<"\t000000000000000000000000  000000  000      000  00  000  000  00  00        00  00000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"\t0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n"
		<<"                                       Click Enter to start....";
	a=getch();
	if(a!='\r')
		start();
}

class ACC
{
 int password;


 protected:

 void passwordSelector()
 {
  int n;
  do
  {
   n=rand()%1000;
  }while(n<100||n==passwordEditor(n));
  password=n;
  for(int i=1; i<=5; i++)
     {
      system("cls");
      cout<<"This is your 3-digit password.\nRemember it.\nIt will disappear in "<<6-i<<" seconds.\n";
      cout<<password;
      Sleep(1000);
     }
  system("cls");
 }

 int passwordEditor(int pw)
 {
  int n;
  ACC acc;
  ifstream ob;
  ob.open(fileACC);
  while(ob.read((char*)&acc, sizeof(acc)))
  {
  	if(pw==acc.pass())
  	   return pw;
  }
  return 0;
 }

 void usernameSelector()
 {
  int flag=0;
  ACC acc;
  char tempFile[20];

  cout<<"Enter an Username-\n(The username must be of one word\nStarting with an alphabet can have digits\nNO SPACES)\n";
  cin>>tempFile;
 
  //cout<<"Hi";
 
  ifstream ob;
  ob.open(fileACC);
  while(ob.read((char*)&acc, sizeof(acc)))
  {
   //ob.read((char*)&acc, sizeof(acc));
   if(strcmp(acc.userName,tempFile)==0)
     {
      flag=1;
      //cout<<"Invalid username!!!!\nEnter another username-\n";
      break;
     }
  }

  if(flag==1)
  {
   cout<<"This username is already occupied!!!!\n";
  // gets(userName);
   usernameSelector();
  }
  else
   strcpy(userName,tempFile);

  ob.close();
 }

 public:

 char userName[20], userFileName[25], gender[10];

 void createACC()
 {
  int ch;
  usernameSelector();
  strcpy(userFileName,userName);
  strcat(userFileName,".TXT");
  cout<<"What should I call you?\n"
      <<"Boss       => Press 1\n"
      <<"Sir        => Press 2\n"
      <<"Madam      => Press 3\n"
      <<"Mam        => Press 4\n"
      <<"By my name => Press 5\n"
	  <<"=> ";
  cin>>ch;
  switch(ch)
  {
	case 1:
		strcpy(gender,"Boss");
		break;

	case 2:
		strcpy(gender,"Sir");
		break;

	case 3:
		strcpy(gender,"Madam");
		break;

	case 4:
		strcpy(gender,"Mam");
		break;
		
	case 5:
		strcpy(gender,userName);
		break;
  }
  passwordSelector();
  ofstream ob(userFileName);
  ob.close();
  
 }


 void useACC()
 {
	int p, flag=0;
	char temp[20];
	ifstream fin(fileACC);
	ACC a;
	cout<<"Enter your username please\n =>";
	cin>>temp;
	while(!fin.eof())
	{
	    fin.read((char*)&a,sizeof(a));
		if(strcmp(temp,a.userName)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nInvalid Username!!!!!!\n";
		useACC();
	}
	else
	{
		do
		{
			char a;
			int i;
			p=0;
			cout<<"Enter the password please\n =>";
			for(i=1; i<=3; i++)
			{
				a=getch();
				p=p*10+a-48;
				cout<<"*";
			}
//			cin>>p;
		system("cls");
		}while(p!=a.pass());

	}

	strcpy(loginFile,a.userFileName);
	strcpy(call,a.gender);
//	a.disp();
//    chats();
 }


 int pass()
 {
  return password;
 }

 void disp()
 {
    cout<<"Username =>       "<<userName<<endl
	    <<"User File Name => "<<userFileName<<endl
    	<<"Password =>       "<<password<<endl;
 }

};

void help()
{
	cout<<"\n\nFor introduction                  => intoduction / introduce yourself / what is your name?"
		<<"\nFor wishsing                      => good morning / good afternoon / good evening / etc"
		<<"\nFor playing games                 => play games / games"
		<<"\nFor time & date                   => time / date / year / day / month"
		<<"\nFor alarm                         => alarm / set alarm"
		<<"\nFor calculator                    => calculate / calculator"
		<<"\nFor praising me                   => good / fantastic / wonderful"
		<<"\nFor reminder                      => read reminder / write reminder / create task / show task"
		<<"\nWhile vieing reminder (other way) => all / today / recent / month / week\n";
}

void creator()
{
	cout<<"\n\nThe name of my maker, creator, father, inventor and everything is SHivam Chanda\n";
}

void signin()
{
 fstream ob;
 system("cls");
 ob.open(fileACC, ios::app);
 if(!ob)
 {
  cout<<"I think its my first time here.\n";
 }
 ACC a;
 a.createACC();
 ob.write((char*)& a, sizeof(a));
 //getch();
}

void Alarm()
{
	if(alarm<=Time&&alarm+5>=Time)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl
		    <<"\t\t\t\t\t\t"
		    <<alarm_name<<endl<<endl
		    <<"\t\t\t\t"
		    <<"Alarm!!! Alarm!!! Alarm!!!"<<endl<<endl
			<<"\t\t\t\t\t\tTime is "
			<<Hour<<":"<<Min<<endl;
		getch();
		alarm=5000;
		strcpy(alarm_name,"NULL");
		system("cls");
	}
	
}

void calculator()
{
	int cont;
	do{
	
	int ch,a,b,fact=1;
	cout<<"Calculator-\n"<<endl
	    <<"Addition         => 1\n"
	    <<"Substraction     => 2\n"
	    <<"Multiplication   => 3\n"
	    <<"Division         => 4\n"
	    <<"Permutation      => 5\n"
	    <<"Remainder        => 6\n"
	    <<"Exponential      => 7\n=>";
	cin>>ch;
	switch(ch)
	{
		case 1:
			//int a,b;
			cout<<"\nEnter two numbers-\n";
			cin>>a>>b;
			cout<<"\nSum= "<<a+b;
			break;
		case 2:
			//int a,b;
			cout<<"\nEnter two numbers-\n";
			cin>>a>>b;
			cout<<"\nDifference= "<<a-b;
			break;
		case 3:
			//int a,b;
			cout<<"\nEnter two numbers-\n";
			cin>>a>>b;
			cout<<"\nProduct= "<<a*b;
			break;
		case 4:	
			//int a,b;
			int choice;
			cout<<"Integer=> 1\n"
			    <<"Decimal=> 2\n=>";
			cin>>choice;
			if(choice==1)
			{
			cout<<"\nEnter dividend-\n";
			cin>>a;
			cout<<"Enter divisor-\n";
			cin>>b;
			cout<<"\nQoutient= "<<a/b;
		    }
		    else
		    {
		    	long double A, B;
		    	cout<<"\nEnter dividend-\n";
			    cin>>A;
			    cout<<"Enter divisor-\n";
			    cin>>B;
			    cout<<"\nAnswer= "<<A/B;
			}
			break;
		case 6:
			//int a,b;
			cout<<"\nEnter dividend-\n";
			cin>>a;
			cout<<"Enter divisor-\n";
			cin>>b;
			cout<<"\nRemainder= "<<a%b;
			break;
		case 5:
			//int fact=1;
			cout<<"Enter a number-\n";
			cin>>a;
			for(int i=2; i<=a; i++)
			    fact*=i;
			cout<<"Permutation= "<<fact;
			break;
		case 7:
			//int a, b;
			cout<<"Enter a number- \n";
			cin>>a;
			cout<<"Enter the exponent- \n";
			cin>>b;
			cout<<"Answer= "<<pow(a,b);
			break;
	}
	cout<<"\nDo you want to continue?\nYes   =>   1\nNo   =>   0\n=>";
	cin>>cont;
	}while(cont);
}

void wishing()
{
 if(Hour<12)
  strcpy(wish, "Good Morning");
 else if(Hour<17&&Hour>=12)
  strcpy(wish, "Good Afternoon");
 else if(Hour>=17)
  strcpy(wish, "Good Evening");
}

struct tags
{
	char tag[30];
	int frequency;
};

struct Reminder
{

 long int date;
 char sub[30], description[100];
};

void reminder()
{
	Reminder r;
	ifstream fin(loginFile);
	while(fin.read((char*)&r, sizeof(r)))
	if(date==r.date || date/100==r.date/100 || (r.date<=date-7 && r.date>=date+7))
	{
		system("cls");
		cout<<"\n\n\n\t\t Today's Reminder-\n"
			<<"\n\nDate         - "<<r.date%100<<"/"<<(r.date/100)%100<<"/"<<r.date/10000
		    <<"\n\nSubject      - "<<r.sub
		    <<"\n\nDescription  -\n"<<r.description<<endl<<r.date<<"\t"<<date;
		getch();
	}
	
}

 void r_input()
 {
 	Reminder r;
 	char a;
 	fstream ob;
 	ob.open(loginFile, ios::app);
 	
 	system("cls");
 	
  cout<<"\nEnter the date of the event-\nFormat(yyyymmdd)\n=> ";
  cin>>r.date;
  cout<<"Enter the subject of that event(Within 30 characters)\n=> ";
  for(int i=0; i<100;)
  {
  	a=getch();
  	if(a=='\r')
  	{
  		cout<<a; i++;
  		r.sub[i]='\0';
  		break;
	}
	else if(a=='\b')
	{
		cout<<a; i--;
	}
	else
	{
		cout<<a; i++;
		r.sub[i]=a;	
	}
  }  //cin>>r.sub;
  cout<<"Give a short description of that event(Within 100 characters)\n=> ";  
  for(int i=0; i<100; )
  {
  	a=getch();
  	if(a=='\r')
  	{
  		cout<<a; i++;
  		r.description[i]='\0';
  		break;
	}
	else if(a=='\b')
	{
		cout<<a;
		i--;
	}
	else
	{
		cout<<a; i++;
		r.description[i]=a;	
	}
  }//cin>>r.description;
    Sleep(1);
  cout<<endl;
  ob.write((char*)&r,sizeof(r));
 }
 
void read_reminder(Reminder r)
{
	cout<<endl<<"Event date - "<<r.date%100<<"/"<<(r.date/100)%100<<"/"<<r.date/10000<<endl
		<<endl<<"Event subject -\n"<<r.sub<<endl
		<<endl<<"Event description -\n"<<r.description<<endl;
}
 
 void r_read()
 {
 	system("cls");
 	
 	int ch, flag=1;
 	
 	long int Date;
 	
 	char say[20],a;
 	
 	ifstream ob(loginFile);
 	
 	Reminder r;
 	
 	cout<<"\nFind reminder - \n"
 	    <<"1. Date-wise\n"
 	    <<"2. Other way\n=>";
 	cin>>ch;
 	
 	switch(ch)
 	{
 		case 1:
 			cout<<"\nEnter the date (yyyymmdd) of the reminder which you are finding\n=>";
 			cin>>Date;
 			
 			while(ob.read((char*)&r,sizeof(r)))
 			     if(Date==r.date)
 			        {
					 read_reminder(r);
					 flag=0; 
				    }			
			break;
			
		case 2:
			cout<<"\nTry the other way-\n";
			cin>>say;	
			if(strcmpi(say,"today")==0)
			{
			    int choice=1;
				while(ob.read((char*)&r,sizeof(r)) && choice==1)
				      if(date==r.date)
				      {
					    system("cls");
					    read_reminder(r); 
						cout<<endl<<"Continue???\n1. Yes\n2. No\n=> ";
					    cin>>choice; 
				      }
			    flag=2;
			}
			
			else if(strcmpi(say,"yesterday")==0)
			{
				//while(ob.read((char*)&r,sizeof(r)))
			}
			
			else if(strcmpi(say,"tomorrow")==0)
			{
				//while(ob.read((char*)&r,sizeof(r)))
			}
			
			else if(strcmpi(say,"recent")==0)
			{
				ob.seekg(-1*sizeof(r),ios::end);
				ob.read((char*)&r,sizeof(r));
				read_reminder(r); 
			}
			
			else if(strcmpi(say,"all")==0)
			{
				while(ob.read((char*)&r,sizeof(r)))
				{
					system("cls");
					read_reminder(r);
					cout<<endl<<"Continue???\n1. Yes\n2. No\n=>";
					cin>>flag;
				    //getch();
				}
			}
			
			else if(strcmpi(say,"month")==0)
			{
				int choice=1;
				while(ob.read((char*)&r,sizeof(r)) && choice==1)
				      if(date/100==r.date/100)
				      {
					    system("cls");
					    read_reminder(r); 
						cout<<endl<<"Continue???\n1. Yes\n2. No\n=> ";
					    cin>>choice; 
				      }
			    flag=2;
			}
			else if(strcmpi(say,"week")==0)
			{
				int choice=1;
				while(ob.read((char*)&r,sizeof(r)) && choice==1)
				      if(r.date>=date-7 && r.date<=date+7)
				      {
					    system("cls");
					    read_reminder(r); 
						cout<<endl<<"Continue???\n1. Yes\n2. No\n=> ";
					    cin>>choice; 
				      }
			    flag=2;
			}
    }
 			if(flag==1)
 			{
 				cout<<"No reminder on this day!!!\n";
			}
			
 				int choice;
 				cout<<endl<<"Wanna try it again???\n1. Yes\n2. No\n=> ";
 				cin>>choice;
 				if(choice==1)
 				   r_read();
 			
 }

void num_guess()
{         system("cls");
 int age, x, ch;
 age=x=64;
 cout<<"Guess a number or consider your age and I will guess it within 7 questions\nBut the number considered shouldn't be greater than 127 or less than 1\nLets start.....";
 getch(); system("cls");
 do
 {     system("cls");
  x/=2;
  cout<<"Is your age/number "<<age<<" ?\n"
      <<"If yes \t\t\t press 0\n"
      <<"If greater than "<<age<<"\t press 1\n"
      <<"If less than    "<<age<<"\t press 2\nYour choice => ";
  cin>>ch;
  if(ch==1)
  age+=x;
  else if(ch==2)
  age-=x;
 }while(ch != 0);system("cls");
 cout<<"Your age/number is "<<age<<endl;
 getch();
}

void I_G()
{
	int ch, num, p,k=0; 
	int len=1, n=4;
	start:
		system("cls");
	cout<<"\t\t\tWelcome to The IMPOSSIBLE GAME \n\n1. New Game\n2. Setting\n3. Rules\n4. Exit\n=> ";
	cin>>ch;
	ex:
	switch(ch)
	{
		case 1:
			num = (n+1)*4*len+1;
			for(int i=1; num >= 1 ; i++)
			{
				if(!num)
				{
					ch = 4;
					goto ex;
				}
				cout<<"Computer - "; if(i%2==0) cout<<"  (Turn)";
				cout<<"\n\n\n";
				
				for(int j=1; j<=num; j++)
					cout<<"| "; cout<<"\t- "<<num<<" matchstick(s)";
				
				cout<<"\n\n\nYou - "; if(i%2!=0) cout<<"  (Turn)"; Sleep(2000);
				cout<<"\n\n";
				if(i%2!=0)
				{	P:
					cout<<"Press '0' to resign\n\tor\nPick matchsticks - ";
					cin>>p;
					if(!p)
					{
						ch = 4;
						goto ex;
					}
					else if((p<1 || p>4) && num-p >= 0)
					{
						cout<<"\nWrong Pick!!!\n";
						goto P;
					}
					num -= p;
				}
				
				else
				{
					for(int j=0; ((n+1)*j)+1<num; j++)
					{
						k=j; 
					}
					p=-((n+1)*k+1-num);
					
					num = (n+1)*k+1;
					
					cout<<"I picked up "<<p<<" matchstick(s)";
					if((p<1 || p>n) && num-p >= 0)
					{
						
						break;
					}
				}
				
				cout<<"\n\n\n";
			}
			if(!num)
			{
				ch = 4;
				
				goto ex;
			}	
			
			break;
		case 2:
			int c;
			cout<<"\t\t\t\tSETTINGS\n\n"
				<<"Maximum number of matchsticks you can pick at a time        - "<<n
				<<"\nTotal number of matchsticks                               - "<<(n+1)*4*len+1<<" or ";
			if(len == 1)
				cout<<"Short";
			else if(len == 1)
				cout<<"Medium";
			else if(len == 1)
				cout<<"Long";
				
	//		cout<<"\nSorry the 'change settings' option is not enabled";
			cout<<"\nWould you wish to change it?\n1. Yes\n2. No\n=> ";
			cin>>c;
			if(c==1)
			{
				cout<<"Enter the maximum number of matchsticks you want to pick at a time - ";
				cin>>n; r:
				cout<<"Lenght\n1. Short\n2. Medium\n3. Long\n=> ";
				cin>>len;
				if(len<0 && len>4)
					goto r;
			}
			goto start;
			
		case 4: 
			cout<<"\n\nThank you for playing and giving me the pleasure of winning and insulting yourself.\n\n";
			break;
		case 3:
			cout<<"\t\t\t\tRULES\n\n";
			cout<<"There will be all total of "<<(n+1)*4*len+1<<" matchsticks. \n"; Sleep(2000);
			cout<<"I will ask you to pick ";
			
			for(int i=1; i<n; i++)
				cout<<i<<", ";
				
			cout<<"or "<<n<<" matchstick(s).\n"; Sleep(2000);
			cout<<"After your turn, I will do my picking.\n"; Sleep(2000);
			cout<<"Whoever is forced to pick up the last matchstick loses the game.\n"; Sleep(2000);
			cout<<"And you know what whatever you do you can't beat me, take it as challenge."; Sleep(2000);
				
			getch();
			goto start;
	}
	getch();
}

void games()
{
	
	int ch;
	cout<<"Which game would you like to play"<<endl
	    <<"Age/Number guessing game           => 1"<<endl
		<<"The Impossible Game                => 2"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			num_guess(); 
			cout<<"How has the game???"<<endl;
			break;
			
		case 2:
			I_G();
			cout<<"How has the game???"<<endl;
			break;
	}
}

void intro()
{
 cout<<"\nHello, my name is TOMI, which stands for 'Intelligent Mind Operated Technology'.\n"   ;  Sleep(2000);
 cout<<"I am created by my maker SHivam Chanda."                                   <<endl;         Sleep(2000);
 cout<<"I am your personal assitant."                                              <<endl;         Sleep(2000);
 cout<<"I will keep reminder of your work."                                        <<endl;         Sleep(2000);
 cout<<"Set alarm(until you don't turn me off)."                                   <<endl;         Sleep(2000);
 cout<<"We can have small chats."                                                  <<endl;         Sleep(2000);
 cout<<"We can play small games. \n";
}

void chats()
{
 int  flag=1, j, k, a, b;
 char userSaid[30][30], exe[50][30], c;
 for(int i=0; flag; i++)
 {
  time();
  wishing();
  Alarm();
  if(i==0)
    {
	    reminder();
	    system("cls");
		cout<<endl<<wish<<", "<<call<<", what can I do for you?"<<endl;
    }
  cout<<"\n=> ";
  k=j=0;
  	do
	{
		c=getch();
		cout<<c;
		if(c==' ')
		{
			userSaid[k][j]='\0';
			k++;
			j=0;
		}
		else if(c=='\r')
		{
			userSaid[k][j]='\0';
			k++;
			break;
		}
		else if(c=='\b' && j!=0)
		{
			j--;
		}
		else
		{
			userSaid[k][j]=c;
			j++;
		}
	}while(1);
  
  strcpy(userSaid[k], "EMPTY");
  
  cout<<endl;
  
  for(j=0,k=0; strcmp(userSaid[j],"EMPTY")!=0 && j<30 ;j++)
  {
  	if(strcmpi(userSaid[j],"introduction")==0||strcmpi(userSaid[j],"intro")==0||strcmpi(userSaid[j],"introduce")==0||strcmpi(userSaid[j],"name")==0)
		{
			strcpy(exe[k],"Introduction"); k++;
		}
    
    else if(strcmpi(userSaid[j],"good")==0 || strcmpi(userSaid[j],"morning")==0)
    {	strcpy(exe[k],"Good Morning"); k++;}
  	
  	if(strcmpi(userSaid[j],"good")==0 || strcmpi(userSaid[j],"afternoon")==0)
    	{strcpy(exe[k],"Good Afternoon"); k++;}
    	
    if(strcmpi(userSaid[j],"good")==0 || strcmpi(userSaid[j],"evening")==0)
    	{strcpy(exe[k],"Good Evening"); k++;}
    	
    if(strcmpi(userSaid[j],"good")==0 || strcmpi(userSaid[j],"night")==0)
    	{strcpy(exe[k],"Good Night"); k++;}
    	
    if(strcmpi(userSaid[j],"good")==0 || strcmpi(userSaid[j],"day")==0)
    	{strcpy(exe[k],"Good Day"); k++;}
    	
    if(strcmpi(userSaid[j],"awesome")==0 || strcmpi(userSaid[j],"wonderful")==0 || strcmpi(userSaid[j],"good")==0 || strcmpi(userSaid[j],"pretty")==0 || strcmpi(userSaid[j],"fantastic")==0||strcmpi(userSaid[j],"very")==0)
    	{strcpy(exe[k],"Praising"); k++;}
    	
    if(strcmpi(userSaid[j],"good")==0||strcmpi(userSaid[j],"bye")==0)
    	{strcpy(exe[k],"Bye"); k++;}
    
    else if(strcmpi(userSaid[j],"games")==0||strcmpi(userSaid[j],"game")==0||strcmpi(userSaid[j],"play")==0)
    	{strcpy(exe[k],"Play games"); k++;}
    	
    else if(strcmpi(userSaid[j],"time")==0)
    	{strcpy(exe[k],"Time"); k++;}
    	
    else if(strcmpi(userSaid[j],"date")==0)
    	{strcpy(exe[k],"Date"); k++;}
    	
    else if(strcmpi(userSaid[j],"year")==0)
    	{strcpy(exe[k],"Year"); k++;}
    
    else if(strcmpi(userSaid[j],"month")==0)
    	{strcpy(exe[k],"Month"); k++;}
    	
    if(strcmpi(userSaid[j],"day")==0)
    	{strcpy(exe[k],"Day"); k++;}
    	
    else if(strcmpi(userSaid[j],"hi")==0 || strcmpi(userSaid[j],"hello")==0 || strcmpi(userSaid[j],"TOMI")==0)
    	{strcpy(exe[k],"Hi"); k++;}
    	
    else if(strcmpi(userSaid[j],"thank")==0||strcmpi(userSaid[j],"thanks")==0||strcmpi(userSaid[j],"love")==0)
    	{strcpy(exe[k],"Thanking"); k++;}
    	
    else if(strcmpi(userSaid[j],"alarm")==0)
    	{strcpy(exe[k],"Alarm"); k++;}
    	
    else if(strcmpi(userSaid[j],"calculator")==0||strcmpi(userSaid[j],"calculate")==0)
    	{strcpy(exe[k],"Calculator"); k++;}
    	
    if(strcmpi(userSaid[j],"reminder")==0||strcmpi(userSaid[j],"task")==0||strcmpi(userSaid[j],"see")==0||strcmpi(userSaid[j],"read")==0||strcmpi(userSaid[j],"view")==0||strcmpi(userSaid[j],"show")==0)
    	{strcpy(exe[k],"View Reminder"); k++;}
    	
    if(strcmpi(userSaid[j],"reminder")==0||strcmpi(userSaid[j],"task")==0||strcmpi(userSaid[j],"write")==0||strcmpi(userSaid[j],"create")==0)
    	{strcpy(exe[k],"Create Reminder"); k++;}
    	
    else if(strcmpi(userSaid[j],"creator")==0||strcmpi(userSaid[j],"father")==0||strcmpi(userSaid[j],"inventor")==0||strcmpi(userSaid[j],"maker")==0)
    	{strcpy(exe[k],"Creator"); k++;}
    	
    else if(strcmpi(userSaid[j],"help")==0)
    	{strcpy(exe[k],"Help"); k++;}
    	
    else
    	{strcpy(exe[k],"NULL"); k++;}
  }
  
  strcpy(exe[k],"EMPTY");
//  cout<<"\n\n\n\n";
//  for(a=0; strcmpi(exe[a],"EMPTY")!=0; a++)
//  	cout<<exe[a]<<" ";
//  cout<<"\n\n\n\n";
  tags t[30], temp;
  
  for(j=0, k=0; strcmpi(exe[j],"EMPTY")!=0 && j<30 ; j++)
  {
  	if(strcmp(exe[j],"NULL")!=0)
	{
		b=1;
		if(k)
		{
		for(a=0; a<k; a++)
		{
			if(strcmp(t[a].tag,exe[j])==0)
			{
				t[a].frequency++; b=0;
			}
		}
		if(b)
		{
			strcpy(t[k].tag, exe[j]);
			t[k].frequency=1;
			k++;
		}
		}
		else
		{
			strcpy(t[k].tag, exe[j]);
			t[k].frequency=1;
			k++;
		}
	}	
  }
  
//    cout<<"\n\n\n\n";
//  for(a=0; a<k; a++)
//  	cout<<t[a].tag<<" ";
//  cout<<"\n\n\n\n";
  
  if(!k) {b=-1; goto ONE;}
  
  else if(k==1) {b=0; goto ONE;}
  
  for(a=0; a<k; a++)
  {
  	for(b=a+1; b<k; b++)
  	{
  		if(t[a].frequency<t[b].frequency)
  		{
  			temp = t[a];
  			t[a] = t[b];
  			t[b] = temp;
		}
	}
  }
  
  for(b=0; b<k; b++)
  {
  	if ((strcmpi(t[b].tag , "Good Morning")==0||strcmpi(t[b].tag , "Good Afternoon")==0||strcmpi(t[b].tag , "Good Evening")==0||strcmpi(t[b].tag , "Good night")==0||strcmpi(t[b].tag , "Good day")==0||strcmpi(t[b].tag , "bye")==0||strcmpi(t[b].tag , "Create Reminder")==0||strcmpi(t[b].tag , "View Reminder")==0)&& t[b].frequency>1)
  		goto ONE;
  }
  
  cout<<"What do want/said/asked ?\n";
  
  for(a=0; a<k; a++)
  {
  	cout<<a+1<<". "<<t[a].tag<<endl;
  }
  
  cout<<"\nChoose any one from it => ";
  cin>>b; b--;
  ONE:
  if(strcmpi(t[b].tag , "Introduction")==0)
  {
  	intro();
  }
  
  else if(strcmpi(t[b].tag , "alarm")==0)
  {
     	int ch=0;
     	if(strcmp(alarm_name,"NULL")!=0)
     	{
     		cout<<"An alarm is already set with\n"
     		    <<"Name = "<<alarm_name<<endl
     		    <<"Time = "<<alarm<<endl
     		    <<"If you want to overwrite this press 1\n If not then press 2\n";
     		cin>>ch;
		}
		if(ch==1||ch==0)
		{
     	cout<<"Current time :: "<<Hour<<":"<<Min<<endl
     	    <<"Enter Alarm Name                 - ";
     	gets(alarm_name);
     	cout<<"Enter Alarm Time (format => hhmm)- ";
		cin>>alarm;
	    }  	
  }
  
  else if(strcmpi(t[b].tag , "Good Morning")==0)
  {
	    if(Hour<12)
	     cout<<wish<<", "<<call<<endl;
	    else
	     cout<<call<<", I think you are making some mistake.\nThe time is "<<Hour<<":"<<Min
		 <<endl<<"You must say, \""<<wish<<"\""<<endl;  	
  }
  
  else if(strcmpi(t[b].tag , "Good Afternoon")==0)
  {
	    if(Hour>=12&&Hour<17)
	     cout<<wish<<", "<<call<<endl;
	    else
	     cout<<call<<", I think you are making some mistake.\nThe time is "<<Hour<<":"<<Min
		 <<endl<<"You must say, \""<<wish<<"\""<<endl;  	
  }
  
  else if(strcmpi(t[b].tag , "Good Evening")==0)
  {
	    if(Hour>=17)
	     cout<<wish<<", "<<call<<endl;
	    else
	     cout<<call<<", I think you are making some mistake.\nThe time is "<<Hour<<":"<<Min
		 <<endl<<"You must say, \""<<wish<<"\""<<endl;  	
  }
  
  else if(strcmpi(t[b].tag , "Good night")==0)
  {
	     if(Hour>=17)
	    {
	    	cout<<"Good night, "<<call<<endl;
	    	break;
		}
		 
		 cout<<call<<", I think you are making some mistake.\nThe time is "<<Hour<<":"<<Min
		 <<endl<<"You must say, \""<<wish<<"\""<<endl;
  }
  
  else if(strcmpi(t[b].tag , "Good day")==0)
  {
    	if(Hour<17)
	    {
	    	cout<<"Have a good day, "<<call<<endl;
	    	break;
		}
		 
		 cout<<call<<", I think you are making some mistake.\nThe time is "<<Hour<<":"<<Min
		 <<endl<<"You must say, \""<<wish<<"\""<<endl;
  }
  
  else if(strcmpi(t[b].tag , "praising")==0)
  {
  	cout<<"Thank you, "<<call<<endl;
  }
  
  else if(strcmpi(t[b].tag , "bye")==0)
  {
  	cout<<"Good Bye, "<<call<<endl; break;
  }
  
  else if(strcmpi(t[b].tag , "play games")==0)
  {
  	games();
  }
  
  else if(strcmpi(t[b].tag , "time")==0)
  {
  	cout<<"The time is -"<<endl<<Hour<<":"<<Min<<":"<<Sec<<endl;
  }
  
  else if(strcmpi(t[b].tag , "date")==0)
  {
     	cout<<"The date is -"<<endl
     	    <<Day<<"/"<<Month<<"/"<<Year<<endl;
  }
  
  else if(strcmpi(t[b].tag , "year")==0)
  {
     	cout<<"The year is -"<<endl
     	    <<Year<<endl;
  }
  
  else if(strcmpi(t[b].tag , "month")==0)
  {
     	cout<<"The month is -"<<endl
     	    <<Month<<endl;
  }
  
  else if(strcmpi(t[b].tag , "day")==0)
  {
     	cout<<"The day is -"<<endl
     	    <<Day<<endl;
  }
  
  else if(strcmpi(t[b].tag , "Hi")==0)
  {
  	cout<<wish<<", "<<call<<", what can I do for you?"<<endl;
  }
  
  else if(strcmpi(t[b].tag , "Thanking")==0)
  {
  	cout<<"Welcome, "<<call<<". I would like to help you more."<<endl;
  }
  
  else if(strcmpi(t[b].tag , "Calculator")==0)
  {
  	calculator();
  }
  
  else if(strcmpi(t[b].tag , "View Reminder")==0)
  {
  	r_read();
  }
  
  else if(strcmpi(t[b].tag , "Create Reminder")==0)
  {
  	r_input();
  }
  
  else if(strcmpi(t[b].tag , "help")==0)
  {
  	help();
  }
  
	else if(strcmpi(t[b].tag , "Creator")==0)
  {
  	creator();
  }
  
  else
	cout<<"I din't get that "<<call<<". Try something else....    (Do you need help??? Then type help!!!)"<<endl;

 }
}


int main()
{
	start();
 system("cls");

 int ch;
 ACC a;

 cout<<"What can I do for you?\n"
     <<"1.Log in to your existing account\n"
     <<"2.Create a new account\n=>";
 cin>>ch;

 if(ch==1)
   {
   	a.useACC();
   	chats();
   } 

 else if(ch==2)
 	{
	 	signin();
	 	main();
	}
 else if(ch==420)
 {
 	system("cls");
 	a.useACC();
 	if(strcmp(loginFile,"SH.TXT")==0 && strcmp(call,"Sir")==0)
 	{
 		system("cls");
 		cout<<"\t\t\t\tWelcome to Master Control\n";
 		ifstream fin(fileACC); ACC a;
 		while(fin.read((char*)&a,sizeof(a)))
 		{
 			if(strcmp(a.userName,"SH")!=0)
 			{
			cout<<"\n";
 			a.disp();
 			getch();
 		}
		}
	}
	
	else goto EX;
 }

 else
    EX:cout<<"Good bye";
 
 //getch();

 return 0;
}
