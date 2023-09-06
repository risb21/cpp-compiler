# cpp-compiler

### An attempt at making a C++ compiler, in C++

----------

- ### Grammar for an Integer Literal in C++ 
<!-- $
\LARGE G = \{V_n,\ V_t,\ P,\ S\}
$ --> <img style="transform: translateY(0.1em); filter: invert() ;" src="svg/YETNfGwM43.svg">
<!-- $\LARGE
V_n = \{[int\_lit],\ [hex\_lit],\ [dec\_lit],\ [oct\_lit], 
$ --> <img style="transform: translateY(0.1em); filter: invert();" src="svg/sb2Tyxa8Ik.svg">
<!-- $
\LARGE\qquad\quad\quad [bin\_lit],\ [hex\_dig],\ [opt\_exp],\ [opt\_type]\}
$ --> <img style="transform: translateY(0.1em); filter: invert();" src="svg/xMte9iq8cc.svg">
<!-- $\LARGE
V_t = \{\text{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, a, b, c, d, e, f, }
$ --> <img style="transform: translateY(0.1em); filter: invert();" src="svg/Dig882Wrkb.svg">
<!-- $\LARGE
\qquad\ \ \ \text{A, B, C, D, E, F, u, U, l, L, }'\ \} 
$ --> <img style="transform: translateY(0.1em); filter: invert();" src="svg/8h7L06LYz2.svg">

<!-- $\Huge \begin{align*}
P = \{\ [int\_lit]\ &\Rightarrow\ [hex\_lit]\ |\ [dec\_lit] \ | \  [oct\_lit] \ | \ [bin\_lit]\\ \\ [hex\_dig]\ &\Rightarrow\ \text{[0-9a-fA-F]}\\ [opt\_exp]\ &\Rightarrow\ \text{[e][0-9]$^+$([lLfF] | $\epsilon$)}\\ 
[opt\_type]\ &\Rightarrow\ \text{([uU] | $\epsilon$) ([lL] ([lL] | $\epsilon$) | $\epsilon$)}\\ \\
[hex\_lit] \ &\Rightarrow \ \text{[0][xX] (($\epsilon$ | $[hex\_dig][\ '\ ]$) $[hex\_dig]$)}^+\ ([opt\_exp]\ |\ [opt\_type]\ |\ \epsilon) \\
[dec\_lit]\ &\Rightarrow\ \text{[1-9] (($\epsilon$ | [ $'$ ]) [0-9])}^*\ ([opt\_exp]\ |\ [opt\_type]\ |\ \epsilon) \\
[oct\_lit] \ &\Rightarrow \ \text{[0] (($\epsilon$ | [0-7][ $'$ ]) [0-7])}^+\ ([opt\_exp]\ |\ [opt\_type]\ |\ \epsilon) \\
[bin\_lit] \ &\Rightarrow \ \text{[0][bB] (($\epsilon$ | [01][ $'$ ]) [01])}^+\ ([opt\_type]\ |\ \epsilon) \ \}
\end{align*}
$ --> <img style="transform: translateY(0.1em); filter: invert();" src="svg/adSI2maSxO.svg">
<!-- $\LARGE
S = [int\_lit]\newline
$ --> <img style="transform: translateY(0.1em); filter: invert();" src="svg/2HOT6DW4RO.svg">