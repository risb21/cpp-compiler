```
# cpp-compiler

### An attempt at making a C++ compiler, in C++

----------

- ### Grammar for an Integer Literal in C++ 
$$\LARGE G = \{V_n,\ V_t,\ P,\ S\}\newline\ \newline $$
$$ \LARGE V_n = \{[int\_lit],\ [hex\_lit],\ [dec\_lit],\ [oct\_lit],$$
$$\LARGE\qquad\qquad\quad [bin\_lit],\ [hex\_dig],\ [opt\_exp],\ [opt\_type]\}\newline
    V_t = \text{\{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, a, b, c, d, e, f, }\newline\qquad\text{A, B, C, D, E, F, u, U, l, L, $'$\}}\newline\ \newline
    \begin{align*}
    P = \{\ [int\_lit] &\Rightarrow [hex\_lit] \ | \ 
    [dec\_lit] \ | \  [oct\_lit] \ | \ [bin\_lit] \\ \\
    [hex\_dig]\ &\Rightarrow\ \text{[0-9a-fA-F]} \\
    [opt\_exp]\ &\Rightarrow\ \text{[e][0-9]$^+$([lLfF] | $\epsilon$)}\\
    [opt\_type]\ &\Rightarrow\ \text{([uU] | $\epsilon$) ([lL] ([lL] | $\epsilon$) | $\epsilon$)}\\\ \\
    [hex\_lit] \ &\Rightarrow \ \text{[0][xX] (($\epsilon$ | $[hex\_dig][\ '\ ]$) $[hex\_dig]$)}^+\ ([opt\_exp]\ |\ [opt\_type]\ |\ \epsilon) \\
    [dec\_lit]\ &\Rightarrow\ \text{[1-9] (($\epsilon$ | [ $'$ ]) [0-9])}^*\ ([opt\_exp]\ |\ [opt\_type]\ |\ \epsilon) \\
    [oct\_lit] \ &\Rightarrow \ \text{[0] (($\epsilon$ | [0-7][ $'$ ]) [0-7])}^+\ ([opt\_exp]\ |\ [opt\_type]\ |\ \epsilon) \\
    [bin\_lit] \ &\Rightarrow \ \text{[0][bB] (($\epsilon$ | [01][ $'$ ]) [01])}^+\ ([opt\_type]\ |\ \epsilon) \ \}
    \end{align*}
    \newline\
    \newline
    
    
    S = [int\_lit]\newline

$$
```
