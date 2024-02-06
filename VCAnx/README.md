# Install VCAnx License

- Guide --> [https://nx.vcatechnology.com]

> Install VCAnx 
```
sudo ./vcanx-installer-2.9r3-linux-x64.sh
```

> Install VCAnx Plugin
```
sudo ./vcanx-installer-2.9r3-linux-x64.sh --plugin-only
```

> Install VCAnx Server
```
sudo ./vcanx-installer-2.9r3-linux-x64.sh --server-only
```

> Install VCAnx Both
```
sudo ./vcanx-installer-2.9r3-linux-x64.sh --both
```

> Install VCAnx Configuration Tool
```
sudo snap install ./vcanx-config-installer-2.9.5.snap --dangerous
```

> Install CUDA Toolkit 12.3
```
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2004/sbsa/cuda-keyring_1.1-1_all.deb
sudo dpkg -i cuda-keyring_1.1-1_all.deb
sudo apt-get update
sudo apt-get -y install cuda-toolkit-12-3
```

```
sudo apt-get install -y cuda-drivers
```

```
sudo apt-get install -y nvidia-kernel-open-545
sudo apt-get install -y cuda-drivers-545
```
