FROM debian:bullseye

RUN apt update -y && apt upgrade -y && apt-get install mariadb-server -y

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/init_db.sh /tmp/
COPY ./conf/init.sql /tmp/init.sql

RUN chown -R mysql:mysql /etc/mysql
RUN chmod +x /tmp/init_db.sh
RUN mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld


ENTRYPOINT ["sh", "/tmp/init_db.sh"]
