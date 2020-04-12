#include "pch.h"
//#include <iostream>
//using namespace std;
//
//struct BSTNode /// BinarySearchTreeNode
//{
//	int value;
//	BSTNode* left = NULL;
//	BSTNode* right = NULL;
//};
//
//class BST // BinarySearchTree
//{
//private:
//	BSTNode* root;
//public:
//	BST() { root = NULL; }
//	//Inserts the value to the BST
//	void insert(int value);
//	
//	/// ------------------------------------------
//	void remove(int value);
//	
//	//Recursive function to delete a node
//	BSTNode* deleteNode(BSTNode* root, int value);
//	
//	/// ------------------------------------------
//	BSTNode* finMin() const;
//
//	//Recursive function to Find the leftmost node in the BST which will be MIN
//	BSTNode* findMin(BSTNode* node) const;
//	/// ------------------------------------------
//	BSTNode* finMax() const;
//
//	//Recursive function to find the rightmost node in the BST which will be MAX
//	BSTNode* findMax(BSTNode* node) const;
//	/// ------------------------------------------
//	void preOrderTraversal() const;
//
//	void preOrderTraversal(BSTNode* node) const;
//
//	/// ------------------------------------------
//	void inOrderTraversal() const;
//
//	void inOrderTraversal(BSTNode* node) const;
//
//	/// ------------------------------------------
//	void postOrderTraversal() const;
//
//	void postOrderTraversal(BSTNode* node) const;
//
//};
//
//void BST::insert(int value)
//{
//	if (root == NULL)
//	{
//		root = new BSTNode();
//		root->left = NULL;
//		root->right = NULL;
//		root->value = value;
//	}
//	else
//	{
//		BSTNode* newNode = new BSTNode();
//		newNode->left = NULL;
//		newNode->right = NULL;
//		newNode->value = value;
//
//		BSTNode* temp = root;
//
//		while (temp)
//		{
//			if (value > temp->value)
//			{
//				if (temp->right == NULL)
//				{
//					temp->right = newNode;
//					break;
//				}
//				temp = temp->right;
//			}
//			else if (value < temp->value)
//			{
//				if (temp->left == NULL)
//				{
//					temp->left = newNode;
//					break;
//				}
//				temp = temp->left;
//			}
//			else
//			{
//				//Do not insert Duplicates
//				break;
//			}
//		}
//	}
//}
//
//void BST::remove(int value)
//{
//	root = deleteNode(root, value);
//}
//
//BSTNode* BST::deleteNode(BSTNode* root, int value)
//{
//	if (root == NULL) return root;
//
//	if (value < root->value)
//		root->left = deleteNode(root->left, value);
//
//	else if (value > root->value)
//		root->right = deleteNode(root->right, value);
//
//
//	else
//	{
//		// node with only one child or no child 
//		if (root->left == NULL)
//		{
//			BSTNode *temp = root->right;
//			delete root;
//			return temp;
//		}
//		else if (root->right == NULL)
//		{
//			BSTNode *temp = root->left;
//			delete root;
//			return temp;
//		}
//
//		// node with two children: Get the inorder successor (smallest 
//		// in the right subtree) 
//		BSTNode* temp = findMin(root->right);
//
//		root->value = temp->value;
//
//		root->right = deleteNode(root->right, temp->value);
//	}
//	return root;
//}
///// ------------------------------------------
//BSTNode* BST::finMin() const
//{
//	return findMin(root);
//}
//
////Recursive function to Find the leftmost node in the BST which will be MIN
//BSTNode* BST::findMin(BSTNode* node) const
//{
//	if (node == NULL)
//		return NULL;
//
//	if (node && node->left == NULL)
//		return node;
//
//	findMin(node->left);
//}
///// ------------------------------------------
//BSTNode* BST::finMax() const
//{
//	return findMax(root);
//}
//
////Recursive function to find the rightmost node in the BST which will be MAX
//BSTNode* BST::findMax(BSTNode* node) const
//{
//	if (node == NULL)
//		return NULL;
//
//	if (node && node->right == NULL)
//		return node;
//
//	findMax(node->right);
//}
///// ------------------------------------------
//void BST::preOrderTraversal() const
//{
//	cout << "preOrderTraversal: ";
//	preOrderTraversal(root);
//	cout << endl;
//}
//void BST::preOrderTraversal(BSTNode* node) const
//{
//	if (node != NULL) {
//		cout << node->value << " ";
//		preOrderTraversal(node->left);
//		preOrderTraversal(node->right);
//	}
//}
///// ------------------------------------------
//void BST::inOrderTraversal() const
//{
//	cout << "inOrderTraversal: ";
//	inOrderTraversal(root);
//	cout << endl;
//}
//void BST::inOrderTraversal(BSTNode* node) const
//{
//	if (node != NULL) {
//		inOrderTraversal(node->left);
//		cout << node->value << " ";
//		inOrderTraversal(node->right);
//	}
//}
///// ------------------------------------------
//void BST::postOrderTraversal() const
//{
//	cout << "postOrderTraversal: ";
//	postOrderTraversal(root);
//	cout << endl;
//}
//void BST::postOrderTraversal(BSTNode* node) const
//{
//	if (node != NULL) {
//		postOrderTraversal(node->left);
//		postOrderTraversal(node->right);
//		cout << node->value << " ";
//	}
//}
//
//const int SIZE = 15;
//int main()
//{
//	BST bst;
//	int values[SIZE] = { 5, 2, 12, -4, 3, 9, 21, -7, 19, 25, -8, -6, -4, 3, 12 };
//	for (int i = 0; i < SIZE; i++)
//		bst.insert(values[i]);
//
//	bst.preOrderTraversal(); /// should be 5 2 -4 -7 -8 -6 3 12 9 21 19 25
//	bst.inOrderTraversal(); /// should be -8 -7 -6 -4 2 3 5 9 12 19 21 25
//	bst.postOrderTraversal(); /// should be -8 -6 7 -4 3 2 9 19 25 21 12 5
//
//	bst.remove(3); /// Node 3 has 0 children --> delete the node and make it NULL;
//	bst.remove(-4); /// Node -4 has 1 children --> Link parent to child --> delete the node and make it NULL;
//	bst.remove(12); /// Node 12 has 2 children --> findMin for the right subtree --> swap value -> delete
//
//	bst.preOrderTraversal(); /// should be 5 2 -7 -8 -6 19 9 21 25
//	bst.inOrderTraversal(); /// should be -8 -7 -6 2 5 9 19 21 25
//	bst.postOrderTraversal(); /// should be -8 -6 7 2 9 25 21 19 5
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <unordered_set>
#include <ctime>

using namespace std;

//Employee.h
class Employee
{
public:
	Employee();
	Employee(string name, int id);
	string getFirstName() const;
	string getlastName() const;
	int getYearHired() const;
	string getFullName() const;
	string getDOB() const;
	void setDOB(string dob);
	void setAddress(string addr);
	string getAddress() const;
	void setSalary(double salary);
	double getSalary() const;
	string getTeleNo() const;
	void setTeleNo(string teleNo);
	bool isLastNameSame(Employee e);
	bool isSameSalaryorHiredSameYear(Employee e);
	int getID() const;
	void setFirstName(string name);
	void setlastName(string name);
	void setId(int id);
	friend ostream& operator << (ostream& out, const Employee e);
private:
	string m_firstname;
	string m_lastname;
	string m_dob;
	string m_address;
	int m_yearHired;
	double m_Salary;
	string m_teleNo;
	int m_areaCode;
	int m_id;
};

//Employee.cpp
//#include "Employee.h"
Employee::Employee()
{
}

Employee::Employee(string firstname, int id):m_firstname(firstname),m_id(id)
{
}

string Employee::getFirstName() const
{
	return m_firstname;
}

string Employee::getlastName() const
{
	return m_lastname;
}

int Employee::getYearHired() const
{
	return m_yearHired;
}

string Employee::getFullName() const
{
	return m_firstname + " " + m_lastname;
}

string Employee::getDOB() const
{
	return m_dob;
}

void Employee::setDOB(string dob)
{
	m_dob = dob;
}

void Employee::setAddress(string addr)
{
	m_address = addr;
}

string Employee::getAddress() const
{
	return m_address;
}

void Employee::setSalary(double salary)
{
	m_Salary = salary;
}

double Employee::getSalary() const
{
	return 0.0;
}

string Employee::getTeleNo() const
{
	return m_teleNo;
}

void Employee::setTeleNo(string teleNo)
{
	m_teleNo = teleNo;
}

bool Employee::isLastNameSame(Employee e)
{
	return this->m_lastname == e.m_lastname;
}

bool Employee::isSameSalaryorHiredSameYear(Employee e)
{
	return (m_Salary == e.m_Salary) || (m_yearHired == e.m_yearHired);
}


int Employee::getID() const
{
	return m_id;
}

void Employee::setFirstName(string name)
{
	m_firstname = name;
}

void Employee::setlastName(string name)
{
	m_lastname = name;
}

void Employee::setId(int id)
{
	m_id = id;
}

ostream& operator << (ostream& out, const Employee e)
{
	out << e.m_id << "  " << e.m_firstname;
	return out;
}

//Department.h
class Department
{
public:
	Department(string id);
	string getId() const;
	string getName() const;
	void setName(string name);
	string getHistory() const;
	void setHistory(string history);
	void addEmployee(Employee e);
	void removeEmployee(Employee e);
	bool isEMployeePresent(int id);
	void printEmployees();
	void noofEmployees();
private:
	string m_deptID;
	string m_name;
	string m_deptHistory;
	Employee m_Employees[25];
	int m_employeeCount = 0;
};

Department::Department(string id):m_deptID(id)
{

}

//Department.cpp
string Department::getId() const
{
	return m_deptID;
}

string Department::getName() const
{
	return m_name;
}

void Department::setName(string name)
{
	m_name = name;
}

string Department::getHistory() const
{
	return m_deptHistory;
}

void Department::setHistory(string history)
{
	m_deptHistory = history;
}

void Department::addEmployee(Employee e)
{
	if (m_employeeCount == 25)
		return;
	m_Employees[m_employeeCount++] = e;
}

void Department::removeEmployee(Employee e)
{
	int  i = 0;
	for (; i < m_employeeCount; i++)
	{
		if (m_Employees[i].getID() == e.getID())
		{
			break;
		}
	}

	for (int j = i; j < m_employeeCount - 1; j++)
	{
		m_Employees[j] = m_Employees[j + 1];
	}

	--m_employeeCount;
}

bool Department::isEMployeePresent(int id)
{
	int  i = 0;
	for (; i < m_employeeCount; i++)
	{
		if (m_Employees[i].getID() == id)
		{
			return true;
		}
	}
	return false;
}

void Department::printEmployees()
{
	cout << endl;
	for (int i = 0; i < m_employeeCount; i++)
	{
		cout << m_Employees[i]<<"\n";
	}
}

void Department::noofEmployees()
{
	cout << "\n Noof Employees : " << m_employeeCount;
}


#include<iostream>
#include <queue>

using namespace std;

// Node of Each Tree

struct node
{
	int data;
	node *left;
	node *right;
};

//Create New Node of Each tree

node *newNode(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//Inorder Traversal of Tree

void inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

//Insertion Of Binary search Tree
node* binarySearchTree(node* head, int data)
{
	if (head == NULL) return newNode(data);

	if (data < head->data)
		head->left = binarySearchTree(head->left, data);
	else if (data > head->data)
		head->right = binarySearchTree(head->right, data);
	return head;
}

//Calculate Height of Tree
int height(node* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int l = height(root->left);
		int r = height(root->right);
		return max(l, r) + 1;
	}
}

// Caluclate Single Parents of Binary Search Tree

int singleParent(node *root) {
	queue<node*> qp;
	int ans = 0;
	if (root == NULL) {
		return 0;
	}
	qp.push(root);
	while (!qp.empty()) {
		node *f = qp.front();
		qp.pop();

		if ((f->left != NULL && f->right == NULL) || (f->right != NULL && f->left == NULL)) {
			ans++;
		}
		if (f->left != NULL) {
			qp.push(f->left);
		}

		if (f->right != NULL) {
			qp.push(f->right);
		}
	}
	return ans;
}

#include <sstream>

void List(int boxes[], string names[], int& N)
{
	int count = 0;
	while (true)
	{
		cout << "\nInput the number of boxes Sold : ";
		int n;
		cin >> n;
		if (n == 0)
			break;
		cout << "\nWhat is the customers name ? :";
		string name;
		cin >> name;
		boxes[count] = n;
		names[count] = name;
		count++;
	}
	N = count;
}

bool GetCustomer(int* NBoxes, string* CName,int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << CName[i] << " bought " << NBoxes[i] << " of cookies";
		cout << endl;
	}
	return true;
}

#include <iostream>
#include <string>
#include <fstream>

using namespace  std;

bool isVowel(char ch)
{
	ch = std::tolower(ch);
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}
	return false;
}

string encrypt(string inString)
{
	string encryptedString = "";
	for (char ch : inString)
	{
		if (ch == ' ')
			encryptedString += '*';
		else if (isVowel(ch)); //if it is vowel dont append in the encrypted string
		else
		{
			encryptedString += ch;
		}
	}
	return encryptedString;
}


#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

// To check if strings differ by exactly one character
bool isadjacent(string& a, string& b)
{
	int count = 0; // to store count of differences
	int n = a.length();

	// Iterate through all characters and return false
	// if there are more than one mismatching characters
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) count++;
		if (count > 1) return false;
	}
	return count == 1 ? true : false;
}

// A queue item to store word and minimum chain length
// to reach the word.
struct QItem
{
	string word;
	int len;
};

// Returns length of shortest chain to reach 'target' from 'start'
// using minimum number of adjacent moves. D is dictionary
int shortestChainLen(string& start, string& target, set<string> &D)
{
	// Create a queue for BFS and insert 'start' as source vertex
	queue<QItem> Q;
	QItem item = { start, 1 }; // Chain length for start word is 1
	Q.push(item);

	// While queue is not empty
	while (!Q.empty())
	{
		// Take the front word
		QItem curr = Q.front();
		Q.pop();

		// Go through all words of dictionary
		set<string>::iterator it = D.begin();
		while (it != D.end())
		{
			// Process a dictionary word if it is adjacent to current
			// word (or vertex) of BFS
			string temp = *it;
			if (isadjacent(curr.word, temp))
			{
				// Add the dictionary word to Q
				item.word = temp;
				item.len = curr.len + 1;
				Q.push(item);

				// Remove from dictionary so that this word is not
				// processed again. This is like marking visited
				D.erase(temp);
				it = D.begin();

				// If we reached target
				if (temp == target)
					return item.len;
			}
			else
			{
				++it;
			}
		}
	}
	return 0;
}

char* xstrcat(char* dest, char* source)
{
	int x = strlen(dest);
	int y = strlen(source);

	dest = (char*)realloc(dest, sizeof(char) * (x + y + 1));
	int  i = 0;
	for (;i < y;i++)
	{
		dest[x + i] = source[i];
	}

	dest[x + i] = '\0';

	return dest;
}

enum class CourseStatus
{
	Open,
	Closed,
	Cancelled
};

class Course
{
private:
	string universityCourseIdNo;
	string deptCourseID;
	int sectionNo;
	int noofCredits;
	vector<int> daysMeet;
	vector<int> timesMeet;
	int roomNo;
	int maxCourseEnrollment;
	string campusHeld;
	string nameofCourseInstr;
	int noofStudentsEnrolled;
	vector<string> StudentID;
	CourseStatus status_;
public:
	Course(string courseId,string deptCourseId):universityCourseIdNo(courseId)
	,deptCourseID(deptCourseId)
	{
		
	}
	void addSectionNoNoofCredits(int secNo,int noofCredit)
	{
		sectionNo = sectionNo;
		noofCredits = noofCredit;
	}
	void addDaysandTimeMeet(int day,int time)
	{
		daysMeet.push_back(day);
		timesMeet.push_back(time);
	}
	void setRoomNo(int room)
	{
		roomNo = room;
	}
	void setMaxCourseEnrollment(int max)
	{
		maxCourseEnrollment = max;
	}
	//Similarly the other parameters can be set
	void enroll(string studentId)
	{
		StudentID.push_back(studentId);
		noofStudentsEnrolled++;
	}
	void setCourseStatus()
	{
		if (noofStudentsEnrolled < maxCourseEnrollment)
			status_ = CourseStatus::Open;
		else if (noofStudentsEnrolled == 0)
			status_ =  CourseStatus::Cancelled;

		status_ =  CourseStatus::Closed;
	}
};
//#include <iostream>
//
//using namespace std;

struct disc
{
	char* title;
	char* director;
	int year;
	int runtime;
	char* genre;
	char* pic;
};

typedef disc* discPtr;
#define MAX	 100
discPtr DB[MAX];
bool selected[MAX];
int numDB;

void LoadDB()
{
	ifstream fin;

	fin.open("HDDB.txt");

	if (!fin.is_open())
		return;

	while (!fin.eof())
	{
		discPtr ptr = new disc();
		string line1;
		getline(fin, line1);
		if (fin.eof())
			break;
		ptr->title =  new char[line1.length() + 1];
		strcpy_s(ptr->title, line1.length() + 1, line1.c_str());
		fin >> ptr->year;
		string genre;
		fin >> genre;
		ptr->genre = new char[genre.length() + 1];
		strcpy_s(ptr->genre, genre.length() + 1, genre.c_str());

		fin >> ptr->runtime;
		string pic;
		fin >> pic;
		ptr->pic = new char[pic.length() + 1];
		strcpy_s(ptr->pic, pic.length() + 1, pic.c_str());
		string dirname;
		getline(fin, dirname, '\n');
		ptr->director = new char[dirname.length() + 1];
		strcpy_s(ptr->director, dirname.length() + 1, dirname.c_str());
		DB[numDB++] = ptr;
	}

}

class SystemUser
{
public:
	SystemUser()
	{
		m_userName = "";
		m_passWord = "";
	}
	SystemUser(string userName,string passWord)
	{
		m_userName = userName;
		m_passWord = passWord;
	}

	string getUserName() const
	{
		return m_userName;
	}

	string setUserName(string userName)
	{
		m_userName = userName;
	}

	bool checkPassword(string passWord)
	{
		bool isUpperCasePresent = false;
		bool islowerCasePresent = false;
		bool isDigitCasePresent = false;
		for(auto ch : passWord)
		{
			if (islower(ch))
				islowerCasePresent = true;
			else if (isupper(ch))
				isUpperCasePresent = true;
			else if (isdigit(ch))
				isDigitCasePresent = true;
		}

		if (isUpperCasePresent && islowerCasePresent 
			&& isDigitCasePresent && passWord.length() > 8)
			return true;

		return false;
	}

	bool updatePassword(string oldPassword,string newPassWord)
	{
		if (oldPassword != m_passWord || !checkPassword(newPassWord))
			return false;

		m_passWord = newPassWord;

		return true;
	}

	bool operator ==(const SystemUser& user)
	{
		if (m_userName == user.m_userName)
			return true;

		return false;
	}

	bool operator !=(const SystemUser& user)
	{
		if (m_userName != user.m_userName)
			return true;

		return false;
	}

	friend  ostream& operator << (ostream& out, const SystemUser& user);
	

	friend istream& operator >> (istream& in, SystemUser& user);

private:
	string m_userName;
	string m_passWord;

};

ostream& operator << (ostream& out, const SystemUser& user)
{
	out << user.m_userName << "  " << user.m_passWord;
	return out;
}

istream& operator >> (istream& in, SystemUser& user)
{
	in >> user.m_userName >> user.m_passWord;
	return in;
}

#include <iostream>

using namespace std;

class Passenger
{
protected:
	string m_name;
	string m_id;
	int m_age;
	int milesTravelling;
public:
	Passenger(string name, int age, string id, int miles)
	{
		m_name = name;
		m_age = age;
		m_id = id;
		milesTravelling = miles;
	}
	virtual int getTicketCost() = 0;
};

//class Person : public Passenger
//{
//public:
//	Person(string name,int age,string id,int miles):Passenger(name
//	,age,id,miles)
//	{
//		
//	}
//	int getTicketCost() override
//	{
//		if (m_age < 20)
//			return milesTravelling * 120;
//		return milesTravelling * 150;
//	}
//};

class Pet : public Passenger
{
public:
	Pet(string name, int age, string id, int miles) :Passenger(name
		, age, id, miles)
	{

	}
	int getTicketCost() override
	{
		if (m_age < 5)
			return milesTravelling * 80;
		return milesTravelling * 120;
	}
};
class Flight
{
	vector<Passenger*> passengers;
public:
	void addPassenger(Passenger* p)
	{
		passengers.push_back(p);
	}
	int calculateTotalRevenue()
	{
		int totalRevenue = 0;
		for(auto& p : passengers)
		{
			totalRevenue += p->getTicketCost();
		}

		return totalRevenue;
	}
};

#define SIZE 5
//#include <stdexcept>

template<typename T>
T& safe_at(T arr[],size_t index)
{
	if (index >= SIZE)
		throw std::out_of_range("Index out of range");

	return arr[index];
}

template <class T> class OrderedIterator; //forward declaration

template <class T>
class OrderedCollection {
	// =================
	friend class OrderedIterator<T>;
	const int capacity; //maximum size of the container
	int size; //number of actual elements in the container
	T **buffer; //pointer to memory for holding elements

public:
	OrderedCollection(int aCapacity = 100);
	OrderedCollection(const OrderedCollection<T> & c);
	~OrderedCollection();

	typedef OrderedIterator<T> iterator;

	int getSize() const { return size; } //answer number of elements
	bool isFull()const { return size == capacity; } //answer if full

	OrderedCollection<T> & addLast(T & element); //add to end
	OrderedCollection<T> & addFirst(T & element); //add to front
	T & removeLast();//remove last element
	T & removeFirst(); //remove first element
	OrderedCollection<T> & remove(const T & element); //remove all items == element
	iterator begin(void); //provide an start iterator
	iterator end(void); //provide an end iterator

	void print() {
		cout << "Collection\n";
		cout << "==========\n";
		for (int i = 0; i < size; i++) cout << *buffer[i];
	}

};

template <class T>
class OrderedIterator { //The iterator class
// ===============
	int index; //location in the container being iterated
	OrderedCollection<T> & s; //container being iterated

public:
	OrderedIterator(OrderedCollection<T> & set, int position = 0);
	OrderedIterator<T> & operator++(int); //to advance to next element
	T & operator*(); //to get element
	bool operator==(const OrderedIterator<T> & iter);
	bool operator!=(const OrderedIterator<T> & iter);
};


//Constructor Implementations
template <class T>
OrderedCollection<T>::OrderedCollection(int aCapacity)
	: capacity(aCapacity), size(0), buffer(new T*[aCapacity]) {}

template <class T>
OrderedCollection<T>::OrderedCollection(const OrderedCollection<T> & c)
	: capacity(c.capacity), size(c.size), buffer(new T*[c.capacity]) {
	for (int i = 0; i < capacity; i++) buffer[i] = c.buffer[i];
}

template <class T>
OrderedCollection<T>::~OrderedCollection() { delete[] buffer; }
//Method Implementations

template <class T>
OrderedCollection<T> & OrderedCollection<T>::addLast(T & element) {
	//add only if the entry is not present
	//Changed : checking for the duplicate element to mimic the set behaviour
	bool bEntryFound = false;
	for (int i = 0; i < size; i++)
	{
		if (*buffer[i] == element)
		{
			bEntryFound = true;
			break;
		}
	}
	if(!bEntryFound)
	{
		//Changed : Add only if it is not already present
		if (size < capacity)
			buffer[size++] = &element;
		else
		{
			//Changed : if exceeds the capacity reallocate
			T** tempBuffer = new T*[capacity * 2];
			for (int i = 0;i < size;i++)
			{
				tempBuffer[i] = buffer[i];
			}
			delete[] buffer;
			buffer = tempBuffer;
		}
	}
	
	return *this;
}

template <class T>
OrderedCollection<T> & OrderedCollection<T>::addFirst(T & element) {

	if (size < capacity) {
		size++;
		for (int i = size - 1; i > 0; i--) buffer[i] = buffer[i - 1];
		buffer[0] = &element;
	}

	return *this;
}

template <class T>
T & OrderedCollection<T>::removeLast() {
	return *buffer[size--];
}

template <class T>
T & OrderedCollection<T>::removeFirst() {
	T* temp;
	size--;
	temp = buffer[0];
	for (int i = 0; i < size; i++)   buffer[i] = buffer[i + 1];
	return *temp;
}

template <class T>
OrderedCollection<T> & OrderedCollection<T>::remove(const T & item) {

	//remove all elements which are == item (assume T implements == oper)
	int newIndex = 0;
	for (int i = 0; i < size; i++) {
		if (*buffer[i] != item) buffer[newIndex++] = buffer[i];
	}
	size = newIndex;
	return *this;
}


template <class T>
typename OrderedCollection<T>::iterator OrderedCollection<T>::begin(void) { //provide an start iterator
	return OrderedIterator<T>(*this);
}

template <class T>
typename OrderedCollection<T>::iterator OrderedCollection<T>::end(void) { //provide an end iterator
	return OrderedIterator<T>(*this, size);
}

template <class T>
OrderedIterator<T>::OrderedIterator(OrderedCollection<T> & set, int position)
	: index(position), s(set) {}

template <class T>
OrderedIterator<T> & OrderedIterator<T>::operator++(int) {
	index++; return *this;
}

template <class T>
T & OrderedIterator<T>::operator*() {
	return *(s.buffer[index]);

}

template <class T>
bool OrderedIterator<T>::operator==(const OrderedIterator<T> & iter) {
	return (&s == &(iter.s)) && (index == iter.index);
}

template <class T>
bool OrderedIterator<T>::operator!=(const OrderedIterator<T> & iter) {
	return !(*this == iter);
}


class BankAccount {
	double balance;
	//Change : added the owner field
	string _owner;
public:
	//changed : initializing owner field
	BankAccount(double anAmount,string owner) :balance(anAmount),_owner(owner) {}
	bool operator== (const BankAccount & b)
	{
		//Changed :  added both balance and owner for equality checking
		return (this->balance == b.balance && this->_owner == b._owner);
	}
	bool operator!= (const BankAccount & b)
	{
		//Changed : added both the balance and owner for inequality checking
		return (this->balance != b.balance || this->_owner != b._owner);
	}
	void printOn(ostream & o) const
	{
		//Changed : added owner and balance for printing
		o <<_owner<< ": $" << balance << "\n";
	}
};
ostream & operator<<(ostream & o, const BankAccount & b) {
	b.printOn(o);
	return o;
}

////Example of how the collection and iterator could be used
//int main() {
//	//Changed added the name into the constructor parameter
//	BankAccount b1(100.0,"Lou"), b2(100.0,""), b3(200.0,"Mark"), b4(150.0,"Waugh");
//	OrderedCollection<BankAccount> accounts;
//	accounts.addLast(b1).addLast(b2).addLast(b3).addLast(b4).addLast(b2);
//
//	for (OrderedCollection<BankAccount>::iterator itr = accounts.begin();
//		itr != accounts.end(); itr++)
//
//		cout << *itr;
//	accounts.print();
//	accounts.remove(b2);
//	accounts.print();
//	return 0;
//}//end main

void printgaps(vector<int> arr, int maxGap)
{
	for(int i = 1;i <= maxGap;++i)
	{
		cout << i << " : ";
		unordered_set<int> aSet;
		for (int j = 0;j < arr.size();++j)
		{
			if(aSet.find((arr[j] + i)) != aSet.end())
			{
				auto itr = aSet.find((arr[j] + i));
				cout << "[ " << *itr << "," << arr[j]<<" ]";
				aSet.erase(itr);
			}
			else if(aSet.find((arr[j] - i)) != aSet.end())
			{
				auto itr = aSet.find((arr[j] - i));
				cout << "[ " << *itr << "," << arr[j] << " ]";
				aSet.erase(itr);
			}
			aSet.insert(arr[j]);
		}
		cout << endl;
	}
}

class Paragraph
{
	string text;
public:
	Paragraph(){}
	Paragraph(string doc) :text(doc){}
	void readFromFile(string fileName)
	{
		ifstream fin;

		fin.open(fileName);

		if (!fin.is_open())
			return;

		string line;
		while (getline(fin,line))
		{
			text += line;
		}
	}
	string getText()
	{
		return text;
	}
	void writeToFile(string fileName)
	{
		ofstream fout;

		fout.open(fileName);

		fout << text;
	}
	void decrypt()
	{
		string temp;
		for(char ch : text)
		{
			temp += (char)((int)ch - 3);
		}
		text = temp;
	}
};

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int maxlen = 15;

char* removeVowels(char name[])
{
	char* namewithVowelsRemoved = new char[maxlen];
	int count = 0;
	for (int i = 0;i < strlen(name);++i)
	{
		char ch = tolower(name[i]);
		if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
		{
			namewithVowelsRemoved[count++] = name[i];
		}
	}
	namewithVowelsRemoved[count] = '\0';
	return namewithVowelsRemoved;
}

string removeVowels(string name)
{
	string namewithVowelsRemoved;
	int count = 0;
	for (char ch : name)
	{
		char temp = tolower(ch);
		if (temp != 'a' && temp != 'e' && temp != 'i' && temp != 'o' && temp != 'u')
		{
			namewithVowelsRemoved += ch;
		}
	}
	return namewithVowelsRemoved;
}

void cstringDemo()
{

	char* guessedName = new char[maxlen];
	char name[] = "Mark Thomas";
	cout << "Guess My Name (first last) :";
	cin.get(guessedName, maxlen);

	if (strcmp(guessedName, name) == 0)
	{
		cout << "\nYou got it right!!";
	}
	else
	{
		cout << "\nNice Try.But incorrect.";
	}

	cout << "\nYou guessed : " << guessedName;
	char* vowelRemovedWord = removeVowels(guessedName);
	cout << "\nWithout Vowels it is :" << vowelRemovedWord;
	strcat(guessedName, " The Barbarian");
	cout << "\n And in less civilized time, it would be " << guessedName;
	delete[] vowelRemovedWord;
}

void stringTypeDemo()
{
	string guessedName;
	string name = "Mark Thomas";
	cout << "Guess My Name (first last) :";
	getline(cin, guessedName);

	if (guessedName == name)
	{
		cout << "\nYou got it right!!";
	}
	else
	{
		cout << "\nNice Try.But incorrect.";
	}

	cout << "\nYou guessed : " << guessedName;
	cout << "\nWithout Vowels it is :" << removeVowels(guessedName);
	guessedName += " The Barbarian";
	cout << "\n And in less civilized time, it would be " << guessedName;
}


struct family
{
	char name[50];
	char street[50];
	char csz[50];
	char relation[50];
	char birthday[50];
};

#include <fstream>
#include <iostream>

using namespace  std;

template<typename T>
void storeValue(ostream& out, T value)
{
	out << value<<"  ";
}

class Pixel
{

public:

	Pixel()
	{
	}

	Pixel(int r, int g, int b) : red(r), green(g), blue(b)
	{
	}

	//GOAL: Define this overloaded insertion operator
	friend ostream& operator <<(ostream&, const Pixel&);

private:

	int red, green, blue;

};

ostream& operator <<(ostream& out, const Pixel& p)
{
	out <<"("<< p.red << "," << p.blue << "," << p.green<<")\n";
	return out;
}

// Abstract Creature
//Demonstrates abstract classes

#include <iostream>
using namespace std;

class Creature //abstract class
{
public:
	Creature(int health = 100);
	virtual void Greet() const = 0;   //pure virtual member function
	virtual void DisplayHealth() const;

protected:
	int m_Health;
};

Creature::Creature(int health) :
	m_Health(health)
{}

void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

class Human : public Creature
{
public:
	Human(int health = 100);
	virtual  void Greet() const;
};

Human::Human(int health):Creature(health)
{
}

void Human::Greet() const
{
	cout << "The human tells hello.\n";
}

class  Elf: public Creature
{
public:
	Elf(int health = 80);
	virtual  void Greet() const;
};

Elf::Elf(int health) :Creature(health)
{
}

void Elf::Greet() const
{
	cout << "The Elf tells hello.\n";
}

class Dwarf : public Creature
{
public:
	Dwarf(int health = 100);
	virtual  void Greet() const;
};

Dwarf::Dwarf(int health) :Creature(health)
{
}

void Dwarf::Greet() const
{
	cout << "The Dwarf grunts hello.\n";
}



class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet() const;
};

Orc::Orc(int health) :
	Creature(health)
{}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}


class  Minion: public Orc
{
public:
	Minion(int health = 120);
	virtual void Greet() const;
};

Minion::Minion(int health) :
	Orc(health)
{}

void Minion::Greet() const
{
	cout << "The Minion orc grunts hello.\n";
}

class  Warrior : public Orc
{
public:
	Warrior(int health = 110);
	virtual void Greet() const;
};

Warrior::Warrior(int health) :
	Orc(health)
{}

void Warrior::Greet() const
{
	cout << "The Warrior orc grunts hello.\n";
}

class  Boss : public Orc
{
public:
	Boss(int health = 150);
	virtual void Greet() const;
};

Boss::Boss(int health) :
	Orc(health)
{}

void Boss::Greet() const
{
	cout << "The Boss orc grunts hello.\n";
}

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Person
{
public:
	string name;
	Person(const string& _name):name(_name),friends(){}

	void addFriend(const Person& p);

	void delFriend(const Person& p);

	void printFriends() const;

	bool hasFriends() const;

	bool isFriendsWith(const Person& other) const;


private:
	unordered_set<const Person*> friends;
};

void Person::addFriend(const Person& p)
{
	friends.insert(&p);
}

void Person::delFriend(const Person& p)
{
	if (friends.empty())
		return;

	auto itr = friends.find(&p);

	if (itr == friends.end())
		return;

	friends.erase(itr);
}

void Person::printFriends() const
{
	for (auto p : friends)
	{
		cout << p->name << "  ";
	}
}

bool Person::hasFriends() const
{
	return !friends.empty();
}

bool Person::isFriendsWith(const Person& other) const
{
	return (friends.find(&other) != friends.end());
}

void deleteOneSidedFriendship(Person& p1, Person& p2)
{
	if(p1.isFriendsWith(p2) && p2.isFriendsWith(p1))
		return;
	p1.delFriend(p2);
}

int main() {



	Person p1(" Severus");

	Person p2(" Lorde");

	Person p3("Scabbers");

	Person p4(" Moony");

	Person p5(" Padfoot");


	
	// bffl's

	p4.addFriend(p5);

	p5.addFriend(p4);



	// don't be friends with rat man

	p4.addFriend(p3);

	p5.addFriend(p3);



	// don't be friends with snake man

	p3.addFriend(p2);



	// don't be friends with grease man

	p2.addFriend(p1);





	unordered_set<Person*> people = { &p1, &p2, &p3, &p4, &p5 };

	cout << "Results:" << endl << endl;





	for (const Person* p : people) {

		if (p->hasFriends()) {

			cout << p->name << " thinks their friends are: ";

			p->printFriends();

			cout << endl;
		}

		else {

			cout << p->name << " doesn't think they have friends." << endl;

		}

	}

	cout << endl;





	for (Person* p1 : people) {

		for (Person* p2 : people) {

			deleteOneSidedFriendship(*p1, *p2);

		}

	}





	for (const Person* p : people) {

		if (p->hasFriends()) {

			cout << p->name << "\'s genuine friends are: ";

			p->printFriends();

			cout << endl;

		}

		else {

			cout << p->name << " has no genuine friends." << endl;

		}

	}

	cout << endl;





	return 0;

}


//#include <iomanip>
//#include <string>
//#include <cctype>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	string fileName;
//	std::cout << "Enter a fileName";
//	getline(cin, fileName);
//
//	ifstream fin;
//	fin.open(fileName);
//
//	while (!fin.is_open())
//	{
//		std::cout << "File Name is Incorrect!please enter fileName again";
//		getline(cin, fileName);
//		fin.open(fileName);
//	}
//
//	string line;
//	int totalCharacterCount = 0;
//
//	std::cout << std::setw(10) << "Line No"
//		<< std::setw(20) << "UpperCase"
//		<< std::setw(20) << "LowerCase"
//		<< std::setw(20) << "DigitCount"
//		<< std::setw(20) << "Punctuation"
//		<< std::setw(10) << "Spaces"
//		<< std::setw(10) << "Others"
//		<< std::setw(20) << "Total Characters";
//
//	std::cout << endl;
//
//	int lineCount = 0;
//
//	int totalspaceCount = 0;
//	int totaldigitCount = 0;
//	int totalupperCase = 0;
//	int totallowerCase = 0;
//	int totalpunctuationCount = 0;
//	int totalother = 0;
//
//	while (getline(fin,line))
//	{
//		int characterCount = 1;
//		int spaceCount = 0;
//		int digitCount = 0;
//		int upperCase = 0;
//		int lowerCase = 0;
//		int punctuationCount = 0;
//		int other = 0;
//
//		for(char ch : line)
//		{
//			if(isspace(ch))
//			{
//				spaceCount++;
//			}
//			else if (isdigit(ch))
//			{
//				digitCount++;
//			}
//			else if(isupper(ch))
//			{
//				upperCase++;
//			}
//			else if(islower(ch))
//			{
//				lowerCase++;
//			}
//			else if(ispunct(ch))
//			{
//				punctuationCount++;
//			}
//			else
//			{
//				other++;
//			}
//			characterCount++;
//		}
//		totalCharacterCount += characterCount;
//		lineCount++;
//
//		totalspaceCount += spaceCount;
//		totaldigitCount += digitCount;
//		totalupperCase += upperCase;
//		totallowerCase += lowerCase;
//		totalpunctuationCount += punctuationCount;
//		totalother += other;
//
//		std::cout << endl;
//
//		std::cout << std::setw(10) << lineCount
//			<< std::setw(20) << upperCase
//			<< std::setw(20) << lowerCase
//			<< std::setw(20) << digitCount
//			<< std::setw(20) << punctuationCount
//			<< std::setw(10) << spaceCount
//			<< std::setw(10) << other
//			<< std::setw(20) << characterCount;
//	}
//
//	std::cout << endl;
//	std::cout << endl;
//	std::cout << std::setw(10) << totalupperCase
//		<< std::setw(20) << totallowerCase
//		<< std::setw(20) << totaldigitCount
//		<< std::setw(20) << totalpunctuationCount
//		<< std::setw(20) << totalspaceCount
//		<< std::setw(20) << totalother;
//
//	std::cout << endl;
//	std::cout << std::setw(10) << setprecision(4) << (float)totalupperCase / (float)totalCharacterCount
//		<< std::setw(20) << setprecision(4) << (float)totallowerCase / (float)totalCharacterCount
//		<< std::setw(20) << setprecision(4) << (float)totaldigitCount / (float)totalCharacterCount
//		<< std::setw(20) << setprecision(4) << (float)totalpunctuationCount / (float)totalCharacterCount
//		<< std::setw(20) << setprecision(4) << (float)totalspaceCount / (float)totalCharacterCount
//		<< std::setw(10) << setprecision(4) << (float)totalother/ (float)totalCharacterCount;
//
//	return 0;
//}

