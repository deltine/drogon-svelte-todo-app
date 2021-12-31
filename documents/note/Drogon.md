・drogonのコンパイル
cd /drogon/install/build
cmake ..
make && sudo make install

・コンパイル成功確認
drogon_ctl -v
※コマンドが実行されれば成功

■プロジェクト作成

・プロジェクト置き場を作成
mkdir /drogon/project && cd /drogon/project

drogon_ctl create project [YOUR_PROJECT_NAME]
drogon_ctl create project dg_sample

・drogonプロジェクトのCMakeLists.txtに以下を追記【要否確認】
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

・ビルド、実行
cd /drogon/install/dg_sample/build
cd /install/drogon/dg_sample/build
cmake ..
make
./dg_sample


・コントローラー作成(HttpController)
cd controllers && drogon_ctl create controller -h demo::v1::User
・コントローラー作成(HttpSimpleController)
cd /drogon/dg_sample/controllers && drogon_ctl create controller TestCtrl
cd /drogon/dg_sample/controllers && drogon_ctl create controller ListParaCtrl

drogon_ctl create controller -h ./controllers/demo::v1::User

・ビューの作成
cd /drogon/dg_sample/view && drogon_ctl create view ListParaView.csp


・Multiple Path Mapping

// "/users/"を接頭辞としたURL全て
ADD_METHOD_TO(UserController::handler1,"/users/.*",Post); 
 
// "/{文字列}/{数字}"のURL全て
ADD_METHOD_TO(UserController::handler2,"/{name}/[0-9]+",Post);

・Regular Expression (Regex: 正規表現)

// "/users/"を接頭辞とするURLをhandler1へ
ADD_METHOD_VIA_REGEX(UserController::handler1,"/users/(.*)",Post); 

// "/abcde5"のような、末尾が数字となるURLをhandler2へ
ADD_METHOD_VIA_REGEX(UserController::handler2,"/.*([0-9]*)",Post); 

// "/data"で始まらないURLをhandler3へ
ADD_METHOD_VIA_REGEX(UserController::handler3,"/(?!data).*",Post);