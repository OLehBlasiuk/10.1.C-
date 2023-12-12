#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) 
{
	ofstream fout(fname); 
	char ch; 
	string s; 
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname) 
{
	ifstream fin(fname);    
	string s;               
	while (getline(fin, s)) 
	{
		cout << s << endl;  
	}
	cout << endl;
}
int CountCommaDashPairs(char* fname) {
	ifstream fin(fname);
	string s;
	int count = 0;

	while (getline(fin, s)) {
		for (unsigned i = 0; i < s.length() - 1; i++) {
			if (s[i] == ',' && s[i + 1] == '-') {
				count++;
			}
		}
	}

	return count;
}
int ProcessTXT1(char* fname) 
{
	ifstream fin(fname);    
	string s;                
	int k = 0;               
	while (getline(fin, s))  
	{                        
		for (unsigned i = 0; i < s.length(); i++)
			if (s[i] == ',' || s[i]+1 == '-')
				k++;
	}
	return k;
}
int ProcessTXT2(char* fname) 
{          
	ifstream fin(fname);    
	string s;              
	int k = 0;    
		while (fin >> s)   
		{
			k++;             
			cout << k << ": " << s << endl;
		}
	return k;
}
int ProcessTXT3(char* fname) 
{                           
	ifstream fin(fname);    
	char s[100];            
	char* w;                
	int k = 0;             
	while (fin.getline(s, sizeof(s))) 
	{
		w = strtok(s, " .,:;!?-'"); 
		while (w != NULL)    
		{
			k++;             
			cout << k << ": " << w << endl; 
			w = strtok(NULL, " .,:;!?-'"); 
		}
	}
	return k;
}
void SortTXT(char* fname, char* gname) 
{
	ofstream g(gname);       
	string s, mins, z = "";             
	int k;                      
	do                       
	{                        
		k = 0;              
		ifstream f(fname);    
		while (getline(f, s))
		{
			if (s <= z)      
				continue;     
			mins = s;              
			k++;                             
			break;           
		}                    
		while (getline(f, s))
		{
			if (s <= z)      
				continue;    
			if (s < mins)    		
			{               
				mins = s;    
				k++;        
			}                
		}	              
		z = mins;           
		                    
		if (k > 0)           
			g << z << endl;  
		f.close();           
	}                       
	while (k > 0);           
}
int main() {
	char fname[100];
	cout << "enter file name 1: ";
	cin >> fname;
	CreateTXT(fname);
	PrintTXT(fname);
	cout << "k(+-=) = " << ProcessTXT1(fname) << endl;
	cout << "k(word1) = " << ProcessTXT2(fname) << endl;
	cout << "k(word2) = " << ProcessTXT3(fname) << endl;
	char gname[100];
	cout << "enter file name 2: ";
	cin >> gname;
	SortTXT(fname, gname);
	PrintTXT(gname);
	cout << "Number of comma-dash pairs:" << CountCommaDashPairs(fname) << endl;

	return 0;
}