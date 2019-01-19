#include <stdio.h>
#include <stdlib.h>

void openning (void);
void enter_name (int max_len, char name[max_len]);
void menu(void);

int main()
{
    openning();
    menu();
}

void enter_name (int max_len, char name[max_len])
{
    scanf("%s", name);
    return;
}

void openning (void)
{
    for (int i = 0; i < 37; i++)
    {
        printf("=");
    }
    printf("\n\n            WARNING!!! \n\nIf you are under 18 close the program\n\n");
    for (int i = 0; i < 37; i++)
    {
        printf("=");
    }
    printf("\n\nPress any key to countinue...\n");
    //char s;
    fflush(stdin);
    getchar();
}

void menu(void)
{
    printf("What do you want?\n");
    printf("1) Start new GAME\n");
    printf("2) Load GAME\n");
    printf("3) Score board\n");
    printf("4) Quit );\n");
    int choise;
    scanf("%d", choise);
    //switch(choise)

}
