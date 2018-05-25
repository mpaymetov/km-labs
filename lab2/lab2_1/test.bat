set PROGRAM="%~1"

%PROGRAM% input.txt
if ERRORLEVEL 1 GOTO err

rem %PROGRAM% input2.txt
rem if ERRORLEVEL 1 GOTO err

echo OK
exit 0

:err
echo Program testing failed
exit 1