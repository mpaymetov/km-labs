set PROGRAM="%~1"

%PROGRAM% 

echo OK
exit /B 0

:err
echo Program testing failed
exit 1