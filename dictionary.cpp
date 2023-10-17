#include <bits/stdc++.h>

using namespace std;

const string dictionaryFile = "dictionary.txt";

map<string, string> loadDictionary()
{
    map<string, string> dictionary;
    ifstream file(dictionaryFile);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            size_t pos = line.find(':');
            if (pos != std::string::npos)
            {
                string word = line.substr(0, pos);
                string meaning = line.substr(pos + 1);
                dictionary[word] = meaning;
            }
        }
        file.close();
    }
    return dictionary;
}

void saveDictionary(const map<string, string> &dictionary)
{
    ofstream file(dictionaryFile);
    if (file.is_open())
    {
        for (const auto &it : dictionary)
            file << it.first << ":" << it.second << "" << endl;
        file.close();
    }
}

void add(map<string, string> &dictionary)
{
    string word, meaning;
    cout << "Enter the word: ";
    cin >> word;
    cin.ignore();
    cout << "Enter the meaning: ";
    getline(cin, meaning);
    dictionary[word] = meaning;
    saveDictionary(dictionary);
    cout << "'" << word << ":" << meaning << "' successfully added to the dictionary." << endl;
}

void search(const map<string, string> &dictionary)
{
    string word;
    cout << "Enter the word to search: ";
    cin >> word;
    auto it = dictionary.find(word);
    if (it != dictionary.end())
        cout << "Meaning of " << it->first << " : " << it->second << "" << endl;
    else
        cout << "'" << word << "' not found in the dictionary." << endl;
}

void remove(map<string, string> &dictionary)
{
    string word;
    cout << "Enter the word to remove: ";
    cin >> word;
    auto it = dictionary.find(word);
    if (it != dictionary.end())
    {
        cout << "'" << it->first << ":" << it->second << "'" << " word successfully removed from the dictionary." << endl;
        dictionary.erase(it);
        saveDictionary(dictionary);
    }
    else
        cout << "'" << word << "' not found in the dictionary." << endl;
}

int main()
{
    map<string, string> dictionary = loadDictionary();
    while (true)
    {
        cout << endl;
        cout << "Dictionary Generator Menu:" << endl;
        cout << "1. Add Word" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. Remove Word" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;
        if (choice == 1)
            add(dictionary);
        else if (choice == 2)
            search(dictionary);
        else if (choice == 3)
            remove(dictionary);
        else if (choice == 4)
            return 0;
        else
            cout << "Invalid choice. Please enter valid choice." << endl;
    }
}
