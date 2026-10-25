@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 2. fopen: режими й помилки.
rem  До показу спрогнозуйте: що поверне fopen у кожному випадку?
rem ============================================================
cd /d "%~dp0..\Файли"
set "BIN=%~dp0..\x64\Debug"
if not exist "%BIN%\Demo2_open.exe" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
rem підготовка: файл лише для читання
if exist readonly.txt attrib -r readonly.txt
echo data> readonly.txt
attrib +r readonly.txt

echo === 1. Файлу немає ===
echo ^> Demo2_open.exe nofile.txt r
"%BIN%\Demo2_open.exe" nofile.txt r
echo.
echo === 2. Каталогу немає ===
echo ^> Demo2_open.exe nodir\out.txt w
"%BIN%\Demo2_open.exe" nodir\out.txt w
echo.
echo === 3. Файл лише для читання ===
echo ^> Demo2_open.exe readonly.txt w
"%BIN%\Demo2_open.exe" readonly.txt w
pause
echo.
echo === 4. Успішне відкриття ===
echo ^> Demo2_open.exe marks.txt r
"%BIN%\Demo2_open.exe" marks.txt r
echo.
echo   Дескриптор 3: номери 0, 1, 2 вже зайняті стандартними потоками.
pause
echo.
echo === 5. Режим a і режим w для наявного файлу ===
echo one two three> test.txt
echo ^> dir test.txt
dir test.txt | findstr test
echo ^> Demo2_open.exe test.txt a
"%BIN%\Demo2_open.exe" test.txt a > nul
dir test.txt | findstr test
echo ^> Demo2_open.exe test.txt w
"%BIN%\Demo2_open.exe" test.txt w > nul
dir test.txt | findstr test
echo.
echo   "w" обнулив файл, хоча програма нічого не записувала.
attrib -r readonly.txt
del readonly.txt
pause