#!/bin/bash
# Grafana Integration Example - Alexia Michelle <alexia@goldendoglinux.org>

# 1. Install a webserver of your choice and configure your web rootdir
# 2. change the value of the WEBROOT var to the path of your web rootdir
# 3. add/edit domains within the DOMAINS variable, one per line, as seen in
# this example.
# cron this script to run at least daily.
# Be sure the script is able to write within the web root dir
# This script will create one .json file per domain in the following format:
# example.com.json
# copy the full url and add it to your grafana dashboard in the form of
# https://example.com/example/example.com.json

WEBROOT="/var/www/html/grafana"

DOMAINS=(
  "lexi.lat"
  "goldendoglinux.org"
  # add more domains here

)

for domain in "${DOMAINS[@]}"; do
    days=$(sslcheck --short "$domain" 2>/dev/null)
    json="{\"domain\": \"${domain}\", \"days\": $days}"
    echo "$json" > "${WEBROOT}/${domain}.json"
done

