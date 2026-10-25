@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 3. Читання текстового файлу marks.txt.
rem  До показу спрогнозуйте: що поверне fscanf, коли файл закінчиться?
rem ============================================================
cd /d "%~dp0..\Файли"
set "BIN=%~dp0..\x64\Debug"
if not exist "%BIN%\Demo3_read.exe" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
echo ^> type marks.txt
type marks.txt
pause
echo.
echo ^> Demo3_read.exe
"%BIN%\Demo3_read.exe"
pause
echo.
echo === Цикл while (!feof(f)) ===
echo ^> Demo3_read.exe feof
"%BIN%\Demo3_read.exe" feof
echo.
echo   Останній запис враховано двічі: feof стає істинним лише ПІСЛЯ невдалого читання.
pause