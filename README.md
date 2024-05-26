# Robot controlat prin gesturi

- Nume: Vărzaru Vlad-Ionuț 
- Grupa: 331CD
  
Mediu de dezvoltare:

- Arduino IDE

Librării și surse 3rd-party:

- Wire.h: Utilizată pentru comunicarea I2C.
- I2Cdev.h: Utilizată pentru comunicația cu MPU6050.
- MPU6050.h: Biblioteca principală pentru MPU6050.
- SoftwareSerial.h: Utilizată pentru comunicarea serială prin Bluetooth.
- 
Citirea și maparea Datelor:

- Datele de la MPU6050 sunt citite în variabilele ax, ay, az, gx, gy, gz.
- Valorile axiale (ax și ay) sunt mapate la intervalele dorite pentru a fi transmise eficient.

Transmiterea si receptia datelor prin Bluetooth:

- Datele mapate sunt convertite într-un format de tip string și trimise prin Bluetooth folosind SoftwareSerial.
- La recepție, stringul este citit și împărțit în valorile componente folosind funcții de manipulare a stringurilor.

Controlul motorului pe baza datelor receptionate:

- Valorile pentru axele X și Y sunt utilizate pentru a decide direcția de miscare a robotului controlat de cele doua motoare.
- Controlul vitezei și directiei motoarelor este realizat prin modificarea semnalelor PWM și a pinilor de control.
