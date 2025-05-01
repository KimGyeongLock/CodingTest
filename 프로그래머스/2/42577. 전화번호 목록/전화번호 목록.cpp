#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;
    for(string phone : phone_book) {
        s.insert(phone);
    }
    
    for(string phone : phone_book) {
        string temp = "";
        for(char c : phone) {
            temp += c;
            if (s.find(temp) != s.end() && temp != phone) {
                return false;
            }
        }
    }
    
    return true;
}