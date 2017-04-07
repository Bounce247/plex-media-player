cd %BUILD_DIR%  || exit /b

if exist ../conanfile.py (
  conan install ..
)

%CMAKE_DIR%\cmake -DDEPENDENCY_TOKEN=%DEP_SECRET% -DCRASHDUMP_SECRET=%CD_SECRET% -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=output -DDEPENDENCY_UNTAR_DIR=c:\jenkins\pmp-deps .. -G Ninja -DCODE_SIGN=ON -DENABLE_CODECS=on || exit /b

ninja || exit /b
ninja package || exit /b
