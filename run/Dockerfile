FROM centos:6.8

RUN buildDeps='openssl-devel mysql-devel libuuid-devel' \
	&& yum install -y $buildDeps \
	$$ yum clean all \
	&& cd /usr/lib64/mysql \
	&& ln -s libmysqlclient_r.so libmysqlclient_r.a

ENV TZ Asia/Shanghai
