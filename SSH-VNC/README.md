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
> VNC (first solution NOMACHINE)
- Check NOMACHINE versions
```
https://downloads.nomachine.com/linux/?id=1
```

- Download NOMACHINE .deb for ARM64
```
https://download.nomachine.com/download/8.11/Linux/nomachine_8.11.3_4_amd64.deb
```

Install NOMACHINE
```
sudo dpkg -i nomachine_8.11.3_4_amd64.deb
```

> VNC (second solution REALVNC)
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
