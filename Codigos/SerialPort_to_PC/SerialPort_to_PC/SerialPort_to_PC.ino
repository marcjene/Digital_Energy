// Definir los pines del ADC de Arduino donde se mide el sensor de corriente
const int SensorPin = , RefPin =  ;

// Definir los datos del sensor de corriente
const int Rshunt = ;                  // Resistencia del transformador: Modelo 50 A: 20 ohms, Modelo 30 A: 33.3 ohms
double n_trafo = ;                  // Numero de vueltas entre primario y secundario

// Variables para calcular cada cuanto pasa un milisegundo
unsigned long time_now = 0;
unsigned long time_ant = 0, difTime = 0, act_time = 0;
 
// Definir variables para calcular el RMS de un ciclo de red
double suma_cuadratica_rms = ;       // En esta variable se va acumulando la suma cuadradica de las corrientes instantaneas  
const int sampleDuration = ;          // Numero de samples que determina cada cuantas muestras se hace el RMS
int contador_suma_cuadratica = ;       // Contador de cuantas veces se ha acumulado valores en la suma cuadratica
double freq = ;                       // Definir la frecuencia de la red

// Definir variables para calcular una media de la corriente
double corriente_acumulada = ;       // Acumulador de valores RMS para hacer la media
const int sampleAverage = ;          // Numero de samples que determina cada cuantas muestras se hace la media de los RMS
int contador_acumulado = ;             // Contador de cuantas veces se ha acumulado valores de RMS


//=================================================================================================================================
// Funcion SETUP: Función que se ejecuta la primera vez que arranca el código
//=================================================================================================================================
void setup() 
{
  // Inicializar el periferico del puerto serie para poder imprimir datos a una velocidad de 115200 bits por segundos
  Serial.begin(115200);
}


//=================================================================================================================================
// Funcion LOOP: Función que se ejecuta ciclicamente de manera infinita
//=================================================================================================================================
void loop()
{
    // Leer el tiempo en microsegundos desde el arranque del arduino
    act_time = micros();
    
    // Calcular la diferencia de tiempo entre el tiempo actual y la ultima vez que se actualizó la corriente instantanea
    difTime = act_time - time_ant;

    // CADA 1 MILISEGUNDO, LEER ADC Y CALCULAR LA CORRIENTE INSTANTANEA PARA CALCULAR EL RMS
    if (difTime >= ) 
    {
        // Actualizar el registro de tiempo con el tiempo actual
        
    
        // Leer del ADC las tensiones del tensor (devuelve datos entre 0 y 1023)
        
    
        // Traducir los valores del ADC a valores de tensión 
        
    
        // Calcular la diferencia de tensión en el sensor, y traducir a corriente (Corriente_primario = N_vueltas * Tension_sensor / Resistencia)
        
    
        // Acumular la corriente cuadratia en la variable que acumula el area
        
    
        // Incrementar el contador de muestras del acumulador del RMS
        
    }

    // CADA CICLO DE RED (20 VALORES ACUMULADOS = 20 ms), CALCULAR RMS DEL ULTIMO CICLO, Y EJECUTAR EL PROMEDIO
    if (contador_suma_cuadratica >= sampleDuration)
    {
        // Hacer la raiz cuadrada para calcular el RMS del último ciclo de red
        
        
        // Reiniciar valores de acumulación para calcular el RMS del último ciclo de red
        
    
        // Acumular valores de corriente RMS para calcular el promedio de RMS
        
        
        // CADA 5 segundos, hacer promedio
        if (contador_acumulado >= sampleAverage) 
        {
            // Calcular la media de la corriente RMS promediado
            double Irms_promedio = ;
            
            // Reiniciar valores de acumulación para calcular el RMS promediado

            
            // Imprimir la corriente filtrada, y la potencia
            Serial.print();
            Serial.print(";");
            Serial.print();
            Serial.println(";");
        }
    }
}