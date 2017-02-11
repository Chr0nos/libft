FROM alpine
MAINTAINER snicolet snicolet@student.42.fr
RUN apk update && apk add git clang binutils openssh libc-dev make
WORKDIR /root
RUN git clone https://github.com/Chr0nos/libft.git
RUN make -C ./libft/
