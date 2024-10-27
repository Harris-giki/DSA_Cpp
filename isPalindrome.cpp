#include<iostream>
using namespace std;

bool is_palindrome(string text)
{
    for(int i = 0; i < text.length() / 2; i++)
    {
        if(text[i] != text[text.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Example usage
    string text;
    cout << "Enter a string to check if it's a palindrome: ";
    cin >> text;
    
    if(is_palindrome(text))
        cout << text << " is a palindrome." << endl;
    else
        cout << text << " is not a palindrome." << endl;

    return 0;
}
