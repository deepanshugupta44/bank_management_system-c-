#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class account
{
        char acc_name[30];
        int acc_no;
        float bal;
        int pin;
        public:
        void setup()
        {
                cout<<"\nEnter your details:\n";
                cout<<"Name:";
                cin>>acc_name;
                cout<<"Acc_no:";
                cin>>acc_no;
                cout<<"Balance:";
                cin>>bal;
                cout<<"Pin:";
                cin>>pin;
        }
        void display()
        {
                cout<<"\nBank details are as follows:\n";
                cout<<"Name:"<<acc_name<<endl;
                cout<<"Acc_no:"<<acc_no<<endl;
                cout<<"Balance:"<<bal<<endl;
        }
        void withdraw(int amt)
        {
                if(bal>=amt)
                {
                        bal-=amt;
                        cout<<"\nBalance Amount left : "<<bal<<endl;
                }
                else
                        cout<<"Insufficient balance in Account\n";
        }
        void deposit(int amt)
        {
                bal+=amt;
                cout<<"\nBalance in Account : "<<bal<<endl;
        }
        void pinchange()
        {
                int cur_pin,new_pin,confirm_pin;
                cout<<"\nEnter the current pin\n";
                cin>>cur_pin;
                if(cur_pin==pin)
                {
                        cout<<"\nEnter the new pin\n";
                        cin>>new_pin;
                        cout<<"Re-enter your pin\n";
                        cin>>confirm_pin;
                        if(new_pin==confirm_pin)
                        {
                                pin=new_pin;
                                cout<<"\nPin changed\n";
                        }
                        else
                        {
                                cout<<"\nPassword did not matched\n";
                        }
                }
                else
                        cout<<"\nWrong Password enter\n";
        }
        int validate_acc(int temp_acc)
        {
                int i,epin,chance=2;
                if(temp_acc==acc_no)
                {
			while(chance>=0)
			{
                        	cout<<"Enter the pin\n";
                        	cin>>epin;
                        	if(epin==pin)
                                	return 1;
				cout<<"\nWrong pin entered!\nYou have "<<chance<<" attempts left\n";
				chance--;
			}
			return 0;
                }
                return 0;
        }
	void delete_acc(account temp)
	{
		strcpy(acc_name,temp.acc_name);
		acc_no=temp.acc_no;
		bal=temp.bal;
		pin=temp.pin;
	}
};
int main()
{
        account a[5];
        int c,choice,amt,j=0,i,temp_acc,val,found,k,flag=0;
        cout<<"**********Welcome to  DBI Bank**********\n";
        while(1)
        {
                cout<<"\nEnter 1 to add new account\nEnter 2 to access an account\nEnter 3 to delete account\nEnter 4 to exit\n";
		cin>>c;
		switch(c)
		{
			case 1:if(j>5)
				{
					cout<<"Capacity full\n";
				}
				else
					a[j++].setup();
				break;

			case 2:cout<<"Enter the account number to be accessed\n";
	                	cin>>temp_acc;
        	        	for(i=0;i<j;i++)
                		{
                        		found=a[i].validate_acc(temp_acc);
                        		if(found)
                        		{
                                		while(1)
                                		{
                                        		cout<<"\nEnter your choice...\n1.Display details\n2.Withdraw\n";
	                                        	cout<<"3.Deposit\n4.Pin change\n5.Quit\n";
        	                                	cin>>choice;
                	                        	switch(choice)
                        	                	{
                                	                	case 1:a[i].display();
                                        	                	break;
                                                		case 2:cout<<"\nEnter the amount to be withdraw\n";
                                                        		cin>>amt;
                                                        		a[i].withdraw(amt);
	                                                        	break;
        	                                        	case 3:cout<<"\nEnter the amount to be deposited\n";
                	                                        	cin>>amt;
                        	                                	a[i].deposit(amt);
                                	                        	break;
                                        	        	case 4:a[i].pinchange();break;
                                                		default:printf("Invalid entry\n");
	                                        	}
        	                                	if(choice==5)
                	                                	break;
                        	        	}
                                		break;
						flag=1;
	                        	}
        	        	}
				if(flag==0)
					cout<<"Account does not exist\n";
				flag=0;
				break;

			case 3:cout<<"Enter the account number to be deleted:\n";
				cin>>temp_acc;
				if(j==0)
					cout<<"No Account to be deleted please enter account first!";
				else
				{
					for(i=0;i<j;i++)
                			{
                        			found=a[i].validate_acc(temp_acc);
	                        		if(found)
						{
							for(k=i;k<j-1;k++)
							{
								a[k].delete_acc(a[k+1]);
							}
							j--;
							flag=1;
							cout<<"Account deleted successfully\n";
						}
					}
					if(flag==0)
						cout<<"Account does not exist\n";
					flag=0;
				}
				break;
			case 4:return 0;
			default:cout<<"Enter the correct option\n";
		}
        }
}


