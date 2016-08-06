#pragma once
namespace bfs
{

	struct Header
	{
		long long number : 64;
	};

	struct EmptyBody
	{
		int emptyInt;
	};

	struct CRHead
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

	struct ConfigHead
	{
		long long bodySize : 64;
		bool fhd : 1;
		bool fullscreen : 1;
	};

}