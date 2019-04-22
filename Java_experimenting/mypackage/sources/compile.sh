#!/bin/bash

cd ..
javac -d classes *.java -g
cd sources/
jar -cvfm test.jar MANIFEST.txt *
java -jar test.jar