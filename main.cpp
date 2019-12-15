#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	int i = 0;
	char buffer[1000];
	ifstream fin("example_text.txt");
	int count;
	int now = 0;
	bool found = false;
	bool inside;

	if (!fin.is_open()) {
		cout << "Error while opening file" << endl;
		system("pause");
	}
	else {
		cout << "File is opened" << endl;
		do {
			cout << "Enter count of words to search: ";
			cin >> count;
			if (count < 0) {
				cout << "Incorrect count, enter count>0" << endl;
			}
		} while (count < 0);
		cout << endl;
		do {
			now = 0;
			i = 0;
			inside = false;
			do {
				fin.get(buffer[i]);
				if (buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i] >= 'a' && buffer[i] <= 'z') {
					if (!inside)
						now++;
					inside = true;
				}
				else
					inside = false;
				i++;
			} while (buffer[i - 1] != '\n' && !fin.eof());

			if (now == count && !fin.eof()) {
				found = true;
				i = 0;
				do {
					cout << buffer[i];
					i++;
				} while (buffer[i - 1] != '\n' && buffer[i - 1] > 0 && i < 1000);
			}
		} while (!fin.eof());
		if (!found)
			cout << "no lines found!" << endl;
		system("pause");
	}
	fin.close();
}
