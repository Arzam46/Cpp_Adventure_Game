		    	#include<iostream>//Preprocessor directives/Library for input and output
				#include<iomanip>//Preprocessor directives/Library for setw() function
				#include<conio.h>//Preprocessor directives/Library for getch() function and string
				#include<time.h>//Preprocessor directives 
				#include<random>//Preprocessor directives
				#include<windows.h>
				#include<fstream>
				using namespace std;//Standard
				HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
				void login();//User defined function
				void line();//User defined function 
				void starline();//User defined function
				void loading();//User defined function 
				void front();//User defined function 
				void food();//User defined function 
				void drink();//User defined function 
				void menu();//User defined function 
				void price();//User defined function
				void gamemenu();//User defined function
				void game1();//User defined function 
				void game2();//User defined function
				void game3(); //User defined function
				void bill();//User defined function 
				int x=0;//Global variable declaration and initialization
				int y=0;//Global variable declaration and initialization
				int z=0;//Global variable declaration and initialization
void pacman();
void pacmanmoves();
void ghost(int num);
void ghostmoves(int num);
void print(char pg,short x,short y);
void print(string pg,short x,short y);
void maze();
short pacmanx=2,pacmany=2,pacmanX,pacmanY;
short ghostx[3]={1,48,48};
short ghosty[3]={13,1,13};
short ghostX[3];
short ghostY[3];
int collision[3]={0,0,0};
int direction[3]={1,2,3};
int ghostup(int num);
int ghostdown(int num);
int ghostright(int num);
int ghostleft(int num);
void game3();
char pkey='d';
int score;
char arr[15][50]={  {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
				    	{'#',' ',' ',' ',' ',' ',' ','.','.','.',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						{'#',' ',' ',' ',' ','.','.','.',' ',' ',' ',' ','#',' ',' ','.','.','.','.','.','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#','#','#','#',' ',' ',' ','#'},
						{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','.','#',' ',' ',' ','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ','#','.','.','.',' ',' ',' ','#'},
						{'#',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','.','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#','#',' ',' ',' ','#'},
						{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ','#'},
						{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','.','.','.','.','#',' ',' ',' ',' ',' ',' ','#',' ','#','#','#','#',' ',' ',' ','#'},
						{'#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','.','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						{'#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
						{'#','.','.',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#'},
						{'#','.','.','.',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','.','#',' ',' ',' ','#','#','#','#','#','#','#','#',' ',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ',' ','#','.','.',' ',' ',' ','#'},
						{'#',' ',' ','.',' ',' ','#','#','#','#','.','.','.','.','.',' ','.','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','.','.','.','.','.','#'},
						{'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ','.','.','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','.','#'},
						{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

				int main()//Main function
				{//Main function body starts
					login();//User defined function calling
					loading();//User defined function calling
					system("cls");
				front();//User defined function calling
				cout<<"Enter any key to continue";//Console output
				getch();
				system("cls");//Command to clear screen
				int a;//Variable declaration
				int b;//Variable declaration
				do//Do while loop
				{//Do body starts
				cout<<"1)Dinner"<<endl;//Console output
				cout<<"2)Games"<<endl;//Console output
				cout<<"Enter your choice: ";//Console output
				cin>>a;//Console input
				system("cls");//Command to clear screen
				switch(a)//Decision making statement
				{//Decision making statement body starts
				case 1:
					loading();
					system("cls");
				menu();//User defined function calling
				break;
				case 2:
					loading();
					system("cls");
				gamemenu();
				}//Decision making statement body starts
				}//Do body ends
				while(a!=1&&a!=2);//while loop
				return 0;
				}//Main function body ends
void login()
{
	string temp;//Temporary string
	char key;//Variable declaration
	int length;//Variable declaration
	string a={"Arzam46"};//String
	string b={"arzam20021014"};//String
	string username;//String
	string password;//String
	while(true)//
	{
	cout<<"Enter username: ";
	getline(cin,username);
	cout<<"Enter password: ";
	while(true)
	{
		key=getch();
		if(key==13)
		{
			break;
		}
		else if(key==8&&password!="")
		{
		cout<<key<<" "<<key;
		temp=password;
		password="";
		length=temp.length();
		for(int i=0;i<length-1;i++)
		{
			password=password+temp[i];	
		}	
		}
		else if(key!=8)
		{
			cout<<"*";
			password=password+key;		
		}
	}
	if(username==a&&password==b)
	{
		system("cls");
		cout<<setw(63);
		starline();
		cout<<"\t\t\t\t\t\t\t\t\tACCESS GRANTED"<<endl;
		cout<<setw(63);
		starline();
		Sleep(2000);
		system("cls");
		break;
	}
	else 
	{
		system("cls");
		cout<<setw(63);
		line();
		cout<<"\t\t\t\t\t\t\t\t\tACCESS DENIED"<<endl;
		password="";
		cout<<setw(63);
		line();	
		Sleep(2000);
		system("cls");
	}
}
}
				void line()//User defined function defination
				{//User defined function body starts
				for(int i=0;i<37;i++)
				{
				cout<<"-";//Console output
				}
				cout<<endl;//Console output
				}//User defined function body ends
				void starline()//User defined function defination
				{//User defined function body starts
				int i=0;//Variable declaration and initialization
				while(i<37)
				{
				cout<<"*";//Console output
				i++;
				}
				cout<<endl;//Console output for line ending
				}//User defined function body ends
				void loading()
				{
					char a=219;
	 				cout<<"\t\t\t\t\t\t\t\t\t    LOADING"<<endl;
					cout<<"    \t\t\t\t\t\t\t\t[\t\t\t\t]\r  \t\t\t\t\t\t\t\t[";
					for(int i=0;i<31;i++)
	{
					cout<<a;
					Sleep(100);
	}		
				}
				void front()//User defined function defination
				{//User defined function body starts
				cout<<setw(63)<<endl;
				starline();//User defined function calling
				cout<<"\t\t\t\t\t\t\t\t    WELCOME TO CHARSI TIKKAH"<<endl;//Console output
				cout<<setw(63)<<endl;
				starline();//User defined function calling
				}//User defined function body ends
				void menu()//User defined function defination
				{//User defined function body starts
				cout<<"\t\t\t\t\t\t\t\t\t      MENU"<<endl;//Console output
				food();//User defined function calling
				system("cls");
				cout<<"\t\t\t\t\t\t\t\t\t      MENU"<<endl;//Console output
				drink();//User defined function calling
				}//User defined function body ends
				void gamemenu()
				{//User defined function body starts
					int b;//Variable declaration
				while(true)
				{
					cout<<"\t\t\t\t\t\t\t\t\t     GAMES"<<endl;
					line();
					starline();
				cout<<"1)Destination reacher game"<<endl//Console output
				<<"2)Number guessing game"<<endl//Console output
				<<"3)Pacman game"<<endl;//Console output
				line();
				cout<<"4)Dinner"<<endl
				<<"5)Exit"<<endl;
				line();
				starline();
				cout<<"Enter your choice: ";//Console output
				cin>>b;//Console input
				system("cls");//Command to clear screen
				if(b==1)//Decision making statement
				{//Decision making statement body starts
				loading();
				system("cls");
					game1();//User defined function calling
				}
				else if(b==2){
				system("cls");
						loading();
						system("cls");
				
					game2();//User defined function calling
				
			}
					else if(b==3)
					{
					char a='y';
			        	loading();
						system("cls");
						game3();
						system("cls");
				}
				else if(b==4)
				{
					menu();
					exit(0);
				}
				else if(b==5)
				{
					system("cls");
				bill();
				exit(0);
				}
			else if(b>5)
				cout<<"Enter the correct choice"<<endl;//Console output
				}//Decision making statement body ends
			
				}//User defined function body ends	
				void food()//User defined function defination
				{//User defined function body starts
						struct menu//Structure/Nested structure
					{//Structure body starts
						float aaluchicken;//Structure member
						float chickenkarahi;//Structure member
						float muttonkarahi;//Structure member
						float chickentikka;//Structure member
						float kabab;//Structure member
						float pchickenfajita;//Structure member
						float pchickentikka;//Structure member
						float flammingpasta;//Structure member
						float crunchypasta;//Structure member
						float fries;//Structure member
						float zingerburger;//Structure member
						float shawarma;//Structure member
					};//Structure body ends
					struct meal//Structure/Nested structure
					{//Structure body starts
						menu asian;//Structure member
						menu fastfood;//Structure member
					};//Structure body ends
					meal dinner;//Structure variable
					dinner.asian.aaluchicken=200;//Accessing structure's member and their initialization
					dinner.asian.chickenkarahi=800;//Accessing structure's member and their initialization
					dinner.asian.muttonkarahi=1500;//Accessing structure's member and their initialization
					dinner.asian.chickentikka=200;//Accessing structure's member and their initialization
					dinner.asian.kabab=250;//Accessing structure's member and their initialization
					dinner.fastfood.pchickenfajita=900;//Accessing structure's member and their initialization
					dinner.fastfood.pchickentikka=1000;//Accessing structure's member and their initialization
					dinner.fastfood.flammingpasta=600;//Accessing structure's member and their initialization
					dinner.fastfood.crunchypasta=600;//Accessing structure's member and their initialization
					dinner.fastfood.fries=150;//Accessing structure's member and their initialization
					dinner.fastfood.zingerburger=300;//Accessing structure's member and their initialization
					dinner.fastfood.shawarma=250;//Accessing structure's member and their initialization
					int num;//Variable declaration	
					int quantity;//Variable declaration
					char a='y';//Variable declaration
					char b='n';//Variable declaration
				cout<<setw(30)<<setiosflags(ios::left)<<"ITEM"<<setw(10)<<"PRICE"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				line();//User defined function calling
				starline();//User defined function calling
				cout<<"ASIAN FOOD"<<endl;//Console output
				starline();//User defined function calling
				cout<<setw(30)<<setiosflags(ios::left)<<"1)AALU CHICKEN"<<setw(10)<<"200"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"2)CHICKEN KARAHI"<<setw(10)<<"800"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"3)MUTTON KARAHI"<<setw(10)<<"1500"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"4)CHICKEN TIKKA"<<setw(10)<<"200"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"5)KABAB"<<setw(10)<<"250"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				line();//User defined function calling
				starline();//User defined function calling
				cout<<"Do you want to order from Asian food?(y/n): ";//Console output
				cin>>a;
				if(a=='y')//Decision making statement
				{//Decision making statement body starts
				while(a=='y')
				{
					do{
					cout<<"Enter the number of dish: ";//Console output
					cin>>num;//Console input
					switch(num)//Decision making statement
					{//Decision making statement body starts
						case 1:
							x+=dinner.asian.aaluchicken;
						cout<<setw(30)<<setiosflags(ios::left)<<"AALU CHICKEN"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 2:
							x+=dinner.asian.chickenkarahi;
						cout<<setw(30)<<setiosflags(ios::left)<<"CHICKEN KARAHI"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 3:
							x+=dinner.asian.muttonkarahi;
						cout<<setw(30)<<setiosflags(ios::left)<<"MUTTON KARAHI"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 4:
						x+=dinner.asian.chickentikka;	
						cout<<setw(30)<<setiosflags(ios::left)<<"CHICKEN TIKKA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 5:
							x+=dinner.asian.kabab;
						cout<<setw(30)<<setiosflags(ios::left)<<"KABAB"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						default:
							cout<<"Enter the correct choice "<<endl;
							break;
					}
				}
				while(num>5);
				cout<<"Enter the quantity: ";//Console output
					cin>>quantity;
					if (quantity>0)//Decision making statement
					{//Decision making statement body starts
					x=x*quantity;
					cout<<endl;
					}//Decision making statement body ends
					cout<<"Do you want to order another dish?(y/n): ";
					cin>>a;
				}
				}
				system("cls");
				cout<<"\t\t\t\t\t\t\t\t\t      MENU"<<endl;//Console output
				cout<<setw(30)<<setiosflags(ios::left)<<"ITEM"<<setw(10)<<"PRICE"<<endl;//Console output with setw() function and setiosflag(ios::left)function and setiosflag(ios::left)function that sets left justification flag
				line();//User defined function calling
				starline();//User defined function calling
				cout<<"FAST FOOD"<<endl;//Console output
				starline();//User defined function calling
				cout<<setw(30)<<setiosflags(ios::left)<<"PIZZA:"<<endl;//Console output with setw() function and setiosflag(ios::left)function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"1)CHICKEN FAJITA"<<setw(10)<<"900"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"2)CHICKEN TIKKA"<<setw(10)<<"1000"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"PASTA:"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"3)FLAMMING PASTA"<<setw(10)<<"600"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"4)CRUNCHY PASTA"<<setw(10)<<"600"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"5)FRIES"<<setw(10)<<"150"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"6)ZINGER BURGER"<<setw(10)<<"300"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"7)SHAWARMA"<<setw(10)<<"250"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				line();//User defined function calling
				starline();//User defined function calling
				cout<<"Do you want to order from Fast food?(y/n): ";//Console output
				cin>>a;
				if(a=='y')//Decision making statement
				{//Decision making statement body starts
				do
				{
					cout<<"Enter the number of dish: ";//Console output
					cin>>num;
					switch(num)
					{//Decision making statement body starts
						case 1:
						y+=dinner.fastfood.pchickenfajita;
						cout<<setw(30)<<setiosflags(ios::left)<<"CHICKEN FAJITA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 2:
						y+=dinner.fastfood.pchickentikka;
						cout<<setw(30)<<setiosflags(ios::left)<<"CHICKEN TIKKA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 3:
						y+=dinner.fastfood.flammingpasta;
						cout<<setw(30)<<setiosflags(ios::left)<<"FLAMMING PASTA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 4:
						y+=dinner.fastfood.crunchypasta;
						cout<<setw(30)<<setiosflags(ios::left)<<"CRUNCHY PASTA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 5:
						y+=dinner.fastfood.fries;
						cout<<setw(30)<<setiosflags(ios::left)<<"FRIES"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 6:
						y+=dinner.fastfood.zingerburger;
						cout<<setw(30)<<setiosflags(ios::left)<<"ZINGER BURGER"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 7:
						y+=dinner.fastfood.shawarma;
						cout<<setw(30)<<setiosflags(ios::left)<<"SHAWARMA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
					}
					cout<<"Enter the quantity: ";//Console output
					cin>>quantity;
					if (quantity>0)//Decision making statement
					{//Decision making statement body starts
					y=y*quantity;
					cout<<endl;
					}//Decision making statement body ends
					cout<<"Do you want to order another dish?(y/n): ";//Console output
					cin>>b;//Console input
				}//Do body ends
				while (b!='n');//While loop
				}//Decision making statement body ends
				}//User defined function body ends
				void drink()//User defined function defination
				{//User defined function body starts
						struct drink//Structure
				{//Structure body starts
					    float japple;//Structure member
						float jmango;//Structure member
						float jorange;//Structure member
						float jguava;//Structure member
						float coke;//Structure member
						float dew;//Structure member
						float sprite;//Structure member
				};//Structure body ends
				drink cj;//Structure variable
					cj.japple=250;//Accessing structure's member and their initialization
					cj.jmango=250;//Accessing structure's member and their initialization
					cj.jguava=250;//Accessing structure's member and their initialization
					cj.jorange=250;//Accessing structure's member and their initialization
					cj.coke=150;//Accessing structure's member and their initialization
					cj.dew=150;//Accessing structure's member and their initialization
					cj.sprite=150;//Accessing structure's member and their initialization
					int num;//Variable declaration
					int quantity;//Variable declaration
					char e='y';//Variable declaration
				cout<<setw(30)<<setiosflags(ios::left)<<"ITEM"<<setw(10)<<"PRICE"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				line();//User defined function calling
				starline();//User defined function calling
				cout<<"DRINKS"<<endl;//Console output
				starline();//User defined function calling
				cout<<setw(30)<<setiosflags(ios::left)<<"JUICES:"<<setw(10)<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"1)APPLE"<<setw(10)<<"250"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"2)MANGO"<<setw(10)<<"250"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"3)GUAVA"<<setw(10)<<"250"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"4)ORANGE"<<setw(10)<<"250"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"COLD DRINKS:"<<setw(10)<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"5)COKE COLA"<<setw(10)<<"150"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"6)DEW"<<setw(10)<<"150"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				cout<<setw(30)<<setiosflags(ios::left)<<"7)SPRITE"<<setw(10)<<"150"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
				line();//User defined function calling
				starline();//User defined function calling
				cout<<"Do you want to order from Drinks?(y/n): ";//Console output
				cin>>e;//Console input
				if(e=='y')//Decision making statement
				{//Decision making statement body starts
				while (e=='y')//While loop
				{//While loop body starts
					cout<<"Enter the number of Drink: ";//Console output
					cin>>num;//Console input
						switch(num)//Decision making statement
					{//Decision making statement body starts
						case 1:
						z+=cj.japple;
						cout<<setw(30)<<setiosflags(ios::left)<<"APPLE"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 2:
						z+=cj.jmango;
						cout<<setw(30)<<setiosflags(ios::left)<<"MANGO"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 3:
						z+=cj.jguava;
						cout<<setw(30)<<setiosflags(ios::left)<<"GUAVA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 4:
						z+=cj.jorange;
						cout<<setw(30)<<setiosflags(ios::left)<<"ORANGE"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 5:
						z+=cj.coke;
						cout<<setw(30)<<setiosflags(ios::left)<<"COKE COLA"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 6:
						z+=cj.dew;
						cout<<setw(30)<<setiosflags(ios::left)<<"6)DEW"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
						case 7:
						z+=cj.sprite;
						cout<<setw(30)<<setiosflags(ios::left)<<"SPRITE"<<endl;//Console output with setw() function and setiosflag(ios::left)function that sets left justification flag
						break;
					}//Decision making statement body ends
					cout<<"Enter the quantity: ";//Console output
					cin>>quantity;//Console input
					if (quantity>0)//Decision making statement
					{//Decision making statement body starts
					z=z*quantity;
					cout<<endl;
					}//Decision making statement body ends
					cout<<"Do you want to order another juice/drink?(y/n): ";//Console output
					cin>>e;//Console input
				}
				}//Decision making statement body starts
				system("cls");//Command to clear screen
				char i='y';//Variable declaration
				cout<<"Do you want to play games?(y/n):";//Console output
				cin>>i;//Console input
				if(i=='y')//Decision making statement
				{//Decision making statement body starts
				system("cls");//Command to clear screen
				gamemenu();//User defined function calling
				}//Decision making statement body ends
				else//Decision making statement
				{//Decision making statement body starts
				system("cls");//Command to clear screen
				bill();//User defined function calling
				}//Decision making statement body ends	
				}
				void bill()//User defined function defination
				{//User defined function body starts
				int q=x+y+z;
				ofstream bill;
				bill.open("Bill.txt");
				bill<<" Your Total Bill: "<<q<<endl;
				bill.close();
				cout<<"Your Total Bill is: "<<q<<endl;
				}
				void game1()//User defined function defination
				{//User defined function body starts
				cout<<setw(62)<<endl;
				starline();
					cout<<"\t\t\t\t\t\t\t       WELCOME TO REACHING DESTINATION GAME"<<endl;//Console output
					cout<<setw(62)<<endl;
					starline();
					cout<<"Press any key to continue"<<endl;//Console output
					getch();
				system("cls");//Command to clear screen	
				int a;//Variable declaration
					while(a!=2)
				{
				cout<<"1)Game Instructions"<<endl;//Console output
				cout<<"2)Play game"<<endl;//Console output
				cout<<"Enter your choice: ";
				cin>>a;//Console input
				system("cls");//Command to clear screen
				if(a==1)//Decision making statement 
				{//Decision making statement body starts
						cout<<"Press d to move forward in x-axis"<<endl//Console output
						<<"Press a to move backward in x-axis"<<endl//Console output
						<<"Press w to move forward in y-axis"<<endl//Console output
						<<"Press s to move backward in y-axis"<<endl;//Console output
						cout<<"Enter any key to go back to menu";
						getch();
						system("cls");
			}
		else if(a==2){
		srand(time(0));
		int x=0;//variable declaration
		int y=0;//variable declaration
		char a,n,e,w,s;//variable declaration
		char j='p';//variable declaration
		int i=0;
		do//using do loop
		{	
			srand(time(0));
			cout<<"\t\t\t\t\t\t\t\t\t    LEVEL "<<i+1<<endl;//Console output
			int x=0;//variable declaration
			int y=0;//variable declaration
			char b,w,s,d,a;//variable declaration
			i=i+1;//Airthmatic assignment operator
			int k=rand()%11;
			int l=rand()%11;
			do//nested do while loop
			{//Do loop body starts
				cout<<"Enter the character= ";//console output
				cin>>b;//console input
				//cout<<endl;//line end
				if(b=='d')//decision making statement
				{//Decision making statement body starts
					x++;//increment operator
					cout<<"The new position is: "<<x<<","<<y<<endl;//Console output
					if(k>x)//Decision making statement/Nested if statement
					{
						cout<<"Go forward in x-axis"<<endl;//Console output
					}
					else if(k<x)//Decision making statement/Nested else if statement
					{
						cout<<"Go back x-axis"<<endl;//Console output
					}
					else if (k==x)//Decision making statement/Nested else if statement
					{
						cout<<"You reached correct destination in x-axis\a"<<endl;//Console output
					}
				}	
				else if(b=='a')//Decision making statement
				{
					x--;//decrement operator
					cout<<"The new position is: "<<x<<","<<y<<endl;//console output
					if(k>x)//Decision making statement/Nested if statement
					{
						cout<<"Go forward in x-axis"<<endl;
					}
					else if(k<x)//Decision making statement/Nested else if statement
					{
						cout<<"Go back in x-axis"<<endl;
					}
					else if (k==x)//Decision making statement/Nested else if statement
					{
						cout<<"You reached correct destination in x-axis\a"<<endl;
					}
				}
				else if(b=='w')//Decision making statement
				{
					y++;//Increment operator
					cout<<"The new position is: "<<x<<","<<y<<endl;//console output
					if(l>y)//Decision making statement/Nested if statement
					{
						cout<<"Go forward in y-axis"<<endl;
					}
					else if(l<y)//Decision making statement/Nested else if statement
					{
						cout<<"Go back in y-axis"<<endl;
					}
					else if (l==y)//Decision making statement/Nested else if statement
					{
						cout<<"You reached correct destination in y-axis\a"<<endl;
					}
				}
				else if(b=='s')//Decision making statement
				{//Decision making statement body starts
					y--;//Decrement operator
					cout<<"The new position is: "<<x<<","<<y<<endl;//console output
					if(l>y)//Decision making statement/Nested if statement
					{
						cout<<"Go forward in y-axis"<<endl;
					}
					else if(l<y)//Decision making statement/Nested else if statement
					{
						cout<<"Go back in y-axis"<<endl;
					}
					else if (l==y)//Decision making statement/Nested else if statement
					{
						cout<<"You reached correct destination in y-axis\a";
					}
				cout<<endl;//Line end
				}
			}
			while(x!=k||y!=l);//nested do while loop
			if(x==k&&y==l)//descision making statement
			{//Decision making statement body starts
				
				cout<<"\t\t\t\t\t\t\t\t\t  You are winner \a"<<endl;//console output
			}//Decision making statement body ends
			
			cout<<endl;//line end
			cout<<"Do you want to play level " <<i+1<<" ,press p:";//console output
			cin>>j;//console input
			cout<<endl;//line end
			system("cls");//Command to clear screen
		}
		while(j=='p');//do while loop
		cout<<"\t\t\t\t\t\t\t\t\t      END"<<endl;//Console output
		Sleep(5000);
		system("cls");
		if(j!='p')
		{
			gamemenu();
		}
		system("cls");//Command to clear screen
		break;
				}//Decision making statement body ends
				else if(a>2)
			{
				cout<<"Enter the correct choice"<<endl;
			}
			}
				}
void game2()//User defined function defination
{//User defined function body starts
cout<<setw(62)<<endl;
				starline();
	cout<<"\t\t\t\t\t\t\t\t WELCOME TO NUMBER GUESSING GAME"<<endl;//Console output
	cout<<setw(62)<<endl;
				starline();
	cout<<"Press any key to continue"<<endl;//Console output
	getch();//Get character
	system("cls");//Command to clear screen
	srand(time(0));
	char a='y';//Variable declarartion
	int guessnum;//Variable declarartion
	while(a=='y')//While loop-
	{//While loop body starts
	int tries=0;//Variable declarartion
	int randnum=rand()%101;//Variable declarartion/Random number
	while(guessnum!=randnum)//While loop
{//Nested while loop body starts
	cout<<"Enter the number: ";//Console output
	cin>>guessnum;//Console input
	if(randnum>guessnum)//Decision making statement
	{
		tries++;//Increment operator
		cout<<"Your guessed number is low than the secret number"<<endl;//Console output
	}
	else if(randnum<guessnum)//Decision making statement
	{
		tries++;//Increment operator
		cout<<"Your guessed number is high than the secret number"<<endl;//Console output	
	}
	else if(randnum==guessnum)//Decision making statement
	{
		cout<<"You guessed correctly\a"<<endl;//Console output
	}
}//Nested while loop body ends
	cout<<"You have guessed "<<randnum<<" in "<<tries<<" attempts"<<endl;//Console output
	cout<<"Do you want to play again?(y/n)";//Console output
	cin>>a;//Console input
	system("cls");//Command to clear screen
}//While loop body ends
//User defined function body ends
}
void game3()
{
cout<<setw(62)<<endl;
				starline();
	cout<<"\t\t\t\t\t\t\t\t\t    PAC-MAN GAME"<<endl;//Console output
	cout<<setw(62)<<endl;
				starline();
	cout<<"Press any key to continue"<<endl;//Console output
	getch();//Get character
	system("cls");//Command to clear screen
	maze();//Calling user defined function
	cout<<endl;//Line ending
	srand(time(0));//Seeding time
while(true)	//While loop
{
	pacman();//Calling user defined function
	pacmanmoves();//Calling user defined function
	ghostmoves(0);//Calling user defined function
	ghostmoves(1);//Calling user defined function
	ghostmoves(2);	//Calling user defined function	
}
}
void print(char pg,short x,short y)//User defined function
{
	SetConsoleCursorPosition(hConsole,{x,y});//Command to move cursor to a specific point/function over loading
	cout<<pg;//Console output
}
void print(string pg,short x,short y)//User defined function
{
	SetConsoleCursorPosition(hConsole,{x,y});//Command to move cursor to a specific point/function over loading
	cout<<pg;//Console output
}
void pacman()
{
	print(" ",pacmanX,pacmanY);//Calling user defined function
	print("P",pacmanx,pacmany);//Calling user defined function
}
void pacmanmoves()
{
	if(kbhit())//Command that detect input from keyboard
{
	pkey=getch();//Get character
}
	if(pkey=='w')//Decision making ststement
	{
	if((arr[pacmany-1][pacmanx]==' '))//Decision making ststement
	{	
	pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
	pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmany--;//Decrement
	}
	else if((arr[pacmany-1][pacmanx]=='.'))//Decision making ststement
	{	
	pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
	pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmany--;//Decrement
		score++;//Increment
	}	
	}
	else if(pkey=='s')//Decision making ststement
	{	
	if((arr[pacmany+1][pacmanx]==' '))//Decision making ststement
	{	
	pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
	pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmany++;//Increment
	}
	else if((arr[pacmany+1][pacmanx]=='.'))//Decision making ststement
	{	
	pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
	pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmany++;//Increment
		score++;//Increment
	}
	}
	else if(pkey=='d')//Decision making ststement
	{
		if((arr[pacmany][pacmanx+1]==' '))//Decision making ststement
	{	
		pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
		pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmanx++;//Increment
	}
	else if((arr[pacmany][pacmanx+1]=='.'))//Decision making ststement
	{	
	pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
	pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmanx++;//Increment
		score++;//Increment
	}		
	}
	else if(pkey=='a')//Decision making ststement
	{
		if((arr[pacmany][pacmanx-1]==' '))//Decision making ststement
	{	
		pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
		pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmanx--;//Decrement
	}
	else if((arr[pacmany][pacmanx-1]=='.'))//Decision making ststement
	{	
	pacmanX=pacmanx;//Storing current position into another variable used for presvious position to print space on that place
	pacmanY=pacmany;//Storing current position into another variable used for presvious position to print space on that place
		pacmanx--;//Decrement
		score++;//Increment
	}		
	}
	SetConsoleCursorPosition(hConsole,{1,16});//Command to move cursor to a specific point
		cout<<"Score: "<<score<<endl;//Console output
}
void maze()
{
for(int i=0;i<15;i++)//For loop	
{
	for(int j=0;j<50;j++)//Nested for loop
	{
		cout<<arr[i][j];//Console output
	}
	cout<<endl;//Line end
}
}
void ghost(int num)//User defined function
{
	print(" ",ghostX[num],ghostY[num]);//Calling user defined function
	print("G",ghostx[num],ghosty[num]);//Calling user defined function
}
void ghostmoves(int num)//User defined function
{
	if(ghostx[num]==pacmanx&&ghosty[num]==pacmany)//Decision making ststement
	{
		system("cls");
		cout<<"\t\t\t\t\t\t\t\t\t  GAME OVER";
		Sleep(5000);
		system("cls");
		gamemenu();
	}
	if(collision[num])//Decision making ststement
	{
		direction[num]=(rand()%4)+1;//Random number generation
	}
	switch(direction[num])//Switch stement for decision making
	{
	case 1:
		collision[num]=ghostup(num);//Calling user defined function
			Sleep(100);
			break;
				case 2:
			collision[num]=ghostdown(num);//Calling user defined function
			Sleep(100);
			break;
				case 3:
			collision[num]=ghostright(num);//Calling user defined function
			Sleep(100);
			break;
				case 4:
			collision[num]=ghostleft(num);//Calling user defined function
			Sleep(100);
			break;
			default:
				break;
	}
	ghost(num);//Calling user defined function
}
int ghostup(int num)//User defined function definition
{
	if(arr[ghosty[num]-1][ghostx[num]]==' ')
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghosty[num]--;//Decrement
		return 0;
	}
else if(arr[ghosty[num]-1][ghosty[num]]=='.')
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghosty[num]--;//Decrement
		return 0;
	}
	return 1;
}
int ghostdown(int num)//User defined function definition
{
	if(arr[ghosty[num]+1][ghostx[num]]==' ')
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghosty[num]++;
		return 0;
	}
else if(arr[ghosty[num]+1][ghostx[num]]=='.')//Decision making ststement
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghosty[num]++;
		return 0;
	}
	return 1;	
}
int ghostright(int num)//User defined function definition
{
		if(arr[ghosty[num]][ghostx[num]+1]==' ')//Decision making ststement
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostx[num]++;
		return 0;
	}
		else if(arr[ghosty[num]][ghostx[num]+1]=='.')//Decision making ststement
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostx[num]++;
		return 0;
	}
	return 1;	
}

int ghostleft(int num)//User defined function definition
{
		if(arr[ghosty[num]][ghostx[num]-1]==' ')//Decision making ststement
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];
		ghostx[num]--;//Decrement
		return 0;
	}
		else if(arr[ghosty[num]][ghostx[num]-1]=='.')//Decision making ststement
	{
		ghostX[num]=ghostx[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostY[num]=ghosty[num];//Storing current position into another variable used for presvious position to print space on that place
		ghostx[num]--;//Decrement
		return 0;
	}
	return 1;	
}