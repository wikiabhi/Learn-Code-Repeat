#include <iostream>
using namespace std;

int alphaCode(long int number, int* result, int dig_count){
	if(dig_count == 0){
		result[0] = 1;
		return 1;
	}
	if(dig_count == 1){
		result[1] = 1;
		return 1;
	}


	if(result[dig_count] > 0 ){
		return result[dig_count];
	}

	int output = alphaCode(number/10, result, dig_count-1);

	if(number % 100 <= 26){
		output += alphaCode(number/100, result, dig_count-2);
	}

	result[dig_count]= output;
	return output;
}

int main(){
	long int input[100];
	cin >> input[0];
	for(int i=1; input[i-1]!= 0; i++){
		cin >> input[i];
	}

	for(int i=0; input[i]!= 0; i++){
		int copy = input[i];
		int dig_count = 0;
		for(int i=0; copy!= 0; i++){
			copy /= 10;
			dig_count++;
		}
		int* output = new int[dig_count];
      	for(int i=0; i<dig_count; i++){
			output[i] = 0;
        }
		cout << alphaCode(input[i], output, dig_count+1) << endl;
	}
}