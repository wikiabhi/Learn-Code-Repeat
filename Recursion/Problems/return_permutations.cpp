#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
  	if(input.empty()){
      output[0] = "";
      return 1;
    }
  
  	int size;
  	
  
  	for(int i=0; i<input.length(); i++){
      	string smallInput = input.substr(0,i) + input.substr(i+1);
      	//string* smallOutput = new string[size];
      	string smallOutput[10000] = {""};
      
      	size = returnPermutations(smallInput, smallOutput);
      	
      	for(int j=0; j<size; j++){
          output[j + i * size] = input[i] + smallOutput[j]; 
        }
      
    }
  
  	return size * input.length(); 
  	
}
