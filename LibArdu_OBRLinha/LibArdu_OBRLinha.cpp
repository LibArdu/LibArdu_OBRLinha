#include "LibArdu_OBRLinha.h"

LibArdu_OBRLinha::LibArdu_OBRLinha(int pinoSensorEsq, int pinoSensorDir, int pinoMotorEsq, int pinoMotorDir) {
    _pinoSensorEsq = pinoSensorEsq;
    _pinoSensorDir = pinoSensorDir;
    _pinoMotorEsq = pinoMotorEsq;
    _pinoMotorDir = pinoMotorDir;
    _velocidadeEsq = 255;  // Velocidade padrão
    _velocidadeDir = 255;  // Velocidade padrão
}

void LibArdu_OBRLinha::iniciar() {
    pinMode(_pinoSensorEsq, INPUT);
    pinMode(_pinoSensorDir, INPUT);
    pinMode(_pinoMotorEsq, OUTPUT);
    pinMode(_pinoMotorDir, OUTPUT);
}

void LibArdu_OBRLinha::seguirLinha() {
    int valorSensorEsq = digitalRead(_pinoSensorEsq);
    int valorSensorDir = digitalRead(_pinoSensorDir);

    if (valorSensorEsq == LOW && valorSensorDir == LOW) {
        // Ambos os sensores na linha, seguir em frente
        atualizarVelocidadesMotores(_velocidadeEsq, _velocidadeDir);
    } else if (valorSensorEsq == LOW && valorSensorDir == HIGH) {
        // Sensor esquerdo na linha, sensor direito fora da linha, virar à direita
        atualizarVelocidadesMotores(_velocidadeEsq / 2, _velocidadeDir);
    } else if (valorSensorEsq == HIGH && valorSensorDir == LOW) {
        // Sensor esquerdo fora da linha, sensor direito na linha, virar à esquerda
        atualizarVelocidadesMotores(_velocidadeEsq, _velocidadeDir / 2);
    } else {
        // Ambos os sensores fora da linha, parar
        atualizarVelocidadesMotores(0, 0);
    }
}

void LibArdu_OBRLinha::virarEsquerda() {
    atualizarVelocidadesMotores(0, _velocidadeDir);
    delay(500); // Ajuste o delay conforme necessário
}

void LibArdu_OBRLinha::virarDireita() {
    atualizarVelocidadesMotores(_velocidadeEsq, 0);
    delay(500); // Ajuste o delay conforme necessário
}

void LibArdu_OBRLinha::definirVelocidadesMotores(int velocidadeEsq, int velocidadeDir) {
    _velocidadeEsq = velocidadeEsq;
    _velocidadeDir = velocidadeDir;
}

void LibArdu_OBRLinha::atualizarVelocidadesMotores(int velocidadeEsq, int velocidadeDir) {
    analogWrite(_pinoMotorEsq, velocidadeEsq);
    analogWrite(_pinoMotorDir, velocidadeDir);
}
