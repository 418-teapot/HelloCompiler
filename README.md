# HelloCompiler

本科上数据结构时有一道作业题是实现一个四则运算的计算器，当时老师问到如何保证能够识别所有的错误情况，我并没有答上来。

现在想来，这本质上是一个编译问题，主要是将原来的中缀表达式转换为一棵逆波兰式的抽象语法树。

心血来潮之下，准备把这道作业题再重新写一遍，作为我学习编译器的 "Hello world" 吧（先占上坑

```EBNF
stmt ::= add_expr;
add_expr ::= mul_expr {opt1 mul_expr};
mul_expr ::= item {opt2 item};
item ::= "(" add_expr ")" | number;
number ::= {digit} ["."] {digit};
opt1 ::= "+" | "-";
opt2 ::= "*" | "/";
digit ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9";
```