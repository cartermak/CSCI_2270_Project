#!/bin/bash


javac -d classes *.java -g
cd classes/
jar -cvfm project.jar MANIFEST.txt *