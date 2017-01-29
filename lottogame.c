/* A program to simulate a Lotto Game

    Author: Fatema Bader 
    Borland 
    Windows
    Date:26/02/16*/
#include <stdio.h>
#include <stdlib.h>
#define NUMS 6
#define SIZE 42

// function prototypes
void fxn1(int *,int*,int*);
void fxn2(int *);
void fxn3(int *);
void fxn4(int*);
void fxn5(int*,int*);
void exit();
main()
{
    int nums[NUMS];
    int option=0;
    int end=1;
    int static compare[SIZE]; 
    int static count[SIZE];
    int played=0,not_played=1,played2=0,played3=0,played4=0;
    

    //Loop for the menu to keep displaying
    do
    {
        //display menu
        printf("\n1.  Enter 6 numbers\n"); 
        printf("2.  Display the numbers\n");
        printf("3.  Sort the numbers\n");
        printf("4.  Compare your chosen lotto numbers with the winning numbers\n");
        printf("5.  Press 5 to display the frequency of the numbers entered\n");
        printf("6.  Press 6 to exit\n");
            
            printf("\nChoose an option from menu:\n");
            scanf("%d",&option); //choose option
            flushall();
                switch(option)
                {
                    
                    case 1: {
                                fxn1(nums,compare,count);
                                //To indicate that user has chosen numbers
                                played=1;
                                played2=1;
                                played3=1;
                                played4=1;
                                not_played=0;
                                break; //breaks out of switch case
                            }
                    case 2: { 
                                if(played==1)
                                {
                                    fxn2(nums);
                                    
                                }
                                if(not_played==1 ) //error check
                                {
                                    printf("sorry choose option 1 first\n");
                                }
                                break;
                            }
                    case 3: {   
                                while( played2==1)
                                {
                                    fxn3(nums);
                                    played2=0;
                                }
                                if(not_played==1 )
                                {
                                    printf("sorry choose option 1 first\n");
                                }
                                break;
                            }
                    case 4: {
                                while( played3==1)
                                {
                                    fxn4(nums);
                                    played3=0;
                                }
                                if(not_played==1 )
                                {
                                    printf("sorry choose option 1 first\n");
                                }
                                break;
                            }
                    case 5: { 
                                while( played4==1)
                                {
                                    fxn5(nums,count);
                                    played4=0;
                                }
                                if(not_played==1 )
                                {
                                    printf("sorry choose option 1 first\n");
                                }
                                break;
                            }
                    case 6: {
                                exit();
                            }
                    default: printf("\nInvalid Input. Try Again\n");
                } //end switch
    } //end while
    while ( end!=0 );
} //end main()
//implementing fxn1
void fxn1(int *numbers, int *compare, int *count)
{
    int i,j,input,num=1;
    printf("Enter your numbers\n");
        for(i=0;i<NUMS;i++) //Loop1
        {            
            scanf("%d",&input);
            flushall();
                //j is a position in Loop2 and compares each position in Loop 1
                for(j=0;j<(i+1);j++) //continuous statement is always comparing j so long as i is in the position greater
                {
                    while( (input == *(numbers+j)) || (input<1 || input>42) ) 
                    {
                        printf("Error. Please choose a different number between 1-42\n");
                        scanf("%d",&input); //rewrite another number
                        flushall();
                    }
                    
                }
                *(numbers+i)=input;
        }
    
    //assigns values 1-42 to compare array
    for(i=0;i<SIZE;i++)
    {
        *(compare+i)=num;
        num++;
    }
    //test each inputted number
    for(i=0;i<NUMS;i++)
    {
        //compare it against the compare array containing number 1-42
       for(j=0;j<SIZE;j++)
       {
           if( *(numbers+i)==*(compare+j) )
            {
                *(count+j) +=1;
            }
       }//end inner for
    }//end outter for
}
//implementing fxn2
void fxn2(int *display)
{
    //displaying numbers
    int i;
    printf("Your numbers:\n");
    for(i=0 ; i<NUMS ; i++)
    {
        printf("%d\n", *(display+i) );
    }
}
//implementing fxn3
void fxn3(int *sort)
{
    int i;
    int j;
    int temp;

    for(i=0;i<NUMS;i++)
    {
        for(j=i;j<NUMS;j++)
        {
            if(*(sort+i) > *(sort+j))
            {//swap
                temp=*(sort+i);
                *(sort+i)=*(sort+j);
                *(sort+j)=temp;
            }
        }
    }
    printf("Sorted numbers:\n");
    for(i=0;i<NUMS;i++)
    {
        printf("%d\n",*(sort+i) );
    }
}
//implementing fxn4
void fxn4(int *my)
{
    int winning[NUMS]={1,3,5,7,9,11};
    int i,j,match=0,num7=42,bonus=0;
    
    //compare users numbers to winning numbers
    for(i=0;i<NUMS;i++)
    {
        for(j=0;j<NUMS;j++)
        {
            if(*(my+i) == *(winning+j))
            {//increment matches
                match++;
            }
        }
        if(*(my+i) == num7)
        {//increment bonus
            bonus++;
        }
    }
    printf("\n%d matches and %d bonus\n",match,bonus);
    //check if any number matches the bonus number i.e num7
        
        if (match>2 && bonus>-1)
        {
            if ( (match==6 && bonus==0) || (match==6  && bonus==1) )
            {
                printf("\nJackpot\n");
            }
            if (match==5 && bonus==1)
            {
                printf("\nNew car\n");
            }
            if(match==5 && bonus==0)
            {
                printf("\nHoliday\n");
            }
            if (match==4 && bonus==1)
            {
                printf("\nWeekend away\n");
            }
            if (match==4 && bonus==0)
            {
                printf("\nNight out\n");
            }
            if (match==3 && bonus==1)
            {
                printf("\nCinema ticket\n");
            }
            if (match==3 && bonus==0)
            {
                printf("\nSorry! You have not won anything!\n");
            }
        }
        else
        {
            printf("\nSorry! You have not won anything!\n");
        }
        
    return;
}
//implementing fxn5
void fxn5(int *numbers, int *count )
{
    int i,n;
    for(i=0;i<NUMS;i++)
    {
        n=*(numbers+i); //n is index
        n=n-1; //position in count array will be n-1  ex. number 24 is in position 23
        //display frequency
        printf("number %d\t\tfrequency %d\n",*(numbers+i),*(count+n)); 
    }
    
}

void exit()
{
    exit(0);
}