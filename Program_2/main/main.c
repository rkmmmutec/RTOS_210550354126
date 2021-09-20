#include "freertos/timers.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"





void *const timer_id;
TimerHandle_t timer_handle;
void task3(void *params)
{
    timer_handle = xTimerCreate("timer",(10000 / portTICK_PERIOD_MS),pdFALSE,timer_id, callback);

    xTimerStart(my_timer_handle, 1);
    while (1)
    {
        printf("task3\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
void callback(TimerHandle_t xTimer)
{
    printf("Callback\n");
}




void task1(void *data)
{
    while(1)
    {
        printf(" task1 started \n");
        //...............//
        printf(" task1 ended \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void task2(void *data)
{
    while(1)
    {
        printf(" task2 started \n");
        //...............//
        printf(" task2 ended \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void task3(void *data)
{
    while(1)
    {
        printf(" task3 started \n");
        //...............//
        printf(" task3 ended \n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);

    }
}







void app_main(void)
{
    xTaskCreate(task1, "tone_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(task2, "ttwo_tsk", 2048, NULL, 8, NULL);
    xTaskCreate(task3, "tthree_tsk", 2048, NULL, 6, NULL);
    
   
}


