sed -e "s/cmake_gen=''/cmake_gen='-DCMAKE_CXX_FLAGS=\"-std=c++20\"'/g" build.sh
sed -e "s/cmake_gen=''/cmake_gen='-DCMAKE_CXX_FLAGS=\"-std=c++20\"'/g" build.sh > build.sh

#cmakeインストール
wget https://github.com/Kitware/CMake/releases/download/v3.22.1/cmake-3.22.1.tar.gz
tar -zxvf cmake-3.22.1.tar.gz

git clone https://github.com/Kitware/CMake.git -d v3.22.1

cd cmake
./bootstrap
make -j5
sudo make install


フォルダ削除
rm -rf ディレクトリ名

コマンド確認？
which cmake

ハッシュクリア？
hash -r