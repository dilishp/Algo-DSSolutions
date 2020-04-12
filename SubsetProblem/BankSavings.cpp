#include "pch.h"
#include <stdio.h>
#include <stdint.h>

//************************************************************************************/
//
//                                                          countNumberofOnes
//
//                 Description: Counts the number of 1s in an integer passed as argument
//                 Preconditions:input argument is passed as a pointer
//                 Postconditions:the number of 1s  returned 
//
//                 Calls:                       N/A
//                 Called by:           main
//
//***********************************************************************************/

int  countNumberofOnes(uint32_t *intData)
{
	uint32_t number = *intData;
	// Write a function that  counts number of 1s in an integer passed 
	int noofOnes = 0;
	while (number)
	{
		int digit = number % 10;
		if (digit == 1)
			noofOnes++;
		number = number / 10;
	}
	return noofOnes;
}


//***********************************************************************************/
//*
//*                                                         setBit
//*
//*                Description: The function sets the bit in the specified bit position in an to the specifid value.
//*                Preconditions: Value can be a 1 or 0.  bitPosition will be between 0 and 31 (for integer size argument)
//*                Postconditions: The bit of *inData at position biPosition will be set to value
//*
//*                Calls:                       N/A
//*                Called by:           main
//*
//***********************************************************************************/

void setBit(uint32_t *inData, uint32_t bitPosition, uint32_t  value)
{
	// Please do not treat the  integer as arrays , this question is about bit manipulations
	// You will need to use bitwise operations to solve this question 
	//Storing the 32 bit Value
	uint32_t number = *inData;
	char bitArr[4] = {0};
	int index = 0;
	while (number)
	{
		bitArr[(index/8)] |= (number % 2) << (index % 8);
		number = number / 2;
		++index;
	}

	bitArr[bitPosition / 8] |= value << ((bitPosition - 1) % 8);

}

//***********************************************************************************/
//*                                                     hammingDistance 
//*                     Description: Function hammingDistance calculates total number of bits 
//*             that need to be inverted in order to change inData1 into inData2 or vice versa. 
//*                     Preconditions: The function accepts two unsigned integers as input 
//*                 Postconditions: The function returns the hamming distance
//*
//                 Calls:                       N/A
//                 Called by:           main
//*
//***********************************************************************************/

int hammingDistance(uint32_t inData1, uint32_t inData2)
{
	//Bit array for inData1
	char bitArr1[4] = { 0 };

	int index = 0;
	while (inData1)
	{
		bitArr1[(index / 8)] |= (inData1 % 2) << (index % 8);
		inData1 = inData1 / 2;
		++index;
	}
	//Bit array for inData2
	char bitArr2[4] = { 0 };
	int index1 = 0;
	while (inData2)
	{
		bitArr2[(index1 / 8)] |= (inData2 % 2) << (index1 % 8);
		inData2 = inData2 / 2;
		++index1;
	}

	int hammingDistance = 0;
	for (uint32_t i = 0; i < 32; i++)
	{
		char byte1 = (bitArr1[i / 8] & (1 << (i % 8)));
		char byte2 = (bitArr2[i / 8] & (1 << (i % 8)));
		if (byte1 != byte2)
		{
			++hammingDistance;
		}
	}
	return hammingDistance;

}
//Main function with the variables, and to test the functions.
//
//#include <stdio.h>
//#include "BitManipulations.h"



int main(int *argc, char **argv)
{
	uint32_t Number;
	uint32_t bitPosition;
	uint32_t value;
	int  numOnes;

	uint32_t input1 = 28;
	uint32_t input2 = 24;
	int32_t hDist;


	value = 1;
	bitPosition = 21;
	Number = 15345;

	numOnes = countNumberofOnes(&Number);

	setBit(&Number, bitPosition, value); // set bit in bitposition to value

	hDist = hammingDistance(input1, input2);        // Calculates hamming distance 

	printf("\nHamming Distance = %d \t number of Ones : %d\n", hDist, numOnes);

	return 0;
}
/*
 * BitManipulations.h
 */

#ifndef BITMANIPULATIONS_H_
#define BITMANIPULATIONS_H_


typedef  unsigned int   uint32_t;
typedef  unsigned short uint16_t;



#endif /* BITMANIPULATIONS_H_ */