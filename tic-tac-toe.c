#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main(void);
char end(int *table)
{
    char i;
    for(i=0;i<3;i++)
    {
        ///checking for vertical win
        if((*(table+i))%3!=0)
            if((*(table+i))%3==(*(table+i+3))%3&&(*(table+i))%3==(*(table+i+6))%3)
            {
                if((*(table+i))%3==1)
                    return 1;
                else
                    return 2;
            }
        ///checking for horizontal win
        if((*(table+i*3))%3!=0)
            if((*(table+i*3))%3==(*(table+i*3+1))%3&&(*(table+i*3))%3==(*(table+i*3+2))%3)
            {
                if((*(table+i*3))%3==1)
                    return 1;
                else
                    return 2;
            }
    }
    ///checking for diagonal win
    if(((*(table+4))%3!=0 &&
         (
           ((*(table))%3==(*(table+4))%3 && (*(table))%3==(*(table+8))%3 ) ||
           ((*(table+2))%3==(*(table+4))%3 && (*(table+2))%3==(*(table+6))%3 )
         )
      ))
      {
        if((*(table+4))%3==1)
            return 1;
        else
            return 2;
      }
    for(i=0;i<9;i++)
        if((*(table+i))%3==0)
            i=11;
    if(i==12)
        return 0;
    return 3;
}
void cpu_update(int pic[20][26],int *table,char playing_position)
{
    ///building x
    if((*(table+playing_position))%3==1)
    {
        pic[playing_position/3*(6+1)+1][playing_position%3*(8+1)+2]='\\';
        pic[playing_position/3*(6+1)+2][playing_position%3*(8+1)+3]='\\';
        pic[playing_position/3*(6+1)+3][playing_position%3*(8+1)+4]='\\';
        pic[playing_position/3*(6+1)+4][playing_position%3*(8+1)+5]='\\';
        pic[playing_position/3*(6+1)+1][playing_position%3*(8+1)+8-3]='/';
        pic[playing_position/3*(6+1)+2][playing_position%3*(8+1)+8-4]='/';
        pic[playing_position/3*(6+1)+3][playing_position%3*(8+1)+8-5]='/';
        pic[playing_position/3*(6+1)+4][playing_position%3*(8+1)+8-6]='/';
    }
    ///building o
    else if((*(table+playing_position))%3==2)
    {
        pic[playing_position/3*(6+1)+1][playing_position%3*(8+1)+2]='/';
        pic[playing_position/3*(6+1)+1][playing_position%3*(8+1)+3]=238;
        pic[playing_position/3*(6+1)+1][playing_position%3*(8+1)+4]=238;
        pic[playing_position/3*(6+1)+1][playing_position%3*(8+1)+5]='\\';
        pic[playing_position/3*(6+1)+2][playing_position%3*(8+1)+1]=179;
        pic[playing_position/3*(6+1)+2][playing_position%3*(8+1)+6]=179;
        pic[playing_position/3*(6+1)+3][playing_position%3*(8+1)+1]=179;
        pic[playing_position/3*(6+1)+3][playing_position%3*(8+1)+6]=179;
        pic[playing_position/3*(6+1)+4][playing_position%3*(8+1)+2]='\\';
        pic[playing_position/3*(6+1)+4][playing_position%3*(8+1)+3]='_';
        pic[playing_position/3*(6+1)+4][playing_position%3*(8+1)+4]='_';
        pic[playing_position/3*(6+1)+4][playing_position%3*(8+1)+5]='/';
    }

}
void player_update(int pic[20][26],int *table,char last_square_position)
{
    char i,j,square_position=-1;
    ///finding square position
    for(i=0;i<9&&!(square_position+1);i++)
        if((*(table+i))>2)
            square_position=i;
    ///deleting square from previous position
    {
        for(j=0;j<8;j++)
            pic[last_square_position/3*(6+1)][(last_square_position%3)*(8+1)+j]=' ';
        for(j=1;j<6-1;j++)
        {
            pic[last_square_position/3*(6+1)+j][(last_square_position%3)*(8+1)]=' ';
            pic[last_square_position/3*(6+1)+j][(last_square_position%3)*(8+1)+8-1]=' ';
        }
        for(j=0;j<8;j++)
            pic[last_square_position/3*(6+1)+6-1][(last_square_position%3)*(8+1)+j]=' ';
    }
    ///building x
    if((*(table+square_position))%3==1)
    {
        pic[square_position/3*(6+1)+1][square_position%3*(8+1)+2]='\\';
        pic[square_position/3*(6+1)+2][square_position%3*(8+1)+3]='\\';
        pic[square_position/3*(6+1)+3][square_position%3*(8+1)+4]='\\';
        pic[square_position/3*(6+1)+4][square_position%3*(8+1)+5]='\\';
        pic[square_position/3*(6+1)+1][square_position%3*(8+1)+8-3]='/';
        pic[square_position/3*(6+1)+2][square_position%3*(8+1)+8-4]='/';
        pic[square_position/3*(6+1)+3][square_position%3*(8+1)+8-5]='/';
        pic[square_position/3*(6+1)+4][square_position%3*(8+1)+8-6]='/';
    }
    ///building o
    else if((*(table+square_position))%3==2)
    {
        pic[square_position/3*(6+1)+1][square_position%3*(8+1)+2]='/';
        pic[square_position/3*(6+1)+1][square_position%3*(8+1)+3]=238;
        pic[square_position/3*(6+1)+1][square_position%3*(8+1)+4]=238;
        pic[square_position/3*(6+1)+1][square_position%3*(8+1)+5]='\\';
        pic[square_position/3*(6+1)+2][square_position%3*(8+1)+1]=179;
        pic[square_position/3*(6+1)+2][square_position%3*(8+1)+6]=179;
        pic[square_position/3*(6+1)+3][square_position%3*(8+1)+1]=179;
        pic[square_position/3*(6+1)+3][square_position%3*(8+1)+6]=179;
        pic[square_position/3*(6+1)+4][square_position%3*(8+1)+2]='\\';
        pic[square_position/3*(6+1)+4][square_position%3*(8+1)+3]='_';
        pic[square_position/3*(6+1)+4][square_position%3*(8+1)+4]='_';
        pic[square_position/3*(6+1)+4][square_position%3*(8+1)+5]='/';
    }
    return;
}
void print(int pic[20][26])
{
    unsigned char i,j;
    printf("USE THE WASD KEYS TO MOVE AND SPACE TO PLAY\n\n");
    ///printing board
    for(i=0;i<20;i++)
    {
        for(j=0;j<26;j++)
            printf("%c",pic[i][j]);
        printf("\n");
    }
    return;
}
void start(int pic[20][26])
{
    unsigned char i,j;
    ///filling the spaces and fixing the vertical lines
    for(i=0;i<20;i++)
    {
        for(j=0;j<8;j++)
            pic[i][j]=' ';
        pic[i][8]=179;
        for(j=9;j<17;j++)
            pic[i][j]=' ';
        pic[i][17]=179;
        for(j=18;j<26;j++)
            pic[i][j]=' ';
    }
    ///fixing the horizontal lines(6
    {
        for(i=0;i<26;i++)
            pic[6][i]=196;
        for(i=0;i<26;i++)
            pic[13][i]=196;
    }
    ///fixing the 4 points where the horizontal and vertical lines meet
    pic[6][8]=pic[6][17]=pic[13][8]=pic[13][17]=197;
    return;
}
int check(int *table,int s1,int s2,int s3)
{
    ///checking if s1 position is equal to s2 and if s3 is free to play
    if(((*(table+s1))%3==(*(table+s2))%3)&&(*(table+s1))%3!=0&&(*(table+s3))%3==0)
        return s3;
    ///same for s1 and s3
    else if(((*(table+s1))%3==(*(table+s3))%3)&&(*(table+s1))%3!=0&&(*(table+s2))%3==0)
        return s2;
    ///and for s2 and s3
    else if(((*(table+s3))%3==(*(table+s2))%3)&&(*(table+s2))%3!=0&&(*(table+s1))%3==0)
        return s1;
    ///returns 0 if nothing is true
    return 0;
}
void move(int pic,int *table,char first)
{
    char i,j,temp_playing_position,playing_position=-1;
    ///checking if there are two same shapes in a row so that cpu to win or to block(first to win then to block)
    for(j=2;j>=1;j--)
    {
        if((temp_playing_position=check(table,0,1,2))&&((*table)%3==j||(*(table+1))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,3,4,5))&&((*(table+3))%3==j||(*(table+4))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,6,7,8))&&((*(table+6))%3==j||(*(table+7))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,0,3,6))&&((*table)%3==j||(*(table+3))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,1,4,7))&&((*(table+1))%3==j||(*(table+4))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,2,5,8))&&((*(table+2))%3==j||(*(table+5))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,0,4,8))&&((*table)%3==j||(*(table+4))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((temp_playing_position=check(table,2,4,6))&&((*(table+2))%3==j||(*(table+4))%3==j))
        {
            playing_position=temp_playing_position;
            (*(table+playing_position))+=2;
            cpu_update(pic,table,playing_position);
            return;
        }
    }
    ///counts the number of times that player has played at a corner and at an edge
    char corner_counter=0;
    char edge_counter=0;
    for(i=0;i<9;i++)
        if(i%2==1)
            if((*(table+i))%3==1)
                edge_counter+=1;
    for(i=0;i<9;i++)
        if(i%2==0&&i!=4)
            if((*(table+i))%3==1)
                corner_counter+=1;
    if(first=='y'||first=='Y')
    {
        /**
        checking for this position or anything symmetrical to it:
         x |   |
        ---|---|---
           | 0 |
        ---|---|---
           | x |
        so that it won't play at any losing position
        */
        if(playing_position==-1&&corner_counter==1&&edge_counter==1)
        {
            if(((*(table))%3==1&&(*(table+7))%3==1)||((*(table+8))%3==1&&(*(table+3))%3==1))
            {
                (*(table+6))+=2;
                playing_position=6;
                cpu_update(pic,table,playing_position);
                return;
            }
            else if(((*(table))%3==1&&(*(table+5))%3==1)||((*(table+8))%3==1&&(*(table+1))%3==1))
            {
                (*(table+2))+=2;
                playing_position=2;
                cpu_update(pic,table,playing_position);
                return;
            }
            else if(((*(table+2))%3==1&&(*(table+7))%3==1)||((*(table+6))%3==1&&(*(table+5))%3==1))
            {
                (*(table+8))+=2;
                playing_position=8;
                cpu_update(pic,table,playing_position);
                return;
            }
            else if(((*(table+2))%3==1&&(*(table+3))%3==1)||((*(table+6))%3==1&&(*(table+1))%3==1))
            {
                (*(table))+=2;
                playing_position=0;
                cpu_update(pic,table,playing_position);
                return;
            }
        }
        /**
        checking for this position or anything symmetrical to it:
         x |   |
        ---|---|---
           | 0 |
        ---|---|---
           |   | x
        so that it won't play at any losing position
        */
        if(playing_position==-1&&corner_counter==2&&edge_counter==0)
        {
            (*(table+1))+=2;
            playing_position=1;
            cpu_update(pic,table,playing_position);
            return;
        }
        /**
        checking for this position:
           |   |
        ---|---|---
           | 0 | x
        ---|---|---
           | x |
        so that it won't play at any losing position
        */
        if(playing_position==-1&&edge_counter==2&&corner_counter==0&&(*(table+5))%3==1)
        {
            (*(table+8))+=2;
            playing_position=8;
            cpu_update(pic,table,playing_position);
            return;
        }
    }
    else
    {
        /**checks this position
         0 | X |
        ---|---|---
           | 0 |
        ---|---|---
           |   | X
        */
        if(edge_counter==1&&corner_counter==1&&(*(table+1))%3==1&&(*(table+8))%3==1&&(*(table+4))%3==2)
        {
            (*(table+6))+=2;
            playing_position=6;
            cpu_update(pic,table,playing_position);
            return;
        }
        /**checks this position
         0 | X | 0
        ---|---|---
           |   |
        ---|---|---
           |   | X
        */
        if(edge_counter==1&&corner_counter==1&&(*(table+1))%3==1&&(*(table+8))%3==1&&(*(table+2))%3==2)
        {
            (*(table+6))+=2;
            playing_position=6;
            cpu_update(pic,table,playing_position);
            return;
        }
        ///plays the first move
        if((*(table+4))%3==1&&edge_counter==0&&corner_counter==0)
        {
            (*(table+8))+=2;
            playing_position=8;
            cpu_update(pic,table,playing_position);
            return;
        }
        else if((*(table+4))%3==0&&edge_counter+corner_counter==1)
        {
            if(corner_counter==1)
            {
                if((*(table+8))%3==0)
                {
                    (*(table+8))+=2;
                    playing_position=8;
                    cpu_update(pic,table,playing_position);
                    return;
                }
                else
                {
                    (*(table+2))+=2;
                    playing_position=2;
                    cpu_update(pic,table,playing_position);
                    return;
                }
            }
            else
            {
                (*(table+4))+=2;
                playing_position=4;
                cpu_update(pic,table,playing_position);
                return;
            }
        }
    }
    ///if it didn't yet play:
    if(playing_position==-1)
    {
        ///plays firstly in middle if free, else in first free corner then edge
        if((*(table+4))%3==0)
        {
            (*(table+4))+=2;
            cpu_update(pic,table,4);
            return;
        }
        else if((*(table))%3==0)
        {
            (*(table))+=2;
            cpu_update(pic,table,0);
            return;
        }
        else if((*(table+2))%3==0)
        {
            (*(table+2))+=2;
            cpu_update(pic,table,2);
            return;
        }
        else if((*(table+6))%3==0)
        {
            (*(table+6))+=2;
            cpu_update(pic,table,6);
            return;
        }
        else if((*(table+8))%3==0)
        {
            (*(table+8))+=2;
            cpu_update(pic,table,8);
            return;
        }
        else if((*(table+1))%3==0)
        {
            (*(table+1))+=2;
            cpu_update(pic,table,1);
            return;
        }
        else if((*(table+3))%3==0)
        {
            (*(table+3))+=2;
            cpu_update(pic,table,3);
            return;
        }
        else if((*(table+5))%3==0)
        {
            (*(table+5))+=2;
            cpu_update(pic,table,5);
            return;
        }
        else if((*(table+7))%3==0)
        {
            (*(table+7))+=2;
            cpu_update(pic,table,7);
            return;
        }
        else
        {
            system("cls");
            printf("ERROR");
        }
    }
    return;
}
void square(int pic[20][26],int *table,char last_square_position)
{
    player_update(pic,table,last_square_position);
    int i,square_position;
    ///finds square position
    for(i=0;i<9;i++)
        if((*(table+i))>2)
            square_position=i;
    ///fixes first row of the square
    {
        pic[square_position/3*(6+1)][(square_position%3)*(8+1)]=218;
        for(i=1;i<=8-2;i++)
            pic[square_position/3*(6+1)][(square_position%3)*(8+1)+i]=196;
        pic[square_position/3*(6+1)][(square_position%3)*(8+1)+8-1]=191;
    }
    ///fixes last row of the square
    {
        pic[square_position/3*(6+1)+6-1][(square_position%3)*(8+1)]=192;
        for(i=1;i<=8-2;i++)
            pic[square_position/3*(6+1)+6-1][(square_position%3)*(8+1)+i]=196;
        pic[square_position/3*(6+1)+6-1][(square_position%3)*(8+1)+8-1]=217;
    }
    ///fixes everything in between
    {
        for(i=1;i<=6-2;i++)
        {
            pic[square_position/3*(6+1)+i][(square_position%3)*(8+1)]=179;
            pic[square_position/3*(6+1)+i][(square_position%3)*(8+1)+8-1]=179;
        }
    }
    ///prints the new tic tac toe board
    print(pic);
    return;
}
void wasd(int pic[20][26],int *table,char players,char first,char username1[17],char username2[17])
{
    char square_position=-1,last_square_position,user_file[17];
    int win,draw,loss;
    unsigned char i=0,a,winner,counter=1;
    FILE *somefile;
    ///finds square position before it changes (because the last square position must be erased)
    for(i=0;i<9&&!(square_position+1);i++)
        if((*(table+i))>2)
            square_position=i;
    last_square_position=square_position;
    a=getch();
    ///loop finishes only when game has been won or lost with break
    while(1)
    {
        ///finds where to move square and saves the last square position
        if((a=='d'||a=='D')&&(square_position%3!=2))
        {
            (*(table+square_position))-=3;
            (*(table+square_position+1))+=3;
            last_square_position=square_position;
            square_position+=1;
        }
        else if((a=='a'||a=='A')&&(square_position%3!=0))
        {
            (*(table+square_position))-=3;
            (*(table+square_position-1))+=3;
            last_square_position=square_position;
            square_position-=1;
        }
        else if((a=='s'||a=='S')&&(square_position<6))
        {
            (*(table+square_position))-=3;
            (*(table+square_position+3))+=3;
            last_square_position=square_position;
            square_position+=3;
        }
        else if((a=='w'||a=='W')&&(square_position>2))
        {
            (*(table+square_position))-=3;
            (*(table+square_position-3))+=3;
            last_square_position=square_position;
            square_position-=3;
        }
        ///if player against cpu
        else if(a==' '&&(*(table+square_position))%3==0&&players=='1')
        {
            ///player plays
            (*(table+square_position))+=1;
            ///cpu plays if game hasn't been ended and it saves the winner
            if((winner=end(table)))
            {
                ///shows last tic tac toe board
                player_update(pic,table,last_square_position);
                system("cls");
                square(pic,table,last_square_position);
                break;
            }
            move(pic,table,first);
            player_update(pic,table,last_square_position);
        }
        ///if player against player
        else if(a==' '&&(*(table+square_position))%3==0&&players=='2')
        {
            ///adds 1 or 2 alternatively in a position so that players play alternatively(1 for X and 2 for O)
            counter++;
            (*(table+square_position))+=counter%2+1;
            player_update(pic,table,last_square_position);
        }
        ///print new board
        system("cls");
        square(pic,table,last_square_position);
        ///if at an end it stops else it continues
        if((winner=end(table)))
            break;
        else
            a=getch();
    }
    ///prints who won if any
    if(winner==1&&players=='2')
    {
        printf(username1);
        printf(" WINS!!!\n");
        printf(username2);
        printf(" LOST!!!\n");
        sprintf(user_file,"%s.txt",username1);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win+1,draw,loss);
        fclose(somefile);
        printf(username1);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win+1,draw,loss);
        sprintf(user_file,"%s.txt",username2);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win,draw,loss+1);
        fclose(somefile);
        printf(username2);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win,draw,loss+1);
    }
    else if(winner==2&&players=='2')
    {
        printf(username2);
        printf(" WINS!!!\n");
        printf(username1);
        printf(" LOST!!!\n");
        sprintf(user_file,"%s.txt",username2);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win+1,draw,loss);
        fclose(somefile);
        printf(username2);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n\n",win+1,draw,loss);
        sprintf(user_file,"%s.txt",username1);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win,draw,loss+1);
        fclose(somefile);
        printf(username1);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win,draw,loss+1);
    }
    else if(winner==3)
    {
        printf("DRAW!\n");
        sprintf(user_file,"%s.txt",username1);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win,draw+1,loss);
        fclose(somefile);
        printf(username1);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win,draw+1,loss);
    }
    else if(winner==1)
    {
        printf("YOU WON!!!\n");
        sprintf(user_file,"%s.txt",username1);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win+1,draw,loss);
        fclose(somefile);
        printf(username1);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win+1,draw,loss);
    }
    else if(winner==2)
    {
        printf("YOU LOST\n");
        sprintf(user_file,"%s.txt",username1);
        somefile=fopen(user_file,"r");
        fscanf(somefile,"%d|%d|%d",&win,&draw,&loss);
        fclose(somefile);
        somefile=fopen(user_file,"w");
        fprintf(somefile,"%d|%d|%d",win,draw,loss+1);
        fclose(somefile);
        printf(username1);
        printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win,draw,loss+1);
    }
    system("pause");
    ///when player presses any key cpu will clear the screen
    system("cls");
    ///prints GAME OVER(but in a cool fashion)
    printf("\n   /%c%c%c%c%c\\      /\\      %c\\    /%c   %c%c%c%c%c%c\n",238,238,238,238,238,179,179,179,238,238,238,238,238);
    printf("  %c            /  \\     %c \\  / %c   %c\n",179,179,179,179);
    printf("  %c     ___   /%c%c%c%c\\    %c  \\/  %c   %c%c%c%c%c%c\n",179,196,196,196,196,179,179,179,196,196,196,196,196);
    printf("  %c      %c   /      \\   %c      %c   %c\n",179,179,179,179,179);
    printf("   \\_____/  /        \\  %c      %c   %c_____\n\n\n",179,179,179);
    printf("   /%c%c%c%c\\   \\        /   %c%c%c%c%c%c    %c%c%c\\\n",238,238,238,238,179,238,238,238,238,238,179,238,238);
    printf("  %c      %c   \\      /    %c         %c   )\n",179,179,179,179);
    printf("  %c      %c    \\    /     %c%c%c%c%c%c    %c__/\n",179,179,179,196,196,196,196,196,179);
    printf("  %c      %c     \\  /      %c         %c \\\n",179,179,179,179);
    printf("   \\____/       \\/       %c_____    %c  \\\n\n\n              ",179,179);
    printf("PLAY AGAIN? Y/N\n");
    a=getch();
    ///checking player's input
    while(a!='y' && a!='n' && a!='Y' && a!='N')
    {
        printf("PLEASE ENTER Y FOR YES OR N FOR NO\n");
        a=getch();
    }
    ///if answer is yes starts again
    if(a=='y' || a=='Y')
    {
        system("cls");
        main();
    }
    return;
}
void get_string(char username[17])
{
    unsigned flag=0,i;
    while(!flag)
    {
        fgets(username, 17, stdin);
        fflush(stdin);
        for(i=1;username[i];i++){}
        username[i-1]='\0';
        while(username[0]=='\0')
        {
            printf("USERNAME MUST BE AT LEAST 1 CHARACTER LONG: \n");
            fgets(username, 17, stdin);
            fflush(stdin);
            for(i=1;username[i];i++){}
            username[i-1]='\0';
        }
        flag=1;
        for(i=0;username[i]!='\0';i++)
            if(!((username[i]>='a'&&username[i]<='z')||(username[i]>='A'&&username[i]<='Z')||(username[i]>='0'&&username[i]<='9')||username[i]=='_'))
                flag=0;
        if(!flag)
            printf("CHARCTERS MUST BE A LETTER, A NUMBER OR UNDERSCORE:\n");
    }
}
void enter_name(char player,char username[17],char number_of_players)
{
    char temp_char, user_file[20], temp_username[17],flag;
    FILE *somefile;
    unsigned char i;
    strcpy(temp_username,username);
    system("cls");
    if(number_of_players=='1')
        printf("PLEASE ENTER YOUR USERNAME: \n");
    else
    {
        printf("PLEASE ENTER WHO PLAYS ");
        if(player==1)
            printf("FIRSTLY:\n");
        else
            printf("SECONDLY:\n");
    }
    fflush(stdin);
    get_string(username);
    if(player==2)
        while(!(strcmp(temp_username,username)))
            get_string(username);
    ///checks if file exists
    sprintf(user_file, "%s.txt", username);
    somefile = fopen(user_file,"r");
    if(somefile==NULL)
    {
        while(somefile==NULL)
        {
            printf("USERNAME DOESN'T EXIST.\nDO YOU WANT TO CREATE NEW? Y/N\n");
            temp_char=getch();
            while(temp_char!='n' && temp_char!='N' && temp_char!='y' && temp_char!='Y')
            {
                printf("PLEASE ENTER Y FOR YES OR N FOR NO\n");
                temp_char=getch();
            }
            if(temp_char=='y' || temp_char=='Y')
            {
                somefile = fopen(user_file, "w");
                fprintf(somefile,"0|0|0");
                fclose(somefile);
                break;
            }
            else
            {
                system("cls");
                if(number_of_players=='1')
                    printf("PLEASE ENTER YOUR USERNAME: \n");
                else
                {
                    printf("PLEASE ENTER WHO PLAYS ");
                    if(player==1)
                        printf("FIRSTLY:\n");
                    else
                        printf("SECONDLY:\n");
                }
                get_string(username);
                if(player==2)
                    while(!(strcmp(temp_username,username)))
                    {
                        printf("USERNAMES MUST BE DIFFERENT:\n");
                        get_string(username);
                    }
                sprintf(user_file, "%s.txt", username);
                somefile = fopen(user_file,"r");
                continue;
            }
        }
    }
    else
    {
        system("cls");
        printf("WELCOME BACK ");
        printf(username);
        printf("\n");
        fclose(somefile);
        system("pause");
    }
    return;
}
void print_statistics()
{
    FILE *user_file;
    char username[17],temp_username[20],temp_char;
    int win,draw,loss;
    system("cls");
    printf("PLEASE ENTER A USERNAME:\n");
    get_string(username);
    sprintf(temp_username,"%s.txt",username);
    user_file = fopen(temp_username,"r");
    while(user_file==NULL)
    {
        printf("USERNAME DOESN'T EXIST. \nDO YOU WANT TO ENTER A NEW USERNAME? Y/N\n");
        temp_char=getch();
        while(temp_char!='y'&&temp_char!='Y'&&temp_char!='n'&&temp_char!='N')
        {
            printf("ENTER Y FOR YES AND N FOR NO:\n");
            temp_char=getch();
        }
        if(temp_char=='y'||temp_char=='Y')
        {
            system("cls");
            printf("PLEASE ENTER A USERNAME:\n");
            get_string(username);
            user_file = fopen(username,"r");
            continue;
        }
        else
            return;
    }
    fscanf(user_file,"%d|%d|%d",&win,&draw,&loss);
    printf(username);
    printf(" HAS %d WINS, %d DRAWS AND %d LOSSES\n",win,draw,loss);
    fclose(user_file);
    system("pause");
}
int main(void)
{
    char players,first=-1,username1[17],username2[17];
    unsigned char i,j;
    int table[3][3],pic[20][26];
    ///builds tic tac toe board
    start(pic);
    do
    {
        system("cls");
        printf("1 -> PLAY AGAINST CPU\n2 -> PLAY AGAINST ANOTHER PLAYER\n3 -> VIEW STATISTICS\n4 -> QUIT\n     ");
        players=getch();
        while(players<'1' || players>'4')
        {
            printf("\nYOU MUST ENTER 1, 2, 3 OR 4: ");
            players=getch();
        }
        if(players=='4')
            return 0;
        else if(players=='3')
            print_statistics();
    }while(players=='3');
    ///accepts usernames and checks if they are already in use or not
    enter_name(1,username1,players);
    strcpy(username2,username1);
    if(players=='2')
        enter_name(2,username2,players);
    ///sets every position to 0 (0 indicates nothing, 1 for X, 2 for O and an added 3 for the square
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            table[i][j]=0;
    ///if against the cpu asks who will play first
    if(players=='1')
    {
        printf("DO YOU WANT TO PLAY FIRST? Y/N\n");
        first=getch();
        while(first!='y'&&first!='Y'&&first!='n'&&first!='N')
        {
            printf("PLEASE ENTER Y FOR YES OR N FOR NO\n");
            first=getch();
        }
    }
    system("cls");
    ///cpu plays at top left corner
    if(first=='n'||first=='N')
    {
        table[0][0]+=2;
        cpu_update(pic,table,0);
    }
    ///sets square at first position
    table[0][0]+=3;
    ///builts square and prints board
    square(pic,table,1);
    ///game starts
    wasd(pic,table,players,first,username1,username2);
}
