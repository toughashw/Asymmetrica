# Docker & Services

> Docker 
```
```
> Docker Compose 
```
```

> Mosquitto
```
docker run -it -d --name mos1 -p 1883:1883 -v /etc/mosquitto/mosquitto.conf:/mosquitto/config/mosquitto.conf eclipse-mosquitto:2
```
> NodeRED
```
docker run -it -p 1880:1880 -v node_red_data:/data --name mynodered nodered/node-red
```
> Grafana
```
docker run -d -p 3000:3000 --name=grafana grafana/grafana-enterprise
```
> ChirpStack
```
git clone https://github.com/chirpstack/chirpstack-docker.git
cd chirpstack-docker
```
```
docker-compose up
```

