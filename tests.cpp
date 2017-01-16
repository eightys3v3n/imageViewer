#include <stdio.h>
#include <string>
#include <vector>
#include <errno.h>
#include "filesystem.hpp"
#include "sorting.hpp"

namespace test
{

struct pair
{
	string f;
	string s;
};

bool directoryContentsSt = false;
bool listImagesSt = false;
bool firstIsFirstCharSt = false;
bool firstIsFirstStringSt = false;
bool sortVectorSt = false;

bool directoryContents()
{
	if (directoryContentsSt)
		return false;

	std::vector<string> contents = ::directoryContents("test_directory");

	if (errno)
	{
		printf("failed to list directory contents\n");
		return true;
	}

	{
		int a = 0;

		for (auto& c : contents)
		{
			if (c == "test_directory1")
				a++;
			else if (c == "test_image1.png")
				a++;
			else if (c == "test_image2.jpeg")
				a++;
		}

		if (a != 3)
		{
			printf("files are not listed correctly\n");
			printf("ensure the following structure exists\n|test_directory\n|-test_image1.png\n|-test_directory1\n|-test_image2.jpeg\n");
			return true;
		}
	}

	contents = ::directoryContents(".");

	if (errno)
	{
		printf("failed to open current directory\n");
		return true;
	}

	if (contents.size() <= 0)
	{
		printf("reported no files in current directory\n");
		return true;
	}

	printf("directoryContents passed\n");
	directoryContentsSt = true;
	return false;
}

bool listImages()
{
	if (listImagesSt)
		return false;

	std::vector<string> images;

	images = ::listImages("test_directory");

	{
		int a = 0;
		for (auto& i:images)
		{
			if (i == "test_image1.png")
				a++;
			else if (i == "test_image2.jpeg")
				a++;
		}

		if (a != 2)
		{
			printf("images are not listed correctly\n");
			printf("ensure the following structure exists\n|test_directory\n|-test_image1.png\n|-test_directory1\n|-test_image2.jpeg\n");
			return true;
		}
	}

	printf("listImages passed\n");
	listImagesSt = true;
	return false;
}

bool firstIsFirstChar()
{
	if (firstIsFirstCharSt)
		return false;

	if (! ::firstIsFirst('a','a'))
	{
		printf("a is not before a (it should be)\n");
		return true;
	}

	if (! ::firstIsFirst('1','1'))
	{
		printf("1 is not before 1 (it should be)\n");
		return true;
	}

	if (! ::firstIsFirst('a','b'))
	{
		printf("a is not before b\n");
		return true;
	}

	if (! ::firstIsFirst('1','2'))
	{
		printf("1 is not before 2\n");
		return true;
	}

	if (! ::firstIsFirst('1','a'))
	{
		printf("1 is not before a\n");
		return true;
	}

	if (::firstIsFirst('b','a'))
	{
		printf("1 is before a\n");
		return true;
	}

	if (::firstIsFirst('2','1'))
	{
		printf("2 is before 1\n");
		return true;
	}

	if (::firstIsFirst('a','1'))
	{
		printf("a is before 1\n");
		return true;
	}

	printf("firstIsFirstChar passed\n");
	firstIsFirstCharSt = true;
	return false;
}

bool firstIsFirstString()
{
	if (firstIsFirstStringSt)
		return false;

	if (firstIsFirstChar())
		return true;

	std::vector<pair> p;

	// should be in correct order
	p = { {"aa","bb"},
				{"ab","ab"},
				{"ab","bb"},
				{"11","22"},
				{"1a","1b"},
				{"11","12"},
				{"2z","3a"},
				{"ba","bc"}};

	for (unsigned int i = 0; i < p.size(); i++)
	{
		if (! firstIsFirst(p[i].f,p[i].s))
		{
			printf("%s is not before %s (it should be)\n", p[i].f.c_str(), p[i].s.c_str());
			return true;
		}
	}

	// should be in incorrect order
	p = { {"bb","aa"},
				{"bb","ab"},
				{"22","11"},
				{"1b","1a"},
				{"12","11"},
				{"3a","2z"},
				{"bc","ba"}};

	for (unsigned int i = 0; i < p.size(); i++)
	{
		if (firstIsFirst(p[i].f,p[i].s))
		{
			printf("%s is before %s (it should not be)\n", p[i].f.c_str(), p[i].s.c_str());
			return true;
		}
	}

	printf("firstIsFirstString passed\n");
	firstIsFirstStringSt = true;
	return false;
}

bool sortVector()
{
	if (sortVectorSt)
		return false;

	if (firstIsFirstString())
		return true;

	std::vector<string> a = {"aaaa",
											"aaaa",
											"aaa1",
											"aaab",
											"baaa",
											"1aaa",
											"1111",
											"1112",
											"111a",
											"111z",
											"9991",};

	::sortVector(a);

	if (a != std::vector<string>{"1111","1112","111a","111z","1aaa","9991","aaa1","aaaa","aaaa","aaab","baaa"})
	{
		printf("sorted wrong {%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s}\n",
			a[0].c_str(),a[1].c_str(),a[2].c_str(),a[3].c_str(),a[4].c_str(),
			a[5].c_str(),a[6].c_str(),a[7].c_str(),a[8].c_str(),a[9].c_str(),a[10].c_str());
		return true;
	}

	printf("sortVector passed\n");
	sortVectorSt = true;
	return false;
}

}


int main()
{
	if (filePath("/hello/asds") != "/hello")
	{
		printf("incorrect file path:%s\n", filePath("/hello/asds").c_str());
		printf("filePath failed\n");
		return 1;
	}
	printf("filePath passed\n");

	if (test::directoryContents())
	{
		printf("directoryContents failed\n");
		return 2;
	}

	if (test::listImages())
	{
		printf("listImages failed\n");
		return 3;
	}

	if (test::sortVector())
	{
		printf("sortVector failed\n");
		return 4;
	}

	return 0;
}