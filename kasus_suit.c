#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

char suit[3][100], player[2][100], next[2][100];
unsigned int start = 2, repeat, seri, nonValid, ronde = 2, nilaiPlayer[3];
int i;
// aturan pada permainan
int aturan()
{
    if (strcmp(player[0], "✊") == 0 && strcmp(player[1], "✌️") == 0 || strcmp(player[0], "✌️") == 0 && strcmp(player[1], "✋") == 0 ||
        (strcmp(player[0], "✋") == 0 && strcmp(player[1], "✊") == 0))
    {
        printf("player 1 WIN🌟\n\n");
        nilaiPlayer[0]++;
    }
    else if (strcmp(player[0], "✌️") == 0 && strcmp(player[1], "✊") == 0 || strcmp(player[0], "✋") == 0 && strcmp(player[1], "✌️") == 0 || (strcmp(player[0], "✊") == 0 && strcmp(player[1], "✋") == 0))
    {
        printf("player 2 WIN🌟\n\n");
        nilaiPlayer[1]++;
    }
    else if (strcmp(player[0], "✊") == 0 && strcmp(player[1], "✊") == 0 || strcmp(player[0], "✌️") == 0 && strcmp(player[1], "✌️") == 0 || (strcmp(player[0], "✋") == 0 && strcmp(player[1], "✋") == 0))
    {
        printf("SERI🤜🤛\n\n");
        seri++;
        if (seri == 1)
        {
            ronde++;
        }
    }
    sleep(1);
    return 0;
}

// program yang menjalankan logika dari suit
void suitPlayer()
{
    for (i = 0; i < 2; i++)
    {
        if (strcmp(suit[i], "1") == 0 || strcmp(suit[i], "batu") == 0)
        {
            strcpy(player[i], "✊");
        }
        else if (strcmp(suit[i], "2") == 0 || strcmp(suit[i], "gunting") == 0)
        {
            strcpy(player[i], "✌️");
        }
        else if (strcmp(suit[i], "3") == 0 || strcmp(suit[i], "kertas") == 0)
        {
            strcpy(player[i], "✋");
        }
        else
        {
            printf("nilai tidak valid\n");
            strcpy(player[i], " ");
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

// program untuk memberikan kondisi player
void kondisiPlayer()
{
    if (player[0] != player[1])
    {
        if (nilaiPlayer[0] == nilaiPlayer[1])
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
    sprintf(suit[1], "%d", randomChoice);
}

// program yang memproses nilai dari player
void nilaiAkhir()
{
    if (nilaiPlayer[0] + nilaiPlayer[1] == 3 || nilaiPlayer[0] == 2 && nilaiPlayer[1] == 0 || nilaiPlayer[0] == 0 && nilaiPlayer[1] == 2)
    {
        for (i = 0; i < 2; i++)
        {
            printf("nilai PLAYER %d adalah %d\n", i + 1, nilaiPlayer[i]);
            sleep(1);
        }
        printf("\n");

        printf("%s memenangkan pertandingan⭐⭐⭐\n", (nilaiPlayer[0] > nilaiPlayer[1]) ? "PLAYER 1" : "PLAYER 2");
        sleep(1);
        ronde = 2, repeat = 0, seri = 0, nonValid = 0, nilaiPlayer[0] = 0, nilaiPlayer[1] = 0;
        while (nonValid == 0)
        {

            printf("apakah ingin melanjutkan permainan? (Y/T): ");
            sleep(1);
            scanf("%c", &next);
            fflush(stdin);
            next = toupper(next);
            if (next == 'T')
            {
                exit(0);
            }
            else if (next == 'Y')
            {
                nonValid = 1;
                printf("\n\n");
            }
            else
            {
                printf("nilai tidak valid\n");
            }
        }
    }
}

int main()
{
    printf("===============================================\n");
    printf("=-----------WELCOME TO SUIT BATTLE!-----------=\n");
    printf("=----------Press 1 to start the game----------=\n");
    printf("=----------Press 0 to quit the game-----------=\n");
    printf("===============================================\n");
    while (next == 'T')
    {
        printf("Enter your answer : ");
        scanf("%d", &start);
        fflush(stdin);
        if (start == 1)
        {
            next = 'Y';
        }
        else if (start == 0)
        {
            exit(0);
        }
        else
        {
            printf("nilai tidak valid\n");
        }
    }

    while (next == 'Y')
    {
        while (repeat < ronde)
        {
            printf("===============================================\n");
            printf("RONDE %d\n", repeat + 1);
            printf("silahkan pilih suit player 1\n");
            printf("1. batu\n");
            printf("2. gunting\n");
            printf("3. kertas\n");
            printf("Enter your answer : ");
            scanf("%[^\n]%*c", suit[0]);
            printf("-----------------------------------------------\n");
            printf("Pemilihan suit secara acak untuk player 2 (bot)\n");
            sleep(1);
            botPlayer();
            repeat++;
            suitPlayer();

            if (strcmp(player[0], " ") == 0)
            {
                printf("\n");
            }
            else
            {
                printf("PLAYER 1 : %s\n", player[0]);
                sleep(1);
                printf("PLAYER 2 : %s\n", player[1]);
                sleep(1);
                aturan();
                printf("===============================================\n");
                kondisiPlayer();
                nilaiAkhir();
            }
        }
    }

    return 0;
}
