#include <Arduino.h>
#include <GameBoy.h>



GameBoy gb;

byte xPlayerCar = 4;
byte yPlayerCar = 12;



void createEnemyCar(int x, int y)
{
    gb.drawPoint(x, y);
    gb.drawPoint(x, y - 1);
    gb.drawPoint(x - 1, y - 1);
    gb.drawPoint(x + 1, y - 1);
    gb.drawPoint(x, y - 2);
    gb.drawPoint(x - 1, y - 3);
    gb.drawPoint(x + 1, y - 3);
}

void deleteEnemyCar(int x, int y)
{
    gb.wipePoint(x, y);
    gb.wipePoint(x, y - 1);
    gb.wipePoint(x - 1, y - 1);
    gb.wipePoint(x + 1, y - 1);
    gb.wipePoint(x, y - 2);
    gb.wipePoint(x - 1, y - 3);
    gb.wipePoint(x + 1, y - 3);
}

void createPlayerCar(byte xPostion, byte yPosition)
{
    gb.drawPoint(xPostion, yPosition);
    gb.drawPoint(xPostion, yPosition + 1);
    gb.drawPoint(xPostion - 1, yPosition + 1);
    gb.drawPoint(xPostion + 1, yPosition + 1);
    gb.drawPoint(xPostion, yPosition + 2);
    gb.drawPoint(xPostion - 1, yPosition + 3);
    gb.drawPoint(xPostion + 1, yPosition + 3);
}

void deletePlayerCar(byte xPosition, byte yPosition)
{
    gb.wipePoint(xPosition, yPosition);
    gb.wipePoint(xPosition, yPosition + 1);
    gb.wipePoint(xPosition - 1, yPosition + 1);
    gb.wipePoint(xPosition + 1, yPosition + 1);
    gb.wipePoint(xPosition, yPosition + 2);
    gb.wipePoint(xPosition - 1, yPosition + 3);
    gb.wipePoint(xPosition + 1, yPosition + 3);
}



void setup()
{
    gb.begin(0);
    Serial.begin(9600);

    createEnemyCar(4, 4);
    createPlayerCar(4,12);
    
}


void loop()
{
    // put your main code here, to run repeatedly:


    if (gb.getKey() == 5 && xPlayerCar < 6)
    {
        deletePlayerCar(xPlayerCar, yPlayerCar);
        createPlayerCar(++xPlayerCar, yPlayerCar);
        delay(250);
    
    }else if (gb.getKey() == 4 && xPlayerCar > 1)
    {        
        deletePlayerCar(xPlayerCar, yPlayerCar);
        createPlayerCar(--xPlayerCar, yPlayerCar);
        delay(250);
        
    }else if (gb.getKey() == 3 && yPlayerCar > 8)
    {        
        deletePlayerCar(xPlayerCar, yPlayerCar);
        createPlayerCar(xPlayerCar, --yPlayerCar);
        delay(250);
        
    }else if (gb.getKey() == 6 && yPlayerCar < 12)
    {        
        deletePlayerCar(xPlayerCar, yPlayerCar);
        createPlayerCar(xPlayerCar, ++yPlayerCar);
        delay(250);
        
    }
    
    

}
