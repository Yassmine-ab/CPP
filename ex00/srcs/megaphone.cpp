#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
			cout << (char)toupper(arg[j]);
	}
	cout << endl;
	return (0);
}
