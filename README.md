# Project: 0x19. C - Stacks, Queues - LIFO, FIFO

KNOWLEDGE TO ACQUIRE & APPLY
----------------------------
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables


## Compilation & Output
	$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty


## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 

### Project Goal
To create an interpreter for Monty ByteCodes files.

## Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

# Author:
* [Sheriff Oladimeji](https://github.com/ollycreatif)
