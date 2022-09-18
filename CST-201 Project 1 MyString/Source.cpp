//Brian Macias
//9/14/22
//This is my own code.

#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	char words[5];
	char add[5];
	int curr_length;
	int capacity;


public:
	//Default Constructor
	MyString() {
		curr_length = 0;
		words[0] = NULL;
	}

	MyString(string user) {
		for (int i = 0; i < user.length(); i++) {
			words[i] = user[i];
		}
		curr_length = user.length();
	}

	MyString(MyString& copy) {
		for (int i = 0; i < 5; i++) {
			words[i] = copy.words[i];
		}
		curr_length = copy.length();
	}

	int length() {
		return curr_length;
	}

	MyString operator<<(MyString &s) {
		//print out string
		for (int i = 0; i < sizeof(words); i++) {
			cout << words[i];
		}
		cout << endl;
		return s;
	}

	/*
	MyString operator+(MyString& s) {
		
		MyString addWord("world");

		char temp[10]{};

		for (int i = 0; i < s.length(); i++) {
			temp[i] = words[i];
		}
		
		delete[] words;
		curr_length = 10;
		
		words[10];

		for (int i = 0; i < s.length(); i++) {
			temp[i] = words[i];
		}

		for (int i = 0; i < s.length(); i++) {
			add[i] = temp[i];
		}

		for (int i = 0; i < addWord.length(); i++) {
			words[i] = add[i];
		}
		return s;
	}
	
	friend bool operator==(MyString& first, MyString& second) {
		//compares the string to input
		if (first == second) {
			cout << "Yes";
			return true;
		}
		else {
			cout << "Not the same";
			return false;
		}
	}
	*/
	int operator[] (int index) { //.getInt()
		if (index >= curr_length) {
			cout << "Array index out of bound, exiting";
		}
		else {
			cout << words[index] << endl;
			return words[index];
		}
	}

	void toUpper() {
		char out;
		for (int i = 0; i < curr_length; i++) {
			if (words[i] >= 97) {
				words[i] = words[i] - 32;
			}
			cout << words[i];
		}
		cout << endl;
	}

	void toLower() {
		char out;
		for (int i = 0; i < curr_length; i++) {
			if (words[i] <= 90) {
				words[i] = words[i] + 32;
			}
			cout << words[i];
		}
		cout << endl;
	}

	void substring(int in) {
		int inCount = in;
		for (inCount; inCount < sizeof(words); inCount++) {
			cout << words[inCount];
		}
		cout << endl;
	}

	void substring(int in, int stop) {
		int inCount = in;
		for (inCount; inCount < stop; inCount++) {
			cout << words[inCount];
		}
		cout << endl;
	}
};

int main() {
	MyString myWord("Hello");
	MyString myNewWord(myWord);
	cout << endl;
	myWord << myNewWord;
	MyString addWord("world");

	cout << myNewWord.length();
	//myNewWord + addWord;
	//myNewWord == myWord;
	myNewWord[4];
	myNewWord.toUpper();
	myNewWord.toLower();
	myNewWord.substring(2);
	myNewWord.substring(1, 3);

}