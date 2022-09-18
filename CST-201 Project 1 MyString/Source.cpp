//Brian Macias
//9/14/22
//This is my own code.

#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	char words[5];
	int curr_length;
	int capacity;

	void ensureCapacity(MyString& user) {
		/*char add[5];
		for (int i = 0; i < 6; i++) {
			add[i] = user[i];
		}*/
	}
public:
	//Default Constructor
	MyString() {
		curr_length = 0;
		words[5] = NULL;
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

	MyString operator+(MyString& s) {
		//char add[5];
		MyString addWord("world");
		//ensureCapacity(addWord);

		char temp[10]{};

		for (int i = 0; i < s.length(); i++) {
			temp[i] = words[i];
		}
		
		delete[] words;
		curr_length = 10;
		words[curr_length];

		for (int i = 0; i < s.length(); i++) {
			words[i] = temp[i];
		}
		for (int i = 6; i < addWord.length() + 6; i++) {
			words[i] = addWord[i];
		}
		return s;
	}
};

int main() {
	MyString myWord("hello");
	MyString myNewWord(myWord);
	cout << endl;
	myWord << myNewWord;
	MyString addWord("world");
	myNewWord +myNewWord;

	cout << myNewWord.length();
	
}