@echo off
set PROGRAM=multmatrix.exe

%PROGRAM% matrix1.txt empty.txt
if NOT ERRORLEVEL 1 goto err
fc.exe open_empty_file.txt out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt not_created_file.txt
if NOT ERRORLEVEL 1 goto err
fc.exe open_not_created_file.txt out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt bad_matrix2.txt
if NOT ERRORLEVEL 1 goto err
fc.exe open_bad_matrix.txt out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt matrix2.txt
if ERRORLEVEL 1 goto err
fc.exe open_successful_matrix.txt out.txt
if ERRORLEVEL 1 goto err

echo Program testing successful


:err
echo Program testing error
