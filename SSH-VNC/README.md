# SETUP SSH & VNC on Boards


- Remote.it ---> [https://www.remote.it]
- REALVNC ---> [https://www.realvnc.com]
- NoMachine ---> [https://www.nomachine.com]

> SSH
- Check RemoteIT versions
```
https://www.remote.it/download-list?products=device-package#Download-Results
```

- Download RemoteIT .deb for ARM64
```
sudo wget https://downloads.remote.it/remoteit/v5.1.1/remoteit-5.1.1.arm64.jetson.deb
```

Install RemoteIT
```
sudo dpkg -i remoteit-5.1.1.arm64.jetson.deb
```


# VNC Preliminar Operations
```
mkdir -p ~/.config/autostart
cp /usr/share/applications/vino-server.desktop ~/.config/autostart/.
gsettings set org.gnome.Vino prompt-enabled false
gsettings set org.gnome.Vino require-encryption false
gsettings set org.gnome.Vino authentication-methods "['vnc']"
gsettings set org.gnome.Vino vnc-password $(echo -n 'la mia password'|base64)
sudo nano /usr/NX/etc/node.cfg
add line DefaultDesktopCommand "/usr/bin/startxfce4"
sudo reboot now
```

> VNC (first solution NOMACHINE) 
[https://kb.nomachine.com/AR02R01074]

- Check NOMACHINE versions
```
https://downloads.nomachine.com/linux/?id=1
```

- Download NOMACHINE .deb for ARM64
```
sudo wget https://download.nomachine.com/download/8.11/Linux/nomachine_8.11.3_4_amd64.deb
```

Install NOMACHINE
```
sudo wget https://www.nomachine.com/free/arm/v8/deb -O nomachine.deb
sudo dpkg -i nomachine.deb
```

> VNC (second solution REALVNC)
[https://omar2cloud.github.io/rasp/realvnc/]

- Check REALVNC versions
```
https://archive.raspberrypi.org/debian/pool/main/r/realvnc-vnc/
```

- Download REALNVC SERVER/VIEWER .deb for ARM64
```
sudo wget https://archive.raspberrypi.org/debian/pool/main/r/realvnc-vnc/realvnc-vnc-server_7.5.1.50075_arm64.deb
sudo wget https://archive.raspberrypi.org/debian/pool/main/r/realvnc-vnc/realvnc-vnc-viewer_7.5.1.50075_arm64.deb
```

Install REALVNC SERVER/VIEWER
```
sudo dpkg -i realvnc-vnc-server_7.5.1.50075_arm64.deb
sudo dkpg -i realvnc-vnc-viewer_7.5.1.50075_arm64.deb
```

> TightVNC (third solution ThightVNC)
```
sudo apt-get update
sudo apt-get install xfce4
```

```
sudo apt-get install tightvncserver
```

```
tightvncserver
```

```
echo "tightvncserver" >> ~/.bashrc
```

```
tightvncserver :5900 -geometry 1280x720
```