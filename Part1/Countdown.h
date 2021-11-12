#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <iterator>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;
// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {

private:
    std::string solution;
    int value;

public:

    CountdownSolution() : solution(), value(0) {}

    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }

    const std::string & getSolution() const {
        return solution;
    }

    int getValue() const {
        return value;
    }

};

// Do not edit above this line

// TODO: write code here:
bool isOperation(char a)
{
    return a=='+' || a=='-' || a=='*' || a=='/' ;

}

int evaluateCountdown( const string& exp)
{
    int l,r,ans;
    stringstream postfix(exp);
    vector<int> temp;
    string s;
    while ( postfix >> s )
    {
        if( isOperation(s[0]) )
        {
            r = temp.back();
            temp.pop_back();
            l = temp.back();
            temp.pop_back();
            switch( s[0])
            {
                case '+': ans =  l + r ; break;
                case '-': ans =  l - r ; break;
                case '*': ans =  l * r ; break;
                case '/': ans =  l / r ; break;
            }

            temp.push_back( ans );
        }
        else
        {
            temp.push_back( std::stoi(s) );
        }
    }

    return temp[0] ; //last element is the answer
}
void cntdwn(const double sum, const double previous, const string digits, const double target, const std::string expr){
   if (digits.length() == 0) {
     if (sum + previous == target) {
       std::cout<<expr << " = " << target;
     }
   } else {
     for (int i = 1; i <= digits.length(); i++) {
       double current = std::stod(digits.substr(0, i));
       string remaining = digits.substr(i);
       cntdwn(sum + previous, current, remaining, target, expr + " + " + std::to_string(current));
       cntdwn(sum, previous * current, remaining, target, expr + " * " + std::to_string(current));
       cntdwn(sum, previous / current, remaining, target, expr + " / " + std::to_string(current));
       cntdwn(sum + previous, -current, remaining, target, expr + " - " + std::to_string(current));
     }
   }
 }

CountdownSolution solveCountdownProblem(const vector<int>& num, const double target) {
  string digits = intToString(num[0]) + " " + intToString(num[1]) + " " + intToString(num[2]) + " " + intToString(num[3]) + " " + intToString(num[4]) + " " + intToString(num[5]);
  for (int i = 1; i <= digits.length(); i++) {
    string current = digits.substr(0, i);
    cntdwn(0, stod(current), digits.substr(i), target, current);
  }
  return CountdownSolution(digits, target);

 }


// Do not edit below this line


#endif
