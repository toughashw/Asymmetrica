# Asymmetrica Linux Machine

> Romania MQTT as a Service 
```
ssh root@109.123.245.17 -p 2200
```

```
mosquitto_sub -v -h 109.123.245.17 -u "12345678" -P "87654321"
-t "URC/RM_APP_URC_004/data"
```
```
mosquitto_pub -h 109.123.245.17 -u "12345678" -P "87654321"
-t "URC/RM_APP_URC_004/data" -m "example message"
```

> Flower MQTT Docker 
```
ssh root@38.242.140.25 -p 2200
```

```
mosquitto_sub -v -h 38.242.140.25 -t "AIRFLOWER/ComuneC/AR_008"
```
```
mosquitto_pub -h 38.242.140.25 -t "AIRFLOWER/ComuneC/AR_008" -m "example message"
```






