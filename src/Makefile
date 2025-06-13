# Makefile for sslcheck - builds on macOS and Linux
# https://github.com/alexiarstein/sslcheck
# If you're building on macOS, be sure to install gettext and openssl.
# Maintained by Alexia Michelle

CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lssl -lcrypto

UNAME_S := $(shell uname -s)
PREFIX = /usr/
DOMAIN = sslcheck
LOCALEDIR = $(PREFIX)/share/locale
BINDIR = $(PREFIX)/bin
POFILES = es fr en

all: sslcheck mo

sslcheck: sslcheck.c
	@echo "Compiling for: $(UNAME_S)"
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

mo:
	@echo "Compiling translation files..."
	@for lang in $(POFILES); do \
		echo "  $$lang"; \
		msgfmt $$lang.po -o $$lang.mo; \
	done

install: all
	@echo "Installing binary to $(BINDIR)"
	install -Dm755 sslcheck $(DESTDIR)$(BINDIR)/sslcheck
	@echo "Installing locales to $(LOCALEDIR)"
	@for lang in $(POFILES); do \
		mkdir -p $(DESTDIR)$(LOCALEDIR)/$$lang/LC_MESSAGES; \
		install -m 644 $$lang.mo $(DESTDIR)$(LOCALEDIR)/$$lang/LC_MESSAGES/$(DOMAIN).mo; \
	done

clean:
	@rm -f sslcheck *.mo *~
	@echo "Clean complete."
