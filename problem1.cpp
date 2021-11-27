#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#define num 20
using namespace std;

//Global variables
float sum =0;
float avg;  //average of array 
int min;    // minimum element
int max;    // maximum element 
int size;   // size of array 
//Function to calculate average of given array
void *avg_fun(void* arg){
    int *arr = (int*)arg;
    for(int i=0;i<size;i++){
        sum += *(arr+i);
        
    }
    avg = sum/size;
    pthread_exit(0);
}
//function to find minimum of array
void *min_fun(void *arg)
{
    int *arr = (int *)arg;
    min = *arr;
    for(int i=0;i<size;i++){

        if(*(arr+i)<min)
        min = *(arr+i);
    }
     pthread_exit(0);
}
// function to find maximum of array
void *max_fun(void *arg)
{
    int *arr = (int *)arg;
    max = *arr;
    for (int i = 0; i < size; i++)
    {

        if (*(arr + i) > max)
            max = *(arr + i);
    }
     pthread_exit(0);
}



int main(){

    int arr[num] = {NULL}; //initialize all elements of array to null
    printf("Enter size of array\t"); 
    scanf("%d",&size);      // take input of size from user
    for(int i =0 ;i<size;i++){
        scanf("%d",arr+i);
    }

    //Display the array elements
    printf("Array---> "); 
    for(int i=0;i<size;i++){
        printf("%d ",*(arr+i));
    }
    //create diffrernt threads for each function 
    pthread_t tid_1, tid_2, tid_3;

    //passing the global variables into respective threads
    pthread_create(&tid_1,NULL, avg_fun, &arr);
    pthread_create(&tid_2, NULL, min_fun, &arr);
    pthread_create(&tid_3, NULL, max_fun, &arr);

    //join all the threads 
    pthread_join(tid_1,NULL);
    pthread_join(tid_2, NULL);
    pthread_join(tid_3, NULL);
    //printing the obtained values
    printf("\naverage = %f\nminimun = %d\n maximum = %d",avg,min,max);
    return 0;    
}
