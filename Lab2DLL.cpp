#include "pch.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include "lab2DLL.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <sstream>

using namespace std;

vector<int> numbers;

inline void TESTHR(HRESULT _hr)
{
	if FAILED(_hr) throw(_hr);
}

int indexOf(int num) {
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == num) {
			return i;
		}
	}
	return -1;
}

bool pushNum(int num) {
	numbers.push_back(num);
	return true;
}

bool askWord(string word) {
	string res = word;
	for (int i = 0; i < res.length(); i++) {
		int num = (int)res[i];
		if (indexOf(num) == -1) {
			return false;
		}
	}
	return true;
}

bool deleteNum(int num) {
	if (indexOf(num) > -1) {
		numbers.erase(numbers.begin() + indexOf(num));
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

string getNums() {
	vector<int> res = numbers;
	string ret = "";

	for (int i = 0; i < res.size(); i++) {
		ret += toString(res[i]);
		ret += "_";
	}

	return ret;
}

void saveToXML() {
	TiXmlDocument doc;
	TiXmlElement* msg;
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(decl);

	TiXmlElement * root = new TiXmlElement("Lab2DLL");
	doc.LinkEndChild(root);

	TiXmlElement * savings = new TiXmlElement("Lab2DLLSavings");
	root->LinkEndChild(savings);

	TiXmlElement * dats = new TiXmlElement("numbers");
	savings->LinkEndChild(dats);

	for (int i = 0; i < numbers.size(); i++) {
		char buf[30];
		_itoa_s(numbers[i], buf, 10);
		TiXmlElement * date = new TiXmlElement("num");
		date->LinkEndChild(new TiXmlText(buf));
		dats->LinkEndChild(date);
	}
	doc.SaveFile("savings.xml");
}

void loadFromXML() {
	TiXmlDocument doc("savings.xml");
	doc.LoadFile();

	TiXmlElement *l_pRootElement = doc.RootElement();


	if (NULL != l_pRootElement)
	{
		// set of &lt;person&gt; tags
		TiXmlElement *l_Lab2DllSavs = l_pRootElement->FirstChildElement("Lab2DLLSavings");

		if (NULL != l_Lab2DllSavs)
		{
			TiXmlElement *l_numbers = l_Lab2DllSavs->FirstChildElement("numbers");

			if (NULL != l_numbers)
			{
				TiXmlElement *l_date = l_numbers->FirstChildElement("num");
				numbers.push_back(stoi(l_date->GetText()));
				l_date = l_date->NextSiblingElement("num");

				while (l_date) {
					numbers.push_back(stoi(l_date->GetText()));
					l_date = l_date->NextSiblingElement("num");
				}
			}
		}
	}
}