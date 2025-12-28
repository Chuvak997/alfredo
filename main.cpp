#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isL(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return true;
    }
    return false;
}

char toL(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    const char* words[] = {
        "programm", "computer", "algorithm",
        "pelemenia", "PUBG", "DOMINIKTORETO",
        "family", "derbent", "MAXMAXBETOV", "NastavnikSaitamiByba",
        "CrishtianoRonaldo","RahmetBrat", "ShavhalChurkachaev", "Braitiiiish","Kimpintiooo",
        "SUBO", "kondisioner", "lavash", "DonaldTramp", "Zeleboba","Ivandaun",
        "Skibidi", "PIDIDI", "herobrin"
    };

    const int NUM_WORDS = sizeof(words) / sizeof(words[0]);

    while (true) {   
        const char* word = words[rand() % NUM_WORDS];
        
        string guessed;
        int word_len = strlen(word);
        for(int i = 0; i < word_len; ++i) {
            guessed += '_';
        }

        int attempts = 6;
        bool win = false;

        cout << "Добро пожаловать в игру: 'Виселица'!\n";
        cout << "Угадайте слово из " << word_len << " букв.\n";
        cout << "У вас есть " << attempts << " попыток.\n\n";

        while(attempts > 0 && !win) {

            cout << "Слово: ";
            for (int i = 0; i < word_len; i++) {
                cout << guessed[i] << " ";
            }
            
            cout << "\nОсталось попыток: " << attempts << endl;
            cout << "Введите букву: ";
            char letter;
            cin >> letter;

            if(!isL(letter)) {
                cout << "Ошибка! Введите букву.\n\n";
                continue;
            }

            letter = toL(letter);

            bool found = false;

            for(int i = 0; i < word_len; i++) {
                char word_letter = toL(word[i]);
                
                if(word_letter == letter && guessed[i] == '_') {
                    guessed[i] = word[i];
                    found = true;
                }
            }

            if(found) {
                cout << "Верно! Буква '" << letter << "' есть в слове.\n";

                win = true;
                for(int i = 0; i < word_len; i++) {
                    if(guessed[i] == '_') {
                        win = false;
                        break;
                    }
                }
            }
            else {
                attempts--;
                cout << "Нет такой буквы! Осталось попыток: " << attempts << "\n";
            }

            cout << endl;
        }

        if(win) {
            cout << "\n\t\tПоздравляем!\t\t\t\n";
            cout << "Вы разумный и смышлённый такие годитесь к нам в Интерпол!\n";
            cout << "Поздравляем! Вы угадали слово: " << word << endl;
        }
        else {
            cout << "Деградация на высшем уровне!\n";
            cout << "Вы проиграли! Загаданное слово было: " << word << endl;
        }
    }

    return 0;
}
