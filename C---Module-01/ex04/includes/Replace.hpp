#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class	FileReplacer
{
	private:
	std::string _filename;
	std::string _s1;
	std::string _s2;
	
	public:
	FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
	~FileReplacer();

	bool processFile();
	
	private:
	std::string replaceAll(const std::string& str, const std::string& from, const std::string& to);
};

#endif