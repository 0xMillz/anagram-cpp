#include <vector>
#include <string>
#include <iostream>

class anagram {

private:
  std::string word;

public:
  anagram(std::string input) {
    //Store input as all uppercase
    for (int i = 0; i < input.length(); i++){
      input[i] = toupper(input[i]);
    }
    std::cout << input << std::endl;
    this->word = input;
  };

  std::vector<std::string> matches(std::vector<std::string> input) {

    //Vector to be returned
    std::vector<std::string> vect;
    //Create thisCopy so this->word isnt destroyed
    std::string thisCopy = this->word;
    //A var to build word to be compared
    std::string temp = "";
    std::string upperInput = "";
    int pos = -1;

  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].length(); j++) {
      if (thisCopy.find(toupper(input[i][j])) != -1) {
        pos = thisCopy.find(toupper(input[i][j]));
        temp += thisCopy[pos];
        upperInput += toupper(input[i][j]);
        thisCopy.replace(pos,1,"");
      }
    }

    if (temp.length() == input[i].length() && this->word.length() == input[i].length() && upperInput.compare(this->word) != 0) {
      vect.push_back(input[i]);
    }
    temp = "";
    upperInput = "";
    thisCopy = this->word;
  }
  return vect;
 }
};