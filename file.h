#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class FileStream {
	FILE* fin;
	bool opened;
public:
	FileStream() {
		if ((fin = fopen("example_text.txt", "r")) == NULL)
		{
			cout << "error while opening file" << endl;
			opened = false;
			system("pause");
		}
		else {
			cout << "file opened" << endl;
			opened = true;
		}
	};

	char get() {
		return fgetc(fin);
	};

	bool eoff() {
		return feof(fin);
	}

	bool is_opened() {
		return opened;
	}

	~FileStream() {
		if (opened==false) {
			cout << "error while closing file" << endl;
		}
		else if(fclose(fin) == EOF){
		}
		else {
			cout << "file closed" << endl;
		}
		system("pause");
	};
};
