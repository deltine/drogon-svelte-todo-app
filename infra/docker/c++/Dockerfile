FROM ubuntu:20.04

ENV TZ "Asia/Tokyo"
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update -yqq \
    # gcc-11 g++-11
    && apt-get install -yqq --no-install-recommends apt-file software-properties-common \
    && apt-file update \
    && apt-file search apt-add-repository \
    && add-apt-repository -y ppa:ubuntu-toolchain-r/test \
    && apt-get install -yqq --no-install-recommends \
    curl wget cmake make pkg-config locales git nodejs npm gcc-11 g++-11 gdb \
    openssl libssl-dev libjsoncpp-dev uuid-dev zlib1g-dev libc-ares-dev libhiredis-dev \
    #Database
    # postgresql-server-dev-all \
    libmariadbclient-dev \
    # libsqlite3-dev \
    # && npm install npx \
    # && npm install n -g \
    # && n stable \
    # && apt purge -y nodejs npm \
    # && npm install -g npm@8.3.0 \
    && apt-get clean \
    && npm cache clean --force \
    && rm -rf /var/lib/apt/lists/* \
    && locale-gen ja_JP.utf8

RUN npm install npx
RUN npm install n -g
RUN n stable
RUN apt purge -y nodejs npm
RUN npm install -g npm@8.3.0

ENV LANG=ja_JP.utf8 \
    LANGUAGE=ja_JP:jp \
    LC_ALL=ja_JP.UTF-8 \
    CC=gcc-11 \
    CXX=g++-11 \
    AR=gcc-ar-11 \
    RANLIB=gcc-ranlib-11 \
    HOST=0.0.0.0 \
    IROOT=/install \
    DROGON_ROOT=/install/drogon

ADD https://api.github.com/repos/an-tao/drogon/git/refs/heads/master $IROOT/version.json
RUN git clone https://github.com/an-tao/drogon $DROGON_ROOT

WORKDIR $DROGON_ROOT

# cmake_gen='CMAKE_CXX_FLAGS="-std=c++20 -fcoroutines"'
# COPY ./infra/docker/c++/build.sh $DROGON_ROOT/build.sh
RUN ./build.sh

WORKDIR /workspace