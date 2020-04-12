#include "pch.h"
#include <string>
#include <iostream>
//#include "vector.h" 

#include <sstream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <functional>
#include <map>
#include <numeric>

using namespace std;

//class vector {
//	int sz; // the size
//	string* elem; // pointer to elements 
//public:
//	vector(int s) :sz(s), elem(new string[s])
//	{
//		for (int i = 0;i < sz;++i)
//		{
//			elem[i] = "-";
//		}
//	} // constructor
//	~vector()
//	{
//		if (elem)
//		{
//			delete[] elem;
//		}
//	}// destructor , deallocates memory 
//	string get(int n)
//	{
//		return elem[n];
//	}//access: read
//	void set(int n, string v)
//	{
//		if (n < sz)
//		{
//			int i = sz - 1;
//			for (;i >= (n - 1);++i)
//			{
//				elem[i + 1] = elem[i];
//			}
//			elem[i] = v;
//		}
//	}// set values
//	int size() const { return sz; } // the number of elements 
//	void print()
//	{
//		for (int i = 0;i < sz;++i)
//		{
//			cout << elem[i] << " ";
//		}
//		cout << ",";
//	}
//
//	vector(const vector& v)
//	{
//		elem = new string[v.sz];
//		sz = v.sz;
//		for (int i = 0;i < sz;++i)
//		{
//			elem[i] = v.elem[i];
//		}
//	}
//
//	vector& operator = (const vector& v)
//	{
//		delete[] elem;
//
//		sz = v.sz;
//
//		elem = new string[sz];
//
//		for (int i = 0;i < sz;++i)
//		{
//			elem[i] = v.elem[i];
//		}
//
//		return *this;
//	}
//
//	string& operator[](int index)
//	{
//		if (index >= sz)
//		{
//			return elem[0];
//		}
//
//		return elem[index];
//	}
//};





string NumbertoString(int number) {
	ostringstream ss;
	ss << number;
	return ss.str();
}

//int main() {
//	vector v1(5);
//	cout << "v1: ";
//	v1.print(); // this should display ,  
//	for (int i = 0; i < v1.size(); ++i) {
//		string s = NumbertoString(i);
//		v1[i] = s;
//	}
//	vector v2 = v1; // copy constructor
//	v1[0] = "-"; // testing deep/shallow copy
//	vector v3(2);
//	cout << "v2: ";
//	v2.print(); // this should display 0, 1, 2, 3, 4 
//	v2[3] = "9"; // testing deep/shallow copy 
//	v3 = v2; // copy assignment 
//	v2[2] = "-"; // testing deep/shallow copy 
//	cout << "v3: ";
//	v3.print(); // this should display 0, 1, 2, 9, 4 
//	cout << "v1: ";
//	v1.print(); // this should display -, 1, 2, 3, 4 
//}
class Integers
{
private:
	int* arr;
	int sz;
public:
	Integers(int size)
	{
		arr = new int[size];
		sz = size;
		for (int i = 0;i < sz;++i)
		{
			arr[i] = i + 1;
		}
	}
	friend void findLargest(Integers i);
	friend void findSmallest(Integers i);
	~Integers()
	{
		for (int i = 0;i < sz;++i)
		{
			arr[i] = 0;
		}
	}
};



void findLargest(Integers integer)
{
	int largest = INT_MIN;

	for (int i = 0;i < integer.sz;++i)
	{
		if (integer.arr[i] > largest)
			largest = integer.arr[i];
	}

	cout << "\nLargest : " << largest;

}

void findSmallest(Integers integer)
{
	int smallest = INT_MAX;

	for (int i = 0;i < integer.sz;++i)
	{
		if (integer.arr[i] < smallest)
			smallest = integer.arr[i];
	}

	cout << "\n Smallest : " << smallest;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class SortedVector
{
public:
	void addItem(T element);
	int removeItem(T element);
	int itemPresent(T element);
	T getItemAt(int index);
	void printList();
private:
	//reason for choosing vector is that it is a dynamic
	//data structure whose size can be increased according to the element
	//insertion and there is minimal wastage of memory
	vector<T> vCollection;
};

template <typename T>
void SortedVector<T>::addItem(T element)
{
	//Complexity O(1)
	vCollection.push_back(element);
}

template <typename T>
int SortedVector<T>::removeItem(T element)
{
	//Complexity O(n)
	//As it has to iterate over all the elements in the worst case if element is not found
	auto itr = std::find(vCollection.begin(), vCollection.end(), element);

	if (itr == vCollection.end())
		return -1;

	vCollection.erase(itr);

	return 0;
}

template <typename T>
int SortedVector<T>::itemPresent(T element)
{
	//Complexity O(n)
	//As it has to iterate over all the elements in the worst case if element is not found
	auto itr = std::find(vCollection.begin(), vCollection.end(), element);

	if (itr == vCollection.end())
		return -1;

	return std::distance(vCollection.begin(), itr);
}

template <typename T>
T SortedVector<T>::getItemAt(int index)
{
	//Complexity O(1)
	if(index < 0 || index >= vCollection.size())
	{
		cout << "\nindex out of range!";
		exit(0);
	}

	return vCollection[index];
}

template <typename T>
void SortedVector<T>::printList()
{
	for(T elem : vCollection)
	{
		cout << elem<<"  ";
	}
}

#include <iostream>
#include <string>
using namespace std;

int hamburger = 20, hot_dog = 10, grilled_cheese = 10, sandwhiches = 10, ketchup = 25, mustard = 25, mayo = 25, order_value = 0, topping_value = 0;

// setting value of ingredients - just hamburger ingredients for now, add more later ( hot dogs / drinks )
// ^^ changed to foods instead of ingredients ^^

// checks ingredients (food stock) and subtracting ingredients (food stock) and notify if no more available ingredients -

void check_ingredients() {
	if (hamburger == 0)
		cout << "we are currently out of hamburgers. \n";
	if (hot_dog == 0)
		cout << "we arecurrently out of hot dogs. \n";
	if (grilled_cheese == 0)
		cout << "we are currently out of grilled cheeses. \n";
	if (sandwhiches == 0)
		cout << "we are currently out of sandwhiches. \n";
	if (ketchup == 0)
		cout << "we are currently out of ketchup. \n";
	if (mustard == 0)
		cout << "we are currently out of mustard. \n";
	if (mayo == 0)
		cout << "we are currently out of mayonnaise. \n";
};
void ordering() {
	cout << "which would you like to order? (please enter the number) \n" << "1. hamburger / 2. hot dog / 3. grilled cheese / 4. sandwhiches \n";
	cin >> order_value;
	while(true)
	{
		if (order_value == 1)
		{
			hamburger -= 1;
			break;
		}
		else if (order_value == 2)
		{
			hot_dog -= 1;
			break;
		}
		else if (order_value == 3)
		{
			grilled_cheese -= 1;
			break;
		}
		else if (order_value == 4)
		{
			sandwhiches -= 1;
			break;
		}
		else
		{
			cout << "\nyou've entered an invalid selection, please enter another. \n";
			cin >> order_value;
		}
	}
	

};
// ^^ correctly removes one from food stock ^^
// ^^ HOW MAKE ANOTHER SELECTION? FOR 'ELSE' ^^

void additional_toppings() {
	cout << "would you like any condiments? (please enter the number) \n" << "1. ketchup / 2. mustard / 3. mayonnaise \n";
	cin >> topping_value;
	while(true)
	{
		if (topping_value == 1)
		{
			ketchup -= 1;
			break;
		}
		else if (topping_value == 2)
		{
			mustard -= 1;
			break;
		}
		else if (topping_value == 3)
		{
			mayo -= 1;
			break;
		}
		else
		{
			cout << "\nyou've entered an invalid selection, please enter another. \n";
			cin >> topping_value;
		}
	}
	
};
void order_summary() {
	int reorder;
	cout << "you ordered xyz" << endl;
	cout << "would you like to order more? 1 for yes, 2 for no." << endl;
	cin >> reorder;
	if (reorder == 1)
		// call order functions again
		cout << " ";
	else // end the function
		cout << "thanks for ordering." << endl;
	cout << endl;
};

#include <iostream>

using namespace std;

void cointoss(int& noofHeads,int& nooftails)
{
	int randValue = ((rand() % (2 - 1 + 1)) + 1);

	if(randValue == 1)
	{
		cout << "\nHeads";
		noofHeads++;
	}
	else if(randValue == 2)
	{
		cout << "\nTails";
		nooftails++;
	}
}


#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

//int main()
//{
//	map<int, int> uMap;
//	cout << "Enter 25 quiz scores between 1 and 10 :";
//	int num;
//	for (int i = 0;i <25;++i)
//	{
//		cin >> num;
//		if (num < 1 || num > 10)
//		{
//			continue;		
//		}
//		uMap[num]++;
//	}
//
//	typedef function<bool(pair<int, int>, pair<int, int>)> Comparator;
//	Comparator cmp = 
//		[](pair<int, int> p1, pair<int, int>  p2)
//	{
//		return p1.second < p2.second;
//	};
//
//	set<pair<int, int>, Comparator> aSet(uMap.begin(), uMap.end(), cmp);
//
//	auto enditr = aSet.end();
//	auto frontitr = aSet.begin();
//	cout << "\nTwo top Most frequently occuring scores are :";
//	cout << frontitr->second<<"  ";
//	++frontitr;
//	cout << frontitr->second;
//
//
//
//	cout << "\nTwo bottom Most frequently occuring scores are :";
//	--enditr;
//	cout << enditr->second<<"   ";
//	--enditr;
//	cout << enditr->second;
//	return 0;
//}

/** Node
 * A basic node contaning an item and a link to the next node in
 * the linked list.
 */
template <class T>
struct Node
{
	T item;
	Node<T>* link;
};

/** stack (linked list implementation)
 * Implementation of the stack ADT as a dynamic linked list. This implementation
 * uses link nodes and grows (and shrinks) the nodes as items popped and pushed
 * onto stack.
 */
template <class T>
class LStack
{
public:
	LStack(); // default constructor
	~LStack(); // destructor
	void clear();
	bool isEmpty() const;
	void push(const T& newItem);
	T top() const;
	void pop();
	int size() const;
	void reverseStack(LStack<T>& otherStack);
private:
	Node<T>* stackTop;
	int numItems;
};

/** stack (list) constructor
 * Constructor for linked list version of stack.
 */
template <class T>
LStack<T>::LStack()
{
	stackTop = NULL;
	numItems = 0;
}

/** stack (list) destructor
 * Destructor for linked list version of stack.
 */
template <class T>
LStack<T>::~LStack()
{
	clear();
}

/** stack (list) clear
 *
 */
template <class T>
void LStack<T>::clear()
{
	Node<T>* temp;

	// iterate through Nodes in stack, freeing them up
	// as we visit them
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;

		// dellocate this Node memory
		delete temp;
	}

	numItems = 0;
}

/** stack (list) isEmpty
 *
 */
template <class T>
bool LStack<T>::isEmpty() const
{
	return stackTop == NULL;
}

/** stack (list) push
 *
 */
template <class T>
void LStack<T>::push(const T& newItem)
{
	// dynamically allocate space for the new Node to hold
	// this newItem
	Node<T>* newNode = new Node<T>;

	// initialize the node
	newNode->item = newItem;
	newNode->link = stackTop;

	// now make this new node the new top of stack
	stackTop = newNode;
	numItems++;
}

/** stack (list) top
 *
 */
template <class T>
T LStack<T>::top() const
{
	//assert(stackTop != NULL)
	if (stackTop == NULL)
	{
		//throw EmptyStackException("LStack<T>::top()");
	}
	else
	{
		return stackTop->item;
	}
}

/** stack (list) pop
 *
 */
template <class T>
void LStack<T>::pop()
{
	//assert(stackTop != NULL)
	if (stackTop == NULL)
	{
		//throw EmptyStackException("LStack<T>::pop()");
	}
	else
	{
		// keep track of the current top, so we can deallocate
		Node<T>* temp;
		temp = stackTop;

		// pop off the top
		stackTop = stackTop->link;

		// deallocate the old top now
		delete temp;

		// update size after removal
		numItems--;
	}
}

/** Stack (list) size
 * Return the current size (number of items) on this stack.
 *
 * @returns int Returns the current stack size.
 */
template <class T>
int LStack<T>::size() const
{
	return numItems;
}

/** reverse stack
 * Copy the elements of this stack in reverse order onto another stack
 *
 * @param otherStack A reference to the other stack.
 *
 * @returns void Nothing returned explicitly, but the otherStack that is passed by
 *   reference will contain a copy of the elements of this stack in reverse order
 *   once this function finishes.
 */
template <class T>
void LStack<T>::reverseStack(LStack<T>& otherStack)
{
	//Clear the other stack
	otherStack.clear();

	//while this stack is not empty push the contents 
	//of this stack to the new stack
	//pop the contents of this stack.
	while(!isEmpty())
	{
		otherStack.push(top());
		pop();
	}
	
}

//pair_class_template.hpp

#include <iostream>

using namespace std;

template<typename T1,typename T2>
class MyPair
{
private:
	T1 value1_;
	T2 value2_;
public:
	MyPair(T1 fValue, T2 sValue) :value1_(fValue),value2_(sValue){}

	T1 getValue1_();
	

	T2 getValue2_();
	

	void display();
	

	void displayReverse();
	

	T1 max_Value();
	

	T1 min_Value();
	

	void swap_Value();


};

//pair_class_template.cpp
//#include "pair_class_template.h"

template <typename T1, typename T2>
T1 MyPair<T1, T2>::getValue1_()
{
	return value1_;
}

template <typename T1, typename T2>
T2 MyPair<T1, T2>::getValue2_()
{
	return value2_;
}

template <typename T1, typename T2>
void MyPair<T1, T2>::display()
{
		cout << "[" << value1_ << "," << value2_ << "]";
}

template <typename T1, typename T2>
void MyPair<T1, T2>::displayReverse()
{
		cout << "[" << value2_ << "," << value1_ << "]";
}

template <typename T1, typename T2>
T1 MyPair<T1, T2>::max_Value()
{
		if (value1_ > value2_)
			return value1_;

		return value2_;
}

template <typename T1, typename T2>
T1 MyPair<T1, T2>::min_Value()
{
		if (value1_ < value2_)
			return value1_;

		return value2_;
}

template <typename T1, typename T2>
void MyPair<T1, T2>::swap_Value()
{
	swap(value1_, value2_);
}

//main.cpp
//#include "pair_class_template.h"

int main() {
	// Create an instance of `MyPair` object called `p1` using `int`
	// and passing in values `3` and `5`
	MyPair<int, int> p1(3, 5);
	// *Start using `p1` to call methods*
	// Call the display method
	p1.display();
	std::cout << "\n";
	// Call the display_reverse method
	p1.displayReverse();
	std::cout << "\n";
	// Call the max_value method and print the value
	std::cout << p1.max_Value() << "\n";
	// Call the min_value method and print the value
	std::cout << p1.min_Value() << "\n";
	// Call the swap_value method;
	p1.swap_Value();
	// Call the display method
	p1.display();
	std::cout << "\n";
	// Call the display_reverse method
	p1.displayReverse();
	std::cout << "\n";
	// Create an instance of `MyPair` object called `p2` using `double`
	// and passing in the values `9.7` and `6.4`
	MyPair<double, double> p2(9.7, 6.4);
	// *Start using `p2` to call methods*
	// Call the display method
	p2.display();
	std::cout << "\n";
	// Call the display_reverse method
	p2.displayReverse();
	std::cout << "\n";
	// Call the max_value method and print the value
	std::cout << p2.max_Value() << "\n";
	// Call the min_value method and print the value
	std::cout << p2.min_Value() << "\n";
	// Call the swap_value method;
	p2.swap_Value();
	// Call the display method
	p2.display();
	std::cout << "\n";
	// Call the display_reverse method
	p2.displayReverse();
	std::cout << "\n";
	// Create an instance of `MyPair` object called `p3` using `char`
	// and passing in the values `a` and `z`
	MyPair<char,char> p3('a','z');
	// *Start using `p3` to call methods*
	// Call the display method
	p3.display();
	std::cout << "\n";
	// Call the display_reverse method
	p3.displayReverse();
	std::cout << "\n";
	// Call the max_value method and print the value
	std::cout << p3.max_Value() << "\n";
	// Call the min_value method and print the value
	std::cout << p3.min_Value() << "\n";
	// Call the swap_value method;
	p3.swap_Value();
	// Call the display method
	p3.display();
	std::cout << "\n";
	// Call the display_reverse method
	p3.displayReverse();
	std::cout << "\n";
	return 0;
}
//ostream& operator <<(ostream& out, const Pair<T1, T2>& p)
//{
//}

#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//int main() {
//	
//	vector<int> aV1(10);
//
//	//fill the vector with the values from 1 to 10
//	std::generate(aV1.begin(),aV1.end(),[]()->int
//	{
//		static int i = 1;
//		return i++;
//	});
//
//	//count the numbers greater than 5
//	int count = std::count_if(aV1.begin(),aV1.end(),[](int num)
//	{
//		return num > 5;
//	});
//
//	cout << "\nNumbers greater than 5 in the given vector are : " << count<<endl;
//
//	//print the vector using for_each
//	std::for_each(aV1.begin(),aV1.end(),[&](int num)
//	{
//		cout << num << " ";
//	});
//
//	//running sum of vector using lambdas
//	int sum = std::accumulate(aV1.begin(),aV1.end(),0);
//
//	cout << "\nSum of elements : " << sum<<endl;
//
//	//STL and lambda to output all the elements which are even
//	std::for_each(aV1.begin(),aV1.end(),[&](int num)
//	{
//		if(num % 2 == 0)
//		{
//			cout << num << " ";
//		}
//	});
//
//	cout << endl;
//
//	//generate to fill the vector with all powers of 2
//	vector<int> v(5);
//
//	std::generate(v.begin(),v.end(),[]()
//	{
//		static int i = 0;
//		++i;
//		return pow(2, i);
//	});
//
//	//print the vector using for_each
//	std::for_each(v.begin(), v.end(), [&](int num)
//	{
//		cout << num << " ";
//	});
//
//
//	return 0;
//}


