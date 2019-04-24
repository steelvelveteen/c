#include<stdio.h>
#include<stdlib.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display(island *start) {
    island *i = start;
    for (;i != NULL; i = i->next) {
        printf("Name: %s Opens: %s Closes: %s\n", i->name,i->opens,i->closes);
    }
}

island *create_island(char *name);

// main entry point 
int main(int argc, char **argv) {

    island amity = {"Amity", "09:00","17:00",NULL};
    island craggy = {"Craggy","09:00","17:00",NULL};
    island isla_nublar = {"Isla Nublar","09:00","17:00",NULL};
    island shutter = {"Shutter","09:00","17:00",NULL };

    // Connecting islands
    amity.next = &craggy;
    craggy.next = &isla_nublar;
    isla_nublar.next = &shutter;

    // display(&amity);
    printf("\n");

    // Inserting an island 'skull' between nublar and shutter
    island skull = {"Skull","09:00","17:00", NULL };
    isla_nublar.next = &skull;
    skull.next = &shutter;

    display(&amity);
    fprintf(stdout,"Now creating an Island dynamically...\n");
    fprintf(stdout,"Name your new island: ");
    char new_island_name[50];
    // fgets(new_island_name, sizeof(new_island_name), stdin);
    scanf("%50s", new_island_name);
    printf("Name selected: %s\n", new_island_name);

    // Call a create island dynamically function
    island *new_island = create_island(new_island_name);
    shutter.next = new_island;

    display(&amity);

    free(new_island);
    return 0;
}

island *create_island(char *name) {
    island *i = malloc(sizeof(island));
    i->name = name;
    i->opens = "08:00";
    i->closes = "18:00";
    i->next = NULL;
    return i;
}
