#include <Arduino.h>
#include <GameBoy.h>

GameBoy gb;

void setup()
{
    gb.begin(0);
    Serial.begin(9600);
}

void Car(int x, int y)
{
    gb.drawPoint(x, y);
    gb.drawPoint(x, y - 1);
    gb.drawPoint(x - 1, y - 1);
    gb.drawPoint(x + 1, y - 1);
    gb.drawPoint(x, y - 2);
    gb.drawPoint(x - 1, y - 3);
    gb.drawPoint(x + 1, y - 3);
}

void deletCar(int x, int y)
{
    gb.wipePoint(x, y);
    gb.wipePoint(x, y - 1);
    gb.wipePoint(x - 1, y - 1);
    gb.wipePoint(x + 1, y - 1);
    gb.wipePoint(x, y - 2);
    gb.wipePoint(x - 1, y - 3);
    gb.wipePoint(x + 1, y - 3);
}

void creatMyCar(int position)
{
    gb.drawPoint(position, 12);
    gb.drawPoint(position, 13);
    gb.drawPoint(position - 1, 13);
    gb.drawPoint(position + 1, 13);
    gb.drawPoint(position, 14);
    gb.drawPoint(position - 1, 15);
    gb.drawPoint(position + 1, 15);
}

void deletMyCar(int position)
{
    gb.wipePoint(position, 12);
    gb.wipePoint(position, 13);
    gb.wipePoint(position - 1, 13);
    gb.wipePoint(position + 1, 13);
    gb.wipePoint(position, 14);
    gb.wipePoint(position - 1, 15);
    gb.wipePoint(position + 1, 15);
}


void loop()
{
    // put your main code here, to run repeatedly:

    Car(4, 4);
    creatMyCar(4);
}
