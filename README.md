Hunt
====

Hunt down all burning lights except for the bottom row.

This can analyze the game lights out quickly for you.
Please excuse my coding style, I did not have much time to write this.

Hunt will first ask you for width and height of the board.
Then you can choose to hunt all options or to hunt a custom option

Hunt all options:
	All combinations of lights clicked in the upper row will be tested.
	The lights will be clicked, so their neighbours will turn on as well.

	Output looks like this:
	10101:10001
	Where 10101 are the lights clicked in the upper row, and 10001 are the lights which are on at the bottom after hunting.

Hunt custom:
	You will be asked to enter a horizontal and a vertical coordinate for the light you want on. Here, the neighbours of the light will not turn on. After each light, you can choose to enter another or to hunt and print the bottom row.

To build, just run Make.
