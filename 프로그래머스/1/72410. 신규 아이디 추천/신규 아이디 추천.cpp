#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int point = 0;
    int len = new_id.length();
    
    for (char& c : new_id) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }
    }
    
    for (int i = 0; i < new_id.length(); i++) {
        char& c = new_id[i];
        if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.')) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    
    for (int i = 0; i < new_id.length(); i++) {
        char& c = new_id[i];
        if (c == '.') {
            point++;
            if (point >= 2) {
                new_id.erase(new_id.begin() + i);
                i--;
                point--;
            }
        } else {
            point = 0;
        }
    }
    
    for (int i = 0; i < new_id.length(); i++) {
        char& c = new_id[i];
        if ((c == '.') && (i == 0 || i == new_id.length() - 1)) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
        

    if (new_id.empty()) new_id = "a";
    
    if (new_id.length() >= 16) {
        new_id = new_id.replace(15, new_id.length(), "");
    }   
    if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.begin() + new_id.length() - 1);

    while (new_id.length() <= 2) {
        new_id += new_id[new_id.length() - 1];
    }     
        
    return new_id;
}