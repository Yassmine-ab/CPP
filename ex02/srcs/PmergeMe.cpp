#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vectorData = other._vectorData;
		this->_dequeData = other._dequeData;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::isValidNumber(const std::string& str) const
{
	if (str.empty())
		return (false);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

int PmergeMe::parseNumber(const std::string& str) const
{
	if (isValidNumber(str) == false)
		throw std::runtime_error("Error: invalid input");
	
	long num = std::atol(str.c_str());
	
	if (num < 0 || num > 2147483647)
		throw std::runtime_error("Error: number out of range");
	
	return (static_cast<int>(num));
}

void PmergeMe::parseInput(int argc, char** argv)
{
	if (argc < 2)
		throw std::runtime_error("Error: no input provided\nUsage: ./PmergeMe <positive integers>");
	
	for (int i = 1; i < argc; i++)
	{
		int num = parseNumber(argv[i]);
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
}

void PmergeMe::displaySequence(const std::string& prefix, const std::vector<int>& data) const
{
	std::cout << prefix;
	for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << data[i];
		if (i < data.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

// ================ ALGORITHME FORD-JOHNSON (VECTEUR) ================

// Génère la séquence de Jacobsthal pour l'ordre d'insertion optimal
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
		return (jacobsthal);
	
	// Calculer les nombres de Jacobsthal: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
	jacobsthal.push_back(0);
	if (n == 1)
		return (jacobsthal);
	
	jacobsthal.push_back(1);
	
	while (true)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >= n)
			break;
		jacobsthal.push_back(next);
	}
	
	return (jacobsthal);
}

// Recherche binaire pour trouver la position d'insertion
size_t PmergeMe::binarySearchInsertVector(const std::vector<int>& arr, int value, size_t end)
{
	size_t left = 0;
	size_t right = end;
	
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	
	return (left);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
	size_t n = arr.size();

	if (n <= 1)
		return;
	
	// Pour les petits tableaux, tri par insertion simple
	if (n <= 10)
	{
		for (size_t i = 1; i < n; i++)
		{
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
		return;
	}
	
	// Phase 1: Former les paires et comparer
	std::vector<std::pair<int, int> > pairs;
	bool isOdd = (n % 2 != 0);
	int straggler = isOdd ? arr[n - 1] : 0;
	
	// Créer les paires (grand, petit)
	for (size_t i = 0; i < n - (isOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	
	// Phase 2: Trier récursivement les "grands" éléments
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);

	fordJohnsonSortVector(largers);
	
	// Réorganiser les paires selon l'ordre des grands
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largers[i])
			{
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	
	// Phase 3: Construire la chaîne principale
	// Commencer avec le premier petit (forcément le plus petit)
	std::vector<int> mainChain;
	if (!sortedPairs.empty())
	{
		mainChain.push_back(sortedPairs[0].second);
		// Ajouter tous les grands
		for (size_t i = 0; i < sortedPairs.size(); i++)
			mainChain.push_back(sortedPairs[i].first);
	}
	
	// Phase 4: Insérer les autres petits selon la séquence de Jacobsthal
	if (sortedPairs.size() > 1)
	{
		std::vector<size_t> jacobsthal = generateJacobsthalSequence(sortedPairs.size());
		std::vector<bool> inserted(sortedPairs.size(), false);
		inserted[0] = true; // Le premier petit est déjà inséré
		
		// Parcourir selon la séquence de Jacobsthal
		for (size_t i = 1; i < jacobsthal.size(); i++)
		{
			size_t start = jacobsthal[i - 1];
			size_t end = jacobsthal[i];
			
			// Insérer en ordre décroissant dans ce groupe
			for (size_t j = end; j > start && j < sortedPairs.size(); j--)
			{
				if (inserted[j] == false)
				{
					int valueToInsert = sortedPairs[j].second;
					// Chercher jusqu'à la position de son partenaire (grand)
					size_t searchEnd = 0;
					for (size_t k = 0; k < mainChain.size(); k++)
					{
						if (mainChain[k] == sortedPairs[j].first)
						{
							searchEnd = k + 1;
							break;
						}
					}
					
					size_t pos = binarySearchInsertVector(mainChain, valueToInsert, searchEnd);
					mainChain.insert(mainChain.begin() + pos, valueToInsert);
					inserted[j] = true;
				}
			}
		}
		
		// Insérer les éléments restants
		for (size_t i = 1; i < sortedPairs.size(); i++)
		{
			if (inserted[i] == false)
			{
				int valueToInsert = sortedPairs[i].second;
				size_t searchEnd = 0;
				for (size_t k = 0; k < mainChain.size(); k++)
				{
					if (mainChain[k] == sortedPairs[i].first)
					{
						searchEnd = k + 1;
						break;
					}
				}
				
				size_t pos = binarySearchInsertVector(mainChain, valueToInsert, searchEnd);
				mainChain.insert(mainChain.begin() + pos, valueToInsert);
			}
		}
	}
	
	// Insérer l'élément seul si il existe
	if (isOdd)
	{
		size_t pos = binarySearchInsertVector(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, straggler);
	}
	
	// Copier le résultat
	arr = mainChain;
}

// ================ ALGORITHME FORD-JOHNSON (DEQUE) ================

size_t PmergeMe::binarySearchInsertDeque(const std::deque<int>& arr, int value, size_t end)
{
	size_t left = 0;
	size_t right = end;
	
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	
	return (left);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr)
{
	size_t n = arr.size();

	if (n <= 1)
		return;
	
	// Pour les petits tableaux, tri par insertion simple
	if (n <= 10)
	{
		for (size_t i = 1; i < n; i++)
		{
			int key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
		return;
	}
	
	// Phase 1: Former les paires et comparer
	std::vector<std::pair<int, int> > pairs;
	bool isOdd = (n % 2 != 0);
	int straggler = isOdd ? arr[n - 1] : 0;

	for (size_t i = 0; i < n - (isOdd ? 1 : 0); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	
	// Phase 2: Trier récursivement les "grands" éléments
	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); i++)
		largers.push_back(pairs[i].first);
	
	fordJohnsonSortDeque(largers);

	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < largers.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == largers[i])
			{
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	
	// Phase 3: Construire la chaîne principale
	std::deque<int> mainChain;
	if (!sortedPairs.empty())
	{
		mainChain.push_back(sortedPairs[0].second);
		for (size_t i = 0; i < sortedPairs.size(); i++)
			mainChain.push_back(sortedPairs[i].first);
	}
	
	// Phase 4: Insérer les autres petits selon la séquence de Jacobsthal
	if (sortedPairs.size() > 1)
	{
		std::vector<size_t> jacobsthal = generateJacobsthalSequence(sortedPairs.size());
		std::vector<bool> inserted(sortedPairs.size(), false);
		inserted[0] = true;

		for (size_t i = 1; i < jacobsthal.size(); i++)
		{
			size_t start = jacobsthal[i - 1];
			size_t end = jacobsthal[i];
			
			for (size_t j = end; j > start && j < sortedPairs.size(); j--)
			{
				if (inserted[j] == false)
				{
					int valueToInsert = sortedPairs[j].second;
					size_t searchEnd = 0;
					for (size_t k = 0; k < mainChain.size(); k++)
					{
						if (mainChain[k] == sortedPairs[j].first)
						{
							searchEnd = k + 1;
							break;
						}
					}
					
					size_t pos = binarySearchInsertDeque(mainChain, valueToInsert, searchEnd);
					mainChain.insert(mainChain.begin() + pos, valueToInsert);
					inserted[j] = true;
				}
			}
		}
		
		for (size_t i = 1; i < sortedPairs.size(); i++)
		{
			if (inserted[i] == false)
			{
				int valueToInsert = sortedPairs[i].second;
				size_t searchEnd = 0;
				for (size_t k = 0; k < mainChain.size(); k++)
				{
					if (mainChain[k] == sortedPairs[i].first)
					{
						searchEnd = k + 1;
						break;
					}
				}
				
				size_t pos = binarySearchInsertDeque(mainChain, valueToInsert, searchEnd);
				mainChain.insert(mainChain.begin() + pos, valueToInsert);
			}
		}
	}
	
	if (isOdd)
	{
		size_t pos = binarySearchInsertDeque(mainChain, straggler, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, straggler);
	}
	
	arr = mainChain;
}

void PmergeMe::sort()
{
	displaySequence("Before: ", _vectorData);

	clock_t startVec = clock();
	fordJohnsonSortVector(_vectorData);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeq = clock();
	fordJohnsonSortDeque(_dequeData);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	displaySequence("After:  ", _vectorData);
	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
