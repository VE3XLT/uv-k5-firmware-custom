#!/bin/sh

IMAGE_NAME="uvk5"

if docker image inspect $IMAGE_NAME >/dev/null 2>&1; then
    echo "Image exists locally"
else
	docker build -t $IMAGE_NAME .
fi

docker run --rm -v "${PWD}/compiled-firmware:/app/compiled-firmware" $IMAGE_NAME /bin/bash -c "cd /app && make && cp firmware* compiled-firmware/"
