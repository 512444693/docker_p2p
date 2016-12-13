# docker_p2p
p2p编译环境镜像

## 生成镜像
    docker build -t p2p_compile .

- Dockerfile会安装依赖库
- public和server目录是底层库，拷贝到镜像的/opt目录下，并编译

## 示例
程序queryvp，假设目录在/opt/program/queryvp下
### 编译
    docker run --rm -v /opt/program/queryvp:/opt/server/cdn/queryvp \
     -w /opt/server/cdn/queryvp p2p_compile ./build.sh

- --rm 退出后删除
- -v 配置数据卷
- -w 设置工作目录
- ./build 编译

### 运行
    docker run --rm -v /opt/program/queryvp:/opt/server/cdn/queryvp \
     -w /opt/server/cdn/queryvp p2p_compile ./queryvp -l

## 其它
- 可配合portainer使用，只需要点点点就可以启动程序，so easy
![image](https://raw.githubusercontent.com/512444693/docker_p2p/master/images/1.jpg)
- 有特殊依赖的程序编译时可能需要在镜像中安装其它依赖