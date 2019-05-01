#include <iostream>
#include <string>
#include <vector>	 
#include <fstream>   
#include <algorithm> // for std::sort

struct Word
{
	std::string word;
	uint16_t order;

	Word(std::string& p_word, uint8_t p_order)
		: word(std::move(p_word)), order(p_order) {}
};

bool cmp(Word& a, Word& b)
{
	if (a.order == b.order)
		return a.word < b.word;
	
	return a.order < b.order;
}

void classification(std::vector<Word>& data)
{
	bool all_caps;
	std::size_t word_length;
	for (auto& e : data)
	{
		all_caps = true;
		word_length = e.word.length();
		for (std::size_t i = 0; i < word_length; ++i)
		{
			if (e.word[i] < 'A' || e.word[i] > 'Z')
			{
				all_caps = false;
				break;
			}
		}
		if (all_caps)
			e.order = 1;
		else if (word_length >= 3)
		{
			if (e.word[word_length - 1] == 'e' &&
				e.word[word_length - 2] == 'x' &&
				e.word[word_length - 3] == 'e')
				e.order = 2;

			else if (e.word[word_length - 1] == 'm' &&
				e.word[word_length - 2] == 'o' &&
				e.word[word_length - 3] == 'c')
				e.order = 3;

			else if (e.word[word_length - 1] == 't' &&
				e.word[word_length - 2] == 'a' &&
				e.word[word_length - 3] == 'b')
				e.order = 4;

			else if (e.word[word_length - 1] == 'c' &&
				e.word[word_length - 2] == 'o' &&
				e.word[word_length - 3] == 'd')
				e.order = 5;

			else if (e.word[word_length - 1] == 't' &&
				e.word[word_length - 2] == 'x' &&
				e.word[word_length - 3] == 't')
				e.order = 6;

			else
				e.order = 7;
		}
		else
			e.order = 7;
	}
}

int main()
{
	std::ifstream inFile;
	inFile.open("6.txt");

	std::vector<Word> data;

	if (inFile.is_open())
	{
		std::cout << "Reading data: \n";
		std::string word;
		while (inFile >> word)
		{
			std::cout << word << '\n';
			data.emplace_back(word, 0);
		}
	}

	classification(data);
	std::sort(data.begin(), data.end(), cmp);

	std::cout << "\n\n Sorting words:\n";
	for (auto& e : data)
		std::cout << e.word << '\n';

}