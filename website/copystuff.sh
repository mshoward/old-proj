#! /bin/sh
rm -rf web
mkdir web
cp -R /web* web
chown -R mason:mason web
