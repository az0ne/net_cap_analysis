# net_cap_analysis
毕设：基于协议分析的网络取证系统

  使用c语言，搭配WinPcap、QT框架进行设计编写。

  捕获底层网卡协议报文，解析协议关键字段：ARP,IPV4,TCP,UDP,ICMP,HTTP
  解析HTTP协议header请求，post表单数据，传输的JPG、PNG格式图片,传输的zip、doc、txt、rar、exe等格式文件。
  解析内容和图片缩略图在GUI界面分类展示，文件保存在程序目录下的data文件夹下。
  
  不足：程序解析，数据保存，GUI界面全部集成在单线程内，运行效率低，用户操作反馈延迟，协议解析种类较少。


