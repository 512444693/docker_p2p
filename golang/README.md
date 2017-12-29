### 编译
```
docker run --rm -it -v "$PWD":/usr/src/webserver -w /usr/src/webserver -e CGO_ENABLED=0 golang go build
```

### 制作镜像
```
docker build -t zhangmin/hello-world . -f Dockerfile.scratch
```

### 运行
```
docker run --rm -p 8099:8099 zhangmin/hello-world
```
