# CPE_2016_matchsticks

Nim gam e/ Marienbad
This is a game with pyramid lines full of sticks and you have to take 1 to x sticks (x is the number of maximum sticks you can take per round). You are playing agaisnt an IA based on the XOR algorithm.
To win you have to let the other player take the last sticks.
There is a bonus where you have an ncurses interface, and you can choose the difficulty level of the IA.

```
***********
*    |    *
*   |||   *
*  |||||  *
* ||||||| *
*|||||||||*
***********
```

## Getting Started

This game is programmed in C on a Linux environment.

### Prerequisites

To compile we are using gcc.
The bonus use the ncruses library.

### Installing

To install the game please use the Makefile to compile the original game.

```
$> make
```

If you want to try the bonus

```
$> cd bonus
$> make
```

At the end you should have a "matchstick" binary in your current folder.

## Running the programm

To run the original : 

Replace {nbr lines} by a number representing the number of lines in the pyramid.
Replace {max match} by a number representing the max number of match to take in a round.
```
$> ./matchstick {nbr lines} {max match}
```

To run the bonus : 

Replace {nbr lines} by a number representing the number of lines in the pyramid.
Replace {max match} by a number representing the max number of match to take in a round.
Replace {IA level} by a number representing the level of the IA (0, 1 or 2).

```
$> ./matchstick {nbr lines} {max match} {IA level}
```


## Authors

* **Sébastien Tan** - *Developer* - [Setanas](https://github.com/Setanas)