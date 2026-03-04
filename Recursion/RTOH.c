#include<stdio.h>
int move=0;
void TOH(int n, int src, int dst, int temp)
{
    if(n==1){
    printf("Move disc %d from %d to %d\n", n, src, dst);
    move++;}
    else{
        TOH(n-1, src, temp, dst);
        move++;
        printf("Move disc %d from %d to %d\n", n, src, dst);
        TOH(n-1, temp, dst, src);

    }
}
int main()
{
    int n;
    printf("Enter the no. of disc");
    scanf("%d",&n);
    printf("The sequence of moves are:\n");
    TOH(n, 1, 3, 2);
    printf("Total no. of moves= %d\n", move);
    return 0;

}