# Makefile para sslcheck - detecta macOS y Linux
# Si estás queriendo compilar SSLCHECK en macOS, recordá instalar
# gettext y openssl. Si los insalás via homebrew no hace falta modificar
# este makefile. Sino apuntá los directorios de ambas correctamente debajo
# Alexia
CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lssl -lcrypto

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    # MacOS con Homebrew
    OPENSSL_DIR := /opt/homebrew/opt/openssl@3
    GETTEXT_DIR := /opt/homebrew/opt/gettext

    CFLAGS += -I$(OPENSSL_DIR)/include -I$(GETTEXT_DIR)/include
    LDFLAGS += -L$(OPENSSL_DIR)/lib -L$(GETTEXT_DIR)/lib -lintl
endif

ifeq ($(UNAME_S),Linux)
    # En Linux asumimos que las libs están en lugares estándar
    LDFLAGS += -lintl
endif

all: sslcheck

sslcheck: sslcheck.c
	@echo "Compilando para: $(UNAME_S)"
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	@rm -f sslcheck
