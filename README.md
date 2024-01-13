# SSL-Check

Herramienta simple de la línea de comandos para chequear la salud y la fecha de vencimiento
del certificado SSL de un dominio.

## USO:
Instructions: 

Requires GCC and libssl 

Debian Ecosystem: ```sudo apt install libssl-dev```
RockyLinux/Fedora/CentOS Stream et al: ```sudo dnf install openssl-devel```

### Compiling:
```gcc sslcheck.c -o sslcheck -lssl -lcrypto```

### Usage: 
./sslcheck example.com

## Author

Alexia Rivera steinberg <alexiarstein@aol.com>

### Additional Notes

This is a very early release of something that might not even be useful but it is released anyway for learning purposes
and perhaps someone can take ideas from it. 

If you want to contribute to it, please by all means do so, feel free to clone it, do your fixes, create a new branch and send me a merge request!!

```
git clone https://github.com/alexiarstein/sslcheck.git

cd sslcheck

git checkout -b "your-fancy-branch-name"

Push to your branch and then send me a merge request over github
```

For ease of use it could be moved to /usr/local/bin and set the mode excecutable for everyone
```
sudo mv sslcheck /usr/local/bin
sudo chmod a+x /usr/local/bin/sslcheck
```
