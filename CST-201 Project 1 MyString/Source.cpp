//Brian Macias
//9/14/22
//This is my own code.

#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	char words[5];
	char temp[10];

	int size;
	int curr_length = 0;
	int capacity;

	void ensureCapacity() {
		capacity = curr_length;
		cout << "Current Capacity " << capacity << endl;

		char* temp = new char[capacity * 3];

		for (int i = 0; i < curr_length; i++)
		{
			temp[i] = words[i];
		}

		delete[] words;

		words == temp;
		
		capacity = capacity * 3;
		cout << "Current Capacity " << capacity << endl;
	}
	//O(n)
public:


	//Default Constructor
	MyString() {
		curr_length = 0;
		words[0] = NULL;
	}
	//O(1)
	MyString(string user) {
		for (int i = 0; i < user.length(); i++) {
			words[i] = user[i];
		}
		curr_length = user.length();
	}
	//O(n)
	MyString(MyString& copy) {
		for (int i = 0; i < 5; i++) {
			words[i] = copy.words[i];
		}
		curr_length = copy.length();
	}
	//O(n)
	int length() {
		return curr_length;
	}
	//O(1)
	MyString operator<<(MyString &s) {
		//print out string
		for (int i = 0; i < sizeof(words); i++) {
			cout << words[i];
		}
		cout << endl;
		return s;
	}
	//O(n)
	
	MyString concat(MyString& s, MyString& n) {

		MyString res(s);

		if (res.capacity >= res.curr_length) {
			res.ensureCapacity();
			for (int i = 0; i < (res.curr_length + n.curr_length); i++) {
				res.words[curr_length + i] = n.words[i];
			}

			res.curr_length = s.curr_length + n.curr_length;

			for (int i = 0; i < res.curr_length; i++) {
				cout << res[i];
			}

		}else {

			for (int i = 0; i < (res.curr_length + n.curr_length); i++) {
				res.words[curr_length + 1] = n.words[i];
			}

			res.curr_length = s.curr_length + n.curr_length;

			for (int i = 0; i < res.curr_length; i++)
			{
				cout << s.words[i];
			}
			cout << endl;
		}
		
		
		return res;
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
	//O(1)	
	int operator[] (int index) { //.getInt()
		if (index >= curr_length) {
			cout << "Array index out of bound, exiting";
		}
		else {
			cout << words[index] << endl;
			return words[index];
		}
	}
	//O(1)
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
	//O(n)
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
	//O(n)
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
	//O(n)
	string substring(int in, int stop) {
		string result;
		int inCount = in;
		for (inCount; inCount < stop; inCount++) {
			cout << words[inCount];
		}
		cout << endl;
		return result;
	}
	//O(1)
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
	//O(n^2)
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
//O(n^2)
int main() {
	MyString myWord("Hello");
	MyString myNewWord(myWord);
	myWord << myNewWord;
	MyString addWord("world");

	cout << myNewWord.length();
	myNewWord.concat(myNewWord, myWord);
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