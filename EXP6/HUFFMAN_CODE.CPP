#include <iostream>
#include <string>
using namespace std;

float freq[100];
int left_child[100];
int right_child[100];
char symbol[100];
int nNodes = 0;

string codes[256];

// Add node
void addNode(char ch, float fr, int l, int r)
{
    symbol[nNodes] = ch;
    freq[nNodes] = fr;
    left_child[nNodes] = l;
    right_child[nNodes] = r;
    nNodes++;
}

// Find minimum node
int findMin(bool used[])
{
    float minVal = 9999;
    int minIdx = -1;

    for (int i = 0; i < nNodes; i++)
    {
        if (!used[i] && freq[i] < minVal)
        {
            minVal = freq[i];
            minIdx = i;
        }
    }

    if (minIdx != -1)
        used[minIdx] = true;

    return minIdx;
}

// Generate codes
void generateCodes(int idx, string code)
{
    if (idx == -1) return;

    if (left_child[idx] == -1 && right_child[idx] == -1)
    {
        codes[(int)symbol[idx]] = code;
        return;
    }

    generateCodes(left_child[idx], code + "0");
    generateCodes(right_child[idx], code + "1");
}

int main()
{
    int n;
    cout << "Enter number of symbols: ";
    cin >> n;

    cout << "Enter symbol and frequency:\n";
    for (int i = 0; i < n; i++)
    {
        char ch;
        float fr;
        cin >> ch >> fr;
        addNode(ch, fr, -1, -1);
    }

    bool used[100] = {false};

    // Build Huffman Tree
    while (true)
    {
        int remaining = 0;

        for (int i = 0; i < nNodes; i++)
            if (!used[i]) remaining++;

        if (remaining == 1) break;

        int left = findMin(used);
        int right = findMin(used);

        addNode('\0', freq[left] + freq[right], left, right);
    }

    // Generate codes
    generateCodes(nNodes - 1, "");

    cout << "\nSymbol | Frequency | Codeword\n";
    cout << "-------+-----------+---------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "  " << symbol[i] << "    |   "
             << freq[i] << "    |  "
             << codes[(int)symbol[i]] << endl;
    }

    // Encode text
    string text;
    cout << "\nEnter text to encode: ";
    cin >> text;

    string encoded = "";

    for (int i = 0; i < text.length(); i++)
    {
        encoded += codes[(int)text[i]];
    }

    cout << "Encoded text: " << encoded << endl;

    return 0;
}
