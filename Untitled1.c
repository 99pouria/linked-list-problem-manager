#include <stdio.h>
#include <stdlib.h>

struct node
{
    char Problem[200];
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
struct node * get_problems (int *number_of_problems);

int main()
{
    int num = 0;
    openning();

    struct node *head = get_problems(&num);


    for (struct node *list = head; list != NULL; list = list -> next)
    {
        printf("%s\n", list->Problem);
        printf("%s\n", list->ans1);
        printf("%d\n", list->People1);
        printf("%d\n", list->Court1);
        printf("%d\n", list->Treasury1);
        printf("%s\n", list->ans2);
        printf("%d\n", list->People2);
        printf("%d\n", list->Court2);
        printf("%d\n", list->Treasury2);
    }
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

struct node * get_problems(int *number_of_problems)
{
    *number_of_problems = 0;
    struct node *list = (struct node *)malloc(sizeof(struct node));
    struct node *head;
    list = head = NULL;
    FILE *fpp = fopen("CHOICES.txt", "r");
    if (fpp == NULL)
    {
        printf("No file with 'CHOICES.txt' name founded\n");
        return NULL;
    }
    int i = 1;
    while(1)
    {
        if (feof(fpp))
        {
            break;
        }
        (*number_of_problems)++;
        char file_name[20];
        fscanf(fpp, "%s", file_name);
        struct node *newD = (struct node *)malloc(sizeof(struct node));
        FILE *f = fopen(file_name, "r");
        if(f == NULL)
        {
            printf("No 'problem file' founded\n");
            break;
        }
        fgets(&newD->Problem, 200, f);
        fgets(&newD->ans1, 100, f);
        fscanf(f, "%d", &newD->People1);
        fscanf(f, "%d", &newD->Court1);
        fscanf(f, "%d", &newD->Treasury1);
        fseek(f, 2 * sizeof(char), SEEK_CUR);
        fgets(&newD->ans2, 100, f);
        fscanf(f, "%d", &newD->People2);
        fscanf(f, "%d", &newD->Court2);
        fscanf(f, "%d", &newD->Treasury2);
        fclose(f);
        list = newD;
        list->next = NULL;
        if (i++ == 1)
        {
            head = list;
        }
        list = list -> next;
    }
    fclose(fpp);
    return head;
}
