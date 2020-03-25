#include <iostream>
#include <vector>
#include <string>
#include "PhoneticFinder.hpp"
// Id of collaborators 208825539 207950577

using namespace std;
vector<string> split(const string& str, const string& delim)  //https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
/** this dictionary gives every letter a specific code which it shares with its similar letters*/
/** for example b=p=f=2*/
static vector <int> dict= {1, 2, 3, 4, 5, 2, 6, 7, 8, 6, 3, 9, 10,11, 12 , 2, 3, 13, 14, 4, 12, 15, 15, 16,8 , 14};
int code(char c){
    if( c>='a' && c<='z')
        return dict[c-'a'];
    if( c>='A' && c<='Z')
        return dict[c-'A'];  
    return 0;    
}

bool checkSim(string word1, string word2){
    for(int i=0; i< word1.length(); i++){
        if(code(word1[i])!= code(word2[i])){
            return false;
        }
    }
    return true;
}
namespace phonetic {
    string find( string text, string word){
        vector<string> words= split(text, " ");
        vector <string> myWord= split(word, " ");
        if (myWord.size() !=1)
            throw  runtime_error( "'"+word+"' is not a legal word");
        word= myWord[0];
        for( int i=0; i< words.size(); i++){
            if( words[i].length() == word.length()){
                if(checkSim(words[i], word))
                    return words[i];
            }
        }
        throw  runtime_error( "Did not find the word '"+word+"' in the text");
        return NULL;
    }
}