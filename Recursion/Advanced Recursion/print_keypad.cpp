#include <iostream>
#include <string>
using namespace std;

void printKeypadHelper(int num, string output){
  	
  	if(num == 0){
      cout << output << endl; 
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
	
  	for(int i=0; i<digitString.length(); i++){
    	printKeypadHelper(smallNum, digitString[i] + output);  
    }
  	
}

void printKeypad(int num){
  	string output = "";
	printKeypadHelper(num, output);
}

int main(){
	int n;
	cin >> n;

	printKeypad(n);
}
