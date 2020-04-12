#include "pch.h"
#include <iostream>

using namespace std;

void main()
{
	uint16_t A,temp,temp1,comp;
	A = 0xA321;
	temp = A;
	temp1 = A;
	comp = 0x0000;
	printf("%x\n", (A & 0xFF0F));
	printf("%x\n", (A | 0x00F0));
	temp = temp & 0xFF6F;
	temp = temp | (1 << 5);
	temp = temp | (1 << 6);
	printf("%x\n", temp);
	temp1 = temp1 & 0xFF9F;
	temp1 = temp1 | (1 << 7);
	temp1 = temp1 | (1 << 4);
	printf("%x\n", temp1);
	temp = (A & 0x00F0) >> 4;
	temp = ~temp;

	printf("%x\n",(A >> 4) & temp);
	printf("%x\n", (A & 0x0FFF));
}