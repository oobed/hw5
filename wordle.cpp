#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include <queue>
#include <string>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;

  void helper(queue<char>floating_letters, set<string>& word_valid, size_t idx,string in, set<string>& dict);


  void helper(queue<char> floating_letters, set<string>& word_valid, size_t idx, string in, const set<string>& dict) {
    int ndashes = 0;
    set<char> already_filled;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    if(idx == in.size()) {
        if (dict.count(in)) {
            word_valid.insert(in);
        }
        return;
    }
    for(char c : in) {
      ndashes += (c == '-');
    }
    if(in[idx] == '-') {
      if(ndashes < floating_letters.size()) {
            return;
        }       
      for(int i = 0; i < floating_letters.size(); i++) {
        char character = floating_letters.front();
        in[idx] = character;
        floating_letters.pop();
        if(already_filled.count(character) == 0) {
          helper(floating_letters, word_valid, idx+1, in, dict);
          already_filled.insert(character);
            } 
          floating_letters.push(character);
          in[idx] = '-';
        }
        
        if(ndashes == floating_letters.size()) {
          return;
        }
        for(char c : alphabet) {
          in[idx] = c;            
          if(already_filled.count(c) == 0) {
            helper(floating_letters, word_valid, idx+1, in, dict);
            }
            
          in[idx] = '-';
        }
    } else{
        helper(floating_letters, word_valid, idx+1, in, dict);
    }
}

    
  set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict){
      queue<char>floating_letters;
      for(int i = 0; i<floating.size();i++){
        floating_letters.push(floating[i]);
      }
      set<string>words_valid;
      helper(floating_letters,words_valid, 0, in, dict);
      return words_valid;
    }
    
    
    
    
    
//     //calculate the number of blanks left for each recursive call
//     //check if the idx is a dash
//     ///if its already a letter, skip it
//     ///if its a dash, 
//     ////iterate through all floating letters
//     ////pop from the queue and put it in the location of the idx
//     ////call the recursive function, with the new word
//     ////put a letter back in the queue
//     ////reset the location back to a dash
    

//     //iterate through the alphabet
//     //set current idx to the current letter 
//     //do the recursive call with the word
//     //reset back to a blanks

//     //at the top, make a new set of characters
//     //if a letter is already used, skip over the recursive call
//     ///if your'e inserting a floating letter, add it to the set of floating letters

