
# DuduClock 嘟嘟天气时钟代码固件
## [PCB 外壳模型 组装视频在这里](https://github.com/leezicai/DuDuClock)

### 原码大聪明老师, 增加内容: 和天气数据可在配置时一起配置, 刷入固件即用

## 开发板地址

```
https://espressif.github.io/arduino-esp32/package_esp32_dev_index.json
```

## 开发板管理器

esp32 by Espressif Systems  2.09版本

## 包与版本

```
Onebutton  2.5.0
Arduinojson 7.0.4
TaskScheduler 3.7.0
ArduinoFFT 2.0.2
```

## 新增本地的包 [包](./local_lib)

## 屏幕引脚与硬件验证

以下 TFT SPI 引脚已在一台 DuduClock 2.1 实机上验证：

| 信号 | GPIO |
| --- | ---: |
| SCLK | 2 |
| MOSI | 3 |
| CS | 7 |
| DC | 4 |
| RST | 5 |

测试硬件为 ESP32-C3 rev 0.4，屏幕参数为 ST7789V、SPI、240×320、显示区域
36.72×48.96 mm、TN 12 o'clock。官方 v2.1.2 固件的机器码同样以
`SPI.begin(2, 3, 3, -1)` 初始化显示总线。

如果将 SCLK 配置为 GPIO 10，该实机会出现背光点亮但画面始终灰白的现象，
而串口、Wi-Fi 扫描和 Web 配网服务仍可正常运行。不同 PCB 或屏幕批次可能采用
不同走线；若硬件参数与上述实机不一致，请先核对原理图或通过已知可用固件确认引脚。
