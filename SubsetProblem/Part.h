#include <string>
#include <iostream>

using namespace std;

class Part
{
public:
	Part(string id, string dwg, int qty);
	string getId();
	void setId(string id);
	string getDrawing();
	void setDrawing(string drawing);
	int getQuantity();
	void setQuantity(int qty);
	string toString();
private:
	string m_identifier;
	string m_drawing;
	int m_quantity;
};


