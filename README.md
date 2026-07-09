# Smart_Irrigation_System
# 🌱 Smart Irrigation System

An Arduino-based automated irrigation system that waters plants only when required, using a **soil moisture sensor** and **relay-controlled water pump**. This project promotes **water conservation**, **energy efficiency**, and **sustainable agriculture**.

---

## 📖 Project Overview
Manual irrigation often leads to overwatering or underwatering. The Smart Irrigation System solves this by continuously monitoring soil moisture and automatically controlling a water pump. It ensures plants receive the right amount of water, reducing waste and improving crop health.

---

## 🎯 Objectives
- Automate irrigation using soil moisture sensing  
- Prevent over-irrigation and under-irrigation  
- Save water and electricity  
- Provide a low-cost, reliable solution for farms and gardens  
- Support sustainable agriculture and smart city initiatives  

---

## 🔧 Components Required
- Arduino Uno R3 (Type-C)  
- Soil Moisture Sensor (Digital Output)  
- Relay Module (5V)  
- DC Motor / Water Pump (5V/12V)  
- Jumper wires & Breadboard  
- External Power Supply (for motor if needed)  
- Plant pot, cardboard, hot glue gun, screwdriver  

---

## ⚙️ Working Principle
1. **Soil Moisture Sensor** detects water content in soil.  
   - Dry soil → HIGH output  
   - Wet soil → LOW output  
2. **Arduino Uno** reads sensor data and compares with threshold.  
3. **Relay Module** acts as a switch to control the pump.  
   - Dry soil → Relay ON → Pump waters plants  
   - Wet soil → Relay OFF → Pump stops  
4. System repeats automatically, forming a closed-loop control.  

---

## 🛠️ Pin Connections
- Soil Moisture Sensor → Pin 7 (Digital Input)  
- Relay Module → Pin 6 (Control Signal)  
- Pump connected via Relay COM & NO terminals  

---

Soil Moisture Sensor → Arduino Uno → Relay Module → Water Pump → Plant
