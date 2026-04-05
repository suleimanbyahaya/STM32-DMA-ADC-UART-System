# STM32-DMA-ADC-UART-System
DMA-based ADC data acquisition and UART telemetry system using STM32F4 and HAL.
# STM32 DMA-Based ADC and UART Telemetry System

This project demonstrates a DMA-based ADC data acquisition system with UART telemetry using an STM32F4 microcontroller and HAL library.

## 📌 Project Overview

The system continuously samples an analog signal using ADC with DMA at approximately 100 samples per second. A simple software filter calculates the average of the last 10 samples to reduce noise.

If the average value exceeds a defined threshold, a warning message is sent via UART and an LED is turned on. The system also transmits the current average value every 1 second.

---

## ⚙️ Features

- ADC data acquisition using DMA
- Circular buffer for continuous sampling
- Software filtering (moving average)
- Threshold-based decision system
- UART communication for telemetry output

---

## 🧰 Hardware Used

- STM32F4 Development Board
- Potentiometer (Analog Input - PA0)
- LED (PA5)
- 220Ω Resistor

---

## 🔌 System Description

- ADC samples analog signal via PA0
- DMA transfers data into memory buffer
- Average of 10 samples is calculated
- If threshold exceeded:
  - LED turns ON
  - Warning message sent via UART
- UART prints average value every 1 second

---

## 💻 Software Used

- STM32CubeIDE
- HAL (Hardware Abstraction Layer)

---

## 📁 Project Structure

---

## 🔁 System Operation

1. ADC continuously samples input signal  
2. DMA stores samples in buffer  
3. Average of last 10 samples is calculated  
4. System checks threshold condition  
5. LED and UART respond accordingly  
6. Data is transmitted every 1 second  

---

## 📊 Example Output

Average ADC Value: 1200  
Average ADC Value: 1500  
Average ADC Value: 3200  
WARNING: High Voltage!  

---

## 📌 Conclusion

This project demonstrates how DMA improves efficiency in embedded systems by offloading data transfer from the CPU. It also shows how simple filtering and UART communication can be combined to create a real-time monitoring system.
