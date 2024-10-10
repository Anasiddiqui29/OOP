#include <iostream>

using namespace std ; 

class BankAccount 
{
	int accountId ;
	double balance ; 
	int * transactionHistory ;
	int numTransactions ;
	ATM atm ;
	
	public:
	
	BankAccount(int accountId , double balance , int * transactionHistory , int numTransactions) 
	{
		this->accountId = accountId ; 
		this->balance = balance ; 
		this->numTransactions = numTransactions ; 
		this->transactionHistory = transactionHistory ; 
		
		
		this->transactionHistory = new int[numTransactions] ;
		
		for(int i = 0; i < numTransactions ; i++)
		{
			this->transactionHistory[i] = transactionHistory[i];
		}
	}
	
	//copy constructor
	BankAccount(const BankAccount &bank)
	{
		accountId = bank.accountId ; 
		balance = bank.balance ;
		numTransactions = bank.numTransactions ;
		transactionHistory = bank.transactionHistory ;
		
		for(int i=0 ; i<numTransactions ; i++)
		{
			transactionHistory[i] = bank.transactionHistory[i] ; 
		}
		  
	}
	
	~BankAccount()
	{
		delete[] transactionHistory ;
	}
	
	void display()
	{
		cout << "Account number: " << accountId <<endl ; 
		cout <<"Account balance: " << balance << endl ; 
		cout <<"Number of transactions: " <<numTransactions <<endl ;
		
		cout << "TRANSACTION DETAILS" << endl ;
		for(int i=0 ; i<numTransactions ; i++)
		{
			cout << "Trasaction "<<i+1<< " : "<<transactionHistory[i] << endl ;	
		}  
		atm.display(); 
	}
	
	void updateTransactionHistory(int * transactionHistory , int numTransactions)
	{
		delete[] this->transactionHistory ;
		
		for(int i=0 ; i<this->numTransactions ; i++)
		{
			this->transactionHistory[i] = transactionHistory[i] ; 
		}
	}	
} ;

class ATM
{
	int pin ; 
	
	public:
	
	ATM(int pin)
	{
		this->pin = pin ; 	
	}	
	
	void Display()
	{
		cout << "ATM pin: " << pin << endl ; 
	}
	
	
} ;

int main()
{
	int transactions[] = {1000,500 , 2000 , 900} ;
	int num_transactions = sizeof(transactions) / sizeof(transactions[0]) ;
	BankAccount acc1(122222 , 23000.00 , transactions , num_transactions) ; 
	
	int transactions1[] = {1500 , 2500 , 4000} ;
	int num_transactions1 = sizeof(transactions1) / sizeof(transactions1[0]) ;
	
	//copy constructor
	BankAccount acc2(acc1) ; 
	
	acc1.display() ; 
	
	acc2.display() ;
	
	acc1.updateTransactionHistory(transactions1 , num_transactions1) ; 
	
	acc1.display() ; 
	
	ATM accc1(1234) ; 
	accc1.Display() ; 
	
	
	
}

