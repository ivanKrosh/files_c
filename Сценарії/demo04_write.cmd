@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 4. Запис у текстовий файл: режими w і a.
rem  До показу спрогнозуйте: що буде в log.txt після двох запусків?
rem ============================================================
cd /d "%~dp0..\Файли"
set "BIN=%~dp0..\x64\Debug"
if not exist "%BIN%\Demo4_write.exe" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
echo ^> Demo4_write.exe
"%BIN%\Demo4_write.exe"
pause
echo.
echo ^> type report.txt
type report.txt
echo.
echo ^> type log.txt
type log.txt
pause
echo.
echo === Другий запуск ===
"%BIN%\Demo4_write.exe" > nul
echo ^> type log.txt
type log.txt
echo.
echo   report.txt перезаписано ("w"), у log.txt рядок дописано в кінець ("a").
pause