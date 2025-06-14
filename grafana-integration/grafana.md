## Grafana integration

### Requirements

a webserver 

If your grafana deployment is outside your local network, your webserver must have permissions to be reached from outside your lan
Alternatively you can create a github pages portal and rewrite the bash script to push the json files to the repo you are using
to host your github pages website


### Install the infinity plugin in grafana

This plugin will allow you to use a URL as data source, which can be in many formats including xml, html and json
the bash script will create the output in json format but feel free to modify it to your liking.


## Cron the bash script

Ideally once a day. It's pointless to check for less time than that for obvious reasons. 

Be sure the bash script can write into the web rootdir.


If you need help open a github issue ticket. 

That's all :3
