set PROGRAM="%~1"

%PROGRAM% input.txt
if ERRORLEVEL 1 GOTO err

%PROGRAM% input2.txt
if ERRORLEVEL 1 GOTO err

%PROGRAM% input3.txt
if ERRORLEVEL 1 GOTO err

echo OK
exit 0

:err
echo Program testing failed
exit 1