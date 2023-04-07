#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
bool isWordValid(const string& word, const string& in, const string& floating);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
    set<string> result;
    string allChars = "abcdefghijklmnopqrstuvwxyz";

    for (auto it = dict.begin(); it != dict.end(); it++) {
        string word = *it;
        if (isWordValid(word, in, floating)) {
            result.insert(word);
        }
    }

    return result;


}

bool isWordValid(const string& word, const string& in, const string& floating) {
    if (word.length() != in.length() + floating.length()) {
        return false;
    }
    for (int i = 0; i < in.length(); i++) {
        if (in[i] != word[i]) {
            return false;
        }
    }
    for (int i = 0; i < floating.length(); i++) {
        if (word.find(floating[i]) == string::npos) {
            return false;
        }
    }
    return true;
}
// Define any helper functions here
