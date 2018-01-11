FROM centos:6.8

RUN buildDeps='openssl-devel mysql-devel libuuid-devel' \
	&& yum install -y $buildDeps \
	$$ yum clean all \
	&& cd /usr/lib64/mysql \
	&& ln -s libmysqlclient_r.so libmysqlclient_r.a

RUN rm -f /etc/localtime \
	&& ln -s /usr/share/zoneinfo/Asia/Shanghai  /etc/localtime
