//// Copyright 2021 Ozhiganova Polina
#include "postfix.h"

std::string infix2prefix(std::string arithmetic_expr) {
  std::string output;
  std::vector<char> nums_vec = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  std::map<char, int> expr_map = {{'+', 1},
                                  {'-', 1},
                                  {'*', 2},
                                  {'/', 2}};
  std::string s = "";
  std::vector<int> for_n;
  std::vector<char> for_expr;
  MyStack<char> opr(100);
  MyStack<int> nums(100);
  for (int i = 0; i < arithmetic_expr.size(); i++) {
    int res = -1;
    bool needed = std::find(nums_vec.begin(), nums_vec.end(), arithmetic_expr[i]) != nums_vec.end();
    while (needed) {
      res = arithmetic_expr[i] - '0';
      s += std::to_string(res);
      res = atoi(s.c_str());
      needed = std::find(nums_vec.begin(), nums_vec.end(), arithmetic_expr[i + 1]) != nums_vec.end();
      i++;
    }
    if (res != -1) {
      nums.push(res);
      output += std::to_string(res) + " ";
    }
    if (arithmetic_expr[i] == '+' || arithmetic_expr[i] == '-') {  // для закрыв нет
      if (opr.isEmpty()) {    // стек пуст, просто кладем
        opr.push(arithmetic_expr[i]);
      } else {
        if (1 < expr_map[opr.get()]) {   // сравниваю приоритет плюса с тем, что в стеке
          int res = nums.pop();
          char mult_or_div = opr.pop();
          if (mult_or_div == '*') {
            int num2 = nums.pop();
            res = num2 * res;
            output += mult_or_div;
            output += " ";
          } else if (mult_or_div == '/') {
            int num2 = nums.pop();
            res = num2 / res;
            output += mult_or_div;
            output += " ";
          }
          nums.push(res);
        } else if (1 == expr_map[opr.get()]) {  // если приоритеты равны
          int res = nums.pop();
          char pls_or_minus = opr.pop();
          if (pls_or_minus == '+') {   // забираю + , лежащий в стеке
            int num2 = nums.pop();
            res = num2 + res;
            output += pls_or_minus;
            output += " ";
          } else if (pls_or_minus == '-') {
            int num2 = nums.pop();
            res = num2 - res;
            output += pls_or_minus;
            output += " ";
          }
          nums.push(res);
          opr.push(arithmetic_expr[i]);  // просто кладу
        } else if (opr.get() == '(') {
          opr.push(arithmetic_expr[i]);
        }
      }
    } else if (arithmetic_expr[i] == '*' || arithmetic_expr[i] == '/') {
      if (opr.isEmpty()) {  // стек пуст, просто кладем
        opr.push(arithmetic_expr[i]);
      } else {
        if (2 > expr_map[opr.get()]) {   // сравниваю приоритет плюса с тем, что в стеке, если меньше, просто кладу
          if ((opr.get() == '+') || (opr.get() == '-')) {
            opr.push(arithmetic_expr[i]);
          }
        } else if (2 == expr_map[opr.get()]) {  // если приоритеты равны
          int res = nums.pop();
          char mult_or_div = opr.pop();
          if (mult_or_div == '*') {
            int num2 = nums.pop();
            res = num2 * res;
            output += mult_or_div;
            output += " ";
          } else if (mult_or_div == '/') {
            int num2 = nums.pop();
            res = num2 / res;
            output += mult_or_div;
            output += " ";
          }
          nums.push(res);
          opr.push(arithmetic_expr[i]);  // кладу в стек */ без проверок
        } else if (opr.get() == '(') {
          opr.push(arithmetic_expr[i]);
        }
      }
    } else if (arithmetic_expr[i] == '(') {
      opr.push(arithmetic_expr[i]);
    } else if (arithmetic_expr[i] == ')') {   // если закрывающаяся , то тут тоже прописать вывод...
      while (opr.get() != '(') {  ///////////////////////
        char expr = opr.pop();
        int res = nums.pop();
        if (expr == '+') {
          int num2 = nums.pop();
          res = num2 + res;
          output += expr;
          output += " ";
        } else if (expr == '-') {
          int num2 = nums.pop();
          res = num2 - res;
          output += expr;
          output += " ";
        } else if (expr == '*') {
          int num2 = nums.pop();
          res = num2 * res;
          output += expr;
          output += " ";
        } else if (expr == '/') {
          int num2 = nums.pop();
          res = num2 / res;
          output += expr;
          output += " ";
        }
        nums.push(res);
      }
      opr.pop();  // убираю ( скобку
    }
    s = "";
  }
  while (!opr.isEmpty()) {
    char expr = opr.pop();
    int res = nums.pop();
    output += expr;
    output += " ";
    if (expr == '+') {
      res = nums.pop() + res;
    } else if (expr == '-') {
      res = nums.pop() - res;
    } else if (expr == '*') {
      res = nums.pop() * res;
    } else if (expr == '/') {
      res = nums.pop() / res;
    }
    nums.push(res);
  }
  return output;
}
