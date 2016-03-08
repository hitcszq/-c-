#include <iostream>
using namespace std;
#include "huff.h"
int main()
{
	huffcode *MIAO = new huffcode();
	MIAO->initial();
	MIAO->build();
	MIAO->encode();
	MIAO->decode();
	return 0;
}