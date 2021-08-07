#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        auto itr = mapWords.find(digits);
        if (itr != mapWords.end()) {
            result = mapWords[digits];
        }
        return result;
    }

    // Convert word into telephone digits, add the digits to dictionary as key and word (arry of string) as value.
    void addToDictionary(string word) {
        string strDigits = phoneAtoi(word);
        auto itr = mapWords.find(strDigits);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (itr != mapWords.end()) {
            vector<string> tmp = mapWords.at(strDigits);
            tmp.push_back(word);
            mapWords[strDigits] = tmp;
        }
        else {
            vector<string> tmp;
            tmp.push_back(word);
            mapWords[strDigits] = tmp;
        }
    }

    void printDictionary() {
        for (map<string, vector<string>>::iterator mapItr = mapWords.begin(); mapItr != mapWords.end(); mapItr++) {
            cout << mapItr->first;
            for (vector<string>::iterator vItr = mapItr->second.begin(); vItr != mapItr->second.end(); vItr++) {
                cout << " " << vItr->c_str();
            }
            cout << endl;
        }
    }
private:
    map<string /* word in phone digits */, vector<string>> mapWords;

    // Convert word to phone digits
    // CALLME => 225563
    string phoneAtoi(string word) {
        string strDigits;
        for (int i = 0; i < word.size(); i++) {
            strDigits.append(phoneChar2Num(word[i]));
        }
        return strDigits;
    }

    // Helper function to convert letter to digit (telephone pad)
    string phoneChar2Num(char c) {
        if (c == 'A' || c == 'B' || c == 'C') {
            return "2";
        }
        else if (c == 'D' || c == 'E' || c == 'F') {
            return "3";
        }
        else if (c == 'G' || c == 'H' || c == 'I') {
            return "4";
        }
        else if (c == 'J' || c == 'K' || c == 'L') {
            return "5";
        }
        else if (c == 'M' || c == 'N' || c == 'O') {
            return "6";
        }
        else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') {
            return "7";
        }
        else if (c == 'T' || c == 'U' || c == 'V') {
            return "8";
        }
        else {
            return "9";
        }
    }
};

int main(int argc, char** argv) {
    ifstream fin(argv[1]);
    string line;
    Solution s;

    while (!fin.eof()) {
        fin >> line;
        if (!isdigit(line[0])) {
            s.addToDictionary(line);
        }
        else {
            // get words that correspond to digits
            vector<string> words = s.letterCombinations(line);
            cout << line << ": ";
            if (words.size() == 0) {
                cout << "<No Results>";
            }
            else {
                for (int i = 0; i < words.size(); i++) {
                    cout << words[i];
                    if (i + 1 != words.size()) cout << ", ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}