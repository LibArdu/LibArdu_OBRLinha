#include <LibArdu_OBRLinha.h>

// Defina os pinos dos sensores e motores
int pinoSensorEsq = 2;
int pinoSensorDir = 3;
int pinoMotorEsq = 9;
int pinoMotorDir = 10;

LibArdu_OBRLinha linhaControl(pinoSensorEsq, pinoSensorDir, pinoMotorEsq, pinoMotorDir);

void setup() {
    Serial.begin(9600);
    linhaControl.iniciar();
    linhaControl.definirVelocidadesMotores(200, 200); // Defina a velocidade inicial dos motores
}

void loop() {
    linhaControl.seguirLinha();
    delay(100);
}
