# SSL-Check

Imprime el remanente de vida de un certificado TLS/SSL


En este momento imprime el resultado en español, pero es sencillo cambiarlo a otro idioma desde el código.

En el futuro implementaré algún tipo de config.


### USO
sslcheck dominio
```sslcheck google.com```

### Dependencias:

requiere gcc (obvio) y la libreria libssl. En debian:
```sudo apt install libssl-dev```

Redhat/Fedora et al:
```sudo dnf install libssl-devel```

### Compilado
```gcc sslcheck.c -o sslcheck -lssl -lcrypto```

### Autora
Alexia Michelle <alexia@goldendoglinux.org>
---
### Instalación

hacer el binario ejecutable y moverlo a /usr/local/bin
```chmod +x sslcheck && sudo mv sslcheck /usr/local/bin```

### Copiar a multiples sistemas

Compartir el binario solo funcionará en sistemas de la misma arquitectura y versión. Sino se debe recompilar en 
el host distinto.

### Notas Adicionales

Este release es algo para uso personal, bien puede integrarse en otras aplicaciones para herramientas de monitoreo.

La licencia es GNU GPL 3.0, pueden cambiar el formato del output a lo que deseen.

No enviar mail por soporte compilando o corriendo esta app, ver terminos en LICENSE.md

Utilizar los issues de git para ese fin.

Cualquier tipo de mejora es bienvenida. Enviar merge request siendo lo más descriptivos posibles así comprendo rápidamente que solución o mejora proponen y puedo incluirla más rapido.

