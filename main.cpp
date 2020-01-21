#include <stdio.h>
#include <iostream>
#include <fstream>
#include "file.h"

using namespace std;

int main(void) {
	int i = 0;
	char buffer[1000];
	FileStream fin;
	int count;
	int now = 0;
	bool found = false;
	bool inside;
	if (fin.is_opened())
	{
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
				buffer[i] = fin.get();
				if (buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i] >= 'a' && buffer[i] <= 'z') {
					if (!inside)
						now++;
					inside = true;
				}
				else
					inside = false;
				i++;
			} while (buffer[i - 1] != '\n' && !fin.eoff());

			if (now == count && !fin.eoff()) {
				found = true;
				i = 0;
				do {
					cout << buffer[i];
					i++;
				} while (buffer[i - 1] != '\n' && buffer[i - 1] > 0 && i < 1000);
			}
		} while (!fin.eoff());
		if (!found)
			cout << "no lines found!" << endl;
		system("pause");
	}
}
