/**
 * @file   aufgabe1-bit.c
 * @brief  Aufgabe1 - Bit Manipulationen 
 */

#include <stdio.h>
// Falls notwendig erweitern Sie die Liste der includes


/**
   @brief Aufgabe1a: Vertauschen von Bytes
   @param [in] short int i
   @return short int

Schreiben Sie eine Funktion die das Low Byte (Bits 0-7) und 
das High Byte (Bits 8-15) vertauscht.
Z.B. aus der Zahl 0x4020 wird die Zahl 0x2040.
*/
short int switchLowHighByte(short int i) {

    
    short int cLow, cHigh;
    
    cLow = i << 8;
    cHigh = i >> 8;
    
    i = cLow | cHigh;
    
    printf("Die getauschte Zahl ist %x", i);
    
    
    getchar();
    return 0;
    

}


typedef enum {
  Stop = 0,
  Start = 1,
  Finish = 5,
  Fail = 255
} Status;


typedef enum {
  One = 1,
  Fifteen = 15,
  Last = 255
} Numbers;

/**
   @brief Aufgabe1b: Serialisierung von Datenstrukturen
   @param [in] Status s
   @param [in] Numbers n
   @param [out] short int* data  

Gegeben sind zwei enums. Ihre Aufgabe ist es jeweils Werte der 
beiden enums in ein Datenpacket der Groesse 16Bit zu packen (serialisieren).
Werte des enums Status sollen dabei in das Low Byte und Werte
des enums Numbers sollen in das High Byte gepackt werden.
*/


void serialize(Status s, Numbers n, short int* data) {
    short int number = n << 8;
    number = number | s;
    *data = number;
}

/**
   @brief Aufgabe1c: Deserialisierung von Datenstrukturen
   @param [in] short int data
   @param [out] Status* s
   @param [out] Numbers* n

Schreiben Sie eine Funktion die Werte der enums Status und Number
aus einem 16Bit Wert entpackt (deserialisiert).
Wir nehmen an, dass die enum Werte mittels der serialize Funktion
verpackt wurden.
*/

void deserialize(short int data, Status* s, Numbers* n) {
    Status stat = data >> 8;
}


int main() {
    short int i, komplett;
    
    //Eingabe Zahl,
    printf("Hex Zahl:");
    scanf("%hx", &i);
    switchLowHighByte(i);
    
    serialize(Start, Fifteen, &komplett);
    printf("\n Serialize %x \n", komplett);
    
    getchar();
    return 0;
}
