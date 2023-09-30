#include <stdio.h>

//BITEWISE OPERATORS
//int main(void) {
//	//bitwise operator
//	//AND &: compare two operance bit by bit
//	unsigned int a = 3; //0011
//	unsigned int b = 6; //0110
//	//a     b     a & b
//	//0     0     0
//	//0     1     0
//	//1     1     1
//	//1     0     0
//	//a & b = 0010, which is 2
//	
//	//truth table
//	//a     b      a & b
//	//0     0      0
//	//0     1      0
//	//1     0      0
//	//1     1      1
//	printf("a & b = %d\n", a & b);
//	
//	
//	//bitwise OR, result is 1 if at least one of the corresponding
//	// bits in the two operands is 1, or true
//	//a | b = 0111, which is 7
//	//truth table
//	//a     b      a | b
//	//0     0      0
//	//0     1      1
//	//1     0      1
//	//1     1      1
//	printf("a | b = %d\n", a | b);
//
//	//bitwise exclusive XOR, result is 1 if the correspinding
//	//bits in the two operands are different
//	//int a = 3; 0011
//	//int b = 6; 0110
//	//a^b = 0101 
//	
//	//truth table
//	//a     b      a ^ b
//	//0     0      0
//	//0     1      0
//	//1     0      0
//	//1     1      1
//	printf("a ^ b = %d\n", a ^ b);
//	
//	//complement ~ all 0 bits are set to 1,
//	//all 1 bits are set to 0
//	//truth table
//	//a     ~a
//	//0     1
//	//1     0
//	//~b =
//	printf("~b = %x\n", ~b);
//	//int a = 3; 0011
//	//a<<2  1100
//	printf("a<<2 = %d\n", a << 2);
//	//a>>2
//	printf("a>>2 = %d\n", a >> 2);
//}

//USING MASK
//write a fnct to convert decimal int to binary
//input decimal number, output is its binary
//with 16 bits width; using bitewise operator
//void toBinary(unsigned int value);
//
//int main(void) {
//	unsigned int a = 3;
//	toBinary(3);
//}
//
//void tobinary(unsigned int value) {
//	//create mask 10000000
//	unsigned int mask = 1 < 7;
//	printf("Mask %x\n", mask);
//	for (int i = 0; i < 8; i++) {
//		putchar(value & mask ? '1' : '0');
//		value <<= 1;
//	}
//}




