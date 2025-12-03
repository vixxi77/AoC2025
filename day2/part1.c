#include <stdio.h>
#include <string.h>

int invalid_id_check(const long _id);

int main(){
	FILE *file;
	file = fopen("input.txt", "r");
	char buffer[4096];
	long sum = 0;

	while(fgets(buffer, sizeof(buffer), file )){
		buffer[strcspn(buffer, "\n")] = 0;
		
		char *token = strtok(buffer, ",");
		while(token != NULL){
			long START, END;
			sscanf(token, "%ld-%ld", &START, &END);
			for(long i = START; i <= END; i++){
				if(invalid_id_check(i)){
					sum += i;
					//printf("Invalid id found %ld \n", i);
				}
			}
			printf("%ld to %ld \n", START, END);
			token = strtok(NULL, ",");
		}
	}
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
