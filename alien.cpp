/* Alien Numbers
 * Google Code Jam, Practice
 * Moises Brenes moises.brenes@gmail.com
 */

#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/* convert a string from any base to any base */
string convert(string alien, string source, string target)
{
	string str;
	int a_size;
	int s_size;
	int t_size;
	int dec;
	int i;

	/* alien number size */
	a_size = alien.size();
	/* source language base */
	s_size = source.size();
	/* target language base */
	t_size = target.size();

	str = "";
	dec = 0;

	/* convert x base to decimal */
	for (i = 0; i < a_size; i++)
		dec = dec + (source.find_first_of(alien[i]) * pow(s_size, a_size - 1 - i));

	/* convert decimal to y base */
	while (dec != 0)
	{
		str = (target[dec % t_size] + str);
		dec = (int) (dec / t_size);
	}

	return str;
}

/* explode a string */
void split(string src, string del, vector<string> *dst)
{
	int found;

	found = src.find_first_of(del);
	while (found != string::npos)
	{
		if (found > 0)
			dst->push_back(src.substr(0, found));

		src = src.substr(found + 1);
		found = src.find_first_of(del);
	}

	if (src.length() > 0)
		dst->push_back(src);
}

int main(int argc, char **argv)
{
	char buffer[256];
	int i;
	int top;
	ifstream input;
	string str;
	vector<string> field;

	if (argc == 2)
	{
		input.open(argv[1]);

		input.getline(buffer, 256);
		str = (string) buffer;

		i = 1;
		top = atoi(str.c_str());
		do
		{
			input.getline(buffer, 256);
			str = (string) buffer;

			if (i <= top)
			{
				split(str, " ", &field);
				cout << "Case #" << i << ": " << convert(field[0], field[1], field[2]) << endl;
				field.erase(field.begin(),field.end());
			}

			i++;
		}
		while (!input.eof());

		input.close();
	}

	return 0;
}
