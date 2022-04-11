#include <iostream>
#include <fstream>
#include <limits>

std::fstream& Gotaline(std::fstream& line, unsigned num){
    line.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        line.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return line;
}

int main() {
  std::string testAgainstVarQuiz = "DO NOT EDIT THIS TOP SECTION!";
  std::string beginning = "DO NOT EDIT THIS TOP SECTION!\nWelcome to the quiz type your questions using the format below\nHow many questions are there? e.g. 1\nQuestion e.g. What is bigger 3 or 4\nHow many answers are there e.g. 2 (Make them single line answers)\nWhich answer is correct e.g. 1";

  
  std::string myText;
  std::ifstream quiz("Quiz.txt");
  getline (quiz, myText);
  
  if (myText == testAgainstVarQuiz) {
  } else {
  std::ofstream quiz("Quiz.txt");
  quiz << beginning; 
  }
  
  std::fstream line("Quiz.txt");
  using namespace std;
  Gotaline(line, 7);
  int questionCount;
  line >> questionCount;

  string answer;
  string question;
  int questionCountLine = 7;
  int printAnswers = 0;
  int answerCount;
  int answerCountLine = questionCountLine+2;
  int answerLines = 0; 
  
  for (int a = 0; a < questionCount; a++) {
  std::cout << "\n" << question;
  Gotaline(line, answerCountLine);
  line >> answerCount;
    while (printAnswers < answerCount) {
      Gotaline(line, answerCountLine);
      line >> answer;
      std::cout << answer;
      answerCountLine++;
      printAnswers++;
    }
  }
  return 0;
}
