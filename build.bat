@echo off

set SRC_DIR=src

set SRCS=%SRC_DIR%\main.c %SRC_DIR%\allocator\linalloc.c
set EXEC=main


set CC=clang
set CFLAGS=-Wl,-stack,0x10000000 -std=c17 -Wall
set DBFLAGS=

%CC% %CFLAGS% %DBFLAGS% %SRC_DIR%\allocator -o %EXEC% %SRCS% %LIB_DIR%

if "%1" == "run" (
    if exist %EXEC%.exe (
        %EXEC%
		del %EXEC%.exe
    )
) else if "%1" == "clean" (
	if exist %EXEC%.exe (
		del %EXEC%.exe
		echo Cleaned up: %EXEC%
	)
)

