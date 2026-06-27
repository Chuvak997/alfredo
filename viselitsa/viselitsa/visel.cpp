#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
    srand(time(0));

    ofstream file("words.txt");
    file << "program computer algorithm developer interface server client network code language";
    file.close();

    ifstream input("words.txt");
    vector<string> words;
    string word;
    while (input >> word) {
        words.push_back(word);
    }
    input.close();

    string secret = words[rand() % words.size()];
    string guessed(secret.length(), '_');

    vector<char> letters;
    int attempts = 6;
    int timeLimit = 60;
    time_t start = time(0);

    cout << "\n=== GUESS THE WORD ===\n";
    cout << "Attempts: " << attempts << " | Time: " << timeLimit << " sec\n\n";

    while (attempts > 0 && guessed != secret) {
        if (time(0) - start >= timeLimit) {
            cout << "\nTime is up! You lost!\n";
            cout << "Word: " << secret << endl;
            return 0;
        }

        cout << "Word: ";
        for (char c : guessed) cout << c << " ";
        cout << endl;

        cout << "Letters: ";
        if (letters.empty()) cout << "none";
        else for (char c : letters) cout << c << " ";
        cout << endl;

        cout << "Attempts left: " << attempts << endl;
        cout << "Time left: " << (timeLimit - (time(0) - start)) << " sec" << endl;

        char ch;
        cout << "Enter letter: ";
        cin >> ch;
        ch = tolower(ch);

        if (find(letters.begin(), letters.end(), ch) != letters.end()) {
            cout << "Already used!\n\n";
            continue;
        }

        letters.push_back(ch);

        bool found = false;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == ch) {
                guessed[i] = ch;
                found = true;
            }
        }

        if (!found) {
            attempts--;
            cout << "Wrong!\n";
        }
        else {
            cout << "Correct!\n";
        }
        cout << endl;
    }

    if (guessed == secret) {
        cout << "\nYOU WIN! Word: " << secret << endl;
    }
    else {
        cout << "\nYOU LOSE! Word: " << secret << endl;
    }

    cout << "Letters used: " << letters.size() << endl;
    cout << "Time spent: " << (time(0) - start) << " sec" << endl;

    return 0;
}