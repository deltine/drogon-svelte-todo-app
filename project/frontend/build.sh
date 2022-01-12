#!/bin/bash

function usage() {
    cat <<EOF
$(basename ${0}) is a tool for ...

Usage:
  $(basename ${0}) [command] [<options>]

Options:
  install|i             Svelteをインストールします。
  run|r                 フロントプロジェクト起動
  dark|d                テーマの更新
  newproject|new|n      新規プロジェクトを作成します。
  --version, -v         バージョンを表示します。
  --help, -h            ヘルプを表示します。
EOF
};

function version() {
    echo "$(basename ${0}) version 0.0.1"
};

case ${1} in
    install|i)
        mkdir /workspace/project/frontend
        cd /workspace/project/frontend
        npx degit sveltejs/template .
        npm i
    ;;

    run|r)
        npm run dev
    ;;

    dark|d)
        npm run prepare
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