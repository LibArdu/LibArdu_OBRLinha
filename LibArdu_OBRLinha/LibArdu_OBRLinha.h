#ifndef LibArdu_OBRLinha_h
#define LibArdu_OBRLinha_h

#include <Arduino.h>

class LibArdu_OBRLinha {
public:
    LibArdu_OBRLinha(int pinoSensorEsq, int pinoSensorDir, int pinoMotorEsq, int pinoMotorDir);
    void iniciar();
    void seguirLinha();
    void virarEsquerda();
    void virarDireita();
    void definirVelocidadesMotores(int velocidadeEsq, int velocidadeDir);  // Método para definir a velocidade dos motores

private:
    int _pinoSensorEsq;
    int _pinoSensorDir;
    int _pinoMotorEsq;
    int _pinoMotorDir;

    int _velocidadeEsq;  // Velocidade atual do motor esquerdo
    int _velocidadeDir;  // Velocidade atual do motor direito

    void atualizarVelocidadesMotores(int velocidadeEsq, int velocidadeDir);
};

#endif
