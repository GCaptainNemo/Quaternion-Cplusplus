# 四元数(Quaternion)

## 一、介绍

四元数由数学家Hamilton引入，作为复数的推广。复数 C = a+bi 除了表示复平面的一点之外，复数乘法还可以表示复平面的旋转变换，进而也可用于R<sup>2</sup>上点的旋转变换。

一个简单的想法是，在R<sup>3</sup>上是否也能构造类似复数这样的代数结构，使得R<sup>3</sup>的旋转变换可以用类似复数乘法表示呢？Hamilton最后发现在R<sup>3</sup>上旋转变换可以用四元数（Quaternion）Q = a + bi + cj + dk 表示。



## 二、四元数定义与性质

### 2.1 四元数定义

四元数由一个实部和三个虚部组成Q = (v0, **v**)，其中虚部满足

- i * i = j * j = k * k = i * j * k = -1
- i *  j = k, j  * i = - k
- j *  k = i, k * j = - i
- k * i = j, i  *  k = - j

**注意**：虚部乘法不满足交换律



#### 2.2 四元数乘法

**Q1** * **Q2** = (v0, **v**)(w0, **w**) = (v0*w0 - dot(**v**, **w**), v0 * **w** + w0 * **v**  + cross(**v** ,  **w**))

四元数乘法的结果可由2.1节的定义推演得到



#### 2.3 四元数表示旋转

假设要表示绕着归一化轴**v** = [v1, v2, v3]旋转θ(rad)，则对应四元数为

**Q** = cos(θ / 2)  +  v1 * sin(θ / 2) i +  v2 * sin(θ / 2) j  + v3 * sin(θ / 2) k 

设待旋转点为[x, y, z], 表示成四元数

**Q_pos** = x i  + y j + z k

则 **Q** * **Q_pos** * conjugate(**Q**)的虚部对应的就是旋转后的坐标，其中conjugate表示四元数的共轭操作，对虚部取相反数。在参考资料[1]中证明了为什么这样操作对应的是三维空间中的旋转。



## 三、仓库介绍

本仓库用C++实现基本四元数类，包括四元数构造函数，基本的四元数运算(加、减、乘、共轭、转旋转矩阵等操作)。其中四元数与旋转矩阵的转换需要先将四元数表示成罗德里格斯向量，再用罗德里格斯(Rodrigues)公式转成旋转矩阵。



## 四、参考资料

[1] [introduction to quaternion](./resources/introquaternions.pdf)































