:loop
python generate_data.py
main.exe
sol.exe
fc out1.txt out2.txt
if errorlevel 1 goto end
goto loop

:end
pause