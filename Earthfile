deps:
    FROM ubuntu:20.04

    ENV DEBIAN_FRONTEND=noninteractive
    RUN apt-get update && \
        apt-get install -y \
        build-essential python3 cmake gcc-arm-none-eabi libnewlib-arm-none-eabi git
    ENV PICO_SDK_PATH=/pico-sdk
    WORKDIR "$PICO_SDK_PATH"
    RUN git clone https://github.com/raspberrypi/pico-sdk.git . && \
        git submodule update --init

test:
    FROM +deps
    WORKDIR /code
    RUN cp "$PICO_SDK_PATH/external/pico_sdk_import.cmake" .
    COPY blink.c CMakeLists.txt .
    WORKDIR /code/build
    RUN cmake .. && make blink
    SAVE ARTIFACT blink.elf AS LOCAL output/
    SAVE ARTIFACT blink.uf2 AS LOCAL output/