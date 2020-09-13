@echo off
win_flex -Pdnayy -o lexer.cxx lexer.lxx
win_bison -y -d -p dnayy -o parser.cxx parser.yxx
pause