#include <iostream>
#include <fstream>
#include <limits>
#include <string>

std::fstream& Gotaline(std::fstream& line, unsigned num){
    line.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        line.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return line;
}

int main() {
  std::fstream line("Quiz.txt");

  std::string beginning = "DO NOT EDIT THIS TOP SECTION!\nWelcome to the quiz type your questions using the format below\nHow many questions are there? e.g. 1\nQuestion e.g. What is bigger 3 or 4\nHow many answers are there e.g. 2 (Make them single line answers)\nWhich answer is correct e.g. 1";
  std::ifstream quiz ("Quiz.txt");
  if (! quiz.is_open()) {
    std::ofstream quiz("Quiz.txt");
    quiz << beginning; 
  }

  std::cout << "Welcome to the quiz. Answer the questions with the question number. Good luck!\n";

  bool Answered = false;
  std::string answer;
  std::string question;
  int input = 0;
  int questionLine = 8;
  int questionCountLine = 7;
  int printAnswers = 0;
  int answerCount = 0;
  int answerCountLine = questionCountLine+2;
  int answerLines = 0;
  int correctAnswer = 0;
  int correct = 0;

  Gotaline(line, 7);
  int questionCount;
  line >> questionCount;
  
  for (int questionLoop = 0; questionLoop < questionCount; questionLoop++) {
    
    Gotaline(line, questionLine);
    line >> question;
    std::cout << "\n" << question;
  
    Gotaline(line, answerCountLine);
    line >> answerCount;
      
    while (printAnswers < answerCount) {
      Gotaline(line, answerCountLine+1);
      line >> answer;
      answerCountLine++;
      printAnswers++;
      std::cout << "\n" << printAnswers << ". " << answer;
    }
    Gotaline(line, answerCountLine+1);
    line >> correctAnswer;
    std::cout << "\n";
      
    while (Answered == false) {
    std::cin >> input;
      if (std::cin) {
        if (input == correctAnswer) {
          correct = correct+1;
          Answered = true;
          std::cout << "Correct\n";
        }
        else{
          std::cout << "Sorry the correct answer was answer " << correctAnswer << "\n";
          Answered = true;
        }
      }
      if (!std::cin) {
        std::cout << "Your input must be an integer\n";
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    questionLine = questionLine+answerCount+3;
    answerCountLine = questionLine+1;
    printAnswers = 0;
    Answered = false;
  }
  std::cout << "Congratulations you got " << correct << "/" << questionCount << "\n";
  return 0;
}