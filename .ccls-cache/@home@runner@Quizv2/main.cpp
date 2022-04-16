#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <cmath>

//function to get the lines from the text file
std::istream& Gotoline(std::istream& line, unsigned num){
  line.seekg(std::ios::beg);
  for(int i=0; i < num - 1; ++i){
    line.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  }
  return line;
}

int main() {
  //setting line to the Quiz.txt file
  std::fstream line("Quiz.txt");
  //setting quiz to the Quiz.txt file and checking if it exists, if it does the code continues if it does not it creates one and inputs the text seen below.
  std::ifstream quiz("Quiz.txt");
  if (! quiz.is_open()) {
    std::ofstream quiz("Quiz.txt");
    quiz << "DO NOT EDIT THIS TOP SECTION!\nWelcome to the quiz type your questions using the format below\nHow many questions are there? e.g. 1\nQuestion e.g. What is bigger 3 or 4\nHow many answers are there e.g. 2 (Make them single line answers)\nWhich answer is correct e.g. 1"; 
  }
  //Asking for the users name
  std::string name;
  std::cout << "What is your name?\n";
  std::cin >> name;
  std::cout << "Welcome to the quiz " << name << ", Answer the questions with the answer number. Good luck!\n";
  //Initiating all the variables to be used in the quiz loop.
  bool Answered = false;
  std::string answer;
  std::string question;
  double input = 0;
  int questionLine = 8;
  int questionCountLine = 7;
  int printAnswers = 0;
  int answerCount = 0;
  int answerCountLine = questionCountLine+2;
  int answerLines = 0;
  int correctAnswer = 0;
  int correct = 0;
  Gotoline(line, 7);
  int questionCount;
  line >> questionCount;
  //The quiz loop.
  for (int questionLoop = 0; questionLoop < questionCount; questionLoop++) {
    //Printing the question to the console.
    Gotoline(line, questionLine);
    line >> question;
    std::cout << "\n" << question;
    //Getting the answer count (amount of answers)
    Gotoline(line, answerCountLine);
    line >> answerCount;
    //Printing all of the answers
    while (printAnswers < answerCount) {
      Gotoline(line, answerCountLine+1);
      line >> answer;
      answerCountLine++;
      printAnswers++;
      std::cout << "\n" << printAnswers << ". " << answer;
    }
    //Getting which answer is correct
    Gotoline(line, answerCountLine+1);
    line >> correctAnswer;
    std::cout << "\n";
    //Recieving input and checking if it is an integer and one of the possible answers for that question.
    while (Answered == false) {
    std::cin >> input;
      if (std::cin) {
        if (input <= answerCount && input > 0 && ceil(input) == input) {
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
        else {
          std::cout << "Your input must be one of the possible answers\n";
        }
      }
      if (!std::cin) {
        std::cout << "Your input must be an integer\n";
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    //re-assigning the variables to new values so they work for the next question.
    questionLine = questionLine+answerCount+3;
    answerCountLine = questionLine+1;
    printAnswers = 0;
    Answered = false;
  }
  std::cout << "Congratulations " << name << ", you got " << correct << "/" << questionCount << "\n";
  return 0;
}