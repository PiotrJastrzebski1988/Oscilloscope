#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"

#include "stm32f4_discovery.h"

#define BIT	( 1 << 2 )	//example of flag
/*
 * TODO:
 * 1. integracja z kontrola wersji: GITHUB, + dodanie plikow (doki etc) na dysk googla
 * 2. wiedza: USB
 * 3. wiedza: freeRTOS
 * 4. debug via USART
 * 5. wiedza: Java USB
 * 6. wiedza: Java FX
 * 7. wiedza: CooCox - jak dodac biblioteke
 * 8. czemu ten timing jest z dupy? (100ms - a togluje z czestotliwoscia ~1s czyli 10 razy wolniej)
 *
 * */


void createTask1();
void vLEDTaskCode1(void * pvParameters);

void vApplicationMallocFailedHook (void);
void vApplicationStackOverflowHook (TaskHandle_t xTask, char * pcTaskName);
void HardFault_Handler (void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void freeRTOSAssert(const char* file, uint32_t line);

EventGroupHandle_t xEventGroup;

int main(void) {
	STM_EVAL_LEDInit(LED4);
	createTask1();

	vTaskStartScheduler();
	while (1);
}

/*TASK 1*/
void createTask1() {
	portBASE_TYPE status;
	TaskHandle_t xHandle = NULL;
	status = xTaskCreate( vLEDTaskCode1, "Task 1", configMINIMAL_STACK_SIZE , NULL, 2,	&xHandle);
	MY_ASSERT(status == pdTRUE);
}
void vLEDTaskCode1(void * pvParameters) {
	const TickType_t xDelay2 = 1000 / portTICK_PERIOD_MS;

	for (;;) {
		STM_EVAL_LEDToggle(LED4);
		vTaskDelay( xDelay2 );
	}
}

void vApplicationIdleHook(void) {
	for(;;){}
}
void vApplicationMallocFailedHook (void) {
	for(;;){}
}
void vApplicationStackOverflowHook (TaskHandle_t xTask, char * pcTaskName){
	for(;;){}
}
void HardFault_Handler (void){
	for(;;){}
}
void MemManage_Handler(void){
	for(;;){}
}
void BusFault_Handler(void){
	for(;;){}
}
void UsageFault_Handler(void){
	for(;;){}
}
void freeRTOSAssert(const char* file, uint32_t line) {
	for(;;){}
}
