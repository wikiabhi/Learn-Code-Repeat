//Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'
// If all the rules are followed by the given string, return true otherwise return false.

#include <iostream>
using namespace std;

bool checkAB(char input[]) {	
  if(input[0] == '\0'){
    return true;
  }
  
  if(input[0] == 'a'){
    	if(input[1] == '\0'){
        	return checkAB(input+1);  
        }else if(input[1] == 'a'){
          	return checkAB(input+1);
        }else if(input[1] == 'b' && input[2] == 'b'){
          	if(input[3] == '\0' || input[3] == 'a'){
	          	return checkAB(input+3);
        	}
        }
    
  }
  return false;
}

int main(){
	char input[10000];
	cin >> input;

	cout << checkAB(input);

}