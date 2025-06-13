# SSL-Check

This is a simple tool to check for the expiration date of a TLS/SSL Certificate by displaying the remainder of days until expiration.

It can be integrated with scripts and monitoring tools.


## Usage
```sslcheck example.com```
Returns long version

```sslcheck --short example.com```
returns only the days in number format (ideal for integrating it within other apps)



## Compiling from source

```cd sslcheck/src
make
sudo make install
```

Requires libssl.

Debian Family:
```sudo apt install libssl-dev```

RHEL/Fedora et al:
```sudo dnf install libssl-devel```

MacOS
```brew install gettext; brew install openssl```
To compile on mac you need to edit the Makefile to point to openssl@3 within the homebrew install dir

## Author
Alexia Michelle


## Language Support

it installs .mo files for English, French and Spanish

To add more support, feel free to send a merge request with the .po file of the language you want it to support
(sslcheck.pot template file included in src/)

## HELP

Open an issue on this project. I do not provide support via email.

## LICENSE

GNU GPL 3.0 (See LICENSE for more info)
