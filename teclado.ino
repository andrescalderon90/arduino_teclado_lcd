#include <LiquidCrystal.h>
#include <Keypad.h>     // importa libreria Keypad//
const int rs=14,en=15,d4=16,d5=17,d6=18,d7=19; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[FILAS] = {5,4,3,2};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {9,8,7,6}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char TECLA;       // almacena la tecla presionada
char CLAVE[7];        // almacena en un array 6 digitos ingresados
char CLAVE_MAESTRA[7] = "123456";   // almacena en un array la contraseña maestra
byte INDICE = 0;      // indice del array
int indice=0;
void setup() {

 Serial.begin(9600);      // inicializa comunicacion serie  
 lcd.begin (16,2); // columnas 16 * 2 filas//
 lcd.setCursor(0,0);
 lcd.print("hola mundo");
 delay(1000);
}

void loop() {
   
  
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (TECLA)        // comprueba que se haya presionado una tecla
  {
   
    lcd.setCursor(indice,1);
    lcd.print(TECLA);
    delay(1000);
    indice++;
    
    
    
  }

 
}
