#include <vector>
#include <string>
#include <iostream>

class anagram {

private:
  std::string word;

public:
  anagram(std::string input) {
    this->word = input;
  };

  std::vector<std::string> matches(std::vector<std::string> input) {

    std::vector<std::string> vect;
    std::string thisCopy = this->word;
    std::string temp = "";
    int pos = -1;

  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].length(); j++) {
      if (thisCopy.find(input[i][j]) != -1) {
        pos = thisCopy.find(input[i][j]);
        temp += thisCopy[pos];
        thisCopy.replace(pos,1,"");
      }
    }
    //std::cout << "temp.length: "<< temp.length() << std::endl;
    //std::cout << "inputi.length: "<< input[i].length() << std::endl;
    //std::cout << "this->word.length: "<< this->word.length() << std::endl;

    if (temp.length() == input[i].length() && this->word.length() == input[i].length()) {
      vect.push_back(input[i]);
    }
    temp = "";
    thisCopy = this->word;
  }
  return vect;
 }
};


/*
auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"tan", "stand", "at"});
    vector<string> expected{"tan"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
    */