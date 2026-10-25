@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 5. Фільтр: прочитати - обробити - записати.
rem  До показу спрогнозуйте: де з'явиться рядок "kept ... of ..."?
rem ============================================================
cd /d "%~dp0..\Файли"
set "BIN=%~dp0..\x64\Debug"
if not exist "%BIN%\Demo5_filter.exe" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
echo === Імена файлів в аргументах ===
echo ^> Demo5_filter.exe marks.txt passed.txt
"%BIN%\Demo5_filter.exe" marks.txt passed.txt
echo ^> type passed.txt
type passed.txt
pause
echo.
echo === Без аргументів: stdin і stdout ===
echo ^> Demo5_filter.exe ^< marks.txt
"%BIN%\Demo5_filter.exe" < marks.txt
pause
echo.
echo ^> Demo5_filter.exe ^< marks.txt ^> passed2.txt
"%BIN%\Demo5_filter.exe" < marks.txt > passed2.txt
echo ^> fc passed.txt passed2.txt
fc passed.txt passed2.txt > nul && echo   Файли однакові.
echo.
echo   Той самий цикл працює з файлом і з перенаправленням. "kept" іде в stderr.
pause