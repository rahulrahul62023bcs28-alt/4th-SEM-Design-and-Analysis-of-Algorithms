#include <iostream>
using namespace std;

int main()
{
    string text,pattern;
    int i, j, n, m;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin,pattern);

    for (n = 0; text[n] != '\0'; n++);

    for (m = 0; pattern[m] != '\0'; m++);

    cout <<pattern <<" found\n";
    cout<<"Starting index(es) at:\n";
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
            cout << i << endl; // starting index
    }

    return 0;
}
