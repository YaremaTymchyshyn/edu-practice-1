
// У текстовому файлі задано послідовність слів, відокремлених пропусками.
// Надрукувати лише ті слова, в яких всі букви різні.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLettersDifferent(string word)
{
    for (size_t i = 0; i < word.length(); i++)
    {
        for (size_t j = i+1; j < word.length(); j++)
        {
            if (word[i] == word[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string word;
    string result;

    ifstream file;
    file.open("file.txt");

    cout << "All words which have different letters:\n";

    while (file >> word)
    {
        if (IsLettersDifferent(word))
        {
            cout << word << "\n";
        }
    }

    file.close();
    return 0;
}