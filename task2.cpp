//-------------------------------------------------------------------------------------------------
// Write a function that counts the number of words in the text for each word length
// (X words with 1-letter length, Y words with 2-letters length, etc.)
//-------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <utility>

//-------------------------------------------------------------------------------------------------

//! 
//! @brief Checking symbol.
//! 
//! @param symbol 
//! @return true if delimiter.
//! @return false if not delimiter.
bool isDelim(char symbol)
{
  bool is_delim = false;
  switch (symbol)
  {
    case '.':
    case ',':
    case '!':
    case ' ':
    case '?':
    case ':':
    case '\\':
    case '/':
    case '\n':
    case '\t':
      is_delim = true;
      break;
    
    default:
      break;
  }
  return is_delim;
}
//-------------------------------------------------------------------------------------------------

//! 
//! @brief Adding found length to statistic storage. 
//! 
//! @param length Length of found word.
//! @param statistic Storage of statistic.
void addToStatistic(int length, std::map<int, int> &statistic)
{
  int count = 0;
  auto itr = statistic.find(length);
  if (itr == statistic.end())
  {
    ++count;
    statistic.insert(std::make_pair(length, count));
  }
  else
  {
    count = statistic.at(length);
    ++count;
    statistic.at(length) = count;
  }
}
//-------------------------------------------------------------------------------------------------

//! 
//! @brief Counter of word length statistic.
//! 
//! @param path Path to text file. 
//! @param statistic Storage of statistic.
//! @return int 
int wordLenthsCount(std::string path, std::map<int, int> &statistic)
{
  std::ifstream file;
  file.open(path);

  statistic.clear();

  int length = 0;
  char symbol;
  while (file.get(symbol))
  {
    if (isDelim(symbol))
    {
      if (length != 0)
        addToStatistic(length, statistic);
      
      length = 0;
    }
    else
      ++length;
  }
  if (length != 0)
    addToStatistic(length, statistic);

  file.close();
}
//-------------------------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
  std::map<int, int> statisic;
  wordLenthsCount("task2.txt", statisic);

  for (auto it = statisic.begin(); it != statisic.end(); ++it)
    std::cout << it->first << " " << it->second << std::endl;

  return 0;
}
//-------------------------------------------------------------------------------------------------
