/*1) Create a Project to demonstrate an ATM Banking Application which will help to get to
know the bank information.. The Project should contain all the necessary
requirements i.e A Program should use the concept of OOP.(compulsory :
Constructor),Make use of scope resolution operator, Loops, ConditionalStatements,
Whichever is required.

2) Give comments where it is required , for better understanding of codes. It will help
you and the project evaluator.
*/
#include<iostream>
#include<stdlib.h>
#include <ctime>
using namespace std;

class Bank
{
	private :
		string acc_name;
		string address;
		string branch_add;
		int acc_no;
		int bal_amt;
	
	public :
		Bank()
		{
			acc_name="Ansari Amanhusain Kalimuddin";
			address="Ahmedabad";
			branch_add="Sarkhej";
			acc_no= 220102345;
			bal_amt = 20000;
		}
		
		void Atm_Access();
		void Atm_acc_status();
		void Incorrect_pin();
		void Atm_main_menu_screen();
		void print_value();
		void dep_amt();
		void withdraw_amt();
		
		
};

void Bank::print_value()
{
	cout << "\n\n\t Account Holder Name     : "<< acc_name;
	cout << "\n\n\t Account Holder Address  : "<< address;
	cout << "\n\n\t Branch Address          : "<< branch_add;
	cout << "\n\n\t Account Number          : "<< acc_no;
	cout << "\n\n\t Balance Amount          : "<< bal_amt;
}

void Bank::Atm_Access()
{
	int atm_pin;
	cout << "\n\n\t====================== ATM Access ==================================";
	cout << "\n\n\tEnter Your Acc Pin Number ! [Only One Attempt is Allowed]    : ";
	cin >> atm_pin;
	if(atm_pin == 12345)
	      Atm_main_menu_screen();
	else 
	      Incorrect_pin();
}

void Bank::Atm_acc_status()
{
	cout << "\n\n\tYou must have the correct pin number to access your account. See your ";
	cout << "\n\n\t      bank representative for assistance during bank opening hour     ";
	cout << "\n\n\t           Thanks for your choice today !                             ";
}

void Bank::Incorrect_pin()
{
	cout << "\n\n\t=============================== Thank You =====================================";
	cout << "\n\n\tYou had made your attempt which failed!!! No more attempt is allowed ! Sorry!!!"; 
}

void Bank::Atm_main_menu_screen()
{
	int num;
	char choice;
	do
	{
	
	    cout << "\n\n\t========================== ATM Main Menu Screen ===============================";
	    cout << "\n\n\n\t                       Enter [1] to Deposite Amount                            ";
	    cout << "\n\n\t                       Enter [2] to Withdraw Amount                            ";
	    cout << "\n\n\t                       Enter [3] to Balance Inquiry                            ";
	    cout << "\n\n\t                       Enter [0] to Exit from Account                           ";
	    cout << "\n\n\n\t            PLEASE SELECT THE OPTION FROM ABOVE MENU AND PRESS ENTER      : ";
	    cin >> num;
	    switch(num)
	    {
		    case 1 :
			    dep_amt();
			    break;
		    case 2 :
			    withdraw_amt();
			    break;
		    case 3 :
			    print_value();
			    break;
		    case 4 :
			    exit(0);
			    break;
		    default :
			    cout << "\n\n\tYou Select Wrong Option !!! ";
			    break;
			
	    }
	   
	    cout << "\n\n\tEnter 'y' to Return to the Menu, any other key to Exit: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void Bank::dep_amt()
{
	int deposite;
	cout << "\n\n\t============================= ATM Account Deposite System ===================================";
	print_value();
	cout <<"\n\n\t--------------------------------------------------------";
	cout << "\n\n\tEnter Amount that you want to Deposite    : ";
	cin >> deposite;
	bal_amt +=deposite;
	cout << "\n\n\tNow Total Balance is   : " << bal_amt;
}

void Bank::withdraw_amt()
{
	int withdraw;
	cout << "\n\n\t============================= ATM Account Withdraw System ===================================";
	print_value();
	cout <<"\n\n\t--------------------------------------------------------";
	cout << "\n\n\tEnter Amount that you want to withdraw    : ";
	cin >> withdraw;
	if(bal_amt > withdraw)
	{
	        bal_amt -=withdraw;
	        cout << "\n\n\tNow Balance Amount is   : " << bal_amt;
	}
	else
	{
	    cout << "\n\n\tYou Don't have sufficent Balance ! Try Again........";
	    cout << "\n\n\n\t                  SORRY !!                            ";
    }
}

main()
{
	Bank B;
	int ch;
	cout << "\n\n\t============================= Welcome To The ATM ===============================";
	cout << "\n\n\t                            -----------------------                             ";
	time_t tt;  
	struct tm* ti;  
	time(&tt); 
	ti = localtime(&tt); 

	cout << "\n\n\t\t\t\tCurrent Date : "
		<< asctime(ti); 

	cout << "\n\n\t                            -----------------------                             ";
	cout << "\n\n\t================================================================================";
	cout << "\n\n\tPress 1 and Then Press Enter to Access Your Account Via Pin Number              ";
	cout << "\n\n\t                                 OR                                             ";
	cout << "\n\n\tPress 0 and Press Enter to get Help                                             ";
	cout << "\n\n\tSelect Your Choice      : ";
	cin >> ch;
	
	switch(ch)
	{
		case 1 :
			B.Atm_Access();
			break;
		case 2 :
			B.Atm_acc_status();
			break;
		default :
			cout << "\n\n\tYou Select Wrong Option!!!";
			break;
			
			 
	}
}
