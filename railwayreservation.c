
#include <stdio.h>
#include <string.h>
#include <time.h>
char username[] = "dolly1";
int rpin = 1234, age[6], seat, cost, tdistance;
char bstation[15], DStation[15], pdetail[6][20], gender[6][10], sbirth[6][4], c[1];

int idverify()
{
    printf("\nEnter the username :\n");
    char userid[10];
    scanf("%s",&userid);
    int upin;
    printf("Enter the password : ");
    scanf("%d",&upin);
    return (rpin != upin && strcmp(username, userid)) ? 1 : 0;
}
void stime()
{
    // Getting the current time
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);

    // Printing the current date and time
    printf("Current Date and Time: %02d/%02d/%04d %02d:%02d:%02d\n",
           localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900,
           localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}

void traininfo()
{
    printf("THE PNR NO. %d\n", rand());
    printf("--------------------------------------------------------------------------------------------------------");
    printf("\nS.No.\tTrain number and Name\t\t\tDestinations   \t\t\t\tTime \t\tDistance\n");
    printf("--------------------------------------------------------------------------------------------------------");
    // printf("\n1\t14008 - Sadhbhavna Express         \tAnand Vihar TRM to Raxaul JN   \t\t16:30  AM     \t957 KM");
    printf("\n%-5d %-40s %-40s %-8s %-10d\n", 1, "14008 - Sadhbhavna Express", "Anand Vihar TRM to Raxaul JN", "16:30 AM", 957);
    printf("\n2\t15204 - LUCKNOW JN                 \tLucknow JN  To Barauni JN      \t\t15:15  AM     \t674 KM");
    printf("\n3\t12532 - Intercity Express          \tLucknow Jn  To Gorakhpur       \t\t16:05  AM     \t276 KM");
    printf("\n4\t12354 - LKU HWH SF EXP             \t Lucknow JN To Howrah JN       \t\t13:20  AM     \t967 KM");
    printf("\n5\t15070 - ASH GKP Express            \t Lucknow Jn  To Gorakhpur      \t\t16:30  AM     \t276 KM");
    printf("\n");
    printf("\n   PRESS 'ENTER' KEY TO CONTINUE ");
    getchar();
}
int distance(char bstation[], char DStation[])
{
    if (strcmp(bstation, "Anand_Vihar") == 0 && strcmp(DStation, "Raxaul") == 0)
        return 957;
    else if (strcmp(bstation, "Lucknow") == 0 && strcmp(DStation, "Barauni") == 0)
        return 674;
    else if (strcmp(bstation, "Lucknow") == 0 && strcmp(DStation, "Gorakhpur") == 0)
        return 276;
    else if (strcmp(bstation, "Lucknow") == 0 && strcmp(DStation, "Howrah") == 0)
        return 967;
    else
    {
        printf("\nWrong station");
        return 0;
    }
}
int seatcost(int schoice, int seat, int tdistance)
{
    if (schoice == 0)

        return cost = (0.48 * seat * tdistance);

    else if (schoice == 1)

        return cost = (0.688 * seat * tdistance);

    else if (schoice == 2)

        return cost = (1.648 * seat * tdistance);

    else if (schoice == 3)

        return cost = (2.572 * seat * tdistance);

    else if (schoice == 4)

        return cost = (4.257 * seat * tdistance);
}
int bookticket(int randomNum)
{

    if (idverify() == 0)
    {
        printf("\nEnter boarding station: ");
        scanf(" %s", &bstation);
        printf("\nEnter destination station  : ");
        scanf("%s", &DStation);
        printf("\nEnter the no. of persons(seat) to book ( **should be minimum than 6) :");
        scanf("%d", &seat);
        for (int i = 0; i < seat; i++)
        {
            printf("\nEnter passenger name : ");
            scanf(" %s",&pdetail[i]);
            printf("\nEnter passenger age : ");
            scanf("%d",&age[i]);
            printf("\nEnter gender : ");
            scanf("%s",&gender[i]);
            printf("\nEnter seat birth \n 1.LB(LOWER BIRTH)\t2.UB(UPPER BIRTH)\t3.MB(MIDDLE BIRTH)\t4.SUB(SIDE UPPER BIRTH)\t5.SLB(SIDE LOWER BIRTH)\n");
            scanf("%s",&sbirth);
        }

        printf("Please choose seat\n \t0.General(2S)\t1.sleeper(S) \t 2.3AC\t3.2AC\t4.1AC\n");
        int schoice;
        printf("\nEnter your choice seat ");
        scanf("%d",&schoice);
        tdistance = distance(bstation, DStation);
        printf("\nThe total distance : %d", tdistance);
        printf("\n The  cost according to seat : ");
        printf("%d", seatcost(schoice, seat, tdistance));
        printf("\nAre you want continue ? press(Y/N) ");
        scanf("%s",&c);
        if (c[0] != 'y' && c[0] != 'Y')
        {
            printf("PNR number :%d \n", randomNum);

            mybooking(randomNum);
        }
    }
}

int mybooking(int randomNum)
{
    stime();
    printf("\n\t boarding station \t\t destination station\t\tseat birth\t\t\n ");
    printf("\t\t %s \t\t\t%s\t\t %s\n", bstation, DStation, sbirth);
    printf("\n\t Passenger Name  \t\tPassenger Age\t\t\n ");
    printf("\t\t%s\t\t\t%d", pdetail, age);
}
void cancelticket(int randomNum)
{
    int PNRNo;
    int seatCancel;
    traininfo(randomNum);
aa:
    printf("\nENTER YOUR PNR NUMBER : ");
    scanf("%d", &PNRNo);
    if (PNRNo != randomNum)
    {
        printf("\nPNR NUMBER IS IT CORRECT ? %d \nENTER (Y/N) : ", PNRNo);
        scanf("%s", &c);
        if (c[0] != 'y' && c[0] != 'Y')
        {
            printf("Enter the no.of seat to  cancel:");
            printf("\n HOW MANY SEATS DO WANT TO CANCEL : ");
            scanf("%d", &seatCancel);
            for (int i = 0; i < seatCancel; i++)
            {
                printf("   \nENTER THE PASSENGER NAME: ");
                scanf("%s",&pdetail);
            }
            printf("\n\nYOUR RESERVATION HAS BEEN CANCEL !!\n\n");
            printf("\n  PRESS 'ENTER' KEY TO CONTINUE \n");
            getchar();
        }

        else if (c[2] == 'n' && c[2] == 'N')
        {
            printf("\nYOUR RESERVATION CANCELATION HAS BEEN DENIED\n");
        }
    }
    else
    {
        printf("\nNOT FOUND!! ENTER THE CORRECT PNR NUMBER\n");
        goto aa;
    }
}

void main()
{
    srand(time(0));
    int randomNum = time(0);
    printf("\n\n=========================================================================================\n");
    printf("\n\t\t\tWELCOME TO ONLINE TRAIN RESERVATION");
    printf("\n\n=========================================================================================\n\n");
    printf("1. Book Ticket \n");
    printf("2. My Booking \n");
    printf("3. Cancel Ticket \n");
    int choice;
    printf("Enter your choice \n");
    scanf("%d",&choice);
        if (choice == 1)
        {
            traininfo();
            bookticket(randomNum);
        }
        else if (choice == 2)
        {
            mybooking(randomNum);
        }
        else if (choice == 3)
        {
            cancelticket(randomNum);
        }
        else if(choice<1 || choice>3){
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
            return;
        }
    printf("\n\n=======================================================================================\n\n");
    printf("THANK YOU FOR USING THIS TRAIN RESERVATION SYSTEM");
    printf("\n\nPRESS ANY KEY TO EXIT THE END PROGRAM !! \n");
    printf("\n\n");
    getchar();
}

