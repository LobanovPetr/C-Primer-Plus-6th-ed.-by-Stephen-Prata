#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;

void fill(istream& os, vector<string>& v)
{
    back_insert_iterator<vector<string> > back_iter(v);
    istream_iterator<string, char> input(os);
    istream_iterator<string, char> eof;
    copy(input, eof, back_iter);
}

int main()
{
    vector<string> words;
    vector<string> from_keyboard;
    
    ifstream in;
    in.open("words.txt");
    fill(in, words);
    
    char ch;
    while(cout << "Enter the <y/n> to start the game\n", cin >> ch, ch == 'y')
    {
        string word_to_guess = words[rand() % words.size()];
        int letters = word_to_guess.size();
        string result(word_to_guess.size(), '_');
        string attempt;
        int tries = 6;
        while(tries && letters)
        {
            cout << "Tries left: " << tries << endl;
            cout << "Word: " << result << endl;
            cout << "Attempts: " << attempt << endl;
            cout << "Enter the letter" << endl;
            cin >> ch;
            if (attempt.find(ch) != string::npos || result.find(ch) != string::npos)
            {
                cout << "You have already entered this letter\n";
                cout << "Try another one\n";
                continue;
            }
            auto idx = word_to_guess.find(ch);
            if (idx == string::npos)
            {
                cout << "Incorrect letter\n";
                attempt += ch;
                tries--;
                if (tries == 0)
                {
                    cout << "Sorry, you lose\n";
                    cout << "Correct word: " << word_to_guess << endl;
                }
                continue;
            }
            cout << "Good guess!\n";
            result[idx] = ch;
            letters--;
            while(idx < word_to_guess.size() - 1 && (idx = word_to_guess.find(ch, idx + 1)) != string::npos)
            {
                result[idx] = ch;
                letters--;
            }
            if (letters == 0)
            {
                cout << "Nice! You won!\n";
                cout << "Your word: " << result << endl;
            }
            
        }
    }
    return 0;
}
