#include <iostream>
#include <fstream>
#include <limits>

std::fstream& Gotaline(std::fstream& test, unsigned num){
    test.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        test.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return test;
}

int main() {
  std::string testAgainstVarQuiz = "DO NOT EDIT THIS TOP SECTION!";
  std::string beginning = "DO NOT EDIT THIS TOP SECTION!\nWelcome to the quiz type your questions using the format below\nHow many questions are there? e.g. 1\nQuestion e.g. What is bigger 3 or 4\nHow many answers are there e.g. 2 (Make them single line answers)\nWhich answer is correct e.g. 1";
  
  std::string myText;
  std::ifstream quiz("Quiz.txt");
  getline (quiz, myText);
  
  if (myText == testAgainstVarQuiz) {
  std::cout << "Success";
  } else {
  std::ofstream quiz("Quiz.txt");
  quiz << beginning; 
  }
  std::fstream test("Quiz.txt");
  using namespace std;
  Gotaline(test, 7);
  int questioncount;
  test >> questioncount;
  std::cout << questioncount;
  Gotaline(test, 8);
  string questions1;
  test >> questions1;
  std::cout << "\n" << questions1;
  std::cin.get();
  return 0;
}