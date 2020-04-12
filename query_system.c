#include<stdio.h>

struct val
{
char process_name[10];
int arrival_time,burst_time,comp_time,turn_ar_time,wait_time;
};

void welcome();
void details();
int constraint(struct val st[],int n);
void round_robin(struct val st[],int n);
void display(struct val st[],int n);

int main()
{

printf("\t \tIMPORTANT instrustion the Queries will be only excuted within the time perid 10:00 to 24:00\n\t\t please remove the colon when writing the time,ie-11:23 ='1123'\n");
welcome();

}

void welcome()
{
char ch;
printf("\npress 'f' for faculty or 's' for student: ");
scanf("%c",&ch);

if (ch=='f')
{
printf("\nwelcome faculty: ");
details();
}
else if(ch=='s')
{
printf("\nwelcome student:");
details();
}
else
{
printf("\ninvalid input try again");
welcome();
}
}

void details()
{

int no_queries_reslove;
printf("\nenter the number of queries to be resolved : ");
scanf("%d",&no_queries_reslove);
struct val st[no_queries_reslove];

for(int i=0;i<no_queries_reslove;i++)
{
printf("\nenter the details:");
printf("\nenter the process name: ");
scanf("%s",&st[i].process_name);
printf("enter Arrival time:");
scanf("%d",&st[i].arrival_time);
printf("enter Burst time:");
scanf("%d",&st[i].burst_time);
}
constraint(st,no_queries_reslove);
}


int constraint(struct val st[],int n)
{
int a=0;
if(a==0)
{
for(int i=0;i<n;i++)
{
if(st[i].arrival_time<1000 || st[i].arrival_time>2400)
{
printf("\nsorry we dont process at this time interval, please enter the values again:");
details();
break;
}
else{a=1;}
}
}
if(a==1)
{
round_robin(st,n);
}
}


void round_robin(struct val st[], int n)
{
int quantum;
printf("\nenter the time quantum for each process: ");
scanf("%d",&quantum);

int temp_burst_t[n];
for(int i=0;i<n;i++)
{
temp_burst_t[i]=st[i].burst_time;
}
int cur_time=0;
while(1)
{ int a=1;
for(int i=0;i<n;i++)
{
if(temp_burst_t[i]>0)
{ a=0; 
if(temp_burst_t[i]>quantum)
{
temp_burst_t[i]-=quantum; 
cur_time+=quantum;
}
else
{
cur_time+=temp_burst_t[i];
st[i].wait_time=cur_time-st[i].burst_time;
temp_burst_t[i]=0;
}
}
}
if(a==1)
{break;}
}
//calculation

for(int i=0;i<n;i++)
{
st[i].turn_ar_time=st[i].wait_time+st[i].burst_time;
st[i].comp_time=st[i].wait_time+st[i].arrival_time;

}
display(st,n);
}


void display(struct val st[],int n)
{
printf("process   arrival time    burst time    completion time     turn around time     waiting time    ");
for(int i=0;i<n;i++)
{printf("\n  %s         %d             %d               %d                %d                  %d\n", st[i].process_name,st[i].arrival_time,st[i].burst_time,st[i].comp_time,st[i].turn_ar_time,st[i].wait_time);}
}

