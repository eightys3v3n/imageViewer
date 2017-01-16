#include "sorting.hpp"

bool firstIsFirst(char a, char b)
{
	if ((int)a > (int)b)
		return false;

	return true;
}

bool firstIsFirst(string a, string b)
{
	// shortest string is always first
	if (a.length() > b.length())
	{
		string c = a;
		a = b;
		b = c;
	}

	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
			continue;

		else if (! firstIsFirst(a[i], b[i]))
			return false;
		else
			return true;
	}

	return true;
}

void sortVector(std::vector<string>& vec)
{
	for (unsigned int a = 0; a < vec.size(); a++)
	{
		for (unsigned int b = a+1; b < vec.size(); b++)
		{
			if (! firstIsFirst(vec[a], vec[b]))
			{
				string c = vec[a];
				vec[a] = vec[b];
				vec[b] = c;
			}
		}
	}
}