## 环境搭建

### 安装

```bash
    sudo apt-get install libbsd-dev
    wget http://www.apuebook.com/src.3e.tar.gz
    tar -zxvf src.3e.tar.gz
    cd apue.3e
    make (遇到的部分问题下面有, 台式机上的Ubuntu20遇到下面问题，笔记本上的WSL下的Ubuntu18一次过，玄学😌)

    放到gcc默认搜索的位置，不然要指定路径有点麻烦
    sudo cp ./include/apue.h /usr/local/include/
    sudo cp ./lib/libapue.a /usr/local/lib/

    编译
    gcc [filename].c -lapue
```

### 问题 1

![image](https://cdn.jsdelivr.net/gh/XmchxUp/cloudimg@master/20210513/image.4179tvm952e0.png)
找到 apue_3e/filedir/devrdev.c 添加头文件

```c
#include <sys/sysmacros.h>
```

![image](https://cdn.jsdelivr.net/gh/XmchxUp/cloudimg@master/20210513/image.16ijggnqrom8.png)

### 问题 2

![image](https://cdn.jsdelivr.net/gh/XmchxUp/cloudimg@master/20210513/image.o14ch92stog.png)
找到 apue.3e/stdio/buf.c

将这两处的\_flag 改成\_flags
![image](https://cdn.jsdelivr.net/gh/XmchxUp/cloudimg@master/20210513/image.4zg8m5h0ujg0.png)

修改这部分
![image](https://cdn.jsdelivr.net/gh/XmchxUp/cloudimg@master/20210513/image.78k39std6lk0.png)
