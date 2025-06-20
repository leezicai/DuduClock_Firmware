#include <Preferences.h>
#include "net.h"
#include "tftUtil.h"

Preferences prefs; // 声明Preferences对象

// 读取Wifi账号、密码和城市名称
void getWiFiCity(){
  prefs.begin("clock");
  ssid = prefs.getString("ssid", "");
  pass = prefs.getString("pass", "");
  city = prefs.getString("city", "");
  adm = prefs.getString("adm", "");
  location = prefs.getString("location", "");

  publicKeyMm = prefs.getString("publicKeyMm");
  publicKeyMm.toCharArray(charPublicKey, 61);
  Serial.println("get:" + publicKeyMm);
  privateKeyMm = prefs.getString("privateKeyMm");
  privateKeyMm.toCharArray(charPrivateKey, 65);
  Serial.println("get:" + privateKeyMm);
  keyID = prefs.getString("keyID");
  Serial.println("get:" + keyID);
  apiHost = prefs.getString("apiHost");
  Serial.println("get:" + apiHost);
  projectID = prefs.getString("projectID");
  Serial.println("get:" + projectID);

  prefs.end();
}

// 写入Wifi账号、密码和城市名称
void setWiFiCity(){
  prefs.begin("clock");
  prefs.putString("ssid", ssid);
  prefs.putString("pass", pass);
  prefs.putString("city", city);
  prefs.putString("adm", adm);
  prefs.putString("location", location);
  prefs.end();
}
void setHeFeng(){
  prefs.begin("clock");
  prefs.putString("publicKeyMm", publicKeyMm);
  prefs.putString("privateKeyMm", privateKeyMm);
  prefs.putString("keyID", keyID);
  prefs.putString("apiHost", apiHost);
  prefs.putString("projectID", projectID);
  prefs.end();
}

// 清除Wifi账号、密码和城市相关信息
void clearWiFiCity(){
  prefs.begin("clock");
  prefs.remove("ssid");
  prefs.remove("pass");
  prefs.remove("city");
  prefs.remove("adm");
  prefs.remove("location");

  prefs.remove("publicKeyMm");
  prefs.remove("privateKeyMm");
  prefs.remove("keyID");
  prefs.remove("apiHost");
  prefs.remove("projectID");

  prefs.remove("backColor");
  prefs.end();
}

// 获取屏幕背光颜色
void getBackColor(){
  prefs.begin("clock");
  backColor = prefs.getInt("backColor",BACK_BLACK);
  prefs.end();
}

// 设置屏幕背光颜色
void setBackColor(int backColor){
  prefs.begin("clock");
  prefs.putInt("backColor",backColor);
  prefs.end();
}

// 测试用，在读取NVS之前，先写入自己的Wifi信息，免得每次浪费时间再配网
void setInfo4Test(){
  prefs.begin("clock");
  prefs.putString("ssid", "sh.soft");
  prefs.putString("pass", "wscc6783234");
  prefs.putString("city", "江阴");
  prefs.putString("adm", "");
  prefs.putString("location", "");
  prefs.end();
}