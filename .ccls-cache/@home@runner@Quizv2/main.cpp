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
  int questionCount;
  test >> questionCount;
  std::cout << questionCount;
  
  string question;
  int questionCountLine = 7;
  int printAnswers = 0;
  int answerCount = questionCountLine+2;
  int answerLines = 0; 

  int currentLineNumber = questionCountLine+totalAnswerCount+3;
  
  for (int a = 0; a < questionCount; a++) {
  Gotaline(test, questionCountLine);  
  test >> question;
  std::cout << "\n" << question;
  Gotaline(test, answerCount);
  test >> answerCount;
  std::cout << "\nb" << answerCount << "\ntest";
    while (printAnswers < answerCount) {
      std::cout << "\nworm test";
      printAnswers++;
    }
  std::cin.get();
  }
  return 0;
}
