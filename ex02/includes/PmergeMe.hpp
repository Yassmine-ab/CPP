#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	_vectorData; // Tableau dynamique contigu en mémoire
		std::deque<int>		_dequeData; // Double-ended queue (liste de blocs en mémoire)

		bool	isValidNumber(const std::string& str) const;
		int		parseNumber(const std::string& str) const;

		void	fordJohnsonSortVector(std::vector<int>& arr);
		std::vector<size_t>	generateJacobsthalSequence(size_t n);
		size_t	binarySearchInsertVector(const std::vector<int>& arr, int value, size_t end);
	
		void	fordJohnsonSortDeque(std::deque<int>& arr);
		size_t	binarySearchInsertDeque(const std::deque<int>& arr, int value, size_t end);
		
		void	displaySequence(const std::string& prefix, const std::vector<int>& data) const;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		
		void	parseInput(int argc, char** argv);
		void	sort();
};

#endif
