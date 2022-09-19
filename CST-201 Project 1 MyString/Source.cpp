//Brian Macias
//9/14/22
//This is my own code.

#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	char* words[5];
	char* temp[10];

	int size;
	int curr_length = 0;
	int capacity;

	void ensureCapacity() {
		if (words.length() == curr_length) {
			char temp[curr_length * 2];
		}
	}

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

	
	MyString concat(MyString& s) {
		
		
		
		return con;
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

	string substring(int in) {
		string result;
		int inCount = in;
		for (inCount; inCount < sizeof(words); inCount++) {
			result += words[inCount];
			cout << words[inCount];
		}
		cout << endl;
		return result;
	}

	string substring(int in, int stop) {
		string result;
		int inCount = in;
		for (inCount; inCount < stop; inCount++) {
			cout << words[inCount];
		}
		cout << endl;
		return result;
	}

	int indexOf(MyString s, string r) {
		for (int i = 0; i <= curr_length - r.length(); i++) {
			int j;

			for (j = 0; j < r.length(); j++) {
				if (words[i + j] != r[j]) {
					break; //breaks when no pattern is found
				}

				if (j == r.length()) {
					return i; //returns the number of iterations if found 

				}else {
					return -1;
				}
			}
		}

	}

	int lastIndexOf(MyString s, string r) {
		for (int i = 0; i <= curr_length - r.length(); i++) {
			int j;

			for (j = 0; j < r.length(); j++) {
				if (words[i + j] != r[j]) {
					break; //breaks when no pattern is found
				}

				if (j == r.length()) {
					return i + r.length(); //returns the number of iterations if found 

				}
				else {
					return -1;
				}
			}
		}
	}
};

int main() {
	MyString myWord("Hello");
	MyString myNewWord(myWord);
	myWord << myNewWord;
	MyString addWord("world");

	cout << myNewWord.length();
	//myNewWord.concat(myNewWord, addWord);
	//myNewWord == myWord;
	myNewWord[4];
	myNewWord.toUpper();
	myNewWord.toLower();
	myNewWord.substring(2);
	myNewWord.substring(1, 3);

	cout<< myNewWord.indexOf(myNewWord, myNewWord.substring(1));
	cout << endl;
	cout << myNewWord.lastIndexOf(myNewWord, myNewWord.substring(3));
}