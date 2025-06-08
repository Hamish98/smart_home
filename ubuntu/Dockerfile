FROM ubuntu:24.04

# 开放 SSH 端口
EXPOSE 22

# 设置非交互模式，避免 tzdata 等组件安装时报错
ENV DEBIAN_FRONTEND=noninteractive

# 创建开发目录
RUN mkdir -p /root/proj

# 安装 openssh-server 和其他必要组件
RUN apt-get update && \
    apt-get install -y openssh-server passwd gcc g++ cmake && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# 设置 root 密码（可根据需要更改）
RUN echo "root:123456" | chpasswd

# 创建 ssh 所需的目录
RUN mkdir -p /var/run/sshd

# 配置 sshd 允许 root 登录和密码登录
RUN sed -i 's/^#\?PermitRootLogin.*/PermitRootLogin yes/' /etc/ssh/sshd_config && \
    sed -i 's/^#\?PasswordAuthentication.*/PasswordAuthentication yes/' /etc/ssh/sshd_config

# 容器启动时运行 sshd
CMD ["/usr/sbin/sshd", "-D"]