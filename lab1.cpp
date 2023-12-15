#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename S> // перегрузка чтобы распечатать цепочки языка
ostream& operator<<(ostream& os, const vector<S>& vector)
{
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

class Language
{
public:
    vector<string> words;
    int size;

    void fill(int size)
    {
        if (size >= 0 && size <= 10000)
        {
            cout << "Введите цепочки языка:" << endl;
            for (int i = 0; i < size; i++)
            {
                string str;
                cin >> str;
                words.push_back(str);
            }
        }
        else
        {
            cout << "Введена неверная размерность языка." << endl;
        }
    }
};

Language conc(Language L1, Language L2)
{
    Language L1L2;
    for (int i = 0; i < L1.words.size(); i++)
    {
        for (int j = 0; j < L2.words.size(); j++)
        {
            L1L2.words.push_back(L1.words[i] + L2.words[j]);
        }
    }
    sort(L1L2.words.begin(), L1L2.words.end());
    auto last = unique(L1L2.words.begin(), L1L2.words.end());
    L1L2.words.erase(last, L1L2.words.end());
    
    return L1L2;
}

int main()
{
    Language L1;
    cout << "Введите размерность языка L1: ";
    int a;
    cin >> a;
    L1.size = a;
    L1.fill(a);
    cout << endl;


    Language L2;
    cout << "Введите размерность языка L2: ";
    int b;
    cin >> b;
    L2.size = b;
    L2.fill(b);
    cout << endl;

    cout << "Получившийся язык L1L2:" << endl;
    Language L1L2 = conc(L1, L2);
    cout << L1L2.words << endl;

    return 0;
}