
#include <iostream>
#include <vector>
using namespace std;

int isGreater(int a, int b) {
    while (to_string(a).size() != to_string(b).size()) {
        if (a > b) {return isGreater(a/10, b);}
        else {return isGreater(a, b/10);}
    }
    if (a > b) {return 1;}
    return 0;
}

string largest_number(vector<int> numbers) {
    string final_salary = "";
    int numbers_remaining = (int) numbers.size();
    while (numbers.size()) {
        int max_pos = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (isGreater(numbers[i], numbers[max_pos])) {max_pos = i;}
        }
        final_salary.append(to_string(numbers[max_pos]));
        numbers.erase(numbers.begin() + max_pos);
    }
    return final_salary;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter numbers: ";
    vector<int> numbers(n);
    for (int i = 0; i < numbers.size(); i++) {cin >> numbers[i];}

    cout << largest_number(numbers);
}
