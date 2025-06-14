#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fibonacci(int n) {
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
	return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(int argc, char *argv[]) {
    // Error: No input provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <non-negative integer>\n", argv[0]);
        exit(1);
    }

    int num = atoi(argv[1]);
    // Error: Invalid input (negative or non-integer)
    if (num < 0 || num == 0) {
        fprintf(stderr, "Error: Please enter a non negative number\n");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) { // Fork failed
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (pid == 0) { // Child process
        printf("Child Process PID: %d\n", getpid());
		printf("Fibonacci sequence: ");
        
        // Generate Fibonacci sequence
        for (int i = 0; i < num; i++) {
			printf("%d ", fibonacci(i));
			}
		printf("\n");
		exit(0);
    } else { // Parent process
        wait(NULL); // Wait for child to complete
		printf("Parent process PID: %d\n", getpid());
    }
    return 0;
}