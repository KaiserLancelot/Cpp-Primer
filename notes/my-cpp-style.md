### 1. 内置类型

字符使用char

整型使用int32_t,int64_t等类型,不使用无符号类型, 需要时应该使用标准类型如size_t,difference_type.

浮点数使用double

如果需要初始化分别使用'\0',0,0.0

### 2. 初始化

全部使用列表初始化且不使用等号,在有std::initializer_list参数的构造函数时,使用小括号(标准库中主要为字符串和容器)

### 3. 命名

* 头文件全小写加下划线
* 类,结构体,枚举,类型模板参数,using,函数每个单词首字母大写,没有下划线
* 变量,函数参数,数据成员全部小写加下划线,类的数据成员以下划线结尾
* const,constexpr变量和枚举字段以k开头,后面每个单词首字母大写,没有下划线

### 4. auto/decltype(auto)

除在模板中外,只在类型非常长,不重要或者无法写出时使用

### 5. for循环中,只在使用迭代器时使用!= 

### 6. 不在虚函数中使用默认参数

### 7. 只有当函数只有10行或更少时才将其定义为内联函数