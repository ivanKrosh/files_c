@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 1. Текстовий і двійковий файл.
rem  До показу спрогнозуйте: скільки байтів займе кожен файл?
rem ============================================================
cd /d "%~dp0..\Файли"
set "BIN=%~dp0..\x64\Debug"
if not exist "%BIN%\Demo1_kinds.exe" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
echo ^> Demo1_kinds.exe
"%BIN%\Demo1_kinds.exe"
echo.
echo   text.txt   - цифри і 0D 0A після кожного числа.
echo   binary.bin - по 4 байти на число, молодший байт першим.
pause
echo.
echo === Обидва файли в Блокноті ===
start notepad text.txt
start notepad binary.bin
echo   text.txt - три рядки з числами; binary.bin - незрозумілі символи.
pause