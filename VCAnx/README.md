# Install VCAnx License

- Guide --> [https://nx.vcatechnology.com]

> Execute .sh
```
sudo chmod +x vcanx-installer-2.9r3-linux-x64.sh
```

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

> Install CUDA Toolkit 11.0
```
sudo wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/sbsa/cuda-ubuntu1804.pin
sudo mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600
sudo wget https://developer.download.nvidia.com/compute/cuda/11.0.1/local_installers/cuda-repo-ubuntu1804-11-0-local_11.0.1-450.36.06-1_arm64.deb
sudo dpkg -i cuda-repo-ubuntu1804-11-0-local_11.0.1-450.36.06-1_arm64.deb
sudo apt-key add /var/cuda-repo-ubuntu1804-11-0-local/7fa2af80.pub
sudo apt-get update
sudo apt-get -y install cuda
```
