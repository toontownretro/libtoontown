#!/bin/bash

flex -Pdnayy -o lexer.cxx lexer.lxx
bison -y -d -p dnayy -o parser.cxx parser.yxx