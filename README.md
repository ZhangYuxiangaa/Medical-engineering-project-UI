# 1、QT Creator安装

```plain
#打开终端并输入以下命令，以更新当前软件包列表：
sudo apt-get update
#输入以下命令以安装Qt Creator：
sudo apt-get install qtcreator
#安装串口助手
sudo apt-get install libqt5serialport5-dev
```
# 2、一键启动配置

参考[https://blog.csdn.net/gmh_gmh/article/details/111325595](https://blog.csdn.net/gmh_gmh/article/details/111325595)

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

# 3、串口配置

```plain
ls -l /dev/ttyUSB*
sudo chmod 777 /dev/ttyUSB0
```

