#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
     int key = arr[i];
     int j = i - 1;
     while (j >= 0 && arr[j] > key)
     {
       arr[j + 1] = arr[j];
       j = j - 1;
     }
     arr[j + 1] = key;
   }
}
int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  int arr[n];
  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Before Sorting:\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
insertionSort(arr, n);
cout << "\nAfter Sorting:\n";
for (int i = 0; i < n; i++)
  cout << arr[i] << " ";
return 0;
}
//Enter number of elements: 5
//Enter elements:
//9 3 7 1 5
