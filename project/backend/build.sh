#!/bin/bash

function usage() {
    cat <<EOF
$(basename ${0}) is a tool for ...

Usage:
  $(basename ${0}) [command] [<options>]

Options:
  install|i                 Drogonをインストールします。                   
  newproject|new|n          新規プロジェクトを作成します。
  build|b                   プロジェクトをビルドします。
  dg_ctl-version|dv         dg_ctlのバージョンを表示します。
  create-view|cv            ビューを作成します。(作成できない？)
  create-controller|cc      コントローラーを作成します。
  create-web-socket|cw      WebSocketコントローラーを作成します。
  create-filters|cf         フィルターを作成します。
  --version, -v     バージョンを表示します。
  --help, -h        ヘルプを表示します。
EOF
};

function version() {
    echo "$(basename ${0}) version 0.0.1"
};

case ${1} in
    install|i)
        cd /install/drogon/build
        cmake ..
        make && sudo make install
    ;;

    newproject|new|n)
        mkdir -p /workspace/project
        cd /workspace/project
        dg_ctl create project backend
    ;;

    build|b)
        cd /workspace/project/backend/build
        cmake ..
        make
    ;;

    create-view|cv) 
        cd /workspace/project/backend/views
        # example
        # dg_ctl create view UsersList.csp
        dg_ctl create view ${2}
    ;;

    create-controller|cc)
        cd /workspace/project/backend/controllers
        # example
        # dg_ctl create controller -h api::TestController
        # dg_ctl create controller -h web::TestController
        dg_ctl create controller -h ${2}
    ;;

    create-web-socket|cw)
        cd /workspace/project/backend/controllers
        # example
        # dg_ctl create controller -h socket::ControllerTest
        dg_ctl create controller -w ${2}
    ;;

    create-filters|cf)
        cd /workspace/project/backend/filters
        # example
        # dg_ctl create controller -h app::web::LoginFilter
        dg_ctl create filter ${2}
    ;;

    dg_ctl-version|dv)
        dg_ctl --version
    ;;

    help|--help|-h)
        usage
    ;;

    version|--version|-v)
        version
    ;;

    *)
        echo "[ERROR] Invalid subcommand '${1}'"
        usage
        exit 1
    ;;
esac