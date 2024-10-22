#include <iostream>
#include <cstring>
using namespace std;

class Stack {
    int top;
    public:
        string arr[50]; // Stack to hold up to 50 words

    Stack() {
        top = -1;
    }

    // Push a word onto the stack
    void push(string word) {
        if (top >= 49) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = word;
        }
    }

    // Pop a word from the stack
    string pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return "";
        } else {
            return arr[top--];
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }
};

// Function to reverse the sentence
void reverseSentence(string sentence) {
    Stack s;
    string word = "";
    
    // Split the sentence into words and push them onto the stack
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            s.push(word); // Push the word onto the stack
            word = "";    // Reset word for the next one
        } else {
            word += sentence[i]; // Add character to the current word
        }
    }
    
    // Push the last word onto the stack (since there's no space after it)
    s.push(word);
    
    // Pop the words from the stack to reverse the sentence
    cout << "Reversed sentence: ";
    while (!s.isEmpty()) {
        cout << s.pop();
        if (!s.isEmpty()) {
            cout << " "; // Add space between words, but not after the last word
        }
    }
    cout << endl;
}

int main() {
    string sentence;
    
    // Read the entire sentence including spaces
    cout << "Enter a sentence: ";
    getline(cin, sentence);  // Use getline to read the full sentence
    
    cout << "Original sentence: " << sentence << endl;
    reverseSentence(sentence);
    
    return 0;
}
