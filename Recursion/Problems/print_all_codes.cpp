#include <iostream>
#include <string.h>
using namespace std;
void printHelper(string input, string output){
	if(input.empty()){
      cout << output <<  endl;
      return; 
    }
  
  
  	char alphabet = stoi(input.substr(0,1)) + 'a' - 1; 	
  
  	printHelper(input.substr(1), output + alphabet);
  
  	
  	if(stoi(input.substr(0,2)) <= 26 && stoi(input.substr(0,2)) >= 10){
		char altAlphabet = stoi(input.substr(0,2)) + 'a' - 1; 
      	
      	printHelper(input.substr(2), output + altAlphabet);
    }
  

}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
	string output = "";
  	printHelper(input, output);
}

int main(){
  string s;
  cin >> s;

  printAllPossibleCodes(s);
}

