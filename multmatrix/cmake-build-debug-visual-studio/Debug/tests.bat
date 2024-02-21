set PROGRAM=multmatrix.exe

%PROGRAM% matrix1.txt empty.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt not_created_file.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt bad_matrix2.txt
if NOT ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt matrix2.txt
if ERRORLEVEL 1 goto err

echo Program testing successful

:err
echo Program testing error