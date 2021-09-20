/*
 *
 
   1. Create 3 realtime tasks each with the periodcity T1=1000ms, T2=2000ms, T3=5000ms.
   Also create two additional task T4 and T5 where T4 sends integer data to T5 using 
   Messsage Queues.
  
*
*
*/





#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"





// Creating task handle
xTaskHandle TaskHandle_1;
xTaskHandle TaskHandle_2;
xTaskHandle TaskHandle_3;
xTaskHandle send_handle;
xTaskHandle recieve_handle;



static void task1(void* pvParameters);
static void task2(void* pvParameters);
static void task3(void* pvParameters);
static void task_send(void* send_handle);
static void task_recieve(void* recieve_handle);



 QueueHandle_t send;


// Periodic task with periodicity of 100ms

void task1(void *TaskHandle_1) 
{                                        

   while(1)
   {

  printf("1-Periodic task created for 1000ms\n");
  vTaskDelay(1000/ portTICK_PERIOD_MS); 
   
   }

  vTaskDelete(NULL);
                                         
}

// Periodic task with periodicity of 2000ms

void task2(void *TaskHandle_2) 
{                                        

   while(1)
   {

  printf("2-Periodic task created for 2000ms\n");
  vTaskDelay(2000/ portTICK_PERIOD_MS); 
   
   }

  vTaskDelete(NULL);
                                         
}


// Periodic task with periodicity of 3000ms

void task3(void *TaskHandle_1) 
{                                        

   while(1)
   {

  printf("3-Periodic task created for 5000ms\n");
  vTaskDelay(3000/ portTICK_PERIOD_MS); 
   
   }

  vTaskDelete(NULL);
                                         
}


// Periodic task with periodicity of 3000ms
//task 4
void task_send(void *send_handle) 
{                                        

   int s = 0;
  

   while(1)
   {

  printf("Send integer\n");
  s++;

  xQueueSend(send,&s,0);

  printf("integer sent Successfully\n");
  vTaskDelay(3000/ portTICK_PERIOD_MS); 
   
   }

  vTaskDelete(NULL);
                                         
}


// Periodic task with periodicity of 3000ms
//TAsk 5
void task_recieve(void *recieve_handle) 
{     

   int buff;                                   

   while(1)
   {
 
   xQueueReceive(send,&buff,0);

   printf("---Recieving Started \n");
   printf("Recieving : Buffer = %d\n",buff);
   printf("---Recieving End\n");
 
   vTaskDelay(3000/ portTICK_PERIOD_MS); 
   
   }

  vTaskDelete(NULL);
                                         
}





void app_main(void)
{



 //Creating 3 tasks T1,T2 and T3 with peridiocity 1000,2000,5000

 xTaskCreate(task1,"( signed char * )_tsk",configMINIMAL_STACK_SIZE,NULL,20,&TaskHandle_1);
 xTaskCreate(task2,"( signed char * )_tsk",configMINIMAL_STACK_SIZE,NULL,14,&TaskHandle_2);
 xTaskCreate(task3,"( signed char * )_tsk",configMINIMAL_STACK_SIZE,NULL,10,&TaskHandle_3);  
 
//Creating two additional task T4 and T5

xTaskCreate(task_send,"_tsk",configMINIMAL_STACK_SIZE,NULL,5,&send_handle);
xTaskCreate(task_recieve,"_tsk",configMINIMAL_STACK_SIZE,NULL,2,&recieve_handle);

send = xQueueCreate(5,sizeof(int));



}
