// Author: TainKung
// Time: 6th June
// This is a little program to product a random string
// and copy it to you clipboard. You can use it to cre
// -ate a password, etc.
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;
typedef set<char>::iterator SET_ITER;

const char defaultSpecialSymbol[]={'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '{', '}', '[', ']', '-', '=', '+', '?'};
set<char> numberSet, lowerCaseLetterSet, upperCaseLetterSet, specialSymbolSet, charSet;
string result; int resultLen;

void initializeSet(){
	cout << "Start Initialization." << endl;
	numberSet.clear();
	for (char i='0'; i<='9'; i++) numberSet.insert(i);
	lowerCaseLetterSet.clear();
	for (char i='a'; i<='z'; i++) lowerCaseLetterSet.insert(i);
	upperCaseLetterSet.clear();
	for (char i='A'; i<='Z'; i++) upperCaseLetterSet.insert(i);
	specialSymbolSet.clear();
	charSet.clear();
	cout << "Initialization Succeed." << endl;
}

void enableSet(set<char> a){
	for (SET_ITER i=a.begin(); i!=a.end(); i++) charSet.insert(*i);
}

template<class T> int getArrayLen(T &a){
	return sizeof(a) / sizeof(a[0]);
}

void outputDefaultSpecialSymbol(){
	const int arrLen=getArrayLen(defaultSpecialSymbol);
	cout << "Default special symbols are these: ";
	for (int i=0; i!=arrLen; i++) cout << defaultSpecialSymbol[i];
	cout << endl;
}

void getSetting(){
	cout << "\nNow choose sets to enable, please input THE NUMBER before the name of sets.\n"
	        "Of course you can choose more than one set.\n"
	        "It okay to use any symbol to split it.\n"
	        "\n"
	        "Here are sets you can choose:\n"
	        "1. Numbers\n"
	        "2. Lower Case Letters\n"
	        "3. Upper Case Letters\n"
	        "4. Special Symbols (You may have to type it by yourself)\n"
	        "\n"
	        "Which sets:";
	string chosenSet; cin >> chosenSet;
	if (chosenSet.find('1') != string::npos) enableSet(numberSet);
	if (chosenSet.find('2') != string::npos) enableSet(lowerCaseLetterSet);
	if (chosenSet.find('3') != string::npos) enableSet(upperCaseLetterSet);
	if (chosenSet.find('4') != string::npos){
		cout << endl;
		outputDefaultSpecialSymbol();
		cout << "Please type in what you want to use, or just type in \"default\":\n";
		string specialSymbol; cin >> specialSymbol;
		if (specialSymbol == "default"){
			int ssLen = getArrayLen(defaultSpecialSymbol);
			for (int i=0; i<ssLen; i++) specialSymbolSet.insert(defaultSpecialSymbol[i]);
		}
		else{
			int ssLen=specialSymbol.length();
			for (int i=0; i<ssLen; i++) specialSymbolSet.insert(specialSymbol[i]);
		}
		enableSet(specialSymbolSet);
	}
}

void getLen(){
	cout << "\nHow long do you want:";
	cin >> resultLen;
}

char inSet(set<char> a, int pos){
	SET_ITER i;
	for (i=a.begin(); pos!=0 && i!=a.end(); pos--, i++);
	return *i;
}

void toClipboard(HWND hwnd, string s){
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}

int main(){
	cin.sync_with_stdio(false);
	bool reDo=1, reSet=1, reLen=1;
	while (reDo){
		system("cls");
		initializeSet();
		result="";
		if (reSet) getSetting();
		if (reLen) getLen();
		const int setSize=charSet.size();
		srand((unsigned)time(NULL));
		for (int i=0; i<resultLen; i++) result+=inSet(charSet, rand() % setSize);
		system("cls");
		cout << "It has been copyed to your clipboard. Here is it:\n\n";
		cout << result << endl << endl;
		toClipboard(GetDesktopWindow(), result);
		char ans;
		cout << "Do you want to redo it? (y/n) "; cin >> ans; reDo=(ans=='y');
		if (reDo) {cout << "Do you want to reset sets? (y/n) "; cin >> ans; reSet=(ans=='y');}
		if (reDo) {cout << "Do you want to reset the length? (y/n) "; cin >> ans; reLen=(ans=='y');} 
		cout << endl;
	}
	return 0;
}