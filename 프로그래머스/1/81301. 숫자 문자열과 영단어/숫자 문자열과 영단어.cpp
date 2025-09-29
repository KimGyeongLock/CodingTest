#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string total = "";
    string temp = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            total.push_back(c);
        } else {
            temp.push_back(c);
            if (temp == "one")   {
                total.push_back('1');
                temp = "";
            }
            else if (temp == "two") {
                total.push_back('2'); temp = "";
            }
            else if (temp == "three") {total.push_back('3'); temp = "";}
            else if (temp == "four")  {total.push_back('4'); temp = "";}
            else if (temp == "five")  {total.push_back('5'); temp = "";}
            else if (temp == "six")   {total.push_back('6'); temp = "";}
            else if (temp == "seven") {total.push_back('7'); temp = "";}
            else if (temp == "eight") {total.push_back('8'); temp = "";}
            else if (temp == "nine")  {total.push_back('9'); temp = "";}
            else if (temp == "zero") {total.push_back('0'); temp = "";}
        }
    }
    return stoi(total);
}