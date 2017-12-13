#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using std::vector;
using std::map;

int get_majority_element(vector<int> &votes) {
    map<int,int> hash;
    int max_value = 0;
    int majority = 0;
    for (int i = 0; i < votes.size(); i++) {
        map<int,int>::const_iterator it = hash.find(votes[i]);
        if(it == hash.end()) { hash.insert(std::pair<int,int>(votes[i],0)); }
        else {
            hash[votes[i]]++;
            if (hash[votes[i]] > max_value) { max_value = hash[votes[i]]; majority = votes[i]; }
        }
    }
    return majority;
}

int main() {

    std::ifstream f;
    f.open("/Users/rolandgavrilescu/ClionProjects/untitled1/text.txt");
    if(!f.is_open()) { exit(EXIT_FAILURE); }

    int n;
    f >> n;
    vector<int> votes(n);
    for (int i = 0; i < votes.size(); ++i) {
        f >> votes[i];
    }

    std::cout << get_majority_element(votes) << '\n';

    f.close();
}
