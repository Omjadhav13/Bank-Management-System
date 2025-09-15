#include <iostream>
using namespace std;
class Account{
	private:
		static int acountno_generator;
		string name,gender;
		int amount;
		int accountno;
		
	public:
		void open(string n,string g,float a){
			name=n;
			gender=g;
			amount=a;
			accountno=++acountno_generator;
			cout << name <<" your account is created and account number is "<<accountno;
		}
		void checkBalance(){
			cout <<"\nAccount number "<< accountno<< "\nName : "<<name  <<"\nBalance "<<amount;
		}
		void deposit(float da){
			if(da==0){
				cout << "Error,amount should not be negative";
			}
			else {
				amount+=da;
				cout << "\nAmount credited successfully";
				checkBalance();
			}
			
		}
		void withdraw(float wa){
			if(wa-amount>amount){
				cout << "\n Insufficient Balance cannot withdraw";
			}
			else {
				amount-=wa;
				cout << "\nAmount withdraw successfully";
				checkBalance();
			}
			
		}
		int getAcc(){
			return accountno;
		}
		
};
int Account::acountno_generator=2500;
int main(){
	bool flag;
	int accounts=0,acc_no;
	Account a[100];
	string name,gender;
	int choice;
	float amount;
	do{
		cout << "\n===================";
		cout << "\n=====dena bank=====";
		cout << "\n===================";
		cout << "\n1.Create Account ";
		cout << "\n2.Deposit";
		cout << "\n3.Withdraw";
		cout << "\n4.check balance";
		cout << "\n0.Exit";
		cout << "\n===================\n";
		cin >> choice;
		switch (choice){
			case 1:
				cout<<"\nEnter Name,Gender and amount:"	;
 				cin>>name>>gender;
 				do{
 					cout<<"\nEnter amount (min amount should be 5000):"	;
 					cin>>amount;
 				}while(amoun<5000);
 				a[accounts].open(name,gender,amount);
 				accounts++;
 				break;
			case 2:
				flag=false;
 				cout<<"\nEnter account number:";
 				cin>>acc_no;
 				for(int i=0;i<accounts;i++)
 				  {
				   if(acc_no==a[i].getAcc())
 						{
 						 flag=true;
 						 a[i].checkBalance();
						 cout<<"\nEnter amount to deposit:"	;
						 cin>>amount;
						 a[i].deposit(amount);
						 break;
					     }
					}
					if(flag==false)
						cout<<endl<<acc_no<<" Not found....";
 				break;
				
			case 3:
				flag=false;
 				cout<<"\nEnter account number:";
 				cin>>acc_no;
 				for(int i=0;i<accounts;i++)
 				  {
				   if(acc_no==a[i].getAcc())
 						{
 						 flag=true;
 						 a[i].checkBalance();
						 cout<<"\nEnter amount to deposit:"	;
						 cin>>amount;
						 a[i].withdraw(amount);
						 break;
					     }
					}
					if(flag==false)
						cout<<endl<<acc_no<<" Not found....";
 				break;

			case 4:
				flag=false;
 				cout<<"\nEnter account number:";
 				cin>>acc_no;
 				for(int i=0;i<accounts;i++)
 				  {
				   if(acc_no==a[i].getAcc())
 						{
 						 flag=true;
 						 a[i].checkBalance();
						  break;
					     }
					}
					if(flag==false)
						cout<<endl<<acc_no<<" Not found....";
 				break;
				
			case 0:
				cout << "\nExiting....";
				break;
			default:
				cout <<"\nWrong choice";
				break;			
		}
	}while(choice!=0);
}
