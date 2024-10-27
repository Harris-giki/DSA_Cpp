#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    int arr[6];

    for(int i = 0; i < n; i++)
    {
        cout << "ENTER THE VALUES OF YOUR ARRAY THAT ARE NEEDED TO BE SORTED:" << endl;
        cin >> arr[i];
    }

    int counter = 1;

    while(counter < n) 
    {
        for(int i = 0; i < n - counter; i++)
        {
            if(arr[i] > arr[i + 1]) 
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++; 
    }

    cout << "FOLLOWING IS THE SORTED ARRAY: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
