// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.

#include <iostream>
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
  
  	if(input.empty()){
      output[0] = "";
      return 1;
    }
  	if(input.length() == 1){
      char alphabet = stoi(input.substr(0,1)) + 'a' - 1; 	
      output[0] = alphabet;
      return 1;
    }
  
  
	string* output1 = new string[input.length()];   
  	int smallOutput1 = getCodes(input.substr(1), output1);
	 
  	
  	char alphabet = stoi(input.substr(0,1)) + 'a' - 1; 	
  	
  	for(int i=0; i<smallOutput1; i++){
      output[i] = alphabet +  output1[i] ;     
    }
  	
  	string* output2 = new string[input.length()]; 
  	int smallOutput2 = 0;
  
  
  	if(stoi(input.substr(0,2)) <= 26 && stoi(input.substr(0,2)) >= 10){
 
      smallOutput2 = getCodes(input.substr(2), output2);   ///
      
	  char alphabet = stoi(input.substr(0,2)) + 'a' - 1;
      
      for(int j=0; j<smallOutput2; j++){
      		output[j+smallOutput1] = alphabet +  output2[j] ;     
      }
    }
  
  	return smallOutput1 + smallOutput2;  ////
  	
}
int main(){
  
}

