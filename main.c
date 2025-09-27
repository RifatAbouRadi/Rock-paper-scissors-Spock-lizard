
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

enum Shape { ROCK = 0, LIZARD = 1, SCISSORS = 2, PAPER = 3, SPOCK = 4, N_SHAPES = 5 }; // Enum for the 5 shape
enum { WINNING_SCORE = 5 };// Winning score needed to end the game

static const char *shape_name[N_SHAPES]   = { "Rock", "Lizard", "Scissors", "Paper", "Spock" }; // Names of the shapes
static const char *shape_symbol[N_SHAPES] = { "🪨",   "🦎",      "✂️",        "📄",    "🖖"    }; // Symbols for the shapes

// result[a][b] =  1 if a beats b, -1 if a loses to b, 0 if tie
static const int result[N_SHAPES][N_SHAPES] = {
/*            R   L   S   P   K(Spock) */
/* R */     { 0,  1,  1, -1, -1 }, //Rock
/* L */     { -1, 0, -1,  1,  1 }, //Lizard
/* S */     { -1, 1,  0,  1, -1 }, //Scissors
/* P */     { 1, -1, -1,  0,  1 }, //Paper
/* K */     { 1, -1,  1, -1,  0 } //Spock
};

// Discard leftover characters in input buffer
static void flush_line(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* eat the rest */ }
}

// Menu: returns 's' for single player or 'e' for exit
static int read_menu(void) {
    for (;;) {
        puts("Welcome to Rock-Paper-Scissors-Spock-Lizard!");
        puts("(s) Single player");
        puts("(e) Exit");
        fputs("Select an item: ", stdout);
        int c = getchar();
        if (c == EOF) { puts("\nEOF received. Bye!"); return 'e'; } // handle end of fil
        flush_line();
        c = tolower(c);
        if (c == 's' || c == 'e') return c;
        puts("❌ Menu key does not exist. Try again.\n");
    }
}

// Print the choices with numbers and symbols
static void print_choices(void) {
    puts("\nSelect a shape:");
    for (int i = 0; i < N_SHAPES; ++i) {
        printf("%d %-8s %s%s", i, shape_name[i], shape_symbol[i], (i==N_SHAPES-1) ? "\n" : "  ||  ");
    }
}


// Ask player to select a shape (0–4), return index
static int read_shape(void) {
    for (;;) {
        print_choices();
        fputs("> ", stdout);
        int c = getchar();
        if (c == EOF) { puts("\nEOF received."); return -1; }
        if (c == '\n') continue;      // blank line → re-prompt
        int digit = c - '0';
        flush_line();
        if (0 <= digit && digit < N_SHAPES) return digit;
        puts("❌ Shape key does not exist. Try again.");
    }
}

// Compare human vs agent shapes, update scores
static void round_outcome(int human, int agent, int *hs, int *as) {
    printf("You:   %s %s\n", shape_name[human], shape_symbol[human]);
    printf("Agent: %s %s\n", shape_name[agent], shape_symbol[agent]);
    int r = result[human][agent];
    if (r > 0) { ++*hs; puts("🙋 You win this round!"); }
    else if (r < 0) { ++*as; puts("🤖 Agent wins this round!"); }
    else puts("🤝 Tie.");
    printf("Score  You:%d  Agent:%d\n\n", *hs, *as);
}

int main(void) {
    srand((unsigned)time(NULL));

    for (;;) {
        int choice = read_menu();
        if (choice == 'e') break;

        puts("\nStarting game 🎉");
        int human_score = 0, agent_score = 0;

        while (human_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
            int h = read_shape();
            if (h < 0) { puts("Game aborted."); return 0; }
            int a = rand() % N_SHAPES;             // agent plays randomly
            round_outcome(h, a, &human_score, &agent_score);
        }

        if (human_score == WINNING_SCORE) puts("🎊 You won!");
        else                               puts("🤖 Agent won!");
        puts("");
    }

    puts("Bye!");
    return 0;
}
