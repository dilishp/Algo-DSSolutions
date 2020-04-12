#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Avatar
{
public:
	virtual string getDescription() = 0;
};

class ActualAvatar : public Avatar
{
public:
	string getDescription() override;
};

string ActualAvatar::getDescription()
{
	return "";
}

class AvatarDecorator : public Avatar
{
protected:
	//Avatar being decorated
	Avatar* m_avatar;
public:
	AvatarDecorator(Avatar* avatar):m_avatar(avatar)
	{
		
	}
	string getDescription() override;
};

string AvatarDecorator::getDescription()
{
	return m_avatar->getDescription();
}

class Jacket : public AvatarDecorator
{
public:
	Jacket(Avatar* avatar):AvatarDecorator(avatar)
	{
		
	}
	string getDescription() override;
};

string Jacket::getDescription()
{
	return m_avatar->getDescription() + "Jacket,";
}


class TShirt : public AvatarDecorator
{
public:
	TShirt(Avatar* avatar) :AvatarDecorator(avatar)
	{

	}
	string getDescription() override;
};

string TShirt::getDescription()
{
	return m_avatar->getDescription() + "T-Shirt,";
}

class Jeans : public AvatarDecorator
{
public:
	Jeans(Avatar* avatar) :AvatarDecorator(avatar)
	{

	}
	string getDescription() override;
};

string Jeans::getDescription()
{
	return m_avatar->getDescription() + "Jeans,";
}

class Shorts : public AvatarDecorator
{
public:
	Shorts(Avatar* avatar) :AvatarDecorator(avatar)
	{

	}
	string getDescription() override;
};

string Shorts::getDescription()
{
	return m_avatar->getDescription() + "Shorts,";
}

class Sunglasses : public AvatarDecorator
{
public:
	Sunglasses(Avatar* avatar) :AvatarDecorator(avatar)
	{

	}
	string getDescription() override;
};

string Sunglasses::getDescription()
{
	return m_avatar->getDescription() + "Sunglasses,";
}

class RunningShoes : public AvatarDecorator
{
public:
	RunningShoes(Avatar* avatar) :AvatarDecorator(avatar)
	{

	}
	string getDescription() override;
};

string RunningShoes::getDescription()
{
	return m_avatar->getDescription() + "RunningShoes,";
}

int main()
{
	Avatar* anAvatar = new ActualAvatar();
	vector<string> vDecorators = { "Jacket","T-Shirt","Jeans",
		"Shorts","Sunglasses","RunningShoes" };

	while (true)
	{
		string choice;
		cout << "Please select cosmetic of your character : \n";
		cout << "(Type exit to finish)\n";
		for(string decorator : vDecorators)
		{
			cout << "\n" << decorator;
		}
		cout << "\n>> ";
		cin >> choice;
		if (choice == "exit")
			break;
		int ch = stoi(choice);
		switch (ch)
		{
		case 1:
			anAvatar = new Jacket(anAvatar);
			vDecorators.erase(vDecorators.begin());
			break;
		case 2:
			anAvatar = new TShirt(anAvatar);
			vDecorators.erase(vDecorators.begin() + 1);
			break;
		case 3:
			anAvatar = new Jeans(anAvatar);
			vDecorators.erase(vDecorators.begin() + 2);
			break;
		case 4:
			anAvatar = new Shorts(anAvatar);
			vDecorators.erase(vDecorators.begin() + 3);
			break;
		case 5:
			anAvatar = new Sunglasses(anAvatar);
			vDecorators.erase(vDecorators.begin() + 4);
			break;
		case 6:
			anAvatar = new RunningShoes(anAvatar);
			vDecorators.erase(vDecorators.begin() + 5);
			break;
		default:
			break;
		}
	}
	
	cout << "Your character has the following items : \n";
	string items = anAvatar->getDescription();
	items.pop_back();
	cout << items;
	cout << "\nThank you for using Avatar 1.0.\n";

	return 0;
	
}










