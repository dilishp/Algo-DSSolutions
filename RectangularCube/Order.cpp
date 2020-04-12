#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

enum Item
{
	Car,
	Chair,
	Computer,
	Aircraft,
	Door,
	Bag,
	Books,
	Laptop,
	Table,
	Sofa,
	TV,
	Shoes,
	Dress,
	Jeep,
	HeadPhone,
	Mobile,
	Purse,
	Cupboard,
	Cap,
	Hammer
};

string itemarr[] =
{ 
	"Car",
	"Chair",
	"Computer",
	"Aircraft",
	"Door",
	"Bag",
	"Books",
	"Laptop",
	"Table",
	"Sofa",
	"TV",
	"Shoes",
	"Dress",
	"Jeep",
	"HeadPhone",
	"Mobile",
	"Purse",
	"Cupboard",
	"Cap",
	"Hammer"
};

struct Order
{
	Item item;
	double price;
	Order(int num, double p)
	{
		item = (Item)num;
		price = p;
	}
};

struct Package
{
	Order* orderptr;
	int size;
	string address;
	string packId;
	string billDetails;
};

string generateBillDetails(const Package& pack)
{
	string billDetails;
	billDetails += "Package ID :" + pack.packId + "\n";
	billDetails += "Address : " + pack.address + "\n";
	billDetails += "Ordered Items : ";
	double total = 0.00;
	for (int i = 0; i < pack.size; i++)
	{
		billDetails += itemarr[(int)pack.orderptr[i].item] + "  " + to_string(pack.orderptr[i].price) + "\n";
		total += pack.orderptr[i].price;
	}
	billDetails += "---------------------------\n";
	billDetails += "Total : "+to_string(total) + "\n";
	return billDetails;
}
int main()
{
	
	Package pack;
	pack.packId = "#4546-786-543-06-5g";
	pack.address = "United States, The Crazy State, Porgareta, Senti-Marraia, St. 12, Villa #2";
	pack.orderptr = new Order[5]{ {(Item)0,2500.00},{(Item)1,60.00},{(Item)2,100.00},{(Item)3,999.50},{(Item)4,150000.00} };
	pack.size = 5;
	pack.billDetails = generateBillDetails(pack);
	cout << "Bill Details : \n"<<pack.billDetails;
	return 0;
}