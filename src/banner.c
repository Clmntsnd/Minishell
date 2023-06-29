#include "../include/minishell.h"

/* void	banner(void)
{
	printf("\n");
	printf(KGRE " ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    \n");
	printf("▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    \n");
	printf(KRED KBLD"▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    \n" RESET);
	printf("▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    \n");
	printf("▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒\n");
	printf("░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░\n");
	printf("░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░\n");
	printf("░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░\n");
	printf("░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   \n");
	printf("       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░\n" RESET);
} */

/* // VSCode
void	banner(void)
{
	//printf(KRED BLD "\n😈😈😈 Welcome to miniꞩhell ... or should I say 🔥 MINIHELLLL 🔥 😈😈😈\n\n" RESET);
	printf(KYEL BLD"	 _____________________________  __________________            \n");
	printf(KYEL BLD"	|                              /                  |          \n");
	printf(KYEL BLD"	|               _       _     /_          _ _     |          \n");
	printf(KYEL "	|     _ __ ___ (_)_ __ (_)___/| |__   ___| | |    |        \n" RESET);
	printf(KYEL "	|    | '_ ` _ \\| | '_ \\| / _/_| '_ \\ / _ \\ | |    |          \n");
	printf(KRED "	|    | | | | | | | | | | \\_/__\\ | | |  __/ | |    |      \n" RESET);
	printf(KRED BLD"	|    |_| |_| |_|_|_| |_|_|/___/_| |_|\\___|_|_|    |   \n" RESET);
	printf(KRED BLD"	|                        /                        |   \n" RESET);
	printf(KRED BLD"	|_______________________/                         |   \n" RESET);
	printf(KRED BLD"	                                                  |   \n" RESET);
	printf("		    ...powered by " KYEL "gle-roux🐭 " RESET "&" KRED " csenand🐭" KRED BLD"  |\n" RESET);
	printf(KRED BLD"	__________________________________________________|   \n\n" RESET);
	printf("				...evaluated by " KRED BLD EVALUATOR" \n\n" RESET);
} */

// TERMINAL
void	banner(void)
{
	//printf(KRED BLD "\n😈😈😈 Welcome to miniꞩhell ... or should I say 🔥 MINIHELLLL 🔥 😈😈😈\n\n" RESET);
	printf(KYEL"	 _____________________________  __________________            \n");
	printf(KYEL"	|                              /                  |          \n");
	printf(KYEL BLD"	|               _       _     /_          _ _     |          \n");
	printf(KYEL BLD"	|     _ __ ___ (_)_ __ (_)___/| |__   ___| | |    |        \n" RESET);
	printf(KRED BLD"	|    | '_ ` _ \\| | '_ \\| / _/_| '_ \\ / _ \\ | |    |          \n");
	printf(KRED BLD"	|    | | | | | | | | | | \\_/__\\ | | |  __/ | |    |      \n" RESET);
	printf(KRED BLD"	|    |_| |_| |_|_|_| |_|_|/___/_| |_|\\___|_|_|    |   \n" RESET);
	printf(KRED"	|                        /                        |   \n" RESET);
	printf(KRED"	|_______________________/                         |   \n" RESET);
	printf(KRED"	                                                  |   \n" RESET);
	printf("		    ...powered by " KYEL "gle-roux🐭 " RESET "&" KRED " csenand🐭" KRED"  |\n" RESET);
	printf(KRED"	__________________________________________________|   \n\n" RESET);
	printf("				...evaluated by " KRED BLD "USER \n\n" RESET);
}
