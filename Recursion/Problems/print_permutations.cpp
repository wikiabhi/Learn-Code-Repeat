#include <iostream>
#include <string>
using namespace std;

void print(string input, string output){
  if(input.empty()){
    cout << output << endl;
    return;
  }
	
  for(int i=0; i<input.length(); i++){
    string smallInput = input.substr(0,i) + input.substr(i+1);
    
    print(smallInput, output + input[i]);
  }
  
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  string output = "";
  print(input, output);
   
}

int main(){
  string s;
  cin >> s;

  printPermutations(s);
}
