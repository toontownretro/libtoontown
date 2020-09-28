@echo off
win_flex -P dnayy -o lexer.cxx lexer.lxx
win_bison -y -d -p dnayy -o parser.cxx parser.yxx
pause