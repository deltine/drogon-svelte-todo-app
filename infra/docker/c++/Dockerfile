FROM ubuntu:20.04

ENV TZ "Asia/Tokyo"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update -yqq \
    && apt-get install -yqq --no-install-recommends software-properties-common \
    curl wget cmake make pkg-config locales git nodejs npm gcc-10 g++-10 gdb \
    openssl libssl-dev libjsoncpp-dev uuid-dev zlib1g-dev libc-ares-dev libhiredis-dev \
    #Database
    # postgresql-server-dev-all \
    libmariadbclient-dev \
    # libsqlite3-dev \
    && npm install npx \
    && apt-get clean \
    && npm cache clean --force \
    && rm -rf /var/lib/apt/lists/* \
    && locale-gen ja_JP.utf8

ENV LANG=ja_JP.utf8 \
    LANGUAGE=ja_JP:jp \
    LC_ALL=ja_JP.UTF-8 \
    CC=gcc-10 \
    CXX=g++-10 \
    AR=gcc-ar-10 \
    RANLIB=gcc-ranlib-10 \
    HOST=0.0.0.0 \
    IROOT=/install

ENV DROGON_ROOT="$IROOT/drogon"

ADD https://api.github.com/repos/an-tao/drogon/git/refs/heads/master $IROOT/version.json
RUN git clone https://github.com/an-tao/drogon $DROGON_ROOT

WORKDIR $DROGON_ROOT

RUN ./build.sh

WORKDIR /workspace