#include<stdio.h>
#include<stdarg.h>
#include<stdint.h>
void tach_bit(int16_t a)
{
	int8_t low = 0, high = 0;
	////Cach 1
	//char* plow = &a;
	//char* phigh = plow + 1;
	//low = *plow;
	//high = *phigh;
	// 
	////Cach 2
	//char* ptr = &a;
	//low = ptr[0];
	//high = ptr[1];
	// 
	//Cach 3
	high =a;
	low = (a >> 8);
	printf("low = 0x%x, high= 0x%x", low, high);
}
void main()
{
	int16_t value = 0xabcd;
	tach_bit(value);
}