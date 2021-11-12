#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <iostream>
#include <vector>
#include <string>
#include <set>

using std::string;
using namespace std;

// TODO: your code goes here:
int worthCloning(const string& s) {
    int j = s.size() - 1;
    while (s.substr(0, j).find(s.substr(j, s.size() - j)) != string::npos) {
        j--;
    }
    return j + 1;
}

int stringConstruction(string target, int copyCost, int appendCost) {
    vector<int> v = vector<int> (1, 0);
    for (int i = 0; i < target.size(); i++) {
        int cost = v[i] + appendCost;
        int j = worthCloning(target.substr(0, i+1));
        if (j <= i) {
            cost = std::min(cost, v[j] + copyCost);
        }
        v.push_back(cost);
    }
    return v[v.size() - 1];

}

// do not write or edit anything below this line

#endif
