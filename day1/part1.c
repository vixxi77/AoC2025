#include <stdio.h>

#define MIN 0
#define MAX 99

int main(){
	FILE *file;
	file = fopen("input.txt", "r");
	char buffer[10];
	int finished_flag = 0;
	char direction;
	int zero_count = 0;
	int code_position = 50;
	
	while(fgets(buffer, 10, file)){
		int number = 0;
		for(int i = 0; buffer[i] != '\n'; i++){
			if(buffer[i] == 'R' || buffer[i] == 'L'){
				direction = buffer[i];
			}else{
				number = number * 10 + (buffer[i] - '0');
			}
		}

		switch(direction){
		case 'R':
			for(int i = 1; i != (number + 1); i++){
				if(code_position == MAX){
					code_position = -1;
				}
				code_position += 1;	
			}
			break;
		case 'L':
			for(int i = 1; i != (number + 1); i++){
				if(code_position == MIN){
					code_position = 100;
				}
				code_position -= 1;	
			}
			break;
		}
		if(code_position == 0)
			zero_count++;

	}

	printf("Amount of times the arrow was left on zero: %d \n", zero_count);


	fclose(file);
	return 0;
}

