////// Copyright 2021 Ozhiganova Polina
#include <iostream>
#include "postfix.h"

int main() {
  std::string s1("2 + 6 * 3 / (4 - 2)");
  std::cout << "Expression:" << std::endl;
  std::cout << s1 << std::endl;
  std::cout << "Polish Notation:" << std::endl;
  // 2 6 3 * 4 2 - / +
  std::string output = infix2postfix(s1);
  std::cout << output << std::endl;
  std::cout << std::endl;

  std::string s2("1 + 2 * (3 + 4 / 2 - (1 + 2)) * 2 + 1");
  std::cout << "Expression:" << std::endl;
  std::cout << s2 << std::endl;
  std::cout << "Polish Notation:" << std::endl;
  // 1 2 3 4 2 / + 1 2 + - * 2 * + 1 +
  std::string output2 = infix2postfix(s2);
  std::cout << output2 << std::endl;
  std::cout << std::endl;

  std::string s3("1 * 2 * 3");
  std::cout << "Expression:" << std::endl;
  std::cout << s3 << std::endl;
  std::cout << "Polish Notation:" << std::endl;
  std::string output3 = infix2postfix(s3);  // 1 2 * 3 *
  std::cout << output3 << std::endl;
  return 0;
}
