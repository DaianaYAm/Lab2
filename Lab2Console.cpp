// Lab2Console.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "lab2DLL.h"
#include <math.h>
#include <string>
#include <conio.h>
#include <locale>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string strToSplit, char delimeter)
{
	stringstream ss(strToSplit);
	string item;
	vector<string> splittedStrings;
	while (getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}


void saveNums() {
	saveToXML();
	cout << "Данные сохранены в XML." << endl;
}

void askMakeWord() {
	cout << "Введите слово" << endl;
	string word;
	cin >> word;
	if (askWord(word)) {
		cout << "Можно" << endl;
	}
	else {
		cout << "Низзя" << endl;
	}
}

void loadNums() {
	loadFromXML();
	cout << "Данные загружены из XML." << endl;
}

void askChar() {
	cout << "Введите ваш символ." << endl;
	char a;
	cin >> a;
	if (pushNum((int)a)) {
		cout << "Ваш символ записан" << endl;
	}
}

void deleteNum() {
	cout << "Введите символ, который надо удалить" << endl;
	char a;
	cin >> a;
	if (deleteNum((int)a)) {
		cout << "Ваше символ удален!" << endl;
	}
}

char stringToChar(string a) {
	int b = stoi(a);
	return (char)b;
}

void clogNums() {
	string nums = getNums();
	if (nums.length() > 0) {
		vector<string> numsSplitted = split(nums, '_');
		cout << "Символы в массиве: " << endl;
		for (int i = 0; i < numsSplitted.size(); i++) {
			cout << "Символ ";
			cout << i + 1;
			cout << ": ";
			cout << stringToChar(numsSplitted[i]) << endl;
		}
	}
	else {
		cout << "Нечего выводить." << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "***********Number Array Handler***********" << endl;
	cout << "*****Для начала работы введите start.*****" << endl;
	bool started = true;
	while (started) {
		string b;
		cin >> b;
		if (b == "start") {
			started = false;
			system("cls");
		}
	}
	cout << "кнопки управления программой: " << endl;
	cout << "Q - ввести новый символ и добавить в базу " << endl;
	cout << "S - проверить, можно ли составить слово" << endl;
	cout << "W - Вывести сохраненные символы" << endl;
	cout << "E - экспортировать данные в XML" << endl;
	cout << "R - импортировать данные из XML" << endl;
	cout << "T - завершить работу за программой" << endl;
	bool choice = true;
	while (choice) {
		char b = _getch();
		switch (b) {
		case 'q':
			askChar();
			break;
		case 'w':
			clogNums();
			break;
		case 'e':
			saveNums();
			break;
		case 's':
			askMakeWord();
			break;
		case 'r':
			loadNums();
			break;
		case 't':
			choice = false;
			break;
		default:
			break;
		}
		
	}
}
