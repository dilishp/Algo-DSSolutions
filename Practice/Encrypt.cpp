#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

class encrypt_decrypt
{
public:
	encrypt_decrypt()
	{

	}

	int getascii(char c)
	{
		return (int)c;
	}

	void convert_binary_flip(int num)
	{
		bin_num = bitset<8>(num);
		complement = bin_num.to_string('1', '0');
	}

	string getvalue()
	{
		return complement;
	}

	void reverse_bits()
	{
		reverse(complement.begin(), complement.end());
	}

	void decrypt_ones()
	{
		bin_num = bitset<8>(complement);
		reversed = bin_num.to_string('1', '0');
	}

	void decrypt_reverse(bitset<8> a)
	{
		complement = a.to_string();
		reverse(complement.begin(), complement.end());
	}

	void decrypt_words()
	{
		bin_num = bitset<8>(reversed);
		complement = char(bin_num.to_ulong());
	}

	friend ofstream& operator << (ofstream& fout, const encrypt_decrypt& encObj)
	{
		fout << encObj.complement;
		return  fout;
	}

	friend ifstream& operator >> (ifstream& fin, bitset<8>& bitObj)
	{
		string binNum;
		fin >> binNum;
		bitObj = bitset<8>(binNum);
		return fin;
	}
private:
	bitset<8> bin_num;
	string complement;
	string reversed;
};

int main()
{
	encrypt_decrypt enc;

	ifstream file1;
	file1.open("input.txt");
	if (!file1.is_open())
	{
		return 0;
	}
	ofstream file2;
	file2.open("encrypt1.txt");

	char c;

	while (file1.get(c))
	{
		int ascii_value = enc.getascii(c);

		enc.convert_binary_flip(ascii_value);

		enc.reverse_bits();

		file2 << enc.getvalue();
	}

	file1.close();
	file2.close();

	ifstream file3;
	file3.open("encrypt1.txt");
	ofstream file4;
	file4.open("decypt1.txt");

	bitset<8> revbits;

	while (file3 >> revbits)
	{
		enc.decrypt_reverse(revbits);

		enc.decrypt_ones();

		enc.decrypt_words();

		file4 << enc.getvalue();
	}

	file3.close();
	file4.close();
}
