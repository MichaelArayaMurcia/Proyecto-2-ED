#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>


class Jugador {
private:
	float posX;
	float posY;

public:
	Jugador() {
		posX = 0;
		posY = 0;
	}

	~Jugador() {
	
	}

	float getposX() {
		return posX;
	}

	float getposY() {
		return posY;
	}

	void setposX(float posX1) {
		posX = posX1;
	}

	void setposY(float posY1) {
		posY = posY1;
	}
};
#endif