/********************************************************************************************************************
/   AUTHOR: ELF
/   COURSE: C Programming
/   PROGRAM NAME: perfLab15C.c
/   PROGRAM DESCRIPTION: Performance lab C  - Errno
/   INSTRUCTIONS:
Use appropriate error handling (assert vs errno) to handle I/O errors.

Replicated the error to test your implementation.
**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS	
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define BUFFER_SIZE 12

int main(void)
{
	char string[BUFFER_SIZE] = { 0 };
	char *inputString = string;
	assert(inputString);
	int goodInput = 0;
	int currentErrno = 0;
	int inputNumber;
	while (goodInput == 0)
	{
		printf("Enter a number: ");
		fgets(inputString, BUFFER_SIZE, stdin);
		currentErrno = errno;
		assert(inputString);
		if (currentErrno != 0)
		{
			printf("Error: %s\n",strerror(currentErrno));
			errno = 0;
			while (fgetc(stdin) != '\n');
		}
		inputNumber = atoi(inputString);
		currentErrno = errno;
		if (currentErrno != 0)
		{
			printf("Error: %s\n", strerror(currentErrno));
			errno = 0;
		}
		else
		{
			goodInput = 1;
		}

	}
	printf("%d\n", inputNumber);

	while (1);
	return 0;
}
