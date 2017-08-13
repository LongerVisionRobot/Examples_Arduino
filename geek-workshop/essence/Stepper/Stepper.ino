// http://blog.sina.com.cn/s/blog_8043e91a0102wiar.html
//使用arduino IDE自带的Stepper.h库文件
#include "Stepper.h" 
// 这里设置步进电机旋转一圈是多少步
#define STEPS 100 
//设置步进电机的步数和引脚（就是注意点2里面说的驱动板上IN0～IN4连接的四个数字口）。
Stepper stepper(STEPS, 
8, 
9, 
10, 
11);

void setup() { 
  // 设置电机的转速：每分钟为90步 
  stepper.setSpeed(90); 
  // 初始化串口，用于调试输出信息 
  Serial.begin(9600);
}

void loop() { 
  // 顺时针旋转一周 
  Serial.println("shun");
  stepper.step(2048); 
  //4步模式下旋转一周用2048 步。 
  delay(50); 
  // 逆时针旋转半周 
  Serial.println("ni");
  stepper.step(-1024); 
  //4步模式下旋转一周用2048 步。 
  delay(50);
}




