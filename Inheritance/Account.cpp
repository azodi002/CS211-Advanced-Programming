#include <iostream>
using namespace std;




class Account
{
  protected: 
  double balance;
  
  public:
  Account(double balanceMade)
  {
    /*Do not allow balance to be negative*/

    if(balanceMade > 0)
      {
	balance = balanceMade;
      }
    
    else
      {
	balanceMade = 0.0;
      }
  }


  void credit(double amount)
  {
    balance+= amount;

  }

  void debit(double amount)
  {
    if(balance > amount)
      {
	balance = balance - amount;
      }
    
    else
      {
	cout << "Insufficient funds." << endl;
      }
  }
  
  double getBalance()
  {
    return balance;
  }

};//Class Account definition ends

class CheckingAccount: public Account
{
   private:
  double fee;

public:
  CheckingAccount(double balanceMade, double feeCharge): Account(balanceMade)
  {
    fee = feeCharge;
  } 

  void debit(double amount)
  {
    if(balance > amount)
      {
	balance = balance - amount - fee;
      }
    
    else
      {
	cout << "Insufficient funds. " << endl;
      }
  }


};

int main()
{

  CheckingAccount myAccount(500, .5);
  myAccount.credit(100);
  cout << myAccount.getBalance() << endl;
  
  myAccount.debit(50);
  cout << myAccount.getBalance() << endl;







  return 0;
}
