#include <stdio.h>
#include <stdlib.h>

struct node
{
    char Problem[1000];
    char ans1[100];
    int People1;
    int Court1;
    int Treasury1;
    char ans2[100];
    int People2;
    int Court2;
    int Treasury2;
    struct node *next;
};

void openning (void);
void enter_name (int max_len, char name[max_len]);
int menu (void);
void clear (void);
struct node * get_problems (int *no_problems);

int main()
{
    openning();
    printf("you are : %d", menu());
}

void clear(void)
{
    system("CLS");
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
    printf("\n\n\n");
}

int menu(void)
{
    printf("What do you want?\n1) Start new GAME\n2) Load GAME\n3) Score board\n4) Quit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        {
            clear();
            printf("Are you sure???[Y/n]\n");
            while(1)
            {
                char quit_ans;
                fflush(stdin);
                scanf("%c", &quit_ans);
                if (quit_ans == 'Y')
                {
                    printf("OK, No problem!!!\n");
                    return 0;
                }
                else if (quit_ans == 'n')
                {
                    clear();
                    return menu();
                }
                else
                {
                    clear();
                    printf("Invalid value... [Y,n]???\n");
                }
            }
        }
    }
}

struct node * get_problems(int *no_problems)
{
    *no_problems = 0;
    struct ndoe *list = (struct node *)malloc(sizeof(struct ndoe *));
    struct ndoe *head;
    head = list;
    list = NULL;
    FILE *fpp = fopen("CHOICES.txt", "r");
    while(1)
    {
        if (feof(fpp))
        {
            break;
        }
        (*no_problems)++;
        char file_name[20];
        fscanf(fpp, "%s", file_name);
        struct node *new = (struct node *)malloc(sizeof(struct node *));
        FILE *f = fopen(file_name, "r");
        fgets(&(new->Problem), 1000, f);
        fgets(&(new->ans1), 100, f);
        fscanf(f, "%d", &(new->People1));
        fscanf(f, "%d", &(new->Court1));
        fscanf(f, "%d", &(new->Treasury1));
        fgets(&(new->ans2), 100, f);
        fscanf(f, "%d", &(new->People2));
        fscanf(f, "%d", &(new->Court2));
        fscanf(f, "%d", &(new->Treasury2));
        f   close
    }
    return head;
};
