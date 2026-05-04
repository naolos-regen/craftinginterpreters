Most Lisp implementations that compile to C also cantain an interpreter that lets them execute Lisp code on the fly as well. Why?

Convenience. When trying to debug and reasonably type code faster in Lisp, you tend to use the interpreted side, because it's easier to follow, when one is curious if whatever got written works. Slime is a perfect example of run and test and run and test. But at the end to achieve native code and fast code you will probably just compile it down to C and C -> IR -> CPU
