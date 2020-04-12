#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class TextBook
{
public:
	string m_title;
	string m_author;
	string m_isbn;
	TextBook* m_next;
public:
	TextBook(string title, string author, string isbn):m_title(title),m_author(author),m_isbn(isbn),m_next(nullptr)
	{

	}
};

//library.h
class Library
{
	TextBook* m_head;
public:
	Library(TextBook* head):m_head(head)
	{}

	void addBook(string title, string author, string ISBN);
	void removeBook(string ISBN);
	void print();
	void print(char startingLetter);
	void print(string author);
	TextBook at(int index);
	int getSize();
	bool isEmpty();
};

//#include "library.h"
//library.cpp
void Library::addBook(string title, string author, string ISBN)
{
	TextBook* book = new TextBook(title, author, ISBN);

	if (nullptr == m_head)
	{
		m_head = book;
		return;
	}

	TextBook* node = m_head;
	TextBook* prevNode = nullptr;
	while (node)
	{
		if (title < node->m_title)
		{
			break;
		}
		prevNode = node;
		node = node->m_next;
	}
	//Insert at the end
	if (nullptr == node && prevNode)
	{
		prevNode->m_next = book;
	}
	//Insert at the front
	else if (nullptr == prevNode)
	{
		book->m_next = m_head;
		m_head = book;
	}
	//Insert at the middle
	else
	{
		book->m_next = prevNode->m_next;
		prevNode->m_next = book;
	}
}

void Library::removeBook(string ISBN)
{
	TextBook* node = m_head;
	TextBook* prevNode = nullptr;
	while (node)
	{
		if (ISBN == node->m_isbn)
		{
			break;
		}
		prevNode = node;
		node = node->m_next;
	}

	if (nullptr == prevNode)
	{
		m_head = node->m_next;
		delete node;
	}
	else if (nullptr == node->m_next)
	{
		prevNode->m_next = nullptr;
		delete node;
	}
	else if(node && prevNode)
	{
		prevNode->m_next = node->m_next;
		delete node;
	}
}

void Library::print()
{
	TextBook* node = m_head;
	while (node)
	{
		cout << "Title :" << node->m_title<<"  ";
		cout << "Author :" << node->m_author<<"  ";
		cout << "ISBN :" << node->m_isbn<<"  ";
		cout << "\n\n";
		node = node->m_next;
	}
}

void Library::print(char startingLetter)
{
	TextBook* node = m_head;
	while (node)
	{
		if (node->m_title[0] == startingLetter)
		{
			cout << "Title :" << node->m_title << "  ";
			cout << "Author :" << node->m_author << "  ";
			cout << "ISBN :" << node->m_isbn << "  ";
			cout << "\n\n";
		}
		node = node->m_next;
	}
}

void Library::print(string author)
{
	TextBook* node = m_head;
	while (node)
	{
		if (node->m_author == author)
		{
			cout << "Title :" << node->m_title << "  ";
			cout << "Author :" << node->m_author << "  ";
			cout << "ISBN :" << node->m_isbn << "  ";
			cout << "\n\n";
		}
		node = node->m_next;
	}
}

TextBook Library::at(int index)
{
	TextBook* node = m_head;
	int nodeCount = 0;
	while (node)
	{
		nodeCount++;
		if (index == nodeCount)
		{
			return *node;
		}
		node = node->m_next;
	}
}

int Library::getSize()
{
	TextBook* node = m_head;
	int nodeCount = 0;
	while (node)
	{
		nodeCount++;
		node = node->m_next;
	}
	return nodeCount;
}

bool Library::isEmpty()
{
	if (nullptr == m_head)
		return true;

	return false;
}
