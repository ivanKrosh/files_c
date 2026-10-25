@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 6. Типові помилки роботи з файлами.
rem  До показу спрогнозуйте: де програма шукає marks.txt?
rem ============================================================
cd /d "%~dp0..\Файли"
set "BIN=%~dp0..\x64\Debug"
if not exist "%BIN%\Demo6_pitfalls.exe" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
echo === 1. Відносний шлях: запуск з теки Файли ===
echo ^> Demo6_pitfalls.exe where
"%BIN%\Demo6_pitfalls.exe" where
echo.
echo === Той самий файл .exe, запуск з теки x64\Debug ===
pushd "%BIN%"
echo ^> Demo6_pitfalls.exe where
.\Demo6_pitfalls.exe where
popd
echo.
echo   Відносний шлях рахується від поточного каталогу, а не від теки з .exe.
pause
echo.
echo === 2. Зворотна коса риска в рядку ===
echo ^> Demo6_pitfalls.exe slash
"%BIN%\Demo6_pitfalls.exe" slash
pause
echo.
echo === 3. Аварія до fclose ===
if exist crash.txt del crash.txt
echo ^> Demo6_pitfalls.exe crash
"%BIN%\Demo6_pitfalls.exe" crash
echo   Код завершення: %errorlevel%   (-1073741819 = 0xC0000005, доступ за нульовою адресою)
echo ^> dir crash.txt
dir crash.txt | findstr crash
echo.
echo   Файл створено, але три рядки лишилися в буфері потоку.
pause