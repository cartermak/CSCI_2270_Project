#!/bin/bash


javac -d classes *.java -g
cd classes/
jar -cvfm test.jar MANIFEST.txt *
java -jar test.jar