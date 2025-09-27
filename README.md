# Rock-paper-scissors-Spock-lizard


## Project Description
This program simulates the extended version of the classic Rock-Paper-Scissors game by adding **Spock** and **Lizard**.  
The player competes against an agent (computer) that plays randomly.  

The game keeps track of the score, announces round results, and ends when either the player or the agent reaches the winning score.  
Invalid inputs (both in the menu and shape selection) are handled with error messages, and the program exits gracefully on `EOF`.

---

## Features
- Entry menu with:
  - `(s)` → Start single-player game  
  - `(e)` → Exit the program  
- Uses **enum** to represent the 5 shapes (Rock, Paper, Scissors, Spock, Lizard).  
- **Agent plays randomly** using random number generation.  
- **Score tracking** after each round.  
- Handles **wrong input** and shows error messages.  
- First to the **WINNING_SCORE** (default = 5) ends the match.  
- Fun emoji-based output 🎉.  

---

## Files
- `rpssl.c` → Source code of the game  
- `README.md` → This documentation  

---

## How to Compile and Run

### Option 1: Run in an Online C Compiler
If GCC is not available, you can use an online C compiler such as:  
👉 [Programiz Online C Compiler](https://www.programiz.com/c-programming/online-compiler)

### Option 2: Compile with GCC locally
```bash
gcc main.c
a.exe 
