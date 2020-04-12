using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticeCsh
{
    abstract class Account
    {
        public Account(long accNo,double accBalance,int dur)
        {
            accountNumber = accNo;
            accountBalance = accBalance;
            duration = dur;
        }
        public abstract double CalculateInterest();

        public abstract double CalculatePenalty();

        public void Deposit(double amount)
        {
            accountBalance += amount;
        }

        public void Withdraw(double amount)
        {
            if (amount > accountBalance)
                return;

            accountBalance -= amount;
        }

       
        protected double accountBalance;

        protected int duration;

        private long accountNumber;

        public long AccountNumber { get => accountNumber; set => accountNumber = value; }

        public override string ToString()
        {
            return accountBalance.ToString() + accountNumber.ToString();
        }
    }

    class SavingsAccount : Account
    {
        private static double InterestRate = 6.93;
        private static double MinAccountBalance = 5000;

        public SavingsAccount(long AccNo, double accBalance, int duration) : base(AccNo, accBalance, duration)
        {

        }
        public override double CalculateInterest()
        {
            double interest = (InterestRate * accountBalance * duration) / 100;
            accountBalance += interest;
            return (InterestRate * accountBalance * duration) / 100;
        }

        public override double CalculatePenalty()
        {
            double penalty = 0;
            if (accountBalance < MinAccountBalance)
            {
                penalty = 500;
                accountBalance -= penalty;
            }

            return penalty;
        }
    }

    class CheckingAccount : Account
    {
        private double InterestRate = 8.2;
        private static double MinAccountBalance = 1000;

        public CheckingAccount(long AccNo,double accBalance,int duration):base(AccNo,accBalance,duration)
        {

        }
        public override double CalculateInterest()
        {
            double interest = (InterestRate * accountBalance * duration) / 100;
            accountBalance += interest;
            return (InterestRate * accountBalance * duration) / 100;
        }

        public override double CalculatePenalty()
        {
            double penalty = 0;
            if (accountBalance < MinAccountBalance)
            {
                penalty = 100;
                accountBalance -= penalty;
            }

            return penalty;
        }
    }

    class Customer
    {
        private string firstName;
        private string lastName;
        private List<Account> accounts;
        private string uniqueid;

        public Customer(string fname,string lname,string uid)
        {
            firstName = fname;
            lastName = lname;
            uniqueid = uid;
        }

        public string Uniqueid { get => uniqueid; set => uniqueid = value; }
        public string LastName { get => lastName; set => lastName = value; }

        public void AddAccounts(Account account)
        {
            accounts.Add(account);
        }

        public void DeleteAccounts(long  accno)
        {
            Account account = accounts.Find((anAccount) => anAccount.AccountNumber == accno);
            if(account != null)
            {
                accounts.Remove(account);
            }
        }

        public Account GetAccount(long accNo)
        {
            Account account = accounts.FirstOrDefault((aAccount) => aAccount.AccountNumber == accNo);
            return account;

        }

        public void PrintAccount()
        {
            accounts.ForEach((anAccount) => Console.WriteLine(anAccount));
        }
    }

    class Bank
    {
        private List<Customer> customers;

        public void AddCustomer(Customer customer)
        {
            customers.Add(customer);
        }

        public void RemoveCustomer(string uid)
        {
            Customer customer = GetCustomer(uid);
            if (null != customer)
                customers.Remove(customer);
        }

        public Customer GetCustomer(string uid)
        {
            Customer customer = customers.FirstOrDefault((aCustomer) => aCustomer.Uniqueid == uid);
            return customer;
        }

        public void PrintCustomers()
        {
            customers.Sort((aCustomer1, aCustomer2) => string.Compare(aCustomer1.LastName,aCustomer2.LastName));

            customers.ForEach((aCustomer) => Console.WriteLine(aCustomer.LastName + " " + aCustomer.Uniqueid + " "));

            customers.ForEach((aCustomer) => aCustomer.PrintAccount());
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Bank bank = new Bank();

            Console.WriteLine("*********Menu**********");
            Console.WriteLine("1. Add Customer");
            Console.WriteLine("2. Delete Customer");
            Console.WriteLine("3. Add Account");
            Console.WriteLine("4. Delete Account");

            Console.WriteLine("Enter an Option");
            int option;
            option = int.Parse(Console.ReadLine());

            switch (option)
            {
                case 1:
                    {
                        Console.WriteLine("Please Enter the customer First Name,Last Name,Uid");
                        string fname = Console.ReadLine();
                        string lname = Console.ReadLine();
                        string uid = Console.ReadLine();
                        Customer customer = new Customer(fname, lname, uid);
                        bank.AddCustomer(customer);
                    }
                    break;
                case 2:
                    {
                        Console.WriteLine("Please Enter the uid of the cutomer to be deleted");
                        string uid = Console.ReadLine();
                        bank.RemoveCustomer(uid);
                    }
                    break;
                case 3:
                    {
                        Console.WriteLine("Enter the Customer Uid where we should Add Account");
                        string uid = Console.ReadLine();
                        Console.WriteLine("Enter the Account Details such s Balance,Duration and AccNo");
                        long accNo = long.Parse(Console.ReadLine());
                        double balance = double.Parse(Console.ReadLine());
                        int duration = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter Which type of Account to be created 1 - Savings, 2- Checking");
                        int accoption = int.Parse(Console.ReadLine());
                        Account account = null;
                        if (accoption == 1)
                        {
                            account = new SavingsAccount(accNo, balance, duration);
                        }
                        else if (accoption == 2)
                        {
                            account = new CheckingAccount(accNo, balance, duration);
                        }
                        bank.GetCustomer(uid)?.AddAccounts(account);
                    }
                    break;
                case 4:
                    {
                        Console.WriteLine("Enter the Customer Uid where we should Delete Account");
                        string uid = Console.ReadLine();
                        Console.WriteLine("Enter the account Number of the account to be deleted");
                        long accNo = long.Parse(Console.ReadLine());
                        bank.GetCustomer(uid)?.DeleteAccounts(accNo);
                    }
                    break;
                default:
                    break;
            }

            //For this to work have a customer with uid = 1 and AccNo = 123

            Console.WriteLine("Enter the Amount to be deposited ");
            double amount = double.Parse(Console.ReadLine());
            bank.GetCustomer("1").GetAccount(123).Deposit(amount);

            Console.WriteLine("Enter the Amount to be Withdrawn ");
            double amt = double.Parse(Console.ReadLine());
            bank.GetCustomer("1").GetAccount(123).Withdraw(amt);

            //Calculate Interest and Penalty
            Console.WriteLine("Interest : {0}", bank.GetCustomer("1").GetAccount(123).CalculateInterest()); 

            Console.WriteLine("Penalty : {0}", bank.GetCustomer("1").GetAccount(123).CalculatePenalty());

            //List Account with the name in the sorted Order of last Name
            bank.PrintCustomers();




        }
    }
}
