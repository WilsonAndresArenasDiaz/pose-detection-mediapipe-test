# pose-detection-mediapipe-test
Detección de postura (de pie/sentado) con MediaPipe y control de LEDs con Arduino
![Multimedia](https://github.com/user-attachments/assets/46509bbd-f052-4119-880f-1072872a14dd)

<div align="center">
  <h1>🕺 Detección de Postura 🤸‍♂️</h1>
  <h3>MediaPipe Pose Landmarker + Arduino</h3>
  <p><i>¿De pie o sentado? Tu cámara lo sabe y controla LEDs</i></p>
  
  ![Python](https://img.shields.io/badge/Python-3.11-blue?logo=python)
  ![MediaPipe](https://img.shields.io/badge/MediaPipe-0.10.8-green?logo=google)
  ![OpenCV](https://img.shields.io/badge/OpenCV-4.9.0-red?logo=opencv)
  ![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?logo=arduino)
  ![Status](https://img.shields.io/badge/Estado-Funcionando-success)
</div>

---

## 📸 **DEMOSTRACIÓN EN VIVO**

<div align="center">
  <table>
    <tr>
      <td align="center">
        <img src="https://via.placeholder.com/400x300/FF0000/FFFFFF?text=De+Pie" width="300" alt="De pie">
        <br><b>🟥 De Pie</b>
      </td>
      <td align="center">
        <img src="https://via.placeholder.com/400x300/00FF00/FFFFFF?text=Sentado" width="300" alt="Sentado">
        <br><b>🟩 Sentado</b>
      </td>
    </tr>
  </table>
  <p><i>La etiqueta cambia de color según la postura detectada</i></p>
</div>

---

## 🎯 **DESCRIPCIÓN DEL PROYECTO**

Este proyecto utiliza **visión por computadora** para detectar en tiempo real si una persona está **de pie** o **sentada**. La postura identificada se muestra en pantalla con una etiqueta de color y, mediante comunicación serial, se envían comandos a un **Arduino** que controla LEDs:

- 🔴 **LED Rojo** → Persona de pie
- 🟢 **LED Verde** → Persona sentada
- ⚫ **Ambos apagados** → Sin persona detectada

> ⚠️ **Nota:** El código incluye un modo simulación para probar sin Arduino físico.

---

## 🏗️ **ARQUITECTURA DEL SISTEMA**

```mermaid
graph LR
    A[Cámara Web] --> B[OpenCV]
    B --> C[MediaPipe Pose Landmarker]
    C --> D[Cálculo de Ángulo]
    D --> E{¿Ángulo > 60°?}
    E -->|Sí| F[De Pie 🔴]
    E -->|No| G[Sentado 🟢]
    F --> H[Enviar 'R' por Serial]
    G --> I[Enviar 'V' por Serial]
    H --> J[Arduino]
    I --> J
    J --> K[LED Rojo 🔴]
    J --> L[LED Verde 🟢]
