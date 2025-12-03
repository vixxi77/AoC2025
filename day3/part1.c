#include <stdio.h>

int main(){

	FILE *file;
	file = fopen("input.txt", "r");
	char buffer[512];
	int first_number = 0;
	int second_number = 0;
	int max = 0;
	int current_number = 0;
	int sum = 0;

	while(fgets(buffer, sizeof(buffer), file)){
		first_number = 0;
		second_number = 0;
		current_number = 0;
		max = 0;

		for(int i = 0; buffer[i] != '\n'; i++){
			first_number = buffer[i] - '0';


			for(int j = i + 1; buffer[j] != '\n'; j++){

				second_number = buffer[j] - '0';

				current_number = first_number * 10 + second_number;	

				if(current_number > max){
					max = current_number;
				} 

			}

		}

		sum += max;

	//	printf("LARGEST NUMBER: %d \n", max);
	//	printf("LARGET FIRST NUMBER: %d, AT INDEX: %d \n", first_number, first_number_index);
	//	printf("LARGET SECOND NUMBER: %d, AT INDEX: %d \n", second_number, second_number_index);
	}

	printf("all joaltages together: %d \n", sum);
	return 0;

}
