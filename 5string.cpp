#include <iostream>
#include <cstring> // for strlen function
using namespace std;

int findLength(char ch[], int size) {
  int index = 0;
  while (ch[index] != '\0') {
    index++;
  }
  return index;
}

void reverseString(char ch[], int n) {
  int i = 0;
  int j = n - 1;
  while (i <= j) {
    swap(ch[i], ch[j]);
    i++;
    j--;
  }
}

void convertToUpperCase(char ch[], int n) {
  int index = 0;
  while (ch[index] != '\0') {
    if (ch[index] >= 'a' && ch[index] <= 'z') {
      ch[index] = ch[index] - 'a' + 'A';
    }
    index++;
  }
}

void replaceCharacter(char ch[], int n) {
  int index = 0;
  while (ch[index] != '\0') {
    if (ch[index] == '@') {
      ch[index] = ' ';
    }
    index++;
  }
}

bool checkPalindrome(char ch[], int n) {
  int i = 0;
  int j = n - 1;
  while (i <= j) {
    if (ch[i] == ch[j]) {
      i++;
      j--;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  char ch[100];

  // Input a string
  cout << "Enter a string: ";
  cin.getline(ch, 100);

  int len = findLength(ch, 100);

  // Check if palindrome
  bool isPalindrome = checkPalindrome(ch, len);
  if (isPalindrome) {
    cout << "The string \"" << ch << "\" is a palindrome." << endl;
  } else {
    cout << "The string \"" << ch << "\" is not a palindrome." << endl;
  }

  // Reverse the string
  reverseString(ch, len);
  cout << "Reversed string: " << ch << endl;

  // Convert to uppercase
  convertToUpperCase(ch, len);
  cout << "Uppercase string: " << ch << endl;

  // Replace '@' with space
  replaceCharacter(ch, len);
  cout << "String after replacing '@' with space: " << ch << endl;

  // Print length using strlen function
  cout << "Length of the string: " << strlen(ch) << endl;

  return 0;
}
