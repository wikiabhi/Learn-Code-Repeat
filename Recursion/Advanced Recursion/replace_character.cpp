#include <iostream>
#include <string>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
   
  	if(input[0] == '\0'){
      return;
    }
  
  	if(input[0] == c1){
      input[0] = c2;
      return replaceCharacter(input+1, c1, c2);
      
    }else{
      return replaceCharacter(input+1, c1, c2);      
    }
    
}

int main(){
	char str[1000];
	cin >> str;


	char c1, c2;  //c1 to find and replace with c2
	cin >> c1 >> c2;

	replaceCharacter(str, c1, c2);

	cout << str;
}