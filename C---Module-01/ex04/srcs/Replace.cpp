#include "Replace.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
	: _filename(filename), _s1(s1), _s2(s2)
{
}

FileReplacer::~FileReplacer()
{
}

std::string	FileReplacer::replaceAll(const std::string& str, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found = 0;
	
	if (s1.empty())
		return (str);
	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result += str.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += str.substr(pos);
	return (result);
}

bool	FileReplacer::processFile()
{
	std::ifstream	inputFile(_filename.c_str());
	std::string		content;
	std::string		line;

	if (!inputFile.is_open())
	{
		std::cerr << "Error: Cannot open file " << _filename << std::endl;
		return (false);
	}	
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
			content += "\n";
	}
	inputFile.close();
	std::string		replacedContent = replaceAll(content, _s1, _s2);
	std::string		outputFilename = _filename + ".replace";
	std::ofstream	outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Cannot create file " << outputFilename << std::endl;
		return (false);
	}
	outputFile << replacedContent;
	outputFile.close();
	std::cout << "File processed successfully. Output: " << outputFilename << std::endl;
	return (true);
}

/*
std::string::npos est une constante spéciale qui signifie "pas trouvé"
std::ifstream  inputFile;  Pour LIRE un fichier
std::ofstream  outputFile; Pour ÉCRIRE un fichier
.c_str() est une méthode qui convertit std::string en const char*
car c++98 attend un pointeur C-style
*/