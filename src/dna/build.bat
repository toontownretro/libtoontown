@echo off
win_flex -P dnayy -o lexer.cxx.prebuilt lexer.lxx
win_bison -y --defines=parser.hxx.prebuilt -p dnayy -o parser.cxx.prebuilt parser.yxx
pause