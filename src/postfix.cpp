//// Copyright 2021 Ozhiganova Polina
#include "postfix.h"

std::string infix2postfix(const std::string& arithmetic_expr) {
  std::string output;
  MyStack<char> opr(100);
  std::map<char, int> expr_map = {
      {'(', 0},
      {')', 1},
      {'+', 2},
      {'-', 2},
      {'*', 3},
      {'/', 3}
  };
  for (auto letter : arithmetic_expr) {
    if (letter == ' ') {
      continue;
    }
    if (('0' <= letter && letter <= '9')
    || letter == '.') {
      output += letter;
      continue;
    }
    char end = output[output.length() - 1];
    if ('0' <= end && end <= '9') {
      output += ' ';
    }
    if (opr.isEmpty()) {
      opr.push(letter);
      continue;
    } else {
      if ((letter == '(') || (expr_map.find(letter)->second)
      > (expr_map.find(opr.get())->second)) {
        opr.push(letter);
        continue;
      }
    }
    if (letter == ')') {
      while (!opr.isEmpty() && opr.get() != '(') {
        output += opr.pop();
        output += ' ';
      }
      if (!opr.isEmpty()) {
        opr.pop();
      }
      continue;
    }
    while ((!opr.isEmpty()) && (expr_map.find(opr.get())->second)
    >= (expr_map.find(letter)->second)) {
      output += opr.pop();
      output += ' ';
    }
    opr.push(letter);
  }
  char end = output[output.length() - 1];
  if ('0' <= end && end <= '9')
    output += ' ';
  while (!opr.isEmpty()) {
    output += opr.pop();
    output += ' ';
  }
  output.pop_back();
  return output;
}
