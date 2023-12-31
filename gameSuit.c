#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

typedef struct
{
    char suit[10];
    int nilaiPlayer[3];
    char player[10];
    int pilihan;
} statusPlayer;

statusPlayer p[2];
char start[20];
char next[30] = "T";
char fragmentSuit[4][20][100] = {
    {"                                ",
     "                                ",
     "                                ",
     "                                ",
     "                                ",
     "                                ",
     "      ##     ##  ######         ",
     "      ##     ## ##    ##        ",
     "      ##     ## ##              ",
     "      ##     ##  ######         ",
     "       ##   ##        ##        ",
     "        ## ##   ##    ##        ",
     "         ###     ######         ",
     "                                ",
     "                                ",
     "                                ",
     "                                ",
     "                                "},

    {"                                ",
     "                                ",
     "           @@@ @                ",
     "         @@  @   @@@@           ",
     "       @@   @@   @  @@@         ",
     "      @     @@  @@  @  @        ",
     "     @@  @@@@@  @   @  @        ",
     "     @@  @@  @ @   @@  @        ",
     "     @@   @ @@@@@ @@  @         ",
     "      @  @@        @@@@         ",
     "      @              @          ",
     "       @            @@          ",
     "        @@        @@@           ",
     "        @          @@           ",
     "         @@@@    @@@            ",
     "             @@@                ",
     "                                ",
     "                                "},

    {"       @@        @@@            ",
     "      @@ @      @   @           ",
     "      @   @    @@  @@           ",
     "      @@   @   @   @            ",
     "       @   @@ @@   @            ",
     "       @    @ @    @            ",
     "       @@   @ @  @@             ",
     "        @ @@@@@@@  @@           ",
     "        @     @    @@@          ",
     "       @   @@@@  @@ @@          ",
     "      @   @  @  @   @           ",
     "      @   @@   @ @@ @           ",
     "      @@  @         @           ",
     "       @  @        @@           ",
     "        @         @@            ",
     "        @@@@    @ @             ",
     "         @@@     @@             ",
     "             @@@                "},

    {"              @@@@              ",
     "       @@     @  @@   @@@@      ",
     "      @  @@   @   @  @   @      ",
     "      @   @@  @   @ @@   @      ",
     "       @   @  @   @ @   @       ",
     "       @@   @ @   @ @   @ @@@@  ",
     "        @   @@@   @@   @ @@  @  ",
     "    @@   @   @    @    @@   @   ",
     "   @  @@ @@           @@  @@    ",
     "   @@   @@@              @@     ",
     "     @@   @@            @@      ",
     "       @    @          @@       ",
     "        @   @@         @        ",
     "        @@  @          @        ",
     "         @@          @@         ",
     "           @@@    @@@@          ",
     "           @@@     @@           ",
     "               @@@              "}};

char fragmentScore[3][7][20] = {
    {"  #####  ",
     " ##   ## ",
     "##     ##",
     "##     ##",
     "##     ##",
     " ##   ## ",
     "  #####  "},

    {"    ##   ",
     "  ####   ",
     "    ##   ",
     "    ##   ",
     "    ##   ",
     "    ##   ",
     "  ###### "},

    {" ####### ",
     "##     ##",
     "       ##",
     " ####### ",
     "##       ",
     "##       ",
     "#########"}};

unsigned int border, repeat, seri, nonValid, ronde = 2;

// fungsi the end
void end()
{
    printf("===========================================================================================================================================================================================\n");
    printf("==                                                                ######## ##     ## ########    ######## ##    ## ########                                                              ==\n");
    printf("==                                                                   ##    ##     ## ##          ##       ###   ## ##     ##                                                             ==\n");
    printf("==                                                                   ##    ##     ## ##          ##       ####  ## ##     ##                                                             ==\n");
    printf("==                                                                   ##    ######### ######      ######   ## ## ## ##     ##                                                             ==\n");
    printf("==                                                                   ##    ##     ## ##          ##       ##  #### ##     ##                                                             ==\n");
    printf("==                                                                   ##    ##     ## ##          ##       ##   ### ##     ##                                                             ==\n");
    printf("==                                                                   ##    ##     ## ########    ######## ##    ## ########                                                              ==\n");
    printf("===========================================================================================================================================================================================\n");
}

// fungsi error
void error()
{
    printf("===========================================================================================================================================================================================\n");
    printf("==                                                                                     INVALID VALUE!!                                                                                   ==\n");
    printf("===========================================================================================================================================================================================\n");
}
// aturan pada permainan
int aturan()
{
    printf("===========================================================================================================================================================================================\n");
    if (strcmp(&(p[0].player[0]), "rock") == 0 && strcmp(&(p[1].player[0]), "scissors") == 0 || strcmp(&(p[0].player[0]), "scissors") == 0 && strcmp(&(p[1].player[0]), "paper") == 0 || (strcmp(&(p[0].player[0]), "paper") == 0 && strcmp(&(p[1].player[0]), "rock") == 0))
    {
        printf("==                                                                                        YOU WIN                                                                                        ==\n");

        p[0].nilaiPlayer[0]++;
    }
    else if (strcmp(&(p[0].player[0]), "scissors") == 0 && strcmp(&(p[1].player[0]), "rock") == 0 || strcmp(&(p[0].player[0]), "paper") == 0 && strcmp(&(p[1].player[0]), "scissors") == 0 || (strcmp(&(p[0].player[0]), "rock") == 0 && strcmp(&(p[1].player[0]), "paper") == 0))
    {
        printf("==                                                                                        YOU LOSE                                                                                       ==\n");

        p[1].nilaiPlayer[0]++;
    }
    else if (strcmp(&(p[0].player[0]), "rock") == 0 && strcmp(&(p[1].player[0]), "rock") == 0 || strcmp(&(p[0].player[0]), "scissors") == 0 && strcmp(&(p[1].player[0]), "scissors") == 0 || (strcmp(&(p[0].player[0]), "paper") == 0 && strcmp(&(p[1].player[0]), "paper") == 0))
    {
        printf("==                                                                                          DRAW                                                                                         ==\n");
        seri++;
        if (seri == 1)
        {
            ronde++;
        }
    }
    printf("===========================================================================================================================================================================================\n");

    sleep(1);
    return 0;
}

// program yang menjalankan logika dari suit
void suitPlayer()
{
    for (border = 0; border < 2; border++)
    {
        if (strcmp((p[border].suit), "1") == 0)
        {
            strcpy(&(p[border].player[0]), "rock");
            p[border].pilihan = 1;
        }
        else if (strcmp((p[border].suit), "2") == 0)
        {
            strcpy(&(p[border].player[0]), "scissors");
            p[border].pilihan = 2;
        }
        else if (strcmp((p[border].suit), "3") == 0)
        {
            strcpy(&(p[border].player[0]), "paper");
            p[border].pilihan = 3;
        }
        else
        {
            error();
            strcpy(&(p[border].player[0]), " ");
            nonValid++;
            if (nonValid >= 1)
            {
                if (repeat != 0)
                {
                    repeat--;
                }
            }
        }
    }
    sleep(1);
}

void emoji()
{
    printf("===========================================================================================================================================================================================\n");
    printf("==                                         PLAYER 1                                         ==                                            PLAYER 2                                       ==\n");
    printf("===========================================================================================================================================================================================\n");

    for (border = 0; border < 18; border++)
    {
        printf("==                               %s             %s                 %s                          ==\n", fragmentSuit[p[0].pilihan][border], fragmentSuit[0][border], fragmentSuit[p[1].pilihan][border]);
        sleep(0.1);
    }
}
// program untuk memberikan kondisi player
void kondisiPlayer(int *a, int *b)
{
    if (&(p[0].player[0]) != &(p[1].player[0]))
    {
        if (*a == *b)
        {
            ronde++;
        }
    }
    seri = 0;
    nonValid = 0;
}

// program membuat bot player
void botPlayer()
{
    srand((unsigned int)time(NULL));
    int randomChoice = rand() % 3 + 1;
    sprintf(p[1].suit, "%d", randomChoice);
}

// program yang memproses nilai dari player
void nilaiAkhir()
{
    if (p[0].nilaiPlayer[0] + p[1].nilaiPlayer[0] == 3 || p[0].nilaiPlayer[0] == 2 && p[1].nilaiPlayer[0] == 0 || p[0].nilaiPlayer[0] == 0 && p[1].nilaiPlayer[0] == 2)
    {

        printf("==                                                                                         SCORE                                                                                         ==\n");
        printf("===========================================================================================================================================================================================\n");
        printf("==                                         PLAYER 1                                         ==                                            PLAYER 2                                       ==\n");
        printf("===========================================================================================================================================================================================\n");
        for (border = 0; border < 7; border++)
        {
            printf("==                                        %s                                         ==                                            %s                                      ==\n", fragmentScore[p[0].nilaiPlayer[0]][border], fragmentScore[p[1].nilaiPlayer[0]][border]);
            sleep(0.1);
        }
        printf("===========================================================================================================================================================================================\n");
        printf("==                                                                                      %s WINS                                                                                    ==\n", (p[0].nilaiPlayer[0] > p[1].nilaiPlayer[0]) ? "PLAYER 1" : "PLAYER 2");
        printf("===========================================================================================================================================================================================\n");
        sleep(1);
        ronde = 2, repeat = 0, seri = 0, nonValid = 0, p[0].nilaiPlayer[0] = 0, p[1].nilaiPlayer[0] = 0;
        while (nonValid == 0)
        {

            printf("do you want to continue the game?(Y/N): ");
            sleep(1);
            scanf("%s", &next);
            fflush(stdin);
            int panjang_next = strlen(next);
            next[0] = toupper(next[0]);
            if (panjang_next == 1 && strcmp(next, "N") == 0 || strcmp(next, "Y") == 0)
            {
                if (strcmp(next, "N") == 0)
                {
                    end();
                    exit(0);
                }
                else if (strcmp(next, "Y") == 0)
                {
                    nonValid = 1;
                    printf("\n");
                }
            }
            else
            {
                error();
            }
        }
    }
}

int main()
{
    printf("===========================================================================================================================================================================================\n");
    printf("==##      ## ######## ##        ######   #######  ##     ## ########    ########  #######      ######  ##     ## #### ########    ########     ###    ######## ######## ##       ########==\n");
    printf("==##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##             ##    ##     ##    ##    ## ##     ##  ##     ##       ##     ##   ## ##      ##       ##    ##       ##      ==\n");
    printf("==##  ##  ## ######   ##       ##       ##     ## ## ### ## ######         ##    ##     ##     ######  ##     ##  ##     ##       ########  ##     ##    ##       ##    ##       ######  ==\n");
    printf("==##  ##  ## ##       ##       ##       ##     ## ##     ## ##             ##    ##     ##          ## ##     ##  ##     ##       ##     ## #########    ##       ##    ##       ##      ==\n");
    printf("==##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##             ##    ##     ##    ##    ## ##     ##  ##     ##       ##     ## ##     ##    ##       ##    ##       ##      ==\n");
    printf("== ###  ###  ######## ########  ######   #######  ##     ## ########       ##     #######      ######   #######  ####    ##       ########  ##     ##    ##       ##    ######## ########==\n");
    printf("===========================================================================================================================================================================================\n");
    printf("== --->Press [9] to start the game                                                                                                                                                       ==\n");
    printf("== --->Press [0] to quit the game                                                                                                                                                        ==\n");
    printf("===========================================================================================================================================================================================\n");

    while (strcmp(next, "T") == 0)
    {
        printf("Enter your answer : ");
        scanf("%s", &start);
        fflush(stdin);
        if (strcmp(start, "9") == 0)
        {
            strcpy(next, "Y");
        }

        else if (strcmp(start, "0") == 0)
        {
            end();
            exit(0);
        }
        else
        {
            printf("\n");
            error();
        }
    }

    while (strcmp(next, "Y") == 0)
    {
        while (repeat < ronde)
        {
            printf("===========================================================================================================================================================================================\n");
            printf("==                                                                                        RONDE  %d                                                                                       ==\n", repeat + 1);
            printf("==                                                                             PLEASE SELECT A SUIT FOR PLAYER 1                                                                         ==\n");
            printf("== ---->Press [1] to choise a rock                                                                                                                                                       ==\n");
            printf("== ---->Press [2] to choise a scissor                                                                                                                                                    ==\n");
            printf("== ---->Press [3] to choise a paper                                                                                                                                                      ==\n");
            printf("===========================================================================================================================================================================================\n");
            printf("Enter your answer : ");
            scanf("%s", &(p[0].suit));
            fflush(stdin);
            printf("===========================================================================================================================================================================================\n");
            printf("==                                                                         RANDOM SELECTION OF SUIT FOR PLAYER 2 [BOT]                                                                   ==\n");
            botPlayer();
            repeat++;
            suitPlayer();

            if (strcmp(&(p[0].player[0]), " ") == 0)
            {
                printf("\n");
            }
            else
            {
                emoji();
                sleep(1);
                aturan();
                kondisiPlayer(&(p[0].nilaiPlayer[0]), &(p[1].nilaiPlayer[0]));
                nilaiAkhir();
            }
        }
    }

    return 0;
}
