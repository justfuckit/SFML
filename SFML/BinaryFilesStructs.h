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
		long long size : 64;
	};

	struct CRBody
	{
		int left : 16;
		int top : 16;
		int width : 16;
		int height : 16;
	};

	struct ConfigHead
	{
		long long bodySize : 64;
		bool fhd : 1;
		bool fullscreen : 1;
	};

}