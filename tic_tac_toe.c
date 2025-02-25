#include<stdio.h>
int conditions_of_x(int x[3][3]);
int conditions_of_o(int x[3][3]);
void print_array(int array[3][3]);
int block_break(char a1, char a2,
char a3, char a4, char a5, char a6, char a7, char a8,
char a9, int value_of_x_or_o);

int main(){

    int value_of_x, value_of_o, x[3][3], check, stop_loop = 0;
    char a1 =' ', a2 = ' ', a3 = ' ', a4 = ' ', a5 = ' ', a6 = ' ', a7 = ' ', a8 = ' ', a9 = ' ';
    int breaks_x, breaks_o, stop_credits;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            x[i][j] = 0;
        }        
    }

    for(int i = 0; i < 5; i++)
    {

    stop_loop = stop_loop + 1;

        printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n", a1,a2,a3,a4,a5,a6,a7,a8,a9);
        printf("player 1 [x] : ");
        scanf("%d", &value_of_x);
        
        
        breaks_x = block_break(a1,a2,a3,a4,a5,a6,a7,a8,a9,value_of_x);
        if (breaks_x == 1){
            stop_credits = 1;
            break;
        }
        
        if (value_of_x < 1 || value_of_x > 9)
        {   
            printf("select a block from 1 to 9\n");
            printf("restart the game");
            stop_credits = 1;
            break;
        }
             
        switch (value_of_x)
        {
        case 1:
            x[0][0] = 2;
            a1 = 'x';
            break;

        case 2:
            x[0][1] = 2;
            a2 = 'x';
            break;

        case 3:
            x[0][2] = 2;
            a3 = 'x';
            break;

        case 4:
            x[1][0] = 2;
            a4 = 'x';
            break;

        case 5:
            x[1][1] = 2;
            a5 = 'x';
            break;

        case 6:
            x[1][2] = 2;
            a6 = 'x';
            break;
        
        case 7:
            x[2][0] = 2;
            a7 = 'x';
            break;

        case 8:
            x[2][1] = 2;
            a8 = 'x';
            break;

        case 9:
            x[2][2] = 2;
            a9 = 'x';
            break;
        
        default:
            break;
        }

        printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n", a1,a2,a3,a4,a5,a6,a7,a8,a9);
        
    check = conditions_of_x(x);
    if (check == 1){
        break;
    }
    
    if (stop_loop == 5)
    {
        break;
    }

    printf("player 2 [O] : ");
    scanf("%d", &value_of_o);

    if ( value_of_o < 1 || value_of_o > 9)
        {   
            printf("select a block from 1 to 9\n");
            printf("restart the game");
            stop_credits = 1;
            break;
        }

    breaks_o = block_break(a1,a2,a3,a4,a5,a6,a7,a8,a9,value_of_o);
        if (breaks_o == 1){
            stop_credits = 1;
            break;
        }
    
    switch (value_of_o){
        
        case 1:
            x[0][0] = 3;
            a1 = 'o';
            break;

        case 2:
            x[0][1] = 3;
            a2 = 'o';
            break;

        case 3:
            x[0][2] = 3;
            a3 = 'o';
            break;

        case 4:
            x[1][0] = 3;
            a4 = 'o';
            break;

        case 5:
            x[1][1] = 3;
            a5 = 'o';
            break;

        case 6:
            x[1][2] = 3;
            a6 = 'o';
            break;
        
        case 7:
            x[2][0] = 3;
            a7 = 'o';
            break;

        case 8:
            x[2][1] = 3;
            a8 = 'o';
            break;

        case 9:
            x[2][2] = 3;
            a9 = 'o';
            break;
        
        default:
            break;
        } 
    
        check = conditions_of_o(x);
        if (check == 1){
        break;

        printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n", a1,a2,a3,a4,a5,a6,a7,a8,a9);
          
    }
    
    }
    
    if (breaks_x == 1 || breaks_o == 1)
    {
        check = 1; // to stop printing "match tied"
    }
    
    if(check == 0 && stop_credits != 1){
        printf("match tied !\n");
    }
    
    if (stop_credits != 1)
    {
        printf("%c | %c | %c\n%c | %c | %c\n%c | %c | %c\n", a1,a2,a3,a4,a5,a6,a7,a8,a9);
        printf("THANKS FOR PLAYING !\nMADE BY HACKER KALAM :)");
    }
    
}

int conditions_of_x(int x[3][3]){
    int verify = 0;
    
    // check rows
    for(int i = 0; i < 3; i++){
        if (x[i][0] == 2 && x[i][1] == 2 && x[i][2] == 2){
            verify = 1;
            printf("player 1 [x] won\n");
                
        }
    }

    // check columns
    if(verify == 0){
        for(int j = 0; j < 3; j++){
            if (x[0][j] == 2 && x[1][j] == 2 && x[2][j] == 2){
                verify = 1;
                printf("player 1 [x] won\n");
                     
        }
    }
    }

    if(verify == 0){ 
        if (((x[0][0] == 2 && x[1][0] == 2) && x[2][0] == 2) || ((x[0][1] == 2 && x[1][1] == 2) && x[2][1] == 2)){
            verify = 1;
            printf("player 1 [x] won\n");
    }
   }

    if (verify == 0)
   {   
        if ((x[2][0] == 2 && x[2][1] == 2) && x[2][2] == 2){
            verify = 1;
            printf("player 1 [x] won\n");    
    
    }
   }

    if(verify == 0){ 
        if ((x[0][0] == 2 && x[1][1] == 2) && x[2][2] == 2 || (x[0][2] == 2 && x[1][1] == 2) && x[2][0] == 2){
            verify = 1;
            printf("player 1 [x] won\n");

    } 
   }  
        return verify;     
    
}

int conditions_of_o(int x[3][3]){
    int verify = 0;
    
    // check rows
    for(int i = 0; i < 3; i++){
        if (x[i][0] == 3 && x[i][1] == 3 && x[i][2] == 3){
            verify = 1;
            printf("player 2 [o] won\n");
            
        }
    }

    // check columns
    if(verify == 0){ 
        for(int j = 0; j < 3; j++){
            if (x[0][j] == 3 && x[1][j] == 3 && x[2][j] == 3){
                verify = 1;
                printf("player 2 [o] won\n");
           
        }
    }
   }
    
    if(verify == 0){
        if (((x[0][0] == 3 && x[1][0] == 3) && x[2][0] == 3) || ((x[0][1] == 3 && x[1][1] == 3) && x[2][1] == 3)){
            verify = 1;
            printf("player 2 [o] won\n");
    }
  }

    if(verify == 0){
        if ((x[2][0] == 3 && x[2][1] == 3) && x[2][2] == 3){
            verify = 1;
            printf("player 2 [o] won\n");    
    
    }
  }

    if(verify == 0){
        if ((x[0][0] == 3 && x[1][1] == 3) && x[2][2] == 3 || (x[0][2] == 3 && x[1][1] == 3) && x[2][0] == 3){
            verify = 1;
            printf("player 2 [o] won\n");

    }   
}
        return verify;     
    
}

int block_break(char a1, char a2, 
char a3, char a4, char a5, char a6, char a7, char a8,
char a9, int value_of_x_or_o){
    int cancel = 0;
    if ((a1 == 'x' || a1 == 'o') && (value_of_x_or_o == 1))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a2 == 'x' || a2 == 'o') && (value_of_x_or_o == 2))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;
        }
    if ((a3 == 'x' || a3 == 'o') && (value_of_x_or_o == 3))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a4 == 'x' || a4 == 'o') && (value_of_x_or_o == 4))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a5 == 'x' || a5 == 'o') && (value_of_x_or_o == 5))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a6 == 'x' || a6 == 'o') && (value_of_x_or_o == 6))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a7 == 'x' || a7 == 'o') && (value_of_x_or_o == 7))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a8 == 'x' || a8 == 'o') && (value_of_x_or_o == 8))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
    if ((a9 == 'x' || a9 == 'o') && (value_of_x_or_o == 9))
        {
            printf("block already taken\nrestart the game !");
            cancel = 1;

        }
        return cancel;    
}

/* 

I made three mistakes(1,2,3) and got one doubt(4) so i used ai.

1. arrays should be started with 0 not 1. i used 1 as the 
first index of the array. this was a mistake. so i changed.

2. I have used nested for loop. it crossed the array 3x3. 
so I have fixed this error.

3.the program used to print player 1 won or player 2 won twice.
the problem was 2 conditions were satisfied simultaneously. so
i made an if condition to check if the previous condition was
satisfied. if that happened other conditions won't run. 

4. i = i - 1; used to stay at the same loop position when user gives
wrong input. [ less than 1 or greater than 9 ] 


# for revision purpose

1. I used break block function to avoid printing "match tied"
if user enters a block that has already taken.

2. this function was used in this game to print the array

void print_array(int x[3][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
        {
            printf("%d    ", x[i][j]);
            
        }        
            printf("\n");
      }
}



*/