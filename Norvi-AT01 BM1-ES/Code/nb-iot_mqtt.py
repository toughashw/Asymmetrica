import time
from machine import UART, Pin
from umqtt.simple import MQTTClient

RX_PIN = 4  # Sostituisci con il pin RX del tuo ESP32
TX_PIN = 5  # Sostituisci con il pin TX del tuo ESP32

apn = "iot.1nce.net"
user = ""
password = ""
mqtt_server = "38.242.140.25"

# Inizializzazione della seriale e del modulo NB-IoT
uart = UART(1, baudrate=9600, tx=TX_PIN, rx=RX_PIN)
nb_pin = Pin(19, Pin.OUT)
nb_pin.value(1)  # Imposta il pin NB-IoT a HIGH

# Connessione al servizio NB-IoT
if not nb.connect(apn, user, password):
    print("Connessione fallita")
    while True:
        pass

print("Connessione NB-IoT stabilita!")

# Connessione al broker MQTT
client = MQTTClient("ESP32Client", mqtt_server)
client.connect()
print("Connesso al broker MQTT")

while True:
    # Leggi dalla porta seriale 2 e invia al broker MQTT
    if uart.any():
        data = uart.readall()
        client.publish("norvi/BM1-ES/test", data.decode('utf-8'))

    # Leggi dal broker MQTT e invia alla porta seriale 2
    msg = client.check_msg()
    if msg:
        uart.write(msg)
    
    # Il tuo codice specifico può andare qui
    
    time.sleep(1)
