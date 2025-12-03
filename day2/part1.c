#include <stdio.h>
#include <string.h>
#include <time.h>

int invalid_id_check(const long _id);
int invalid_id_check_nocalls(const long _id);

int main(){
	FILE *file;
	file = fopen("input.txt", "r");
	char buffer[4096];
	long sum = 0;
	
	time_t start = clock();

	while(fgets(buffer, sizeof(buffer), file )){
		buffer[strcspn(buffer, "\n")] = 0;
		
		char *token = strtok(buffer, ",");
		while(token != NULL){
			long START, END;
			sscanf(token, "%ld-%ld", &START, &END);
			for(long i = START; i <= END; i++){
				if(invalid_id_check_nocalls(i)){
					sum += i;
					//printf("Invalid id found %ld \n", i);
				}
			}
			printf("%ld to %ld \n", START, END);
			token = strtok(NULL, ",");
		}
	}

	time_t end = clock();
	double final_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time to calcucalte: %.4f", final_time);

	printf("final sum is: %ld", sum);

	fclose(file);
	return 0;
}

int invalid_id_check(const long _id){
	char _buffer[200];
	sprintf(_buffer, "%ld", _id);

	int length = strlen(_buffer);

	if(length % 2 != 0) return 0;

	int half = length/2;

	if(strncmp(_buffer, half + _buffer, half) == 0) return 1;

	return 0;
}

int invalid_id_check_nocalls(const long _id){

	long x = _id;
	int length = 0;

	while(x){
		x /= 10;
		length++;
	}

	if(length % 2 != 0) return 0;

	int half = length/2;

	long power10 = 1;

	for(int i = 0; i < half; i++) 
		power10 *= 10;

	long first = _id / power10;
	long second = _id % power10;
	
	return first == second;
}
