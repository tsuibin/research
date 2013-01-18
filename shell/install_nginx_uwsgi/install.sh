#!/bin/bash

# DIY: 
# git clone http://git/aps.git
# cd aps/tool/install
# ./install.sh

# vars for debug
INSTALL_MYSQL=0
INSTALL_NGINX=1
INSTALL_UWSGI=1
INSTALL_PYTHON=1 
INSTALL_WWW=1

if [ $INSTALL_PYTHON -eq 1 ] ; then
    apt-get install python2.7 python-mysqldb
fi

if [ $INSTALL_MYSQL -eq 1 ] ; then
    mysql -V > /dev/null 2>&1
    if [ $? -eq 1 ] ; then
        apt-get install mysql-server-5.1 mysql-client-5.1
    else
        service mysql stop > /dev/null 2>&1
        sleep 3
    fi
    mysqld_safe --skip-grant-tables &
    sleep 5
    mysql -u root < ../../sql/db.sql
    sleep 5
    mysqladmin -u root -p'root' shutdown
    update-rc.d mysql defaults
    service mysql start
fi

if [ $INSTALL_UWSGI -eq 1 ] ; then
    apt-get install uwsgi uwsgi-plugin-cgi
    cp uwsgi.xml /etc/uwsgi/uwsgi.xml
    sed -i "s/exit 0/uwsgi\ \/etc\/uwsgi\/uwsgi\.xml/g" /etc/rc.local
    echo "exit 0" >> /etc/rc.local
    uwsgi /etc/uwsgi/uwsgi.xml
fi

if [ $INSTALL_NGINX -eq 1 ] ; then
    apt-get install nginx-full
    addr=`ifconfig | grep "inet " | awk '{print $2}' | sed -e 's/^.*:\(\(127\)\|\(192\)\).*//g' | sed -n '/.*:/p' | awk -F: '{print $2}'`
    sed "s/server_name localhost;/server_name $addr;/g" nginx.conf > /tmp/nginx.conf
    cp -f /tmp/nginx.conf /etc/nginx/sites-available/default
    update-rc.d nginx defaults
    service nginx start
fi

if [ $INSTALL_WWW -eq 1 ] ; then
    mkdir /home/www-data
    cp -r ../../web/* /home/www-data
    chown -R www-data:www-data /home/www-data
fi

exit 0
