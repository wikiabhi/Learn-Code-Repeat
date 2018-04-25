//Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
   
	if(num == 0){
		output[0] = "";
		return 1;
	}

	int digit = num % 10;
	string digitString;

	if(digit == 2){
		digitString = "abc";
	}else if(digit == 3){
		digitString = "def";
	}else if(digit == 4){
		digitString = "ghi";
	}else if(digit == 5){
		digitString = "jkl";
	}else if(digit == 6){
		digitString = "mno";
	}else if(digit == 7){
		digitString = "pqrs";
	}else if(digit == 8){
		digitString = "tuv";
	}else if(digit == 9){
		digitString = "wxyz";
	}

	int smallNum = num/10;	
	int smallOutputSize = keypad(smallNum, output);

	//copy
	for(int i=0; i<smallOutputSize; i++){
		string copy = output[i];
		for(int j=0; j< digitString.size(); j++){
			output[i+ j*smallOutputSize] = copy + digitString[j];
		}
	}

	return smallOutputSize * digitString.size(); 
}

int main(){
	int n;
	cin >> n;

	string* output = new string[1000];
	int count = keypad(n, output);

	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}