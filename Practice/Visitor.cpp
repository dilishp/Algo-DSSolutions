#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NAME_LEN = 200;

class ProductVisitor;

class Product
{
public:
	Product() {};
	virtual void accept(ProductVisitor *v) = 0;
	virtual double getPrice() = 0;
	char *getName() { return name; };
protected:
	char name[MAX_NAME_LEN];
};

class Item : public Product
{
public:
	Item(const char *n) : price(0.0) { strcpy_s(name, n); };
	Item(const char *n, double p) : price(p) { strcpy_s(name, n); };
	virtual void accept(ProductVisitor *v) = 0;
	double getPrice() { return price; };
	void setPrice(double p) { price = p; };

private:
	double price;
};

class FreshVegetable : public Item
{
public:
	FreshVegetable(const char *n) : Item(n) {};
	FreshVegetable(const char *n, double p) : Item(n, p) {};

	void accept(ProductVisitor *v);
};

class CannedItem : public Item
{
public:
	CannedItem(const char *n) : Item(n) {};
	CannedItem(const char *n, double p) : Item(n, p) {};
	void accept(ProductVisitor *v);
};


class Package : public Product
{
public:
	Package(const char pname[]) { strcpy_s(name, pname); };
	Package& addProduct(Product *product) { contents.push_back(product); return *this; };
	Product *getProduct(int i) { return contents[i]; };
	int size() { return contents.size(); };
	virtual void accept(ProductVisitor *v);
	double getPrice() { double p = 0.0; for (unsigned int i = 0;i < contents.size();i++) { p += contents[i]->getPrice(); } return p; };
private:
	vector<Product *> contents;
};

class ProductVisitor
{
public:
	ProductVisitor() {};
	virtual void visit(FreshVegetable *p) = 0;
	virtual void visit(CannedItem *p) = 0;
	void visit(Package *p);
};

class CheapestVisitor : public ProductVisitor
{
public:
	double getMinPrice(); // Return the price of the cheapest item
	Item *getMinItem(); // Return the item with the cheapest price
	void reset(); // Reset before visiting a different product
	void setPrice(const double dPrice) { m_dPrice = dPrice; }

	void visit(FreshVegetable *p);
	void visit(CannedItem *p);
private:
	vector<Item*> m_Itemvector;
	double m_dPrice;
};

class ReducePriceVisitor : public ProductVisitor
{
public:
	ReducePriceVisitor(double dfreshveg, double dcannedVeg) :m_dfreshvegded(dfreshveg), m_dcannedvegded(dcannedVeg) {}
	void visit(FreshVegetable *p) override;
	void visit(CannedItem *p) override;
private:
	double m_dfreshvegded;
	double m_dcannedvegded;
};
// Accept() method for all products that accept a
// ProductVisitor

void FreshVegetable::accept(ProductVisitor *v)
{
	v->visit(this);
};


void CannedItem::accept(ProductVisitor *v)
{
	v->visit(this);
};


void Package::accept(ProductVisitor *v)
{
	v->visit(this);
};

// Visit method for ProductVisitor class on Package class
void ProductVisitor::visit(Package *p)
{

	for (size_t index = 0;index < p->size(); index++)
	{
		p->getProduct(index)->accept(this);
	}

}
void CheapestVisitor::visit(CannedItem *p)
{
	if (p->getPrice() < m_dPrice)
	{
		m_dPrice = p->getPrice();
	}
	m_Itemvector.push_back(p);
}
void CheapestVisitor::visit(FreshVegetable *p)
{
	if (p->getPrice() < m_dPrice)
	{
		m_dPrice = p->getPrice();
	}
	m_Itemvector.push_back(p);
}

void ReducePriceVisitor::visit(FreshVegetable *p)
{
	p->setPrice(p->getPrice() - ((m_dfreshvegded*0.01) * p->getPrice()));
}

// Visit Method for ReducePriceVisitor class on CannedItem class

void ReducePriceVisitor::visit(CannedItem *p)
{
	p->setPrice(p->getPrice() - ((m_dcannedvegded*0.01) * p->getPrice()));
}

// CheapestVisitor Method to return the price of the cheapest item
double CheapestVisitor::getMinPrice()
{	
	return m_dPrice;
}

// CheapestVisitor Method to return the cheapest Item
Item *CheapestVisitor::getMinItem()
{
	auto iterator = find_if(m_Itemvector.begin(), m_Itemvector.end(), [this](Item* item)->bool {
		return item->getPrice() == m_dPrice;
	});

	if (iterator == m_Itemvector.end())
	{
		return nullptr;
	}

	return static_cast<Item*>(*iterator);
}

// CheapestVisitor Method to reset before finding the minimum item
void CheapestVisitor::reset()
{
	m_Itemvector.clear();
}








void test1(double freshVegReduction, double cannedItemReduction)
{
	// Declare a couple of fresh vegetables and
	// a canned item, giving their name and their price.
	FreshVegetable carrot("carrot", 50.0), peas("peas", 60.0), parsnips("parsnips", 55.0);
	CannedItem mushyPeas("mushyPeas", 80.0), bakedbeans("bakedBeans", 100.0);

	// Declare a package to contain multiple products
	Package pack1("package1");

	// Add products to the package
	pack1.addProduct(&carrot);
	pack1.addProduct(&peas);
	pack1.addProduct(&bakedbeans);

	// The Cheapest Visitor calculates the price of the cheapest
	// item in the package
	CheapestVisitor cheap;
	cheap.setPrice(pack1.getProduct(0)->getPrice());
	pack1.accept(&cheap);

	cout << "The cheapest item is "
		<< cheap.getMinItem()->getName() << " at price "
		<< cheap.getMinPrice() << " rupies." << endl;

	// The ReducePriceVisitor takes two arguments - a percentage (0.80) by
	// which to reduce the price of FreshVegetable products and
	// a percentage (0.50) by which to reduce CannedItem products

	ReducePriceVisitor priceModifier(freshVegReduction, cannedItemReduction);
	pack1.accept(&priceModifier);

	// Use CheapestVisitor to re-calculate price of cheapest item

	cheap.reset(); // re-set to compute a new minimum price
	pack1.accept(&cheap);
	cout << "The cheapest item is "
		<< cheap.getMinItem()->getName() << " at price "
		<< cheap.getMinPrice() << " rupies." << endl;

}


void test2(double freshVegReduction, double cannedItemReduction)
{
	// Declare a couple of fresh vegetables and
	// a canned item, giving their name and their price.
	FreshVegetable carrot("carrot", 50.0), peas("peas", 60.0), parsnips("parsnips", 55.0);
	CannedItem mushyPeas("mushyPeas", 80.0), bakedbeans("bakedBeans", 100.0);
	// Declare a package to contain multiple items

	Package pack1("package1");

	// Declare a second package that will contain pack1

	Package pack2("package2");

	// Add products to the packages - pack2 contains pack1
	pack1.addProduct(&carrot);
	pack1.addProduct(&peas);
	pack1.addProduct(&mushyPeas);
	pack2.addProduct(&pack1);
	pack2.addProduct(&bakedbeans);
	pack2.addProduct(&parsnips);
	// The Cheapest Visitor calculates the price of the cheapest
	// item in the package
	CheapestVisitor cheap;
	cheap.setPrice(pack1.getProduct(0)->getPrice());
	pack2.accept(&cheap);

	cout << "The cheapest item is "
		<< cheap.getMinItem()->getName() << " at price "
		<< cheap.getMinPrice() << " rupies." << endl;

	// The ReducePriceVisitor takes two arguments - a percentage (0.80) by
	// which to reduce the price of FreshVegetable products and
	// a percentage (0.50) by which to reduce CannedItem products

	ReducePriceVisitor priceModifier(freshVegReduction, cannedItemReduction);
	pack2.accept(&priceModifier);

	// Use CheapestVisitor to re-calculate price of cheapest item

	cheap.reset(); // re-set to compute a new minimum price
	pack2.accept(&cheap);
	cout << "The cheapest item is "
		<< cheap.getMinItem()->getName() << " at price "
		<< cheap.getMinPrice() << " rupies." << endl;

}

int main()
{
	test1(0.8, 0.5);
	test1(0.5, 0.8);
	test1(1.0, 0.4);
	test2(0.8, 0.5);
	test2(0.5, 0.8);
	test2(1.0, 0.4);
	return 0;
}

