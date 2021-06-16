# make stallman cry
FROM ubuntu

# dont ask me for my timezone please
ENV DEBIAN_FRONTEND=noninteracrive

# set working directory
COPY . /usr/src/davis
WORKDIR /usr/src/davis

# install build dependencies from apt
RUN set -ex;\
apt-get update;\
apt-get install -y gcc g++ cmake git wget libjsoncpp-dev uuid-dev openssl libcurl4-openssl-dev libpulse-dev libssl-dev zlib1g-dev postgresql-all;

# build drogon from source
RUN set -ex;\
git clone https://github.com/an-tao/drogon;\
cd drogon;\
git submodule update --init;\
mkdir build; cd build;\
cmake ..; make;\
make install;\
cd ../..; rm -rf drogon;

# build aws cpp sdk from source
RUN set -ex;\
git clone --recurse-submodules https://github.com/aws/aws-sdk-cpp;\
cd aws-sdk-cpp;\
mkdir build; cd build;\
cmake .. -DCMAKE_BUILD_TYPE=Release -D BUILD_ONLY="s3" -DENABLE_TESTING=OFF; make;\
make install;\
cd ../..; rm -rf aws-sdk-cpp;

# i can't think of any better ways of doing this
RUN set -ex;\
cd /usr/include;\
mkdir awsdoc; cd awsdoc;\
mkdir s3; cd s3;\
wget https://raw.githubusercontent.com/awsdocs/aws-doc-sdk-examples/master/cpp/example_code/s3/include/awsdoc/s3/S3_EXPORTS.h;\
wget https://raw.githubusercontent.com/awsdocs/aws-doc-sdk-examples/master/cpp/example_code/s3/include/awsdoc/s3/s3-demo.h;\
wget https://raw.githubusercontent.com/awsdocs/aws-doc-sdk-examples/master/cpp/example_code/s3/include/awsdoc/s3/s3_examples.h;\
wget https://raw.githubusercontent.com/awsdocs/aws-doc-sdk-examples/master/cpp/example_code/s3/include/awsdoc/s3/s3_list_objects_with_aws_global_region.h;

# time to build davis
RUN set -ex;\
cd /usr/src/davis;\
mkdir build; cd build;\
cmake ..; make; ls -A;

# run the backend
CMD ["./Davis_Backend"]
