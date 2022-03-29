#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	
	if (argc != 3) {
		cout << "ERROR: Wrong amount of arguments!" << endl;
		cout << "\n" << "Programm closed...\n\n" << endl;
		exit(1);
		return 0;
	}

	vector<string> prevKeys;
	vector<string> prevValues;

	string prevFile = argv[1];
	string currFile = argv[2];

	ifstream prevKeyFile;
	prevKeyFile.open(prevFile);
	string delim = ",";
	int endCount = 0;

	if (prevKeyFile.is_open())
	{
		while (!prevKeyFile.eof())
		{
			string line = "";
			getline(prevKeyFile, line);
			if (line == ",,,,,,,,,,,,,,,,,,,,")
			{
				endCount++;
				if (endCount > 6) break;
			}
			int pos = 0;
			int commaCount = 0;
			while ((pos = line.find(delim)) != string::npos)
			{	
				if (commaCount == 10)
				{
					prevKeys.push_back(line.substr(0, pos));
					
				}
				else if (commaCount == 17)
				{
					prevValues.push_back(line.substr(0, pos));
					break;
				}
				line.substr(0, pos);
				line.erase(0, pos + delim.length());
				commaCount++;
			}
		}
	}

	prevKeyFile.close();

	vector<string> currKeys;

	ifstream currKeyFile;
	currKeyFile.open(currFile);
	endCount = 0;

	if (currKeyFile.is_open())
	{
		while (!currKeyFile.eof())
		{
			string line = "";
			getline(currKeyFile, line);
			if (line == ",,,,,,,,,,,,,,,,,,,,")
			{
				endCount++;
				if (endCount >= 10) break;
			}
			int pos = 0;
			int commaCount = 0;
			while ((pos = line.find(delim)) != string::npos)
			{
				if (commaCount == 10)
				{
					currKeys.push_back(line.substr(0, pos));
					break;
				}
				line.substr(0, pos);
				line.erase(0, pos + delim.length());
				commaCount++;
			}
		}
	}

	currKeyFile.close();


	map<string, string> map1;

	for (int i = 0; i < prevKeys.size()&& prevKeys.size() == prevValues.size() ; i++)
	{	
		if (prevKeys[i] != "" && map1.find(prevKeys[i]) != map1.end())
		{	
			map1.erase(prevKeys[i]);
			map1.insert({prevKeys[i],"xxxxxxxx"});
		}
		else
		{
			map1.insert({prevKeys[i],prevValues[i]});
		}
	}

	ofstream writeFile1;
	writeFile1.open("currValue.txt");

	for (string val : currKeys)
		writeFile1 << map1[val] << endl;

	writeFile1.close();

		
	return 0;
}