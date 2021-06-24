FROM centos:8
RUN yum install cmake make gcc-c++ -y
# BUGS for centos:8 https://bugs.centos.org/view.php?id=18212
RUN yum install libarchive-3.3.3-1.el8.x86_64 -y
COPY . /app
WORKDIR /app
RUN cmake .
RUN make

FROM centos:8
COPY --from=0 /app/pcc /usr/local/pcc/bin/pcc
ENV PATH="/usr/local/pcc/bin:${PATH}"%