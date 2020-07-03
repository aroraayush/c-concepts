Setup referrenced from [yular.github.io](http://yular.github.io/2017/01/28/C-Redis-QuickStart/)
---
Works on CentOS/Ubuntu
```
git clone https://github.com/redis/hiredis.git
cd hiredis
make
sudo make install
``` 
Adding `hiredis` to linux include directory
```
sudo mkdir /usr/include/hiredis
sudo cp libhiredis.so /usr/lib/
sudo cp hiredis.h /usr/include/hiredis/
sudo cp read.h /usr/include/hiredis/
sudo cp sds.h /usr/include/hiredis/
ldconfig
```
Run the `example.c` file
```
make
make test
```
