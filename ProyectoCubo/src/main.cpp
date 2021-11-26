#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <SPI.h>

static const uint8_t BUILTIN_LED = 2;
const int GPIO_PIN_NUMBER_1 = 1;
const int GPIO_PIN_NUMBER_2 = 2;
const int GPIO_PIN_NUMBER_4 = 4;
const int GPIO_PIN_NUMBER_5 = 5;
const int GPIO_PIN_NUMBER_12 = 12;
const int GPIO_PIN_NUMBER_13 = 13;
const int GPIO_PIN_NUMBER_14 = 14;
const int GPIO_PIN_NUMBER_15 = 15;
const int GPIO_PIN_NUMBER_18 = 18;
const int GPIO_PIN_NUMBER_19 = 19;
const int GPIO_PIN_NUMBER_21 = 21;
const int GPIO_PIN_NUMBER_22 = 22;
const int GPIO_PIN_NUMBER_23 = 23;
const int GPIO_PIN_NUMBER_25 = 25;
const int GPIO_PIN_NUMBER_26 = 26;
const int GPIO_PIN_NUMBER_27 = 27;
const int GPIO_PIN_NUMBER_32 = 32;
const int GPIO_PIN_NUMBER_33 = 33;
const int GPIO_PIN_NUMBER_34 = 34;
const int GPIO_PIN_NUMBER_35 = 35;


// const char* ssid = "CONFECCIONES LUMA";
// const char* password = "eEnqN8gjGL";

const char* ssid = "Totalplay-9C9F";
const char* password = "9C9F890ENG942buF";

const char *mqtt_server = "hairdresser.cloudmqtt.com";
const int mqtt_port = 15476;
const char *mqtt_user = "qudxvewe";
const char *mqtt_pass = "W2V2LvCJ715s";

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[50];
int value = 0;
long espera = 0;

// FUNCIONES CREADAS:
// void setup_wifi();
// void callback();
// void reconnect();

// E S T A B L E C E R    W I F I
void setup_wifi() {

  Serial.println("");
  Serial.print("Conectando a -> ");
  Serial.println(ssid);

  // Nos conectamos a la red wifi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conexion Exitosa!");
  Serial.print("Mi IP  es ->");
  Serial.println(WiFi.localIP());

}

// H A C E R    L A   C A L L B A C K
// Topico, se refiere al tema sobre el cual viene suscrita la informacion
// Payload, la información enviada bajo el tópico del punto 1
// Lenght, se refiere al tamaño del dato
// Con esta funcion imprimimos el topico y con un ciclo imprimimos el payload
// NOTA: El callback funciona como una interrupcion
void callback(char* topic, byte* payload, unsigned int lenght){
  Serial.print("Mensaje recibido bajo el topico -> ");
  Serial.print(topic);
  Serial.print("\n");

  for(int i = 0; i < lenght; i++){
    Serial.print((char)payload[i]);
  }

  if((char)payload[0] == '0') {
    digitalWrite(GPIO_PIN_NUMBER_1, LOW);
    digitalWrite(GPIO_PIN_NUMBER_2, LOW);
    digitalWrite(GPIO_PIN_NUMBER_4, LOW);
    digitalWrite(GPIO_PIN_NUMBER_5, LOW);
    digitalWrite(GPIO_PIN_NUMBER_12, LOW);
    digitalWrite(GPIO_PIN_NUMBER_13, LOW);
    digitalWrite(GPIO_PIN_NUMBER_14, LOW);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    digitalWrite(GPIO_PIN_NUMBER_25, LOW);
    digitalWrite(GPIO_PIN_NUMBER_26, LOW);
    digitalWrite(GPIO_PIN_NUMBER_27, LOW);
    digitalWrite(GPIO_PIN_NUMBER_32, LOW);
    digitalWrite(GPIO_PIN_NUMBER_33, LOW);
    digitalWrite(GPIO_PIN_NUMBER_34, LOW);
    digitalWrite(GPIO_PIN_NUMBER_35, LOW);
    Serial.println("\n Led apagado");
  } else if((char)payload[0] == '1'){
    digitalWrite(GPIO_PIN_NUMBER_1, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_2, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_4, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_5, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_12, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_13, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_14, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_25, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_26, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_27, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_32, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_33, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_34, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_35, HIGH);
    Serial.println("\n Led prendido");
  } else if((char)payload[0] == '2') {
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    Serial.println("\n Led prendido y apagado");
  } else if((char)payload[0] == '3'){
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(1000);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    delay(1000);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(1000);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    Serial.println("\n Led de lado a lado");
  } else if((char)payload[0] == '4') {
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    delay(1000);
    digitalWrite(GPIO_PIN_NUMBER_22, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, LOW);
    digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_15, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_21, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, LOW);
    digitalWrite(GPIO_PIN_NUMBER_21, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_18, HIGH);
    digitalWrite(GPIO_PIN_NUMBER_23, LOW);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, LOW);
    digitalWrite(GPIO_PIN_NUMBER_23, HIGH);
    delay(500);
    digitalWrite(GPIO_PIN_NUMBER_19, HIGH);
    Serial.println("\n Led apagado diferente");
  }else if((char)payload[0] == '5'){

  }else if((char)payload[0] == '6'){

  }

  Serial.println();
}

// R E C O N E C T A R
void reconnect(){
  while (!client.connected()) {
    Serial.println("Intentando Conexión MQTT");

    String clientId = "clientId-f4FrxdeHa0";
    //clientId = clientId + String(random(0xffff), HEX);

    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      Serial.println("Conexión a MQTT exitosa!!!");
      client.publish("salida", "primer mensaje");
      client.subscribe("entrada");
    } else {
      Serial.println("Falló la conexion...");
      Serial.print(client.state());
      Serial.print("Se intentará de nuevo en 5 segundos");
      delay(5000);
    }
  }
}


// S  E  T  U  P
void setup() {

  // LED, puerto del led de la esp32

  pinMode(GPIO_PIN_NUMBER_1, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_2, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_4, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_5, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_12, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_13, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_14, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_15, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_18, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_19, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_21, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_22, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_23, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_25, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_26, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_27, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_32, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_33, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_34, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_35, OUTPUT);

  digitalWrite(GPIO_PIN_NUMBER_1, LOW);
  digitalWrite(GPIO_PIN_NUMBER_2, LOW);
  digitalWrite(GPIO_PIN_NUMBER_4, LOW);
  digitalWrite(GPIO_PIN_NUMBER_5, LOW);
  digitalWrite(GPIO_PIN_NUMBER_12, LOW);
  digitalWrite(GPIO_PIN_NUMBER_13, LOW);
  digitalWrite(GPIO_PIN_NUMBER_14, LOW);
  digitalWrite(GPIO_PIN_NUMBER_15, LOW);
  digitalWrite(GPIO_PIN_NUMBER_18, LOW);
  digitalWrite(GPIO_PIN_NUMBER_19, LOW);
  digitalWrite(GPIO_PIN_NUMBER_21, LOW);
  digitalWrite(GPIO_PIN_NUMBER_22, LOW);
  digitalWrite(GPIO_PIN_NUMBER_23, LOW);
  digitalWrite(GPIO_PIN_NUMBER_25, LOW);
  digitalWrite(GPIO_PIN_NUMBER_26, LOW);
  digitalWrite(GPIO_PIN_NUMBER_27, LOW);
  digitalWrite(GPIO_PIN_NUMBER_32, LOW);
  digitalWrite(GPIO_PIN_NUMBER_33, LOW);
  digitalWrite(GPIO_PIN_NUMBER_34, LOW);
  digitalWrite(GPIO_PIN_NUMBER_35, LOW);

  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  // Esta funcion nos permite llamar al servidor (enviarle un mensaje)
  // Los servidores MQTT pueden iniciar las conversaciones
  client.setCallback(callback);


}


void loop() {

  // Evaluar si está conectado o si sigue conectado al server
  if (client.connected() == false) {
    reconnect();
  }

  // OBLIGATORIO
  client.loop();

  // Tener cuidado con el tiempo de espera, puede haber pérdida de msgs
  // delay(50000);

  if (millis() - lastMsg > 2000) {
    lastMsg = millis();
    value++;
    String mes = "Valor -> " + String(value);
    mes.toCharArray(msg, 50);
    client.publish("Salida", msg);
    Serial.println("Mensaje enviado -> " +  String(value));
  }

}