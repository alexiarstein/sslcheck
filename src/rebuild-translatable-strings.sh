#!/bin/bash
# SSLCHECK by Alexia Michelle <alexia@goldendoglinux.org>
# You probably don't need this unless you are actively developing the code
# This rebuilds the .po files in case new translatable strings are added to the source code
# Alexia

xgettext -k_ -o sslcheck.pot sslcheck.c
msgmerge --update es.po sslcheck.pot
msgmerge --update fr.po sslcheck.pot
msgmerge --update en.po sslcheck.pot
echo "strings updated. Review the lines that require translation"
