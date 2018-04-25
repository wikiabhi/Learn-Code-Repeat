#include <iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0'){
      return;
    }	
  
  	if(input[0] == input[1]){
      int i=1;
      
      for(; input[i] != '\0'; i++){      
        input[i-1] = input[i];
      }
      input[i-1] = input[i];
      
      return removeConsecutiveDuplicates(input);
      
    }else{
      return removeConsecutiveDuplicates(input+1);
      
    }
  
}

int main(){
	char str[1000];
	cin >> str;

	removeConsecutiveDuplicates(str);

	cout << str;

}