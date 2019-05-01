#include <stdio.h>
#include <malloc.h>

#define length 250

struct Student
{
    char ln[length];
    char fn[length];
    char fa[length];
    int group;
    int marks[4];
};

int main() {
    FILE *p;
    struct Student *s;
    int n, i;


    p = fopen("7.txt","r");

    fscanf(p, "%d", &n);
    s = (struct Student *)malloc(n * sizeof(struct Student));


    for (i = 0; i < n; ++i) {
        fscanf(p, "%s %s %s %d %d %d %d %d", (s+i)->ln, (s+i)->fn, (s+i)->fa,
                &(s+i)->group, &(s+i)->marks[0], &(s+i)->marks[1], &(s+i)->marks[2], &(s+i)->marks[3] );

    }
    printf("Smart: ");
    for(i = 0; i < n; i++)
    {
        if(s[i].marks[0] == 5 && s[i].marks[1] == 5 && s[i].marks[2] == 5 && s[i].marks[3] == 5) {
                printf("%s ", s[i].ln);
        }
    }
    printf("\nStupid: ");
    for(i = 0; i < n; i++)
    {
        if(s[i].marks[0] == 2 || s[i].marks[1] == 2 || s[i].marks[2] == 2 || s[i].marks[3] == 2) {
                printf("%s ", s[i].ln);
        }
    }
    
    free(s);

    printf("\n");
}
