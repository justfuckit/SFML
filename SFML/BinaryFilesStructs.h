#pragma once
struct Header
{
	long long number : 64;
};

struct CRHeader
{
	long long number : 64;
};

struct CRBody
{
	int number1 : 16;
	int number2 : 16;
	int number3 : 16;
	int number4 : 16;
};