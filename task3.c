#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100
#define DESCRIP_LENGTH 100

int numTasks=0;
int ID[MAX_TASKS];
char taskDescrip[MAX_TASKS][DESCRIP_LENGTH];

void addTask()
{
    if(numTasks>=MAX_TASKS)
    {
        printf("Task list is full\n");
        return;
    }

    printf("Enter task description: ");
    scanf(" %[^\n]",taskDescrip[numTasks]);
    ID[numTasks]=numTasks+1;
    numTasks++;
    printf("Task added successfully!\n");
}

void viewTasks()
{
    printf("Current Tasks:\n");
    for (int i=0; i<numTasks; i++)
    {
        printf("Task ID: %d\n",ID[i]);
        printf("Description: %s\n",taskDescrip[i]);
    }
}

void removeTask()
{
    int taskID;
    printf("Enter task ID to remove:");
    scanf("%d",&taskID);

    if(taskID<1 || taskID>numTasks)
    {
        printf("Invalid task ID\n");
        return;
    }
    for(int j=taskID-1; j<numTasks-1; j++)
    {
        ID[j]=ID[j+1];
        strcpy(taskDescrip[j], taskDescrip[j+1]);
    }
    numTasks--;
    printf("Task removed successfully!\n");
}

int main()
{
    int n;
    printf("Minions Task Manager\n");
    do{
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d",&n);

        switch (n)
        {
        case 1:
            addTask();
            break;
        case 2:
            viewTasks();
            break;
        case 3:
            removeTask();
            break;
        case 4:
            printf("Exiting Minions Task Manager. Have a great day!");
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
    while(n!=4);
    return 0;
}