# # Create network first
# docker network create --subnet=172.15.1.0/24 qt-net
# # Build it
# docker build -t hill/client .
# # Run it (client second)
# docker run -t -v /c/Users/hillk/Desktop/Tutorials/Docker_socket_test/client_container/work:/mnt --workdir /mnt --network=qt-net --ip 172.15.1.10 --name clientcon -e ipaddr="172.15.1.20" -e port=1234 -e message_num=2000 --rm hill/client
#
# Pull base image.
FROM ubuntu:20.04

## Let apt-get know we are running in noninteractive mode
ENV DEBIAN_FRONTEND noninteractive

# Install.
RUN  apt-get update && \
	 apt-get install -y qt5-default && \
	 apt-get install -y build-essential && \
	 apt-get install -y cmake
  
# Define default command.
CMD /bin/bash build_run_client.sh ${ipaddr} ${port} ${message_num}