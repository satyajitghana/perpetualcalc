#include<iostream.h>
#include<conio.h>

//Functions Prototype
int first_day (int);
void month_name(int);
int no_days(int,int);
int leap(int);

void main()
{
restart:
clrscr();

unsigned int year,month;
int x;

//Perpetual_calendar table 
int perpetual_calender[14][12]=
{1,4,4,7,2,5,7,3,6,1,4,6,
2,5,5,1,3,6,1,4,7,2,5,7,
3,6,6,2,4,7,2,5,1,3,6,1,
4,7,7,3,5,1,3,6,2,4,7,2,
5,1,1,4,6,2,4,7,3,5,1,3,
6,2,2,5,7,3,5,1,4,6,2,4,
7,3,3,6,1,4,6,2,5,7,3,5,
1,4,5,1,3,6,1,4,7,2,5,7,
2,5,6,2,4,7,2,5,1,3,6,1,
3,6,7,3,5,1,3,6,2,4,7,2,
4,7,1,4,6,2,4,7,3,5,1,3,
5,1,2,5,7,3,5,1,4,6,2,4,
6,2,3,6,1,4,6,2,5,7,3,5,
7,3,4,7,2,5,7,3,6,1,4,6};

//To take input of year from user
cout<<"\nEnter Year : ";
cin>>year;

//To find the first day of the year
x=first_day(year);

//To take input of the month from user
cout<<"Enter month (1 - 12) : ";
month_input:
cin>>month;
	if(month<1 || month>12)
		{
			cout<<"Enter a valid month (1 - 12) : ";
			goto month_input;
		}
cout<<"\n\n";

//To find the month corresponding to the number entered
month_name(month);

//To print Mon Tue Wed........
cout<<"\t"<<year<<"\n\n\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n";

//To find the corresponding data from the array
int j=perpetual_calender[x-1][month-1], days=no_days(month,year);
	for (int i=0; i<j; i++)
		cout<<"\t";
	for(i=1; i<=days; i++)
		{
			cout<<i<<"\t";
				if(j==7)
					{
						cout<<"\n\t";
						j=1;
					}
				else
					j++;
			}



//To repeat 
cout<<"\n\nWanna See the calender for another month? (y/n) : ";
char ch;
cin>>ch;

if(ch=='y' || ch=='Y')
	goto restart;
else cout<<"\nHave a Good Day";
}

//Logic to find the first day of the year 
int first_day (int a)
{
int t=a%7;
t+=(a-1)/4;
t-=(a-1)/100;
t+=(a-1)/400;
t=t%7;
if(t==0)
	t=7;
if(leap(a))
	t+=7;
return t;
}

//Logic to find the corresponding month to the number input from user 
void month_name(int m)
{
switch(m)
{
case 1 : cout<<"January";
break;
case 2 : cout<<"February";
break;
case 3 : cout<<"March";
break;
case 4 : cout<<"April";
break;
case 5 : cout<<"May";
break;
case 6 : cout<<"June";
break;
case 7 : cout<<"July";
break;
case 8 : cout<<"August";
break;
case 9 : cout<<"September";
break;
case 10: cout<<"October";
break;
case 11: cout<<"November";
break;
case 12: cout<<"December";
break;
}
}

//Logic to find the number of days 
int no_days(int month, int year)
{
int days;
switch(month)
	{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10:
		case 12: days=31;
		break;

		case 4 :
		case 6 :
		case 9 :
		case 11: days=30;
		break;

		case 2 : if(leap(year))
					days=29;
				 else
					days=28;
		break;
	}
return days;
}

int leap (int year)
{
if (year%100==0)
	if (year%400==0)
		return 1;
	else
		return 0;
else 
	if (year%4==0)
		return 1;
else
	return 0;
}

//End of Program

