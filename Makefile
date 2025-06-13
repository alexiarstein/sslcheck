CC = gcc
CFLAGS = -Wall -O2 -I/usr/local/opt/openssl/include
LDFLAGS = -L/usr/local/opt/openssl/lib -lssl -lcrypto

PO_DIR = po
MO_DIR = /usr/local/share/locale

APP = sslcheck
SRC = sslcheck.c

all: $(APP)

$(APP): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Extrae las cadenas para traducción
.PHONY: pot
pot:
	xgettext --keyword=_ --from-code=UTF-8 -o $(PO_DIR)/sslcheck.pot $(SRC)

# Compila los archivos .po a .mo
.PHONY: locales
locales:
	mkdir -p $(MO_DIR)/es/LC_MESSAGES
	mkdir -p $(MO_DIR)/en/LC_MESSAGES
	msgfmt $(PO_DIR)/es.po -o $(MO_DIR)/es/LC_MESSAGES/sslcheck.mo
	msgfmt $(PO_DIR)/en.po -o $(MO_DIR)/en/LC_MESSAGES/sslcheck.mo

clean:
	rm -f $(APP)
