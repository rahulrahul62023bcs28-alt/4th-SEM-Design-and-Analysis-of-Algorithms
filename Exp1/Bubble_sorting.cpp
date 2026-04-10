#include <iostream>
using namespace std;

int main()
{
    int n, a[10], temp;
    cout<<"\n__________BUBBLE_SORTING__________\n";
    cout << "\nEnter number of elements for sort :\n ";
    cin >> n;
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n-1; i++)
    {
        int flag = 1;
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 0;
            }
        }
        if(flag != 0)
            break;
    }
    cout << "Sorted array :\n";
    for(int i = 0; i < n; i++)
        cout << a[i] <<  " ";
        cout << endl;

    return 0;
}
