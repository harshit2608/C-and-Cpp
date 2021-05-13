#include<iostream>

using namespace std;

class Bank{
    char name_of_depositor[30];
    int Acc_no;
    char type_of_account[20];
    int Balance;
public:
    Bank()
    {
       	 Acc_no = 0;     
         Balance = 0;
    }
    void Details()
    {
        cout<<"Enter your full Name ";
        cin>>name_of_depositor;
        cout<<"Account Number ";
        cin>>Acc_no;
        cout<<"Type of Account: ";
        cin>>type_of_account;
        cout<<"Enter Balance ";
        cin>>Balance;   
     }
    void Deposit()
    {
        double deposit;
        cout<<"Enter the Amount to deposit: ";
        cin>>deposit;
        Balance += deposit;  
    }
    void Withdraw()
    {
        double Amount;
        cout<<"Enter Amount to withdraw ";
        cin>>Amount;
        if(Balance >= Amount)
            Balance -= Amount;
        else
            cout<<"Less Balance \n";
    }
    void Display()
    {
        cout<<"\t\t:Customer Details:\n\n";
        cout<<"Name: "<<name_of_depositor<<"\n";
        cout<<"Account No.: "<<Acc_no<<"\n";
        cout<<"Account Type: "<<type_of_account<<"\n";
        cout<<"Balance: "<<Balance<<"\n";    
    }
};

int main()
{
    Bank b;
    int option;
    cout<<"\t\t ---- Welcome to Bank ----";
    cout<<"\n 1.Enter Details \n 2.Deposit \n 3.Withdraw \n 4.Display Details \n 5.Exit\n";
    do{
        cout<<"choose option: ";
        cin>>option;
        switch(option){
            case 1: b.Details();
                    break;
            case 2: b.Deposit();
                    break;
            case 3: b.Withdraw();
                    break;
            case 4: b.Display();
                    break;
            case 5: cout<<"Have a nice day.....";
                    break;
            default: cout<<"Enter valid option";
        }
    }while(option != 5);
    return 0;
}
