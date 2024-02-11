from machine import Pin, I2C
from ssd1306 import SSD1306_I2C
import time
from umqtt.simple import MQTTClient
import network

# Credenziali di connessione WiFi
ssid = "Taranto OnAir"
password = "Alex260981"

# Indirizzo IP del server MQTT
mqtt_server = "38.242.140.25"

# Inizializzazione del bus I2C e del display OLED
i2c = I2C(scl=Pin(17), sda=Pin(16))
oled = SSD1306_I2C(128, 64, i2c, addr=0x3c)

# Connessione alla rete WiFi
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(ssid, password)
while not wifi.isconnected():
    pass
print("Connesso alla rete WiFi")

# Connessione al broker MQTT
client = MQTTClient("ESP32Client", mqtt_server)
client.connect()
print("Connesso al broker MQTT")

def publish_message(topic, message):
    client.publish(topic, message)

# Main loop
while True:
    # Il tuo codice può andare qui

    # Esempio di pubblicazione su un topic MQTT
    publish_message("norvi/AE01-R/test", "Ciao dal tuo Norvi AE01-R!")

    # Aggiorna il display OLED
    oled.fill(0)
    oled.text("Hello, ESP32!", 0, 0)
    oled.show()

    # Aggiorna ogni 5 secondi
    time.sleep(5)
