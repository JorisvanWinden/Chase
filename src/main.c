#include <stdio.h>
#include "hunt.h"

// asks for board with and height, prompts what to do, does it. Cleans up.
int main(int argc, char * argv[])
{
	int M, N;
	printf("Enter board width: ");
	scanf("%d", &N);
	printf("Enter board height: ");
	scanf("%d", &M);

	printf("Enter 1 to display all hunts\nEnter 2 to create a custom hunt: ");
	int res;
	scanf("%d", &res);

	if(res == 1)
	{
		hunt_all(M, N);
	} else if (res == 2)
	{
		hunt_custom(M, N);
	}
}
