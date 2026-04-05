#include "main.h"
#include <string.h>
#include <stdio.h>

#define ADC_BUFFER_SIZE 10
#define THRESHOLD 3000

uint16_t adc_buffer[ADC_BUFFER_SIZE];
uint16_t adc_average = 0;
char uart_msg[50];

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

uint16_t calculate_average(uint16_t *buffer)
{
  uint32_t sum = 0;

  for (int i = 0; i < ADC_BUFFER_SIZE; i++)
  {
    sum += buffer[i];
  }

  return sum / ADC_BUFFER_SIZE;
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();

  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buffer, ADC_BUFFER_SIZE);

  while (1)
  {
    adc_average = calculate_average(adc_buffer);

    if (adc_average > THRESHOLD)
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);

      sprintf(uart_msg, "WARNING: High Voltage!\r\n");
      HAL_UART_Transmit(&huart2, (uint8_t*)uart_msg, strlen(uart_msg), 100);
    }
    else
    {
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
    }

    sprintf(uart_msg, "Average ADC Value: %d\r\n", adc_average);
    HAL_UART_Transmit(&huart2, (uint8_t*)uart_msg, strlen(uart_msg), 100);

    HAL_Delay(1000);
  }
}
