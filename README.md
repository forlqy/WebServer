# WebServer
Web服务器项目—参考sylar

## 环境
ubuntu 22.04 

## 依赖
1. boost库
```
git clone 
```
2. yaml-cpp
```
git clone
```
3. Ragel工具(生成有限状态机)
```
sudo apt install ragel
```
```
ragel -G2 -C http11_parser.rl -o http11_parser.cpp
ragel -G2 -C httpclient_parser.rl -o httpclient_parser.cpp
```


## 部署
```
cd build && cmake ..
```
```
make
```
在bin文件会生成可执行文件
