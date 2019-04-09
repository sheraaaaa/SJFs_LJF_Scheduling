//Q17......
#include<stdio.h>


// creating a structure of a process
struct process {
    int processno;
    int AT;
    int BT;

    // for backup purpose to print in last
    int BTbackup;
    int WT;
    int TAT;
    int CT;
};

// creating a structe of 4 processes
struct process p[4];

// variable to find the total time
int totaltime = 0;
int prefinaltotal = 0;

// comparator function for sort()
int compare(struct process p1,struct process p2)
{
    // compare the Arrival time of two processes
    return p1.AT < p2.AT;
}

// finding the largest Arrival Time among all the available
// process at that time
int findlargest(int at)
{
    int max = 0, i;
    for (i = 0; i < 4; i++) {
        if (p[i].AT <= at) {
            if (p[i].BT > p[max].BT)
                max = i;
        }
    }

    // returning the index of the process having the largest BT
    return max;
}

// function to find the completion time of each process
int findCT()
{

    int index;
    int flag = 0;
    int i = p[0].AT;
    while (1) {
        if (i <= 4) {
            index = findlargest(i);
        }

        else
            index = findlargest(4);
        printf("Process executing at time %d is: P%d\n",totaltime,index + 1);

        p[index].BT -= 1;
        totaltime += 1;
        i++;

        if (p[index].BT == 0) {
            p[index].CT = totaltime;
            printf(" Process P%d is completed at %d\n",p[index].processno,totaltime);
        }

        // loop termination condition
        if (totaltime == prefinaltotal)
            break;
    }
}

int main()
{

    int i;

    // initializing the process number
    for (i = 0; i < 4; i++) {
        p[i].processno = i + 1;
    }

    // cout<<"arrival time of 4 processes : ";
    for (i = 0; i < 4; i++) // taking AT
    {
        p[i].AT = i + 1;
    }

    // cout<<" Burst time of 4 processes : ";
    for (i = 0; i < 4; i++) {

        // assigning {2, 4, 6, 8} as Burst Time to the processes
        // backup for displaying the output in last
        // calculating total required time for terminating
        // the function().
        p[i].BT = 2 * (i + 1);
        p[i].BTbackup = p[i].BT;
        prefinaltotal += p[i].BT;
    }

    // displaying the process before executing
    printf("PNo\tAT\tBT\n");

    for (i = 0; i < 4; i++) {
        printf("\t%d\t%d\t%d\n",p[i].processno, p[i].AT, p[i].BT);
    }
    printf("\n");

    // soritng process according to Arrival Time
    //sort(p, p + 4, compare);

    // calculating initial time when execution starts
    totaltime += p[0].AT;

    // calculating to terminate loop
    prefinaltotal += p[0].AT;
    findCT();
    int totalWT = 0;
    int totalTAT = 0;
    for (i = 0; i < 4; i++) {
        // since, TAT = CT - AT
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BTbackup;

        // finding total waiting time
        totalWT += p[i].WT;

        // finding total turn around time
        totalTAT += p[i].TAT;
    }

    printf("After execution of all processes ... \n");

    // after all process executes
    printf("PNo\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < 4; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].processno,p[i].AT,p[i].BTbackup,p[i].CT,p[i].TAT,p[i].WT);
    }
    printf("\nTotal TAT = %d\n",totalTAT);
    printf("Average TAT = %d\n",totalTAT/4);
    printf("Total WT = %d\n",totalWT);
    printf("Average WT = %d\n",totalWT / 4);
    
int n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
i=0;
int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;


printf(" -------Shortest Job First Scheduling ( NP )-------\n");
printf("\nEnter the No. of processes :");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&at[i]);
bt[i]=2*at[i];
printf("\tSo, the burst time of %d process : %d",i+1,bt[i]);
}

/*Sorting According to Arrival Time*/

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}

/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/

for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if (btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;
wsum=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}

wavg=(wsum/n);
tsum=0;
for(i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
tsum=tsum+tt[i];
}

tavg=(tsum/n);

printf("\n************************");
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
}

printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}
