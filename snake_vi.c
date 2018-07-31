
#include<stdio.h>
#include<conio.h>

struct food {
    int x;
    int y;
    char value;
};
struct snake_node {
    int x, y;
    char value;
    struct snake_node *next;
    char direction_of_node;
    char rev_direction_of_node;
};
struct snake_legs {
    struct snake_node *front_legs;
    struct snake_node *back_legs;
    char direction;
    char opposite_direction;
};


int isCurrentPositionValid(struct snake_legs *movement_pointer, int min_gridX, int min_gridY, int max_gridX, int max_gridY) {
    if(movement_pointer->front_legs->x<=max_gridX && movement_pointer->front_legs->x >= min_gridX && movement_pointer->front_legs->y<=max_gridY && movement_pointer->front_legs->y >= min_gridY) {
        return 1;
    } else return 0;
}
void bringSnakeFromOppositeSide(struct snake_legs *movement_pointer, int min_gridX, int min_gridY, int max_gridX, int max_gridY) {
    if(movement_pointer->front_legs->x < min_gridX) movement_pointer->front_legs->x = max_gridX;
    else if(movement_pointer->front_legs->x >= max_gridX) movement_pointer->front_legs->x = min_gridX;
    else if(movement_pointer->front_legs->y < min_gridY) movement_pointer->front_legs->y = max_gridY;
    else if(movement_pointer->front_legs->y >= max_gridY) movement_pointer->front_legs->y = min_gridY;
}
struct snake_node* reverse(struct snake_node *ptr) {
    struct snake_node *temp_ptr;
    if(ptr->next!=NULL) {
        temp_ptr = reverse(ptr->next);
        temp_ptr->next = ptr;
        return ptr;
    }
    else {
        return ptr;
    }
}
void reverse_the_snake(struct snake_legs *movement_pointer) {
    reverse(movement_pointer->back_legs);
    movement_pointer->back_legs->next = NULL;
    movement_pointer->back_legs->value = 'A';
    movement_pointer->front_legs->value = 'T';
    struct snake_legs *temp = movement_pointer->front_legs;
    movement_pointer->front_legs = movement_pointer->back_legs;
    movement_pointer->back_legs = temp;
}
void move_snake(struct snake_legs *movement_pointer, char new_direction, int min_gridX, int min_gridY, int max_gridX, int max_gridY) {
    switch(new_direction) {
        case 'a':
            if(new_direction != movement_pointer->opposite_direction) {
                struct snake_node *ptr = movement_pointer->back_legs;
                movement_pointer->back_legs = ptr->next;
                movement_pointer->back_legs->value = 'T';
                movement_pointer->front_legs->next = ptr;
                ptr->next = NULL;
                ptr->direction_of_node = 'a';
                ptr->rev_direction_of_node = 'd';
                movement_pointer->front_legs->value = '#';
                ptr->x = movement_pointer->front_legs->x;
                ptr->y = movement_pointer->front_legs->y-1;
                movement_pointer->front_legs = ptr;
                ptr->value = 'A';
                movement_pointer->direction = 'a';
                movement_pointer->opposite_direction = 'd';
                int isValid = isCurrentPositionValid(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                if(!isValid) {
                    bringSnakeFromOppositeSide(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                }
            } else {
                move_snake(movement_pointer, 'd', 0, 0, 29, 99);
            }
            break;
        case 'd':
            if(new_direction != movement_pointer->opposite_direction) {
                struct snake_node *ptr = movement_pointer->back_legs;
                movement_pointer->back_legs = ptr->next;
                movement_pointer->back_legs->value = 'T';
                movement_pointer->front_legs->next = ptr;
                ptr->next = NULL;
                ptr->direction_of_node = 'd';
                ptr->rev_direction_of_node = 'a';
                movement_pointer->front_legs->value = '#';
                ptr->x = movement_pointer->front_legs->x;
                ptr->y = movement_pointer->front_legs->y+1;
                movement_pointer->front_legs = ptr;
                ptr->value = 'A';
                movement_pointer->direction = 'd';
                movement_pointer->opposite_direction = 'a';
                int isValid = isCurrentPositionValid(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                if(!isValid) {
                    bringSnakeFromOppositeSide(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                }
            } else {
                move_snake(movement_pointer, 'a', 0, 0, 29, 99);
            }
            break;
        case 'w':
            if(new_direction != movement_pointer->opposite_direction) {
                struct snake_node *ptr = movement_pointer->back_legs;
                movement_pointer->back_legs = ptr->next;
                movement_pointer->back_legs->value = 'T';
                movement_pointer->front_legs->next = ptr;
                ptr->next = NULL;
                ptr->direction_of_node = 'w';
                ptr->rev_direction_of_node = 's';
                movement_pointer->front_legs->value = '#';
                ptr->x = movement_pointer->front_legs->x-1;
                ptr->y = movement_pointer->front_legs->y;
                movement_pointer->front_legs = ptr;
                ptr->value = 'A';
                movement_pointer->direction = 'w';
                movement_pointer->opposite_direction = 's';
                int isValid = isCurrentPositionValid(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                if(!isValid) {
                    bringSnakeFromOppositeSide(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                }
            } else {
                move_snake(movement_pointer, 's', 0, 0, 29, 99);
            }
            break;
        case 's':
            if(new_direction != movement_pointer->opposite_direction) {
                struct snake_node *ptr = movement_pointer->back_legs;
                movement_pointer->back_legs = ptr->next;
                movement_pointer->back_legs->value = 'T';
                movement_pointer->front_legs->next = ptr;
                ptr->next = NULL;
                ptr->direction_of_node = 's';
                ptr->rev_direction_of_node = 'w';
                movement_pointer->front_legs->value = '#';
                ptr->x = movement_pointer->front_legs->x+1;
                ptr->y = movement_pointer->front_legs->y;
                movement_pointer->front_legs = ptr;
                ptr->value = 'A';
                movement_pointer->direction = 's';
                movement_pointer->opposite_direction = 'w';
                int isValid = isCurrentPositionValid(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                if(!isValid) {
                    bringSnakeFromOppositeSide(movement_pointer, min_gridX, min_gridY, max_gridX, max_gridY);
                }
            } else {
                move_snake(movement_pointer, 'w', 0, 0, 29, 99);
            }
            break;
        case 'r':
            reverse_the_snake(movement_pointer);
            movement_pointer->direction = movement_pointer->front_legs->rev_direction_of_node;
            movement_pointer->opposite_direction = movement_pointer->front_legs->direction_of_node;
            char dir = movement_pointer->front_legs->direction_of_node;
            movement_pointer->front_legs->direction_of_node = movement_pointer->front_legs->rev_direction_of_node;
            movement_pointer->front_legs->rev_direction_of_node = dir;
            break;
    }
}



int main() {
    int i, j, p, m, syscls, s2;
    char ch;
    char grid[30][100];


    struct food food_position;
    food_position.x = 15;
    food_position.y = 16;
    food_position.value = 'X';

    // initialize snake values like head and tail
    struct snake_legs *legs = (struct snake_legs *)malloc(sizeof(struct snake_legs));
    legs->front_legs = (struct snake_node *)malloc(sizeof(struct snake_node));
    legs->back_legs  = (struct snake_node *)malloc(sizeof(struct snake_node));
    legs->direction = 'd';
    legs->opposite_direction = 'a';
    legs->front_legs->x = 10;
    legs->front_legs->y = 30;
    legs->back_legs->x = 10;
    legs->back_legs->y = 29;
    legs->front_legs->value = 'A';
    legs->back_legs->value = 'T';
    legs->front_legs->direction_of_node = 'd';
    legs->front_legs->rev_direction_of_node = 'a';
    legs->back_legs->direction_of_node = 'd';
    legs->back_legs->rev_direction_of_node = 'a';
    legs->front_legs->next = NULL;
    legs->back_legs->next = legs->front_legs;


    // add some nodes in between head and tail of snake
    for(i = 0 ; i < 5 ; i++) {
        struct snake_node *another_node = (struct snake_node *)malloc(sizeof(struct snake_node));
        another_node->next = legs->back_legs->next;
        legs->back_legs->next = another_node;
        another_node->x = legs->back_legs->x;
        another_node->y = legs->back_legs->y;
        another_node->direction_of_node = legs->back_legs->direction_of_node;
        another_node->direction_of_node = legs->back_legs->rev_direction_of_node;
        another_node->value = '#';
        legs->back_legs->y--;
    }

    while (1) {

        // initialize grid with empty character value like space
        for(i = 0 ; i < 30 ; i++) {
            for(j = 0 ; j < 100 ; j++) {
                grid[i][j] = ' ';
            }
        }

        // give grid values hold by snake
        struct snake_node *a_pointer;
        a_pointer = legs->back_legs;
        while(a_pointer!=NULL) {
            grid[a_pointer->x][a_pointer->y] = a_pointer->value;
            a_pointer = a_pointer->next;
        }

        // give grid value of food position
        grid[food_position.x][food_position.y] = food_position.value;



        // print grid on screen
        for(i = 0 ; i < 30 ; i++) {
            for(j = 0 ; j < 100 ; j++) {
                printf("%c",grid[i][j]);
            }
            printf("\n");
        }
        if(kbhit()) {
            ch = getch();
            move_snake(legs, ch, 0, 0, 29, 99);
        }
        else move_snake(legs, legs->direction, 0, 0, 29, 99);
        for(syscls = 0 ; syscls < 50000 ; syscls++){
            for(s2 = 0 ; s2 < 2000 ; s2++) {}
        }
       // system("cls");
    }
}
