#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		std::cerr << "  filename: file to process" << std::endl;
		std::cerr << "  s1: string to replace" << std::endl;
		std::cerr << "  s2: replacement string" << std::endl;
		return (1);
	}
	
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	FileReplacer replacer(filename, s1, s2);
	if (!replacer.processFile())
		return (1);
	return 0;
}