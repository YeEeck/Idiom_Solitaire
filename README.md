# Idiom_Solitaire
该程序由YeEeck制作
程序开源，免费。

[点此下载](/成语接龙辅助_By_YeEeck.7z)

使用说明：
请完整解压后打开程序！不要在压缩包里打开！
打开 启动.exe 即可启动程序。
对应输入四字成语即可。
注意：成语首尾匹配模式为，同拼音（包括不同声调）。以后的版本会增加精确字符匹配的功能。同拼音同声调匹配太难了，我不会做。

文件说明：
启动.exe 为主程序文件。
Char2spell.exe 作用是将汉字转化为拼音。

list文件夹中包含已由我分类打包好的11174个常用成语。

src文件夹内包含程序的源码
main.c 文件为主程序源码文件。
Relist.c 文件为将一个大的词库细分为易用的按拼音分类的词库程序的源码
Char2spell.cpp 文件为CSDN找到的汉字转拼音，并由我魔改后的版本的C++源码，编译后即为 Char2spell.exe。

更新记录：
2020.4.26 第二次更新：
1.更新了精确匹配版
2.稍微修改了显示格式
3.增加了输入纠错功能
