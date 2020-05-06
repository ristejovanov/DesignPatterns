#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cctype>

using namespace std;

struct Sentence
{
  struct WordToken
  {
    bool capitalize;
  };

  Sentence(const string& text)
  {
    initializeVector(text);
  }

  WordToken& operator[](size_t index)
  {
    return _myWords[index].second;
  }

  string str() const
  {
    std::string output;
    for (auto& word : _myWords)
    {
      if (word.second.capitalize == true)
      {

        word == *(_myWords.end() - 1) ? "" : " ";
        output += capitalizeWord(word.first) + (word == *(_myWords.end() - 1) ? "" : " ");
      }
      else
      {
        output += word.first + (word == *(_myWords.end() - 1) ? "" : " ");
      }
    }
    return output;
  }

  std::string capitalizeWord(std::string word) const
  {
    std::string out;
    for (auto let : word)
    {
      out += std::toupper(let);
    } 
    return out;
  }

  void initializeVector(std::string text)
  {
    bool stop = true;

    do
    {
      auto it = text.find(" ");
      if (it != std::string::npos)
      {
        _myWords.push_back({ text.substr(0,it), {false} });
        text = text.substr(it + 1);
      }
      else
      {
        if (text.size() > 0)
        {
          _myWords.push_back({ text,{false} });
          stop = false;
        }
      }
    } while (stop);
  }


  std::vector<std::pair<std::string, WordToken>> _myWords;
};

void usecase()
{
  Sentence sentance("Hello world");
  sentance[1].capitalize = true;
  cout << sentance.str();
}